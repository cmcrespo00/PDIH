#include <stdio.h>
#include <dos.h>

int x;

void mi_pausa(){
    union REGS inregs, outregs;

    inregs.h.ah = 8;
    int86(0x21, &inregs, &outregs);
}

void mi_modo_video(unsigned char modo){
    union REGS inregs, outregs;

    inregs.h.ah = 0x00;
    inregs.h.al = modo;
    int86(0x10,&inregs,&outregs);
    return;
}

int mi_getchar(){
    union REGS inregs, outregs;

    int caracter;
    inregs.h.ah = 1;
    int86(0x21, &inregs, &outregs);
    caracter = outregs.h.al;

    return caracter;
}

void mi_putchar(char c){
    union REGS inregs, outregs;

    inregs.h.ah = 2;
    inregs.h.dl = c;
    int86(0x21, &inregs, &outregs);
}

//////////////////////////////////////////////

void gotoxy(int x, int y){
    union REGS inregs, outregs;

    inregs.h.ah = 0x02;
    inregs.h.dh = x;
    inregs.h.dl = y;
    inregs.h.bh = 0;

    int86(0x10,&inregs,&outregs);
    return;
}

void setcursortype(int tipo_cursor){
    union REGS inregs, outregs;

    inregs.h.ah = 0x01;
    switch(tipo_cursor){
        case 0: //invisible
            inregs.h.ch = 010;
            inregs.h.cl = 000;
			break;
        case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
    }
	int86(0x10, &inregs, &outregs);
}

void setvideomode(int x){
    union REGS inregs, outregs;

    inregs.h.ah=0;
    inregs.h.al=x; // Resolución: 80x25 / Colores: 16 / Tipo: Texto

    printf("\n%d\n", x);

    int86(0x10, &inregs, &outregs);
}

void getvideomode(){
    union REGS inregs, outregs;

    inregs.h.ah=0xF;
    inregs.h.al=x;

    int86(0x10, &inregs, &outregs);

    x=outregs.h.al;

    if (x == 0x03){
        printf("\nModo texto");
    }else if (x == 0x02){
        printf("\nModo samba");
    }else if (x == 0x01){
        printf("\nmodo epico");
    }else if (x== 0x04){
        printf("\nmodo grafico");
    }else{
        printf("\nmodo raro");
    }
}

void textcolor(int color){
    union REGS inregs, outregs;

    inregs.h.ah=0x09;
    inregs.h.al=98;
    inregs.h.bl=color;
    inregs.h.bh=0x00;
    inregs.x.cx=10;

    int86(0x10, &inregs, &outregs);
}

void textbackground(int color){
    union REGS inregs, outregs;

    inregs.h.ah=0x09;
    inregs.h.al=98;
    inregs.h.bl=color << 4;
    inregs.h.bh=0x00;
    inregs.x.cx=10;

    int86(0x10, &inregs, &outregs);
}

void clrscr(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void cputchar(char c){
    union REGS inregs, outregs;

    inregs.h.ah=2;
    inregs.h.dl=c;

    int86(0x21, &inregs, &outregs);
}

getche(int tmp){
	printf("\nPulsa una tecla... ");
	tmp = mi_getchar();

	printf("\nHas pulsado: ");
	mi_putchar( (char)tmp );
}


void dibujarCuadradoModoTexto(int f1, int c1, int f2, int c2, int primerPlano, int fondo){
    union REGS inregs, outregs;

    inregs.h.ah=0x06;
    inregs.h.al=0;
    inregs.h.bh=fondo << 4 | primerPlano;
    inregs.h.ch=f1;
    inregs.h.cl=c1;
    inregs.h.dh=f2;
    inregs.h.dl=c2;

    int86(0x10, &inregs, &outregs);
}

void modoGraficoCGA(int x, int y, int color){
    union REGS inregs, outregs;

    inregs.h.ah=0x0C;
    inregs.x.cx=x;
    inregs.x.dx=y;
    inregs.h.al=color;

    int86(0x10, &inregs, &outregs);
}

int main(){
	int tmp, i, j, k, l, m, n;

	getche(tmp);

	printf("\nCursor invisible: ");

	setcursortype(0);
	mi_pausa();

	printf("\nCursor grueso: ");

	setcursortype(2);

	mi_pausa();

	printf("\nCursor normal: ");

	setcursortype(1);

	mi_pausa();

	printf("\n\n");

	textcolor(3);

	printf("\n");

	textbackground(3);

	printf("\n");

	cputchar('x');

	dibujarCuadradoModoTexto(20, 20, 21, 21, 2, 3);

	gotoxy(0,5);

	mi_pausa();

	clrscr();

	mi_pausa();

	printf("\nPantalla borrada");

	mi_pausa();

	setvideomode(0x04); // Entrar en modo gráfico -> 320 (ancho) x 200 (alto)

	getvideomode();

	mi_pausa();

	//Cara de Creeper:

	//ojos
	for(i=40; i<80; i++){
        modoGraficoCGA(40, i, 0x01);
		modoGraficoCGA(80, i, 0x01);
		modoGraficoCGA(120, i, 0x01);
		modoGraficoCGA(160, i, 0x01);
		modoGraficoCGA(i, 40, 0x01);
		modoGraficoCGA(i, 80, 0x01);
	}

	for(j=120; j<160; j++){
		modoGraficoCGA(j, 80, 0x01);
		modoGraficoCGA(j, 40, 0x01);
	}

	//boca horizontal
	for(k=80; k<120; k++){
		modoGraficoCGA(k, 81, 0x01);
		modoGraficoCGA(k, 141, 0x01);
	}

	for(j=60; j<80; j++){
		modoGraficoCGA(j, 101, 0x01);
		modoGraficoCGA(j, 161, 0x01);
	}

	for(j=120; j<140; j++){
		modoGraficoCGA(j, 101, 0x01);
		modoGraficoCGA(j, 161, 0x01);
	}

	//boca vertical
	for(k=81; k<101; k++){
		modoGraficoCGA(80, k, 0x01);
		modoGraficoCGA(120, k, 0x01);
	}

	for(k=101; k<161; k++){
		modoGraficoCGA(60, k, 0x01);
		modoGraficoCGA(140, k, 0x01);
	}

	for(k=141; k<161; k++){
		modoGraficoCGA(80, k, 0x01);
		modoGraficoCGA(120, k, 0x01);
	}

	modoGraficoCGA(80, 80, 0x01);
	modoGraficoCGA(80, 101, 0x01);
	modoGraficoCGA(80, 161, 0x01);
	modoGraficoCGA(160, 80, 0x01);
	modoGraficoCGA(140, 161, 0x01);

	mi_pausa();

	return 0;
}
