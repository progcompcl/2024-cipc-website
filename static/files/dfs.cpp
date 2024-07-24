#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;
vector<int> parent;

void dfs(int u)
{
    for(int v : graph[u]){
        if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            parent[v] = u;
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    graph.resize(n);
    dist.resize(n, -1);
    parent.resize(n, -1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dist[0] = 0;
    dfs(0);
    
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
    cout << endl;

    return 0;
}
