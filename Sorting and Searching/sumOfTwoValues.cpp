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

void solve(){
    ll n,x;cin>>n>>x;
    vector<ll> a(n);
    
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> b = a;

    sort(a.begin(),a.end());
    bool found=false;  //to check if elements are there or not
    for(ll i=0;i<n;i++){
        ll find=x-a[i];  //element to find
        ll l=i+1,r=n-1;
        ll mid;
        while(l<=r){
            mid=(l+r)/2;
            if(a[mid]==find){
                found=true;
                break;
            }else if(a[mid]>find){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        if(found==true){
            ll ans1;  //to be sure that position of both element is not same
            ll firste=a[i],seconde=a[mid];  //firstelement and secondelement
            bool firstb=false,secondb=false;  //have we found first or second element
            for(ll j=0;j<n;j++){  //loop to find position of both element
                if( (firste==b[j]) && (!firstb) && ((j+1)!=ans1)){
                    firstb=true;
                    cout<<j+1<<" ";
                    ans1=j+1;
                }
                if( (seconde==b[j]) && (!secondb) && ((j+1)!=ans1)){
                    secondb=true;
                    cout<<j+1<<" ";
                    ans1=j+1;
                }
                if(firstb && secondb){
                    return;
                }
            }
        }
    }
    if(!found)
    cout<<"IMPOSSIBLE";
}



signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //ll t;cin>>t;while(t--)
    solve();
}