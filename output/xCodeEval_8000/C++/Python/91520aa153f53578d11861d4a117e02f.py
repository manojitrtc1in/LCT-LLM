import math

def to_int(s):
    x = 0
    for i in range(len(s)):
        x *= 10
        x += int(s[i])
    return x

def solve():
    s = input()
    st10 = [1] * 20
    for i in range(1, 20):
        st10[i] = st10[i-1] * 10
    s = s[::-1]
    while s[-1] < '0' or s[-1] > '9':
        s = s[:-1]
    s = s[::-1]
    VEC = []
    for i in range(len(s), 0, -1):
        VEC.append(to_int(s))
        s = s[::-1]
        s = s[:-1]
        s = s[::-1]
    VEC = VEC[::-1]
    SET = set()
    ans = 0
    for i in range(len(VEC)):
        x = VEC[i]
        while x < 1989 or x in SET:
            x += st10[i+1]
        SET.add(x)
        ans = x
    print(ans)

t = int(input())
for _ in range(t):
    solve()
