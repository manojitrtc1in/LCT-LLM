
























































































































































































































































import collections

























































































































































































































































































































































































































































































































































































































































































































































































































































l = int(input())
ans = 0
c = [input() for i in range(l)]
stack = [1]
for i in range(l):
    if c[i] == 'add':
        ans += stack[-1]
    elif c[i] == 'end':
        stack.pop()
    else:
        stack.append(min(stack[-1] * int(c[i].split()[1]), 2**32))
    if ans >= 2**32:
        ans = 'OVERFLOW!!!'
        break
print(ans)
