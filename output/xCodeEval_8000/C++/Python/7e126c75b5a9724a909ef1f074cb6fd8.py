import math

N1 = int(1e5)
B = int(1e5)
N = int(3e8)

lp = [0] * (N1 + 1)
prime = []

def seive():
    for i in range(2, N1 + 1):
        if lp[i] == 0:
            lp[i] = i
            prime.append(i)
        for j in prime:
            if j > lp[i] or i * j > N1:
                break
            lp[i * j] = j

