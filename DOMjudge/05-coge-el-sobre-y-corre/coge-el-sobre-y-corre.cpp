#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stack>
using namespace std;

#include <iostream>

using namespace std;

bool solve(){
    int n, k;
    cin >> n >> k;
    
    if (n == 0 | k == 0) return false;
    int posibility= n - k + 1;

        string test;
        cin.ignore();
        getline(cin, test);
        vector<int> testList;
        istringstream iss(test);

        int numero;
        while (iss >> numero) {
            testList.push_back(numero);
        }

        for(int it = 0; it < posibility; it++){
        stack<int> pila;
            // Cada posibilidad es un nuevo caso en el que elije entre k mesajes.
            for(int j= it; j < k + it; j++){
                // Va eligiendo de k veces dentro de cada posibilidad.
                if (pila.empty()) pila.push(testList[j]);
                if (testList[j] > pila.top()) pila.push(testList[j]);
            }
            if(it == posibility -1) cout<<pila.top()<<"\n";
            else cout<<pila.top()<<" ";
        }
    
    return true;
}

int main()
{
    while(solve()){
    }

    return 0;
}