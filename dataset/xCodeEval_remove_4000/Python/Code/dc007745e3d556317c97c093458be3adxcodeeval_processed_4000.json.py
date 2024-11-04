
n = int(input())
a = []
cnt_num = dict()
for i in map(int, input().split()):
    cnt_num[i] = cnt_num.get(i, 0) + 1
    a.append(i)
if n == 1:
    print("YES")
    print(*a)
    exit(0)
matrix = [[0] * n for _ in range(n)]
for i in range(n // 2):
    for j in range(n // 2):
        for k, am in cnt_num.items():
            if am >= 4:
                matrix[i][j] = k
                matrix[i][n - j - 1] = k
                matrix[n - i - 1][j] = k
                matrix[n - i - 1][n - j - 1] = k
                cnt_num[k] -= 4
                break
        else:
            print("no")
            exit(0)
if n % 2:
    for i in range(n // 2):
        for k, am in cnt_num.items():
            if am >= 2:
                matrix[i][n // 2] = k
                matrix[n - i - 1][n  // 2] = k
                cnt_num[k] -= 2
                break
        else:
            print("no")
            exit(0)
    for i in range(n // 2):
        for k, am in cnt_num.items():
            if am >= 2:
                matrix[n // 2][i] = k
                matrix[n // 2][n - i - 1] = k
                cnt_num[k] -= 2
                break
        else:
            print("no")
            exit(0)
    for k, am in cnt_num.items():
        if am >= 1:
            matrix[n // 2][n // 2] = k
            break
    else:
        print("no")
        exit(0)
print("YES")
for i in matrix:
    print(*i)