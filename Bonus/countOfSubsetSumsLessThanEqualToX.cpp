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


vector<int> subsetSums(int n,vector<int> a){
    vector<int> ans;
    for(int mask=0;mask < (1<<n) ; mask++){     // (1<<n) = 2 to the power n
        int subSum =0;
        for(int j=0;j<n;j++){
            if(mask & (1<<j)){
                subSum +=a[j];
            }
        }
        ans.push_back(subSum);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

void solve(){
    int n=3,X=5;
    vector<int> v={1,2,3};
    vector<int> a,b;

    for(int i=0;i<n;i++){
        if(i&2){
            a.push_back(v[i]);
        }else{
            b.push_back(v[i]);
        }
    }

    auto Sa=subsetSums(a.size(),a);
    auto Sb=subsetSums(b.size(),b);
    ll ans=0;
    for(auto v:Sa){
        ans+=upper_bound(Sb.begin(),Sb.end(),X-v)-Sb.begin();   // uprbond returns iterator can get element by iterator-array.begin();
    }
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}