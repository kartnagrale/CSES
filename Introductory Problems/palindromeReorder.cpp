#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    string s;cin>>s;
    int n=s.size();
    unordered_map<char,int> mp;
    string ans="";
    int count=0;
    char c;
    for(char x:s) mp[x]++;
    for(auto x:mp){
        if(x.second%2==1){
            c=x.first;
            count++;
            if(count>1){ cout<<"NO SOLUTION"; return; }
        }
    }
    if(s.size()%2==0 && count>0) cout<<"NO SOLUTION";
    else{
        for(auto x:mp){
            for(int i=0;i<x.second/2;i++) 
                ans+=x.first;
        }
        cout<<ans;
        if(s.size()%2==1) cout<<c;
        reverse(ans.begin(),ans.end());
        cout<<ans;
    }
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve();
}