from collections import namedtuple
import sys

pii = namedtuple('pii', ['first', 'second'])

def merge(a, b):
    if b.first == 0:
        return pii(a.first, a.second + b.second)
    else:
        return pii(b.first + a.first, b.second)

def build(cur, l, r):
    if l == r:
        if s[l] == 'A':
            tr[cur] = pii(0, 1)
        else:
            tr[cur] = pii(1, 0)
    else:
        m = (l + r) // 2
        dcur = cur + cur
        build(dcur, l, m)
        build(dcur + 1, m + 1, r)
        tr[cur] = merge(tr[dcur], tr[dcur + 1])

def get(cur, l, r, x, y):
    if x > r or y < l:
        return pii(0, 0)
    if x <= l and r <= y:
        return tr[cur]
    m = (l + r) // 2
    dcur = cur + cur
    return merge(get(dcur, l, m, x, y), get(dcur + 1, m + 1, r, x, y))

def solve():
    global s, tr
    t = input().strip()
    s = input().strip()
    n = len(s)
    s += t
    sn = len(s)
    tr = [pii(0, 0)] * (4 * sn)
    build(1, 0, sn - 1)
    
    q = int(input())
    ans = []
    for _ in range(q):
        l = list(map(int, input().split()))
        r = list(map(int, input().split()))
        l[1] += n
        r[1] += n
        l = [x - 1 for x in l]
        r = [x - 1 for x in r]
        
        a = get(1, 0, sn - 1, l[0], r[0])
        b = get(1, 0, sn - 1, l[1], r[1])
        
        if a.first > b.first or a.first % 2 != b.first % 2 or a.second < b.second:
            ans.append('0')
            continue
        
        if (a.first == b.first and a.second % 3 == b.second % 3) or \
           (a.first != b.first and a.first > 0) or \
           (a.second > b.second and a.first != b.first):
            ans.append('1')
        else:
            ans.append('0')
    
    print(''.join(ans))

if __name__ == "__main__":
    input = sys.stdin.read
    solve()
