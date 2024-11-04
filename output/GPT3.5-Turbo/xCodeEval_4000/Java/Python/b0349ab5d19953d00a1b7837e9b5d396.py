import math
import sys

class ProblemC_76:
    
    def __init__(self):
        self.ONLINE_JUDGE = "ONLINE_JUDGE" in sys.argv
        self.inp = sys.stdin if self.ONLINE_JUDGE else open("input.txt", "r")
        self.out = sys.stdout if self.ONLINE_JUDGE else open("output.txt", "w")
        self.tok = []
    
    def init(self):
        pass
    
    def read_string(self):
        while not self.tok:
            self.tok = self.inp.readline().split()
        return self.tok.pop(0)
    
    def read_int(self):
        return int(self.read_string())
    
    def read_long(self):
        return int(self.read_string())
    
    def read_double(self):
        return float(self.read_string())
    
    def main(self):
        self.init()
        self.solve()
    
    def solve(self):
        n = self.read_int() - 1
        m = self.read_int()
        a = self.read_int() - 1
        b = self.read_int() - 1
        i = a // m
        j = b // m
        l = a % m
        r = m - 1 if b == n else b % m
        if l == 0 and r == m - 1:
            self.out.write("1")
            return
        if j - i < 2:
            self.out.write(str(j - i + 1))
            return
        if (l != 0 and r == m - 1) or (l == 0 and r != m - 1):
            self.out.write("2")
            return
        if l - r == 1:
            self.out.write("2")
            return
        self.out.write("3")
    
    def run(self):
        try:
            t1 = time.time()
            self.main()
            t2 = time.time()
            print("Time =", t2 - t1, file=sys.stderr)
        except Exception as e:
            print(e, file=sys.stderr)
            sys.exit(-1)

if __name__ == "__main__":
    ProblemC_76().run()
