import sys
from queue import Queue

def input():
  data = sys.stdin.readline()
  return data

N, K = map(int, input().split())

queue = Queue()
dist = Queue()
queue.put(N)
dist.put(0)
curdist = -1

MAX = 100001
visited = [False] * MAX

while not queue.empty():
    
    x = queue.get()
    curdist = dist.get()
    
    visited[x] = True
    
    if x == K:
        break
    
    for next in (x + 1, x - 1, x * 2):
        if 0 <= next < MAX and not visited[next]:
            queue.put(next)
            dist.put(curdist + 1)
    
print(curdist)
