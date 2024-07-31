// https://cses.fi/problemset/task/1079
// coeficientes binomial con lucas theorem
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN = 1e6+5, M =1e9+7;
ll f1[mxN], f2[mxN], iv[mxN];

ll CnR(ll a, ll b){ // coeficiente binomial de (a, b)
    return f1[a]*f2[b]%M*f2[a-b]%M;
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
 
    int n;
    cin >> n;
    // inversos modulares
    iv[1] = 1;
    for(int i = 2; i<mxN; ++i){
        iv[i]=M-M/i*iv[M%i]%M;
    }

    f1[0]=f2[0]=1;
    for(int i = 1; i<mxN;++i){
        f1[i]=f1[i-1]*i%M;
        f2[i]=f2[i-1]*iv[i]%M;
    }
    while(n--){
        int a, b;
        cin >> a >> b;
        cout << CnR(a, b) << "\n";
    }
}
