for s in[*open(0)][2::2]:
    a=sorted(map(int,s.split()));
    s=sum(a);print(*(['YES']+a[::2*(s<0)-1],['NO'])[s==0])
