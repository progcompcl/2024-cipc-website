#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll INF = 1e18;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    for(int i = 0; i < m; i++){
        int u, v; ll w;
        cin >> u >> v >> w;
        u--; v--;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});  // Si es no dirigido descomentar esta linea
    }

    priority_queue<pii, vector<pii>, greater<pii>> q;

    vector<ll> dist(n, INF);

    int start = 0;
    dist[start] = 0;
    q.push({0, start});
    
    while(!q.empty())
    {
        pii p = q.top(); q.pop();
        ll d = p.first;
        int u = p.second;
    
        if(d != dist[u]) continue;
    
        for(pii a : graph[u])
        {
            int v = a.first, w = a.second;
            if(dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}
