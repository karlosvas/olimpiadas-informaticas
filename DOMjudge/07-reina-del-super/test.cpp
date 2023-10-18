#include <iostream>
#include <string>
#include <list>
#include <queue>
#include <stack>
using namespace std;

int main()
{   
    // c = Clientes esperando
    // n = Numero de cajas abiertas en ese momento 
    int n, c;
    while (cin>>n>>c) {
        // cout<<"Empieza"<<"\n";
        cin.ignore();
        
        if (n < 1 && c < 1) break;

        string secLine;
        getline(cin, secLine);
        
        list<string> listSec;
        queue<char> pila;
        
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
        int ism = 1;
        queue<int> filas;
        vector<int> v;

        if(n > c) ism = c + 1;
        // Si el numero de cajas disponibles es mayor que el numero de personas en la fila ismael se dirijira a ala siguiente fila despues de el ultimo e la fila.
        else{
            int a;
            int x;

            while (it != listSec.end()){
                cout<<"n es "<<n<<" vsice "<<v.size()<<"\n";
                if(v.size() == n){
                    // indice 3
                    for(int k = 0; k < v.size() + x; k++){
                        a = v[k] + stoi(*it);
                        cout<<v[k]<<"\n";
                        v.pop_back();
                    }
                    
                }else{
                    a = stoi(*it);
                    v.push_back(a);
                }
                cout<<ism<<" ism\n";
                x++;
                it++;
            }

                // if (a > next){
                //     ismael++;
                // }
        }
        // cout<<"ismael "<<ismael<<"\n";
        // cout<<ismael<<"\n";
    }
    return 0;
}

// queue<int>filas[n];

//             while (it != listSec.end()){
//             int actual = stoi(*it);
//             quRow.push(actual);

//             it++;
//             if (it != listSec.end()) {
//                 int next = stoi(*it);
//                 if(actual > next){
//                     if(filas[x].empty()){
//                     filas[x].push(actual);
//                     }
//                 }
//             }
                
//             }
// // int pilaNext = 0;
                // if (ism == n){
                //     int pilaActual;
                //     while (!quRow.empty()){
                //         pilaActual += quRow.front();
                //         quRow.pop();
                //         pilaNext += quRow.front();
                //         quRow.pop();
                //     }
                //     actual += pilaActual;
                //     ism= 1;
                // }
                //     cout<<"imsael"<<ism<<"\n";
                // if (it != listSec.end()){
                //     // Si el actual tarda mas que el siguiente y este existe, isamel se dirije a la siguiente fila.
                //     int next = stoi(*it);
                //     if(pilaNext != 0) next = next + pilaNext;
                //     quRow.push(actual);
                //     quRow.push(next);
                //     if (actual > next){
                //         ism++;
                //     }
                //     cout<<actual<<" "<<next<<"\n";
                // }