#include <iostream>
#include <vector>
#include <sstream>
#include <ctime>

using namespace std;


string casos(int n){
    string strFecha;
    vector<tm> vecAccidentes;
    int numAccidentes;

        while (n > 1 && n < 3000){
            getline(cin, strFecha);
            istringstream stream(strFecha);
            string fecha, accidentes;
            
            stream >> fecha;
            stream >> accidentes;

            std::cout << "Fecha: " << fecha << "\n";
            std::cout << "Accidentes: " << accidentes << "\n";
            n--;
        }
    return strFecha;
}

int main() {
    int n;
    
    while (cin>>n){
        cin.ignore();
        string res = casos(n);
        cout<<res<<"\n";
        cout<<"---";
    }
    
    return 0;
}


