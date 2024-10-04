#include <iostream>
#include <list>
#include <string>
using namespace std;

bool solve () {
    string linea;
    getline(cin, linea);

    if(!cin) return false;

    list<char> resultado;
    auto it = resultado.begin();
    for (char c : linea){
        switch (c){
        case '-':
            it = resultado.begin();
            break;
        case '+':
            it = resultado.end();
            break;
        case '*':
            if(it != resultado.end()){
                ++it;
            }
            break;
        case '3':
            if(it != resultado.end()){
                it = resultado.erase(it);
            }
            break;
        default:
            resultado.insert(it, c);
            break;
        }
    }
    cout<<string(resultado.begin(), resultado.end())<<"\n";
    return true;
}

int main(){
    while (solve());
    return 0;
}