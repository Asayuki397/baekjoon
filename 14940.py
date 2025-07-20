import sys
from queue import Queue

def input():
  data = sys.stdin.readline()
  return data

n, m = map(int, input.split())

graph = [[]]
for i in range(n):
    for j in range(m):
        x = int.input()
        if x == 2:
            goal = (m,n)
        graph[m][n] = x

visited = [[False for i in range(n)] in range(m)]

queue = Queue()
queue.put(goal)

while not queue.empty():
