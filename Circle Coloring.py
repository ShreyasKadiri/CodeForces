R=lambda:map(int,input().split())
t,=R()
exec(t*'n,=R();r=[0]*n;i=0\nfor t in zip(R(),R(),R()):i+=1;r[i-1],*_={*t}-{r[i-2],r[i%n]}\nprint(*r)\n')
