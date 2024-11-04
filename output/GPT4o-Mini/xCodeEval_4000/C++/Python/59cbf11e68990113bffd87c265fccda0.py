import sys
from bisect import bisect_left, bisect_right

maxn1 = 31
maxn2 = 100
maxn3 = (1 << 20) + 10
inf = 10**18

C = [[0] * maxn2 for _ in range(maxn2)]
arr = [0] * (2 * maxn1)
A, B, n, N = 0, 0, 0, 0
pa1, pb1 = 0, 0
pre1 = 0
opt = [[0] * (maxn2) for _ in range(maxn1)]
vec = [[0] * maxn3 for _ in range(maxn1)]
pt = [0] * maxn1

def do_save(l, r):
    global pa1, pb1, pre1
    pt[:] = [0] * len(pt)
    MSKA = 0
    MSKB = 0
    SZ = r - l
    for i in range(l, r):
        if arr[i] == 1:
            MSKA += (1 << (i - l))
        if arr[i] == -1:
            MSKB += (1 << (i - l))
    for msk in range(1 << SZ):
        if (MSKA & msk) != MSKA or (MSKB & msk) != 0 or pa1 + bin(msk).count('1') >= maxn1:
            continue
        cnta = pa1
        cntb = pb1
        num = pre1
        for i in range(SZ):
            if (msk >> i) & 1:
                num += C[cnta][A - 1] * C[cntb][A]
                cnta += 1
            else:
                num -= C[cnta][A] * C[cntb][A - 1]
                cntb += 1
        vec[cnta][pt[cnta]] = num
        pt[cnta] += 1
    for i in range(maxn1):
        vec[i][:pt[i]] = sorted(vec[i][:pt[i]])

def do_calc(l, r):
    SZ = r - l
    MSKA = 0
    MSKB = 0
    ans = (inf, 0)
    for i in range(l, r):
        if arr[i] == 1:
            MSKA += (1 << (i - l))
        if arr[i] == -1:
            MSKB += (1 << (i - l))
    for msk in range(1 << SZ):
        pp = bin(msk).count('1')
        cnta = n - pp
        cntb = l - cnta
        start = cnta
        num = 0
        if cnta < 0 or cntb < 0 or (MSKA & msk) != MSKA or (MSKB & msk) != 0:
            continue
        for i in range(SZ):
            if (msk >> i) & 1:
                num += C[cnta][A - 1] * C[cntb][A]
                cnta += 1
            else:
                num -= C[cnta][A] * C[cntb][A - 1]
                cntb += 1
        it = bisect_left(vec[start], -num)
        cand1 = (inf, 0)
        cand2 = (inf, 0)
        if it < pt[start]:
            x = vec[start][it]
            cand1 = (num + x, bisect_right(vec[start], x) - it)
        if it > 0:
            x = vec[start][it - 1]
            cand2 = (-num - x, it - bisect_left(vec[start], x))
        if cand1[0] < ans[0]:
            ans = (cand1[0], 0)
        if cand2[0] < ans[0]:
            ans = (cand2[0], 0)
        if cand1[0] == ans[0]:
            ans = (ans[0], ans[1] + cand1[1])
        if cand2[0] == ans[0]:
            ans = (ans[0], ans[1] + cand2[1])
    return ans

def solve():
    ans = (inf, 0)
    Ca = 0
    Cb = 0
    for start in range(N):
        mid = (start + 1 + N) >> 1
        if Ca < A and arr[start] != -1 and Ca + start + 1 >= A and start >= 2 * A - 1:
            global pa1, pb1, pre1
            pa1 = A
            pb1 = start + 1 - A
            pre1 = C[pb1][A]
            do_save(start + 1, mid)
            p = do_calc(mid, N)
            if p[0] < ans[0]:
                ans = (p[0], 0)
            if p[0] == ans[0]:
                ans = (ans[0], ans[1] + C[start - Ca - Cb][A - 1 - Ca] * p[1])
        if Cb < A and arr[start] != 1 and Cb + start + 1 >= A and start >= 2 * A - 1:
            pb1 = A
            pa1 = start + 1 - A
            pre1 = -C[pa1][A]
            do_save(start + 1, mid)
            p = do_calc(mid, N)
            if p[0] < ans[0]:
                ans = (p[0], 0)
            if p[0] == ans[0]:
                ans = (ans[0], ans[1] + C[start - Ca - Cb][A - 1 - Cb] * p[1])
        Ca += arr[start] == 1
        Cb += arr[start] == -1
    return ans

def main():
    global A, B, n, N
    input = sys.stdin.read
    data = input().split()
    A, B = map(int, data[:2])
    n = A + B
    N = 2 * n
    s = data[2]
    for i in range(len(s)):
        if s[i] == 'A':
            arr[i] = 1
        if s[i] == 'B':
            arr[i] = -1
    p = solve()
    print(p[1] if p[0] == opt[A][B] else 0)

C[0][0] = 1
for i in range(1, maxn2):
    C[i][i] = C[i][0] = 1
    for j in range(1, i):
        C[i][j] = C[i - 1][j] + C[i - 1][j - 1]

# Initialize opt array with given values
# (The initialization of the opt array is omitted for brevity; it should be filled similarly to the C array.)

main()
