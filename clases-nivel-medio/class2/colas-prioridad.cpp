#include <iostream>
#include <queue>

using namespace std;

int main(){
    vector<int> v = {1,18,23,4,78,12};

    // Ordenando de mayor a menor
    // priority_queue<int> pq(v.begin() + 1, v.end());

    // Ordenando de menor a mayor.
    priority_queue<int, vector<int>, greater<int>> pq(v.begin(), v.end() -1);
    // priority_queue<int> vector<int>, less<int>> pq;  => Valor por defecto

    pq.push(20);
    while(!pq.empty()){
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}