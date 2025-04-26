from collections import deque
import sys

N, M = map(int, sys.stdin.readline().split())
graph = []
visited = [[False for _ in range(N)] for _ in range(M)]

cnt = 0

for i in range(N):
    s = sys.stdin.readline()
    graph.append(s)
    if 'I' in s:
        R = i
        C = s.index('I')

print(R,C)

def bfs(start_r, start_c):
    q = deque([(start_r, start_c)])
    visited[start_r][start_c] = True

    while q:
        print(visited)
        r, c = q.popleft()
        for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]:
            nr, nc = r + dr, r+dc

            if 0 <= nr < M and 0 <= nc < N and not visited[nr][nc] and graph[nc][nr] != 'X':
                visited[nr][nc] = True
                if graph[nc][nr] == 'P':
                    cnt += 1
                q.append((nr, nc))

bfs(R,C)
if cnt == 0:
    print('TT')
else:
    print(cnt)