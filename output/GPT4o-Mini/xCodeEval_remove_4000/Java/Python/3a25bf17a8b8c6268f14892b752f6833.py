import sys
from collections import defaultdict
from itertools import islice

class FastReader:
    def __init__(self):
        self.bfr = sys.stdin
        self.st = []

    def next(self):
        if not self.st:
            self.st = self.bfr.readline().strip().split()
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

    def id15(self, n):
        return [self.next_int() for _ in range(n)]

    def id38(self, n):
        return [self.next_double() for _ in range(n)]

    def id42(self, n):
        return [self.next_long() for _ in range(n)]

    def id19(self, n, m):
        return [[self.next_int() for _ in range(m)] for _ in range(n)]

def check(tgt, src):
    n = len(tgt)
    if len(src) != n:
        return 0

    xDig = None
    for i in range(n):
        if src[i] == 'X':
            if xDig is None:
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
    out = sys.stdout
    id33 = 1000000007
    t = 1

    for tc in range(t):
        sOG = fr.next()
        n = len(sOG)

        if n == 1:
            if sOG[0] == '0' or sOG[0] == '_' or sOG[0] == 'X':
                out.write("1\n")
            else:
                out.write("0\n")
            continue

        answer = 0

        # Case 1
        s = list(sOG)
        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0')
        shit |= (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '0')

        if not shit:
            if s[n - 1] == 'X' or s[n - 2] == 'X':
                for i in range(n):
                    if s[i] == 'X':
                        s[i] = '0'
            s[n - 1] = '0'
            s[n - 2] = '0'
            answer += check("00", s)

            for num in range(int(1e6)):
                tgt = str(num) + "00"
                answer += check(tgt, s)

        # Case 2
        s = list(sOG)
        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5')
        shit |= (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '2')
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
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
                tgt = str(num) + "25"
                answer += check(tgt, s)

        # Case 3
        s = list(sOG)
        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '0')
        shit |= (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '5')
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
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
                tgt = str(num) + "50"
                answer += check(tgt, s)

        # Case 4
        s = list(sOG)
        shit = (s[n - 1] != '_' and s[n - 1] != 'X' and s[n - 1] != '5')
        shit |= (s[n - 2] != '_' and s[n - 2] != 'X' and s[n - 2] != '7')
        shit |= (s[n - 1] == 'X' and s[n - 2] == 'X')

        if not shit:
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
                tgt = str(num) + "75"
                answer += check(tgt, s)

        out.write(f"{answer}\n")

if __name__ == "__main__":
    main()
