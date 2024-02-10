# El chispómetro cuántico

Juan Chispas es el becario m´as famoso e ingenioso del laboratorio de Investigaci´on Energ´etica de una de las compa˜n´ıas el´ectricas m´as importantes
del pa´ıs. En su d´ıa a d´ıa de becario tiene que enfrentarse a numerosas
situaciones peculiares, y a veces desafiantes, desde intentar explicar las
complejidades de sus tareas a sus superiores del laboratorio hasta lidiar
con bromas cient´ıficas que desaf´ıan la gravedad.
Hoy le toca afilar su ingenio. Tiene que medir el voltaje de una serie
de pilas experimentales que podr´ıan revolucionar el mundo de la energ´ıa.
Su laboratorio cuenta con el Chisp´ometro cu´antico, un dispositivo especializado que le permite medir la suma de voltajes de cualquier par de pilas
que elija. Pero, ah´ı est´a la broma, solo puede realizar estas mediciones de
a pares. Es decir, si al chisp´ometro le da solamente una pila, no reacciona.
Tiene que darle dos pilas y el chisp´ometro se˜nala la suma conjunta de los voltajes de esas dos pilas.
Juan debe idear un plan astuto para determinar el voltaje de cada pila individualmente. ¿Podr´a
sortear los obst´aculos c´omicos y, al mismo tiempo, dise˜nar una estrategia inteligente que le permita
conocer los voltajes de todas las pilas? Tiene que hacerlo r´apido, que despu´es ha quedado con sus otros
colegas becarios para idear la siguiente broma que van a gastar al conserje. Por supuesto, tambi´en admite
ayuda.
Para poder ayudar a Juan, vas a tener que dise˜nar un programa que determine el voltaje individual
de varios conjuntos de pilas, cada uno independiente del anterior. Para cada conjunto, debe leer de la
entrada est´andar el n´umero N de pilas de ese conjunto, 3 ≤ N ≤ 100.000 (otra broma de mal gusto para
Juan Chispas). Las pilas est´an numeradas de 1 a N. Despu´es, el programa deber´a utilizar el chisp´ometro
cu´antico con pares de pilas. Para utilizarlo tendr´a que escribir por la salida estandar “?” seguido de los
dos ´ındices de pilas distintas que quiere proporcionar al chisp´ometro. Por ejemplo, ? 1 2 si se quiere
conocer el voltaje conjunto de las dos primeras pilas. A continuaci´on podr´a leer de la entrada est´andar
la respuesta del aparato (un n´umero entre 0 y 109
). El programa deber´a seguir haciendo consultas hasta
que conozca los voltajes de las N pilas. En ese momento escribir´a “Respuesta:” seguido de un espacio
en blanco y seguido de los voltajes de todas las pilas, de la 1 a la N, separados por espacios. Tras ello,
el programa pasar´a al siguiente conjunto de pilas. El proceso termina cuando al leer el n´umero de pilas
de un conjunto se obtenga un 0.
A continuaci´on aparece un ejemplo de ejecuci´on. En cursiva aparece lo le´ıdo por la entrada est´andar
y en negrita lo escrito por la salida est´andar.
4  
? 1 4  
0  
? 1 2  
10  
? 4 3  
5  
Respuesta: 0 10 5 0  
0

### Notas

Al tratarse de un problema interactivo es importante que cada vez que tu soluci´on escriba algo que
el juez deba leer se asegure de volcar la salida (usando terminolog´ıa inglesa, haga “flush”). La forma de
hacerlo var´ıa entre lenguajes. En los admitidos en la competici´on puede hacerse con:
• C++: cout << endl; o cout << flush;
• C: fflush(stdout);
1
• Java: System.out.flush();
• Python: print(..., flush=True) o sys.stdout.flush()
