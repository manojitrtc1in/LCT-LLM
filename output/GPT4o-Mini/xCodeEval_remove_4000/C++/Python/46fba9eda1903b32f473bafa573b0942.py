from sortedcontainers import SortedSet

MOD = int(1e9 + 7)
INF = int(1e18)

def yes():
    print("Yes")

def no():
    print("No")

def main():
    a = int(input())
    n = int(1e17) * 18

    n %= a
    k = n

    for i in range(44):
        n = (n + k) % a

    if n < 0:
        n += a

    c = a - n
    d = c + int(1e18) - 1
    print(c, d)

if __name__ == "__main__":
    main()
