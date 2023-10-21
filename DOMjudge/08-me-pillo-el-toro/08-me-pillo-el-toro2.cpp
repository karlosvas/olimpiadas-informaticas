#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;


bool resolve(){
    int n;
    cin>>n;
    if(n == 0) return false;

    string auth;
    string point;
    int note = 0;
    int it = 0;

    vector<pair<string, int>> v;

    for(int i = 0; i < n; i++){
        cin.ignore();
        getline(cin, auth);
        cin>>point;

        if(v[it].first != auth && !v.empty()) note = 0;

        if(point == "CORRECTO") note++;
        else if(point == "INCORRECTO") note--;

        if(v.empty()){
            v.push_back({auth, note});
        }else if(v[it].first == auth){
            v[it].second = note;
        }else{
            v.push_back({auth, note});
            it++;
        }
    }

    sort(v.begin(), v.end());
    for (const auto& result : v) {
        if(result.second == 0) continue;
        cout << result.first << ", " << result.second << "\n";
    }

    cout<<"---"<<"\n";
    return true;
}

int main(){
    while(resolve());
    return 0;
}