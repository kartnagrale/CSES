#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define M_PI=3.14159265358979323846
const int M=1e9+7;
ll mod(ll x){ return ((x%M)+M)%M; }
ll add(ll a,ll b){ return mod(mod(a)+mod(b)); }
ll mul(ll a,ll b){ return mod(mod(a)*mod(b)); }
ll binaryExponentiation(ll a,ll b){
    if(b==0) return 1;
    ll ans = binaryExponentiation(a,b/2);
    if(b%2==1) return mul((mul(ans,ans)),a);
    else return mul(ans,ans);
}
bool sortBySecond(const pair<ll,ll> &a, const pair<ll,ll> &b){ return a.second < b.second; }

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    vector<ll> dp(x+1,1e7);

    for(ll i=0;i<n;i++) cin>>a[i];

    dp[0]=0;
    for(ll i=1;i<=x;i++){
        for(ll j=0;j<n;j++){
            if(a[j]<=i)
            dp[i] = min(dp[i],dp[i-a[j]]+1);
        }
    }

    if(dp[x]<1e7)
    cout<<dp[x];
    else
    cout<<-1;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}