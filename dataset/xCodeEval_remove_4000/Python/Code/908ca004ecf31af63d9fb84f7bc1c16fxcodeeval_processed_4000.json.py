
t = int(input())
for _ in range(t):
    s = list(input())
    a = [s.count('R'), s.count('S'), s.count('P')]
    if a[0] == max(a):
        print('P' * len(s))
    elif a[1] == max(a):
        print('R' * len(s))
    else:
        print('S' * len(s))