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

void solve(){
    ll n;cin>>n;
    vector<int> dp(n+1,1e7);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        string a=to_string(i);
        for(char c:a){
            ll digit=c-'0';
            if(digit!=0)
            dp[i]=min(dp[i],dp[i-digit]+1);
        }
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}