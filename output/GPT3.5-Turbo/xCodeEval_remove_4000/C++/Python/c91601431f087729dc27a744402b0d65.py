class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __lt__(self, other):
        return self.x * other.y < self.y * other.x

def solve():
    n = int(input())
    p = []
    for _ in range(n):
        x, y = map(int, input().split())
        p.append(Point(x, y))
    
    cur = 0
    for i in range(n):
        if p[i].x < p[cur].x or (p[i].x == p[cur].x and p[i].y < p[cur].y):
            cur = i
    
    s = input()
    s += 'R'
    ans = [cur]
    used = [False] * n
    for i in range(n - 1):
        used[cur] = True
        zero = p[cur]
        a = []
        for j in range(n):
            a.append(Point(p[j].x - zero.x, p[j].y - zero.y))
        
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
    
    for x in ans:
        print(x + 1, end=' ')
    print()

solve()
