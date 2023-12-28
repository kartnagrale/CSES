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

vector<ll> dp(10000000,-1);
ll diceCombinations(ll n){
    if(n==0) return 1;
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = add(add(add(add(add(diceCombinations(n-1),diceCombinations(n-2)), diceCombinations(n-3)),diceCombinations(n-4)), diceCombinations(n-5)),diceCombinations(n-6));
}

void solve(){
    ll n;cin>>n;
    cout<<diceCombinations(n);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}
