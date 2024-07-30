#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
vector<ll> a, b, c;
vector<int> order;
ll B;

bool solve(ll P){
    vector<ll> d(n), z(n);

    for(int i = 0; i < n; i++){
        d[i] = a[i] - b[i];
        z[i] = P/c[i] - B - a[i];
    }

    for(int i = 0; i < n; i++){
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int &a, int &b) {
        if(d[a] <= 0 && d[b] <= 0){       // Ambos negativos (o cero)
            return z[a] > z[b];
        }else if(d[a] > 0 && d[b] > 0){   // Ambos positivos
            return d[a] + z[a] < d[b] + z[b];
        }else{                            // Distinto signo
            return d[a] < d[b];
        }
    });

    bool valid = true;
    ll acc_sum = 0;
    for(int i = 0; i < n; i++){
        if(acc_sum > z[order[i]]){
            valid = false;
        }
        acc_sum += d[order[i]];
    }
    return valid;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        a.resize(n);
        b.resize(n);
        c.resize(n);
        order.resize(n);

        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i] >> c[i];
        }

        B = 0;
        for(int i = 0; i < n; i++){
            B += b[i];
        }

        ll l = 0, r = 1e18;
        while(l != r){
            ll mid = (l + r) / 2;
            if(solve(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        solve(l);
        for(int i = 0; i < n; i++){
            cout << order[i] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
