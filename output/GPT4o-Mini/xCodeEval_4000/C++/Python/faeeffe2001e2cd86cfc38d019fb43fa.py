from collections import defaultdict
from math import isqrt

class InfInt:
    BASE = 10**9
    UPPER_BOUND = 999999999

    def __init__(self, value=0):
        if isinstance(value, str):
            self.from_string(value)
        elif isinstance(value, int):
            self.from_int(value)
        else:
            self.val = [0]
            self.pos = True

    def from_string(self, s):
        self.pos = True
        self.val = []
        for i in range(len(s), 0, -9):
            self.val.append(int(s[max(0, i-9):i]))
        if self.val[-1] < 0:
            self.val[-1] = -self.val[-1]
            self.pos = False
        self.correct()

    def from_int(self, l):
        self.pos = l >= 0
        self.val = []
        l = abs(l)
        while l > 0:
            self.val.append(l % self.BASE)
            l //= self.BASE
        if not self.val:
            self.val = [0]

    def correct(self):
        self.remove_leading_zeros()

    def remove_leading_zeros(self):
        while len(self.val) > 1 and self.val[-1] == 0:
            self.val.pop()

    def __mul__(self, other):
        if isinstance(other, InfInt):
            result = InfInt()
            result.val = [0] * (len(self.val) + len(other.val))
            for i in range(len(self.val)):
                carry = 0
                for j in range(len(other.val)):
                    product = self.val[i] * other.val[j] + result.val[i + j] + carry
                    result.val[i + j] = product % self.BASE
                    carry = product // self.BASE
                result.val[i + len(other.val)] += carry
            result.correct()
            return result
        else:
            raise NotImplementedError

    def __str__(self):
        if not self.pos:
            return '-' + ''.join(f'{v:09d}' for v in reversed(self.val))
        return ''.join(f'{v:09d}' for v in reversed(self.val))

def alpha(n):
    cnt = 10
    res = InfInt(1)
    for i in range(min(n, 11)):
        res *= InfInt(cnt)
        cnt = max(cnt - 1, 0)
    return res

def beta(n):
    cnt = 9
    res = InfInt(9)
    for i in range(min(n - 1, 11)):
        res *= InfInt(cnt)
        cnt = max(cnt - 1, 0)
    return res

def power(n, p):
    if p <= 0:
        return InfInt(1)
    x = power(n, p // 2)
    if p % 2:
        return x * x * n
    else:
        return x * x

s = input().strip()
leading = s[0]
lead = not leading.isdigit()
bits = [0] * 30
cnt = 0

for char in s:
    if char.isalpha():
        bits[ord(char) - ord('A')] = 1
    elif char == '?':
        cnt += 1

if not lead:
    res = alpha(sum(bits)) * power(InfInt(10), cnt)
else:
    if leading == '?':
        res = alpha(sum(bits)) * power(InfInt(10), cnt - 1) * InfInt(9)
    else:
        res = beta(sum(bits)) * power(InfInt(10), cnt)

print(res)
