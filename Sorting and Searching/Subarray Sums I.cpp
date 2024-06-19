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
    ll n,x;cin>>n>>x;
    unordered_map<ll,ll> m;
    m[0]=1;
    ll sum=0,ans=0;
    for(int i=0;i<n;i++){
        ll b;cin>>b;
        sum+=b;
        if(m.find(sum-x)!=m.end()){
            ans+=m[sum-x];
        }
        m[sum]++;

    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}