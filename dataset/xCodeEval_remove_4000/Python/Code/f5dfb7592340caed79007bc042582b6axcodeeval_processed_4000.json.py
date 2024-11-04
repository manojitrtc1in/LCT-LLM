




















import sys
for _ in range(int(input())):
  n, m = map(int, input().split())
  a = [list(map(int, input())) for i in range(n)]
  ans = "YES"
  for i in range(n-1):
    for j in range(m-1):
      if a[i][j] + a[i+1][j] + a[i][j+1] + a[i+1][j+1] == 3:
        ans = "NO"
  print(ans)
