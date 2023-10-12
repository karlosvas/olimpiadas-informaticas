#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    string cadena = "Del reves";
    queue<char> cola;
    
    for(char c : cadena){
        cola.push(c);
    }

   while (!cola.empty()) {
        char c = cola.front(); cola.pop();
        cout<<c;
    }
    cout<<"\n";

    return 0;
}