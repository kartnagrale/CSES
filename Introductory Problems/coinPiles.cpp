#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b;cin>>a>>b;
    if((a+b)%3==0){
        if(max(a,b)>2*min(a,b))
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}