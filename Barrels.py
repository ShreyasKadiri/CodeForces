I=lambda:map(int,input().split());
t,=I();exec('n,k=I();print(sum(sorted(I())[~k:]));'*t)
