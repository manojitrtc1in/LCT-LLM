def solve():
    x, y, i, j, k = 0, 0, 0, 0, 0
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

    res = 0
    for i in range(16):
        if not _1(x, i):
            continue
        for j in range(16):
            if not _1(y, j):
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

def main():
    RD()
    if ~0x8421 & solve():
        print("YES")
    else:
        print("NO")

main()
