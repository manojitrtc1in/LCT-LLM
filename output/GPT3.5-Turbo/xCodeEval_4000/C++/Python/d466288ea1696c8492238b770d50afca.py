class Int:
    size = 0
    max = 1000000000

    def __init__(self, a="0"):
        self.arr = [0] * (Int.size + 1)
        self.sign = 0
        if a[0] == '-':
            self.sign = 1
            a = a[1:]
        self.arr[0] = 0
        while len(a) > 9:
            self.arr[0] += 1
            self.arr[self.arr[0]] = Int.num(a[-9:])
            a = a[:-9]
        self.arr[0] += 1
        self.arr[self.arr[0]] = Int.num(a)

    def __str__(self):
        res = ""
        if self.sign:
            res += "-"
        res += Int.str(self.arr[self.arr[0]])
        for i in range(self.arr[0] - 1, 0, -1):
            k = Int.max
            for j in range(9):
                res += Int.str((self.arr[i] % k) // (k // 10))
                k //= 10
        return res

    def __mul__(self, a):
        if a == "0":
            return Int("0")
        elif a == str(Int.max):
            if self != "0":
                self.arr.append(0)
                self.arr[0] += 1
        elif Int.abs(a) < str(Int.max):
            tmp = 0
            carry = 0
            brr = a.arr
            for i in range(1, self.arr[0] + 1):
                tmp = self.arr[i] * brr[1] + carry
                self.arr[i] = tmp % Int.max
                carry = tmp // Int.max
            if carry:
                self.arr.append(carry)
                self.arr[0] += 1
        else:
            tmp = Int()
            res = Int("0")
            brr = a.arr
            for i in range(brr[0], 0, -1):
                tmp = self * Int.str(brr[i])
                res = res * Int.str(Int.max) + tmp
            self.arr = res.arr
        self.sign = (self.sign + a.sign) % 2
        return self

    def __imul__(self, a):
        return self * a

    def __rmul__(self, a):
        return self * a

    def __add__(self, a):
        brr = a.arr
        carry = 0
        if self < "0":
            if a < "0":
                if self.arr[0] >= brr[0]:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] = self.arr[i] + brr[i] + carry
                        carry = self.arr[i] // Int.max
                        self.arr[i] %= Int.max
                    while carry:
                        self.arr[i] = self.arr[i] + carry
                        carry = self.arr[i] // Int.max
                        self.arr[i] %= Int.max
                        i += 1
                    if i == self.arr[0] + 2:
                        self.arr[0] += 1
                else:
                    c = Int(self)
                    d = Int(a)
                    self = d + c
            else:
                if self == (-a):
                    self = "0"
                elif -self > a:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] = self.arr[i] - brr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                    while carry:
                        self.arr[i] = self.arr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                        i += 1
                    while self.arr[self.arr[0]] == 0 and self.arr[0] > 1:
                        self.arr[0] -= 1
                else:
                    c = Int(self)
                    d = Int(a)
                    self = d + c
        else:
            if a < "0":
                if self == -a:
                    self = "0"
                elif self > -a:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] = self.arr[i] - brr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                    while carry:
                        self.arr[i] = self.arr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                        i += 1
                    while self.arr[self.arr[0]] == 0 and self.arr[0] > 1:
                        self.arr[0] -= 1
                else:
                    c = Int(self)
                    d = Int(a)
                    self = d + c
            else:
                c = -Int(self)
                d = -Int(a)
                self = -(d + c)
        return self

    def __iadd__(self, a):
        return self + a

    def __radd__(self, a):
        return self + a

    def __sub__(self, a):
        return self + (-a)

    def __isub__(self, a):
        return self - a

    def __rsub__(self, a):
        return -self + a

    def __neg__(self):
        c = Int(self)
        c.sign = (c.sign + 1) % 2
        return c

    def __eq__(self, a):
        return not (a > self or a < self)

    def __ne__(self, a):
        return not (self == a)

    def __lt__(self, a):
        return a > self

    def __le__(self, a):
        return not (self > a)

    def __gt__(self, a):
        brr = a.arr
        if self.sign != a.sign:
            return self.sign < a.sign
        if self.sign == 0:
            if self.arr[0] != brr[0]:
                return self.arr[0] > brr[0]
            for i in range(self.arr[0], 0, -1):
                if self.arr[i] != brr[i]:
                    return self.arr[i] > brr[i]
            return False
        if self.arr[0] != brr[0]:
            return self.arr[0] < brr[0]
        for i in range(self.arr[0], 0, -1):
            if self.arr[i] != brr[i]:
                return self.arr[i] < brr[i]
        return False

    def __ge__(self, a):
        return not (self < a)

    @staticmethod
    def abs(a):
        return -a if a < "0" else a

    @staticmethod
    def num(a):
        res = 0
        for i in range(len(a)):
            res = res * 10 + int(a[i])
        return res

    @staticmethod
    def str(a):
        res = ""
        h = 1 if a < 0 else 0
        a = -a if a < 0 else a
        while a != 0:
            res = str(a % 10) + res
            a //= 10
        if len(res) == 0:
            res = "0"
        if h:
            res = "-" + res
        return res

    @staticmethod
    def set_size(k):
        Int.size = k


def solve(s, h=0):
    u = [False] * 26
    answer = Int("1")
    k = 0
    for i in range(len(s)):
        if s[i] == '?':
            k += 1
        if s[i] >= 'A' and s[i] <= 'Z':
            u[ord(s[i]) - ord('A')] = True
    for i in range(k):
        global qanak
        qanak += 1
    k = 0
    for i in range(26):
        if u[i]:
            k += 1
    if k > 10:
        return Int("0")
    for i in range(k):
        answer *= Int.str(10 - i - h)
    return answer


qanak = 0
Int.set_size(12)
answer = Int("0")
s = input()
if len(s) == 1:
    if s[0] == '?' or (s[0] >= 'A' and s[0] <= 'Z'):
        answer = Int("9")
    else:
        answer = Int("1")
    print(answer)
    exit()
if s[0] == '?':
    st = s[1:]
    answer = Int("9") * solve(st)
elif s[0] >= 'A' and s[0] <= 'Z':
    for k in range(1, 10):
        st = s
        qanak = 0
        for i in range(len(st)):
            if st[i] == s[0]:
                st = st[:i] + str(k) + st[i + 1:]
        answer += solve(st, 1)
else:
    answer = solve(s)
print(answer, end="")
for i in range(qanak):
    print("0", end="")
print()
