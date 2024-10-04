// #include <iostream>
// #include <sstream>
// #include <deque>
// #include <ctime>
// #include <string>
// #include <vector>

// using namespace std;

// void casos(int n){
//     if (n < 0 & || n > 3000) return;
//     // Creo una pila para la comparación.
//     deque<int> stackAccidentes;
//     deque<string> stackFechas;
//     string solution;
    
//     while (n > 0){
//         string str;
//         getline(cin, str);
//         // cin.ignore();
//         istringstream stream(str);
//         // Defino la fecha y los accidentes separados por espacios.
//         string fecha, accidentes;
//         stream >> fecha;
//         stream >> accidentes;
//         // Convierto a numero los accidentes y los pusheo a la pila.
//         int numAcc = stoi(accidentes);
//         stackFechas.push_back(fecha);

//         if(n == 1){
//             // Si ha llegado al ultimo bucle que diga cual de toda la sucesion a sdo mayor.
//             if(solution.empty()) cout<<stackFechas[0]<<"\n";
//             else cout<<solution<<"\n";

//         }else if(!stackAccidentes.empty()){
//             stackAccidentes.push_back(numAcc);

//             if(stackAccidentes.front() > stackAccidentes.back()){
//                 solution += fecha;
//                 cout<<solution<<"\n";
//             }
//             cout<<fecha<<"\n";
//             // Vaciando pila si encuentra un numero mayor que el anterior.
//             stackAccidentes.pop_back();
//             stackAccidentes.pop_back();

//         }else{
//             stackAccidentes.push_back(numAcc);
//             cout<<"NO HAY\n";
//         }
//         n--;
//     }
//     return;
// }

// int main() {
//     int n;
    
//     while (cin>>n){
//         cin.ignore();
//         casos(n);
//         cout<<"---\n";
//     }
    

    
//     return 0;
// }