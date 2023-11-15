#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,n) for(int i=0;i<n;i++)
void solve(){
    int n;cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else{
            n=n*3+1;
        }
        cout<<n<<" ";
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}