// Dada una frase que puede incluir parenteis, averiguar si estos estos están bien puestos (cada paréntesis abierto tiene su correspondeinte cerrado y están bien anidados).
#include <iostream>
using namespace std;

int main(){
    
    string text;
    while (getline(std::cin, text)){
        int fistChar = 0;
        int lastChar = 0;
        int it = 0;
        
        for (char c: text){
            if(c == ' ') continue;
            it ++;
            if(c == '('){
                fistChar++;
                for (int i = it; i < text.length(); i++){
                    if (text[i] == ')'){
                        lastChar = fistChar;
                    }
                }
            }
            if(c == '['){
                fistChar++;
                for (int i = it; i < text.length(); i++){
                    if (text[i] == ']'){
                        lastChar = fistChar;
                    }
                }
            }
            if(c == '{'){
                fistChar++;
                for (int i = it; i < text.length(); i++){
                    if (text[i] == '}'){
                        lastChar = fistChar;
                    }
                }
            }
        }

        if(fistChar == lastChar & fistChar != 0 & lastChar != 0){
        cout<<"SI\n";
        }else if(text.empty()){
        cout<<"SI\n";
        }else{
        cout<<"NO\n";
        }
    }

    return 0;
}

// Fallo, por bucle infinito.