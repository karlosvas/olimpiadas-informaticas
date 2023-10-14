#include <iostream>
#include <stack>
#include <deque>
#include <string>
using namespace std;

bool isVocal(char c) {
    c = tolower(c);  // Convierte el carácter a minúsculas para la comparacion;
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

string reverseX1ToX(string x2) {
    string x1;
    stack<char> coons;
    // Pila que guarda coincidencias de dos consonsantes repetidas.
    for (char c : x2) {
        if (!isVocal(c)) coons.push(c);
        else {
            while (!coons.empty()) {
                x1 += coons.top();
                coons.pop();
            }
            x1 += c;
        }
    }
    while (!coons.empty()) {
        x1 += coons.top();
        coons.pop();
    }
    return x1;
}

string reverseX2ToX1(string x2) {
    string x1;
    // Inicaiamos dos deque para paoder acceder a los impares y los pares.
    deque<char> deqFront;
    deque<char> deqEnd;
    // Recorremos el texto de forma inversa y le damos so correspondiente valor a cada itineracion de este.
    for (int i = x2.length(); i >= 0; --i) {
        if (i % 2 == 0) {
            // Si es par le damos su correspodneinte valor delante de la cola de el frente.
            deqFront.push_front(x2[i]);
        } else {
            // Si la iteración es inpar le añadimos su correspoendiente valor, detras de la cola.
            deqEnd.push_back(x2[i]);
        }
    }

    deqFront.insert(deqFront.end(), deqEnd.begin(), deqEnd.end());
    // Una vez echo esto lo concatenamos y lo guardamos en x1 para retornarlo.
    for (char c : deqFront) x1+= c;
    return x1;
}

int main(){
    string x2;
    while (getline(cin, x2)){
        string x1 = reverseX2ToX1(x2);
        string x = reverseX1ToX(x1);
        cout<<x<<"\n";
    }
    return 0;
}