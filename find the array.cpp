#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++){
		int n;
		cin>>n;

		int a[n];
		ll sumeven=0,sumodd=0;
		for (int i=0; i<n; i++){
			cin>>a[i];
			if(i&1)
				sumodd += a[i];
			else
				sumeven += a[i];
		}
		int e=1;
		if(sumeven>sumodd)
			e=0;
		for (int i=0; i<n; i++){
			if(i%2==e)
				cout<<a[i]<<" ";
			else
				cout<<"1 ";
		}
		cout<<"\n";
	}
#ifndef ONLINE_JUDGE
	cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
#endif
	return 0;
}
