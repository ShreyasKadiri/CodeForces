#include<bits/stdc++.h>
using namespace std;
 
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define print_upto(a,n)        for(int i=0;i<n;i++)    cout<<a[i]<<" "; cout<<endl
#define take(x,n)           for(int i=0;i<n;i++)  cin>>x[i];
 
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define watch2(x,y) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<"\n"
#define watch3(x,y,z) cout <<(#x)<<" is "<<(x)<<" and "<<(#y)<<" is "<<(y)<<" and "<<(#z)<<" is "<<(z)<<"\n"
 
#define ll long long
#define ff first
#define ss second
#define null NULL
#define all(c) (c).begin(),(c).end()
#define nl "\n"
 
#define ld long double
#define eb emplace_back
#define pb push_back
#define pf push_front
#define mod 998244353
 
typedef vector<ll> vl;
typedef vector< vl > vvl;
typedef pair< ll, ll> pll;
typedef map< ll, ll> mll;
 
ll fact[300006];
 
ll fast_mod_exp(ll a, ll b, ll m) {
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % m;
 
		a = (a * a) % m;
		b = b >> 1;
	}
 
	return res;
}
 
ll mod_inverse(ll a, ll m) {
	// m is prime
	return fast_mod_exp(a, m - 2, m);
}
 
// ncr = ( n*(n-1)*(n-2)*.....(n-r+1) ) * mod_inverse(fact[r],p);
ll ncr(ll n, ll r, ll p) {
	if (r == 0)
		return 1;
 
	// ll ans = 1;
	// for (ll i = 0; i <= r - 1; i++) {
	// 	ans = (ans * (n - i)) % p;
	// }
 
	return ((fact[n] * mod_inverse(fact[n - r], p)) % p * mod_inverse(fact[r], p)) % p;
}
 
bool cmp(pair<ll, ll>p1 , pair<ll, ll>p2) {
	if (p1.first < p2.first)
		return true;
	else if (p1.first > p2.first)
		return false;
	else {
		return p1.second > p2.second;
	}
}
 
 
int main() {
 
	// Use ctrl+shift+b ( second option )
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt" , "w" , stderr);
#endif
 
	ll n, k;
	cin >> n >> k;
 
	fact[0] = fact[1] = 1;
	for (ll i = 1; i <= 300002; i++) {
		fact[i] = (fact[i - 1] * i ) % mod;
	}
 
	vector<pair<ll, ll>> v;
	for (ll i = 1; i <= n; i++) {
		ll st, en;
		cin >> st >> en;
 
		v.pb({st, 1});
		v.pb({en, 0});
	}
 
	sort(v.begin(), v.end(), cmp);
 
	ll on_so_far = 0;
	ll ans = 0;
 
	for (ll i = 0; i < v.size(); i++) {
		if (v[i].second == 1) {
			if (on_so_far >= k - 1)
				ans =  (ans + ncr(on_so_far, k - 1, mod)) % mod;
			on_so_far++;
		} else
			on_so_far--;
	}
 
	cout << ans << nl;
 
	return 0;
}
 
