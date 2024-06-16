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

bool com(const pair<ll,ll> &a,const pair<ll,ll> &b){
    return a.second/a.first > b.second/b.first;
}

long long getMax(ll n,ll x,vector<ll> &price,vector<ll> &pages){
    vector<ll> dp(x+1,0);
    for(int i=0;i<n;i++){
        for(int c=x;c>0;c--){
            if(price[i]>c)
                continue;
            dp[c]=max(dp[c],pages[i]+dp[c-price[i]]);
        }
    }
    return dp[x];
}

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> price(n),pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    cout<<getMax(n,x,price,pages);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}