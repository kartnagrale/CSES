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
    vector<ll> a(n);

    vector<ll> p2(n+1);
    for(int i = 2; i <= n; i++){
        p2[i] += p2[i-1];
        ll x = i;
        while(x % 2 == 0)
            p2[i]++, x /= 2;
    }

    ll x=0;
    for(int i=1;i<=n;i++){
        ll p;
        cin >> p;
        
        ll totp2 = p2[n-1] - p2[i-1] - p2[n - i];
        if(totp2 == 0)
            x ^= p;
    }
    cout<<x;

}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}
