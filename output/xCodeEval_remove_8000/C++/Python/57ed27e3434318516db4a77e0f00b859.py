import sys

str = input()
res = 1
use = [False] * 1200
zero = 0
all = 10
n = len(str)

for i in range(n):
    if i == 0:
        if str[i] >= 'A' and str[i] <= 'J':
            res *= 9
            all -= 1
            use[ord(str[i])] = True
        elif str[i] == '?':
            res *= 9
    else:
        if str[i] >= 'A' and str[i] <= 'J':
            if use[ord(str[i])]:
                continue
            use[ord(str[i])] = True
            res *= all
            all -= 1
        elif str[i] == '?':
            zero += 1

print(res, end='')
for _ in range(zero):
    print('0', end='')
print()
