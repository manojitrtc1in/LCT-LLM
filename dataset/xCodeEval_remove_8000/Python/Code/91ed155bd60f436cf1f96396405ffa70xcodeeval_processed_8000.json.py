
























































































































































































































































import collections





























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































n = int(input())
a = list(map(int, input().split()))
dic = {}
for i in range(2 * n):
    dic.setdefault(a[i], []).append(i)
ans, prev1, prev2 = 0, 0, 0
for i in range(n):
    ans += abs(prev1 - min(dic[i + 1])) + abs(prev2 - max(dic[i + 1]))
    prev1, prev2 = min(dic[i + 1]), max(dic[i + 1])
print(ans)