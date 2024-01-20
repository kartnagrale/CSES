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

int s,ra,pa,rb,pb,c;
int allowed[10][10];

inline bool check(int x,int y){
    if((x>=1) && (y>=1)&& (x<=s) && (y<=2*x-1) && (allowed[x][y])==0) return true;
    else return false;
}

int getBest(int a,int b,int x,int y){
    vector<pair<int,int>> move1,move2;

    if(check(a,b-1)){
        move1.emplace_back(make_pair(a,b-1));
    }
    if(check(a,b+1)){
        move1.emplace_back(make_pair(a,b+1));
    }
    if(b%2==0){
        if(check(a-1,b-1)) move1.emplace_back(make_pair(a-1,b-1));
    }else{
        if(check(a+1,b+1)) move1.emplace_back(make_pair(a+1,b+1));
    }

    if(check(x,y-1)){
        move2.emplace_back(make_pair(x,y-1));
    }
    if(check(x,y+1)){
        move2.emplace_back(make_pair(x,y+1));
    }
    if(y%2==0){
        if(check(x-1,y-1)) move2.emplace_back(make_pair(x-1,y-1));
    }else{
        if(check(x+1,y+1)) move2.emplace_back(make_pair(x+1,y+1));
    }

    if(move1.empty() && move2.empty()){
        return 0;
    }else if(!move1.empty()){
        int best=-1000;
        for(auto &v:move1){
            allowed[v.first][v.second]=1;
            best = max(best , 1-getBest(x,y,v.first,v.second));
            allowed[v.first][v.second]=0;
        }
        return best;
    }else{
        return -getBest(x,y,a,b);
    }
}

void solve(){
    cin>>s>>ra>>pa>>rb>>pb>>c;
    memset(allowed,0,sizeof(allowed));
    allowed[ra][pa]=1;
    allowed[rb][pb]=1;
    for(int i=0;i<c;i++){
        int x,y;
        cin>>x>>y;
        allowed[x][y]=1;
    }
    cout<<getBest(ra,pa,rb,pb)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c=1;
    ll t;cin>>t;while(t--){
        cout<<"Case #"<<c++<<": ";
        solve();
    }
    
}
