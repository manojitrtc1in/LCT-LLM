def solve():
    x, y, i, j, k, res = 0, 0, 0, 0, 0, 0
    ch = input().strip()
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)

    x = solve()
    ch = input().strip()
    y = solve()

    for i in range(16):
        if not (x & (1 << i)):
            continue
        for j in range(16):
            if not (y & (1 << j)):
                continue
            if ch == '^':
                k = i ^ j
            if ch == '&':
                k = i & j
            if ch == '|':
                k = i | j
            res |= 1 << k
    return res

RD()
if ~0x8421 & solve():
    print("YES")
else:
    print("NO")
