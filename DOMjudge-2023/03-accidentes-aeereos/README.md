# Accidentes aéreos
Estamos programando un bot de Telegram que enviará noticias a sus
seguidores y ahora nos toca tratar el escabroso tema de los accidentes
de aviación. Cuando se produce uno de estos accidentes, suelen hacerse comentarios del estilo “Este es el accidente más grave desde febrero
de 1995”.
Nos han pasado un listado (ordenado cronológicamente) de accidentes
ocurridos en el pasado y queremos estar preparados para que, cuando
ocurra el siguiente accidente, podamos producir un comentario como el
anterior.
De hecho, para probar esta funcionalidad, queremos saber cuál habría sido el comentario cuando
se produjo cada uno de los accidentes conocidos.
Entrada
La entrada está formada por una serie de casos. Cada caso comienza con el número N de accidentes
conocidos (un número entre 1 y 300.000). A continuación aparecen N líneas con la descripción de
cada uno de ellos: una fecha (con formato DD/MM/AAAA) y el número de víctimas en ese accidente
(no superior a 106
). Todas las fechas son distintas y el listado está ordenado cronológicamente del
accidente más antiguo al más reciente.
Salida
Para cada caso se escribirán N líneas. La i-ésima línea contendrá la fecha del último accidente anterior que tuvo (estrictamente) más víctimas que el accidente i-ésimo. Si no existe tal accidente (en
particular, eso ocurre siempre para el primero), se escribirá NO HAY en su lugar.
Después de cada caso se escribirá una línea con tres guiones (---).
Entrada de ejemplo
6
19/12/1990 50
01/02/2000 80
10/05/2001 30
20/10/2005 10
08/07/2007 60
10/07/2007 40
2
01/01/2000 100
21/12/2001 99


Salida de ejemplo
NO HAY
NO HAY
01/02/2000
10/05/2001
01/02/2000
08/07/2007
---
NO HAY
01/01/2000
---