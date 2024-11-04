from collections import deque
import sys

input = sys.stdin.read
data = input().splitlines()

n, k = map(int, data[0].split())
c = 0
a = [[0] * 505 for _ in range(505)]
out = [0] * 125005
chk = [0] * 125005
ans = 0
best = 0
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]

class Pos:
    def __init__(self, ii, jj):
        self.i = ii
        self.j = jj

def solve():
    global c, best, ans
    idx = 1
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            x = data[idx]
            idx += 1
            a[i][j] = -1 if x == '.' else 0

    q = deque()
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if a[i][j] == -1:
                c += 1
                a[i][j] = c
                q.append(Pos(i, j))
                while q:
                    t = q.popleft()
                    for k in range(4):
                        if a[t.i + di[k]][t.j + dj[k]] == -1:
                            a[t.i + di[k]][t.j + dj[k]] = c
                            q.append(Pos(t.i + di[k], t.j + dj[k]))

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

            for j in range(addj + 1, addj + k):
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

            for j in range(addj + 1, addj + k):
                chk[a[addi][j]] = 0
                chk[a[addi + k + 1][j]] = 0

            best = max(best, ans)

        for i in range(addi + 1, addi + k + 1):
            for j in range(n - k + 1, n + 1):
                out[a[i][j]] += 1

    print(best)

def prep():
    return

def main():
    prep()
    if len(data) > 1:
        test_num = int(data[1])
        for test_count in range(1, test_num + 1):
            solve()
    else:
        solve()

if __name__ == "__main__":
    main()
