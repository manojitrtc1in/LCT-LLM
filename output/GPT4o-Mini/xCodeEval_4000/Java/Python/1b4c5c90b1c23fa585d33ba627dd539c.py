import sys
from collections import defaultdict

class Scanner:
    def __init__(self, file=None):
        if file:
            self.br = open(file, 'r')
        else:
            self.br = sys.stdin
        self.st = None

    def next(self):
        while self.st is None or not self.st:
            self.st = self.br.readline().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

def main():
    sc = Scanner()
    t = sc.next_int()
    for _ in range(t):
        n = sc.next_int()
        k = sc.next_int()
        d = sc.next_int()
        a = [sc.next_int() for _ in range(n)]
        hm = {}
        occ = [0] * (n + 1)
        id = 0
        
        for i in range(n):
            if a[i] not in hm:
                hm[a[i]] = id
                id += 1
        
        for i in range(n):
            a[i] = hm[a[i]]
        
        ans = 0
        for i in range(d):
            occ[a[i]] += 1
            if occ[a[i]] == 1:
                ans += 1
        
        ansl = ans
        for i in range(d, n):
            ans1 = ansl
            occ[a[i]] += 1
            if occ[a[i]] == 1:
                ans1 += 1
            occ[a[i - d]] -= 1
            if occ[a[i - d]] == 0:
                ans1 -= 1
            ans = min(ans, ans1)
            ansl = ans1
        
        print(ans)

if __name__ == "__main__":
    main()
