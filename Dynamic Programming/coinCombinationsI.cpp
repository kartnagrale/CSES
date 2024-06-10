#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll m=1e9+7;
void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<ll> dp(x+1,0);

    dp[0]=1;

    for(int i=1;i<=x;i++){
        for(int j=0;j<n;j++){
            if(a[j]<=i){
                dp[i]=(dp[i]+dp[i-a[j]])%m;
            }
        }
    }
    cout<<dp[x];
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}