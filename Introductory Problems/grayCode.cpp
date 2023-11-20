#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector<string> solve(int n){
    vector<string> s;
    if(n==1){
        s.push_back("0");
        s.push_back("1");
        return s;
    }
    vector<string> ans=solve(n-1);
    for(int i=0;i<ans.size();i++){
        s.push_back("0"+ans[i]);
    }
    for(int i=ans.size()-1;i>=0;i--){
        s.push_back("1"+ans[i]);
    }
    return s;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    int n;
    cin>>n;
    vector<string> a;
    a=solve(n);
    for(auto x:a) cout<<x<<"\n";
    return 0;
}