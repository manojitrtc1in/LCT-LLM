def solve():
    x, y, k, res = 0, 0, 0, 0
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
    input()

    for i in range(16):
        if _1(x, i):
            for j in range(16):
                if _1(y, j):
                    if ch == '^':
                        k = i ^ j
                    if ch == '&':
                        k = i & j
                    if ch == '|':
                        k = i | j
                    res |= _1(k)

    return res

n = int(input())
print("YES" if (~0x8421 & solve()) else "NO")
