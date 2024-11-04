from sys import stdin, stdout

def yes():
    stdout.write("Yes\n")

def no():
    stdout.write("No\n")

def main():
    a = int(stdin.readline().strip())
    n = 10**17 * 18
    n %= a
    k = n

    for i in range(44):
        n = (n + k) % a

    if n < 0:
        n += a
    c = a - n
    d = c + 10**18 - 1
    stdout.write(f"{c} {d}\n")

if __name__ == "__main__":
    main()
