#include "bits/stdc++.h"
using namespace std;
int main()
{
        int n;
	cin >> n;
	int a[n];
	for(int i=0;i < n;i++)
		cin >> a[i];
	int Rabbit1 = 1;
 
	for(int i = 1 ;i < n;i++)
	{
		if(a[i] >= a[i-1]){
			Rabbit1++;
		}else{
			break;
		}
	}
 
	int Rabbit2 = 1;
 
	for(int i = n-2;i>=0;i--)
	{
		if(a[i] >= a[i+1]){
			Rabbit2++;
		}else{
			break;
		}
	}
	cout << min(n , Rabbit2 + Rabbit1);
}
