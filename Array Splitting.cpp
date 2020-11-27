int main()
{
    ll n, k, ans = 0, pn; 
    cin>>n>>k;
    vector<ll>a(n),pre(n-1);
    FOR(i,1,n) 
      cin>>a[i-1];
    pre[0] = a[0];
    FOR(i,1,n-2) 
      pre[i] = pre[i-1] + a[i];
    pn = pre[n-2] + a[n-1];
    sort(all(pre));
    FOR(i,0,k-2) {
        ans += -1LL*pre[i];
    }
    ans += pn*k;
    cout<<ans;
    return 0;
}
