#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    while (cin >> N){
        if(N < 1 || N > 3000) break;
        // Creamos un par de string y enteros, y resultados para guardar la solución.
        vector<pair<string, int>> accidentes;
        vector<string> resultados;

        for (int i = 0; i < N; ++i) {
            // Bucle para cada caso de prueba. guardando en variables las fechas y victimas.
            string fecha;
            int victimas;
            cin>>fecha>>victimas;
            // verificamso si es mayor de 10 elevado a 6;
            if(victimas > 1e6) break;

            while (!accidentes.empty() && accidentes.back().second <= victimas) {
                // Si el vector no esta vacio y el segundo elemento es menor o igual que las victimas borrar el ultimo elemento.
                accidentes.pop_back();
            }

            if (!accidentes.empty()) {
                // Si el vector no esta vacio añadir el primer elemento del vector, a los resultados.
                resultados.push_back(accidentes.back().first);
            } else {
                // Si el vector esta vacio, se añade la respuesta NO HAY.
                resultados.push_back("NO HAY");
            }
            // Independientemente de los demas se añade como par de pilas a accidentes.
            accidentes.push_back(make_pair(fecha, victimas));
            cout<<resultados[i]<<"\n";
        }
        cout<<"---\n";
    }
    return 0;
}
