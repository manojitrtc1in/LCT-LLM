import sys
import random
from collections import defaultdict

class Fenwick:
    def __init__(self, n):
        self.fw = [0] * (n + 1)

    def update(self, i, d):
        while i < len(self.fw):
            self.fw[i] = max(self.fw[i], d)
            i |= (i + 1)

    def get(self, n):
        result = 0
        while n >= 0:
            result = max(result, self.fw[n])
            n = (n & (n + 1)) - 1
        return result

    def range_query(self, l, r):
        return self.get(r) - self.get(l - 1)

def solution(cin, cout):
    n, m = map(int, cin.readline().split())
    cnt = [0] * (m + 2)

    for _ in range(n):
        l, r = map(int, cin.readline().split())
        cnt[l] += 1
        cnt[r + 1] -= 1

    for i in range(1, m + 1):
        cnt[i] += cnt[i - 1]

    fw_l = Fenwick(100001)
    l = [0] * (m + 1)
    for i in range(1, m + 1):
        l[i] = fw_l.get(cnt[i]) + 1
        fw_l.update(cnt[i], l[i])

    fw_r = Fenwick(100001)
    r = [0] * (m + 1)
    for i in range(m, 0, -1):
        r[i] = fw_r.get(cnt[i]) + 1
        fw_r.update(cnt[i], r[i])

    ans = 0
    for i in range(1, m + 1):
        ans = max(ans, l[i] + r[i] - 1)

    cout.write(f"{ans}\n")

def main():
    random.seed()
    input = sys.stdin.read
    data = input().splitlines()
    cin = iter(data)
    cout = sys.stdout

    queries = 1
    for _ in range(queries):
        solution(cin, cout)

if __name__ == "__main__":
    main()
