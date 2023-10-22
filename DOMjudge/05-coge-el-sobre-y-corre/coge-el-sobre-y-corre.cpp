#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;


bool solve(){
    int n, k;
    cin>>n>>k;
    
    if (n == 0 || k == 0) return false;

        string test;
        cin.ignore();
        getline(cin, test);

        vector<int> testList;
        istringstream iss(test);

        int number;
        while (iss >> number) {
            testList.push_back(number);
        }
        
        priority_queue<int> pq;
        vector<int> v;
        int it= 0;
        for(int element : testList){
            if(it == k){
                it= 0;
                v.push_back(pq.top());
                while (!pq.empty()){
                    pq.pop();
                }
            }
            pq.push(element);
            it++;
        }

        while (!pq.empty()) {
            v.push_back(pq.top());
            pq.pop();
        }

        for(int result : v){
            cout<<result<<" ";
        }

        cout<<"\n";
    return true;
}

int main(){
    while(solve());
    return 0;
}