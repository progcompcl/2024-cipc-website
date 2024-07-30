// https://codeforces.com/problemset/problem/329/B
// Biridian Forest

#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ff first
#define ss second

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int r, c;
vector<vector<char>> grid(r, vector<char>(c));

vector<vector<int>> bfs(int sx, int sy){
    vector<vector<int>> dist(r, vector<int>(c, -1));
    dist[sx][sy] = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});

    while(!q.empty()){
        pair<int, int> pos = q.front();
        q.pop();
        int x = pos.ff, y = pos.ss;

        rep(i, 4){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 0 && nx < r && ny >= 0 && ny < c && grid[nx][ny] != 'T' && dist[nx][ny] == -1){
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> r >> c;

    grid.resize(r, vector<char>(c));
    rep(i, r) rep(j, c) cin >> grid[i][j];

    int sx, sy;
    int ex, ey;
    rep(i, r) rep(j, c) {
        if(grid[i][j] == 'S')
            sx = i, sy = j;
        if(grid[i][j] == 'E')
            ex = i, ey = j;
    }

    vector<vector<int>> dist = bfs(ex, ey);

    int distance_exit = dist[sx][sy];

    int ans = 0;
    rep(i, r) rep(j, c){
        if('0' <= grid[i][j] && grid[i][j] <= '9')
            if(dist[i][j] != -1 && dist[i][j] <= distance_exit)
                ans += (grid[i][j] - '0');
    }
    cout << ans << endl;


    return 0;
}
