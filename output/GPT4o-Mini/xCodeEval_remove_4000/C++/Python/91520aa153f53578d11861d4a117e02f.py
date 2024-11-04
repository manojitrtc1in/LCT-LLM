from sys import stdin, stdout

EPS = 0.000000001
id0 = 1000000000
INF64 = 1000000000000000000
INF32 = 1000000000

def to_int(s):
    x = 0
    for char in s:
        x *= 10
        x += ord(char) - ord('0')
    return x

def solve():
    s = stdin.readline().strip()
    st10 = [1] * 20
    for i in range(1, 20):
        st10[i] = st10[i - 1] * 10

    s = s[::-1]
    while s and (s[-1] < '0' or s[-1] > '9'):
        s.pop()
    s = s[::-1]

    VEC = []
    while s:
        VEC.append(to_int(s))
        s = s[::-1]
        s.pop()
        s = s[::-1]

    VEC.reverse()

    SET = set()
    ans = 0
    for i in range(len(VEC)):
        x = VEC[i]
        while x < 1989 or x in SET:
            x += st10[i + 1]

        SET.add(x)
        ans = x

    stdout.write(str(ans) + '\n')

def main():
    t = int(stdin.readline())
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
