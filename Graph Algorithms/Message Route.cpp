#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
void Solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> dist(n+1,INT_MAX),parent(n+1);
    queue<int> q;
    dist[1]=0;
    q.push(1);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int child:adj[node]){
            if(dist[child]==INT_MAX){
                dist[child]=dist[node]+1;
                parent[child]=node;
                q.push(child);
            }
        }
    }
    if(dist[n]==INT_MAX) cout<<"IMPOSSIBLE";
    else{
        cout<<dist[n]+1<<'\n';
        vector<int> ans;
        ans.push_back(n);
        while(ans.back()!=1) ans.push_back(parent[ans.back()]);
        reverse(begin(ans),end(ans));
        for(int x:ans) cout<<x<<' ';
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