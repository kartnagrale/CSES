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

set<string> st;
void strings(int i,string s,int n){
    if(i==n) return;
    st.insert(s);
    for(int j=0;j<n;j++){
        swap(s[i],s[j]);
        strings(i+1,s,n);
        swap(s[i],s[j]);
    }
}
void solve(){
    string s;cin>>s;
    strings(0,s,s.size());
    cout<<st.size()<<"\n";
    for(string x:st) cout<<x<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}