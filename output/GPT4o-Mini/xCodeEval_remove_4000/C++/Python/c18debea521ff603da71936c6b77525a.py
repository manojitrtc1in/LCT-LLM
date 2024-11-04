def res(s, n):
    global k, m
    dem = 10
    if s > k:
        return
    if k - s < 10:
        while m and dem < 100:
            print(f"{dem}0{k - s}", end="")
            if n < 10:
                print("000", end="")
            elif n < 100:
                print("00", end="")
            elif n < 1000:
                print("0", end="")
            print(n)
            m -= 1
            dem += 1
        return
    elif k - s < 100:
        print(f"00{k - s}", end="")
    elif k - s < 1000:
        print(f"0{k - s}", end="")
    elif k - s < 10000:
        print(k - s, end="")
    
    if n < 10:
        print("000", end="")
    elif n < 100:
        print("00", end="")
    elif n < 1000:
        print("0", end="")
    print(n)
    m -= 1

def process():
    global m
    for i in range(10000):
        x = [0] * 10000
        a = i
        d = a % 10
        a //= 10
        c = a % 10
        a //= 10
        b = a % 10
        a //= 10
        s = a * b * c * d
        
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a - b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a - b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a - b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a - b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b - c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b + c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b + c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b - c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -(a + b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -(-a + b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -(a + b * c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -(-a + b * c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a + b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (-a + b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a + b * c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (-a + b * c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b * c
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + b - c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b + c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - b - c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b + c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + b - c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (10 * a + b + c * d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (10 * a + b - c * d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -10 * a - b + c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b + 10 * c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b - 10 * c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b + 10 * c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a * b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a * b - c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a + b * c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a - b * c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (-a + b * c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (-a * b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b * c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (-b * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b + c * d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b - c * d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (-b + c * d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (10 * a + b) * (c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (10 * a + b) * (c - d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (10 * a + b) * (-c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a + b) * (10 * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a - b) * (10 * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (-a + b) * (10 * c + d)
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b + c) + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (b - c) + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * (-b + c) + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + (b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + (b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + (-b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + (-b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a + (b - c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a + (b - c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a - (b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = 10 * a + b + c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = 10 * a + b - c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -10 * a - b + c * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b + 10 * c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = a * b - 10 * c - d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = -a * b + 10 * c + d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a * b + c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a * b - c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a + b * c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return
        
        s = (a - b * c) * d
        if s > 0 and x[s] == 0:
            x[s] += 1
            res(s, i)
        if m == 0:
            return

def process1():
    for i in range(m):
        if i < 10:
            print(f"0000000{i}")
        elif i < 100:
            print(f"000000{i}")
        elif i < 1000:
            print(f"00000{i}")
        elif i < 10000:
            print(f"0000{i}")
        elif i < 100000:
            print(f"000{i}")
        elif i < 1000000:
            print(f"00{i}")

k, m = map(int, input().split())
if k == 0:
    process1()
else:
    process()
