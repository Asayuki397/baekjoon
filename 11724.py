import sys
sys.setrecursionlimit(2000)

N, M = map(int, sys.stdin.readline().split())
graph = [[] for _ in range(N+1)]
visited = [False for _ in range(N+1)]

for i in range(M):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

def dfs(graph, v, visited):
    for node in graph[v]:
        if not visited[node]:
            visited[node] = True
            dfs(graph, node, visited)

cnt = 0

for i in range(1, N+1):
    if not visited[i]:
        visited[i] = True
        dfs(graph, i, visited)
        cnt += 1

print(cnt)