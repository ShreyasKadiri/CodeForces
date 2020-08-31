#include<bits/stdc++.h>
#define int  long long 
#define loop(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007
#define INF 10000000000000
#define pb push_back
#define lim 1000002
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  
  int t,n,i,m;
   
    cin>>n;
    int a[n+1];

    loop(i,0,n) cin>>a[i];
    if(n>1){
    
    cout<<2<<" "<<n<<endl;

    loop(i,1,n)
    {
    	cout<<a[i]*(n-1)<<" ";
    	a[i]=a[i]*n;
    }
    cout<<endl;
    cout<<1<<" "<<n<<endl;

    loop(i,0,n)
    {
    	if(i) cout<<(-a[i])<<" ";
    	else
    		cout<<0<<" ";
    }
    cout<<endl;}

    cout<<1<<" "<<1<<endl;
    cout<<(-a[0])<<endl;
    if(n==1)
    {
    	cout<<1<<" "<<1<<endl;
    cout<<0<<endl;
    cout<<1<<" "<<1<<endl;
    cout<<0<<endl;
    }


    return 0;}
