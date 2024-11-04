'''
def main():
    from sys import stdin,stdout
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    from math import ceil
    n,m,a=map(int,stdin.readline().split())
    stdout.write(str(ceil(n/a)*ceil(m/a)))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    i=int(stdin.readline())
    if i&1:
        stdout.write('NO\n')
    else:
        if i//2 >1:
            stdout.write('YES\n')
        else:
            stdout.write('NO\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    for _ in range(int(stdin.readline())):
        s=stdin.readline().strip()
        if len(s) <=10:
            stdout.write(s+'\n')
        else:
            stdout.write(s[0]+str(len(s[1:-1]))+s[-1]+'\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,k=map(int,stdin.readline().split())
    a=list(map(int,stdin.readline().split()))
    count=0
    for i in range(n):
        if a[i] and a[i]>=a[k-1]:
            count+=1
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    t=''
    s=s.lower()
    for i in s:
        if i not in 'aeiouy':
            t+='.'+i
    stdout.write(t)
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    stdout.write(str((n*m)//2))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    count=0
    for _ in range(int(stdin.readline())):
        if sum(list(map(int,stdin.readline().split())))>=2:
            count+=1
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    x=0
    for _ in range(int(stdin.readline())):
        s=stdin.readline().strip()
        if '++' in s:
            x+=1
        elif '--' in s:
            x-=1
    stdout.write(str(x))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    l=sorted(list(map(int,stdin.readline().split())))
    counter=l.count(4)
    l=l[:n-counter]
    i=0
    while len(l):
        if len(l)==1:
            counter+=1
            break
        
    stdout.write(str(counter))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    count=1
    flag=0
    for i in range(1,len(s)):
        if s[i]==s[i-1]:
            count+=1
            if count >=7:
                flag=1
                break
        else:
            count=1
    if flag:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    maxim=0
    total=0
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        total+=(b-a)
        if total >maxim:
            maxim=total
    stdout.write(str(maxim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip().lower()
    t=stdin.readline().strip().lower()
    if s==t:
        stdout.write('0')
    elif s < t:
        stdout.write('-1')
    else:
        stdout.write('1')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    l=list(map(str,stdin.readline().strip().split('+')))
    l.sort()
    stdout.write('+'.join(l))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    if s.isupper():
        stdout.write(s.lower())
    elif (s[0].islower() and s[1:].isupper()) or (len(s)==1 and s.islower()):
        stdout.write(s.title())
    else:
        stdout.write(s)
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    count=0
    s=stdin.readline().strip()
    for i in range(1,n):
        if s[i]==s[i-1]:
            count+=1
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    if 'H' in s or 'Q' in s or '9' in s:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    stdout.write(s[0].upper()+s[1:])
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    test='hello'
    s=stdin.readline().strip()
    while len(test) and len(s):
        if test[0]==s[0]:
            test=test[1:]
            s=s[1:]
        else:
            s=s[1:]
    if test=='':
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    if len(set(stdin.readline().strip())) & 1:
        stdout.write('IGNORE HIM!')
    else:
        stdout.write('CHAT WITH HER!')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    count=0
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        if b-a>=2:
            count+=1
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    k=int(stdin.readline())
    l=int(stdin.readline())
    m=int(stdin.readline())
    n=int(stdin.readline())
    d=int(stdin.readline())
    count=0
    for i in range(1,d+1):
        if i % k and i % l and i % m and i % n:
            count+=1
    stdout.write(str(d-count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    for i in range(5):
        a=list(map(int,stdin.readline().split()))
        try:
            x=a.index(1)+1
            y=i+1
        except:
            g=''
    stdout.write(str(abs(x-3)+abs(y-3)))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    k,n,w=map(int,stdin.readline().split())
    m=(w*(w+1)*k)//2
    if m<=n:
        stdout.write('0')
    else:
        stdout.write(str(m-n))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    l=list(map(int,stdin.readline().split()))
    p=[0 for _ in range(n)]
    for i in range(n):
        p[l[i]-1]=i+1
    stdout.write(' '.join(str(x) for x in p))
if __name__=='__main__':
    main()
'''

'''
def main():
    l=[]
    for i in range(4,1001):
        s=str(i)
        flag=1
        for element in s:
            if element !='4' and element !='7':
                flag=0
                break
        if flag:
            l.append(i)
    from sys import stdin,stdout
    n=int(stdin.readline())
    for i in l:
        if n%i==0:
            stdout.write('YES')
            return
    stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,x=map(int,stdin.readline().split())
    s=stdin.readline().strip()
    for _ in range(x):
        s=s.replace('BG','GB')
    stdout.write(s)
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    n+=1
    while True:
        if len(str(n))==len(set(str(n))):
            break
        else:
            n+=1
    stdout.write(str(n))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a=stdin.readline().strip()
    b=stdin.readline().strip()
    if a==b[-1::-1]:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    l=sorted(list(map(int,stdin.readline().split())))
    p=l[-1]
    lsum=sum(l[:-1])
    l=l[:-1]
    count=1
    while lsum >= p:
        p+=l[-1]
        lsum-=l[-1]
        l=l[:-1]
        count+=1
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    k=s.count('4')+s.count('7')
    if  k==4 or k==7:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    stdout.write(str(int(stdin.readline())+1))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    count=0
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        count+=(b-a)
    stdout.write(str(count))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,q=map(int,stdin.readline().split())
    l=sorted(list(map(int,stdin.readline().split())))
    o=[]
    for i in range(n):
        o.append(0)
    while q:
        a,b=map(str,stdin.readline().split())
        if a =='in':
            b=int(b)
            flag=0
            for i in range(n):
                if b<=l[i] and o[i]==0:
                    o[i]=1
                    flag=1
                    break
            if flag:
                stdout.write(str(i+1)+'\n')
            else:
                stdout.write('-1\n')
        else:
            b=int(b)-1
            o[b]=0
        q-=1
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin, stdout
    n=int(stdin.readline())
    while n>5:
        if n&1:
            n-=5
            n//=2
        else:
            n-=4
            n//=2
    if n==1:
        stdout.write('Sheldon')
    elif n==2:
        stdout.write('Leonard')
    elif n==3:
        stdout.write('Penny')
    elif n==4:
        stdout.write('Rajesh')
    else:
        stdout.write('Howard')
if __name__=='__main__':
    main()
'''

'''
WA
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    counter=n
    while n>=m:
        counter+=n//m
        n//=m
    stdout.write(str(counter))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a=int(stdin.readline())
    b=int(stdin.readline())
    c=int(stdin.readline())
    maxim=a*b*c
    if a+b+c > maxim:
        maxim=a+b+c
    if (a+b)*c >maxim:
        maxim=(a+b)*c
    if a*(b+c)>maxim:
        maxim=a*(b+c)
    if a+b*c > maxim:
        maxim=a+b*c
    stdout.write(str(maxim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a,b,c=0,0,0
    for _ in range(int(stdin.readline())):
        x,y,z=map(int,stdin.readline().split())
        a+=x
        b+=y
        c+=z
    if a or b or c:
        stdout.write('NO')
    else:
        stdout.write('YES')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    l=list(map(int,stdin.readline().split()))
    max_so_far=1
    counter=1
    for i in range(1,n):
        if l[i]>=l[i-1]:
            counter+=1
        else:
            max_so_far=max(max_so_far,counter)
            counter=1
    stdout.write(str(max(max_so_far,counter)))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    li=sorted(list(map(int,stdin.readline().split())))
    minim=100000
    for i in range(m-n+1):
        sub=li[i:i+n]
        d=0
        for i in range(1,len(sub)):
            d+=sub[i]-sub[i-1]
        minim=min(minim,d)
    stdout.write(str(minim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    from math import floor,sqrt
    def check(n):
        if n==2:
            return True
        elif n & 1:
            for i in range(3,floor(sqrt(n))+1):
                if n % i==0:
                    return False
            return True
        else:
            return False
    n=int(stdin.readline())
    i=4
    while True:
        #print(check(i),check(n-i))
        if check(n-i) or check(i):
            i+=1
            continue
        else:
            stdout.write(str(i)+' '+str(n-i))
            break
if __name__=='__main__':
    main()
'''

'''
def main():
    def gcd(a,b):
        if b:
            return gcd(b,a%b)
        else:
            return a
    from sys import stdin,stdout
    a,b,n=map(int,stdin.readline().split())
    flag=0
    while n > 0:
        if flag:
            n-=gcd(n,b)
            flag=0
        else:
            n-=gcd(n,a)
            flag=1
    if flag:
        stdout.write('0')
    else:
        stdout.write('1')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a,b=map(int,stdin.readline().split())
    if a==1 or b==1:
        stdout.write('Akshat')
    elif min(a,b)**2 & 1:
        stdout.write('Akshat')
    else:
        stdout.write('Malvika')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a,b=map(int,stdin.readline().split())
    counter=a
    while a:
        counter+=a//b
        if a > b:
            d=a%b
        else:
            d=0
        a=(a+d)//b
    stdout.write(str(counter))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    stdout.write(s.replace('WUB',' ').strip())
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    t=tuple(map(int,stdin.readline().split()))
    maxim=t[0]
    imaxim=0
    minim=t[0]
    iminim=0
    for i in range(1,n):
        if t[i] > maxim:
            maxim=t[i]
            imaxim=i
        if t[i] <=minim:
            minim=t[i]
            iminim=i
    if imaxim > iminim:
        stdout.write(str(imaxim+n-iminim-2))
    else:
        stdout.write(str(imaxim+n-iminim-1))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a=set()
    n=set(range(1,int(stdin.readline())+1))
    for i in range(2):
        a.update(tuple(map(int,stdin.readline().split()))[1:])
    if a==n:
        stdout.write('I become the guy.')
    else:
        stdout.write('Oh, my keyboard!')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    state=''
    counter=0
    for _ in range(int(stdin.readline())):
        s=stdin.readline()
        if s!=state:
            counter+=1
            state=s
    stdout.write(str(counter))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=set(stdin.readline().strip()[1:-1].split(', '))
    if '' in s:
        stdout.write('0')
    else:
        stdout.write(str(len(s)))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    stdout.write(str(4-len(set(map(int,stdin.readline().split())))))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    for i in range(n):
        if (i & 3) & 1 :
            if i & 3 == 1:
                stdout.write('.'*(m-1)+'#\n')
            else:
                stdout.write('#'+'.'*(m-1)+'\n')
        else:
            stdout.write('#'*m+'\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    a=stdin.readline().strip()
    b=stdin.readline().strip()
    s=''
    for i in range(len(a)):
        if a[i]==b[i]:
            s+='0'
        else:
            s+='1'
    stdout.write(s)
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    s=0
    i=0
    while s<=n:
        #print(i,s,n)
        s+=((i+2)*(i+1))//2
        i+=1
    stdout.write(str(i-1))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    from math import ceil
    stdout.write(str(ceil(int(stdin.readline())/5)))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    if n<0:
        n*=-1
        b=n//10
        a=(b//10)*10+n%10
        if a<b:
            if a:
                stdout.write('-'+str(a))
            else:
                stdout.write('0')
        else:
            if b:
                stdout.write('-'+str(b))
            else:
                stdout.write('0')
    else:
        stdout.write(str(n))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    from math import ceil
    a=sum(map(int,stdin.readline().split()))
    b=sum(map(int,stdin.readline().split()))
    c=int(stdin.readline())
    counter=0
    if a:
        counter+=1
        counter+=ceil(a/5)-1
    if b:
        counter+=1
        counter+=ceil(b/10)-1
    if counter <= c:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    score={'q':9,'r':5,'b':3,'n':3,'p':1,'k':0}
    white=0
    dark=0
    for _ in range(8):
        for i in stdin.readline().strip():
            if i=='.':
                continue
            else:
                if i in 'qrbnpk':
                    dark+=score[i]
                else:
                    white+=score[i.lower()]
    if white>dark:
        stdout.write('White')
    elif white==dark:
        stdout.write('Draw')
    else:
        stdout.write('Black')
if __name__=='__main__':
    main()
'''
'''
WA
#556A
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    s=stdin.readline().strip()
    if s.count('0')==n or s.count('1')==n:
        stdout.write(str(n))
        return
    c=0
    while c!=n:
        c=n
        s=s.replace('01','',len(s))
        s=s.replace('10','',len(s))
        n=len(s)
    stdout.write(str(len(s)))
if __name__=='__main__':
    main()
'''
'''
#486A
def main():
    from sys import stdin,stdout
    from math import ceil
    n=int(stdin.readline())
    result=ceil(n/2)
    n//=2
    stdout.write(str(n*(n+1)-result*result))
if __name__=='__main__':
    main()
'''
'''
#230A
def main():
    from sys import stdin,stdout
    dic={}
    s,n=map(int,stdin.readline().split())
    while n:
        a,b=map(int,stdin.readline().split())
        dic[a]=dic.get(a,0)+b
        n-=1
    flag=1
    for key in sorted(dic.keys()):
        if s<=key:
            flag=0
            break
        else:
            s+=dic[key]
    if flag:
        stdout.write('YES')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    tup=tuple(map(int,stdin.readline().split()))
    x=1
    w=0
    for i in range(m):
        if tup[i]>=x:
           w+=tup[i]-x
           x=tup[i]
        else:
            w+=(n-x)+tup[i]
            x=tup[i]
    stdout.write(str(w))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    l=[]
    tup=sorted(list(map(int,stdin.readline().split())))
    for _ in range(2):
        t=sorted(list(map(int,stdin.readline().split())))
        for i in range(len(tup)):
            if i<len(t):
                if tup[i]!=t[i]:
                    l.append(tup[i])
                    break
            else:
                l.append(tup[i])
        tup=t.copy()
    for i in l:
        stdout.write(str(i)+'\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    l=[]
    for _ in range(n):
        l.append(0)
    for _ in range(m):
        line=tuple(map(int,stdin.readline().split()))
        l[line.index(max(line))]+=1
    stdout.write(str(l.index(max(l))+1))
if __name__=='__main__':
    main()
'''

'''
WA
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    counter=0
    pcount=0
    for i in stdin.readline().strip().split():
        if int(i)>0:
            if pcount>=10:
                continue
            else:
                if pcount + int(i)>10:
                    pcount=10
                else:
                    pcount+=int(i)
        else:
            if pcount>0:
                pcount-=1
            else:
                counter+=1
    stdout.write(str(counter))
if __name__=='__main__':
    main()
'''

def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    t=tuple(map(int,stdin.readline().split()))
    dic={}
    asum=0
    for i in t:
        for j in range(32):
            x=(1<<j)-i
            if x in dic:
                asum+=dic[x]
        if i not in dic:
            dic[i]=1
        else:
            dic[i]+=1
    stdout.write(str(asum))
if __name__=='__main__':
    main()
