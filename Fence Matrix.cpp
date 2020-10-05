#include <bits/stdc++.h>
    #include <math.h>
 
    using namespace std;
    typedef long long ll;
    typedef unsigned long long ull;
    # define M_PI  3.14159265358979323846
 
 
    const int M=1e9+7;
    long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
 
    ll modPow(ll a, ll b){
        if(b==0)
            return 1LL;
        if(b==1)
            return a%M;
        ll res=1;
        while(b){
            if(b%2==1)
                res=mul(res,a);
            a=mul(a,a);
            b=b/2;
        }
        return res;
    }
 
    int a[105][105];
    void solve (){
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        ll total=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int other1=a[i][m-j-1];
                int other2=a[n-i-1][j];
                vector<int>b;
                b.push_back(a[i][j]);
                b.push_back(other1);
                b.push_back(other2);
                sort(b.begin(),b.end());
                a[i][j]=a[i][m-j-1]=a[n-i-1][j]=b[1];
                total+=(ll)(b[2]-b[1])+(b[1]-b[0]);
            }
        }
        cout<<(total)<<"\n";
    }
    int main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cout<<fixed;
        cout<<setprecision(10);
//        freopen("timber_input.txt", "r", stdin);
//        freopen("timber_output.txt", "w", stdout);
        int t=1;
        cin>>t;
        for(int i=1;i<=t;i++){
        //    cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }
