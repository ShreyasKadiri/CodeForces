#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,a,c,f;
    string s,x;
    cin>>t;
    while(t--){
        f=1;
        x="";
        cin>>n;
        a=n;
        while(n--){
            cin>>s;
            x+=s;
        }
        sort(x.begin(),x.end());
        c=1;
        for(int i=0; i<x.size(); i++){
            if(x[i]==x[i+1])
            c++;
            else
            {
                if(c%a!=0)
                {
                    f=0;
                    break;
                }
                else
                c=1;
            }
        }
        
        if(f==1)
        cout<<"YES"<<endl;
        else
        cout<<"NO"<<endl;  
    }   
}
