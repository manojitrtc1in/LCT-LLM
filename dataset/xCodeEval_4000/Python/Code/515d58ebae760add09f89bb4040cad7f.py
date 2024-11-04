import math

'''
t = int(input())

for t in range(t):
    n = int(input())
    s = input()
    if(len(set(s)) == 1):
        print(n)
    else:
        ans = 0
        i = round(n/2) - 1
        centerChar = s[i]
        while(i >= 0 and s[i] == centerChar):
            ans += 1
            i -= 1
        i = round(n/2)
        while(i <= n-1 and s[i] == centerChar):
            i += 1
            ans += 1
        print(ans)
'''
'''
t = int(input())

for t in range(t):
    hot, cold, total = map(int, input().split())
    if(hot == total):
        print(1)
    elif((hot + cold)/2 == total):
        print(2)
    else:
        a = hot - total
        add = total - ((hot + cold)/2)
        x = math.ceil(a * (1/add))
        if(x % 2 == 0):
            x += 1
        if(abs((((hot * math.ceil((x+2)/2)) + (cold * math.floor((x+2)/2)))/(x+2)) - total) < abs((((hot * math.ceil(x/2)) + (cold * math.floor(x/2)))/x) - total)):
            x += 2
        if(x < 0):
            print(2)
        else:
            print(x)
'''
'''
t = int(input())

for t in range(t):
    n = int(input())
    nums = list(map(int, [char for char in input()]))
    preNums = nums.copy()
    for i in range(1, n):
        preNums[i] += preNums[i-1]
    preNums = [0] + preNums
    nums = [0] + nums
    n += 1
    ans = 0
    for i in range(1, n):
        index = i
        while(index < n):
            if(preNums[index] - preNums[i-1] == index - i + 1):
                ans += 1
            if(index == n - 1):
                break
            elif(nums[index+1] == 0 or index + nums[index+1] >= n):
                index += 1
            else:
                index += nums[index+1]
    print(ans)
'''
'''
infile = open("cowdance.in", 'r')
outfile = open("cowdance.out", 'w')

n, tmax = map(int, infile.readline().split())
cows = []

for i in range(n):
    cows.append(int(infile.readline()))

cows = sorted(cows, reverse = True)
k = 0
right = n
left = 0
mid = 0
ans = nx

for i in range(math.floor(math.log2(n)) + 1):
    mid = (left + right) // 2
    if(mid == 0):
        continue
    k = mid
    stage = cows[:k]
    sec = k
    while(sec < n):
        sec += k
        next = cows[sec-k:sec]
        stage.sort()
        for j in range(len(next)):
            stage[j] += next[j]
    if(max(stage) <= tmax and k < ans):
        ans = k
        right = mid
    else:
        left = mid + 1
outfile.write(str(ans))
'''
'''
infile = open("convention.in", 'r')
outfile = open("convention.out", 'w')

n, m, c = map(int, infile.readline().split())
cows = list(map(int, infile.readline().split()))
cows.sort()

times = []
for i in range(0, n, c):
    sec = cows[i:i+c]
    times.append(sec[-1] - sec[0])

breaks = ((m*c) - n) // 2
times.sort()
for i in range(breaks):
    if(times):
        times.pop(-1)
if(len(times) > 0):
    outfile.write(str(times[-1]))
else:
    outfile.write('0')
'''
'''
infile = open("angry.in", 'r')
outfile = open("angry.out", 'w')

n, k = map(int, infile.readline().split())
haybales = []

for i in range(n):
    haybales.append(int(infile.readline()))
haybales.sort()

low = 0
high = n
r = (low + high)//2
ans = 10**9

for i in range(math.ceil(math.log2(n))):
    r = (low + high)//2
    newHaybales = haybales.copy()
    for j in range(k):
        if(newHaybales):
            start = newHaybales[0]
            while(newHaybales and newHaybales[0] - start <= r*2):
                newHaybales.pop(0)
    if(newHaybales):
        low = r
    else:
        if(r < ans):
            ans = r
        high = r
        
outfile.write(str(ans))
'''
'''
infile = open("socdist.in", 'r')
outfile = open("socdist.out", 'w')

n, m = map(int, infile.readline().split())
segs = []
for i in range(m):
    segs.append(list(map(int, infile.readline().split())))

cows = n
high = segs[-1][1]
low = segs[0][0]
d = 0
dis = high - low
ans = 10**9
for i in range(math.ceil(math.log2(dis))):
    cows = n-1
    d = (low + high)//2
    index = 0
    start = segs[0][0]
    end = segs[0][1]
    while(True):
        if(start + d <= end):
            cows -= 1
            start += d
        else:
            if(index < m-1):
                index += 1
            else:
                break
            start = segs[index][0]
            end = segs[index][1]
            cows -= 1
    if(cows <= 0):
        if(d < ans):
            ans = d
        low = d
    else:
        high = d

outfile.write(str(ans))
'''
'''
infile = open('convention2.in', 'r')
outfile = open('convention2.out', 'w')

n = int(infile.readline())
cows = []

for i in range(n):
    cows.append(list(map(int, infile.readline().split())) + [i])

cows = sorted(cows, key = lambda x:x[0])
time = cows[0][0]
line = PriorityQueue()
ans = 0
count = 0
total = 0

while(count < n):
    prevCowLen = len(cows)
    while(cows and cows[0][0] <= time):
        line.put((cows[0][2], cows[0][0:2]))
        cows.pop(0)
        total += 1
    if(total == 0):
        time = cows[0][0]
        line.put((cows[0][2], cows[0][0:2]))
        cows.pop(0)
        total += 1
    curCow = line.get()[1]
    if(time - curCow[0] > ans):
        ans = time - curCow[0]
    time += curCow[1]
    count += 1
    total -= 1
    
outfile.write(str(ans))
'''
'''
infile = open("snowboots.in", 'r')
outfile  = open("snowboots.out", 'w')

n, b = map(int, infile.readline().split())
snow = list(map(int, infile.readline().split()))

for i in range(b):
    boot = list(map(int, infile.readline().split()))
    maxD = 0
    for i in range(1, n - boot[1]+1):
        if(min(snow[i:i+boot[1]]) > maxD):
            maxD = min(snow[i:i+boot[1]])
    if(maxD > boot[0]):
        outfile.write('0' + '\n')
    else:
        outfile.write('1' + '\n')
'''
'''
movies = []
def check(i, end):
    global movies
    n = len(movies)
    i += 1
    while(i < n and movies[i][0] < end):
        if(movies[i][1] < end):
            return False
        i += 1
    return True

n, k = map(int, input().split())
movies = []

for i in range(n):
    movies.append(list(map(int, input().split())))

movies = sorted(movies, key = lambda x:x[0])
ans = 0

for k in range(k):
    index = 0
    while(index < len(movies)):
        if(check(index, movies[index][1])):
            ans += 1
            endTime = movies[index][1]
            movies.pop(index)
            while(index < len(movies) and movies[index][0] < endTime):
                index += 1
        else:
            index += 1
print(ans)
'''
'''
n = int(input())
times = []
for i in range(n):
    times.append(list(map(int, input().split())))
times = sorted(times, key = lambda x:x[0])
ans = 0
time = 0
for task in times:
    time += task[0]
    ans += task[1] - time
print(ans)
'''
'''
n, k = map(int, input().split())
nums = [0] + list(map(int, input().split()))
n += 1
total = sum(nums)
for i in range(1, n):
    nums[i] += nums[i-1]
low = 0
high = total
mid = (low + high)//2
ans = total+1
if(n == 2):
    print(nums[1])
else:
    for i in range(45):
        mid = (low + high)//2
        start = 1
        cur = 2
        for j in range(k):
            while(cur < n and nums[cur] - nums[start-1] <= mid):
                cur += 1
            start = cur
        if(cur == n):
            if(mid < ans):
                ans = mid
            high = mid
        else:
            low = mid + 1
    print(ans)
'''
'''
burger = input()
bCount, sCount, cCount = burger.count('B'), burger.count('S'), burger.count('C')
bTotal, sTotal, cTotal = map(int, input().split())
bPrice, sPrice, cPrice = map(int, input().split())
money = int(input())
ans = 0
if(bCount == 0):
    bTotal = 0
if(sCount == 0):
    sTotal = 0
if(cCount == 0):
    cTotal = 0

while(True):
    if(bTotal > 0 or sTotal > 0 or cTotal > 0):
        if(bTotal >= bCount):
            bTotal -= bCount
        elif(bTotal > 0 and bTotal < bCount):
            a = bCount - bTotal
            if(money < a * bPrice):
                break
            money -= a * bPrice
            bTotal = 0
        else:
            if(money < bPrice * bCount):
                break
            money -= bPrice * bCount
        if(sTotal >= sCount):
            sTotal -= sCount
        elif(sTotal > 0 and sTotal < sCount):
            a = sCount - sTotal
            if(money < a * sPrice):
                break
            money -= a * sPrice
            sTotal = 0
        else:
            if(money < sPrice * sCount):
                break
            money -= sPrice * sCount
        if(cTotal >= cCount):
            cTotal -= cCount
        elif(cTotal > 0 and cTotal < cCount):
            a = cCount - cTotal
            if(money < a * cPrice):
                break
            money -= a * cPrice
            cTotal = 0
        else:
            if(money < cPrice * cCount):
                break
            money -= cPrice * cCount
        ans += 1
    else:
        ans += money // (bCount * bPrice + sCount * sPrice + cCount * cPrice)
        break
print(ans)
'''
'''
n = int(input())

for i in range(n):
    ans = 0
    num = int(input())
    if(math.sqrt(num) % 1 == 0):
        ans += 1
    for fac in range(1, math.ceil(math.sqrt(num))):
        if(num % fac == 0):
            ans += 2
    print(ans)
'''
'''
def gcd(a, b):
    return a if b == 0 else gcd(b, a%b)
print(gcd(29384, 10293))
'''
'''
n = int(input())
MOD = 10**9 + 7

for i in range(n):
    a, b = map(int, input().split())
    print(pow(a, b, MOD))
'''
'''
def findBi(n, k):
    if(k == 0):
        return 1
    if(n == k):
        return 1
    return findBi(n-1, k-1) + findBi(n-1, k)

n = int(input())

for i in range(n):
    a, b = map(int, input().split())
    ans = findBi(a, b)
    print(ans)
'''
'''
infile = open("time.in", 'r')
outfile = open("time.out", 'w')

n, m, c = map(int, infile.readline().split())
cities = list(map(int, infile.readline().split()))
paths = [[] for i in range(n+1)]
for i in range(m):
    a, b = map(int, infile.readline().split())
    paths[a].append(b)
'''
'''
n, x = map(int, input().split())
coins = list(map(int, input().split()))
vals = [0] * (x+1)

for i in range(1, x+1):
    vals[i] = 10**9
    for c in coins:
        if(i - c >= 0):
            vals[i] = min(vals[i], vals[i-c]+1)
print(vals[-1])
'''
'''
n, a, b = map(int, input().split())
vals = [[0, 1] for i in range(n)]
vals[0][0] = 1
            
for i in range(1, n+1):
    if(vals[i-a] == 1):
        vals[i] = 1
        vals[math.floor(i/2)] = 1
    if(i - b >= 0):
        if(vals[i-b] == 1):
            vals[i] = 1
            vals[math.floor(i/2)] = 1

for i in range(n, -1, -1):
    if(vals[i] == 1):
        print(i)
        break
'''
'''
n, k = map(int, input().split())
heights = [0] + list(map(int, input().split()))
costs = [0] * (n+1)
if(k >= n-1):
    print(heights[-1] - heights[1])
else:
    for i in range(2, k+1):
      costs[i] = abs(heights[i] - heights[1])
    for i in range(k+1, n+1):
      curCost = 10**9
      for j in range(i-k, i):
        curCost = min(curCost, abs(heights[j] - heights[i]) + costs[j])
      costs[i] = curCost
    print(costs[-1])
'''
'''
n = int(input())
acts = []
for i in range(n):
    acts.append(list(map(int, input().split())))
for i in range(1, n):
    acts[i][0] += max(acts[i-1][1], acts[i-1][2])
    acts[i][1] += max(acts[i-1][0], acts[i-1][2])
    acts[i][2] += max(acts[i-1][1], acts[i-1][0])
print(max(acts[-1]))
'''
'''
n, x = map(int, input().split())
coins = list(map(int, input().split()))
coins.sort()
vals = [0]*(x+1)
vals[0] = 1
for i in range(x+1):
    if(vals[i] >= 1):
        for num in coins:
            if(i+num <= x):
                vals[i+num] += vals[i]
print(vals[-1] % (10**9 + 7))
'''
'''
n, w = map(int, input().split())
items = []
for i in range(n):
    items.append(list(map(int, input().split())))
table = [[0] * (w+1) for i in range(n+1)]
for i in range(w):
    table[0][i] = 0
for i in range(n):
    table[i][0] = 0

for i in range(1, n+1):
    for capacity in range(1, w+1):
        maxValWithoutCur = table[i-1][capacity]
        maxValWithCur = 0
        if(capacity >= items[i-1][0]):
            maxValWithCur += items[i-1][1]
            remCap = capacity - items[i-1][0]
            maxValWithCur += table[i-1][remCap]
        table[i][capacity] = max(maxValWithoutCur, maxValWithCur)
print(table[n][w])
'''
'''
t = int(input())
for t in range(t):
    n = int(input())
    s = input()
    if(len(set(s)) == 1):
        print(n)
        continue
    ans = n * (n+1) / 2
    for i in range(n-1):
        if(i <= n-3):
            if(len(set(s[i:i+3])) == 1):
                ans -= (n - i+2)
        if(len(set(s[i:i+2])) == 1):
                ans -= i+1
    print(int(ans))
'''
'''
t = int(input())
for i in range(t):
    n, m, k = map(int, input().split())
    a = input()
    b = input()
    c = ''
    a = ''.join(sorted([char for char in a]))
    b = ''.join(sorted([char for char in b]))
    aCount = 0
    bCount = 0
    while(a != '' and b != ''):
        if(aCount != k and (a[0] < b[0] or bCount == k or (a[0] == b[0] and len(a) < len(b)))):
            c += a[0]
            aCount += 1
            bCount = 0
            a = a[1:]
        else:
            c += b[0]
            bCount += 1
            aCount = 0
            b = b[1:]
    print(c)
'''

for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = sorted(arr)
    if(n==1):
        print(-1)
        continue
    for i in range(n-1):
        if(arr[i]==ans[i]):
            ans[i],ans[i+1]=ans[i+1],ans[i]
    if(ans[n-1]==arr[n-1]):
        ans[n-1],ans[n-2] = ans[n-2],ans[n-1]
    print(*ans)
