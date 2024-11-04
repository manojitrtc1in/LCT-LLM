from collections import deque

def solve():
    n = int(input())
    dq = deque()
    for i in range(n):
        dq.append(int(input()))
    a = dq.popleft()
    b = 0
    pre = a
    cnt = 1
    while dq:
        now = 0
        while now <= pre and dq:
            now += dq.pop()
        if now != 0:
            b += now
            pre = now
            cnt += 1
        
        if not dq:
            break
        
        now = 0
        while now <= pre and dq:
            now += dq.popleft()
        if now != 0:
            a += now
            pre = now
            cnt += 1
    print(cnt, a, b)

for _ in range(int(input())):
    solve()
