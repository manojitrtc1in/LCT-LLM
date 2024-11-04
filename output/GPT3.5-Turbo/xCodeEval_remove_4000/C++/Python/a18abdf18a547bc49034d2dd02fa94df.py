ma = {}
a = [0, 0, 0, 0]
while True:
    try:
        s = input()
        if s in ma:
            a[ma[s][0]] += ma[s][1]
    except EOFError:
        break

m = max(a)
if a[0] == m:
    print(1)
elif a[1] == m:
    print(2)
else:
    print(3)
