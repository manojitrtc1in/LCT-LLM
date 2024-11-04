def solve():
    x, y, i, j, k, res = 0, 0, 0, 0, 0, 0
    ch = input()
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)

    x = solve()
    ch = input()
    y = solve()

    for i in range(16):
        if not x & (1 << i):
            continue
        for j in range(16):
            if not y & (1 << j):
                continue
            if ch == '^':
                k = i ^ j
            if ch == '&':
                k = i & j
            if ch == '|':
                k = i | j
            res |= 1 << k
    input()
    return res


N = int(input())
e = 0
print("YES" if not (0x8241 & solve()) else "NO")
