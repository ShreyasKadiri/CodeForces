#include "bits/stdc++.h"
using namespace std;
int main()
{
  set<int> s;
 	int n, m;
 	cin >> n >> m;
 	for(int i = 0;i < m;i++){
 		int x;
 		cin >> x;
 		s.insert(x);
 	}
 	if(s.size() == n - 1){
 		cout << "YES";
 	}else{
 		cout << "NO";
 	}
}
