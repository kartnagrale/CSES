#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    ll n;cin>>n;
    vector<int> ps(1e6+10,0);
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        ps[x]++;
    }
    for(int i=1e6;i>=1;i--){
        int c=0;
        for(int j=i;j<=1e6;j+=i){
            c+=ps[j];
        }
        if(c>1){
            cout<<i; return;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}