from collections import deque

def bfs(start_r, start_c, M, N, graph, visited):

    q = deque([(start_r, start_c)])
    visited[start_r][start_c] = True

    while q:
        
        r, c = q.popleft()

        for dr, dc in ((-1, 0), (1, 0), (0, -1), (0, 1)):
            nr = r + dr
            nc = c + dc

            if 0 <= nr < M and 0 <= nc < N and not visited[nr][nc] and graph[nr][nc]:
                visited[nr][nc] = True
                q.append((nr, nc))


T = int(input())

for i in range(T):
    M, N, K = map(int, input().split())
    graph = [[False for _ in range(N)] for _ in range(M)]
    visited = [[False for _ in range(N)] for _ in range(M)]

    for j in range(K):
        a, b = map(int, input().split())
        graph[a][b] = True

    cnt = 0

    for x in range(M):
        for y in range(N):
            if not visited[x][y] and graph[x][y]:
                bfs(x, y, M, N, graph, visited)
                cnt += 1
    print(cnt)