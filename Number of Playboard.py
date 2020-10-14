for n in[*open(0)][1:]:
	print(2);n=int(n)
	for i in range(n,1,-1):print(i-1,n);n=n+i>>1
