#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;cin>>s;
    int c=1,ans=1;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]) c++;
        else c=1;
        ans=max(ans,c);
    }
    cout<<ans;
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}