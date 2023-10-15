#include <iostream>
#include <string>
using namespace std;

int main(){
    string text;
    while (cin>>text){
        // El cursor es a donde esta apuntando para escriir o eliminar en ese indice.
        int cursor = 0;
        string resultado;

        for (char c : text){
            if ( c == '-') cursor = 0; // => Incio de la cadena.
            else if ( c == '+') cursor = resultado.size(); // => Final de la cadena.
            else if ( c == '*') {
                // => Lo movemos el cursor hacia la derecha.
                if (static_cast<string::size_type>(cursor) <= resultado.size() - 1) cursor++;
            } 
            else if ( c == '3') {
                // Le damos la nueva posicion al cursor.
                // Verificamos que este en rango de out_of_range.
                if (static_cast<string::size_type>(cursor) <= resultado.size() - 1 && cursor >= 0) resultado.erase(cursor, 1);
                else if (cursor > 0) {
                    resultado.pop_back();
                    cursor--;
                }
            }else {
                // Introducir un nuevo carácter.
                    resultado.insert(cursor, 1, c);
                    cursor++;
            }
        }
        if(!resultado.empty()) cout<<resultado<<"\n";
    }
    return 0;
}