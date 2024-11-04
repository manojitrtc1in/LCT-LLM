class modint:
    def __init__(self, val, mod):
        self.val = val % mod
        self.mod = mod

    def __add__(self, other):
        if isinstance(other, int):
            other = modint(other, self.mod)
        return modint((self.val + other.val) % self.mod, self.mod)

    def __sub__(self, other):
        if isinstance(other, int):
            other = modint(other, self.mod)
        return modint((self.val - other.val) % self.mod, self.mod)

    def __mul__(self, other):
        if isinstance(other, int):
            other = modint(other, self.mod)
        return modint((self.val * other.val) % self.mod, self.mod)

    def __pow__(self, power):
        return modint(pow(self.val, power, self.mod), self.mod)

    def __str__(self):
        return str(self.val)


def treedp(now, pre):
    ndp = [modint(0, mod) for _ in range(3)]
    ndp[2] = modint(1, mod)
    for to in tree[now]:
        if to == pre:
            continue
        tmp = [modint(0, mod) for _ in range(3)]
        treedp(to, now)
        tdp = dp[to]

        for i in range(3):
            tmp[i] = tdp[2] * ndp[i]

        tmp[0] += ndp[2] * tdp[2] + ndp[1] * tdp[2]

        tmp[0] += (ndp[1] + ndp[2]) * tdp[1]

        tmp[0] += 2 * ndp[0] * tdp[0]
        tmp[1] += (ndp[1] * 2 + ndp[2]) * tdp[0]
        tmp[2] += ndp[2] * tdp[0]

        ndp = tmp

    dp[now] = ndp


n = int(input())
tree = [[] for _ in range(n)]
dp = [[modint(0, mod) for _ in range(3)] for _ in range(n)]

for _ in range(n - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    tree[a].append(b)
    tree[b].append(a)

treedp(0, -1)
rdp = dp[0]
print(rdp[0] + rdp[2])
