import sys
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])

def solve():
    n = int(input().strip())
    p = [Point(*map(int, input().strip().split())) for _ in range(n)]
    
    cur = 0
    for i in range(n):
        if (p[i].x < p[cur].x) or (p[i].x == p[cur].x and p[i].y < p[cur].y):
            cur = i
            
    s = input().strip() + 'R'
    ans = [cur]
    used = [False] * n
    
    for i in range(n - 1):
        used[cur] = True
        zero = p[cur]
        a = [Point(p[j].x - zero.x, p[j].y - zero.y) for j in range(n)]
        
        idx = -1
        for j in range(n):
            if not used[j]:
                if idx == -1:
                    idx = j
                else:
                    if s[i] == 'R' and a[j] < a[idx]:
                        idx = j
                    if s[i] == 'L' and a[idx] < a[j]:
                        idx = j
        
        cur = idx
        ans.append(cur)
    
    print(' '.join(str(x + 1) for x in ans))

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().splitlines()
    solve()
