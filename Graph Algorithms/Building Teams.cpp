#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void dfs(int u,bool &possible, vector<int> &vis, vector<int> &team, vector<vector<int>> &adj, int p=0){
    for(int v : adj[u]){
        if(v != p){
            if(!vis[v]){
                team[v] = !team[u];
                vis[v] = true;
                dfs(v,possible, vis, team,adj, u);
            } else
                if(team[v] == team[u])
                    possible = false;
        }
    }
}

void Solve() {
    int n,m;
    cin>>n>>m;
    bool possible;
    vector<int> vis(n+1), team(n+1);
    vector<vector<int>> adj(n+1); 
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    possible = true;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i,possible,vis,team,adj);
        }
    }
    if(!possible)
        printf("IMPOSSIBLE");
    else
        for(int i = 1; i <= n; i++)
            cout<<(team[i]?1:2)<<' ';
    cout<<'\n';
}
 
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int t = 1;
    // // freopen("in",  "r", stdin);
    // // freopen("out", "w", stdout);
    
    // cin >> t;
    // for(int i = 1; i <= t; i++) 
    // {
    //     //cout << "Case #" << i << ": ";
    //     Solve();
    // }
    Solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}