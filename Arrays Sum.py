for _ in range(int(input())):
	n,k=map(int,input().split());d=len(set(list(map(int,input().split()))));j=0;m=0;tot=0
	while(tot<d and k-(j>0)>0):t=k-(j>0);tot+=t;m+=1;j+=1
	print(-1) if tot < d else print(m)
