import sys
from collections import deque
from math import gcd, log2

MOD = 1000000007
INF = 1 << 61

def extgcd(a, b):
    if a < b:
        return extgcd(b, a)
    if b > 0:
        g, x, y = extgcd(b, a % b)
        return g, y - (a // b) * x, x
    else:
        return a, 1, 0

def main():
    input = sys.stdin.read
    data = input().split()
    
    m = int(data[0])
    h1, a1, x1, y1 = map(int, data[1:5])
    
    t = [h1]
    used = [0] * m
    used[h1] = 1
    
    while True:
        tmp = (t[-1] * x1 + y1) % m
        t.append(tmp)
        if used[tmp]:
            break
        used[tmp] = 1
    
    used = [0] * m
    h2, a2, x2, y2 = map(int, data[5:9])
    used[h2] = 1
    s = [h2]
    
    while True:
        tmp = (s[-1] * x2 + y2) % m
        s.append(tmp)
        if used[tmp]:
            break
        used[tmp] = 1

    l1 = l2 = -1
    mn1 = mn2 = INF
    now = 0
    
    while True:
        if t[-1] == t[now]:
            l1 = len(t) - now - 1
        if t[now] == a1:
            mn1 = now
            break
        now += 1
        if now == len(t):
            break
    
    now = 0
    while True:
        if s[-1] == s[now]:
            l2 = len(s) - now - 1
        if s[now] == a2:
            mn2 = now
            break
        now += 1
        if now == len(s):
            break

    def calc():
        if mn1 != INF and mn2 != INF:
            if mn1 == mn2:
                return mn1
            if mn1 > mn2 and l2 == -1:
                return -1
            if mn1 < mn2 and l1 == -1:
                return -1
            if l1 == -1:
                if (mn1 - mn2) % l2 == 0:
                    return mn1
                else:
                    return -1
            if l2 == -1:
                if (mn2 - mn1) % l1 == 0:
                    return mn2
                else:
                    return -1
            if l1 == l2:
                if abs(mn1 - mn2) % l1 == 0:
                    return max(mn1, mn2)
                else:
                    return -1
            if mn2 > mn1 and (mn2 - mn1) % l1 == 0:
                return mn2
            if mn1 > mn2 and (mn1 - mn2) % l2 == 0:
                return mn1

            if abs(mn2 - mn1) % abs(gcd(l1, l2)) != 0:
                return -1
            
            x, y = extgcd(l1, l2)
            x *= (mn2 - mn1) // gcd(l1, l2)
            y *= (mn2 - mn1) // gcd(l1, l2)
            
            if x * l1 + mn1 < max(mn1, mn2):
                x += ((max(mn1, mn2) - x * l1 + mn1 + l1 - 1) // l1 + l2 // gcd(l1, l2) - 1) // (l2 // gcd(l1, l2)) * (l2 // gcd(l1, l2))
            if x * l1 + mn1 >= max(mn1, mn2):
                x -= (x * l1 + mn1 - max(mn1, mn2)) // l1 // (l2 // gcd(l1, l2)) * (l2 // gcd(l1, l2))
            return x * l1 + mn1
        else:
            return -1

    print(calc())

if __name__ == "__main__":
    main()
