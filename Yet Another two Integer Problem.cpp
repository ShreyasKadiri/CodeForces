#include<iostream>
using namespace std;
int main(){
long t;
cin>>t;
long a,b;
for(int i=0; i<t; i++){
cin>>a>>b;
long resta,count;
resta=abs(b-a);
count=0;
if(resta%10>0)
count++;
cout<<resta/10 + count<<'\n';
}
return 0;
}
