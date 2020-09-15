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

    vector<int>a(200005);
    int dp[200005][2];
    int n;

    int ok(int i, int turn){
        if(i>=n)
            return dp[i][turn]=0;
        if(dp[i][turn]!=-1)
            return dp[i][turn];
        if(turn){
            int mini=1e9;
            if(i<n && a[i]==1)
                mini=min(mini,ok(i+1,turn^1)+1);
            if(i<n && a[i]==0)
                mini=min(mini,ok(i+1,turn^1));
            if(i+1<n && a[i]==0 && a[i+1]==1)
                mini=min(mini,ok(i+2,turn^1)+1);
            if(i+1<n && a[i]==0 && a[i+1]==0)
                mini=min(mini,ok(i+2,turn^1));
            if(i+1<n && a[i]==1 && a[i+1]==0)
                mini=min(mini,ok(i+2,turn^1)+1);
            if(i+1<n && a[i]==1 && a[i+1]==1)
                mini=min(mini,ok(i+2,turn^1)+2);
            return dp[i][turn]=mini;
        }
        else{
            int mini=1e9;
            mini=min(ok(i+1,turn^1),ok(i+2,turn^1));
            return dp[i][turn]=mini;
        }
    }
 
    void solve (){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        memset(dp,-1,sizeof(dp));
        ok(0,1);
        cout<<dp[0][1]<<"\n";

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
//            cout<<"Case #"<<i<<": ";
            solve();
        }
        return 0;
    }
