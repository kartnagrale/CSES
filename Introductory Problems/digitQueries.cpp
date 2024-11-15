#include <bits/stdc++.h>
using namespace std;
#define int long long
int power(int a,int b){
    int res=1;
    while(b>0){
        if(b&1){
            res=(res*a);
        }
        a=a*a;
        b>>=1;
    }
    return res;
}
int finddigit(int n){
    int digits=1,base=9;
    while(n-digits*base>0){
        n-=digits*base;
        base*=10;
        digits++;
    }
    int index=n%digits;
    int res=power(10,(digits-1))+(n-1)/digits;
    if(index!=0) res=res/power(10,digits-index);
    return res%10;
}
void solve(){
    int n;cin>>n;
    cout<<finddigit(n)<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    solve();
}


// The idea is to divide the problem in three parts:
// Find the interval in which the Nth digit lies.
// Calculate the number which contains the Nth digit.
// Find out which digit in the number is the result.
// Identify the interval in which the Nth digit is located by calculating the number of digits in each interval. For instance, there are 9 (1*9) digits in the interval 1 - 9, 180 (2*90) digits in the interval 10 - 99, 2700 (3*900) digits in the interval 100 - 999, and so on. Subtract N with the number of digits in the interval (base*digits) and stop if it is less than zero. Now to find the target number, we know that the first 'd' digit number would be 10^(d-1), adding (N-1)/d to it would give us our target number. Index of the Nth digit is N % d. If index equals to 0, it means the target digit is the last digit of number else divide the target number by 10^(digits - index) and return the last digit which is our result.

