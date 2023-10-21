#include <iostream>
#include <string>
#include <list>
#include <queue>
using namespace std;

int main()
{   
    // c = Clientes esperando
    // n = Numero de cajas abiertas en ese momento 
    int n, c;
    while (cin>>n>>c) {
        cin.ignore();
        
        if (n < 1 && c < 1) break;

        string secLine;
        getline(cin, secLine);
        
        list<string> listSec;
        queue<char> pila;
        
        // Transportar datos a una lista utilizando queue.
        for (string::size_type num = 0; num < secLine.size(); num++){
            if (secLine[num] == ' ' || num == secLine.size() - 1) {
                if (num == secLine.size() - 1) pila.push(secLine[num]);
                string res;
                while (!pila.empty()) {
                    res += pila.front();
                    pila.pop();
                }
                listSec.push_back(res);
            } else pila.push(secLine[num]);
        }

        list<string>::iterator it = listSec.begin();
        vector<int> vRow;

        int ism = 1;
        int i = 0;

        if (n > c) ism = c + 1;
        else {
            while (it != listSec.end()) {
                int e = stoi(*it);
               if (vRow.size() < static_cast<vector<int>::size_type>(n)){
                    vRow.push_back(e);
                    if(vRow.size() == static_cast<vector<int>::size_type>(n)){
                        i = 0;
                        it++;
                        continue;
                    }
                }else vRow[i] += e;
                i++;
                it++;
            }
        }
        
        // Compara cion de si el actual es mas grande que el siguiente para cambiarse de fila.
        for(vector<int>::size_type i = 0; i < vRow.size(); i++){
            int a = vRow[i];
            int b = (i + 1 < vRow.size()) ? vRow[i + 1] : 0;
                if(b != 0){
                    if(a > b){
                    ism += 1;
                }
            }
        }
        // Fila en al que deve ir ismael
        cout<<ism<<"\n";
    }
    return 0;
}