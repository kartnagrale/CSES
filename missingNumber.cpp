#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    int a[n+1]={0};
    for(int i=0;i<n;i++){
        cin>>a[0];
        a[a[0]]++;
    }
    for(int i=1;i<n+1;i++){
        if(a[i]==0){
            cout<<i;
            return;
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}