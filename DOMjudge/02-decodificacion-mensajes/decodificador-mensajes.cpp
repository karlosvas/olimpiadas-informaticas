#include <iostream>
#include <stack>
#include <deque>
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
    deque<char> deq;
    int l = x2.length();
    if(l %2 == 0) l = l-1;
        while(l >= 0){
                // Añade el penúltimo elemento
                int j = l - 1;
                deq.push_front(x2[j]);
                // Añade el último elemento
                deq.push_back(x2[l]);
            // Se resta a la longitud dos en cada bucle para pasar a los dos anteriores.
            l-= 2;
        }
    for (char c: deq){
        // Se da el valor de la string con los valores del deque.
        x1 += c;
    }
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