#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string cadena = "Del reves";
    stack<char> pila;
    // for de rango => for(char c: message)
    for(char c: cadena){
        pila.push(c);
    }

    while (!pila.empty()) {
        char c = pila.top(); pila.pop();
        cout<<c;
    }
    cout<<"\n";

    return 0;
}