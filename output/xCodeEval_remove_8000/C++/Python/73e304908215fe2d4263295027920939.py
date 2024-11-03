import sys
import math
import time

Mod = 1000000007
INF = 1e9
LINF = 1e18
Pi = 3.141592653589793116
EPS = 1e-9
Gold = ((1+math.sqrt(5))/2)
keymod = [1000000007, 1000000009, 1000000021, 1000000033]
keyCount = len(keymod)

def getbit(s, i):
    return (s >> i) & 1

def onbit(s, i):
    return s | (1 << i)

def offbit(s, i):
    return s & (~(1 << i))

def cntbit(s):
    return bin(s).count('1')

TimeStart = time.time()
TimeEnd = time.time()

def Input():
    global m, h1, a1, x1, y1, h2, a2, x2, y2, vis1, vis2
    m, h1, a1, x1, y1 = map(int, input().split())
    h2, a2, x2, y2 = map(int, input().split())
    vis1 = [-1] * m
    vis2 = [-1] * m

def Solve():
    global vis1, vis2
    vis1[h1] = 0
    id4 = -1
    id5 = -1
    while True:
        z = (h1 * x1 + y1) % m
        if vis1[z] != -1:
            id4 = vis1[z]
            id5 = (vis1[h1] + 1) - vis1[z]
            break
        else:
            vis1[z] = vis1[h1] + 1
        h1 = z
    
    vis2[h2] = 0
    id0 = -1
    id2 = -1
    while True:
        z = (h2 * x2 + y2) % m
        if vis2[z] != -1:
            id0 = vis2[z]
            id2 = (vis2[h2] + 1) - vis2[z]
            break
        else:
            vis2[z] = vis2[h2] + 1
        h2 = z
    
    if vis1[a1] == -1 or vis2[a2] == -1:
        print("-1")
        return
    
    if vis1[a1] < id4 and vis2[a2] < id0:
        if vis1[a1] == vis2[a2]:
            print(vis1[a1])
        else:
            print("-1")
        return
    
    if vis1[a1] >= id4 and vis2[a2] >= id0:
        ans = -1
        for i in range(1000001):
            expected = vis1[a1] + id5 * i
            if (expected - vis2[a2]) % id2 == 0 and (expected - vis2[a2]) // id2 >= 0:
                ans = expected
                break
        print(ans)
        return
    
    if vis1[a1] < id4 and vis2[a2] >= id0:
        if (vis1[a1] - vis2[a2]) % id2 == 0 and (vis1[a1] - vis2[a2]) // id2 >= 0:
            print(vis1[a1])
        else:
            print("-1")
        return
    
    if vis1[a1] >= id4 and vis2[a2] < id0:
        if (vis2[a2] - vis1[a1]) % id5 == 0 and (vis2[a2] - vis1[a1]) // id5 >= 0:
            print(vis2[a2])
        else:
            print("-1")
        return

def main():
    Input()
    Solve()

if __name__ == "__main__":
    main()
