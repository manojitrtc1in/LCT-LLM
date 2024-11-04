
sets = int(input())
while sets:
    sets -= 1
    a, b, c = map(int, input().split())
    if a >= c: print(-1, end = " ")
    else: print(1, end = " ")
    if a * b <= c: print(-1)
    else: print(b)
        
