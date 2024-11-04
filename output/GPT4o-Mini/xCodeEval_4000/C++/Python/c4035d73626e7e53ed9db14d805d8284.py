import math

def popcount(x):
    return bin(x).count('1')

def main():
    n, p = map(int, input().split())
    
    if p == 0:
        print(popcount(n))
        return
    
    if p > 0:
        for i in range(1, 36):
            n -= p
            if n < 0:
                print(-1)
                return
            if popcount(n) <= i and popcount(n) != 0:
                if popcount(n) == 1 and i > math.log(n, 2) + 1:
                    print(-1)
                    return
                print(i)
                return
        print(-1)
        return

    if p < 0:
        for i in range(1, 36):
            n += -p
            if n < 0:
                continue
            if popcount(n) <= i and popcount(n) != 0:
                if popcount(n) == 1 and i > math.log(n, 2) + 1:
                    print(-1)
                    return
                print(i)
                return
        print(-1)
        return

if __name__ == "__main__":
    main()
