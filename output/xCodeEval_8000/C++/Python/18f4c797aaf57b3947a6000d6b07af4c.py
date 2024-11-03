from collections import defaultdict

def push(stk, nn, vis, x):
    if not vis[x]:
        vis[stk[nn]] = True
        stk[nn] = x
        nn += 1
    else:
        j = stk.index(x)
        for i in range(j, nn-1):
            stk[i] = stk[i+1]
        stk[nn-1] = x
    return stk, nn, vis

def main():
    A = input().strip()
    n = len(A)
    m = int(input())
    Q = []
    have = set()
    ans = defaultdict(int)

    for _ in range(m):
        buf = input().strip()
        q = 0
        for c in buf:
            q |= (1 << (ord(c) - ord('a')))
        Q.append(q)
        have.add(q)

    stk = [0] * 26
    nn = 0
    vis = [False] * 26

    for i in range(n):
        stk, nn, vis = push(stk, nn, vis, A[i])
        s = 0
        for j in range(nn, -1, -1):
            s |= (1 << stk[j])
            if (s & (1 << A[i+1])):
                break
            if s in have:
                ans[s] += 1

    for i in range(m):
        print(ans[Q[i]])

if __name__ == "__main__":
    main()
