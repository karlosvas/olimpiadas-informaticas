#include <iostream>
#include <set>
using namespace std;

int sumascubos (int n){
    int suma = 0;
    while(n > 0){
        int d = n% 10;
        suma += d*d*d;
        n = n / 10;
    }
    return suma;
}

void cubifinito(int n){
    set<int> cjto;
    while(!cjto.count(n)){
        if(n == 1){
            cout<<n<<" -> cubinfinito.\n";
            break;
        }else {
            cout<<n<<" - ";
            cjto.insert(n);
            n = sumascubos(n);
        }
    }
    if(n != 1){
        cout<<n<<" -> no cubinfinito.\n";
    }
    return n == 1;
}

int main(){
    int n;

    while(cin>>n){
        cubifinito(n);
    }

    return 0;
}