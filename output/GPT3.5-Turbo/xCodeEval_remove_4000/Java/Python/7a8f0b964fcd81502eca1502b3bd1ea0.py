import sys
import math
import random

class Main:
    def __init__(self):
        self.initTime = 0
        self.rnd = random.Random(7777)
    
    def main(self):
        self.initTime = self.currentTimeMillis()
        self.run()
    
    def run(self):
        self.solve()
    
    def solve(self):
        xp = self.nextDouble()
        yp = self.nextDouble()
        
        pp = id9(xp, yp)
        rP = math.sqrt(xp * xp + yp * yp)
        vP = self.nextDouble()
        
        ps = id9(self.nextDouble(), self.nextDouble())
        vs = self.nextDouble()
        
        tvp = 1
        
        vP /= tvp
        vs /= tvp
        
        omegaP = vP / rP
        star = id6(id9(0.0, 0.0), self.nextDouble())
        
        ans = 3e6
        
        left = 0
        right = ans
        
        for it in range(10000):
            mid = 0.5 * (left + right)
            
            if self.can(mid, pp, rP, vP, ps, vs, star):
                right = mid
                ans = min(ans, mid)
            else:
                left = mid
        
        sys.stdout.write(str(ans / tvp))
    
    def can(self, t, pp, rP, vP, ps, vs, star):
        return self.id4(ps, pp.rotate(t * vP / rP)) < t * vs
    
    def id4(self, p1, p2):
        if self.hasCSC(p1, p2, star):
            tp1 = self.id10(p1, star)
            tp2 = self.id10(p2, star)
            
            ret = 1e100
            
            ret = min(ret, self.id1(p1, p2, tp1[0], tp2[0]))
            ret = min(ret, self.id1(p1, p2, tp1[0], tp2[1]))
            ret = min(ret, self.id1(p1, p2, tp1[1], tp2[0]))
            ret = min(ret, self.id1(p1, p2, tp1[1], tp2[1]))
            
            return ret
        
        return self.dist(p1, p2)
    
    def hasCSC(self, p1, p2, c):
        A = p2.y - p1.y
        B = p1.x - p2.x
        d = A * A + B * B
        
        dist = 0.0
        
        if abs(d) < EPS:
            dist = self.dist(p1, c.c)
        else:
            t = (B * (p1.x - c.c.x) - A * (p1.y - c.c.y)) / d
            if 0.0 <= t and t <= 1.0:
                dist = math.sqrt(self.sqr(p1.x - B * t - c.c.x) + self.sqr(p1.y + A * t - c.c.y))
            else:
                dist = min(self.dist(p1, c.c), self.dist(p2, c.c))
        
        return dist <= c.r + EPS
    
    def id1(self, p1, p2, tp1, tp2):
        phi = math.acos(max(-1.0, min(1.0, tp1.scalarProduct(tp2) / tp1.len() / tp2.len())))
        return self.dist(p1, tp1) + self.dist(p2, tp2) + star.r * phi
    
    def id10(self, p, c):
        d = self.dist(p, c.c)
        cos = c.r / d
        sin = math.sqrt(1.0 - cos * cos)
        v = p.sub(c.c).normalize(c.r)
        
        return [v.rotate(cos, sin), v.rotate(cos, -sin)]
    
    def sqr(self, x):
        return x * x
    
    def dist(self, p1, p2):
        return math.sqrt(self.id2(p1, p2))
    
    def id2(self, p1, p2):
        return self.sqr(p2.x - p1.x) + self.sqr(p2.y - p1.y)
    
    def nextDouble(self):
        return float(input())
    
    def currentTimeMillis(self):
        return int(round(time.time() * 1000))

class id9:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    
    def set(self, x, y):
        self.x = x
        self.y = y
    
    def copy(self):
        return id9(self.x, self.y)
    
    def add(self, v):
        return id9(self.x + v.x, self.y + v.y)
    
    def inc(self, v):
        self.x += v.x
        self.y += v.y
    
    def sub(self, v):
        return id9(self.x - v.x, self.y - v.y)
    
    def dec(self, v):
        self.x -= v.x
        self.y -= v.y
    
    def mul(self, K):
        return id9(K * self.x, K * self.y)
    
    def scale(self, K):
        self.x *= K
        self.y *= K
    
    def len(self):
        return math.sqrt(self.x * self.x + self.y * self.y)
    
    def norm(self, newLen):
        return self.mul(newLen / self.len())
    
    def normalize(self, newLen):
        self.scale(newLen / self.len())
    
    def scalarProduct(self, v):
        return self.x * v.x + self.y * v.y
    
    def crossProduct(self, v):
        return self.x * v.y - v.x * self.y
    
    def rotate90(self):
        return id9(-self.y, self.x)
    
    def rotate(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        return id9(self.x * cos - self.y * sin, self.x * sin + self.y * cos)
    
    def turn90(self):
        self.x, self.y = -self.y, self.x
    
    def turn(self, angle):
        cos = math.cos(angle)
        sin = math.sin(angle)
        self.x, self.y = self.x * cos - self.y * sin, self.x * sin + self.y * cos
    
    def __eq__(self, other):
        return abs(self.x - other.x) < EPS and abs(self.y - other.y) < EPS
    
    def __str__(self):
        return "(%.3f, %.3f)" % (self.x, self.y)

class id6:
    def __init__(self, c, r):
        self.c = c
        self.r = r
    
    def area(self):
        return math.pi * self.r * self.r
    
    def lay(self, p):
        return r - EPS <= dist(c, p) <= r + EPS
    
    def contains(self, p):
        return dist(c, p) < r + EPS

if __name__ == "__main__":
    main = Main()
    main.main()
