from sys import stdin, stdout
from bitarray import bitarray

B = 100 * 1000
MN = 3 * 10**8 + 10

is_prime = bitarray(MN)
is_prime.setall(0)

def check(x):
    if x == 2:
        return True
    if x % 4 != 1:
        return False

    F = False
    for d in range(2, int(x**0.5) + 1):
        if x % d == 0:
            return False
        if d * d != x and is_prime[x - d * d]:
            F = True
    return F

def main():
    l, r = map(int, stdin.readline().split())
    ret = 0
    pl = l // B
    pr = r // B

    for d in range(1, int(MN**0.5)):
        is_prime[d * d] = 1

    if pl == pr:
        for i in range(l, r + 1):
            ret += check(i)
        stdout.write(f"{ret}\n")
        return

    for i in range(pl + 1, pr):
        ret += prec[i]

    for i in range(l, (pl + 1) * B):
        ret += check(i)
    for i in range(r, pr * B - 1, -1):
        ret += check(i)

    stdout.write(f"{ret}\n")

if __name__ == "__main__":
    main()
