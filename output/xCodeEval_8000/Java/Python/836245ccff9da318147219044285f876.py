import sys


class FastReader:
    def __init__(self):
        self.input = sys.stdin.readline()
        self.pointer = 0
        self.tokens = self.input.split()

    def next(self):
        if self.pointer >= len(self.tokens):
            self.tokens = self.input.split()
            self.pointer = 0
        self.pointer += 1
        return self.tokens[self.pointer - 1]

    def nextInt(self):
        return int(self.next())

    def nextLong(self):
        return int(self.next())

    def nextDouble(self):
        return float(self.next())

    def nextLine(self):
        return input()


def main():
    mod = 1000000007
    mod2 = 998244353
    inp = FastReader()
    out = sys.stdout

    n = inp.nextInt()
    a = [0] * n
    input(a, n)
    if n > 66:
        out.write("1\n")
        return
    pref = [0] * (n + 1)
    pref[1] = a[0]
    for i in range(1, n):
        pref[i + 1] = pref[i] ^ a[i]
    gg = 34
    for c in range(n - 1):
        for left in range(c, -1, -1):
            for right in range(c + 1, n):
                if xor(left, c) > xor(c + 1, right):
                    gg = min(gg, right - left - 1)
    out.write(str(gg) if gg != 34 else "-1")
    out.write("\n")


def xor(i, j):
    return pref[j + 1] ^ pref[i]


def sort(a):
    a.sort()


def ruffleSort(a):
    import random
    n = len(a)
    for i in range(n):
        j = random.randint(0, n - 1)
        a[i], a[j] = a[j], a[i]
    a.sort()


def input(a, n):
    for i in range(n):
        a[i] = inp.nextLong()


if __name__ == "__main__":
    main()
