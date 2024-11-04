MOD = 998244353
MAX_MOD = 1000000007

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

    def __repr__(self):
        return str(self.value)

    def inv(self):
        return pow(self.value, MOD - 2, MOD)

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
            aa = (aa[0] / pow(2, Left[0]), aa[1] / pow(2, Left[0]))
        if Right[0] != 0:
            bb = (bb[0] / pow(2, Right[0]), bb[1] / pow(2, Right[0]))

        if aa[0].value != bb[0].value or aa[1].value != bb[1].value:
            ok = False

        if ok:
            print("Yes")
        else:
            print("No")

solve()
