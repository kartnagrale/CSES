//https://cses.fi/problemset/task/1639

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
int editDistance(string &s1,string &s2,int n,int m,vector<vector<int>> &memo){
    if(n==0) return m;
    if(m==0) return n;

    if(memo[n][m]!=-1) return memo[n][m];

    if(s1[n-1]==s2[m-1]) return memo[n][m]=editDistance(s1,s2,n-1,m-1,memo);
    
    return memo[n][m]=1+min({
        editDistance(s1,s2,n-1,m,memo),
        editDistance(s1,s2,n,m-1,memo),
        editDistance(s1,s2,n-1,m-1,memo)
    });
}

void Solve() {
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.size(),m=s2.size();
    vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
    cout<<editDistance(s1,s2,n,m,memo)<<'\n';
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