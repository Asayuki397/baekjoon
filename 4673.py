selfnums = []

for i in range(10000):
    selfnums.append(i+1)

allnums = selfnums.copy()

for num in allnums:
    sum = 0
    sum += num
    for i in str(num):
        sum += int(i)
    
    if sum in selfnums:
        selfnums.remove(sum)

for num in selfnums:
    print(num)