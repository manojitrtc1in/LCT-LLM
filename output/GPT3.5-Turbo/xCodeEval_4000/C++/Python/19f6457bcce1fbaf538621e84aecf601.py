def powe(b, e):
    r = 1
    while e:
        if e & 1:
            r = r * b % mod
        b = b * b % mod
        e >>= 1
    return r

def admul(a, b, c):
    a = (a + b * c) % mod

def go():
    n = int(input())
    p = [[0] * n for _ in range(n)]
    i100 = powe(100, mod - 2)
    for i in range(n):
        row = list(map(int, input().split()))
        for j in range(n):
            p[i][j] = row[j] * i100 % mod

    init = [0] * (1 << n)
    x = {tuple(init): 1}

    for turn in range(n):
        newx = {}
        for s in range(1 << n):
            mul = 1
            for i in range(n):
                if s >> i & 1:
                    mul = mul * p[i][turn] % mod
                else:
                    mul = mul * (1 - p[i][turn]) % mod
            for state, val in x.items():
                state = list(state)
                for k in range(1 << n):
                    if (k & s) and state[k] < bin(k).count('1'):
                        state[k] += 1
                add = True
                for k in range(1 << n):
                    if state[k] + (n - turn - 1) < bin(k).count('1'):
                        add = False
                if add:
                    if tuple(state) in newx:
                        newx[tuple(state)] += mul * val
                    else:
                        newx[tuple(state)] = mul * val
        x = newx

    fin = [bin(i).count('1') for i in range(1 << n)]
    ans = x[tuple(fin)]
    ans %= mod
    if ans < 0:
        ans += mod
    print(ans)

n = int(input())
if n == 1:
    go(1)
elif n == 2:
    go(2)
elif n == 3:
    go(3)
elif n == 4:
    go(4)
elif n == 5:
    go(5)
elif n == 6:
    go(6)
