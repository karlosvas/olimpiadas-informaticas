#include <iostream>

using namespace std;

bool solve() {
    // Tambor 010101
    string cadena;
    cin >> cadena;

    if (!cin) return false;

    int l = cadena.size();

    // Contadores de casos favorables y totales
    int casos_favorables = 0, total_casos = 0;
    for (int i = 0; i < l; i++) {
        // Sabemos que nos encontramos en alguna posición "0"+1 porque disparamos después de Sergey y fallo
        if (cadena[i] == '0') {
            // Incrementamos el contador de casos totales
            total_casos++;
            // Si nos salimos del rango preguntamos por la primera posición he incrementamo el contador de casos favorables
            if (cadena[(i + 1) % l] == '0') {
                casos_favorables++;
            }
        }
    }

    // Probabilidades de si no giramos o si giramos
    // Si no giramos favorables/casos
    float no_girar = static_cast<float>(casos_favorables) / static_cast<float>(total_casos);
    // Si giramos, la probabilidad de no encontrarse una bala en la siguiente posición es cantidad de 0 / cantidad de posibilidades
    float girar = static_cast<float>(total_casos) / static_cast<float>(l);

    // Decidimos si girar o no girar, selecionamos lo que de mas posibilidades de sobrevivir
    if (girar == no_girar)
        cout << "Da igual\n";
    else if (no_girar > girar)
        cout << "No girar\n";
    else
        cout << "Girar\n";
    return true;
}

int main() {
    while (solve());
    return 0;
}
