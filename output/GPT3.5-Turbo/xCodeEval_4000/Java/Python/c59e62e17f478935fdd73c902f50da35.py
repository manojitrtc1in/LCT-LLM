import sys

def perfect(i):
    f1 = -1
    f2 = -1

    while i > 0:
        lastDig = i % 10

        if f1 == -1:
            f1 = lastDig
        if f2 == -1 and lastDig != f1:
            f2 = lastDig

        if f1 != -1 and f2 != -1 and (lastDig != f1 and lastDig != f2):
            return False

        i //= 10

    return True

def main():
    n = int(sys.stdin.readline())

    b = n // step

    count = values[b]
    for i in range(b * step + 1, n + 1):
        if perfect(i):
            count += 1

    print(count - 1)

step = 1000000
