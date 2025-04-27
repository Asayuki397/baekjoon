n = int(input())
connected = int(input())

graph = [[] for i in range(n+1)]
visited = [False for _ in range(n+1)]

for i in range(connected):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

cnt = 0

def worm(i):

    visited[i] = True

    global cnt
    cnt += 1

    global graph

    for i in graph[i]:
        if not visited[i]:
            worm(i)

worm(1)

print(cnt - 1)