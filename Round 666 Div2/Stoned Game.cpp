#include<bits/stdc++.h>
long long i, t, n, a[110000], s; 
int main() {
	std::cin >> t;
	while (t--)
	{
		std::cin >> n; 
		for (i = s = 0; i < n; i++) { 
			std::cin >> a[i]; s += a[i];
		} 
		std::sort(a, a + n); 
		puts(s >= a[n - 1] * 2 && 1 ^ s % 2 ? "HL" : "T");
	}
}
