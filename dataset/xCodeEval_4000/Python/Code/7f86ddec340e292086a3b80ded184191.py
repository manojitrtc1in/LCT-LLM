def ni():
    return int(input())
def nis():
    return map(int, input().split())

data = '
primes = [10**9+7]
acc = 0
for i in data:
    if i == ' ':
        acc += 93
        continue
    acc += ord(i) - 33
    primes.append(acc)
    acc = 0

for i in range(1, 50000):
    primes[i] += primes[i-1]

for T in range(ni()):
    n = ni()
    a = [*nis()]
    k = n // 2
    print(k)
    for i in range(k):
        print(i*2+1, i*2+2, min(a[i*2], a[i*2+1]), primes[i])