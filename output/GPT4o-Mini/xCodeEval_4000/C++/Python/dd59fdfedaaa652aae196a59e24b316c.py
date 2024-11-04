def solve():
    ch = input()[0]
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)

    x = solve()
    ch = input()[0]
    y = solve()
    input()  # consume the newline

    res = 0
    for i in range(16):
        if (x & (1 << i)) != 0:
            for j in range(16):
                if (y & (1 << j)) != 0:
                    if ch == '^':
                        k = i ^ j
                    if ch == '&':
                        k = i & j
                    if ch == '|':
                        k = i | j
                    res |= (1 << k)

    return res

def main():
    input()  # read the number of test cases
    print("YES" if (~0x8421 & solve()) else "NO")

if __name__ == "__main__":
    main()
