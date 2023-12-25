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
bool sortBySecond(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.second < b.second;
}


void solve(){
    ll n;cin>>n;

    ll a,b;
    ll count=1;
    vector<pair<ll,ll>> ab; 
    for(int i=0;i<n;i++){
        cin>>a>>b;
        ab.push_back(make_pair(a,b));
    }

    sort(ab.begin(),ab.end(),sortBySecond);

    int j=0;
    ll current_ending=ab[j].second;
    
    for(int i=0;i<n;i++){
        if(current_ending<=ab[i].first){
            count++;
            current_ending=ab[i].second;
        }
    }
    cout<<count;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}