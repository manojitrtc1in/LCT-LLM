






































































































































































































































































































































































































































































































































































































































































for _ in range(int(input())):
    n= int(input())
    arr = [list(map(int, input())) for i in range(n)]
    res=0
    for i in range(n):
        for j in range(n):
            ans = arr[i][j] + arr[j][n-1-i] + arr[n-1-i][n-1-j] + arr[n-1-j][i]
            res+= min(ans, 4-ans)
    print(res//4)
    






































































































































































































































































































































































































































































































































































































































































# }