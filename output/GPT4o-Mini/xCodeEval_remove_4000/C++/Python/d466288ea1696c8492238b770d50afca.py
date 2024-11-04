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
        if isinstance(other, Int):
            return self.compare(other) == 0
        return self.compare(Int(other)) == 0

    def __ne__(self, other):
        return not self.__eq__(other)

    def __lt__(self, other):
        return self.compare(other) < 0

    def __le__(self, other):
        return self.compare(other) <= 0

    def __gt__(self, other):
        return self.compare(other) > 0

    def __ge__(self, other):
        return self.compare(other) >= 0

    def __add__(self, other):
        result = self.__copy__()
        result += other
        return result

    def __sub__(self, other):
        result = self.__copy__()
        result -= other
        return result

    def __mul__(self, other):
        result = self.__copy__()
        result *= other
        return result

    def __str__(self):
        return self.to_str()

    def compare(self, other):
        brr = other.arr
        if self.sign != other.sign:
            return self.sign - other.sign
        if self.sign == 0:
            if self.arr[0] != brr[0]:
                return self.arr[0] - brr[0]
            for i in range(self.arr[0], 0, -1):
                if self.arr[i] != brr[i]:
                    return self.arr[i] - brr[i]
            return 0
        if self.arr[0] != brr[0]:
            return self.arr[0] - brr[0]
        for i in range(self.arr[0], 0, -1):
            if self.arr[i] != brr[i]:
                return self.arr[i] - brr[i]
        return 0

    def __iadd__(self, other):
        if isinstance(other, str):
            other = Int(other)
        brr = other.arr
        carry = 0
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
                    self = other + self
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
                    self = other + self
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
                    self = -other + self
            else:
                self = -self + -other
        return self

    def __isub__(self, other):
        return self.__iadd__(-other)

    def __imul__(self, other):
        if isinstance(other, str):
            other = Int(other)
        if other == Int("0"):
            self = Int("0")
        elif other == Int(str(Int.max)):
            if self != Int("0"):
                for i in range(self.arr[0], 0, -1):
                    self.arr[i + 1] = self.arr[i]
                self.arr[1] = 0
                self.arr[0] += 1
        elif Int.abs(other) < str(Int.max):
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
            tmp = Int("0")
            res = Int("0")
            brr = other.arr
            for i in range(brr[0], 0, -1):
                tmp = self * str(brr[i])
                res = res * str(Int.max) + tmp
            self = res
        self.sign = (self.sign + other.sign) % 2
        return self

    @staticmethod
    def abs(a):
        return -a if a < Int("0") else a

    @staticmethod
    def num(a):
        return int(a)

    @staticmethod
    def str(a):
        return str(a)

    def to_str(self):
        res = ""
        if self.sign:
            res = "-"
        res += Int.str(self.arr[self.arr[0]])
        for i in range(self.arr[0] - 1, 0, -1):
            k = Int.max
            for j in range(9):
                res += Int.str((self.arr[i] % k) // (k := k // 10))
        return res


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
    print(answer, end="")
    for _ in range(qanak):
        print(0, end="")
    print()
