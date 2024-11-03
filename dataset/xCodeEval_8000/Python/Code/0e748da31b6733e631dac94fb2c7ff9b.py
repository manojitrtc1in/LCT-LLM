'''value = 0
def Ordervalue(n):
    value = 0
    for i in n:
        value += ord(i)
    print(value)'''
from typing import List

'''s = input("Enter word")
t = int(len(s) - 2)
if len(s)<= 10 :
    print(s)
elif len(s) > 10:
    print(s[0] + str(t) + s[len(s)-1])'''
'''n = int(input())

for i in range(0,n):
    s = str(input())
    t = int(len(s) - 2)
    if len(s) <= 10:
        print(s)
    else:
        print(s[0] + str(t) + s[len(s) - 1])'''

'''n = int(input())
count = 0
for i in range (0,n):
    x = input()
    if x.count('1') >= 2:
        count+=1
print(count)'''

'''n = int(input())
count = 0
for i in range(0,n):
    a = input()
    if a == "++X" or a == "X++":
        count +=1
    elif a == "--X" or a == "X--":
        count = count-1
    else:
        count += 0
print(count)'''

'''n = int(input())
count = 0
for i in range(0, n):
    a = input()
    if "++" in a:
        count += 1
    else:
        count -= 1
print(count)'''

'''m = str(input()).lower()
n = str(input()).lower()

if m==n :
    print(0)
elif m > n :
    print (1)
else:
    print(-1)'''

'''n = str(input())
print(n[0].upper() + n[1:len(n)])'''

'''
n=str(input())
s = set(n)

if len(s)%2 == 0:
    print("CHAT WITH HER!")
else:
    print("IGNORE HIM!")
'''


'''n = int(input())
count = 0
string = str(input())
for i in range(0,n-1):
    if string[i]==string[i+1] :
        count+=1
    else:
        continue
print(count)'''


'''n = int(input())
if n%5 == 0:
    print(n//5)
else:
    print(n // 5 + 1)'''

'''n = str(input())
uppercase = 0
lowercase = 0

for i in range(0, len(n)):
    if n[i].isupper():
        uppercase+=1
    elif n[i].islower():
        lowercase+=1

if uppercase > lowercase:
    print(n.upper())
else:
    print(n.lower())'''


'''n = str(input())
q = "0000000"
p = "1111111"
if q in n or p in n:
    print("YES")
else:
    print("NO")'''
'''
n = str(input())
if "0" in n or "1" in n or "2" in n or "3" in n or "5" in n or "6" in n or "8" in n or "9" in n :
    print("NO")
elif len(n)==1 or len(n)==2 or len(n)==3 or len(n)==5 or len(n)==6 or len(n)==8 or len(n)==9:
    print("NO")
else:
    print("YES")

'''

'''n = str(input())
count = 0
for i in range(0, len(n)):
    if n[i] == "4" or n[i] == "7" :
        count+=1

if count == 4 or count == 7 :
    print("YES")
else:
    print("NO")'''
'''
r =int(input())
n = str(input())
if n.count("A") > n.count("D"):
    print("Anton")
elif n.count("A") == n.count("D"):
    print("Friendship")
else:
    print("Danik")
'''

'''
n = int(input())
count = 0
p = []
for i in range(1, n+1):
    p.append(input())
    if i >1:
        if p[i-1] != p[i-2]:
            count+=1
print(count+1)
'''

'''
n = str(input())
m = str(input())
result = []

for i in range (0, len(n)):
    if n[i]==m[i]:
        result.append("0")
    else:
        result.append("1")
for i in result:
    print(i,end="")
'''



'''n = int(input())

for i in range(0,n-1):
    if i%2 == 0:
        print("I hate that",end=" ")
    else:
        print("I love that",end=" ")
if n%2 == 1:
    print("I hate it")
else:
    print("I love it")'''


'''n = int(input())
result = 0
for i in range(0,n):
    if (i+1)%2 == 0:
        result+=i+1
    else:
        result = result-(i+1)

print(result)'''


'''
n = int(input())

if n%2==0:
    print(n//2)
else:
    print(-n//2 )
'''

'''k = int(input())
l = int(input())
m = int(input())
n = int(input())
d = int(input())
unhealthy = 0
for i in range(1,d+1):
    if i%k == 0 or i%l == 0 or i%m == 0 or i%n == 0:
        unhealthy+=1
print(unhealthy)'''

'''a = input()
a = a.strip(',')
b = list(a)
b.sort()
c=0
for i in range (0, len(b)):
    if (b[i]!=' ' and b[i]!='{'and b[i]!=','and b[i]!='}'):
        if b[i] != b[i-1]:
            c+=1
print(c)'''


'''n=int(input())
s = str(input()).lower()
alphabet='abcdefghijklmnopqrstuvwxyz'

if len(set(alphabet) - set(s)) == 0:
    print("YES")
else:
    print("NO")'''


'''n = int(input())

print((n//100) + (n%100//20) + (n%20%100//10) + (n%10%20%100//5) + (n%5%10%20%100))'''



'''n = int(input())
p = str(input())
if "1" in p:
    print("HARD")
else:
    print("EASY")'''



'''n = int(input()) +1
while len(set(str(n))) < 4:
    n+=1
print(n)'''

'''n = int(input())
p=[]
count = 0
for i in range(0,n):
    p.append(input())
    if p[i] == "Tetrahedron":
        count+=4
    elif p[i] == "Cube":
        count+=6
    elif p[i] == "Octahedron":
        count+=8
    elif p[i] == "Dodecahedron":
        count+=12
    elif p[i] == "Icosahedron":
        count+=20

print(count)'''




'''n,k = map(int,input().split())
l = map(int, input().split())
count = 0
L = list(l)
cut = L[k-1]
for i in range(0,len(L)):
    if L[i] >= cut and L[i]>0:
        count+=1
print(count)'''


'''
m,n = map(int,input().split())
print(int(m*n/2))
'''

'''
n= input().split('+')
n.sort()
print( '+'.join(n))'''


'''
Limik , Bob = map(int, input().split())

count = 0
while Limik <= Bob:
    Limik*=3
    Bob*=2
    count+=1
print(count)

'''


'''k,n,w = map(int,input().split())
count = 0
for i in range(0,w):
    count+=k*(i+1)

if count - n <= 0:
    print("0")
else:
    print(count - n)
'''



'''n,k = map(int, input().split())
for i in range(0,k):
    if n%10 == 0:
        n=n/10
    else:
        n = n - 1
print(int(n))
'''

'''
n = str(input())
m = str(input())
count = 0
for i in range(0,len(m)):
    if len(n) != len(m):
        count=0
        break
    elif n[i] == m[len(m)-i-1]:
        count+=1

if count == len(m):
    print("YES")
else:
    print("NO")
'''

'''
n = int(input())
count = 0
for i in range(0, n):
    p , q = map(int,input().split())
    if p+1 >= q :
        count+=0
    else:
        count+=1
print(count)'''

'''
n = int(input())
count = 0
l = list(map(int, input().split()))

for i in range(0,n):
    count+=l[i]
print(count/n)
'''
'''
n = int(input())

for i in range(0,n):
    k,l= map(int,input().split())
    if k %l == 0:
        print("0")
    elif k < l :
        print(l-k)
    else:
        print(l - (k%l))
'''
'''
h,k = map(int, input().split())

for i in range(0,h):
    if (i+1)%4 == 1 or (i+1)%4 == 3:
        print('
    elif (i+1)%4 == 2:
        print('.'*(k-1)+'
    else:
        print('
'''


'''
n,k = map(int, input().split())

count = 240-k
question = 0
for i in range (0,n):
    if count >= 5*i + 5:
        count-=5*i + 5
        question+=1
print(question)
'''

'''
n = int(input())
t = list(map(int, input().split()))
h = ut = 0
for i in t:
    if i > 0:
        h+=i
    elif h > 0 and i < 0:
        h-=1
    else:
        ut+=1

print(ut)
'''

'''
b , r = map(int,input().split())
diff = 0
sum = b+r
while b>0 and r > 0:
    b-=1
    r-=1
    diff+=1

same = str(int((sum)/2 - diff))
diff = str(diff)
print( diff +" "+same )
'''



'''
t= int(input())

for i in range(0,t):
    nu = int(input())
    list = []
    pa = 1
    while nu > 0:
        remainder = nu%10
        nu = nu//10
        if remainder >0:
            list.append(remainder*pa)
        pa = pa*10
    print(len(list))
    for i in list:
        print(i , end=" ",)
    print("")
'''


'''
n,k = map(int,input().split())
count = 0
for i in range(1,11):
    if (i*n)%10 in [0,k]:
        print(i)
        break
'''

'''
n = int(input())

for i in range (0,n):
    m = int(input())
    l = list(map(int,input().split()))
    count = 0
    l.sort()
    s= sum(l)
    if len(l)==1:
        print("YES")
        continue
    for i in range(1, m):
        if l[i] - l[i - 1] <= 1:
            s -= l[i - 1]
            l[i - 1] = 0
    if l[i] == s:
        print("YES")
    else:
        print("NO")

'''

'''
w,x,y,z = map(int,input().split())
l = [w,x,y,z]
l.sort()
t = l[-1]
print(l[-1] - l[-2] , l[-1] - l[-3], l[-1] - l[-4] )
'''





'''
n = int(input())

while n >0:
    a,b = map(int,input().split())
    print((abs(a-b)+9)//10 )
    n-=1
'''

'''
i,j,k = map(int,input().split())
print(max(i,j,k) - min(i,j,k))
'''

'''
n = int(input())

def composite(n):
    for i in range(0,n-2):
        if n%(i+2) == 0:
            return True
    return False

for i in range(n-2):
    x = i+2
    y = n-x
    if composite(x) and composite(y):
        print("{} {}".format(x, y))
        break
'''

'''
n=int(input())


for i in range(0,n):
    t =str(input())
    l=[t[0]]
    for i in range(1,len(t)):
        if i%2 == 1:
            l.append(t[i])

    for i in l:
        print(i,end="")
    print("")
'''

'''
n, k, l, c, d, p, nl, np = map(int,input().split())
print(int((min(k*l//nl , c*d , p/np))//n))
'''
'''
n = int(input())

for i in range(0,n):
    p= int(input())
    a = list(map(int,input().split()))
    m = a[0]
    for j, num in enumerate(a):
        a[j] -= m
    for k in a:
        if a[1] != 0 and a[1] == a[2]:
            print(1)
            break
        if k != 0:
            print(a.index(k) + 1)
            break
'''


'''
n = int(input())

for i in range(0,n):
    l,m,n = map(int,input().split())
    o = n%l
    if m < o:
        print(n-o+m)
    elif m == o:
        print(n)
    elif m > o:
        print(n-o+m-l)
'''


'''
n, m ,a = map(int,input().split())

if n % a == 0:
    n = n//a
else:
    n = (n//a +1)

if m % a == 0:
    m = m//a
else:
    m = (m//a +1)

print(n*m)
'''

'''
word = str(input()).lower()

for i in word:
    if i != "a" and i !="e" and i !="i" and i !="o" and i !="u" and i!="y":
        print("." + i , end="")
'''

'''
n = int(input())
x=0
y=0
z=0
for i in range(0,n):
    l = list(map(int,input().split()))
    x+=l[0]
    y+=l[1]
    z+=l[2]

if x==0 and y == 0 and z==0:
    print("YES")
else:
    print("NO")
'''


'''
m = "hello"
s = input()
x = 0
for i in range(0,len(s)):
    if s[i] == m[x]:
        x+=1
        if x==5:
            print("YES")
            exit()
    else:
        print("NO")
'''


'''
s = input()
m = "hello" + "?"*(len(s)-5)

x = 0
for i in range(0,len(s)):
    if s[i] == m[x]:
        x+=1
if x==5:
    print("YES")
else:
    print("NO")
'''

'''
n = (input())
count = 0

s=list(n)
for i in range(len(s)):
    if s[i] == "4" or s[i] == "7":
        count +=1
n = int(n)
l = [4,7,47,74,447,474,774,747,477,744]
d = 0
for i in range(len(l)):
    if n > l[i]:
        if n%l[i]==0:
            d+=1

if d > 0 or count == len(s):
    print("YES")
else:
    print("NO")
'''




'''
n = int(input())
l = list(map(int,input().split()))
s = sum(l)/2
value=0
coin =0
for i  in reversed(sorted(l)):
    value+=i
    coin+=1
    if value > s:
        break
print(coin)

'''
'''
n ,k = map(int,(input().split()))
odd =[]
even =[]
for i in range(1,n+1):
    if i%2 == 1:
        odd.append(i)
    else:
        even.append(i)
numbers = list(odd + even)
print(numbers[k-1])
'''
'''
n, k = list(map(int, input().split()))
print((k - (n + 1) // 2) * 2 if k > (n + 1) // 2 else k * 2 - 1)
'''


'''
n = int(input())
l=list(map(int,input().split()))
count = 1
m = 1
for i in range(1,n):
    if l[i] >= l[i-1]:
        count+=1
    else:
        m = max(m,count)
        count=1
m =  max(m,count)
print(m)
'''

'''
n = int(input())
l = list(map(int,input().split()))
count = 0
for i in l:
    if 4-i in l:
        count+=1
        l.remove(4-i)
    else:
        count+=1
print(count)

'''


'''
n = int(input())
l = list(map(int,input().split()))

ones = l.count(1)
twos = l.count(2)
threes= l.count(3)
fours=l.count(4)
cars = 0


if threes < ones:
    ones -= threes
    if twos%2 !=0 :
        ones -=2
        if ones > 0:
            if ones % 4 == 0:
                cars += ones // 4
            else:
                cars += ones // 4 + 1
    elif twos == 0 or twos%2 == 0:
        if ones > 0:
            if ones % 4 == 0:
                cars += ones // 4
            else:
                cars += ones // 4 + 1
cars += fours
cars += threes
if twos%2 == 0:
    cars+=twos//2
else:
    cars+=twos//2 + 1

print(cars)
'''


'''
n = int(input())

l = list(map(int,input().split()))

l.sort()
for i in l:
    print(i ,end=" ")
'''

'''
a = int(input())
b = int(input())
c = int(input())

p = a +b*c
q = a*b + a*c
r = a*b*c
s = a*c + c*b
t = a+b+c
u = a*b + c
print(max(p,q,r,s,t,u))
'''

'''
n =int(input())
l = list(map(int,input().split()))

even= []
odd =[]

for i in l:
    if i%2 == 0:
        even.append(i)
    else:
        odd.append(i)

if len(even) == 1:
   print((l.index(even[0]))+1)
else:
    print((l.index(odd[0]))+1)
'''
'''
import re

print(( re.sub('WUB', ' ', input())))
'''

'''
n =int(input())
d={}
for i in range(0,n):
    s=str(input())
    if s in d:
        print(s+str(d[s]))
        d[s]+=1
    else:
        print("OK")
        d[s] =1

print(d)
'''

'''
n,m = map(int,input().split())
count = 0

while n >0 and m>0:
    n-=1
    m-=1
    count+=1

if count%2 == 1:
    print("Akshat")
else:
    print("Malvika")
'''
'''
n = int(input())

for i in range(0,n):
    d = int(input())
    if d > 1:
        print((d+1)//2 - 1)
    else:
        print(0)
'''

'''
n,m=map(int,input().split())
l = list(map(int,input().split()))
c = l[0] - 1
for i in range(1,m):
    if l[i] < l[i - 1]:
        c += (n - l[i - 1])
        c += l[i]
    else:
        c += l[i] - l[i - 1]
print(c)
'''

'''
n = (input())

if int(n) > 0:
    print(n)
else:
    print(max(map(int, (n[:-1], n[:-2] + n[-1]))))
'''

'''
l =[]
j=0
i=0
while j<=1000:
    if i%3 !=0 and (i%10 !=3) :
        l+=[i]
        j+=1
    i+=1

for _ in range(int(input())):
    n=int(input())
    print(l[n-1])
'''

'''
for _ in range (int(input())):
    matrix=[]
    s=input()
    for i in range (8):
        matrix.append(input())
    for j in range(1,7)   :
        if matrix[j].count("
                print(j + 1, (matrix[j].index("
'''

'''
for _ in range(int(input())):
    n,m = map(int,input().split())
    print(int(m*((m-1) + n*(n+1))//2))
'''

'''
for _ in range(int(input())):
    n,m = map(int,input().split())
    list = map(int,input().split())
    energy_req = sum(list)
    if energy_req - m > 0:
        print(energy_req - m)
    else:
        print(0)
'''


'''
n, q = map(int,input().split())
l = list(map(int, input().split()))
l.sort()
l.reverse()
r = [0]
for i in l:
    r.append(r[-1] + i)
for _ in range(q):
    x,y = map(int,input().split())
    print(r[x]-r[x-y])
'''

'''
t = int(input())

for _ in range(0,t):
    n,m = map(int , input().split())
    l = []
    for i in range(0,n):
        l.append(input().split())
'''
'''
for _ in range(int(input())):
    n,m = map(int,input().split())
    print(("01"*(min(n,m)) + ("0"*(max(0,n-m)) )+ ("1"*max(0,m-n))))
'''

'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    s = len(set(l))
    print(s - (s-n)%2)
'''
'''
for _ in range(int(input())):
    l = list(map(int,input().split()))
    count = 0
    for i in range(1,len(l)):
        if l[0] < l[i]:
            count+=1
    print(count)
'''

'''
for _ in range(int(input())):
    n = int(input())
    l =list(map(int,input().split()))
    count =0
    for i in l:
        if i%2 == 1:
            count+=1
    print(min(count , n-count))
'''
'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    for i in range(n):
        if b[i] == 
'''

'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    if sum(l)/n in l:
        print("YES")
    else:
        print("NO")
'''
'''
for _ in range(int(input())):
    a,b,c= map(int,input().split())
    print(a+b*c,b,c)
'''
'''
for _ in range(int(input())):
    s = input()
    if len(s)==2:
        print(s[-1])
    else:
        print(min(s))

'''

'''
for _ in range(int(input())):
    n,z = map(int,input().split())
    l =list(map(int,input().split()))
    p =[]
    for i in l:
        p.append(i|z)
    print(max(p))
'''
'''
for _ in range(int(input())):
    n = int(input())
    l = [0] + list(map(int,input().split()))
    num = 0
    for i in range(len(l)-1):
        if l[i] == 0 and l[i+1] != 0:
            num+=1
    print(min(num,2))
'''

'''
for _ in range(int(input())):
    n = int(input())
    a = 0
    b = 0
    c = 0
    if n == 6:
        a = 2
        b = 3
        c = 1
    elif n==7:
        a = 2
        b = 4
        c = 1
    elif n%3 ==0:
        a += n//3
        b += n//3 + 1
        c += n//3 - 1
    elif n%3 == 1:
        a += n // 3 + 1
        b += n // 3 + 2
        c += n // 3 - 2
    else:
        a += n // 3 + 1
        b += n // 3 + 2
        c += n // 3 - 1

    print(a,b,c)
'''

'''
for _ in range(int(input())):
    n =int(input())
    if n >= 1900:
        print("Division 1")
    elif 1900 > n > 1599:
        print("Division 2")
    elif 1600 > n > 1399:
        print("Division 3")
    else:
        print("Division 4")
'''

'''
for _ in range(int(input())):
    n = int(input())
    print(n-3,1,1,1)
'''
'''
for _ in range(int(input())):
    n = input()
    a =0
    b = 0
    for i in n:
        if i =='A': a+=1
        if i == 'B': b+=1
        if b > a:
            print('NO')
            break
    else:
        print("YES" if n[-1] =='B' else 'NO' )
'''

'''
for _ in range(int(input())):
    t = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    d = []
    for i in range(t):
        d.append(a[i]-b[i])
    m = max(d)

    if m < 0:
        print("NO")
        continue
    p =[]
    for i in range(t):
        p.append(max(0,a[i] - m))

    if p==b:
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    print(a[sum(b)%n])
'''
'''
for _ in range(int(input())):
    n = int(input())
    l =list(map(int,input().split()))
    if n==1:
        print(0)
    elif l.count(l[0]) == n :
        print(0)
    else:
        print(sum(l) - (n)*min(l) )
'''
'''
for _ in range(int(input())):
    a,b,c,x,y = map(int,input().split())
    z = max(x-a ,0) + max(y-b,0)
    if z <= c:
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    n = input()
    if (int(n[0]) + int(n[1]) + int(n[2])) == (int(n[3]) + int(n[4]) +int(n[5])):
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    x , y =map(int,input().split())
    if y%x == 0:
        print("1 " + str(y//x))
    else:
        print("0 0")
'''


'''
for _ in range(int(input())):
    n = input()
    x = ord(n[0]) - 97
    y = ord(n[1]) -96
    if y>x:
        y-=1
    print(x*25 +y)
'''

'''
for _ in range(int(input())):
    n = int(input())
    l =list(map(int,input().split()))
    a=b=0
    for i in range(2,len(l)):
        if l[i]%2 != l[i-2]%2:
            print("NO")
            break
    else:
        print("YES")
'''
'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    l.sort()
    for i in range(n-2):
        if l[i] == l[i+1] and l[i] == l[i+2]:
            print(l[i])
            break
    else:
        print("-1")
'''

'''
import re
for _ in range(int(input())):
    s = input()
    if re.fullmatch(r"((bbb)|(bb)|(aaa)|(aa))*",s):
        print("YES")
    else:
        print("NO")
'''
'''
for _ in range(int(input())):
    n,m = map(int,input().split())
    if n > m:
        n,m = m,n
    if n==1 and m > 2:
        print(-1)
    else:
        print(2*m - 2 - (n+m)%2 )
'''

'''
n = str(input())
if n.count('H') >=1 or n.count('Q') >=1 or n.count('9') >=1 :
    print("YES")
else:
    print("NO")
'''
'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    b = list(map(int,input().split()))
    sum = 0
    for i in range(len(a)-1):
        sum+=min((abs(a[i]-a[i+1]) + abs(b[i] - b[i+1])) ,( abs(a[i] - b[i+1]) + abs(b[i] - a[i+1])) )
    print(sum)
'''
'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    l.append(0)
    l.sort()
    if l[n] - l[n -1] > 1:
            print("NO")
    else:
        print("YES")
'''
'''
for i in range(int(input())):
    s=input()
    a=[]
    for i in range(len(s)):
        a.append(ord(s[i])-96)
    if len(s)%2==0:
        print('Alice', sum(a))
    elif len(s)==1:
        print('Bob', sum(a))
    else:
        print('Alice', max(sum(a)-a[len(a)-1]*2, sum(a)-a[0]*2))
'''
'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    if 0 in l:
        print(n-l.count(0))
    elif len(set(l)) < n:
        print(n )
    else:
        print(n + 1)
'''

'''
for _ in range(int(input())):
    n , m =map(int,input().split())
    s =[]
    z = 1000000000000
    for i in range(n):
        s.append(input())
    for j in range(len(s)):
        for k in range(j+1 , n):
            w = 0
            for c in range(m):
                w += abs(ord(s[j][c]) - ord(s[k][c]))
            if w < z: z = w
    print(z)
'''

'''
for _ in range(int(input())):
    n = int(input())
    s = input()
    c = 0
    for i in range(0,n ,2):
        if s[i] !=s[i+1]:
            c+=1
    print(c)
'''

'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    if (sum(l) -n)%2 == 1:
        print("errorgorn")
    else:
        print("maomao90")
'''

'''
for _ in range(int(input())):
    m , n = map(int,input().split())
    if m==0:
        print(1)
    else:
        print(m*1+n*2 +1)
'''
'''
for _ in range(int(input())):
    l1 , r1,l2,r2 = map(int,input().split())
    if min(r1,r2) >= max(l1,l2):
        print(max(l1,l2))
    else:
        print(l1+l2)
'''

'''
for _ in range(int(input())):
    n = int(input())
    s = list(map(int,input().split()))
    f = list(map(int,input().split()))
    d = [f[0] -s[0]]
    for i in range(1,n):
        if s[i] > f[i-1]:
            d.append(f[i] - s[i])
        else:
            d.append(f[i] -f[i-1])
    for i in d:
        print(i ,end=" ")
    print("")
'''

'''
for _ in range(int(input())):
    n = int(input())
    s = input()
    a = s[n // 2:]
    b = a[0]
    ans = 0
    for i in a:
        if i == b:
            ans += 2
        else:
            break
    ans -= n & 1
    print(ans)
'''

'''
for _ in range(int(input())):
    s = int(input())
    if s%2 == 1 or s==2 or s==0:
        print(-1)
    else:
        max = min =0
        if s%4 ==0:
            max+= s//4
        else:
            max+= s//4

        if s%6 == 0:
            min += s//6
        elif s%6 == 2:
            min += (s//6) +1
        else:
            min +=s//6 + 1

        if min ==0:
            print(max ,max)
        else:
            print(min, max) 
'''

'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    c = 0
    for i in range(n - 2, -1, -1):
        if l[i + 1] == 0:
            c = -1
            break
        while l[i] >= l[i + 1]:
            l[i] = l[i] // 2
            c += 1
    print(c)
'''

'''
for _ in range(int(input())):
    n , m = map(int,input().split())
    a = list(map(int,input().split()))
    d = n + max(a) - min(a) + sum(a)
    if d <= m:
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    a,b = map(str,input().split())
    for i in a:
        if i not in b:
            a = a.replace(i, '', 1)
    for i in a:
        a = a.replace(i, '', abs(b.count(i) - a.count(i)))
    print('YES' if a == b else 'NO')
'''

'''
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    print(l[0])
'''
'''
for _ in range(int(input())):
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    c = 0
    if k==1:
        print((n-1)//2)
        continue
    for i in range(1,n-1):
        if a[i] > a[i-1] + a[i+1]:
            c+=1
    print(c)
'''

'''
for _ in range(int(input())):
    n = int(input())
    l =list(map(int,input().split()))
    pos =[]
    neg =[]
    for i in l:
        if i > 0:
            pos.append(i)
        elif i<0:
            neg.append(i)

    if len(pos) > 2 or len(neg) >2:
        print("NO")
        continue

    new = pos +neg
    if 0 in l:
        new.append(0)
    ans = "YES"
    for i in range(len(new)-2):
        for j in range(i+1,len(new)-1):
            for k in range(j+1,len(new)):
                if new[i] + new[j] +new[k] not in new:
                    ans = "NO"
    print(ans)
'''

'''
for _ in range(int(input())):
    n = int(input())
    a = str(input())
    if a[0] == '9':
        print(int('1'*(n+1)) - int(a))
    else:
        print(int('9'*n) - int(a))
'''

'''
for _ in range(int(input())):
    n = int(input())
    p = list(map(int,input().split()))
    l = 2**30 -1
    for i in range(n):
        if p[i] != i :
            l&=i
    print(l)
'''
'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    tot = a[0]

    for i in range(1, n):
        if tot < 0:
            break
        elif tot == 0:
            if a[i] != 0:
                break
        else:
            tot += a[i]
    else:
        if tot == 0:
            print("Yes")
            continue

    print("No")
'''

'''
for _ in range(int(input())):
    n, k = map(int,input().split())
    s = input().strip()
    c = s[:k].count("W")
    m = c
    for i in range(k, n):
        c += (s[i] == "W") - (s[i - k] == "W")
        m = min(m, c)
    print(m)
'''

'''
s=input()
print([s,s.swapcase()][s[1:]==s[1:].upper()])
'''

'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    if n%2 == 1:
        print("Mike")
    else:
        if a.index(min(a)) %2 == 1:
            print("Mike")
        else:
            print("Joe")
'''
'''
for _ in range(int(input())):
    m = int(input())
    s1 = list(map(int ,input().split()))
    count =0
    l =[]

    for i in range(m):
        a = int(s1[i])
        a %= 10
        if l.count(a) < 3:
            l.append(a)
    n = len(l)

    for i in range(n-2):
        for j in range(1,n-1):
            for k in range(2,n):
                sum = l[i] +l[j] + l[k]
                if sum%10 == 3:
                    if i == j or i ==k or j==k:
                        continue
                    else:
                        count +=1

    if count >= 1:
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    n,s = map(int,input().split())
    a = list(map(int,input().split()))
    i = 0
    if sum(a) < s :
        print(-1)
    elif sum(a) == s:
        print(0)
    else:
        i = j = 0
        cnt = 0
        ans = 0
        for k in range(n):
            cnt += a[k]
            while cnt > s:
                cnt -= a[i]
                i += 1
            if cnt == s:
                ans = max(ans, k - i + 1)
        print(n - ans)
'''


'''
for _ in range(int(input())):
    n,m= map(int,input().split())
    a = [[1, 0, 0, 1], [0, 1, 1, 0], [0, 1, 1, 0], [1, 0, 0, 1]]
    for i in range(n):
        for j in range(m):
            print(a[i%4][j%4] , end=' ')
        print('')
'''

'''
for _ in range(int(input())):
    n = int(input())
    s = input()
    c = n
    for i in range(1,n):
        if s[i] != s[i-1]:
            c+=i
    print(c)
'''


'''
for _ in range(int(input())):
    n,k = map(int,input().split())
    l = list(map(int,input().split()))
    sum = 0
    count = 0
    for i in range(1,n):
        if l[i] > (l[i-1]//2):
            sum+=1
        else:
            sum = 0

        if sum >= k:
            count+=1
    print(count)
'''
'''
for _ in range(int(input())):
    x,y = map(int,input().split())
    print(x-y)
'''


'''
for _ in[0]*int(input()):
 input()
 a=max(map(int,input().split()))
 input()
 b=max(map(int,input().split()))
 if a>b:print('Alice');print('Alice')
 if a<b:print('Bob');print('Bob')
 if a==b:print('Alice');print('Bob')
'''


'''
for t in range(int(input())):
	n, m = map(int, input().split())
	f = [0 for i in range(n + m)]
	g = [0 for i in range(n + m)]
	a = []
	for i in range(n):
		a.append(list(map(int, input().split())))

		for j in range(m):
			f[i + j] += a[i][j]
			g[i - j + m] += a[i][j]
	z = 0
	for i in range(n):
		for j in range(m):
			z = max(z, f[i + j] + g[i - j + m] - a[i][j])
	print(z)
'''

'''
for _ in range(int(input())):
    a= input()
    b = input()
    if b == 'a':
        print(1)
        continue
    elif b.find('a') != -1:
        print(-1)
    else:
        print(2**len(a))
'''

'''
for _ in range(int(input())):
    s = input()
    k = len(set(s))
    for i in range(k, len(s)):
        if s[i] != s[i-k]:
            print('NO')
            break
    else:
        print('YES')
'''

'''
for _ in range(int(input())):
    l , r ,a = map(int,input().split())
    y = a * ((r + 1) // a) - 1
    if y < l:
        x = r
    else:
        x = y
    print((x // a) + (x % a))
'''
'''
for _ in range(int(input())):
    n = int(input())
    c = len(set(map(int,input().split())))
    for i in range(1,n+1):
        print(max(c,i) , end=" ")
    print('')
'''

'''
for _ in range(int(input())):
    x1, y1 = map(float,input().split())
    x2, y2 = map(float, input().split())
    x3, y3 = map(float, input().split())
    s = 0
    if y1 == y2 != s and y3 < y1:
        print(abs(x2-x1))
    elif  y2 ==y3!= s and y1 < y2:
        print(abs(x3-x2))
    elif  y3 ==y1 != s and y2 < y3:
        print(abs(x1-x3))
    else:
        print(0)
'''


'''
for _ in range(int(input())):
    a,b,c=map(int,input().split())
    if (a+c)%(2*b)==0 or ((2*b-c)>0 and (2*b-c)%a==0) or (((2*b-a)>0 and (2*b-a)%c==0)):
        print("YES")
    else:
        print("NO")
'''

'''
import math
for _ in range(int(input())):
    n = int(input())
    l = 2
    while math.gcd(l,n-l-1) != 1:
        l+=1
    print(l , n -l -1 ,1)
'''
'''
import math
for _ in range(int(input())):
    x1 , p1 = map(int,input().split())
    x2, p2 = map(int, input().split())
    num = math.log10(x1 / x2) + p1 - p2
    if num == 0:
        print('=')
    elif num > 0:
        print('>')
    else:
        print('<')
'''


'''
for _ in range(int(input())):
    n,a,b = map(int,input().split())
    ans = [a]
    for i in range(n,0,-1):
        if i !=a and i != b:
            ans.append(i)
    ans.append(b)
    if len(ans)==n and min(ans[:n//2])==a and max(ans[n//2:])==b:
        print(*ans)
    else:
        print(-1)
'''
'''
import math
for _ in range(int(input())):
    n = int(input())
    l = list(map(int,input().split()))
    gc = abs(1 - l[0])
    for j in range(2, n + 1):
        num1 = abs(l[j - 1] - (j))
        gc = math.gcd(gc, num1)
    print(gc)
'''

'''
for _ in range(int(input())):
    n = int(input())
    s = str(input())
    l = []
    for i in range(n):
        if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' :
            l.reverse()
            l.append(s[i])
        else:
            l.append(s[i])
    for j in l:
        print(j , end="")
    print('')
'''
'''
import bisect
for _ in range(int(input())):
    n , q = map(int,input().split())
    a = list(map(int,input().split()))
    a.sort(reverse=True)
    for i in range(1,n):
        a[i]+=a[i-1]
    for j in range(q):
        p = int(input())
        mark = bisect.bisect_left(a,p)
        if mark == n:
            print(-1)
        else:
            print(mark + 1)
'''
'''
for _ in range(int(input())):
    s = str(input())
    x , y = max(s.rfind("1"),0) , s.find('0') + 1
    if y ==0:
        y = len(s)
    print(y-x)
'''

'''
for _ in range(int(input())):
    n = int(input())
    z = list(map(int,input().split()))

    l = 0
    r = n-1
    bob , alice = 0,0
    count = 0
    b , a = 0,0
    
    while l <= r:

        if alice > bob:
            bob += z[r]
            b += 1
            r -= 1

        else:
            alice += z[l]
            a += 1
            l += 1

        if bob == alice:
            count = a + b

    print(count)
'''

'''
for _ in range(int(input())):
    n = int(input())
    print(2)
    for j in range(1,n+1,2):
        t = j
        while j < n+1:
            print(j , end=' ')
            j*=2
    print('')
'''
'''
import bisect
n = int(input())
x = list(map(int, input().split()))
x.sort()
for _ in range(int(input())):
    p = int(input())
    print(bisect.bisect_left(x,p+1))
'''

'''
for _ in range(int(input())):
    n = int(input())
    if 360%(180-n) == 0:
        print("YES")
    else:
        print("NO")
'''
'''
c = "Poor"
for i in range(int(input())):
    a,b=input().split(" ")
    if a!=b:
        c="Happy"
print(c,"Alex")
'''
'''
for _ in range(int(input())):
    n = input()
    print(int(n) - 10**(len(n) - 1) )
'''

'''
for _ in range(int(input())):
    n = input().lower()
    if n == "yes":
        print("YES")
    else:
        print("NO")
'''

'''
for _ in range(int(input())):
    n = int(input())
    f = list(map(int, input().split()))
    for i in range(n):
        s = input()
        f[i] += s.count("D") - s.count("U")
    for i in range(n):
        f[i] = f[i] % 10
    print(*f)
'''


'''
for _ in range(int(input())):
    n,x = map(int,input().split())
    l = list(map(int,input().split()))
    l.sort()
    front = l[n:]
    back = l[:n]
    for i in range(n):
        if front[i] - back[i] < x:
            print("NO")
            break
    else:
        print("YES")
'''
'''
for _ in range(int(input())):
    n = int(input())
    print(n , end= " ")
    for i in range(1,n):
        print(i , end=" ")
    print("")
'''

'''
for _ in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    if a[n-1] != 0 and a[a[n-1] - 1] != 0:
        print("YES")
    else:
        print("NO")
'''


'''
dict = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}
digits = input()
m = []
n = len(digits)
if n == 0:
    m = m

l = 0
while l < n:
    if l == 0:
        for i in dict.get(digits[l]):
            m.append( i)
    else:
        k=m[::]
        m=[]


        for i in dict.get(digits[l]):

            for j in k:
                m.append(j + i)
    l+=1
print(m)
'''


'''
grid = [[3,2,1],[1,7,6],[2,7,7]]
row = []
column = []
for i in grid:
    row.append(i)
for j in grid:
    for k in range(len(grid[0])):
        column.append(j[k])
print(row)
print(column)
'''












import math
from math import gcd
for _ in range(int(input())):
    a=list(map(int,input().split()))
    if a.count(0)>0:
        if a.count(0)==1:
            print(1)
        else:
            print(0)
    else:
        gcd1=gcd(a[0], a[1])
        gcd2=gcd(a[2], a[3])
        a[0]//=gcd1
        a[1]//=gcd1
        a[2]//=gcd2
        a[3]//=gcd2
        
        k=(a[0]*a[3])%(a[1]*a[2])
        l=(a[1]*a[2])%(a[0]*a[3])
        
        if (a[0]*a[3])==(a[2]*a[1]):
            print(0)
        elif k==0 or l==0:
            print(1)
        else:
            print(2)

