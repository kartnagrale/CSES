#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    int a[n]={0};
    cin>>a[0];
    int ans=0;
    for(int i=1;i<n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]){
            ans=ans+a[i-1]-a[i];
            a[i]=a[i]+a[i-1]-a[i];
        }
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}
