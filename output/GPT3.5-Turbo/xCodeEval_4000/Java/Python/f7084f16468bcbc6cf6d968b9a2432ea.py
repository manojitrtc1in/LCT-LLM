import sys

class FastReader:
    def __init__(self, file):
        self.file = file
        self.buffer = ""
        self.pos = 0
        self.size = 0

    def read(self):
        if self.pos >= self.size:
            self.buffer = self.file.readline()
            self.size = len(self.buffer)
            self.pos = 0
            if self.size == 0:
                return -1
        self.pos += 1
        return self.buffer[self.pos - 1]

    def next(self):
        while True:
            c = self.read()
            if c == -1 or c >= 'a' and c <= 'z' or c >= 'A' and c <= 'Z':
                break
        if c == -1:
            return ""
        result = c
        while True:
            c = self.read()
            if c == -1 or c < 'a' or c > 'z' and c < 'A' or c > 'Z':
                break
            result += c
        return result

    def nextInt(self):
        while True:
            c = self.read()
            if c == -1 or c >= '0' and c <= '9' or c == '-':
                break
        if c == -1:
            return 0
        sign = -1 if c == '-' else 1
        result = 0 if c == '-' else int(c)
        while True:
            c = self.read()
            if c == -1 or c < '0' or c > '9':
                break
            result = result * 10 + int(c)
        return sign * result

    def nextLong(self):
        while True:
            c = self.read()
            if c == -1 or c >= '0' and c <= '9' or c == '-':
                break
        if c == -1:
            return 0
        sign = -1 if c == '-' else 1
        result = 0 if c == '-' else int(c)
        while True:
            c = self.read()
            if c == -1 or c < '0' or c > '9':
                break
            result = result * 10 + int(c)
        return sign * result

    def nextDouble(self):
        while True:
            c = self.read()
            if c == -1 or c >= '0' and c <= '9' or c == '-' or c == '.':
                break
        if c == -1:
            return 0
        sign = -1 if c == '-' else 1
        result = 0 if c == '-' else int(c)
        while True:
            c = self.read()
            if c == -1 or c < '0' or c > '9':
                break
            result = result * 10 + int(c)
        if c == '.':
            k = 1
            v = 0
            while True:
                c = self.read()
                if c == -1 or c < '0' or c > '9':
                    break
                v = v * 10 + int(c)
                k *= 10
            result += v / k
        return sign * result

    def nextLine(self):
        while True:
            c = self.read()
            if c == -1 or c == '\n':
                break
        return self.buffer[self.pos:self.size].strip()

class Main:
    def __init__(self):
        self.inp = FastReader(sys.stdin)
        self.out = sys.stdout

    def main(self):
        nt = 1
        sb = []
        for it in range(nt):
            n = self.inp.nextLong()
            k = self.inp.nextLong()

            if k == 1:
                self.out.write(str(n) + "\n")
                return

            lo = 1
            hi = n // 2

            while lo <= hi:
                mid = (hi + lo) // 2
                val = mid * 2 - 1

                if self.cnt(val, n) >= k:
                    lo = mid + 1
                else:
                    hi = mid - 1
            cand = hi * 2 - 1
            if self.cnt(cand, n) < k:
                cand = 0

            lo = 1
            hi = n // 2

            while lo <= hi:
                mid = (hi + lo) // 2
                val = mid * 2
                if self.cnt(val, n) >= k:
                    lo = mid + 1
                else:
                    hi = mid - 1

            cand = max(cand, hi * 2)
            self.out.write(str(cand) + "\n")

    def cnt(self, v, n):
        if v > n:
            return 0

        cnt = 0
        if v % 2 == 1:
            segSize = 1
            start = v
            while start <= n:
                end = min(n, start + segSize - 1)
                cnt += end - start + 1

                segSize *= 2
                start *= 2
        else:
            segSize = 2
            start = v
            while start <= n:
                end = min(n, start + segSize - 1)
                cnt += end - start + 1

                segSize *= 2
                start *= 2

        return cnt

if __name__ == "__main__":
    Main().main()
