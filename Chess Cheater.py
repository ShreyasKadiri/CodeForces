I=input
for _ in[0]*int(I()):
 n,k=map(int,I().split());s=I();c=s.count('W');n=min(n,c+k);a=sorted(map(len,filter(None,s.strip('L').split('W'))))
 while a and c+a[0]<=n:c+=a.pop(0)
 print((2*n-len(a)or 1)-1)
