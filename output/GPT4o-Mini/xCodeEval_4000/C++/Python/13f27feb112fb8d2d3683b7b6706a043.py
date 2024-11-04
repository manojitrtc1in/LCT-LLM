def solve():
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

    res = 0
    for i in range(16):
        if ~x & (1 << i):
            continue
        for j in range(16):
            if ~y & (1 << j):
                continue
            if ch == '^':
                k = i ^ j
            if ch == '&':
                k = i & j
            if ch == '|':
                k = i | j
            res |= 1 << k
    input()  # to consume the newline
    return res

def main():
    N = int(input().strip())
    print("YES" if ~0x8241 & solve() else "NO")

if __name__ == "__main__":
    main()
