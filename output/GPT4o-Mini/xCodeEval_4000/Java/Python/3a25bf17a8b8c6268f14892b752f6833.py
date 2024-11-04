import sys
from collections import defaultdict
from itertools import islice

gigamod = 1000000007
epsilon = 0.00000001

class FastReader:
    def __init__(self):
        self.bfr = sys.stdin
        self.st = None

    def next(self):
        if self.st is None or not self.st:
            self.st = self.bfr.readline().split()
        return self.st.pop(0)

    def next_int(self):
        return int(self.next())

    def next_long(self):
        return int(self.next())

    def next_double(self):
        return float(self.next())

    def next_char(self):
        return self.next()[0]

    def next_string(self):
        return self.next()

    def next_int_array(self, n):
        return [self.next_int() for _ in range(n)]

    def next_double_array(self, n):
        return [self.next_double() for _ in range(n)]

    def next_long_array(self, n):
        return [self.next_long() for _ in range(n)]

def check(tgt, src):
    n = len(tgt)
    if len(src) != n:
        return 0

    xDig = 0
    for i in range(n):
        if src[i] == 'X':
            if xDig == 0:
                xDig = tgt[i]
            else:
                if tgt[i] != xDig:
                    return 0

    if tgt[0] == '0':
        return 0

    for i in range(n):
        if src[i] != '_' and src[i] != 'X' and tgt[i] != src[i]:
            return 0

    return 1

def main():
    fr = FastReader()
    t = 1

    for _ in range(t):
        sOG = fr.next()
        n = len(sOG)

        if n == 1:
            if sOG[0] == '0' or sOG[0] == '_' or sOG[0] == 'X':
                print(1)
            else:
                print(0)
            continue

        answer = 0

        # Check for "00"
        s = list(sOG)
        if (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0') and \
           (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '0'):
            if s[n - 1] == 'X' or s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '0'
            s[n - 1] = '0'
            s[n - 2] = '0'
            answer += check("00", s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "00")
                answer += check(tgt, s)

        # Check for "25"
        s = list(sOG)
        if (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5') and \
           (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '2'):
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '2'
            s[n - 1] = '5'
            s[n - 2] = '2'
            answer += check("25", s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "25")
                answer += check(tgt, s)

        # Check for "50"
        s = list(sOG)
        if (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0') and \
           (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '5'):
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '0'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'
            s[n - 1] = '0'
            s[n - 2] = '5'
            answer += check("50", s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "50")
                answer += check(tgt, s)

        # Check for "75"
        s = list(sOG)
        if (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5') and \
           (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '7'):
            if s[n - 1] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '5'
            elif s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '7'
            s[n - 1] = '5'
            s[n - 2] = '7'
            answer += check("75", s)

            for num in range(int(1e6)):
                tgt = list(str(num) + "75")
                answer += check(tgt, s)

        print(answer)

if __name__ == "__main__":
    main()
