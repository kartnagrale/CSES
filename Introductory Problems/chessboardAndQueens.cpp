#include<bits/stdc++.h>
#include<math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define M_PI=3.14159265358979323846
const int M=1e9+7;
ll mod(ll x){ return ((x%M)+M)%M; }
ll add(ll a,ll b){ return mod(mod(a)+mod(b)); }
ll mul(ll a,ll b){ return mod(mod(a)*mod(b)); }
ll binaryExponentiation(ll a,ll b){
    if(b==0) return 1;
    ll ans = binaryExponentiation(a,b/2);
    if(b%2==1) return mul((mul(ans,ans)),a);
    else return mul(ans,ans);
}
bool sortBySecond(const pair<ll,ll> &a, const pair<ll,ll> &b){ return a.second < b.second; }

vector<int> placed;
vector<string> a; 
int ans=0;

void rec(int row){
    if(row==8){
        ans++;
        return;
    }
    for(int col=0;col<8;col++){
        if(a[row][col]=='.'){
            bool safe=1;
            for(int pRow=0;pRow<row;pRow++){
                int pCol=placed[pRow];
                if(pCol==col || (abs(row-pRow)==abs(col-pCol))){
                    safe=0;
                }
            }
            if(safe){
                placed.push_back(col);
                rec(row+1);
                placed.pop_back();
            }
        }
    }
}
void solve(){
    for(int i=0;i<8;i++){
        string s;
        cin>>s;
        a.push_back(s);
    }
    rec(0);
    cout<<ans;
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}