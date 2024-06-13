/*
  Author          :   Kartik Nagrale
  Codeforces      :   https://codeforces.com/profile/Kartiknagrale
  Codechef        :   https://www.codechef.com/users/kartiknagrale
  Leetcode        :   https://leetcode.com/u/kartikknagrale/
  Github          :   https://github.com/kartnagrale
  Atcoder         :   https://atcoder.jp/users/Kartiknagrale
  Connect         :   https://www.linkedin.com/in/kartik-nagrale/
*/

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int x,n;
    cin>>x>>n;
    set<int> s;
    multiset<int,greater<int>> pq;
    pq.insert(x);
    s.insert(x);
    s.insert(0);
    for(int i=0;i<n;i++){
        int p;cin>>p;
        auto it=s.upper_bound(p);
        int eleHigh=*it;
        it--;
        int eleLow=*it;
        s.insert(p);
        pq.erase(pq.find(eleHigh-eleLow));
        pq.insert(eleHigh-p);
        pq.insert(p-eleLow);
        cout<<*pq.begin()<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}