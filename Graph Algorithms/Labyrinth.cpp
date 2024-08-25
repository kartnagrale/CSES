#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    vector<vector<int>> prevStep(n,vector<int>(m));

    vector<int> dx={-1,0,1,0};
    vector<int> dy={0,1,0,-1};
    string stepDir="URDL";

    queue<pair<int, int>> q;
	pair<int, int> begin, end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            if(grid[i][j]=='A') begin=make_pair(i,j);
            if(grid[i][j]=='B') end=make_pair(i,j);
        }
    }

    q.push(begin);
    vis[begin.first][begin.second]=true;

    while(!q.empty()){
        pair<int,int> curr=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            pair<int,int> next=make_pair(curr.first +dx[i],curr.second+dy[i]);

            if( next.first<0 || next.second<0 || next.first>=n || next.second>=m
                || grid[next.first][next.second]=='#' || vis[next.first][next.second]) continue;

            vis[next.first][next.second]=true;
            prevStep[next.first][next.second]=i;
            q.push(next);
        }
    }

    if(vis[end.first][end.second]){
        cout<<"YES\n";
        vector<int> steps;
        while(end!=begin){
            int prev=prevStep[end.first][end.second];
            steps.push_back(prev);
            end=make_pair(end.first-dx[prev],end.second-dy[prev]);
        }
        reverse(steps.begin(),steps.end());
        cout<<steps.size()<<'\n';
        for(int x:steps) cout<<stepDir[x];
        cout<<'\n';
    }else{
        cout<<"NO\n";
    }
    
}
 
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    Solve();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}