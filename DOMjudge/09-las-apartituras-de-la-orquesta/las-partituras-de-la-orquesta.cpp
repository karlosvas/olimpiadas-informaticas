#include <iostream>
#include <string>
#include <queue>
using namespace std;

bool resolve(){
    // Partituras que se pueden compar (p)
    // Números de instrumenstos distintos (n)
    int p,n;
    cin>>p>>n;

    if (p < n || p > 200000 || n > 100000) return false;
    // Se garantiza que al menos habra una partitura(p) por cada instrumento diferente (n).

    int num;
    priority_queue<int> pq;
    queue<int> res;

    for(int i = 0; i< n;i++){
        // Cantidad de músicos que hay para cada uno de los instrumentos;
        cin>>num;
        if(num > 1000) return false;
        pq.push(num);
    }

    for(int i= 0; i < p - n;i++){
        num = pq.top() / 2;
        pq.pop();
        pq.push(num);
    }

    cout<<pq.top()<<"\n";
    return true;
}

int main(){
    while(resolve());
    return 0;
}