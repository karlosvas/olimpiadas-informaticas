#include <iostream>
#include <string>
#include <map>

using namespace std;

bool resolve(){
    int n;
    cin>>n;

    if(n == 0) return false;

    map<string, int> authorNotes;

    for (int i = 0; i < n; i++) {
        string auth, point;

        cin.ignore();
        getline(cin, auth);
        cin>>point;

        if (point == "CORRECTO") {
            authorNotes[auth]++;
        } else {
            authorNotes[auth]--;
        }
    }

    for (const auto& entry : authorNotes){
        if(entry.second != 0){
            cout<< entry.first << ", "<<entry.second <<"\n";
        }
    }
    cout<<"---\n";

    return true;
}

int main() {
    while (resolve());
    return 0;
}
