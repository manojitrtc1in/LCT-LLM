import sys

MOD = 1000000007
EPS = 0.000000001
INFD32 = 1000000000
INF64 = 1000000000000000000
INF32 = 1000000000
maxN = 100300

def to_int(s):
    x = 0
    for char in s:
        x = x * 10 + (ord(char) - ord('0'))
    return x

def solve():
    s = input().strip()
    st10 = [1] * 20
    for i in range(1, 20):
        st10[i] = st10[i - 1] * 10

    s = s[::-1]
    while s and (s[-1] < '0' or s[-1] > '9'):
        s.pop()
    s = s[::-1]

    VEC = []
    for i in range(len(s), 0, -1):
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

    print(ans)

def main():
    input = sys.stdin.read
    data = input().splitlines()
    t = int(data[0])
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()
