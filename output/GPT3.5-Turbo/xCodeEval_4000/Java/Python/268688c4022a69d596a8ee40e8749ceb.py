import sys

def solve():
    n = int(input())
    dq = list(map(int, input().split()))
    a = dq.pop(0)
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
            now += dq.pop(0)
        if now != 0:
            a += now
            pre = now
            cnt += 1

    print(cnt, a, b)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()
