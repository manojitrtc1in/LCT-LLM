A = 100000
B = 100000
P = 10000
PMAX = 1000000
L1 = 100000
P3 = 1000000

a = [0] * (PMAX + 1)
b = [0] * (A + 1)
p = [0] * P
y = [0] * P

n = 0
n2 = 0
n3 = 0
bl = 0
bh = 0
ans = 0
k = 0
kl = 0
kh = 0
i = 0
j = 0
b1 = -1
b2 = 0
q2 = 0
c = 0

n = int(input())

p[0] = 2
k = 1
for i in range(3, PMAX + 1, 2):
    if a[i] == 0:
        p[k] = i
        k += 1
        if i <= PMAX // i:
            for j in range(i * i, PMAX + 1, i):
                a[j] = 1

for i in range(P):
    n2 = n // p[i]
    if n2 == 0 or n2 < p[i]:
        break
    b2 = n2 // A
    q2 = n2 % A
    if b1 != b2:
        a = [0] * (A + 1)
        b1 = b2
        bl = b1 * A
        bh = bl + q2 + 1
        c = 1 if b1 == 0 else 0
        y[0] = -1
        for j in range(1, P):
            y[j] = max(bl // p[j] * p[j] + p[j], p[j] * p[j]) - bl
            if y[j] % 2 == 0:
                y[j] += p[j]
        kl = bl
        while kl < bh:
            kh = min(kl + L1, bh) - bl
            for j in range(1, P):
                for k in range(y[j], kh, 2 * p[j]):
                    a[k] = 1
                y[j] = k
            if kl == 0:
                k = 3
                a[2] = 1
            else:
                k = kl - bl + 1
            while k < kh:
                a[k] = a[k + 1] = c if a[k] == 0 else c
                k += 2
            kl += L1

    ans += b[b1] + a[q2] - (i + 1)

i = 0
j = P
while True:
    k = i + (j - i) // 2
    if k == i:
        break
    if p[k] > P3:
        n3 = n + 1
    else:
        n3 = p[k] * p[k] * p[k]
    if n3 > n:
        j = k
    elif n3 < n:
        i = k
    else:
        break
if p[k] * p[k] * p[k] <= n:
    ans += k + 1

print(ans)
