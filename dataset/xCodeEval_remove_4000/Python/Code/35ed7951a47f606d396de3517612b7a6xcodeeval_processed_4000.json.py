
























































































































































































































































import collections






































































































































































































































































































































































































































































































































































































































































































n = int(input())
a = list(map(int, input().split()))
a.sort()
print('NO' if a[-3] + a[-2] <= a[-1] else 'YES')
if a[-3] + a[-2] > a[-1]:
    print(' '.join(str(i) for i in a[:-3] + [a[-3]] + [a[-1]] + [a[-2]]))