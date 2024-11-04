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
        if isinstance(a, Int):
            c = Int()
            c.__imul__(self, a)
            return c
        elif isinstance(a, str):
            c = Int(a)
            c.__imul__(self, c)
            return c

    def __imul__(self, a):
        if a == "0":
            self.arr = [0] * (Int.size + 1)
            self.sign = 0
        elif a == str(Int.max):
            if self != "0":
                for i in range(self.arr[0], 0, -1):
                    self.arr[i + 1] = self.arr[i]
                self.arr[1] = 0
                self.arr[0] += 1
        elif Int.abs(a) < str(Int.max):
            carry = 0
            brr = a.arr
            for i in range(1, self.arr[0] + 1):
                tmp = self.arr[i] * brr[1] + carry
                self.arr[i] = tmp % Int.max
                carry = tmp // Int.max
            if carry:
                self.arr[i + 1] = carry
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
            res = chr(a % 10 + ord('0')) + res
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
        if 'A' <= s[i] <= 'Z':
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
    if s[0] == '?' or ('A' <= s[0] <= 'Z'):
        answer = Int("9")
    else:
        answer = Int("1")
    print(answer)
    exit()
if s[0] == '?':
    st = s[1:]
    answer = Int("9") * solve(st)
elif 'A' <= s[0] <= 'Z':
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
    print(0, end="")
print()
