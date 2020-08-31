#include <bits/stdc++.h>

using namespace std;


#define endl "\n"
typedef long long int ll;
ll longmax=1e63+5;
int intmax=1e9+5;
ll minimum(ll ans,ll total){
if(total<ans){
    return total;
}
return ans;
}
void solve(){
ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    ll c=100005;
    ll ans=1e63+5;
    ll mxx=1e18+5;;
    for(ll i=1;i<=c;i++){
            ll total=0;
            ll power=1;
            ll f=1;
        for(ll j=0;j<n;j++){
            total+=llabs(a[j]-power);
            //total1+=abs(pow(i,j)-a[j]);
            if(mxx/power<i){
                f=0;
                break;
            }
            if(total>=ans){
                break;
            }
            power*=i;
        }
        //cout<<ans<<endl;
        if(!f)break;
        ans=minimum(ans,total);
    }
    //cout<<power<<endl;
    cout<<ans<<endl;
}

int main(){
    solve();
    return 0;
}
