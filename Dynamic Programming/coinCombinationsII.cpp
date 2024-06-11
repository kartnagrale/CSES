#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;

//space complexity n*x
void solve(){
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<vector<int>> dp(n+1,vector<int> (x+1));
    for(int i=0;i<n;i++){
        dp[i][0]=1;
    }
    for(int i=n-1;i>=0;i--){
        for(int sum=1;sum<=x;sum++){
            int skipping=dp[i+1][sum];
            int picking=0;
            if(a[i]<=sum){
                picking=dp[i][sum-a[i]];
            }
            dp[i][sum]=(skipping+picking)%m;
        }
    }
    cout<<dp[0][x];
}

//space complexity x
void solve2(){
    int n,x;cin>>n>>x;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> nextState(x+1,0);
    nextState[0]=1;

    for(int i=n-1;i>=0;i--){
        vector<int> currState(x+1,0);
        currState[0]=1;
        for(int sum=1;sum<=x;sum++){
            int skipping=nextState[sum];
            int picking=0;
            if(a[i]<=sum){
                picking=currState[sum-a[i]];
            }
            currState[sum]=(skipping+picking)%m;
        }
        nextState=currState;
    }
    cout<<nextState[x];
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int t;cin>>t;while(t--)
    solve2();
}