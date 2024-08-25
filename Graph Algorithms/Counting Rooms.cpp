#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
bool ispossible(int i,int j,int n,int m,vector<vector<char>> &grid){
    if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='.') return true;
    return false;
}

void deleteroom(int i,int j,int n,int m,vector<vector<char>> &grid){
    grid[i][j]='#';
    if(ispossible(i+1,j,n,m,grid)){
        deleteroom(i+1,j,n,m,grid);
    }
    if(ispossible(i,j+1,n,m,grid)){
        deleteroom(i,j+1,n,m,grid);
    }
    if(ispossible(i-1,j,n,m,grid)){
        deleteroom(i-1,j,n,m,grid);
    }
    if(ispossible(i,j-1,n,m,grid)){
        deleteroom(i,j-1,n,m,grid);
    }
}

void Solve() {
    int n,m;cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='.'){
                ans++;
                deleteroom(i,j,n,m,grid);
            }
        }
    }
    cout<<ans;
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
