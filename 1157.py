k = input().upper()
count = {}


for char in k:
    if count.get(char) == None:
        count[char] = 1
    else: count[char] += 1

maxvalue = max(count.values())

ans = [k for k,v in count.items() if v == maxvalue]

if len(ans) > 1:
    print("?")
else: print(ans[0])