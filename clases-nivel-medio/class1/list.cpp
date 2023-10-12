#include <iostream>
#include <string>
#include <list>
using namespace std;

void mostrar(list<int> const& l){
    for (auto it = l.begin(); it != l.end() & !l.empty(); it++) {
        cout<<*it<<' ';
    }
    cout<<"\n";
}

int main(){
    list<int> lista = {1,2,3,4};
    mostrar(lista);

    auto it = lista.begin();
    it++;
    lista.insert(it,7);
    mostrar(lista);
    // LLamar a insert no modifica el operador por lo que el it sige siendo 2.
    lista.insert(it,8);
    mostrar(lista);

    return 0;
}

