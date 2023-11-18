#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    if(n>0) cout<<0<<"\n";
    if(n>1) cout<<6<<"\n";
    if(n>2) cout<<28<<"\n";
    if(n>3) cout<<96<<"\n";
    for(int i=5;i<=n;i++){
        cout<<((i*i)*(i*i-1)-4*2-8*3-(i-4)*4*4-4*4-(i-4)*4*6-(i-4)*(i-4)*8)/2<<"\n";
    }
    
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}