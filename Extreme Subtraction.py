def solve(n,a):
   s=sum([max(0,a[i]-a[i+1])
   for i in range(n-1)]):
       print('YES') if s <= a[0] else print('NO')
   for j in range(int(input())):
       solve(int(input()),list(map(int,input().split())))
