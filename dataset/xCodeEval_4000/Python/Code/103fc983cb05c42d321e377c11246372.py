import math
"""def maxOccurences(numbers):
    i=1
    alice = 1
    bob = 0
    while i<len(numbers)-1:
        
        if numbers[i] == numbers[i-1] and alice == 1:
            numbers.pop(i-1)
            numbers.pop(i)
            bob = 1
            alice =0

        elif numbers[i] == numbers[i-1] and bob == 1:
            numbers.pop(i-1)
            number.pop(i)
            bob = 0
            alice=1
            
        i+=1
        
    if bob==0:
        print("Bob")
    else:
        print("Alice")
a = maxOccurences([1,3,3,1,5])
print(a)"""
"""n = int(input())
x = list(map(int,input().split()))
y = list(map(int,input().split()))
myMap = dict()
for i in range(len(x)):
    if myMap.get(x[i])== None:
        myMap[x[i]]=1
for i in range(len(y)):
    if myMap.get(y[i]) == None:
        myMap[y[i]]=1
print(myMap)
if len(myMap)==n:
    print("I become the guy.")
else:
    print("Oh, my keyboard!")"""

"""testcases = int(input())
while testcases > 0:
    a,b,k = map(int,input().split())
    aFactor = math.ceil(k/2)
    bFactor = math.floor(k/2)
    pos = a*aFactor - b*bFactor
    print(pos)
    testcases-=1"""
"""n = int(input())
if n==1:
    print(-1)
else:
    i=1
    while i<=n:
        print(str(i+1)+ " " + str(i), end=" ")
        i+=2"""
"""testcases = int(input())
while testcases > 0:
    n = int(input())
    myArray = list(map(int,input().split()))
    myMap = dict()
    for i in range(len(myArray)):
        if myMap.get(myArray[i]) == None:
            myMap[myArray[i]]=1
        else:
            myMap[myArray[i]]+=1
    if len(myMap)==1:
        print(n)
    elif len(myMap)==n:
        print(1)
    else:
        a = max(myMap, key=myMap.get)
        print(myMap[a])
    testcases-=1"""

"""testcases = int(input())
while testcases > 0:
    myString = input()
    myMap = dict()
    for i in range(len(myString)):
        if myString[i]=="1":
            if myMap.get(myString[i])== None:
                myMap[myString[i]]=1
            else:
                myMap[myString[i]]+=1
    flag=0
    i=0
    zeroCount=0
    oneCount=0
    while i<len(myString):
        if myString[i]=="1":
            if flag!=1:
                flag=1
            while i<len(myString) and myString[i]=="1":
                oneCount+=1
                i+=1
        if flag==1:
            if oneCount == myMap["1"]:
                break
            else:
                zeroCount+=1
        i+=1
    print(zeroCount)
    testcases-=1"""

"""testcases = int(input())
while testcases > 0:
    n,m = map(int,input().split())
    myArray=[]
    for i in range(n):
        myString = input()
        myArray.append(myString)
    i=0
    j=m-1
    count=0
    while i<n-1:
        if myArray[i][j]=="R":
            count+=1
        i+=1
    i=n-1
    j=0
    while j<m-1:
        if myArray[i][j]=="D":
            count+=1
        j+=1
    print(count)
    testcases-=1"""

"""testcases = int(input())
while testcases > 0:
    x,y = map(int,input().split())
    myString = input()
    myMap=dict()
    flag1=0
    flag2=0
    for i in range(len(myString)):
        if myMap.get(myString[i])==None:
            myMap[myString[i]]=1
        else:
            myMap[myString[i]]+=1
    if x>0:
        if myMap.get('R')!=None:
            if myMap['R']>=x:
                flag1=1
    elif x<0:
        if myMap.get('L')!=None:
            if myMap['L']>=abs(x):
                flag1=1
    else:
        flag1=1
    if y>0:
        if myMap.get('U')!=None:
            if myMap['U']>=y:
                flag2=1
    elif y<0:
        if myMap.get('D')!=None:
            if myMap['D']>=abs(y):
                flag2=1
    else:
        flag2=1
    if flag1 and flag2:
        print("YES")
    else:
        print("NO")
    testcases-=1"""

"""length = int(input())
myString = input()

finalString = ""
i=0
j=1
while i<len(myString):
    finalString+=myString[i]
    i = i + j
    j = j + 1
print(finalString)"""

"""a = int(input())
b= a
while True:
    c = b
    c = str(c)
    total= 0
    for i in range(len(c)):
        total += int(c[i])
    if total%4==0:
        print(b)
        break
    else:
        b+=1"""
"""n=int(input())
myArray = list(map(int,input().split()))
myMap=dict()
for i in range(len(myArray)):
    if myMap.get(myArray[i])==None:
        myMap[myArray[i]]=1
    else:
        myMap[myArray[i]]+=1
a = max(myMap , key=myMap.get)
print(myMap[a])"""

"""testcases = int(input())
while testcases > 0:
    cost = 0
    n , c0 , c1 , h = map(int,input().split())
    myString = input()
    myMap= dict()
    for i in range(len(myString)):
        if myMap.get(myString[i])==None:
            myMap[myString[i]] = 1
        else:
            myMap[myString[i]] += 1
    if myMap.get('0')!=None and myMap.get('1') !=None:
        if c0*myMap['0'] < c1*myMap['1']:
            if h+c0 < c1:
                cost = c0*myMap['0'] + h*myMap['1'] + c0*myMap['1']
            else:
                cost = c0*myMap['0'] + c1*myMap['1']
        elif c0*myMap['0'] > c1*myMap['1']:
            if h+c1 < c0:
                cost = c1*myMap['1'] + h*myMap['0'] + c1*myMap['0']
            else:
                cost = c0*myMap['0'] + c1*myMap['1']
        else:
            cost = c0*myMap['0'] + c1*myMap['1']
    elif myMap.get('0') == None and myMap['1']!=None:
        if c0+h < c1:
            cost = c0*myMap['1'] + myMap['1']*h
        else:
            cost = c1*myMap['1']
    elif myMap.get('1')==None and myMap['0']!=None:
        if c1+h < c0:
            cost = h*myMap['0'] + c1*myMap['0']
        else:
            cost = c0*myMap['0']
    print(cost)
    testcases-=1"""

"""n,k = map(int,input().split())
myArray = list(map(int, input().split()))
maxNo = -1
count=0
for i in range(len(myArray)):
    maxNo = max(maxNo , myArray[i])
if maxNo <= k:
    print(len(myArray))
else:
    i=0
    j=len(myArray)-1
    while i<=j:
        if myArray[i] <= k:
            i+=1
            count+=1
        elif myArray[j] <= k:
            j-=1
            count+=1
        else:
            break
    print(count)"""

"""n = int(input())
myMap = dict()
myArray = list(map(int,input().split()))
for i in range(len(myArray)):
    if myMap.get(myArray[i])==None:
        myMap[myArray[i]]=1
    else:
        myMap[myArray[i]]+=1
i=0
while i<len(myArray):
    if myMap[myArray[i]] > 1:
        myMap[myArray[i]]-=1
        myArray.pop(i)
    else:
        i+=1
print(len(myArray))
for i in range(len(myArray)):
    print(myArray[i], end=" ")"""

"""sticks, k = map(int,input().split())
a = int(sticks/k)

if a%2==0:
    print("NO")
else:
    print("YES")"""

"""testcases = int(input())
while testcases > 0:
    n,m = map(int,input().split())
    myArray = list(map(int,input().split()))
    total = 0
    flag=0
    for i in range(1,len(myArray)):
        total+=myArray[i]
    if total > m-myArray[0]:
        print(m)
    else:
        print(total+myArray[0])
    testcases-=1"""

"""testcases = int(input())
while testcases>0:
    n = int(input())
    myString = input()
    length = 0
    i=len(myString)-1
    while i>=0:
        if myString[i]==")":
            length+=1
            i-=1
        else:
            break
    d = n-length
    if d>=length:
        print("NO")
    else:
        print("YES")
    testcases-=1"""

"""testcases = int(input())
while testcases > 0:
    n,k = map(int,input().split())
    myArray = list(map(int,input().split()))
    maxElement = max(myArray)
    myList1=[]
    myList2=[]
        
    for i in range(len(myArray)):
        myArray[i]=maxElement-myArray[i]
        myList1.append(myArray[i])
    maxElement = max(myArray)
    for i in range(len(myArray)):
        myArray[i] = maxElement - myArray[i]
        myList2.append(myArray[i])
    if k%2!=0:
        for i in range(len(myList1)):
            if i!=len(myList1)-1:
                print(myList1[i],end=" ")
            else:
                print(myList1[i])
    else:
        for i in range(len(myList2)):
            if i!=len(myList2)-1:
                print(myList2[i], end=" ")
            else:
                print(myList2[i])
    testcases-=1"""

"""x,y,z = map(int,input().split())
myArray = list(map(int,input().split()))

if myArray[0] < x:
    print("NO")
else:
    flag=0
    myArray[0]-=x
    total2=0
    total2 = myArray[0]+myArray[1]
    if total2 >=y:
        total2-=y
        if total2+myArray[2]>=z:
            flag=1
        else:
            flag=0
    else:
        flag=0
    if flag==1:
        print("YES")
    else:
        print("NO")"""
"""testcases = int(input())
while testcases>0:
    minValue= 10000000000
    n,m = map(int,input().split())
    if n>m:
        i=1
        while i<=n:
            minValue = min(minValue, (n^i)+(m^i))
            i+=1
    elif n<=m:
        i=1
        while i<=m:
            minValue = min(minValue, (n^i)+(m^i))
            i+=1
    print(minValue)
    testcases-=1"""

"""testcases = int(input())
while testcases > 0:
    myString1 = input()
    myString2 = input()
    myString3 = input()
    flag=0
    for i in range(len(myString1)):
        if myString3[i]!=myString2[i] and myString3[i]!=myString1[i]:
            flag=1
            break
    if flag==1:
        print("NO")
    else:
        print("YES")
    testcases-=1"""

"""s, v1, v2, t1, t2 = map(int,input().split())
if t2*2 + v2*s < t1*2 +v1*s:
    print("Second")
elif t2*2 + v2*s > t1*2 +v1*s:
    print("First")
else:
    print("Friendship")"""

"""testcases = int(input())
while testcases > 0:
    n=int(input())
    if n==1:
        print(0)
    else:
        moves=0
        flag=0
        while n!=1:
            a=n
            b=n
            c=n
            if n%2!=0 and n%3!=0 and n%5!=0:
                flag=1
                break
            else:
                if n%2==0:
                    a=a/2
                if n%3==0:
                    b = (b*2)/3
                if n%5==0:
                    c=(4*n)/5
            n = min(min(a,b),c)
            moves+=1
        if flag==1:
            print(-1)
        else:
            print(moves)
    testcases-=1
    myString.upper()
    myString.isupper()"""

"""myString1= input()
myString2 = input()
myText = input()
myText = list(myText)
newText = ""
myMap = dict()
for i in range(len(myString1)):
    myMap[myString1[i]]=i

for i in range(len(myText)):
    if myText[i]=="0" or myText[i]=="1" or myText[i]=="2"  or myText[i]=="3" or myText[i]=="4" or myText[i]=="5" or myText[i]=="6" or myText[i]=="7" or myText[i]=="8" or myText[i]=="9":
        newText += myText[i]    
    else:
        if myText[i].isupper() == True:
            myText[i]=myText[i].lower()
            newText += myString2[myMap[myText[i]]].upper()
        else:
            newText += myString2[myMap[myText[i]]]
print(newText)"""

"""l,r,d = map(int,input().split())
teamSize = 0
if l<r:
    if l+d==r:
        teamSize = l+r+d
    elif l+d < r:
        teamSize = 2*(l+d)
    else:
        diff = r-l
        l+=diff
        d-=diff
        teamSize = l+r+2*int(d/2)
elif r<l:
    if r+d==l:
        teamSize = l+r+d
    elif r+d < l:
        teamSize = 2*(r+d)
    else:
        diff = l-r
        r+=diff
        d-=diff
        teamSize = l+r+2*int(d/2)
else:
    teamSize = l+r+2*int(d/2)
print(teamSize)"""

"""n = int(input())
myArray = list(map(int,input().split()))
myMap = dict()
for i in range(len(myArray)):
    myMap[myArray[i]]=i

maxElement = max(myArray)
minElement = min(myArray)

if myArray[0]==maxElement and myArray[n-1]==minElement or myArray[0]==minElement or myArray[n-1]==maxElement:
    print(n-1)
else:
    if myMap[maxElement] < myMap[minElement]:
        dist =  max(abs(0-myMap[minElement]),abs(n-1-myMap[maxElement]))
    else:

        dist = max(abs(0-myMap[maxElement]), abs(n-1-myMap[minElement]))
    print(dist)"""

"""n = int(input())
myArray = list(map(int,input().split()))
myMap = dict()
myMap[myArray[0]]=1
length = 1
for i in range(1,len(myArray)):
    if myMap.get(myArray[i])==None:
        myMap[myArray[i]]=1
        length = max(length , len(myMap))
    else:
        del myMap[myArray[i]]
print(length)"""

"""n = int(input())
myMap = dict()
while n>0:
    name = input()
    if myMap.get(name)==None:
        print("NO")
        myMap[name]=1
    else:
        print("YES")
    n-=1"""

testcases = int(input())
while testcases > 0:
    n,k = map(int,input().split())
    myArray = list(map(int,input().split()))
    myMap = dict()
    maxValue = myArray[0]
    minValue = myArray[0]
    mexValue=-1
    for i in range(len(myArray)):
        myMap[myArray[i]]=1
        if i!=0:
            if maxValue < myArray[i]:
                maxValue = myArray[i]
            if minValue > myArray[i]:
                minValue = myArray[i]
                
    if minValue!=0:
        mexValue=0
    else:
        while True:
            mexValue+=1
            if myMap.get(mexValue)==None:
                break
    if mexValue > maxValue:
        print(len(myMap)+k)
    else:
        while k>0:
            value = int(math.ceil((mexValue+maxValue)/2))
            if myMap.get(value)==None:
                myMap[value]=1
            else:
                myMap[value]+=1
                break
            myArray.append(value)
            k-=1
        print(len(myMap))
    testcases-=1


    

        
    


    

            
            
    


   






    
