#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void dfs(int node,vector<vector<int>> &adj,vector<int> &vis){
    vis[node]=1;
    for(int it:adj[node]){
        if(vis[it]==0)
        dfs(it,adj,vis);
    }
}

void Solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    vector<int> vis(n+1,0);
    vector<int> bridges;
    for(int i=0;i<m;i++){
        int node1,node2;
        cin>>node1>>node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            bridges.push_back(i);
            dfs(i,adj,vis);
        }
    }
    cout<<bridges.size()-1<<'\n';
    for(int i=0;i<bridges.size()-1;i++){
        cout<<bridges[i]<<' '<<bridges[i+1]<<'\n';
    }
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
        //cout << "Case #" << i << ": ";
        Solve();
    // }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}