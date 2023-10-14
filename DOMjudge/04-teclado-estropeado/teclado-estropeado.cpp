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
                if(static_cast<string::size_type>(cursor) < resultado.size()) cursor++;
            } // => Lo movemos a la derecha. 
            else if ( c == '3') {
                // Verificamos que este en rango de out_of_range.
                if (static_cast<string::size_type>(cursor) + 1 < resultado.length()) resultado.erase(cursor, 1);
                else resultado.pop_back();
            } else {
                // Introducir un nuevo carácter.
                if (static_cast<string::size_type>(cursor) > resultado.length()) resultado.insert(cursor - 1, 1, c);
                else {
                    resultado.insert(cursor, 1, c);
                }
                cursor++;
            }
        }
        if(!resultado.empty()) cout<<resultado<<"\n";
    }
    return 0;
}