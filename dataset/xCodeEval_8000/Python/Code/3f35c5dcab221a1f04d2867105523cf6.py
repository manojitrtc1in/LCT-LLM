
























































































































































































































































import collections









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































n = int(input())
a = list(map(int, input().split()))
m = int(input())
q = list(map(int, input().split()))
a.sort()
total = sum(a)
for i in q:
    print(total - a[-i])
