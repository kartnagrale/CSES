#include <bits/stdc++.h>
using namespace std;
// #define int long long
void solve(){
    int n;cin>>n;
    int ans=0;
    for(int i=5;i<=n;i*=5){
        ans+=floor(n/i);
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}