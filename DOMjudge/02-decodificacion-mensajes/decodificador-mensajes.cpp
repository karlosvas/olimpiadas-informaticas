#include <iostream>
#include <queue>
#include<deque>
using namespace std;

string codificationX1(string x) {
    queue<char> cola;
    string vuelta;

    for (char c : x) {

        c = tolower(c);
        if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u') {
            cola.push(c);
            if (cola.size() == 2) {
                vuelta += cola.back();
                vuelta += cola.front();
                cola.pop();
                cola.pop();
            }
        } else if (!cola.empty()) {
            vuelta += cola.front();
            vuelta += c;
            cola.pop();
        } else {
            vuelta += c;
        }
    }

    for (int i = 0; i < x.length(); i++) {
        if (isupper(x[i])) {
            vuelta.at(i) = toupper(vuelta.at(i));
        }
    }
    return vuelta;
}

string codificationX2(string x) {
    string x1;
    deque<char> dequex2;

    for (char c: x){
        dequex2.push_back(c);
    }
    return x1;
}


int main(){
    
    string x;
    while (getline(cin, x)){
        string x1 = codificationX2(x);
        cout<<x1<<"\n";
        string x2 = codificationX2(x1);
        cout<<x2<<"\n";
    }
    return 0;
}