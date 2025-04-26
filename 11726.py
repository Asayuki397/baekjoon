n = int(input())

memo = [1, 2]

for i in range(n):
    if i == 0 or i == 1:
        continue

    memo.append(memo[i-1] + memo[i-2])

print(memo[n-1] % 10007)