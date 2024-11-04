MOD = 10**9 + 7
MAX_MOD = 10**18

class modint:
    def __init__(self, value):
        self.value = value % MOD

    def __add__(self, other):
        if isinstance(other, modint):
            return modint(self.value + other.value)
        else:
            return modint(self.value + other)

    def __sub__(self, other):
        if isinstance(other, modint):
            return modint(self.value - other.value)
        else:
            return modint(self.value - other)

    def __mul__(self, other):
        if isinstance(other, modint):
            return modint(self.value * other.value)
        else:
            return modint(self.value * other)

    def __truediv__(self, other):
        if isinstance(other, modint):
            return self * other.inv()
        else:
            return self * modint(pow(other, MOD - 2, MOD))

    def __radd__(self, other):
        return self + other

    def __rsub__(self, other):
        return -self + other

    def __rmul__(self, other):
        return self * other

    def __rtruediv__(self, other):
        return modint(other) / self

    def __str__(self):
        return str(self.value)

    def __repr__(self):
        return str(self)

    def inv(self):
        return modint(pow(self.value, MOD - 2, MOD))

    def pow(self, n):
        return modint(pow(self.value, n, MOD))

    def __pow__(self, n):
        return self.pow(n)

    def __eq__(self, other):
        if isinstance(other, modint):
            return self.value == other.value
        else:
            return self.value == other

    def __ne__(self, other):
        return not (self == other)

    def __lt__(self, other):
        if isinstance(other, modint):
            return self.value < other.value
        else:
            return self.value < other

    def __le__(self, other):
        return self < other or self == other

    def __gt__(self, other):
        if isinstance(other, modint):
            return self.value > other.value
        else:
            return self.value > other

    def __ge__(self, other):
        return self > other or self == other

    def __neg__(self):
        return modint(-self.value)

    def __pos__(self):
        return self

    def __abs__(self):
        return modint(abs(self.value))

    def __int__(self):
        return self.value

    def __float__(self):
        return float(self.value)

    def __hash__(self):
        return hash(self.value)

def solve():
    n = int(input())
    t = input()
    cnter = []
    for i in range(len(t)):
        if t[i] == '0':
            cnter.append(i * 2 + i % 2)

    hoge = [(modint(0), modint(0))] * 300000
    rev = [(modint(0), modint(0))] * 300000
    nexts = (modint(1), modint(1))
    for i in range(len(cnter)):
        hoge[i + 1] = (hoge[i][0] + nexts[0] * (cnter[i] % 2), hoge[i][1] + nexts[1] * (cnter[i] % 2))
        rev[i + 1] = (rev[i][0] + nexts[0] * ((cnter[i] + 1) % 2), rev[i][1] + nexts[1] * ((cnter[i] + 1) % 2))
        nexts = (nexts[0] * 2, nexts[1] * 2)

    query = int(input())
    for _ in range(query):
        a, b, c = map(int, input().split())
        a -= 1
        b -= 1
        Left = (cnter.index(a * 2), cnter.index((a + c) * 2))
        Right = (cnter.index(b * 2), cnter.index((b + c) * 2))
        if Left[1] - Left[0] != Right[1] - Right[0]:
            print("No")
            continue

        ok = True
        aa = (hoge[Left[1]][0] - hoge[Left[0]][0], hoge[Left[1]][1] - hoge[Left[0]][1])
        if a % 2 == b % 2:
            bb = (hoge[Right[1]][0] - hoge[Right[0]][0], hoge[Right[1]][1] - hoge[Right[0]][1])
        else:
            bb = (rev[Right[1]][0] - rev[Right[0]][0], rev[Right[1]][1] - rev[Right[0]][1])

        if Left[0] != 0:
            aa = (aa[0] / (2 ** Left[0]), aa[1] / (2 ** Left[0]))
        if Right[0] != 0:
            bb = (bb[0] / (2 ** Right[0]), bb[1] / (2 ** Right[0]))

        if aa != bb:
            ok = False

        if ok:
            print("Yes")
        else:
            print("No")

solve()
