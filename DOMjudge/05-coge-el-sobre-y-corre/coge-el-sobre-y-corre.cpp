#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

int main (){
    // n es el numero de sobres disoponibles
    // k el numero de sobres cojido para ese caso en concreto.
    int n,k;
    while (cin>>n>>k){
        // Terminamos el bucle si no cumple con los requesitos.
        if(n < 1 || n > 5000 || k > n) break;
        // Las posibilidades que tiene de que el dineroro se lo lleve el presidente.
        int posibility= n - k + 1;

        string test;
        cin.ignore();
        getline(cin, test);
        vector<int> testList;
        istringstream iss(test);

        int numero;
        while (iss >> numero) {
            testList.push_back(numero);
        }

        for(int it = 0; it < posibility; it++){
        stack<int> pila;
            // Ca posibilidad es un nuevo casos enm el que elije entre k mesajes.
            for(int j= it; j < k + it; j++){
                // Va eligiendo de k veces dentro de cada posibilidad.
                if (pila.empty()) pila.push(testList[j]);
                if (testList[j] > pila.top()) pila.push(testList[j]);
            }
            if(it == posibility -1) cout<<pila.top()<<"\n";
            else cout<<pila.top()<<" ";
        }
    }
    return 0;
}