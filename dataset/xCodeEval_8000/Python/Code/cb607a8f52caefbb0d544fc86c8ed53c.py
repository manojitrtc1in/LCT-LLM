'''class parrot:
    species="bird"

    def __init__(self,name,age):
        self.name=name
        self.age=age
blu=parrot("golden",10)
whi=parrot("black",15)
print(blu.age)
print(whi.age)
'''
'''


class parrot:
    
    def __init__(self,name,age):
        self.name=name
        self.age=age

    def sing(self,song):
        return "{} sings {}".format(self.name,song)

    def dance(self):
        return "{} is now dancing".format(self.name)
blu=parrot("Blu",10)
print(blu.sing("'Happy'"))
print(blu.dance())'''

'''
class bird:
    def __init__(self):
        print("Bird is ready")
    def whoisthis(self):
        print("Bird")
    def swim(self):
        print("Swim faster")
class penguin(bird):
    def __init__(self):
        super().__init__()
        print("penguin is ready")
    def whoisthis(self):
        print("penguin")
    def run(self):
        print("run faster")

peg=penguin()
peg.whoisthis()
peg.swim()
peg.run()

'''
'''
class MyNewClass:
    "This is a docstring. I have created a new class"
    pass
'''
'''
k=[1,2,3,4]
del k[0]
print(k)

'''
'''
def get(s):
    b=s.count('B')
    a=s.count('A')
    l=s.count('L')
    o=s.count('O')
    n=s.count('N')
    co=0
    while(b>=1 and a>=1 and l>=2 and o>=2 and n>=1):
        co+=1
        b=b-1
        a=a-1
        l=l-2
        o=o-2
        n=n-1
    return co'''



'''

l=[-1,1,-2,2]
ans=0
for i in range(1,len(l)):
    if l[i]<ans:
        ans=l[i]
print(ans)'''
'''

A = [42, 33, 60]
input3 =  [51, 32, 43]
input4 = [598888888,688888888,5988888881111,6888888881111]
input5 = [5,9,6,8]
input6 = [59,68]

def sA(digit):
    digit = str(digit)
    tp = 0
    res = [tp + int(x) for x in digit]
    return sum(res)

def s_C(A):
    rs = [sA(str(A[0]))]
    for x in range(1,len(A)):
       t =  sA(str(A[x]))
       if t not in rs:
           pass
       elif t in rs:
           rs.append(t)
    if len(rs) == 1:
        return False
    else:
        return True

def solution(A):
    max_ = 0
    temp = []
    if s_C(A) != False:
        for x in range(0, len(A),1):
            toUse = sA(str(A[x]))
            for y in range(1,len(A),1):
                to2 = sA(A[y])
            if toUse == to2 :
                temp.append(A[x] + A[y])
                break
    if len(temp) != 0:
        return max(temp)
    return -1


print(solution(A))'''
'''

def get(n):
    l=list(str(n))
    lk=[int(l[i]) for i in range(len(l))]
    for i in range(len(lk)-1):
        if abs(lk[i]-lk[i+1])==1:
            continue
        else:
            return 0
    return 1
        


a,b=map(int,input().split())
su=0
for i in range(a,b+1):
    if get(i)==1:
        su+=i
print(su)'''




'''
            
    
    
def pet(u):
    return u and (not(u &(u-1)))

y=int(input())
l=list(map(int,input().split()))
c=0
su=0
for i in range(len(l)):
    if (pet(l[i])):
        c+=1
        su+=l[i]
print(c)
print(su)
    '''


'''

class Solution:
    def maxAND(A,N):
        re=0
     
        for i in range(0,N) :
            for j in range(i+1,N):
                re=max(re,A[i]&A[j])
     
        return res
    def maxAnd(A,N):
        A.sort()
        A[0]=A[0]+1
        return maxAND(A,N)'''


'''

n=int(input())
m=int(input())
for i in range(1,n+1):
    if i%2==0:
        print(" ",end="")
    else:
        print("*",end="")
        

for i in range(m):
    if i%2==0:
        print("")
        
    else:
        print("*",end="")
        for j in range(2*m-1):
            print(" ",end="")
        print("*")
    
        
    


for i in range(1,n+1):
    if i%2==0:
        print(" ",end="")
    else:
        print("*",end="")'''

'''
n=int(input())
m=int(input())
for i in range(1,n+1):
    for j in range(1,n+1-i):
        print(" ",end=" ")
    for k in range(i):
        if i%2!=0:
            print("
        else:
            print(" ",end=" ")
            
    print()
'''


'''
n=int(input())
m=int(input())
for i in range(1,n+1):
    for j in range(1,i+1):
        print(" ",end=" ")
    for k in range(1,n+1-i):
        if i%2==0:
            print(" ",end=" ")
        else:
            print("
    print()
'''
'''
n=int(input())
for i in range(1,n+1,2):
    
    for j in range(1,i+1):
        for i in range(1,(i//2)+2):
            print("*",end=" ")
        for i in range(1,(i//2)+1):
            print("*",end=" ")
        
    print()'''
'''
n=int(input())
m=0
for i in range(n):
    for j in range(n-m):
        print(j+i+1,end=" ")
    for i in range(m):
        print(i+1,end=" ")
    m+=1
    print()
'''
'''
n=int(input())
arr=[[0 for j in range(n)]for i in range(n)]
u1=0
u2=n-1
for o in range(n,0,-1):
    
    for i in range(n):
        for j in range(n):
            arr[u1][j]=o
    for i in range(n):
        for j in range(n):
            arr[j][u1]=o
    for i in range(n):
        for j in range(n):
            arr[j][u2]=o
    for i in range(n):
        for j in range(n):
            arr[u2][j]=o
    u1=u1+1
    u2=u2-1
for i in range(n):
    for j in range(n):
        print(arr[i][j],end=" ")
    print()'''


'''
n=int(input())
k=65
m=n
for i in range(n):
    k=65
    for j in range(m):
        print(chr(k),end=" ")
        k+=1
    m=m-1
    print()
for i in range(n):
    g=65
    for j in range(i+1):
        print(chr(g),end=" ")
        g+=1
    print()'''

'''
n=int(input())
for i in range(n,0,-1):
    p=65
    for j in range(i):
        print(" ",end=" ")
    for i in range(n-j):
        print(chr(p),"  ",end="")
        p+=1
    print()'''
'''
n1=input()
l1=['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
l2=[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26]
index=l1.index(n1)
n=l2[index]
print(n)
g=65
for i in range(n,0,-1):
    for j in range(i):
        print(" ",end=" ")
    print(chr(g))
    g+=1
    print()
for i in range(n):
    for j in range(i):
        print(" ",end=" ")
    print(chr(g-1))
    g=g-1
    if g==64:
        break
    
    print()'''

'''

n=int(input())
u=n*n
u1=1
for i in range(n):
    for j in range(n):
        if u1%2==0:
            print(0,end=" ")
        else:
            print(1,end=" ")
        u1+=1
        
    print()

'''
'''
n=int(input())
for i in range(n):
    for j in range(i):
        print(" ",end="")
    print("
    
    for i in range((n-i)*2):
        print(" ",end="")
    print("
    print()
print(12*" ","
'''
'''
def get(n):
    if len(n)==2:
        return n
    else:
        ln=[]
        for i in range(len(n)):
            if i%2==0:
                ln.append(n[i])
        print(ln)
        return get(ln)
                
l=list(map(int,input().split()))
new=get(l)
print(l.index(new[-1]))
'''




'''
import math

def highestPowerof2(n):

	p = int(math.log(n, 2));
	print(p)
	return int(pow(2, p));

n = 5;
print(highestPowerof2(n));
'''
'''
import math
n=int(input())
l=[]
p=1
for i in range(1,n+1):
    lk=[]
    for j in range(i):
        lk.append(p)
        p+=1
    l.append(lk)
su=0
for i in range(len(l)):
    re=1
    for j in range(len(l[i])):
        re=re*l[i][j]
    su+=re
print(su)
'''
'''
def get(l):
    for i in range(len(l)):
        if l[i]%2!=0:
            r=True
        else:
            r=False
            break
    return r
n=int(input())
for i in range(n):
    nk=input()
    l=list(nk)
    l=[int(l[i]) for i in range(len(l))]
    if l[-1]%2==0:
        print(0)
    if l[-1]%2!=0:
        if len(l)==1 or get(l)==True:
            print(-1)
        elif l[0]%2==0:
            print(1)
        else:
            print(2)

'''
'''
def perfectno(num):
    sum_v=0  
    for i in range(1,num):  
        if (num%i==0):  
            sum_v=sum_v+i  
    if(sum_v==num):  
        return 1 
    else:
        return 0
n=int(input())
fact=0
summ=0
for i in range(1,n+1):
    if n%i==0:
        summ+=i
if perfectno(fact) and perfectno(summ):
       print("It is sublime number")
else:
        print("It is not sublime number")

'''

'''
l=[5,4,1,0]
for i in range(len(l)):
    for j in range(len(l)):
        if l[i]&l[j]==l[i]:
            print(l[i],l[j],(l[i]&l[j]))'''
'''
n=input()
g="password"
if len(n)>31 or len(n)<7 or g in n:
    print("false")
else:
    l=list(n)
    o=[1,2,3,4,5,6,7,8,9,0]
    c=0
    for i in range(len(l)):
        if l[i].isupper() or l[i] in o or l[i].isalnum():
            c=1
        else:
            c=0
            break
    if (c):
        print("false")
    else:
        print("true")'''









'''
n=int(input())
for i in range(n):
    k=int(input())
    l=list(map(int,input().split()))
    c=0
    for a in l:
        for b in l:
            if (a+b)%4==0:
                c+=1
    print(c)
'''
'''
for i in range(int(input())):
    s=input()
    lk=list(s)
    if len(lk)%2==0:
        if ("".join(lk[:len(lk)//2])) == ("".join(lk[len(lk)//2:len(lk)])):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
            
'''
'''
for i in range(int(input())):
    a,b=map(int,input().split())
    num1=list(str(a))
    num_re2=list(str(b))
    num1=[int(num1[i]) for i in range(len(num1))]
    num_re2=[int(num_re2[i]) for i in range(len(num_re2))]
    
    
    ik=[]
     while(len(num1)):
        print(ik)
        
        if len(num_re2)==0:
            print(-1)
            break
        if num_re2[-1]>=num1[-1]:
            ik.append(num_re2[-1]-num1[-1])
            num1.pop(-1)
            num_re2.pop(-1)
            print(num1)
            print(num_re2)
            break
        elif int(str(num_re2[-2])+str(num_re2[-1]))>=num1[-1] and len(num_re2)>1:
            ik.append(int(str(num_re2[-2])+str(num_re2[-1]))-num1[-1])
            num1.pop(-1)
            num_re2.pop(-1)
            num_re2.pop(-2)
    if len(num1)!=0:
        print(ik)
        '''
        
    
            
'''
def displayResult(N,arr):
    arr=[str(arr[i]) for i in range(len(arr))]
    u="".join(arr)
    return u.count("<>")
print(displayResult(5,['*','<','*','<','*']))'''


'''
def prime(n):
    if n<=1:
        return 0
    for i in range(2,n):
        if n%i==0:
            return 0
    return 1


n=int(input())
if (prime(n)):
    print("it is prime number")
else:
    print("NOT prime number")
'''

'''
def solve(N):
    sr=0
    for i in range(2,N+1):
        if (prime(i)):
            sr+=i
    return sr
print(solve(5))

'''
'''
n=int(input())
l=list(map(int,input().split()))
q=int(input())
for i in range(q):
    a,b=map(int,input().split())
    ki=[]
    cr=0
    for i in range(a-1,b-1):
        if l[i]<=l[i+1]:
            cr+=1
        else:
            
            break
    cr+=1
    print(cr)
'''
''' 
l=list(map(int,input().split()))
l.sort()
ki=[]
cr=0
if len(l)>2:
    ki=[l[0]]
    for i in range(1,len(l)):
        ki.append(l[i])
        if min(ki[-1],ki[-2])> min(ki[-1],ki[-3]):
            cr+=min(ki[-1],ki[-3])
        else:
            cr+=min(ki[-1],ki[-2])
            
    print(cr)
elif len(l)==2:
    print(min(l[0],l[1]))
else:
    print(0)
'''

'''
for i in range(int(input())):
    a,b=map(int,input().split())
    la=input()
    la=list(la)
    
    
    if a==1:
        print("YES")
    else:
        if a%2==0:
            l1=la[:a//2]
            l2=la[a//2:]
            l2.sort()
            
            
            ct=0
            for i in range(len(l2)):
                if l1[i]!=l2[i]:
                    
                    ct+=1
            
            if b==ct:
                print("Yes")
            else:
                print("NO")
        else:
            l1=la[:a//2]
            l2=la[a//2+1:]
            
            
            l2.sort()
            ct=0
            for i in range(len(l2)):
                if l1[i]!=l2[i]:
                    ct+=1
            if b==ct:
                print("Yes")
            else:
                print("NO")
            

'''
'''
for i in range(int(input())):
    n,b=map(int,input().split())
    st=input()
    lst=list(st)
    
    l1=[]
    for i in range(len(lst)//2):
        l1.append(lst[i])
    lst.reverse()
    l2=[]
    for i in range(len(lst)//2):
        l2.append(lst[i])
    
    
    if n==1:
        if b==0:
            print("Yes")
        else:
            print("NO")
    else:
        cout=0
        for i in range(len(l1)):
            if l1[i]!=l2[i]:
                cout+=1
        if cout==b:
            print("Yes")
        else:
            print("NO")
            
'''
'''
for i in range(int(input())):
    a,b=map(int,input().split())
    s=input()
    if b==0:
        print(1)
    else:
        
        l=[]
        c1=s+s[::-1]
        c2=s[::-1]+s
        l.append(c1)
        l.append(c2)
        print(len(set(l)))
        
'''
'''
for i in range(int(input())):
    n=int(input())
    p=['1','2','3','4','5','6','7','8','9']
    if n%7==0:
        print(n)
    else:
        if len(list(str(n)))==1:
            print(7)
        else:
            lk=list(str(n))
            lk=lk[:-1]
            for i in range(len(p)):
                lk+=[p[i]]
                gh=''.join(lk)
                if int(gh)%7==0:
                    k=gh
                    break
                else:
                    lk=lk[:-1]
        print(k)
'''

'''
for i in range(int(input())):
    n=int(input())
    s=input()
    if n==1:
        print("YES")
    elif n==2:
        if s=="10" or s=="01":
            print("YES")
        else:
            print("NO")
    else:
        print("NO")'''

'''
for i in range(int(input())):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    for i in range(n):
        if l1[i]<l2[i]:
            c=l2[i]
            l2[i]=l1[i]
            l1[i]=c
        else:
            continue
    print(max(l1)*max(l2))
            
'''
'''
for i in range(int(input())):
    n=input()
    l=list(n)
    m=[]
    for i in range(len(l)):
        if l[i] not in m:
            m.append(l[i])
    
    sr=""
    for i in range(len(m)):
        if l.count(m[i])>1:
            sr+=m[i]*2
        else:
            sr+=m[i]
    print(sr)
            
'''

'''
for i in range(int(input())):
    n,m,r,c=map(int,input().split())
    r=r-1
    c=c-1
    s=list(input() for i in range(n))
    lt=[]
    for i in range(n):
        for j in range(m):
            lt.append(s[i][j])
    if "B" not in lt:
        print(-1)
    elif s[r][c]=="B":
        print(0)
    else:
        c1=0
        c2=0
        for i in range(n):
            for j in range(m):
                if s[i][c]=="B":
                    c1=1
                    break
            if c1==1:
                break
        for i in range(n):
            for j in range(m):
                if s[r][j]=="B":
                    c2=1
                    break
            if c2==1:
                break
        if c1==1 or c2==1:
            print(1)
        else:
            print(2)
        
'''
'''
input1=int(input())
input2=int(input())
c=input1+input2
print("AP KA ADD KIYA NUMBER HAI",c)

'''

'''

p=str(Name)
u=list(p)
l=[int(p[i]) for i in range(len(u))]
re=""
if len(l)%2==0:
    for i in range(0,len(l),2):
        if l[i]>l[i+1]:
            re+=str(l[i])
        else:
            re+=str(l[i+1])
else:
    for i in range(0,len(l)-1,2):
        if l[i]>l[i+1]:
            re+=str(l[i])
        else:
            re+=str(l[i+1])
    re+=str(l[-1])



'''



'''


def KMPSearch(pat, txt):
	M = len(pat)
	N = len(txt)

	
	
	lps = [0]*M
	j = 0 

	
	computeLPSArray(pat, M, lps)

	i = 0 
	while i < N:
		if pat[j] == txt[i]:
			i += 1
			j += 1

		if j == M:
			print ("Found pattern at index " + str(i-j))
			j = lps[j-1]

		
		elif i < N and pat[j] != txt[i]:
			
			
			if j != 0:
				j = lps[j-1]
			else:
				i += 1

def computeLPSArray(pat, M, lps):
	len = 0 

	lps[0] 
	i = 1

	
	while i < M:
		if pat[i]== pat[len]:
			len += 1
			lps[i] = len
			i += 1
		else:
			
			
			
			if len != 0:
				len = lps[len-1]

				
			else:
				lps[i] = 0
				i += 1

txt = "ABABDABACDABABCABAB"
pat = "ABABCABAB"
KMPSearch(pat, txt)



        
'''


'''
import math

for i in range(int(input())):
        a,b=map(int,input().split())
        
        if a==0 and b==0:
                print(0)
        elif (math.sqrt(a*a+b*b))==int(math.sqrt(a*a+b*b)):
                print(1)
        else:
                print(2)

'''
'''
for i in range(int(input())):
        n,b,x,y=map(int,input().split())
        l=[0]
        for i in range(n):
                if max(l[-1]+x,l[-1]-y)<=b:
                        l.append(max(l[-1]+x,l[-1]-y))
                else:
                        l.append(min(l[-1]+x,l[-1]-y))
        print(sum(l))
                        
                
        
        
        
'''
'''
def regular(st):
        left=[]
        right=[]
        for ele in st:
                if ele=='(':
                        left.append('(')
                else:
                        right.append(')')
        if len(left)==len(right):
                return 1
        else:
                return 0
        

st=input()
print(regular(st))
'''
'''
def Reverse(lst):
    return [ele for ele in reversed(lst)]

def palin(s):
        kl=list(s)
        
        
        if "".join(kl)=="".join(Reverse(kl)):
                return 1
        else:
                return 0

s=input()
print(palin(s))
        
'''

'''



n=input()
l=list(n)
print()
lg=l.count('G')
lb=l.count('B')

if lg>lb:
    kl=[]
    for i in range(len(l)):
        if i%2==0:
            kl.append('G')
        else:
            kl.append('B')
    
    c1=0
    for i in range(len(l)):
        if l[i]!=kl[i]:
            c1+=1
    print(c1//2)
elif lg<lb:
    kl=[]
    for i in range(len(l)):
        if i%2==0:
            kl.append('B')
        else:
            kl.append('G')
   
    c1=0
    for i in range(len(l)):
        if l[i]!=kl[i]:
            c1+=1
    print(c1//2)
else:
    k1=[]
    for i in range(len(l)):
        if i%2==0:
            k1.append('G')
        else:
            k1.append('B')
    
    k2=[]
    for i in range(len(l)):
        if i%2==0:
            k2.append('B')
        else:
            k2.append('G')
    
    cr=0
    for i in range(len(l)):
        if l[i]!=k1[i]:
            cr+=1
    cy=0
    for i in range(len(l)):
        if l[i]!=k2[i]:
            cy+=1
    print(min(cr//2,cy//2))
        
'''
'''
import math
def prime(n):
    nums=[0,0] + [1]*(n-2)
    for i in range(2,int(math.sqrt(n)+1)):
        if nums[i]==1:
            for j in range(i*i,n,i):
                nums[j]=0
    return sum(nums)
print(prime(7))
'''
'''
cr=0
ni=int(input())
while(ni!=1):
    print(prime(ni))
    ni=ni-prime(ni)
    if ni==1:
        break
    cr+=1
print(cr)
   
'''
'''
def Sie(n):
    pr = [True for i in range(n + 1)]
    p0 = 2
    while (p0 * p0 <= n):
        if (pr[p0] == True):
            for i in range(p0 ** 2, n + 1, p0):
                pr[i] = False
        p0+=1
    pr[0]= False
    pr[1]= False

    fr=0
    for p in range(n + 1):
        if pr[p]:
            fr+=1
    return(fr)



ni=int(input())
cr=0
while(ni>1):
    ni=ni- Sie(ni)
    
    cr+=1
print(cr+1)
'''
'''
mat=[input().split() for i in range(10)]
die=list(map(int,input().split()))
kl=[]
for i in range(10):
    for j in range(10):
        if mat[i][j]=='End' or mat[i][j]=='Start' or 'S' in list(mat[i][j]) or 'L' in list(mat[i][j]):
            continue
        else:
            mat[i][j]=int(ma[i][j])
for i in range(10):
    for j in range(10):
        kl.append(mat[i][j])
kl.sort()
su=0
for i in range(len(die))
p=kl[i]
su+=die[i]
if 'S' in p:
    p

'''

'''
for i in range(int(input())):
    a,k=map(int,input().split())
    l=list(map(int,input().split()))
    if (max(l)-min(l))==k:
        print("YES")
    else:
        print("NO")
'''
'''
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    if (n==1 and l[0]>1) or (n>1 and l[-1]-l[-2]>1):
        print("NO")
    else:
        print("YES")'''
   
'''           
for i in range(int(input())):
    n=int(input())
    if n==1:
        print(1)
    elif n==2:
        print(2)
    elif n==3:
        print(21)
    else:
        k=n//3
        r=n%3
        
        if r==0:
            print('21'*k)
        elif r==1:
            print('12'*k+'1')
        else:
            print('21'*k+'2')'''

'''
for i in range(int(input())):
    
    a,b=map(int,input().split())
    mat=[list(map(int, list(input()))) for i in range(a)]
    ans='YES'
    k=False
    for i in range(a-1):
        for j in range(b-1):
            if (mat[i][j]+mat[i+1][j]+mat[i][j+1]+mat[i+1][j+1])==3:
                ans='NO'
                k=True
                break
        if (k):
            break
    print(ans)'''
'''
for i in range(int(input())):
    n=int(input())
    print(2**n-1)'''
'''
for i in range(int(input())):
    n=int(input())
    l=list(map(str,input().split()))
    k=''.join(l)
    p=k.count('10')
    p1=k.count('0')
    print(p+p1)
'''
'''
for _ in range(int(input())):
  n = int(input())
  a = list(map(int, input().split()))
 
  if a.count(0) == 0:
    print(0)
  else:
    s = ''.join(map(str, a))
    print(s)
    s = s.strip('1')
    print(s)
    print(len(s) + 1)
'''
'''
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    y=len(l)
    ui=[]
    new=[]
    for i in range(len(l)):
        if 1<=l[i]<=y:
            ui.append(l[i])
        else:
            new.append(l[i])
    print(new)
            
    for i in range(len(new)):
        j=new[i]
        while(j not in ui):
            j=j//2
        ui.append(j)
    if sum(ui)==n*(n+1)//2:
        print("YES")
    else:
        print("NO")'''

'''
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    j=l.index(max(l))
    h=list(set(l.copy()))
    h.sort(reverse=True)
    if len(h)==1:
        print(max(l)*min(l))
    else:
        
        for i in range(1,len(h)):
            min1=l.index(h[i])
            if min1<j:
                if min(l[min1:j])==h[i]:
                    print(max(l)*h[i])
                    break
            elif min1>j:
                min1=l.index(h[i])
                if min(l[j:min1+1])==h[i]:
                    print(max(l)*h[i])
                    break
            else:
                print(max(l)*min(l))
                break
            
'''
'''
for i in range(int(input())):
    a,b=map(int,input().split())
    if a==b:
        print((a+b)//4)
    elif a>b:
        if 4*b<a:
            print(b)
        else:
            p=a//4
            k=a%4
            if p>b:'''
'''
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    
    l=list(set(l))
    p=sorted(l)
    l=[str(l[i]) for i in range(len(l))]
    if l.count('0')==n or l.count('1')==n or l.count('2')==n:
        print("YES")
    elif '1' in l:
        print("NO")
    else:
        g=0
        for i in range(len(p)-1):
            if p[i+1]-p[i]==1:
                print("NO")
                break
            else:
                g+=1
        if g+1==len(p):
            print("YES")
   
        
  '''

'''


def sum(a,b):
    return a+b
n=int(input())
n1=int(input())
print("som ofa and is ",sum(n,n1))



'''
'''
for i in range(int(input())):
    n=int(input())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    for i in range(n):
        k=min(l1[i],l2[i])
        l1[i]=max(l1[i],l2[i])
        l2[i]=k
    
    
    u1=sum([abs(l1[i]-l1[i+1]) for i in range(n-1)])
    

    u2=sum([abs(l2[i]-l2[i+1]) for i in range(n-1)])
    print(u2+u1)
'''
'''
for i in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    p=[str(l[i]) for i in range(len(l))]
    if len(l)==1 or p.count(p[0])==n:
        print(0)
    else:
       d={}
       for i in range(len(l)):
           if l[i] in d:
               d[l[i]]+=1
           else:
                d[l[i]]=1
       
       new=d.values()
       nu1=n-max(new)
       maxx=max(new)
       
       c=1
       while(1):
            if 2*maxx>=n:
                break
            else:
                maxx=2*maxx
                c+=1
       print(c+nu1)
            
'''
'''
for i in range(int(input())):
    n=input()
    l=list(n)
    if len(l)==1:
        print(0)
    elif l.count(l[0])==len(l):
        print(1)
    else:
        d={}
        for i in range(len(l)):
            if l[i] in d:
                d[l[i]]+=1
            else:
                d[l[i]]=1
    
        c=0
        for ele in d:
            if d[ele]==1:
                c+=1
            elif d[ele]==2:
                c+=2
            elif d[ele]>2:
                c+=2
        print(c//2)
        '''

'''
for i in range(int(input())):
    n,m=map(int,input().split())
    a=list(map(int,input().split()))
    if n>m or sum(a)>m:
        print("NO")
    else:
        s=0
        for i in range(n-1):
            s+=max(a[i],a[i+1])%m
        s+=max(a[0],a[-1])%m
        if n+s<=m:
            print("YES")
        else:
            print("NO")
        
'''
'''
t = int(input())
for i in range(t):
    n, r, b = map(int, input().split())
    p = r % (b + 1)
    y = ""
    for j in range(int(r / (b + 1))):
        y = y + "R"
    ans = ""
    for i in range(b + 1):
        if i > 0:
            ans = ans + "B"
        ans = ans + y
        if p > 0:
            ans = ans + "R"
            p = p - 1
    print(ans)
'''
'''
for i in range(int(input())):
    n=int(input())
    n1=input()
    n2=input()
    l1=list(n1)
    l1=[int(l1[i]) for i in range(n)]
    l2=list(n2)
    l2=[int(l2[i]) for i in range(n)]
    cou=0
    f=0
    if l1[0]==0 and l2[0]==1:
        cou+=1
        l1[0]=2
        f=1
    if l1[1]==1 and l2[0]==1 and f==0:
        cou+=1
        l1[1]=2
    f1=0
    if l1[-1]==0 and l2[-1]==1:
        cou+=1
        l1[-1]=2
        f1=1
    if l1[-2]==1 and l2[-1]==1 and f1==0:
        cou+=1
        l1[-2]=2
    
        
    for i in range(1,len(l2)-1):
        if l2[i]==1:
            if l1[i]==0:
                cou+=1
                l1[i]=2
                continue
            elif l1[i-1]==1:
                cou+=1
                l1[i-1]==1
                continue
            elif l1[i+1]==1:
                cou+=1
                l1[i+1]=2
                continue
    print(cou)
        '''        
             
'''    
for i in range(int(input())):
    n=int(input())
    n1=input()
    n2=input()
    l1=list(n1)
    l1=[int(l1[i]) for i in range(n)]
    l2=list(n2)
    l2=[int(l2[i]) for i in range(n)]
    co=0
    for i in range(n):
        if l2[i]==1 and l1[i]==0:
            co+=1
            l2[i]=2
            l1[i]=2
    for i in range(1,n):
        if l2[i]==1 and l1[i-1]==1:
            co+=1
            l2[i]=2
            l1[i-1]=2
    for i in range(n-1):
        if l2[i]==1 and l1[i+1]==1:
            co+=1
            l1[i+1]=2
            l2[i]=2
    print(co)
'''
'''
for i in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    i=0
    u=[]
    cu=0
    pu=0
    while(i<n-1):
        if l[i]>l[i+1]:
            cu+=1
            i+=1
            u.append(pu+1)
            pu=0
        else:
            u.append(cu)
            cu=0
            pu+=1
            i+=1
    u.append(cu+1)
    print(u)
            
'''
'''
for i in range(int(input())):
    n,k=map(int,input().split())
    l=list(map(int,input().split()))
    p=l.copy()
    p.sort()
    if p==l:
        print("YES")
    else:
        u=[]
        f=0
        for i in range(n-1):
            if l[i]<=l[i+1] and l[i+1]-l[i]==1:
                u.append(l[i])
                f=1
            else:
                if f:
                    u.append(l[i])
                    f=0
                    u.append("
        if f:
            u.append(l[-1])
    
        g=[]
        cy=0
        for i in range(len(u)):
            if u[i]!="
                cy+=1
            else:
                g.append(cy)
                cy=0
    
    
        
        p=(n-sum(g))+len(g)
        if p<=k<=n:
            print("YES")
        else:
            print("NO")

'''


t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    a=list(map(int,input().split()))
    c=1
    a=[[a[i],i]for i in range(n)]
   
    a.sort()
   
    for j in range(1,n):
        \
        if a[j-1][1]+1!=a[j][1]:
            c+=1
    if c<=k:
        print('YES')
    else:
        print('NO')
