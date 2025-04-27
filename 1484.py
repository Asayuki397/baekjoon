g = int(input())

xn = [g//(k+1) for k in range(g) if g%(k+1) == 0]
res = []

for i in range(len(xn)//2):
    a = xn[i]
    b = xn[len(xn)-i-1]

    if (a+b) % 2 ==0:
        res.append((a+b)//2)

if len(res) == 0:
    print(-1)
else:
    for item in sorted(res):
        print(item)
    