#include <iostream>
#include <set>
using namespace std;

//135
int sumascubos (int n){
    int suma = 0;
    while(n > 0){
        int d = n% 10;
        suma += d*d*d;
        n = n / 10;
    }
    return suma;
}

bool cubifinito(int n){
    set<int> cjto;
    while(n != 1 && !cjto.count(n)){
        cjto.insert(n);
        n = sumascubos(n);
    }
    return n == 1;
}

int main(){
    for (int n = 1; n <= 1000;n++) {
        if(cubifinito(n))
        cout<<n<<"\n";
    }
    return 0;
}