import math

'''
n = int(input())
nums = list(map(int, input().split()))
numsSum = sum(nums)

if(numsSum % 3 == 0): 
    start = 0
    end = n-1
    a = nums[start]
    b = nums[end]
    numsSum -= a
    numsSum -= b
    ans = 0
    while(start < end - 2 and a <= numsSum and b <= numsSum):
        if(a < b):
            start += 1
            a += nums[start]
            numsSum -= nums[start]
        elif(b < a):
            end -= 1
            b += nums[end]
            numsSum -= nums[end]
        elif(a == b != numsSum):
            if(nums[start+1] == 0):
                start += 1
            elif(nums[end - 1] == 0):
                end -= 1
            else:
                start += 1
                a += nums[start]
                numsSum -= nums[start]
        else:
            if(set(nums[start+1:end]) == set([0])):
                ans += int((end - start) * (end - start - 1) / 2)
                break
            else:
                aCount = 1
                bCount = 1
                while(nums[start+1] == 0):
                    start += 1
                    aCount += 1
                while(nums[end-1] == 0):
                    end -= 1
                    bCount += 1
                ans += aCount * bCount
            start += 1
    print(ans)
            
else:
    print(0)
'''
'''
t = int(input())
for t in range(t):
    n = int(input())
    reds = list(map(int, input().split()))
    m = int(input())
    blues = list(map(int, input().split()))
    a, b = 0, 0
    ans = 0
    total = 0
    while(a < n or b < m ):
        if(a == n ):
            total += blues[b]
            b += 1
        elif(b == m):
            total += reds[a]
            a += 1
        elif(reds[a] > blues[b] and reds[a] > 0):
            total += reds[a]
            a += 1
        elif(b < m - 1 and reds[a] < blues[b] and blues[b] > 0):
            total += blues[b]
            b += 1
        else:
            add = 0
            rSum = 0
            bSum = 0
            while(rSum <= 0 and bSum <= 0):
                if(a + add >= n and b + add >= m):
                    a += add
                    b += add
                    break
                if(a + add <= n-1):
                    rSum += reds[a + add]
                if(b + add <= m-1):
                    bSum += blues[b + add]
                add += 1
            if(rSum > 0):
                a += add
                total += rSum
            elif(bSum > 0):
                b += add
                total += bSum
        ans = max(ans, total)
    print(ans)
'''
'''
n = int(input())
grid = []
paths = [[0] * n for i in range(n)]
for i in range(n):
    grid.append(list(map(str, [char for char in input()])))
if(grid[0][0] == '*'):
    print(0)
else:
    cur = [[0,0]]
    next = set()
    paths[0][0] = 1
    for i in range(2*n-1):
        for cor in cur:
            y = cor[0]
            x = cor[1]
            if(y != 0):
                paths[y][x] += paths[y-1][x]
            if(x != 0):
                paths[y][x] += paths[y][x-1]
            if(y != n-1):
                if(grid[y+1][x] != '*'):
                    next.add((y+1, x))
            if(x != n-1):
                if(grid[y][x+1] != '*'):
                    next.add((y, x+1))
        cur = list(next)
        next = set()
    print(paths[-1][-1])
'''
'''
n, m = map(int, input().split())
fCor = list(map(int, input().split()))
bCor = list(map(int, input().split()))
f = input()
b  = input()
grid = [[0, [0,0], [0,0], 0, 0] * n for i in range(m)]
grid[0][0][1] = fCor
grid[0][0][2] = bCor
cur = set((0,0))
next = set()
while(cur):
    for cor in cur:
        a, b, c = 10**9, 10**9, 10**9
        y, x = cor[0], cor[1]
        if(y > 0):
            a = grid[y-1][x][0]
        if(x > 0):
            b = grid[y][x-1][0]
        if(y > 0 and x > 0):
            c = grid[y-1][x-1][0]
        fAdd = [0,0]
        bAdd = [0,0]
        if(a != 10**9):
            bCor = grid[y-1][x][1]
            bIndex = grid[y-1][x][3]
'''
'''
t = int(input())
for t in range(t):
    n = int(input())
    s = input()
    t = input()
    index = 0
    a = s.replace('b', '')
    b = t.replace('b', '')
    if(a != b):
        print('NO')
        continue
    sCount = 0
    tCount = 0
    yes = True
    for i in range(n):
        if(s[i] == 'a'):
            sCount += 1
        if(t[i] == 'a'):
            tCount += 1
        if(tCount > sCount):
            yes  = False
            break
    if(not yes):
        print('NO')
        continue
    sCount = 0
    tCount = 0
    yes = True
    for i in range(n):
        if(s[i] == 'c'):
            sCount += 1
        if(t[i] == 'c'):
            tCount += 1
        if(sCount > tCount):
            yes  = False
            break
    if(not yes):
        print('NO')
        continue
    print('YES')
'''
'''
n = int(input())
paths = [[] for i in range(n+1)]
tree = [[] for i in range(n+1)]
for i in range(n-1):
    a, b = map(int, input().split())
    paths[a].append(b)
    paths[b].append(a)

def search(start, count, x, prev):
    global paths
    global tree
    next = paths[x]
    count += 1
    if(prev in paths[x]):
        paths[x].remove(prev)
    if(len(paths[x]) > 1):
        count += len(paths[x])
        tree[start] = [paths[x], count]
        for path in paths[x]:
            search(path, 0, path, x)
    elif(len(paths[x]) == 0):
        tree[start] = [[], count]
        return
    else:
        search(start, count, paths[x][0], x)

search(1, 0, 1, 0)

cur = [1]
next = []
print(tree)
ans = 0
while(cur):
    for x in cur:
        for num in tree[x][0]:
            next.append(num)
        ans += math.ceil(math.log2(tree[x][1]))
        trig = tree[x][1] - (len(tree[x][0])+1)
        ans += int(trig*(trig+1)/2)
        ans += (trig+1)*len(tree[x][0])
    cur = next
    next = []
print(ans)
'''
'''
t = int(input())
for t in range(t):
    n = int(input())
    a = input()
    b = input()
    ans = 10**9
    if(a == b):
        print(0)
        continue
    mCount = [0,0]
    nmCount = [0,0]
    for i in range(n):
        if(a[i] == b[i]):
            mCount[int(a[i])] += 1
        else:
            nmCount[int(a[i])] += 1
    if(mCount[0] == mCount[1]-1):
        ans = sum(mCount)
    if(nmCount[0] == nmCount[1]):
        ans = min(sum(nmCount), ans)
    if(ans != 10**9):
        print(ans)
    else:
        print(-1)
'''
'''
n = int(input())
cows = []
for i in range(n):
    cows.append(list(map(int, input().split())))
cows.sort(key = lambda x:x[0])
for i in range(n):
    cows[i][0] =  i+1
cows.sort(key = lambda x:x[1])
for i in range(n):
    cows[i][1] =  i+1
grid = [[0] * (n+1) for i in range(n+1)]
for cow in cows:
    grid[cow[1]][cow[0]] = 1
for i in range(1, n+1):
    for j in range(1, n+1):
        grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1]
ans = n + 1
for i in range(n):
    for j in range(i+1, n):
        cow1 = cows[i]
        cow2 = cows[j]
        x1,y1 = min(cow1[0], cow2[0]), min(cow2[1], cow1[1])
        x2,y2 = max(cow1[0], cow2[0]), max(cow2[1], cow1[1])
        high, low = 1,1
        high = grid[-1][x2] - grid[-1][x1-1] - grid[y2][x2] + grid[y2][x1-1] + 1
        low = grid[y1-1][x2] - grid[y1-1][x1-1] + 1
        ans += high * low
print(ans)
'''
'''
n = int(input())
eCows = []
nCows = []
cows = [[] for i in range(n)]
for i in range(n):
    cow = input().split()
    if(cow[0] == 'E'):
        eCows.append([int(cow[1]),int(cow[2]),i])
    else:
        nCows.append([int(cow[1]),int(cow[2]),i])
eCows.sort(key=lambda x:x[1])
nCows.sort(key=lambda x:x[0])
iters = max(len(eCows), len(nCows))
for i in range(math.ceil(math.sqrt(iters))):
    nextCows = [[] for i in range(n)]
    for eCow in eCows:
        for nCow in nCows:
            if(nCow[0] > eCow[0] and nCow[1] < eCow[1]):
                if(eCow[1] - nCow[1] < nCow[0] - eCow[0] and (cows[nCow[2]] == [] or cows[nCow[2]][0] >= eCow[1]-nCow[1])):
                    nextCows[eCow[2]]= [nCow[0] - eCow[0], nCow[2]]
                    continue
    for nCow in nCows:
        for eCow in eCows:
            if(nCow[0] > eCow[0] and nCow[1] < eCow[1]):
                if(eCow[1] - nCow[1] > nCow[0] - eCow[0] and (cows[eCow[2]] == [] or cows[eCow[2]][0] >= nCow[0]-eCow[0])):
                    nextCows[nCow[2]] = [eCow[1] - nCow[1], eCow[2]]
                    continue
    cows = nextCows
ans = [0] * n
for i in range(n):
    cow = cows[i]
    if(cow != []):
        curCow = cow[1]
        curTime = cow[0]
        ans[curCow] += 1
        while(True):
            if(cows[curCow] == []):
                break
            else:
                curCow = cows[curCow][1]
                ans[curCow] += 1
for num in ans:
        print(num)
'''
'''
n, k = map(int, input().split())
moves = [[] for i in range (n+1)]
ans = [0] * n
for i in range(k):
    a,b = map(int, input().split())
    moves[a].append([b, i])
    moves[b].append([a, i])
start = 0
prevCount = -1
def dfs(pos, time, positions):
    global start
    global moves
    global ans
    global prevCount
    positions.add(pos)
    if(moves[pos] == []):
        ans[start-1] = len(positions)
        return
    if(pos == start and (prevCount == len(positions))):
        ans[start-1] = len(positions)
        return
    if(pos == start and len(positions) != 1):
        prevCount = len(positions)
    if(moves[pos][-1][1] <= time):
        time = moves[pos][0][1]
        pos = moves[pos][0][0]
        dfs(pos, time, positions)
    else:
        for move in moves[pos]:
            if(move[1] > time):
                time = move[1]
                pos = move[0]
                dfs(pos, time, positions)
                break
for i in range(1, n+1):
    start = i
    prevCount = -1
    dfs(i, -1, set())
for num in ans:
    print(num)
'''
'''
n, q = map(int, input().split())
fence = input()
for q in range(q):
    a, b = map(int, input().split())
    sec = fence[:a-1]
    uniqs = list(set(sec))
    strokes = len(uniqs)
    up = [0] * len(uniqs)
    for i in range(a-2):
        if(len(sec) > 1 and sec[i] > sec[i+1]):
            if(up[uniqs.index(sec[i])] == 1):
                strokes += 1
            up[uniqs.index(sec[i])] = abs(up[uniqs.index(sec[i])]-1)
    if(len(sec) > 1 and sec[-1] > sec[-2] and up[uniqs.index(sec[-1])] == 1):
        strokes += 1
    sec = fence[b:]
    uniqs = list(set(sec))
    up = [0] * len(uniqs)
    strokes += len(uniqs)
    for i in range(n-b-1):
        if(len(sec) > 1 and sec[i] > sec[i+1]):
            if(up[uniqs.index(sec[i])] == 1):
                strokes += 1
            up[uniqs.index(sec[i])] = abs(up[uniqs.index(sec[i])]-1)
    if(len(sec) > 1 and sec[-1] > sec[-2] and up[uniqs.index(sec[-1])] == 1):
        strokes += 1
    print(strokes)
'''
'''
m, s = map(int, input().split())
if((m > 1 and s == 0) or s > m*9):
    print("-1 -1")
elif(m == 1 and s == 0):
    print("0 0")
else:
    minNum, maxNum = "", ""
    minNum = "1" * m
    num = s
    num -= m
    for i in range(m-1, -1, -1):
        minNum = minNum[:i] + str(int(minNum[i]) + min(8, num)) + minNum[i+1:]
        num -= min(8, num)
    maxNum = "1" * m
    num = s
    num -= m
    for i in range(m):
        maxNum = maxNum[:i] + str(int(maxNum[i]) + min(8, num)) + maxNum[i+1:]
        num -= min(8, num)
    print(maxNum)
'''
'''
n, k = map(int, input().split())
cows = [i for i in range(1, n+1)]
states = [set() for i in range(k)]
pos = [set() for i in range(n)]
moves = []
for i in range(n):
    pos[i].add(cows[i])
for i in range(k):
    moves.append(list(map(int, input().split())))
i = 0
while True:
    move = moves[i]
    prevLen = len(states[i])
    a, b = move[0], move[1]
    cow1, cow2 = cows[a-1], cows[b-1]
    cows[a-1] = cow2
    cows[b-1] = cow1
    pos[cow1-1].add(b)
    pos[cow2-1].add(a)
    states[i].add(tuple(cows))
    if(len(states[i]) == prevLen):
        break
    i += 1
    i %= k
for p in pos:
    print(len(p))
'''

t = int(input())
for t in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    a = 0
    b = 1
    maxNum = 0
    while(b < n):
        if(nums[b] != nums[a]):
            maxNum = max(maxNum, b-a)
            a = b
        b += 1
    maxNum = max(maxNum, b-a)
    if(maxNum > math.ceil(n/2)):
        print(n - ((n - maxNum)*2))
    else:
        if(n%2==0):
            print(0)
        else:
            print(1)
