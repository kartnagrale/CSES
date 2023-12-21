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

ll n;
vector<ll> a(21);
ll mini=LONG_LONG_MAX;

int appleDivision(ll i,ll sum1,ll sum2){
    if(i==n){
        mini = min (mini, abs(sum1-sum2));
        return mini;
    }
    appleDivision(i+1, sum1+a[i], sum2);
    appleDivision(i+1, sum1, sum2+a[i]);
    return mini;
}

void solve(){
    cin>>n;
    a.resize(n);
    for(int i=0;i<n;i++) cin>>a[i];

    cout<<appleDivision(0,0,0);
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}