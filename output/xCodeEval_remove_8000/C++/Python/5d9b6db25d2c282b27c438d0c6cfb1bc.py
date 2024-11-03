class Permutation(list):
    def __init__(self, size):
        super().__init__(range(size))

    def multiply(self, rhs):
        res = Permutation(len(self))
        for i in range(len(self)):
            res[i] = self[rhs[i]]
        return res

    def __mul__(self, rhs):
        return self.multiply(rhs)

    def __imul__(self, rhs):
        res = self.multiply(rhs)
        self[:] = res[:]
        return self

    def pow(self, deg):
        result = Permutation(len(self))
        a = self
        b = deg
        while b > 0:
            if b & 1:
                result *= a
            a *= a
            b >>= 1
        return result

    def next(self):
        i = len(self) - 1
        while i > 0 and self[i - 1] >= self[i]:
            i -= 1
        if i <= 0:
            return False
        j = len(self) - 1
        while self[j] <= self[i - 1]:
            j -= 1
        self[i - 1], self[j] = self[j], self[i - 1]
        self[i:] = self[len(self) - 1:i - 1:-1]
        return True


def check(a):
    n = len(a)
    b = [0] * n
    log = []

    def merge(l, r):
        if r - l <= 1:
            return
        m = (l + r) // 2
        merge(l, m)
        merge(m, r)
        i = l
        j = m
        k = l
        while i < m and j < r:
            if a[i] < a[j]:
                log.append('0')
                b[k] = a[i]
                i += 1
            else:
                log.append('1')
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        a[l:r] = b[l:r]

    merge(0, n)
    return ''.join(log)


def solve():
    s = input().strip()
    s = s[::-1]

    for length in range(2, 1112):
        p = Permutation(length)
        tmp = s
        if try_recover(0, length, tmp, p) and not tmp:
            ans = [0] * length
            for i in range(length):
                ans[p[i]] = i
            print(length)
            print(' '.join(str(x + 1) for x in ans))
            return


def try_recover(l, r, s, p):
    if r - l <= 1:
        return True
    mid = (l + r) // 2
    if not try_recover(l, mid, s, p) or not try_recover(mid, r, s, p):
        return False
    left = [p[i] for i in range(mid - 1, l - 1, -1)]
    right = [p[i] for i in range(r - 1, mid - 1, -1)]
    pos = l
    while left and right:
        if not s:
            return False
        ch = s[-1]
        s = s[:-1]
        if ch == '1':
            p[pos] = right.pop()
        else:
            p[pos] = left.pop()
        pos += 1
    while left:
        p[pos] = left.pop()
        pos += 1
    while right:
        p[pos] = right.pop()
        pos += 1
    return True


if __name__ == '__main__':
    solve()
