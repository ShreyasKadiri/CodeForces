for s in[*open(0)][1:]:
    n=int(s);
    print(*([[(n-n%3*7%9)//3,n%3//2,n%3%2],[-1]][3!=n<5]))