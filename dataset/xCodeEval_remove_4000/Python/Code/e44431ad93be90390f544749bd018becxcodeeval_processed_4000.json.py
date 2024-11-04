
n = int(input())
for x in range(n):
    N = int(input())
    a = list(map(int, input().split()))
    zero, pos, neg = 0, 0, 0
    for i in range(N):
        if not i % 2:
            if a[i] < 0: a[i] *= -1
        else:
            if a[i] > 0: a[i] *= -1
    print(' '.join(str(i) for i in a))
        