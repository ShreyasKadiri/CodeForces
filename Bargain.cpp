#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define M 1000000007
#define N 100003
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

string s; int n;
ll tens[N], sumTens[N], pref[N], suff[N], prefSum[N], suffSum[N];

ll mulMod(ll, ll); ll addMod(ll, ll);
void readArray(int *, int); void printArray(int *, int);

int main() {
    cin>>s;  n = s.length();

    if(n == 1) {
        cout<<0<<endl;
        return 0;
    }
    if(n == 2) {
        cout<<(s[0] - '0') + (s[1] - '0')<<endl;
        return 0;
    }

    tens[0] = 1, sumTens[0] = 0;
    for(int i=1; i<N; i++) {
        tens[i] = mulMod(tens[i - 1], 10);
        sumTens[i] = addMod(sumTens[i - 1], tens[i]);
    }

    pref[0] = (s[0] - '0'), suff[n - 1] = (s[n - 1] - '0');
    prefSum[0] = pref[0], suffSum[n - 1] = suff[n - 1];

    for(int i=1; i<n; i++) {
        pref[i] = addMod(mulMod(pref[i - 1], 10), (s[i] - '0'));
        prefSum[i] = addMod(prefSum[i - 1], pref[i]);
    }

    ll p = 10;
    for(int i=n-2; i>=0; i--) {
        suff[i] = addMod(mulMod((s[i] - '0'), p), suff[i + 1]);
        suffSum[i] = addMod(suffSum[i + 1], suff[i]);
        p = mulMod(p, 10);
    }    

    ll ans = 0;
    ans = addMod(ans, suffSum[1]);        // 1st digit
    ans = addMod(ans, prefSum[n - 2]);     // last digit

    for(int i=1; i<n-1; i++) {
        ll temp = mulMod(pref[i - 1], sumTens[n - i - 1]);
        temp = addMod(temp, suffSum[i + 1]);

        ans = addMod(ans, temp);
    }

    cout<<ans<<endl;
    return 0;
}

ll mulMod(ll a, ll b) {
    a *= b;
    a %= M;
    return a;
}
ll addMod(ll a, ll b) {
    long long c = (a + b) % M;
    return c;
}
void readArray(int *nums, int n) {
    for(int i=0; i<n; i++) cin>>nums[i];
}
void printArray(int *nums, int n) {
    for(int i=0; i<n; i++) cout<<nums[i]<<" ";
    cout<<endl;
}
