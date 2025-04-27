from collections import deque
import sys

input = sys.stdin.readline

graph = []

M, N, K = map(int, input().split())

visited = [[[False for _ in range(M)] for _ in range(N)] for _ in range(K)]
q = deque()

clock = 0

for i in range(K):
    temp = []
    for j in range(N):
        s = list(map(int, input().split()))
        temp.append(s)
        if 1 in s:
            for k in range(M):
                if s[k] == 1:
                    q.append((i, j, k))

    graph.append(temp)

def bfs(q):
    global clock
    while q:
        clock += 1
        for _ in range(len(q)):
            a, b, c = q.popleft()
            visited[a][b][c] = True

            for da, db, dc in ((-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1)):
                na = a + da
                nb = b + db
                nc = c + dc

                if 0 <= na < K and 0 <= nb < N and 0 <= nc < M and not visited[na][nb][nc] and graph[na][nb][nc] == 0:
                    visited[na][nb][nc] = True
                    graph[na][nb][nc] = 1
                    q.append((na, nb, nc))

clock -= 1

bfs(q)

for i in range(K):
    for j in range(N):
        for k in range(M):
            if graph[i][j][k] == 0:
                clock = -1
                break

print(clock)