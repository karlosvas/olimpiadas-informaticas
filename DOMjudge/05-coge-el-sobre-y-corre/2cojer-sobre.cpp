#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

void max(deque<int> &envelopes, int num){
    while (!envelopes.empty() && envelopes.back() < num) {
        envelopes.pop_back();
    }
    envelopes.push_back(num);
}

bool solve(){
    int n, k;
    cin>>n>>k;
    
    if (n == 0) return false;

    queue<int> cases;
    deque<int> envelopes;

    for (int i= 0; i < k; i++) {
        int cash; cin>>cash;
        cases.push(cash);
        max(envelopes, cash);
    }

    cout<<envelopes.front();

    for(int i = k; i < n; i++){
        int sale = cases.front();
        cases.pop();

        if (envelopes.front() == sale) envelopes.pop_front();

        int num;
        cin>>num;

        cases.push(num);
        max(envelopes, num);
        cout<<" "<<envelopes.front();
    }

    cout<<"\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}