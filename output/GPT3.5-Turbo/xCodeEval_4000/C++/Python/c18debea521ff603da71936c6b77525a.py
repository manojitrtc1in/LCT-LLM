k, m = map(int, input().split())

def res(s, n):
    dem = 10
    if s > k:
        return
    if k - s < 10:
        while m and dem < 100:
            print(str(dem) + "0" + str(k - s), end="")
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
        print("00" + str(k - s), end="")
    elif k - s < 1000:
        print("0" + str(k - s), end="")
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
    for i in range(10000):
        x = [False] * 10000
        a = i
        d = a % 10
        a //= 10
        c = a % 10
        a //= 10
        b = a % 10
        a //= 10
        s = a * b * c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a * b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a * b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a * b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a * b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -(a + b * c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -(-a + b * c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -(a + b * c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -(-a + b * c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b * c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b * c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b * c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b + c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b - c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b + c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b - c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b + c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b - c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b + c * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -10 * a - b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b - c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = 10 * a + b - 10 * c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -10 * a - b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b - 10 * c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a - b + 10 * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + 10 * b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - 10 * b - c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + 10 * b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + 10 * b + c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + 10 * b + c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b + c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b + c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b + c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b - c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a - b + c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b - c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b - c) * d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b + c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (-b + c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b - c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b + c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (-b - c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b - c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (-b + c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b) * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b) * c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b) * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b) * c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b) * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b) * c - d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a - b) * c + d
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a + b * (-c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a - b * (-c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = -a + b * (-c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b) * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b) * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b) * (c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a - b) * (c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (-a + b) * (c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = (a + b) * (-c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b + c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b + c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b - c + d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        s = a * (b - c - d)
        if s > 0 and not x[s]:
            x[s] = True
            res(s, i)
        if m == 0:
            return
        for i in range(m):
            if i < 10:
                print("0000000" + str(i))
            elif i < 100:
                print("000000" + str(i))
            elif i < 1000:
                print("00000" + str(i))
            elif i < 10000:
                print("0000" + str(i))
            elif i < 100000:
                print("000" + str(i))
            elif i < 1000000:
                print("00" + str(i))

if k == 0:
    process1()
else:
    process()
