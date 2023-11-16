#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int y,x;cin>>y>>x;
    int m=max(x,y);
    int a=m*m-(m-1);
    if(x==y) cout<<a<<"\n";
    else if(y>x){
        if(m%2==0){
            cout<<a+(m-x)<<"\n";
        }
        else{
            cout<<a-(m-x)<<"\n";
        }
    }else{
        if(m%2==0){
            cout<<a-(m-y)<<"\n";
        }
        else{
            cout<<a+(m-y)<<"\n";
        }
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;while(t--)
    solve();
}