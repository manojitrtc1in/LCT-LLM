
























































































































































































































































import collections





































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































for t in range(int(input())):
    n = int(input())
    s = input()
    l, r = 0, 0
    if s[0] == '<':
        for i in range(1, n):
            if s[i] != s[i - 1]:
                l = i
                break
    if s[-1] == '>':
        for i in range(n - 2, -1, -1):
            if s[i] != s[i + 1]:
                r = n - i - 1
                break
    print(min(l, r))