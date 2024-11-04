import sys

def pre(n, length):
    np = [False] * n
    np[0] = np[1] = True
    for i in range(n):
        if not np[i]:
            for j in range(i+i, n, i):
                np[j] = True
    div = n // length
    num = [0] * div
    j = 0
    for i in range(n):
        if i == 2 or (not np[i] and i % 4 == 1):
            num[j] += 1
        if (i + 1) % length == 0:
            j += 1
    print(num)

def main():
    n = 310000000
    length = 100000
    pre(n, length)

if __name__ == "__main__":
    main()
