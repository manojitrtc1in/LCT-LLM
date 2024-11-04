M = 998244353

n, m = map(int, input().split())
a = list(map(int, input().split()))
w = list(map(int, input().split()))

W1 = 0
W2 = 0
for i in range(n):
    if a[i]:
        W1 += w[i]
    else:
        W2 += w[i]

probs = [0] * (m + 1)
probs[0] = 1

for i in range(m):
    new_probs = [0] * (m + 1)
    for d1 in range(i + 1):
        d2 = d1 - i
        w1 = W1 + d1
        w2 = W2 + d2
        w0 = w1 + w2
        if probs[d1] and w2 >= 0:
            inv_w0 = pow(w0, M - 2, M)
            if w2 > 0:
                new_probs[d1] = (new_probs[d1] + probs[d1] * w2 * inv_w0) % M
            new_probs[d1 + 1] = (new_probs[d1 + 1] + probs[d1] * w1 * inv_w0) % M
    probs = new_probs

after_ops_1 = [0] * (m + 1)
after_ops_2 = [0] * (m + 1)
after_ops_1[0] = 1
after_ops_2[0] = 1

for i in range(1, m + 1):
    after_ops_1[i] = after_ops_1[i - 1] * (1 + pow(W1 + i - 1, M - 2, M)) % M

for i in range(1, m + 1):
    after_ops_2[i] = after_ops_2[i - 1] * (1 - pow(W2 - i + 1, M - 2, M)) % M

coef1 = 0
coef2 = 0

for i in range(m + 1):
    coef1 = (coef1 + after_ops_1[i] * probs[i]) % M

for i in range(m + 1):
    coef2 = (coef2 + after_ops_2[i] * probs[m - i]) % M

for i in range(n):
    if a[i]:
        print(w[i] * coef1 % M)
    else:
        print(w[i] * coef2 % M)
