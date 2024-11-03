from math import pow

s = input()

leading = s[0]

if leading.isdigit():
    lead = False
else:
    lead = True

bits = [0] * 30
cnt = 0

for i in range(len(s)):
    if s[i].isalpha():
        bits[ord(s[i]) - ord('A')] = 1
    elif s[i] == '?':
        cnt += 1

def alpha(n):
    cnt = 10
    res = 1
    for i in range(min(n, 11)):
        res *= cnt
        cnt = max(cnt - 1, 0)
    return res

def beta(n):
    cnt = 9
    res = 9
    for i in range(min(n - 1, 11)):
        res *= cnt
        cnt = max(cnt - 1, 0)
    return res

def power(n, p):
    if p <= 0:
        return 1
    x = power(n, p // 2)
    if p % 2 == 1:
        return x * x * n
    else:
        return x * x

if not lead:
    res = alpha(bits.count()) * power(10, cnt)
else:
    if leading == '?':
        res = alpha(bits.count()) * power(10, cnt - 1) * 9
    else:
        res = beta(bits.count()) * power(10, cnt)

print(res)
