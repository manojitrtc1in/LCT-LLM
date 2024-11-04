nax = 5 * 10**5 + 44
cou = [0] * nax
prev = [0] * nax
less = [0] * nax

def sum(l, r):
    assert l < nax and r < nax
    return less[r] - less[l]

n = int(input())
for _ in range(n):
    x = int(input())
    cou[x] += 1

for i in range(1, nax):
    less[i] = less[i - 1] + cou[i - 1]

p = 0
for i in range(nax):
    prev[i] = p
    if cou[i]:
        p = i

ans = 0
for y in range(2, nax):
    low = 2
    high = nax - 1
    all_sum = 0
    for i in range(1, nax // y + 1):
        all_sum += i * sum(i * y, min(nax - 1, i * y + y))
    
    if all_sum == 0:
        continue
    
    while low <= high:
        x = (low + high) // 2
        can_get = False
        if x % y == 0:
            can_get = (sum(x, nax - 1) >= 2 or sum(min(nax - 1, 2 * x), nax - 1) >= 1) and (all_sum - 2 * (x // y) >= x)
        else:
            best = -1
            if sum(x, nax - 1) >= 2:
                save = 0
                small_loss = x // y
                for i in range(0, nax, y):
                    top = min(nax - 1, i + y)
                    g = prev[top]
                    if g != 0 and g >= max(i, x) and g % y >= x % y:
                        if cou[g] >= 2:
                            save += 2
                        else:
                            save += 1
                            gg = prev[g]
                            if gg >= max(i, x) and gg % y >= x % y and gg != 0:
                                save += 1
                best = max(best, all_sum - small_loss * 2 - max(0, 2 - save))
            
            if 2 * x < nax and sum(2 * x, nax - 1) >= 1:
                waste = nax
                for i in range(0, nax, y):
                    top = min(nax - 1, i + y)
                    g = prev[top]
                    if g >= 2 * x:
                        waste = min(waste, g // y - (g - 2 * x) // y)
                best = max(best, all_sum - waste)
            
            if best >= x:
                can_get = True
        
        if can_get:
            ans = max(ans, x * y)
            low = x + 1
        else:
            high = x - 1

print(ans)
