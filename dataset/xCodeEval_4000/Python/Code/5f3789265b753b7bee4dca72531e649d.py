def cmp (key):
    return key[0]

































































































































































































































































































































































































































































































































































































n, s = [int(hoiii) for hoiii in input().split()]
hmmmm = []
for i in range(n):
    x, y, k = [int(hoi) for hoi in input().split()]
    hmmmm.append(((x**2 + y**2)**0.5, k))
hmmmm.sort(key=cmp)
megamillion = 1000000 - s
naswer = 0
for i in hmmmm:
    if megamillion <= 0:
        break
    else:
        megamillion = megamillion - i[1]
        naswer = i[0]
if megamillion <= 0:
    print(naswer)
else:
    print(-1)