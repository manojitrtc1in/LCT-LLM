from collections import defaultdict
from math import isqrt

class InfInt:
    BASE = 1000000000
    id5 = 999999999
    id0 = 9

    def __init__(self, value=0):
        self.val = []
        self.pos = True
        if isinstance(value, str):
            self.from_string(value)
        elif isinstance(value, int):
            self.from_int(value)
        else:
            raise ValueError("Unsupported type for InfInt")

    def from_string(self, s):
        self.pos = True
        self.val.clear()
        s = s.lstrip('-')
        for i in range(len(s), 0, -self.id0):
            self.val.append(int(s[max(0, i - self.id0):i]))
        if s[0] == '-':
            self.pos = False
        self.correct()

    def from_int(self, l):
        self.pos = l >= 0
        l = abs(l)
        while l > 0:
            self.val.append(l % self.BASE)
            l //= self.BASE

    def correct(self):
        self.remove_leading_zeros()

    def remove_leading_zeros(self):
        while len(self.val) > 1 and self.val[-1] == 0:
            self.val.pop()

    def __str__(self):
        if not self.pos:
            return '-' + ''.join(f'{v:0{self.id0}}' for v in reversed(self.val))
        return ''.join(f'{v:0{self.id0}}' for v in reversed(self.val))

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
            result.pos = self.pos == other.pos
            return result
        return NotImplemented

    def __pow__(self, p):
        if p == 0:
            return InfInt(1)
        if p < 0:
            raise ValueError("Negative exponent not supported")
        result = InfInt(1)
        base = self
        while p:
            if p % 2:
                result *= base
            base *= base
            p //= 2
        return result

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

s = input().strip()
leading = s[0]
lead = leading.isdigit()
bits = [0] * 30
cnt = 0

for char in s:
    if char.isalpha():
        bits[ord(char) - ord('A')] = 1
    elif char == '?':
        cnt += 1

if not lead:
    res = alpha(sum(bits)) * InfInt(10) ** cnt
else:
    if leading == '?':
        res = alpha(sum(bits)) * InfInt(10) ** (cnt - 1) * 9
    else:
        res = beta(sum(bits)) * InfInt(10) ** cnt

print(res)
