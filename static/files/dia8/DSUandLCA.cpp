// https://codeforces.com/contest/609/problem/E
#include <bits/stdc++.h>
using namespace std; 

#define ll long long
#define ar array

const ll mxN = 2e5+5, M = 1e9+7;
ll n, m, up[20][mxN], mxup[20][mxN], d[mxN];

struct DSU{
    ll p[mxN];
    void init(){
        iota(p, p+mxN-1, 0);
    }
    ll find_set(ll a){
        if(p[a] == a){
            return a;
        }
        return p[a] = find_set(p[a]);
    }
    void unite(ll a, ll b){
        a = find_set(a); 
        b = find_set(b);
        p[b] = a;
    }
}dsu;

struct EDGE{
    ll a, b, w, idx; 
    void read(ll fidx){
        cin >> a >> b >> w, --a, --b;
        idx = fidx; 
    }

};
vector<EDGE> flag;
vector<EDGE> edg;
vector<pair<ll, ll>> adj[mxN];

void dfs(ll u = 0, ll p = -1){
    for(ll i = 1; i<20; ++i){
        up[i][u] = up[i-1][up[i-1][u]];
        mxup[i][u] = max(mxup[i-1][u], mxup[i-1][up[i-1][u]]);
    }
    for(pair<ll, ll> v : adj[u]){
        if(v.first != p){
            d[v.first] = d[u]+1;
            up[0][v.first] = u;
            mxup[0][v.first] = v.second;
            dfs(v.first, u);
        }
    }
}

ll lca(ll a, ll b){
    if(d[a]<d[b]) swap(a, b);
    ll diff = d[a]-d[b];
    for(ll i = 0; i<20; ++i){
        if(diff & (1<<i)){
            a = up[i][a];
        }
    }
    for(ll i = 19; i>=0; --i){
        if(up[i][a] != up[i][b]){
            a = up[i][a]; 
            b = up[i][b];
        }
    }
    if(a == b){
        return a;
    }
    return up[0][a];
}

ll get(ll a, ll b){
    if(d[a]<d[b]) swap(a, b);
    ll diff = d[a]-d[b];
    ll mx = 0;
    for(ll i = 19; i>=0; --i){
        if(diff & (1<<i)){
            mx = max(mx, mxup[i][a]);
            a = up[i][a];
        }
    }
    return mx;
}

int main(){
#ifdef _DEBUG
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);

    cin >> n >> m; 
    dsu.init();
    memset(up, -1, sizeof(up)); 
    memset(mxup, 0, sizeof(up));
    for(ll i = 0; i<m; ++i){
        EDGE x; 
        x.read(i);
        flag.push_back(x);
    }
    sort(flag.begin(), flag.end(), [&](EDGE &a1, EDGE &b1){
        return a1.w < b1.w;
    });
    ll ans = 0; 
    for(ll i = 0; i<m; ++i){
        if(dsu.find_set(flag[i].a) != dsu.find_set(flag[i].b)){
            ans += flag[i].w;
            adj[flag[i].a].push_back({flag[i].b, flag[i].w});
            adj[flag[i].b].push_back({flag[i].a, flag[i].w});
            edg.push_back(flag[i]);
            dsu.unite(flag[i].a, flag[i].b);
        }
    }
    dfs();
    vector<ll> resp(m);
    for(EDGE vals : flag){
        ll x = vals.a; 
        ll y = vals.b;
        ll gap = vals.w;
        ll l = lca(x, y); 
        resp[vals.idx] = ans - max(get(x, l), get(y, l)) + gap;
    }
    for(ll i = 0; i<m; ++i){
        cout << resp[i] << "\n";
    }
}
