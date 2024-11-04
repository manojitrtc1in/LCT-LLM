import sys

def main():
    b, d = map(int, input().split())
    a = input()
    c = input()
    t = [0] * len(c)
    s = 0
    n = len(c)
    for i in range(len(c)):
        k = t[i]
        for j in range(len(a)):
            if a[j] == c[(i + k) % n]:
                k += 1
        t[i] = k
    for i in range(b):
        s += t[s % n]
    print(s // n // d)

if __name__ == "__main__":
    main()
