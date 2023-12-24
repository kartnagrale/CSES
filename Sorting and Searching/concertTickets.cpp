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

void solve(){
    ll n,m;cin>>n>>m;

    ll x;
    multiset<ll> a;
    ll b[m];
    for(ll i=0;i<n;i++){
        cin>>x;
        a.insert(x);
    }

    for(ll i=0;i<m;i++){
        cin>>b[i];
        auto it=a.upper_bound(b[i]);
        if(it==a.begin()){
            cout<<-1<<"\n";
            continue;
        }else{
            cout<<*(--it)<<"\n";
            a.erase(it);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}