//https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();

    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));

    for(int i=0;i<=n;i++) memo[i][0]=i;
    for(int i=0;i<=m;i++) memo[0][i]=i;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1]){
                memo[i][j]=memo[i-1][j-1];
            }else{
                memo[i][j]=1+min({
                    memo[i-1][j],memo[i][j-1],memo[i-1][j-1]
                });
            }
        }
    }
    cout<<memo[n][m]<<'\n';
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