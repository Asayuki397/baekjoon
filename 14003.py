n = int(input())

a = list(map(int, input().split()))
a = sorted(list(set(a)))


print(len(a))

string = ""
for num in a:
    string += str(num) + " "

print(string[:-1])