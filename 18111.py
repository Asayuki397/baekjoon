import sys
input = sys.stdin.readline

N, M, B = map(int, input().split())
ground = []
for _ in range(N):
    ground += list(map(int, input().split()))

min_height = min(ground)
max_height = max(ground)

freq = [0] * (max_height + 1)
for height in ground:
    freq[height] += 1

result_time = float('inf')
result_height = 0

for h in range(min_height, max_height + 1):
    remove_blocks = 0
    add_blocks = 0
    for height in range(len(freq)):
        if height > h:
            remove_blocks += (height - h) * freq[height]
        elif height < h:
            add_blocks += (h - height) * freq[height]

    if remove_blocks + B >= add_blocks:
        time = remove_blocks * 2 + add_blocks
        if time <= result_time:
            result_time = time
            result_height = h

print(result_time, result_height)