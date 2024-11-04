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

    def __copy__(self):
        new_int = Int()
        new_int.arr = self.arr[:]
        new_int.sign = self.sign
        return new_int

    def __eq__(self, other):
        return not (self > other or self < other)

    def __ne__(self, other):
        return not (self == other)

    def __lt__(self, other):
        return other > self

    def __gt__(self, other):
        if self.sign != other.sign:
            return self.sign < other.sign
        if self.sign == 0:
            if self.arr[0] != other.arr[0]:
                return self.arr[0] > other.arr[0]
            for i in range(self.arr[0], 0, -1):
                if self.arr[i] != other.arr[i]:
                    return self.arr[i] > other.arr[i]
            return False
        if self.arr[0] != other.arr[0]:
            return self.arr[0] < other.arr[0]
        for i in range(self.arr[0], 0, -1):
            if self.arr[i] != other.arr[i]:
                return self.arr[i] < other.arr[i]
        return False

    def __neg__(self):
        c = self.__copy__()
        c.set_sign((self.sign + 1) % 2)
        return c

    def __add__(self, other):
        c = self.__copy__()
        c += other
        return c

    def __sub__(self, other):
        c = self.__copy__()
        c -= other
        return c

    def __mul__(self, other):
        c = self.__copy__()
        c *= other
        return c

    def __str__(self):
        res = ""
        if self.sign:
            res += '-'
        res += Int.str(self.arr[self.arr[0]])
        for i in range(self.arr[0] - 1, 0, -1):
            k = Int.max
            for j in range(9):
                res += Int.str((self.arr[i] % k) // (k := k // 10))
        return res

    def __iadd__(self, other):
        brr = other.arr
        carry = 0
        i = 0

        if self < Int("0"):
            if other < Int("0"):
                if self.arr[0] >= brr[0]:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] += brr[i] + carry
                        carry = self.arr[i] // Int.max
                        self.arr[i] %= Int.max
                    while carry:
                        self.arr[i] += carry
                        carry = self.arr[i] // Int.max
                        self.arr[i] %= Int.max
                        i += 1
                    if i == self.arr[0] + 2:
                        self.arr[0] += 1
                else:
                    c = self.__copy__()
                    d = other.__copy__()
                    self = d += c
            else:
                if self == -other:
                    self = Int("0")
                elif -self > other:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] -= brr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                    while carry:
                        self.arr[i] += carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                        i += 1
                    while self.arr[self.arr[0]] == 0 and self.arr[0] > 1:
                        self.arr[0] -= 1
                else:
                    c = self.__copy__()
                    d = other.__copy__()
                    self = d += c
        else:
            if other < Int("0"):
                if self == -other:
                    self = Int("0")
                elif self > -other:
                    for i in range(1, brr[0] + 1):
                        self.arr[i] -= brr[i] + carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                    while carry:
                        self.arr[i] += carry
                        if self.arr[i] < 0:
                            carry = -1
                            self.arr[i] += Int.max
                        else:
                            carry = 0
                        i += 1
                    while self.arr[self.arr[0]] == 0 and self.arr[0] > 1:
                        self.arr[0] -= 1
                else:
                    c = self.__copy__()
                    d = other.__copy__()
                    self = -(d += c)
            else:
                c = -self
                d = -other
                self = -(d += c)

        return self

    def __isub__(self, other):
        return self.__iadd__(-other)

    def __imul__(self, other):
        if other == Int("0"):
            self = Int("0")
        elif other == Int.str(Int.max):
            if self != Int("0"):
                for i in range(self.arr[0], 0, -1):
                    self.arr[i + 1] = self.arr[i]
                self.arr[1] = 0
                self.arr[0] += 1
        elif Int.abs(other) < Int.str(Int.max):
            tmp = 0
            carry = 0
            brr = other.arr
            for i in range(1, self.arr[0] + 1):
                tmp = self.arr[i] * brr[1] + carry
                self.arr[i] = tmp % Int.max
                carry = tmp // Int.max
            if carry:
                self.arr[i] = carry
                self.arr[0] += 1
        else:
            tmp = Int()
            res = Int("0")
            brr = other.arr
            for i in range(brr[0], 0, -1):
                tmp = self * Int.str(brr[i])
                res = res * Int.str(Int.max) + tmp
            self = res

        self.sign = (self.sign + other.sign) % 2
        return self

    @staticmethod
    def num(a):
        res = 0
        for char in a:
            res = res * 10 + int(char)
        return res

    @staticmethod
    def str(a):
        res = ""
        h = 1 if a < 0 else 0
        a = abs(a)
        while a != 0:
            res = chr(a % 10 + ord('0')) + res
            a //= 10
        if res == "":
            res = "0"
        if h:
            res = "-" + res
        return res

    @staticmethod
    def abs(a):
        return -a if a < Int("0") else a

def solve(s, h=0):
    u = [False] * 26
    answer = Int("1")
    k = 0
    for char in s:
        if char == '?':
            k += 1
        if 'A' <= char <= 'Z':
            u[ord(char) - ord('A')] = True
    for _ in range(k):
        global qanak
        qanak += 1

    k = sum(u)
    if k > 10:
        return Int("0")
    for i in range(k):
        answer *= Int.str(10 - i - h)
    return answer

if __name__ == "__main__":
    global qanak
    qanak = 0
    Int.size = 12
    answer = Int("0")
    s = input()
    if len(s) == 1:
        if s[0] == '?' or ('A' <= s[0] <= 'Z'):
            answer = Int("9")
        else:
            answer = Int("1")
        print(answer)
        exit(0)
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
    print(answer, end='')
    for _ in range(qanak):
        print(0, end='')
    print()
