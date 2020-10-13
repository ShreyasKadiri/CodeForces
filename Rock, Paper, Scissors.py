n=int(input());
a,b,c=map(int,input().split());
x,y,z=map(int,input().split());
max=min(a,y)+min(b,z)+min(c,x);
min=min(a,n-y)+min(b,n-z)+min(c,n-x);
print(n-min,max)
