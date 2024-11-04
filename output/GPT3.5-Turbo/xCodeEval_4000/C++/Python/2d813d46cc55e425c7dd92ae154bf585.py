import queue

n, k = map(int, input().split())
a = [[0] * (n + 2) for _ in range(n + 2)]
out = [0] * 125005
chk = [0] * 125005
c = 0
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]

def solve():
    global c
    global a
    global out
    global chk
    global ans
    global best

    for i in range(1, n + 1):
        s = input()
        for j in range(1, n + 1):
            if s[j - 1] == '.':
                a[i][j] = -1
            else:
                a[i][j] = 0

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if a[i][j] == -1:
                c += 1
                a[i][j] = c
                q = queue.Queue()
                q.put((i, j))
                while not q.empty():
                    t = q.get()
                    for k in range(4):
                        if a[t[0] + di[k]][t[1] + dj[k]] == -1:
                            a[t[0] + di[k]][t[1] + dj[k]] = c
                            q.put((t[0] + di[k], t[1] + dj[k]))

    for i in range(n + 2):
        for j in range(n + 2):
            out[a[i][j]] += 1

    for addi in range(n - k + 1):
        for i in range(addi + 1, addi + k + 1):
            for j in range(k):
                out[a[i][j]] -= 1

        for addj in range(n - k + 1):
            ans = k * k
            for i in range(addi + 1, addi + k + 1):
                out[a[i][addj]] += 1
                out[a[i][addj + k]] -= 1

            for i in range(addi + 1, addi + k + 1):
                p = a[i][addj]
                if p and not chk[p]:
                    chk[p] = 1
                    ans += out[p]
                p = a[i][addj + k + 1]
                if p and not chk[p]:
                    chk[p] = 1
                    ans += out[p]

            for j in range(addj + 1, addj + k + 1):
                p = a[addi][j]
                if p and not chk[p]:
                    chk[p] = 1
                    ans += out[p]
                p = a[addi + k + 1][j]
                if p and not chk[p]:
                    chk[p] = 1
                    ans += out[p]

            for i in range(addi + 1, addi + k + 1):
                chk[a[i][addj]] = 0
                chk[a[i][addj + k + 1]] = 0

            for j in range(addj + 1, addj + k + 1):
                chk[a[addi][j]] = 0
                chk[a[addi + k + 1][j]] = 0

            best = max(best, ans)

        for i in range(addi + 1, addi + k + 1):
            for j in range(n - k + 1, n + 1):
                out[a[i][j]] += 1

    print(best)

solve()
