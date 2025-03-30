#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool casan(char a, char b){
    return (a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}');
}

bool solve(){
    string n;
    getline(cin, n);

    if(!cin) return false;

    bool correcto = true;
    stack<char> pila;

    for (char c: n){
        if(c == '(' || c == '[' || c == '{'){
            pila.push(c);
        }else if(c == ')' || c == ']' || c == '}'){
            if(pila.empty() || !casan(pila.top(), c)) {
                correcto = false;
                break;
            }
            pila.pop();
        }
    }

    if(correcto && pila.empty()) cout << "SI\n";
    else cout << "NO\n";

    return true;
}

int main(){
    while (solve());
    return 0;
}
