 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <bits/stdc++.h>
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
long long maxv = 1e9;
 
 
long long X,Y,Z,K;
vector<long long>A;
vector<long long>B;
vector<long long>C;
int main(){
	cin>>X>>Y>>Z>>K;
	A.resize(X);
	B.resize(Y);
	C.resize(Z);
	for(int i=0;i<X;i++)
		cin>>A[i];
	for(int i=0;i<Y;i++)
		cin>>B[i];
	for(int i=0;i<Z;i++)
		cin>>C[i];
	sort(A.rbegin(),A.rend());
	sort(B.rbegin(),B.rend());
	sort(C.rbegin(),C.rend());
	vector<long long>ab;
	for(int i=0;i<X;i++){
		for(int j=0;j<Y;j++)
			ab.push_back(A[i]+B[j]);
	}
	sort(ab.rbegin(),ab.rend());
	vector<long long>abc;
	for(int i=0;i<(min(K,X*Y));i++){
		for(int j=0;j<Z;j++)
			abc.push_back(ab[i]+C[j]);
	}
	sort(abc.rbegin(),abc.rend());
	for(int i=0;i<K;i++)
		cout<<abc[i]<<"\n";
	return 0;
}
