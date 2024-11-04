import sys

def solve():
    ch = sys.stdin.read(1)
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)

    x = solve()
    ch = sys.stdin.read(1)
    y = solve()

    res = 0
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
    sys.stdin.read(1)  # consume the newline
    return res

def main():
    N = int(sys.stdin.readline().strip())
    if ~0x8241 & solve():
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
