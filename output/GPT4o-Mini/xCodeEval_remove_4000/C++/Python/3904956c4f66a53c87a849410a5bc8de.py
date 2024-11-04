from collections import deque
import sys

def read_int():
    return int(sys.stdin.readline().strip())

def read_char():
    return sys.stdin.read(1)

def solve():
    ch = read_char()
    if ch == '0':
        return 1 << 0
    if ch == '1':
        return 1 << 15
    if ch == '?':
        return (1 << 3) | (1 << 12)

    x = solve()
    ch = read_char()
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
    read_char()  # consume the newline character
    return res

def main():
    read_int()
    print("YES" if (~0x8421 & solve()) else "NO")

if __name__ == "__main__":
    main()
