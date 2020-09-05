#include<iostream>
using namespace std;
#define ll long long
int main(){
int t;
cin>>t;

ll a,b,x,y,n,c,d;
for(ll i=0; i<t; i++){
cin>>a>>b>>x>>y>>n;
ll ans1=0;
c=a,d=b;
ll m=n;
ll l=0,r=0;
l=(c-x);
if(l<=m){
m-=l;
c-=l;
}
else{
l=m;
m=0;
c-=l;
}
r=d-y;
if(r<=m){
m-=r;
d-=r;
}
else{
r=m;
m=0;
d-=r;
}
ans1=c*d;
ll res1=0,res2=0;
res1=(b-y);
if(res1<=n){
n-=res1;
b-=res1;
}
else{
res1=n;
n=0;
b-=res1;
}
res2=a-x;
if(res2<=n){
n-=res2;
a-=res2;
}
else{
res2=n;
n=0;
a-=res2;
}
ans1=min(a*b,ans1);
cout<<ans1<<endl;
}
return 0;
}
