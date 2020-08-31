t=int(input())
alphabet= [chr(x) for x in range(ord("a"),ord("z")+1)]
i=0
c=0
for i in range(t):
      n=int(input())
      sum={}
      item=0
      j=0
      for item in alphabet:
            sum[item]=0
      for j in range(n):
            s=input()
            l=list(s)
            items=0
            for items in alphabet:
                  sum[items]=sum[items]+l.count(items)
      for ele in alphabet:
            if sum[ele]%n==0:
                  c=1
            else:
                  print("NO")
                  c=0
                  break
      if c==1:
            print("YES")
            
