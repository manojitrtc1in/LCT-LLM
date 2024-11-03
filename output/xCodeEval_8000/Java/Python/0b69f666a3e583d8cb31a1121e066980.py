import sys

def calc(l):
    to = l // m
    res = 0
    for i in range(to):
        res += num[i]
    for i in range(to * m, l):
        if isLucky(i):
            res += 1
    return res

def isLucky(i):
    return i == 2 or isP(i) and i % 4 == 1

def isP(i):
    if i < 2:
        return False
    for j in range(2, int(i ** 0.5) + 1):
        if i % j == 0:
            return False
    return True

def pre(n, length):
    np = [False] * n
    np[0] = np[1] = True
    for i in range(n):
        if not np[i]:
            for j in range(i + i, n, i):
                np[j] = True
    div = n // length
    num = [0] * div
    j = 0
    for i in range(n):
        if i == 2 or (not np[i] and i % 4 == 1):
            num[j] += 1
        if (i + 1) % length == 0:
            j += 1
    print(num)

def main():
    n = 310000000
    m = 100000
    l = nextInt()
    r = nextInt() + 1
    res = calc(r) - calc(l)
    print(res)

if __name__ == "__main__":
    main()
