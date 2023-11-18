#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    int total=n*(n+1)/2;
    if(total%2) cout<<"NO\n";
    else{
        cout<<"YES\n";
        cout<<n/2<<"\n";
        for(int i=1;i<=n/4;i++){
            cout<<i<<" ";
        }
        for(int i=n*3/4+1;i<=n;i++){
            cout<<i<<" ";
        }
        cout<<"\n";
        if(n%2) cout<<n/2+1<<"\n";
        else cout<<n/2<<"\n";
        for(int i=n/4+1;i<=n*3/4;i++){
            cout<<i<<" ";
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}