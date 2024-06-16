/*
    Author       :   Kartik Nagrale
    Codeforces   :   https://codeforces.com/profile/Kartiknagrale
    Codechef     :   https://www.codechef.com/users/kartiknagrale
    Leetcode     :   https://leetcode.com/u/kartikknagrale/
    Github       :   https://github.com/kartnagrale
    Atcoder      :   https://atcoder.jp/users/Kartiknagrale
    Connect      :   https://www.linkedin.com/in/kartik-nagrale/
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int m = 1e9+7;

int getNum(int n,vector<string> &v){

    vector<vector<int>> dp(n,vector<int> (n,0));

    for(int i=0;i<n;i++){
        if(v[i][0]=='*'){
            break;
        }
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++){
        if(v[0][i]=='*'){
            break;
        }
        dp[0][i]=1;
    }
    
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(v[i][j]=='*') continue;

            dp[i][j] = ( dp[i-1][j] + dp[i][j-1] )%m;
        }
    }
    return dp[n-1][n-1];
}

void solve(){
    int n;cin>>n;
    vector<string> v;
    for(int i=0;i<n;i++){
        string x;cin>>x;
        v.push_back(x);
    }
    cout<<getNum(n,v);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}