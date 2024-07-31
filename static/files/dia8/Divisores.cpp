// https://cses.fi/problemset/task/1713
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        set<int> a;
        for(int i = 1; i*i<=n; ++i){
            if(n%i==0){
                a.insert(i);
                a.insert(n/i);
            }
        }
        cout << a.size() << "\n";
    }
}
