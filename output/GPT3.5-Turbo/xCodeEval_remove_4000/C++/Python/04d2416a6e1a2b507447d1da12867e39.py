def win(a, b):
    if a % 2:
        cnt = 0
        while b:
            cnt += b % a
            b //= a
        return cnt % 2 == 0
    else:
        return b % (a + 1) % 2 == 0

def ss(a, b):
    if not a:
        return False
    if not ss(b % a, a):
        return True
    return win(a, b // a)

t = int(input())
while t > 0:
    a, b = map(int, input().split())
    if ss(min(a, b), max(a, b)):
        print("First")
    else:
        print("Second")
    t -= 1
