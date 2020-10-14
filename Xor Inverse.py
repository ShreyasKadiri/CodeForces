import sys,collections as cc;input = sys.stdin.buffer.readline;
I = lambda : list(map(int,input().split()));
n,=I();

l=I();an=ban=0;ar=cc.defaultdict(list);ar[0]=l;xo=1<<30
for i in range(30,-1,-1):
	a=b=0;pr=cc.defaultdict(list)
	for j in ar:
		ff=j;j=ar[j];aa=bb=0;oo=zz=0
		for x in range(len(j)):
			if j[x]&xo:aa+=zz;oo+=1;pr[2*ff+0].append(j[x])
			else:bb+=oo;zz+=1;pr[2*ff+1].append(j[x])
		a+=aa;b+=bb
	ar=pr
	if a<b:an+=xo;ban+=a
	else:ban+=b
	xo//=2
print(ban,an)

