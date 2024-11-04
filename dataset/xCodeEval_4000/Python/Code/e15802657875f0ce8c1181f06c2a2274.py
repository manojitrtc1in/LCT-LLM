import math
import sys
sys.setrecursionlimit(200006)
'''
t = int(input())

for t in range(t):
    N = int(input())
    stones = list(map(int, input().split()))[1:-1]
    ans = 0
    if(N == 3 and stones[0]%2):
        print('-1')
    elif(len(stones) == stones.count(1)):
        print('-1')
    else:
        for stone in stones:
            ans += stone//2
            if(stone%2): ans += 1
        print(ans)
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    s = input()
    curIndex = 1
    opers = 0
    while(curIndex < len(s)):
        curIndex += 1
        sec = s[:curIndex]
        regular = False
        count = 0
        if(curIndex % 2 == 0):
            for char in sec:
                if(char == "("):
                    count += 1
                else:
                    count -= 1
                if(count < 0):
                    break
            if(count == 0): regular = True

        if(regular):
            s = s[curIndex:]
            curIndex = 1
            opers += 1
        elif(sec == sec[::-1]):
            s = s[curIndex:]
            curIndex = 1
            opers += 1

    print(str(opers) + " " + str(len(s)))
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    passes = list(map(int, input().split()))
    total = sum(passes)
    if(total == 0):
        print(0)
        continue
    maxPass = max(passes)
    if(maxPass <= total - maxPass):
        print(1)
    else:
        print(maxPass - (total - maxPass))
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    cakes = list(map(int, input().split()))
    num1 = max(cakes)
    cakes.remove(num1)
    num2 = max(cakes)
    print(num1 + num2)
'''
'''
t = int(input())

for t in range(t):
    elegant = True
    inputs = list(map(int, input().split()))
    n, m = inputs[0], inputs[1]
    grid = []
    for k in range(n):
        grid.append(list(map(int, [char for char in input()])))
    if(n == 1 or m == 1):
        print("YES")
        continue
    for x in range(m):
        for y in range(n):
            if(grid[y][x] != 1): continue
            blackCount = 0
            sub = False
            if(x > 0):
                if(grid[y][x-1] == 1):
                    blackCount += 1
                    if(y == 0):
                        if(grid[y+1][x-1] == 0):
                            sub = True
                    elif(y == n-1):
                        if(grid[y-1][x-1] == 0):
                            sub = True
                    else:
                        if(grid[y-1][x-1] == 0 and grid[y+1][x-1] == 0):
                            sub = True
            if(x < m-1):
                if(grid[y][x+1] == 1):
                    blackCount += 1
                    if(y == 0):
                        if(grid[y+1][x+1] == 0):
                            sub = True
                    elif(y == n-1):
                        if(grid[y-1][x+1] == 0):
                            sub = True
                    else:
                        if(grid[y-1][x+1] == 0 and grid[y+1][x+1] == 0):
                            sub = True
            if(y < n-1):
                if(grid[y+1][x] == 1):
                    blackCount += 1
                    if(x == 0):
                        if(grid[y+1][x+1] == 0):
                            sub = True
                    elif(x == m-1):
                        if(grid[y+1][x-1] == 0):
                            sub = True
                    else:
                        if(grid[y+1][x-1] == 0 and grid[y+1][x+1] == 0):
                            sub = True
            if(y > 0):
                if(grid[y-1][x] == 1):
                    blackCount += 1
                    if(x == 0):
                        if(grid[y-1][x+1] == 0):
                            sub = True
                    elif(x == m-1):
                        if(grid[y-1][x-1] == 0):
                            sub = True
                    else:
                        if(grid[y-1][x-1] == 0 and grid[y-1][x+1] == 0):
                            sub = True

            if(sub and blackCount >= 2):
                elegant = False
                break
            
    if(elegant): print("YES")
    else: print("NO")
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    if(sum(nums[0:(math.ceil(N/2))]) < sum(nums[math.ceil((N + 0.5)/2):])):
        print("YES")
    else:
        print("NO")
'''
'''
t = int(input())

for t in range(t):
    inputs = list(map(int, input().split()))
    N, k = inputs[0], inputs[1]
    nums = list(map(int, input().split()))
    nums.sort()
    sett = set(nums)
    yes = False
    for i in range(N):
        if(nums[i] + k in sett):
            yes = True
    if(yes): print("YES")
    else: print("NO")
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    nums = set(map(int, input().split()))
    if(1 in nums):
        sett = set()
        for num in nums:
            sett.add(num-1)
            sett.add(num)
        if(len(sett) == len(nums)*2):
            print("YES")
        else:
            print("NO")
    else: print("YES")
'''
'''
t = int(input())

for t in range(t):
    inputs = list(map(int, input().split()))
    N, x = inputs[0], inputs[1]
    nums = list(map(int, input().split()))
    nums.sort()
    ans = N
    for num in nums:
        if(num*x in nums):
            
            ans -= 2
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    nums = list(map(int, input().split()))
    ans = []
    i = 0
    j = N-1
    for k in range(N):
        if(nums[j] > nums[i]):
            ans.append(nums[j])
            j -= 1
        else:
            ans.insert(i, 0)
            i += 1
    check = []
    i = 0
    j = N-1
    for k in range(N):
        if(ans[j] < ans[i]):
            check.append(ans[j])
            j -= 1
        else:
            check.insert(0, ans[i])
            i += 1
    print(check, nums)
    if(check == nums):
        for num in ans[:-1]:
            print(num, end=" ")
        print(ans[-1])
    else:
        print(-1)
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    candies = list(map(int, input().split())) 
    if(N == 1):
        if(N == 1 and candies[0] > 1):
            print("NO")
        else:
            print("YES")
    else:
        a = max(candies)
        candies.remove(a)
        b = max(candies)
        if(a > b + 1):
            print("NO")
        else:
            print("YES")
'''
'''
t = int(input())

for t in range(t):
    inputs = list(map(int, input().split()))
    l,r,a = inputs[0], inputs[1], inputs[2]
    if(r % a != a - 1 and r - (r % a) - 1 >= l):
        r -= (r % a) + 1
    print(math.floor(r/a) + r % a)
'''
'''
t = int(input())

for t in range(t):
    n,k = map(int, input().split())
    if(n == 1 and k == 1):
        print("YES")
        print(1)
        continue
    elif(n % 2 == 1 and k != 1):
        print("NO")
        continue
    else:
        print("YES")
        odd = 1
        even = 2
        for i in range(n):
            for j in range(k):
                if(i % 2):
                    print(even, end=' ')
                    even += 2
                else:
                    print(odd, end=' ')
                    odd += 2
            print("")
''' 
'''
t = int(input())

for t in range(t):
    oddCoins, evenCoins = map(int, input().split())
    if(oddCoins == 0):
        print(1)
        continue
    ans = oddCoins
    ans += evenCoins * 2 + 1
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    cH, cD = map(int, input().split())
    mH, mD = map(int, input().split())
    coins, dUpgrade, hUpgrade = map(int, input().split())
    yes = False

    for i in range(coins + 1):
        newCH = cH + (coins-i)*hUpgrade
        newCD = cD + (coins - (coins-i))*dUpgrade
        if(newCD * math.ceil(newCH/mD) >= mH):
            yes = True
            break

    if(yes):
        print("YES")
    else:
        print("NO")

'''
'''
t = int(input())

for t in range(t):
    a, s = input().split()   
    aIndex = len(a)-1
    sIndex = len(s) - 1
    b = ""

    while True:
        if(aIndex < 0):
            b += str(s[0:sIndex+1])
            break
        if(aIndex >= 0 and sIndex < 0):
            b = "1-"
            break
        if(aIndex < 0 and sIndex < 0):
            break
        aNum = a[aIndex]
        sNum = s[sIndex]
        if(int(aNum) <= int(sNum)):
            b += str(int(sNum)-int(aNum))
            aIndex -= 1
            sIndex -= 1
        elif(sIndex > 0 and s[sIndex-1] == "1"):
            b += str(int(s[sIndex-1:sIndex+1]) - int(aNum))
            aIndex -= 1
            sIndex -= 2
        else:
            b = "1-"
            break
    print(b)
    print(int(b[::-1]))
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    nums = list(map(int, input().split()))
    if(len(set(nums)) == 1):
        print(0)
        continue
    assignNum = nums[-1]
    numsAhead = 0
    index = N-1
    subSegments = []
    while(nums[index] == assignNum):
        numsAhead += 1
        index -= 1
    curSegment = [0]
    for i in range(N-1):
        if(nums[i] != assignNum and nums[i+1] == assignNum):
            curSegment.append(i)
            subSegments.append(curSegment)
            curSegment = []
        if(nums[i] == assignNum and nums[i+1] != assignNum):
            curSegment.append(i+1)
'''
'''
t = int(input())

for t in range(t):
    ans = 0
    w, h = list(map(int, input().split()))
    xs = list(map(int, input().split()))[1:]
    dis = max(xs) - min(xs)
    xs = list(map(int, input().split()))[1:]
    if(max(xs) - min(xs) > dis):
        dis = max(xs) - min(xs)
    ans = dis * h
    ys = list(map(int, input().split()))[1:]
    dis = max(ys) - min(ys)
    ys = list(map(int, input().split()))[1:]
    if(max(ys) - min(ys) > dis):
        dis = max(ys) - min(ys)
    if(dis * w > ans):
        ans = dis * w
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    N = int(input())
    nums = list(map(int, input().split()))
    nums.sort()
    maxMin = nums[0]
    for i in range(N-1):
        if(nums[i+1] - nums[i] > maxMin):
            maxMin = nums[i+1] - nums[i]
    print(maxMin)
'''
'''
t = int(input())

for t in range(t):
    nums = list(map(int, input().split()))
    k = nums[-1]
    nums.pop(-1)
    minAdj = max(nums) - (sum(nums) - max(nums)) - 1
    maxAdj = 0
    for num in nums:
        maxAdj += num - 1
    if(k >= minAdj and k <= maxAdj):
        print("YES")
    else:
        print("NO")
'''
'''
t = int(input())

for t in range(t):
    x = int(input())
    line = input()
    segments = list(line.split("W"))
    yes = True
    for segment in segments:
        if(len(segment) == 0):
            continue
        if(len(set(segment)) == 1):
           yes = False
    if(yes):
        print("YES")
    else:
        print("NO")
'''
'''
t = int(input())

for t in range(t):
    x = int(input())
    nums = list(map(int, input().split()))
    new = []
    for i in range(0, x, 2):
        new.append(nums[i :i+2])
    minNum = 0
    yes = True
    for seg in new:
        if min(seg) < minNum:
            yes = False
        else:
            minNum = max(seg)
    if yes:
        print("YES")
    else:
        print("NO")
'''
'''
t = int(input())

for t in range(t):
    y, x = map(int, input().split())
    grid = []
    for i in range(y):
        grid.append([i for i in input()])
    moved = True
    while(moved):
        moved = False
        for i in range(1, y):
            for j in range(x):
                if(grid[i][j] == '.' and grid[i-1][j] == '*'):
                    grid[i-1][j] = '.'
                    grid[i][j] = '*'
                    moved = True
    for line in grid:
        string = ""
        for char in line:
            string += char
        print(string)
'''
'''
t = int(input())

for t in range(t):
    n, x = map(int, input().split())
    costs = list(map(int, input().split()))
    costs.sort()
    removeList = []
    for cost in costs:
        if cost > x:
            removeList.append(cost)
    for cost in removeList:
        costs.remove(cost)
    total = sum(costs)
    ans = 0
    while(costs):
        
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    n, m = map(int, input().split())
    words = []
    for i in range(n):
        words.append(input())

    ans = 10**10
    for i in range(n-1):
        for j in range(i+1, n):
            a = words[i]
            b = words[j]
            total = 0
            for k in range(m):
                total += abs(ord(a[k]) - ord(b[k]))
            if(total < ans):
                ans = total
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    n, m = map(int, input().split())
    board = []
    ans = 0
    for i in range(n):
        board.append(list(map(int, input().split())))
    for i in range(n):
        for j in range(m):
            total = board[i][j]
            x = i
            y = j
            while(x > 0 and y > 0):
                x -= 1
                y -= 1
                total += board[x][y]
            x = i
            y = j
            while(x < n-1 and y < m-1):
                x += 1
                y += 1
                total += board[x][y]
            x = i
            y = j
            while(x > 0 and y < m-1):
                x -= 1
                y += 1
                total += board[x][y]
            x = i
            y = j
            while(x < n-1 and y > 0):
                x += 1
                y -= 1
                total += board[x][y]
            if(total > ans):
                ans = total
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    n, q = map(int, input().split())
    candies = sorted(list(map(int, input().split())), reverse = True)
    sums = [0] * n
    sums[0] = candies[0]
    for i in range(1, n):
        sums[i] = sums[i-1] + candies[i]
    for i in range(q):
        goal = int(input())
        ans = 0
        low = 0
        mid = n//2
        high = n-1
        if(sums[-1] < goal):
                ans = -1
                print(ans)
                continue
        if(sums[0] >= goal):
                ans = 1
                print(ans)
                continue
        for j in range(round(math.log2(n)) + 1):
            if(sums[mid] > goal):
                ans = sums[mid]
                high = mid - 1
            if(sums[mid] < goal):
                low = mid + 1
            else:
                ans = sums[mid]
            mid = (low + high)//2
        ans = sums.index(ans) + 1
        print(ans)
'''
'''
n, t = map(int, input().split())

books = list(map(int, input().split()))
ans = 0
start = 0
end = 0

total = books[0]

if(sum(books) <= t):
    print(n)
else:
    for i in range(n):
        start = i
        if(start):
            total -= books[start-1]
        while(total <= t):
            end += 1
            if(end == n + 1):
                break
            total += books[end%n]
        if(end == n + 1): break
        if(end - start > ans):
                ans = end - start

    print(ans)
'''
'''
n, x = map(int, input().split())

nums = list(map(int, input(.split()))
nums.sort()
total = 0
index = 0
if(sum(nums) <= x):
    print(n)
else:
    while(total + nums[index] <= x):
        total += nums[index]
        index += 1
    print(index)
'''
'''
n, k = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
if(n == 1):
    print(nums[0] + k)
else:
    top = nums[math.ceil(n/2)-1:]
    count = 1
    median = top[0]
    while(True):
        if(count >= len(top)):
            median += k // count
            break
        elif((top[count] - median) * count <= k):
            k -= (top[count] - median) * count
            median += top[count] - median
            count += 1
        else:
            median += k // count
            break
        
    print(median)
'''
'''
n, m = map(int, input().split())
a = [0] * (n+1)
b = [0] * (n+1)
cons = [[] for i in range(n+1)]
yes = True

def dfs(x, num, visited):
    global yes
    global cons
    global a
    global b
    visited.add(x)
    if(num % 2 == 1 and b[x] != 0):
        yes = False
    if(num % 2 == 0 and a[x] != 0):
        yes = False
    if(num % 2 == 1):
        a[x] = x
        b[x] = 0
    else:
        b[x] = x
        a[x] = 0
    for next in cons[x]:
        if next not in visited:
            dfs(next, num + 1, visited)

for i in range(m):
    con = list(map(int, input().split()))
    cons[con[0]].append(con[1])
    cons[con[1]].append(con[0])

for i in range(1, n+1):
    if(b[i] != 0):
        dfs(i, 2, set())
    else:
        dfs(i, 1, set())

if(yes):
    ans = ""

    for num in a[1:]:
        if(num > 0):
            ans += "1 "
        else:
            ans += "2 "

    print(ans[:-1])
else:
    print("IMPOSSIBLE")
'''
'''
n, m = map(int, input().split())
grid = []
for i in range(n):
    grid.append([char for char in input()])

def ff(y, x):
    global grid
    global n
    global m
    grid[y][x] = '#'
    if(y - 1 >= 0 and grid[y-1][x] == "."):
        ff(y-1, x)
    if(y + 1 < n and grid[y+1][x] == "."):
        ff(y+1, x)
    if(x - 1 >= 0 and grid[y][x-1] == "."):
        ff(y, x-1)
    if(x + 1 < m and grid[y][x+1] == "."):
        ff(y, x+1)

ans = 0

for i in range(n):
    for j in range(m):
        if(grid[i][j] == "."):
            ff(i, j)
            ans += 1

print(ans)
'''
'''
n = int(input())
subs = list(map(int, input().split()))
cons = [[] for i in range(n+1)]
total = 0

def search(x):
    global total
    global cons
    total += 1
    for next in cons[x]:
        search(next)

for i in range(n-1):
    cons[subs[i]].append(i+2)

ans = ""

for i in range(1, n+1):
    total = -1
    search(i)
    ans += str(total) + " "
    
print(ans[:-1])
'''
'''
t = int(input())

for t in range(t):
    n = int(input())
    s = input()
    ans = 0
    for i in range(n):
        newS = s[:i] + s[i+1:]
        if newS == newS[::-1]:
            ans += 1
    print(ans)
'''
'''
t = int(input())

for t in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    nums1 = nums
    nums1.sort()
    sorts = []
    for i in range(n):
        if(nums[i] != nums1[i]):
            sorts.append(nums[i], nums1.index(nums[i]))
    print(sorts)
    ans = 0
    for X in range(0, nums1[-1] - 1):
        yes = True
        for sort in sorts:
            if(sort[0] & nums[sort[1]] != X):
                yes = False
                break
        if(yes):
            ans = X
    print(ans)
'''
t = int(input())

for t in range(t):
    n = int(input())
    nums = list(map(int, input().split()))
    a = 0
    b = 1
    ans = [0] * n
    if(n == 1 or nums[-1] != nums[-2]):
        ans = -1
    else:
        while(b != n):
            if(b == a+1 and nums[b] != nums[a]):
                ans = -1
                break
            elif(nums[b] != nums[a]):
                ans[a] = b
                for i in range(a+1, b):
                    ans[i] = i
                a = b
            elif(b == n-1):
                ans[a] = b+1
                for i in range(a+1, n):
                    ans[i] = i
            b += 1
    if(ans == -1):
        print(ans)
    else:
        print(' '.join([str(num) for num in ans]))
