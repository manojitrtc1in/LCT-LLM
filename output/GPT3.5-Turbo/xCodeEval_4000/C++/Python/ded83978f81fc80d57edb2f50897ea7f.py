nA, nB, nV, mx, cans = 0, 0, 0, 0, 0
d = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]
prefix = [[0 for _ in range(1001)] for _ in range(101)]
c = [[[0 for _ in range(101)] for _ in range(101)] for _ in range(101)]
ans = []

def solve():
    global nA, nB, nV, mx, cans, d, prefix, c, ans
    A = '#' + input().strip() + '#'
    B = '#' + input().strip() + '#'
    V = '#' + input().strip() + '#'
    nA = len(A)
    nB = len(B)
    nV = len(V)
    for iV in range(nV):
        for C in range(ord('A'), ord('Z')+1):
            prefix[iV][C] = iV+1
            while prefix[iV][C] > 0:
                if V[1:prefix[iV][C]] == V[iV+2-prefix[iV][C]:iV+1] + chr(C):
                    break
                prefix[iV][C] -= 1
    for iA in range(1, nA):
        for iB in range(1, nB):
            for iV in range(nV):
                d[iA][iB][iV] = max(d[iA-1][iB][iV], d[iA][iB-1][iV])
                if A[iA] == B[iB]:
                    d[iA][iB][prefix[iV][ord(A[iA])]] = max(d[iA][iB][prefix[iV][ord(A[iA])]], d[iA-1][iB-1][iV]+1)
                    c[iA][iB][prefix[iV][ord(A[iA])]] = iV
    for iV in range(nV):
        mx = max(mx, d[nA-1][nB-1][iV])
        if mx == d[nA-1][nB-1][iV]:
            cans = iV
    if mx == 0:
        print(0)
    else:
        iA, iB, iV = nA-1, nB-1, cans
        while iA > 0 and iB > 0:
            if c[iA][iB][iV] == -1:
                iA -= 1
            elif c[iA][iB][iV] == -2:
                iB -= 1
            else:
                ans.append(A[iA])
                iV = c[iA][iB][iV]
                iA -= 1
                iB -= 1
    while ans:
        print(ans.pop(), end='')
    print()

solve()
