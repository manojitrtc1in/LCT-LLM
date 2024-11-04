




"""
l=[]
l=list(map(int,input().split()))
t=int(input())
for i in range(0,len(l)):
    for j in range(1,len(l)):
        if (l[i]+l[j]==t and i!=j):
            m=[l[i],l[j]]
print(m)
"""
"""
class Solution:
    def twoSum(self,l: List[int], t: int) -> List[int]:
        for i in range(len(l)):
            for j in range(i+1, len(l)):
                if l[i]+l[j] == t:
                    return [i, j]
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    count = 0
    for k in range(n):
        if 1+k+count<a[k]:
            count+=a[k]-(1+k+count)
    print(count)
"""
"""
t = int(input())
for i in range(t):
    a = []
    n = input()
    a.append(n)
    s = "".join(a)

    b = []
    m = input()
    b.append(m)
    s1 = "".join(b)

    c = []
    for j in range(len(s1)):
        c.append((s.find(s1[j])) + 1)
    l=[]
    for i in range(len(c)-1):
        diff = abs(c[i] - c[i + 1])
        l.append(diff)
    x = sum(l)
    print(x)
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    b=[]
    for i in range(0, len(a)):
        if a[i]>=0:
            b.append((a[i]*a[i]))
    sum = 0
    for j in range(0, len(b)):
         sum = sum + b[j]
    print(sum)
"""
"""
def palindrome(ar, begin, end):

    if (begin >= end):
        return 1

    if (ar[begin] == ar[end]):
        return palindrome(ar, begin + 1,end - 1)
    elif (ar[begin] != ar[end]):
        return 0

t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    if len(a)==1:
        print("YES")
        continue
    elif len(a)==2:
        print("YES")
        continue
    elif len(a)>2:
        a.sort()
        for j in range(0,len(a),2):
            if a[j]== a[j+1]:
                print("YES")
            else:
                print("NO")
"""
"""
t=int(input())
for i in range(t):
    n = int(input())
    a=[int(n) for n in input().split()]

    if (sum(a))%(len(a))==0:
        print("0")
    else:
        print("1")
"""
"""
t=int(input())
for i in range(t):
    a=[int(n) for n in input().split()]
    if (a[0]==a[1] and a[2]%2==0) or (a[0]==a[2] and a[1]%2==0) or (a[2]==a[1] and a[0]%2==0):
        print("YES")
    elif (a[0]+a[1]==a[2]) or (a[0]+a[2]==a[1]) or (a[2]+a[1]==a[0]):
        print("YES")
    else:
        print("NO")
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    b=str(input())
    o=[]
    l=[]
    for i in range(len(b)):
        if b[i]=="1":
            l.append(a[i])
        elif b[i]=="0":
            o.append(a[i])
    o.sort()
    l.sort()
    merged_list = [j for i in zip(o, l) for j in i]
    print(*merged_list,sep=" ")

"""
"""
from collections import Counter
def countDistinct(arr):
    return len(Counter(arr).keys())
t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    count=0
    for i in range(len(a)):
        for j in range(i+1,len(a)):
            if a[i]==a[j]:
               a[i]=-a[i]
    if __name__ == "__main__":
        print(countDistinct(a))
"""
"""

t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    count=0
    if len(a)>5:
        for i in range(2, len(a) - 1):
            if (2 * a[i - 1]) - (a[i - 2] + a[i]) != 0:
                count = count + 1
            elif (2 * a[i - 1]) - (a[i - 2] + a[i]) == 0:
                count = count
        print(count)
    else:
        for i in range(2, len(a)):
            if (2 * a[i - 1]) - (a[i - 2] + a[i]) != 0:
                count = count + 1
            elif (2 * a[i - 1]) - (a[i - 2] + a[i]) == 0:
                count = count
        print(count)
"""
"""
t=int(input())
for i in range(t):
    a=[int(n) for n in input().split()]
    if (a[0]+1)/2 >= a[1]:
        count=a[1]
        t=[["." for y in range(a[0])]for y in range(a[0])]
        for i in range(0,a[0]):
            for j in range(0,a[0]):
                if j==i and i%2==0 and count>0:
                    t[i][j]="R"
                    count=count-1
        x = '\n'.join([''.join(['{:}'.format(item) for item in row]) for row in t])
        print(x)
    else:
        print("-1")

"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a=[int(n) for n in input().split()]
    print(max(a)-min(a))
"""
"""
t=int(input())
for i in range(t):
    x=[int(n) for n in input().split()]
    a=x[0]
    b=x[1]
    c=x[2]
    if ((2*b)==(a+c)):
        print("YES")
    elif (a+c)%(2*b)==0 and (a+c)/(2*b)>0:
        print("YES")
    elif (2*b-c)%a==0 and (2*b-c)/a>0:
        print("YES")
    elif (2*b-a)%c==0 and (2*b-a)/c>0:
        print("YES")
    else:
        print("NO")
"""
"""
for _ in range(int(input())):
    n=int(input())
    a=list(map(int, input().split()))
    s=set()
    for i in a:
        while (i>n or i in s) and i>1:
            i=i//2
        s.add(i)
    if len(s)==n: print("YES")
    else: print("NO")
"""
"""
t=int(input())
for i in range(t):
    x=[int(n) for n in input().split()]
    n=x[0]

    a=[int(n) for n in input().split()]
    b=[int(n) for n in input().split()]
    c=[]
    for i in range(n):
       c.append([a[i],b[i]])
    c.sort()

    k = x[1]
    for i in range(n):
        if int(c[i][0])<=k:
            k+=c[i][1]
    print(k)
"""
"""
t=int(input())
for i in range(t):
    x=[int(n) for n in input().split()]
    l=x[0]
    r=x[1]
    k=x[2]
    if r==l and r==1:
        print("No")
    elif r==l and r>1:
        print("Yes")
    else:
        a = (r - l) // 2
        if r % 2 != 0 or l % 2 != 0:
            a += 1
        if a > k:
            print("No")
        else:
            print("Yes")
"""
"""
t=int(input())
for i in range(t):
    
    x = [int(n) for n in input().split()]
    n=x[0]
    k=x[1]
    s=input()
    if k==0:
        print("1")
    elif s==s[::-1]:
        print("1")
    else:
        print("2")
        
        
        
        
        
"""
"""
t=int(input())
for i in range(t):
    u = [int(n) for n in input().split()]
    n=u[0]
    k=u[1]
    if n%2!=0 and k>1:
        print("NO")
    else:
        print("YES")
        A = [list(range(1 + k * i, 1 + k * (i + 1)))for i in range(n)]
        res=[[A[j][i] for j in range(n)] for i in range(k)]
        for i in res:
            for j in i:
                print(j,end=" ")
            print()
"""
"""
t=int(input())
for i in range(t):
    p = [int(n) for n in input().split()]
    q = [int(n) for n in input().split()]
    r = [int(n) for n in input().split()]
    hc=p[0]
    dc=p[1]
    hm=q[0]
    dm=q[1]
    k=r[0]
    w=r[1]
    a=r[2]
    flag=0
    for i in range(k+1):
        thc=hc + (k-i)*a
        tdc=dc + (i)*w
        if ((thc//dm)+(thc%dm!=0))>=((hm//tdc)+(hm%tdc!=0)):
            flag=1
            break
    if flag==1:
            print("YES")
    else:
            print("NO")
"""
"""
from math import log2
for _ in range(int(input())):
    n = int(input())
    a=int(log2(n-1))
    k=2**a
    print(*range(1,k),0,*range(k,n))
"""
"""
t=int(input())
for i in range(t):
    a,b=map(int,input().split())
    inc=0
    while True:
        if ((a+inc)|b == b) or (a|(b+inc)==(b+inc)):
            break
        inc+=1
    print(min(inc+1,b-a))
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a = [int(n) for n in input().split()]
    b = [int(n) for n in input().split()]
    for i in range(n):
        if a[i]<b[i]:
            a[i],b[i]=b[i],a[i]
    print(max(a)*max(b))
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    a = [int(n) for n in input().split()]
    a.reverse()
    count=0
    k=1
    while(k<n):
        if a[k]==a[0]:
            k +=1
            continue
        count += 1
        k=k*2
    print(count)
"""
"""
t=int(input())
for i in range(t):
    n,k=map(int,input().split())
    l=[i for i in range(n)]
    if n==4 and k==3:
        print("-1")
        continue
    elif k==n-1:
        l[0],l[k-1]=l[k-1],l[0]
        l[k-2],l[k-1]=l[k-1],l[k-2]
    else:
        l[0],l[k]=l[k],l[0]
    for i in range(n//2):
        print(l[i],l[n-1-i])
"""
"""
t=int(input())
for i in range(t):
    n = input()
    ind=0
    for i in range(1,len(n)-1):
        if (int(n[i])+int(n[i+1])>9):
            ind=i
    print(n[:ind]+str(int(n[ind])+int(n[ind+1]))+n[ind+2:])
"""
"""
for _ in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    s=input()
    d={}
    g,p=[],[]
    for i in range(n):
        if s[i]=='0':
            p.append(l[i])
        else:
            g.append(l[i])
    p.sort()
    g.sort()
    p.extend(g) 
    k=1
    for i in p:
        d[i]=k
        k+=1
    for i in l:
        print(d[i],end=' ')
    print()
"""
"""
from collections import Counter
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    rem = Counter(a)
    c = set()
    ans = []
    mex = 0
    for i in range(n):
        c.add(a[i])
        while mex in c:
            mex += 1
        if rem[mex] == 0:
            ans.append(mex)
            c.clear()
            mex = 0
        rem[a[i]] -= 1
    print(len(ans))
    print(*ans)
"""
"""
t=int(input())
for i in range(t):
    n=int(input())
    mt = [int(n) for n in input().split()]
    h = [int(n) for n in input().split()]
    ans=[]
    for i in range(1,h[0]+1):
        ans.append(i)

    for i in range(1,n):
        if mt[i]-mt[i-1]==1 and h[i]==1:
            ans.append(1)
        elif mt[i]-mt[i-1]==1 and h[i]>1:
            ans.append(h[i-1]+1)
        elif mt[i] - mt[i - 1] > 1 and h[i] == 1:
            ans.append(1)
        elif mt[i] - mt[i - 1] > 1 and h[i]>1 and  mt[i] - mt[i - 1]== h[i]-h[i-1]:
            for j in range(h[i-1]+1,h[i]+1):
                ans.append(j)
        elif mt[i] - mt[i - 1] > 1 and h[i]>1 and  mt[i] - mt[i - 1]!= h[i]-h[i-1]:
            for j in range(1,h[i]+1):
                ans.append(j)
    print(sum(ans))
    print(ans)
"""
"""











//



using namespace std;

int main()
{
    ll t = 1;
     cin >> t;
    while (t--)
    { 
     ll n;
     cin >> n;
     ll a[n];
     ll result=0;
   //  vector<ll> 
   bool f=true;
     for (ll i = 0; i < n; i++)
     {
        cin >> a[i];
        if(i>0&&i<n-1)
        {
            if(a[i]!=1){ f=false;
           }
        result += ((a[i]+1)/2);
        }
     }
     if(n==3)
     {
         if(a[1]%2==0)
         {
              cout << result << endl;
            
         }else
         {
             cout << -1<<endl;
         }
     }else if(!f){
          cout << result << endl;
         
     }else{
         cout << -1<<endl;
     }
    }
    return 0;
    }
"""
"""
t=int(input())
for i in range(t):
    w,h=map(int,input().split())
    ans=0
    for i in range(4):
        a = [int(n) for n in input().split()]
        ans=max(ans,(a[-1]-a[1])*(h if i<2 else w))
    print(ans)
"""
"""
import sys
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    eve=sys.maxsize
    odd=sys.maxsize
    flag=True
    for i in range(n-1,-1,-1):
        if l[i]%2==1:
            if eve<l[i]:
             flag=False
            else:
                eve=l[i]
        else:
            if odd<l[i]:
                flag=False
            else:
                odd=l[i]
    if flag:
        print("YES")
    else:
        print("NO")
"""
"""
t = int(input())
for _ in range(t):
    n,k = map(int, input().split())
    if k==1:
        print("YES")
        for i in range(n):
            print(i+1)
    elif n%2!=0:
        print("NO")
    else:
        print("YES")
        for i in range(1, n + 1):
            for j in range(k):
                print(i + n * j, end=" ")
            print()

"""
"""
import sys;input=sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    eve=[i for i in l if i%2==0]
    odd = [i for i in l if i % 2 != 0]
    print("YES" if eve==sorted(eve) and odd==sorted(odd) else "NO")
"""
"""
def solve(a,s):
    j = len(s) - 1
    b = ''
    for i in range(len(a) - 1, -1, -1):
        if j < 0:
            return ("-1")
        elif s[j] >= a[i]:
            b += str(int(s[j]) - int(a[i]))
            j -= 1
        elif j == 0 or s[j - 1] != '1':
            return ("-1")
        else:
            b += str(int(s[j - 1:j + 1]) - int(a[i]))
            j -= 2
    if j >= 0:
        b += s[:j + 1][::-1]
    return (str(int(b[::-1])))
"""
"""
def solve():
    n = int(input())
    
    a = map(int, input().split())
    
    s = input()
    x = sorted(zip(s, a))
    flag = 0
    for i, (color, num) in enumerate(x, 1):
        if color == 'B' and i > num or color == 'R' and i < num:
            return "NO"
    return "Yes"
"""
"""
    if len(s) == 1 or s[0] == s[1]: print(s[0] + s[0]); continue
    i=1
    while i<n and s[i]<=s[i-1]:
        i+=1
    print(s[:i]+s[i-1::-1])
"""
"""
a=[]
    f=False
    for i in range(n):
        a.append(list(map(int, input().split())))
    for i in range(5):
        for j in range(i+1,5):
            p=q=r=0
            for k in range(n):
                p+=(a[k][i]==1)
                q+=(a[k][j]==1)
                r+=(a[k][j]==1 and a[k][i]==1)
            p-=r
            q-=r
            if p<=n//2 and q<=n/2 and p+q+r==n:
                f=True
    print("YES" if f else "NO")
"""
"""
from collections import defaultdict

t = int(input())
for _ in range(t):
    n, x = map(int, input().split())
    a = list(sorted(map(int, input().split())))
    need = defaultdict(int)
    for y in a:
        if need[y]:
            need[y] -= 1
        else:
            need[x * y] += 1
    print(sum(need.values()))
"""
import sys
input=sys.stdin.readline
n,q= map(int, input().split())
a = dict(enumerate(map(int, input().split())))
s=sum(a.values())
default=0
for _ in range(q):
    b=list(map(int, input().split()))
    t = b[0]
    if t==1:
        s-=a.get(b[1]-1,default)
        s+=b[2]
        a[b[1] - 1] = b[2]
    elif t==2:
        s = n*b[1]
        a={}
        default=b[1]
    print(s)