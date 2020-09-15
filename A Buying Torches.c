#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        long long x,y,k;
        scanf("%lld %lld %lld",&x,&y,&k);
        long long ans,a = k*y +k -1;
        ans = (a/(x-1));
        if(ans*(x-1)!=a) ans++;
        ans+=k;
        printf("%lld\n",ans);
    }
    return 0;
}
