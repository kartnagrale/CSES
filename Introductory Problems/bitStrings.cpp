#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int mod=1e9+7;
    int n;cin>>n;
    int ans=1;
    for(int i=0;i<n;i++){
        ans=(ans*2)%mod;
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}