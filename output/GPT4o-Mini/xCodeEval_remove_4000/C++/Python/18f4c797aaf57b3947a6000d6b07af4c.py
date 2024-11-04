from collections import defaultdict

N = 1000009
M = 10009
Z = 26

A = [''] * N
buf = [''] * Z
Q = [0] * M
have = set()
ans = defaultdict(int)
n = 0
m = 0

stk = [0] * Z
nn = 0
vis = [False] * Z

def push(x):
    global nn
    if not vis[x]:
        vis[stk[nn]] = True
        stk[nn] = x
        nn += 1
    else:
        j = 0
        while True:
            if stk[j] == x:
                break
            j += 1
        for j in range(j, nn - 1):
            stk[j] = stk[j + 1]
        stk[nn - 1] = x

def main():
    global n, m
    with open("in.txt", "r") as f:
        A[:] = f.readline().strip()
    
    n = len(A)
    A = [ord(A[i]) - ord('a') for i in range(n)] + [Z]

    m = int(input())
    for i in range(m):
        buf = input().strip()
        for cur in buf:
            Q[i] |= 1 << (ord(cur) - ord('a'))
        have.add(Q[i])

    for i in range(n):
        push(A[i])
        s = 0
        for j in range(nn - 1, -1, -1):
            s |= 1 << stk[j]
            if (s & (1 << A[i + 1])) != 0:
                break
            if s in have:
                ans[s] += 1

    for i in range(m):
        print(ans[Q[i]])

if __name__ == "__main__":
    main()
