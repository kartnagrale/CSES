#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void dfs(int node,int parent,vector<int> &path,bool &found,vector<bool> &vis,vector<vector<int>> &adj){
    if(found) return;
    if(vis[node]){
        if(path.size()>2){
            found=true;
            int c=1;
            string ans=to_string(node)+" ";
            for(int i=path.size()-1;i>=0;i--){
                c++;
                ans+=to_string(path[i]);
                if(path[i]==node) break;
                else ans+=" ";
            }
            cout<<c<<"\n"<<ans;
        }
        return;
    }
    vis[node]=true;
    path.push_back(node);
    for(int child:adj[node]){
        if(child==parent) continue;
        dfs(child,node,path,found,vis,adj);
    }
    path.pop_back();
}

void Solve() {
    int n,m;cin>>n>>m;
    vector<bool> vis(n+1);
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool found=false;
    for(int i=1;i<=n;i++){
        if(vis[i]) continue;
        vector<int> path;
        dfs(i,-1,path,found,vis,adj);
    }
    if(!found){
        cout<<"IMPOSSIBLE";
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
    //     //cout << "Case #" << i << ": ";
    //     Solve();
    // }
    Solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}