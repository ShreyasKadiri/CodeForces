for s in [*open(0)][1:]:a,b=map(int,s.split());
print((a-3+b)//b+1 if a>2 else 1)
