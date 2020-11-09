mod = 998244353
for _ in range(int(input())):
    N, K = map(int, input().split())
    A = list(map(int, input().split()))
    B = list(map(int, input().split()))
    pos = {a: i for i, a in enumerate(A, 1)}
    seen = {i: 0 for i in range(1, N + 1)}
    for b in B:
        seen[pos[b]] = 1
    seen[0] = seen[N + 1] = 1
    ans = 1
    for b in B:
        ans = ans * (2 - seen[pos[b] - 1] - seen[pos[b] + 1]) % mod
        seen[pos[b]] = 0
    print(ans)
