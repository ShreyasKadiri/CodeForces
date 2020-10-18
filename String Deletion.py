for i in range(int(input())):
    n=int(input())
    s=input()
    x=0
    y=1
    for i in range(1,n):
        if s[i]==s[i-1]:
            x+=1
            x=min(x,y)
        else:
            y+=1
    print(x+(y-x+1)//2)
