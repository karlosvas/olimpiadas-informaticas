# include <iostream>
#include <map>
using namespace std;

int main(){
    map<string, int> edades;

    edades.insert({"jose", 33}); // => Necesita un vcllave valor, tipo peer

    edades["marta"] = 5;
    edades["jose"] = 34;
    edades["luis"] = edades["marta"] + 3;

    for(auto [nombre, edad]: edades){ //=>  Da tantas vueltas como keys tiene el dicionario.
    cout<<nombre<<" tiene "<<"años\n";

    }
    return 0;
}