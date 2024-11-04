















t = int(input())
for t in range(t):
    x = int(input())
    if(x == 1):
        print(3)
        continue
    b = bin(x)[2:][::-1]
    i = 0
    ans = 1
    while(b[i] != '1'):
        ans *= 2
        i += 1
    if(i+1 == len(b)):
        ans += 1
    print(ans)
