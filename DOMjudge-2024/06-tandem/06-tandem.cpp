#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long tandem(vector<int> &v, int k){
    long a = 0, b = v.size() - 1, ret = 0;
    sort(v.begin(), v.end());

    while (a < b){
        if(v[a] + v[b] > k){
            b--;
        } else {
            ret += b - a;
            a++;
        }
    }
    return ret;
}

bool solve(){
    int n, k;
    cin >> n >> k;

    if (!cin) return false;

    vector<int> v(n);

    for(auto &value : v)
        cin >> value;

    cout << tandem(v, k) << endl;

    return true;
}

int main(int argc, char const *argv[]) {
    while (solve());
    return 0;
}
