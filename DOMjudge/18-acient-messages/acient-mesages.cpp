#include <iostream>
#include <vector>
#include <map>

using namespace std;
using Matriz = vector<vector<int>> ;

vector<vector<bool>> visit;
Matriz m;

bool blanco = false;
bool negro = true;

int incF[] ={-1,0,1,0};
int incC[] ={0,1,0,-1};

void hexa_to_bin(string const &linea, vector<bool> &v){
    for (int i = 0; i < linea.lenght(); i++){
        int interval = (linea[i] >= 'a') ? (line[i] - 'a' + 10) : (linea[i] - '0')
        for(int  j = 3; j >= 0; --j){
            v[4*i+j] = (interval % 2) ? negro : blanco;
            interval /= 2;
        }
    }
    
}

int dfs(int f, int c){
    visit[f][c] = true;
    string sol;
    
    if(m[f][c] != 0){
        sol += dfs(m[f][c]);
    }

    return 0;
}

bool Sole(){
    int H,W; cin>>H>>W;

    if(H == 0) return false;

    // Matriz(M)
    m.assign(H,vector<int> W,0);
    visit.assing(H,vector<bool> (W, false));

    for(int f= 0; f < H; f++){
        for(int c= 0; c < W; c++){        
            if(!visit && m[f][c] != 0){
                dfs(f,c);
            }
        }
    }
    return true;
}

int main(){
    while(Solve())
    return 0;
}