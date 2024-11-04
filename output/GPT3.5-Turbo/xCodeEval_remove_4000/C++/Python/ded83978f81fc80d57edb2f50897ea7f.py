import sys

def solve():
    A, B, V = sys.stdin.readline().split()
    nA = len(A)
    nB = len(B)
    nV = len(V)
    A = ' ' + A
    B = ' ' + B
    V = ' ' + V
    prefix = [[0] * 1001 for _ in range(101)]
    for iV in range(nV):
        for C in range(ord('A'), ord('Z')+1):
            prefix[iV][C] = iV + 1
            while prefix[iV][C] > 0:
                if V[1:prefix[iV][C]] == V[iV+2-prefix[iV][C]:iV+1] + chr(C):
                    break
                prefix[iV][C] -= 1
    d = [[[-1] * 101 for _ in range(101)] for _ in range(101)]
    c = [[[-1] * 101 for _ in range(101)] for _ in range(101)]
    for iA in range(1, nA):
        for iB in range(1, nB):
            for iV in range(nV):
                d[iA][iB][iV] = max(d[iA-1][iB][iV], d[iA][iB-1][iV])
                if A[iA] == B[iB]:
                    d[iA][iB][prefix[iV][ord(A[iA])]] = max(d[iA][iB][prefix[iV][ord(A[iA])]], d[iA-1][iB-1][iV] + 1)
                    if d[iA][iB][prefix[iV][ord(A[iA])]] == d[iA-1][iB-1][iV] + 1:
                        c[iA][iB][prefix[iV][ord(A[iA])]] = iV
    mx = 0
    cans = 0
    for iV in range(nV):
        if d[nA-1][nB-1][iV] > mx:
            mx = d[nA-1][nB-1][iV]
            cans = iV
    if mx == 0:
        sys.stdout.write('0\n')
    else:
        iA = nA - 1
        iB = nB - 1
        iV = cans
        ans = []
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
        for ch in reversed(ans):
            sys.stdout.write(ch)
        sys.stdout.write('\n')

def main():
    solve()

if __name__ == "__main__":
    main()
