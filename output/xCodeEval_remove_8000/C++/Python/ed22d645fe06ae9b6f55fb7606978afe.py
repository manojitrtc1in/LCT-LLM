import sys

def LIS(n, a):
    b = []
    b.append(a[0])
    for i in range(1, n):
        if b[-1] < a[i]:
            b.append(a[i])
        else:
            l = 0
            r = len(b)
            while l < r:
                m = (l + r) // 2
                if b[m] < a[i]:
                    l = m + 1
                else:
                    r = m
            b[r] = a[i]
    return len(b)

def main():
    b, d = map(int, input().split())
    a = input()
    c = input()
    an = len(a)
    cn = len(c)
    t = [0] * cn
    for i in range(cn):
        k = t[i]
        for j in range(an):
            if a[j] == c[(i+k)%cn]:
                k += 1
        t[i] = k
    
    tt = [(-1, -1)] * N
    s = 0
    bj = False
    for i in range(b):
        s += t[s%cn]
        if bj:
            continue
        if tt[s%cn][0] == -1:
            tt[s%cn] = (i, s)
        else:
            r = i - tt[s%cn][0]
            s += (s - tt[s%cn][1]) * ((b - i) // r)
            i += ((b - i) // r) * r
            bj = True
    s //= cn*d
    print(s)

if __name__ == "__main__":
    main()
