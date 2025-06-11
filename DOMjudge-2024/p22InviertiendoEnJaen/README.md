# Invirtiendo en Jaén

Tras amasar una inmensa fortuna en las empresas tecnológicas de su país, Comm O’Lhivas
ha decidido dar un giro a su vida y dedicarse a negocios más campestres. Enamorado desde hace años del sur de España, ha puesto sus miras en los aceituneros de Jaén, y está
decidido a comprar la mayor plantación de olivos que encuentre en la zona.
Siendo un hombre que consigue todo aquello que se propone, se ha hecho con los mapas del catastro, en los que el terreno se muestra troceado en parcelas cuadradas, todas
del mismo tamaño. Las que están cultivadas con olivos aparecen de color verde, y el resto
aparecen en blanco. Dado que no es un inversor que se conforme con negocios pequeños,
necesita ahora decidir qué plantación es la más grande, para comprarla entera. Se considera que una plantación es un conjunto de parcelas con olivos situadas de tal modo que
podemos ir de cualquier parcela a cualquier otra sin salir de la plantación, y moviéndonos
únicamente en vertical o en horizontal.
Por ejemplo, en el siguiente mapa (donde cada parcela se ha representado mediante un
cuadrado) la plantación más grande (marcada con puntos blancos) tiene 9 parcelas:

## Entrada

La entrada estará compuesta por diversos casos de prueba. Para cada caso, la primera línea
contendrá el número F de filas y el número C de columnas de parcelas que tiene el mapa
(números entre 1 y 100). A continuación aparecerán F líneas, cada una con C caracteres. El
espacio en blanco representa una parcela sin plantar, y el carácter # representa una parcela
con olivos.

## Salida

Para cada caso de prueba se escribirá en una línea independiente el número de parcelas
de la plantación más grande.

### Entrada de ejemplo

8 8
-#-#---#
-###---#
----####
#-------
-#-#----
-###-##-
###--##-
--#-----

3 10
###---####
##--------
##########

### Salida de ejemplo

9
15
