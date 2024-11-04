import sys
import math
import random

class Main:
    
    EPS = 1e-7
    
    def __init__(self):
        self.pp = id9()
        self.rP = 0.0
        self.vP = 0.0
        self.omegaP = 0.0
        self.ps = id9()
        self.vs = 0.0
        self.star = None

    def run(self):
        self.in_stream = sys.stdin
        self.out_stream = sys.stdout
        self.solve()

    def solve(self):
        xp = self.next_double()
        yp = self.next_double()
        
        self.pp.set(xp, yp)
        self.rP = math.sqrt(xp * xp + yp * yp)
        self.vP = self.next_double()
        
        self.ps.set(self.next_double(), self.next_double())
        self.vs = self.next_double()
        
        tvp = 1
        
        self.vP /= tvp
        self.vs /= tvp
        
        self.omegaP = self.vP / self.rP
        self.star = id6(id9(0.0, 0.0), self.next_double())
        
        ans = 3e6
        
        left = 0
        right = ans
        
        for it in range(10000):
            mid = 0.5 * (left + right)
            
            if self.can(mid):
                right = mid
                ans = min(ans, mid)
            else:
                left = mid
        
        self.out_stream.write(f"{ans / tvp}\n")

    def can(self, t):
        return id4(self.ps, self.pp.rotate(t * self.vP / self.rP)) < t * self.vs

    def next_double(self):
        return float(self.next_token())

    def next_token(self):
        return next(self.tokenizer)

    def tokenizer(self):
        for line in self.in_stream:
            for token in line.split():
                yield token

class id9:
    def __init__(self, x=0.0, y=0.0):
        self.x = x
        self.y = y

    def set(self, x, y):
        self.x = x
        self.y = y
        return self

    def rotate(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        return id9(self.x * cos - self.y * sin, self.x * sin + self.y * cos)

class id6:
    def __init__(self, c, r):
        self.c = c
        self.r = r

def id4(p1, p2):
    # Placeholder for the actual implementation
    return 0.0

if __name__ == "__main__":
    main = Main()
    main.run()
