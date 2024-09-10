//https://cses.fi/problemset/task/2413

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
 
int mod=1e9+7;
vector<int> a(1e6+1),b(1e6+1);

void calculateAnswerForAll(){
    a[0]=1;
    b[0]=1;
    for(int i=1;i<1e6+1;i++){
        a[i]=(2*a[i-1]+b[i-1])%mod;
        b[i]=(4*b[i-1]+a[i-1])%mod;
    }
}

void Solve() {
    int n;cin>>n;
    if(n==1) cout<<2<<'\n';
    else
    cout<<(a[n-1]+b[n-1])%mod<<'\n';
}
 
int32_t main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    calculateAnswerForAll();

    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}