import sys

class FastReader:
    def __init__(self):
        self.input = sys.stdin.readline().strip()
        self.tokenizer = iter(self.input.split())
    
    def next(self):
        return next(self.tokenizer)
    
    def nextInt(self):
        return int(self.next())
    
    def nextLong(self):
        return int(self.next())
    
    def nextDouble(self):
        return float(self.next())
    
    def nextLine(self):
        return self.input

class InVoker:
    def __init__(self):
        self.mod = 1000000007
        self.mod2 = 998244353
        self.inp = FastReader()
        self.out = sys.stdout
    
    def main(self):
        n = self.inp.nextInt()
        a = [0] * n
        self.input(a, n)
        if n > 66:
            self.out.write("1\n")
            return
        pref = [0] * (n + 1)
        pref[1] = a[0]
        for i in range(1, n):
            pref[i + 1] = pref[i] ^ a[i]
        gg = 34
        for c in range(n - 1):
            for left in range(c, -1, -1):
                for right in range(c + 1, n):
                    if self.xor(left, c) > self.xor(c + 1, right):
                        gg = min(gg, right - left - 1)
        self.out.write(str(gg) if gg != 34 else "-1")
        self.out.write("\n")
    
    def xor(self, i, j):
        return pref[j + 1] ^ pref[i]
    
    def sort(self, a):
        a.sort()
    
    def ruffleSort(self, a):
        random.shuffle(a)
        a.sort()
    
    def input(self, a, n):
        for i in range(n):
            a[i] = self.inp.nextLong()

invoker = InVoker()
invoker.main()
