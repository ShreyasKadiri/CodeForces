#include <bits/stdc++.h>
typedef long long ll;
using namespace std; 
int main(){
	//freopen("input.in","r",stdin);
	//freopen("output.in","w",stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,t;
    cin>>n;
    vector<ll> v(n);
    ll su(0),cnt(0);
    set<ll> s;
    s.insert(0);
    for(auto &it:v){
    	cin>>it;
    	su+=it;
    	if(s.count(su)){
    		cnt++;
    		s.clear();
    		s.insert(0);
    		s.insert(it);
    		su=it;
    	}
    	else s.insert(su);

    }
    cout<<cnt;
	return 0;
}
