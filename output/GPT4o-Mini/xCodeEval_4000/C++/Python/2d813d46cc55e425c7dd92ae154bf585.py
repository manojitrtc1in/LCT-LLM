import sys
from collections import deque
from functools import reduce

MOD = 1000000007
MOD2 = 1000000009
INF = 2000000000
LINF = 8000000000000000000
PI = 3.141592653589793

n, k, p, c = 0, 0, 0, 0
a = [[0] * 505 for _ in range(505)]
out = [0] * 125005
chk = [0] * 125005
ans, best = 0, 0
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]

class Pos:
    def __init__(self, ii=0, jj=0):
        self.i = ii
        self.j = jj

q = deque()

def scan():
    return map(int, sys.stdin.readline().split())

def print_result(*args):
    print(*args)

def solve():
    global best
    global c
    global out
    global chk

    global n, k
    n, k = scan()
    
    for i in range(1, n + 1):
        row = sys.stdin.readline().strip()
        for j in range(1, n + 1):
            a[i][j] = -1 if row[j - 1] == '.' else 0

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

    print_result(best)

def prep():
    pass

def main():
    if len(sys.argv) > 1 and sys.argv[1] == 'USEFILE':
        sys.stdin = open("in.txt", "r")
        sys.stdout = open("out.txt", "w")

    prep()
    if len(sys.argv) > 1 and sys.argv[1] == 'TESTCASE':
        test_num = int(sys.stdin.readline())
        for test_count in range(1, test_num + 1):
            if len(sys.argv) > 1 and sys.argv[1] == 'SPLITCASE':
                print(f"\n>>>>> Test {test_count} <<<<<")
            if len(sys.argv) > 1 and sys.argv[1] == 'PRINTCASE':
                print(f"Case #{test_count}: ", end='')
            solve()
    else:
        solve()

if __name__ == "__main__":
    main()
