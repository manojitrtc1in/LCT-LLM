class modint:
    def __init__(self, val):
        self.mod = 998244353
        self.val = val % self.mod

    def __add__(self, other):
        return modint(self.val + other.val)

    def __sub__(self, other):
        return modint(self.val - other.val)

    def __mul__(self, other):
        return modint(self.val * other.val)

    def __pow__(self, power):
        return modint(pow(self.val, power, self.mod))

    def __str__(self):
        return str(self.val)

    def __repr__(self):
        return str(self.val)


def main():
    n = int(input())
    tree = [[] for _ in range(n)]
    dp = [[modint(0) for _ in range(3)] for _ in range(n)]

    def leaf(v):
        return len(tree[v]) == 1

    def treedp(now, pre):
        ndp = dp[now]
        ndp[2] = modint(1)
        for to in tree[now]:
            if to == pre:
                continue
            tmp = [modint(0) for _ in range(3)]
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

    for i in range(1, n):
        a, b = map(int, input().split())
        a -= 1
        b -= 1
        tree[a].append(b)
        tree[b].append(a)

    treedp(0, -1)
    rdp = dp[0]
    print(rdp[0] + rdp[2])


if __name__ == "__main__":
    main()
