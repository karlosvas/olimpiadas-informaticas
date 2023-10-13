#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool casan(char a, char c){
    return (a=='(' && c ==')') || (a=='[' && c ==']') || (a=='{' && c =='}');
}

bool resuelve(){
    string cadena;
    getline(cin,cadena);
    if(!cin)
        return false;
    stack<char> abiertos;
    bool correcta = true;

    for (char c: cadena){
        if (c== '(' || c== '[' || c== '{'){
            abiertos.push(c);
        } else if (c== ')'|| c== ']' || c == '}'){
            if(abiertos.empty() || !casan(abiertos.top(), c)){
                correcta = false; break;
            }else {
                abiertos.pop();
            }
        } // else ignorar c
    }

    if (correcta && abiertos.empty()) cout<<"SI\n";
    else cout<<"NO\n";

    return true;
}

int main(){

    while(resuelve()){

    }

    return 0;
}
