from collections import deque
import sys

input = sys.stdin.readline

M, N = map(int, input().split())
# M is the number of columns, and N is the number of rows.
graph = []
visited = [[False for _ in range(M)] for _ in range(N)]
q = deque()
clock = 0

for i in range(N):
    s = list(map(int, input().split()))
    graph.append(s)
    if 1 in s:
        for j in range(M):
            if s[j] == 1:
                # Push as (row, column)
                q.append((i, j))

def bfs(q):
    global clock
    while q:
        clock += 1
        for _ in range(len(q)):
            r, c = q.popleft()
            visited[r][c] = True

            for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
                nr = r + dr
                nc = c + dc

                if 0 <= nr < N and 0 <= nc < M and not visited[nr][nc] and graph[nr][nc] == 0:
                    visited[nr][nc] = True
                    graph[nr][nc] = 1
                    q.append((nr, nc))

bfs(q)

clock -= 1
for i in range(N):
    for j in range(M):
        if graph[i][j] == 0:
            clock = -1
            break

print(clock)