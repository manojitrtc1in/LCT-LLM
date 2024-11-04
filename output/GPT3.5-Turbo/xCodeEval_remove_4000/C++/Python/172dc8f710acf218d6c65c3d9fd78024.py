def merge(a, b):
    if b[0] == 0:
        a[1] += b[1]
        return a
    else:
        b[0] += a[0]
        return b

def build(cur, l, r):
    if l == r:
        if s[l] == 'A':
            tr[cur] = [0, 1]
        else:
            tr[cur] = [1, 0]
    else:
        m = (l + r) // 2
        dcur = cur + cur
        build(dcur, l, m)
        build(dcur + 1, m + 1, r)
        tr[cur] = merge(tr[dcur], tr[dcur + 1])

def get(cur, l, r, x, y):
    if x > r or y < l:
        return []
    if x <= l and r <= y:
        return tr[cur]
    m = (l + r) // 2
    dcur = cur + cur
    return merge(get(dcur, l, m, x, y), get(dcur + 1, m + 1, r, x, y))

s = input()
t = input()
n = len(s)
s += t
sn = len(s)
tr = [[0, 0] for _ in range(sn * 4)]
build(1, 0, sn - 1)
q = int(input())
ans = ""
for _ in range(q):
    l = [0, 0]
    r = [0, 0]
    for i in range(2):
        l[i], r[i] = map(int, input().split())
        l[i] -= 1
        r[i] -= 1
    l[1] += n
    r[1] += n
    a = get(1, 0, sn - 1, l[0], r[0])
    b = get(1, 0, sn - 1, l[1], r[1])
    if a[0] > b[0] or a[0] % 2 != b[0] % 2 or a[1] < b[1]:
        ans += '0'
        continue
    ans += '1' if ((a[0] == b[0] and a[1] % 3 == b[1] % 3) or
                  (a[0] != b[0] and a[0] > 0) or
                  (a[1] > b[1] and a[0] != b[0])) else '0'
print(ans)
