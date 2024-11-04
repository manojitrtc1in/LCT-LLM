import math

class MILLERRABIN:
    def __init__(self):
        self.prime_table = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37]

    def witness(self, a, d, s, n):
        r = pow(a, d, n)
        if r == 1 or r == n - 1:
            return 0
        for _ in range(s - 1):
            r = pow(r, 2, n)
            if r == 1:
                return 1
            if r == n - 1:
                return 0
        return 1

    def test(self, n):
        if n <= 2:
            return 0
        p = n - 1
        s = 0
        while p % 2 == 0:
            p //= 2
            s += 1
        for a in self.prime_table:
            if a >= n:
                break
            if self.witness(a, p, s, n):
                return 0
        return 1


def process(from_val):
    seq = _seq.copy()
    sup = _sup.copy()
    if from_val + from_val < seq[0]:
        return 1
    open_dict = {}
    close_dict = {}
    open_dict[0] = from_val - (seq[0] - from_val)
    close_dict[0] = seq[0] - from_val
    for i in range(1, 45):
        ext = open_dict.pop(i - 1, seq[i])
        seq[i] -= ext
        open_dict[i] = ext
        ext = close_dict.pop(i - 1, seq[i])
        sup[i] += seq[i] - ext
        close_dict[i] = ext
        cls = open_dict.pop(i, sup[i])
        sup[i + 1] += sup[i] - cls
        close_dict[i] = cls
    if sup[45] != 0:
        return 1
    return 0


def find(lef, rig):
    while lef <= rig:
        mid = (lef + rig) // 2
        if not process(mid):
            if mid == lef or process(mid - 1):
                return mid
            rig = mid - 1
        else:
            lef = mid + 1
    return -1


while True:
    try:
        n = int(input())
        a = list(map(int, input().split()))
        _seq = [0] * 50
        _sup = [0] * 50
        cur = 0
        for i in range(n):
            while a[i] >= (1 << (cur + 1)):
                cur += 1
            if a[i] == (1 << cur):
                _seq[cur] += 1
            else:
                _sup[cur] += 1
        if process(_seq[0]):
            print("-1")
        else:
            hig = _seq[0]
            low = find(1, hig)
            for i in range(low, hig + 1):
                if i != low:
                    print(" ", end="")
                print(i, end="")
            print()
    except EOFError:
        break
