import math

mod = int(math.pow(10, 9)) + 7
n = 0
m = 0
a = []
st = []

def main():
    global n, m, a, st
    n = int(input())
    m = int(input())
    a = [n//m] * m
    for i in range(1, n%m+1):
        a[i] += 1
    
    b = [0] * m
    for i in range(m):
        t = ((i)%m * (i)%m)%m
        b[t] += a[i]
    
    ans = 0
    for i in range(m):
        if i == 0:
            ans += (b[i]*(b[i]))
        else:
            ans += b[i] * b[m-i]
    
    print(ans)

if __name__ == "__main__":
    main()
