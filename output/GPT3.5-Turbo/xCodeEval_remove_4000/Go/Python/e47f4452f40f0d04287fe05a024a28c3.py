MOD = 1000 * 1000 * 1000 + 7

def solve():
    n = readInt()
    a = readInt()
    b = readInt()
    movesNum = readInt()

    dp = [[0] * (n + 1) for _ in range(2)]

    for i in range(1, n + 1):
        dp[0][i] = 1 + dp[0][i - 1]
        if dp[0][i] >= MOD:
            dp[0][i] -= MOD

    for move in range(movesNum):
        for x in range(1, n + 1):
            length = abs(x - b)
            dp[(move & 1) ^ 1][x] = dp[(move & 1) ^ 1][x - 1]
            if length > 1:
                left = max(x - (length - 1), 1)
                right = min(x + (length - 1), n)
                add = dp[(move & 1)][right] - dp[(move & 1)][left - 1]
                if add < 0:
                    add += MOD
                sub = dp[(move & 1)][x] - dp[(move & 1)][x - 1]
                if sub < 0:
                    sub += MOD
                diff = add - sub
                if diff < 0:
                    diff += MOD
                dp[(move & 1) ^ 1][x] += diff
                if dp[(move & 1) ^ 1][x] >= MOD:
                    dp[(move & 1) ^ 1][x] -= MOD

    ans = dp[((movesNum - 1) & 1) ^ 1][a] - dp[((movesNum - 1) & 1) ^ 1][a - 1]
    if ans < 0:
        ans += MOD
    printInt(ans)
    printLine()


def readString():
    return input()

def readLine():
    return input()

def readInt():
    return int(input())

def id8():
    return int(input())

def id4():
    return float(input())

def printString(value):
    print(value, end='')

def printLine():
    print()

def printSpace():
    print(' ', end='')

def printInt(value):
    print(value, end='')

def id5(value):
    print(value, end='')

def id6(value):
    print(value, end='')

def maxInt(a, b):
    return max(a, b)

def minInt(a, b):
    return min(a, b)

def absInt(a):
    return abs(a)

def id2(a, b):
    return max(a, b)

def id9(a, b):
    return min(a, b)

def id14(a):
    return abs(a)

def id11(a, b):
    return max(a, b)

def id0(a, b):
    return min(a, b)

def id12(a):
    return abs(a)

solve()
