from heapq import heappush, heappop;
import sys;input=sys.stdin.readline;INF = 10**10

def dijkstra(N, G, s):
    dist = [INF] * N;que = [(0, s)];dist[s] = 0
    while que:
        c, v = heappop(que)
        if dist[v] < c:continue
        for t, cost in G[v]:
            if dist[v] + cost < dist[t]:dist[t] = dist[v] + cost;heappush(que, (dist[t], t))
    return dist[1]
    
N, M = map(int, input().split());sx, sy, fx, fy = map(int, input().split());vs = [];g = [set() for _ in range(M+2)]

for i in range(M):x, y = map(int, input().split());g[0].add((i+2, min(abs(x-sx), abs(y-sy))));g[i+2].add((1, abs(x-fx)+abs(y-fy)));vs.append((i+2, x, y))
vs.sort(key=lambda x:x[1])

for (b, bx, by), (i, x, y) in zip(vs, vs[1:]):c = x-bx;g[i].add((b, c));g[b].add((i, c))
vs.sort(key=lambda x:x[2])

for (b, bx, by), (i, x, y) in zip(vs, vs[1:]):c = y-by;g[i].add((b, c));g[b].add((i, c))
print(min(dijkstra(M+2, g, 0), abs(fy-sy)+abs(fx-sx)))
