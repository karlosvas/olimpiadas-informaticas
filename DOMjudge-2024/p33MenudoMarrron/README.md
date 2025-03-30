# Menudomarrón

Tras el confinamiento, el mundo se ha vuelto loco: griterío en lascallesyenlosbalcones,lanzamientodecontenedores,manifestaciones clandestinas... No hay quien ande por la ciudad. Contodo,elpapelhigiénico se havueltounbienpreciado,debido asusmúltiplesusos.Losmanifestanteslosusanparalanzarlos sin herir a nadie, los artistas para hacer mejunje, y hay gente que lo utiliza hasta como filtro de café. Yconlademandaelpreciohaempezadoasubir.Además,laciudadestápatasarriba,porlo quepuedehabernumerosascallescortadas.Aloqueseunelasrestriccionesdemovilidad. Por todo ello, has decidido crear una aplicación que dado el conjunto de calles transitables delaciudadyeldesupermercados,asícomoelpreciodelrollodepapelhigiénicoencada supermercado,calculecuántolecostaríaauncompradorelrollomásbarato,dependiendo de dóndeseencuentre. Entrada La entrada consistirá en una serie de casos de prueba. Cada caso comienza con una línea conelnúmeroNdepuntosenlaciudad(1≤N≤25.000)yelnúmeroCdecallestransitables (0 ≤ C ≤200.000). A continuación, aparecerán C líneas, cada una con dos números (entre 1 y N), describiendo los dos puntos de la ciudad que une una calle de doble sentido. Tras la descripción de las calles aparecerá el número S de supermercados en la ciudad (0 ≤ S≤N), seguido de S líneas con dos números: el punto donde está localizado un supermercado en la ciudad y el precio del rollo de papel higiénico en dicho supermercado. Se garantiza que no habrá dos supermercados en la misma localización. Finalmente, aparecerá una línea con el número K de consultas (1 ≤ K ≤ N), seguido de esas consultas, consistente cadaunaenelpuntodelaciudaddondeseencuentraelcomprador. Salida Para cada caso de prueba se escribirá una línea por cada una de las K consultas con el precio del rollo más barato que se puede comprar desde la localización del comprador. En caso de que no se pueda alcanzar ningún supermercado desde esa localización, se escribirá MENUDO MARRON en su lugar. La salida de cada caso de prueba termina con una línea con tres guiones (---).

### Entrada de ejemplo

7 5  
1 2  
2 3  
3 1  
4 5  
7 6  
3  
2 100  
3 200  
4 50  
4 1  
3 5  
6

### Salida de ejemplo

100  
100  
50  
MENUDO MARRON

---
