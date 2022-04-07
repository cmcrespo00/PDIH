//  gcc rpong.c -o pong -lncurses
// ./pong

#include <ncurses.h>
#include <unistd.h>

#define DELAY 5000
typedef struct{short int x, y, puntos; bool mover_horizontal, mover_vertical;} objeto;

int main() {
  objeto pantalla;

  int tamano_barra = 3, i = 0, cont=0;
  bool terminar = false;

  initscr();

  start_color();
  init_pair(1,COLOR_MAGENTA,COLOR_BLACK);     //Color de la puntuación
  init_pair(2,COLOR_MAGENTA,COLOR_MAGENTA);   //Color barra central
  init_pair(3,COLOR_YELLOW,COLOR_BLACK);      //Color de la pelota
  init_pair(4,COLOR_YELLOW,COLOR_YELLOW);     //Color de las barras

  keypad(stdscr, true);
  noecho();
  curs_set(FALSE);

  getmaxyx(stdscr, pantalla.y, pantalla.x);  //Guarda el tamaño de la terminal
                                             //para ajustar el programa a ese
                                             //tamaño
  objeto barra_izquierda = {1, pantalla.y/2, 0, false, false},
           barra_derecha = {pantalla.x-2, pantalla.y/2, 0, false, false},
                  pelota = {pantalla.x/2, pantalla.y/2, 0, false, false}; //La pelota comienza
                                                                          //en el centro de la
                                                                          //terminal

  mvprintw(1,0,"       *********            ***                                    \n"
               "          ***     *******   ***    *******                         \n"
               "          ***    ***   ***  ***   ***   ***                        \n"
               "          ***    ********   ***   ********                         \n"
               "          ***    ***        ***   ***                              \n"
               "          ***     *******   ****   *******                         \n"
               "                     ********                                      \n"
               "                    ***    ***   ********    *******    *********  \n"
               "                    ***    ***  ***    ***  ***   ***  ***     *** \n"
               "                    *********   ***    ***  ***   ***  ***     *** \n"
               "                    ***         ***    ***  ***   ***   *********  \n"
               "                    ***          ********   ***   ***          *** \n"
               "                                                        *********  \n"
               "  *****************************************************************************\n"
               "  *** Instrucciones para poder jugar:                                       ***\n"
               "  ***   Para comenzar el juego pulsa cualquier tecla.                       ***\n"
               "  ***   Jugador de la derecha: Controles 'flecha arriba' y 'flecha abajo'.  ***\n"
               "  ***   Jugador de la izquierda: Controles 'w' y 's'.                       ***\n"
               "  ***   Para pausar el juego pulse 'p'.                                     ***\n"
               "  ***   Para salir pulse ESC.                                               ***\n"
               "  *****************************************************************************\n"
               );

  getch();

  for (nodelay(stdscr,1); !terminar; usleep(DELAY)) {
    if (++cont % 16 == 0){
      if ((pelota.y == pantalla.y-1) || (pelota.y == 1))
        pelota.mover_vertical =! pelota.mover_vertical;
      if ((pelota.x >= pantalla.x-2) || (pelota.x <= 2)){
        pelota.mover_horizontal =! pelota.mover_horizontal;
        if ((pelota.y == barra_derecha.y-1) || (pelota.y == barra_izquierda.y-1)) {
          pelota.mover_vertical = false;
        } else if ((pelota.y == barra_derecha.y+1) || (pelota.y == barra_izquierda.y+1)) {
          pelota.mover_vertical = true;
        } else if ((pelota.y != barra_derecha.y) && (pelota.y != barra_izquierda.y)) {
          if (pelota.x >= pantalla.x-2)
            barra_derecha.puntos++;
          else
            barra_izquierda.puntos++;
          pelota.x = pantalla.x/2;
          pelota.y = pantalla.y/2;
        }
      }

      if(pelota.mover_horizontal)
        pelota.x = pelota.x+1;
      else
        pelota.x = pelota.x-1;

      if(pelota.mover_vertical)
        pelota.y = pelota.y+1;
      else
        pelota.y = pelota.y-1;

      if (barra_derecha.y <= 1)
        barra_derecha.y = pantalla.y-2;
      if (barra_derecha.y >= pantalla.y-1)
        barra_derecha.y = 2;

      if (barra_izquierda.y <= 1)
        barra_izquierda.y = pantalla.y-2;
      if (barra_izquierda.y >= pantalla.y-1)
        barra_izquierda.y = 2;
    }

    switch (getch()) {
      case 'w':      barra_izquierda.y--; break;
      case 's':      barra_izquierda.y++; break;
      case KEY_DOWN: barra_derecha.y++; break;
      case KEY_UP:   barra_derecha.y--; break;
      case 'p':      getchar(); break;               //Pausar juego
      case 0x1B:     endwin(); terminar++; break;    //Salir del juego
    }

    erase();
    attron(COLOR_PAIR(1));
    mvprintw(0, pantalla.x/2-3, "%i     %i", barra_derecha.puntos, barra_izquierda.puntos);
    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(2));
    mvvline(0, pantalla.x/2, ACS_VLINE, pantalla.y);
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    mvprintw(pelota.y,pelota.x,"o");
    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));
    for(i=-1;i<2;i++){
      mvprintw(barra_izquierda.y+i,barra_izquierda.x,"|");
      mvprintw(barra_derecha.y+i,barra_derecha.x,"|");}
    attroff(COLOR_PAIR(4));
  }
}
