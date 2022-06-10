# **************** librerías ****************
library(tuneR)
library(seewave)
library(audio)

# **************** Ejercicio 1: Leer dos ficheros de sonido (WAV o MP3) de unos pocos segundos de duración cada uno. ****************
gato <- readMP3('gato.mp3')
oveja <- readWave('oveja.wav')

# **************** Ejercicio 2: Dibujar la forma de onda de ambos sonidos. ****************
plot( extractWave(gato, from = 1, to = 393984) )
plot( extractWave(oveja, from = 1, to = 19764) )

# **************** Ejercicio 3: Obtener la información de las cabeceras de ambos sonidos. ****************
str(gato)
str(oveja)

# **************** Ejercicio 4: Unir ambos sonidos en uno nuevo. ****************
mezcla <- pastew(gato, oveja, output = "Wave" )

# **************** Ejercicio 5: Reproducir la señal obtenida y almacenarla como un nuevo fichero WAV, denominado “mezcla.wav”. ****************
mezcla
plot( extractWave(mezcla, from = 1, to = 412748) )
listen(mezcla)

writeWave(mezcla, file.path("mezcla.wav"))









