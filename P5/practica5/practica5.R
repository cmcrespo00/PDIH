# **************** librerías ****************
library(tuneR)
library(seewave)
library(audio)

# **************** Apartado 1: Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno. En el primero debe escucharse el nombre de la persona que realiza la práctica. En el segundo debe escucharse el apellido. ****************
nombre <- readWave('nombre.wav')
apellido <- readWave('apellido.wav')

# **************** Apartado 2: Dibujar la forma de onda de ambos sonidos. ****************
plot( extractWave(nombre, from = 1, to = 22050) )
plot( extractWave(apellido, from = 1, to = 22050) )

# **************** Apartado 3:  Obtener la información de las cabeceras de ambos sonidos.****************
nombre
str(nombre)
apellido
str(apellido)

# **************** Apartado 4: Unir ambos sonidos en uno nuevo. ****************
mezcla <- pastew(nombre, apellido, output = "Wave" )

# **************** Apartado 5: Dibujar la forma de onda de la señal resultante. ****************
plot( extractWave(mezcla, from = 1, to = 22050) )

# **************** Apartado 6:  Pasarle un filtro de frecuencia para eliminar las frecuencias entre 10000Hz y 20000Hz****************
mezcla2 <- bwfilter(mezcla, f=f, channel=1, n=1, from=10000, to=20000, bandpass=TRUE, listen = FALSE, output = "Wave")
plot( extractWave(mezcla2, from = 1, to = 22050) )

# **************** Apartado 7: Almacenar la señal obtenida como un fichero WAV denominado “mezcla.wav”. ****************
writeWave(mezcla2, file.path("mezcla.wav"))

# **************** Apartado 8: Cargar un nuevo archivo de sonido, aplicarle eco y a continuación darle la vuelta al sonido. Almacenar la señal obtenida como un fichero WAV denominado “alreves.wav”. ****************
nombreapellido <- readWave('nombreapellido.wav')

eco <- echo(nombreapellido,f=22050,amp=c(0.8,0.4,0.2),delay=c(1,2,3), output="Wave")
eco@left <- 10000 * eco@left
plot( extractWave(eco, from = 1, to = 22050) )

alreves <- revw(eco, output="Wave")
plot( extractWave(alreves, from = 1, to = 22050) )

writeWave(alreves, file.path("alreves.wav"))
