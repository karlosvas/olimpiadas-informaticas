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
        
        // Transportar datos a una lista
        for (int num = 0; num < secLine.size(); num++){
            if (secLine[num] == ' ' || num == secLine.size() - 1) {
                if (num == secLine.size() - 1) pila.push(secLine[num]);
                string res;
                while (!pila.empty()) {
                    res += pila.front();
                    pila.pop();
                }
                listSec.push_back(res);
            } else {
            pila.push(secLine[num]);
            }
        }

        list<string>::iterator it = listSec.begin();
        vector<int> vRow;

        int ism = 1;
        int i = 0;

        if (n > c) {
        ism = c + 1;
        } else {
            while (it != listSec.end()) {
                int e = stoi(*it);
                if(vRow.size() < n){
                    cout<<"vacio, i es "<< i<<" push de "<<e<<"\n";
                    vRow.push_back(e);
                    if(vRow.size() == n){
                        i = 0;
                        it++;
                        continue;
                    }
                }else{
                    cout<<"no vacio i es "<<i<<" actualizando "<<vRow[i]<<" + "<<e<<"\n";
                    vRow[i] += e;
                }
                i++;
                it++;
            }
        }
        
        for(int i = 0; i < vRow.size(); i++){
            int a = vRow[i];
            int b = (i + 1 < vRow.size()) ? vRow[i + 1] : 0;
            if(b != 0){
                cout<<"a "<<a<<" > b "<<b<<"\n";
                 if(a > b){
                ism += 1;
            }
            }
        }
            cout<<"El ism es "<<ism<<"\n";
        // Atendido en la caja ism;
        // cout<<ism<<"\n";
    }
    return 0;
}