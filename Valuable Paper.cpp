#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<db,db> pdd;
struct  ppp{ll l,r,v;}a[100005];
bool cmp(ppp x,ppp y){
    return x.v<y.v;
}
int main(){
    ll n,m;cin>>n>>m;
    for(ll  i=1;i<=m;i++){
        cin>>a[i].l>>a[i].r>>a[i].v;
    }
    sort(a+1,a+1+m,cmp);
    set<ll> in,out;
    for(ll i=1;i<=m;i++){
        in.insert(a[i].r);
        out.insert(a[i].l);
        if(in.size()==n&&out.size()==n){
            cout<<a[i].v<<endl;return 0;
        }
    }
    cout<<-1<<endl;
}
