k = list(map(str, input().split(' ')))

if k[0] == '':
    k.pop(0)

if k[len(k)-1] == '':
    k.pop(len(k)-1)
    
print(len(k))