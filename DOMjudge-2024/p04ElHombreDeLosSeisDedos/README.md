# El hombreconseis dedos

El otro día me presentaron a un hombre y al darnos la mano noté algo extraño. ¡Luego me di cuenta de que tenía seis dedos! La cosa me sorprendió tanto que he estado investigando y resulta que no es tan extraño que una personanazcaconmásdecincodedosenunamanoounpie. Laanomalíagenética se denomina polidactilia y se estima que 1 de cada 500 bebés nace con ella. Lo que ocurre es que normalmente el dedo extra es muy pequeño y termina siendo extirpado sin más consecuencias. Lo que sí es más extraño es que el dedo se encuentre completo y sea funcional. Eso es lo que le ocurría a este hombre. Continuando mi investigación he dado con una página web donde se han recopilado los años donde se conoce que nació una persona con algún dedo de más, completo y funcional. Y estoy interesado en construir un programa para averiguar en qué siglo nacieron más personas así. Ya puestos, sería mejor tener un programa más general, que sirviera también para averiguar la decada con másnacimientos, o el lustro, etc.

## Entrada

El programarecibirá por la entrada estándar una serie de casos de prueba. Cadacasoconstade dos líneas. En la primera aparecen dos números: el número N de nacimientos de los que tenemos constancia(entre 1y200.000)yelnúmeroAdeañosdelperiodoenelqueestamosinteresados(un númeromayorquecero). En la segundaaparecen, separados por espacios y ordenados cronológicamente,losNañosdenacimiento(sienunmismoañonaciómásdeunapersona,elañoaparecerá repetido). Detrás del último caso aparece una línea con dos ceros.

## Salida

Para cada caso de prueba el programa escribirá una línea con el mayor número de personas que hanacido en unperiodo de Aaños. Ten encuenta quesi unperiodo de Aañoscomienza enel año Dentonces abarca hasta el año D + A– 1, inclusive.

# Entrada de ejemplo

10 5  
1 1 4 4 5 6 6 7 10 11  
10 6  
1 1 4 4 5 6 6 7 10 11  
0 0

# Salida de ejemplo

6  
7
