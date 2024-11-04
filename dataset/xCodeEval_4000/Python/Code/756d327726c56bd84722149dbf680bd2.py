'''
def main():
    from sys import stdin,stdout
if __name__=='__main__':
    main()
'''

'''
def main():
    import sys
    a,b=map(int,sys.stdin.readline().split())
    if a>b:
        if a-b==1:
            s=''
            for i in range(a+b):
                if i&1:
                    s+='1'
                else:
                    s+='0'
        else:
            s='-1'
    elif b>a:
        if b<=2*(a+1):
            s=''
            if b-a==1:
                for i in range(a+b):
                    if i&1:
                        s+='0'
                    else:
                        s+='1'
            else:
                n=b-a-1
                i=0
                flag=0
                while i<a+b:
                    if flag&1:
                        s+='0'
                    else:
                        if n:
                            s+='11'
                            n-=1
                            i+=1
                        else:
                            s+='1'
                    i+=1
                    flag=~flag
        else:
            s='-1'
    else:
        s=''
        for i in range(a+b):
            if i&1:
                s+='1'
            else:
                s+='0'
    sys.stdout.write(s)
if __name__=='__main__':
    main()
'''

'''
def main():
    import sys
    n=sys.stdin.readline().strip()
    lodd=int(n[-1])
    odd=0
    even=0
    s=''
    j=0
    for i in n:
        if ord(i)&1:
            odd+=1
        else:
            even+=1
            feven=int(i)
            feindex=j
            if(feven<lodd):
                break
        j+=1
    if even:
        for i in range(len(n)):
            if i==feindex:
                sys.stdout.write(n[-1])
            elif i==len(n)-1:
                sys.stdout.write(str(feven))
            else:
                sys.stdout.write(n[i])
    else:
        sys.stdout.write('-1')
if __name__=='__main__':
    main()
'''

'''
def main():
    import sys
    s=sys.stdin.readline().strip()
    n=int(sys.stdin.readline())
    tup=tuple(map(int,sys.stdin.readline().split()))
    maxim=max(tup)
    score=0
    for i in range(len(s)):
        score+=(i+1)*tup[ord(s[i])-97]
    d=n*(2*len(s)+n+1)//2
    score+=maxim*d
    sys.stdout.write(str(score))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    from math import ceil,sqrt
    def sqr(a):
        return a*a
    r,x,y,a,b=map(int,stdin.readline().split())
    mid=((x+a)/2,(y+b)/2)
    #print(mid)
    dis=sqrt(sqr(x-mid[0])+sqr(y-mid[1]))
    #print(dis)
    n=ceil(dis/r)
    stdout.write(str(n)+'\n')
if __name__=='__main__':
    main()
'''


'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    tup=tuple(map(int,stdin.readline().split()))
    minim=min(tup)
    maxim=max(tup)
    maximindex=tup.index(maxim)
    flag=1
    i=0
    pv=tup[-1]
    while i<n:
        if tup[i]<pv:
            if tup[i]==minim and pv==maxim:
                l=i+1
                while l<max(maximindex,n):
                    if tup[l]<tup[l-1]:
                        flag=0
                        break
                    l+=1
                break
            else:
                flag=0
                break
        pv=tup[i]
        i+=1
    #print(i)
    if flag:
        if i:
            stdout.write(str(n-i))
        else:
            stdout.write('0')
    else:
        stdout.write('-1')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    MOD=int(1e9)+7
    x,y=map(int,stdin.readline().split())
    n=(int(stdin.readline())-1)%6
    tup=(x,y,y-x,-x,-y,x-y)
    stdout.write(str(tup[n]%MOD))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n=int(stdin.readline())
    ksum=n
    for i in range(n):
        x=int(stdin.readline())
        if i:
            if x<p:
                ksum+=1+(p-x)
                p=x
            else:
                ksum+=(1+x-p)
                p=x
        else:
            ksum+=x
            p=x
    stdout.write(str(ksum))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import collections
    s=stdin.readline().strip()
    t=stdin.readline().strip()
    if set(t).issubset(set(s)) and len(t)<=len(s):
        sp=0
        tp=0
        sc=collections.Counter(s)
        tc=collections.Counter(t)
        while sp<len(s) and tp<len(t):
            if s[sp]==t[tp]:
                tp+=1
                sp+=1
            else:
                sp+=1
        if tp==len(t):
            stdout.write('automaton')
        else:
            if len(t)==len(s):
                if sc!=tc:
                    stdout.write('need tree')
                else:
                    stdout.write('array')
            else:
                flag=1
                for i in sc:
                    if sc[i]<tc[i]:
                        flag=0
                if flag:
                    stdout.write('both')
                else:
                    stdout.write('need tree')
    else:
        stdout.write('need tree')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import collections
    myDic=collections.defaultdict(set)
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        myDic[a].add(b)
    maxim=min(myDic[min(myDic)])
    for i in sorted(myDic):
        tmpmin=min(myDic[i])
        tmpmax=max(myDic[i])
        if tmpmin>=maxim:
            maxim=tmpmax
        else:
            maxim=i
    stdout.write(str(maxim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import collections
    n=int(stdin.readline())
    tup=tuple(map(int,stdin.readline().split()))
    maxim=max(tup)
    cnt=collections.Counter(tup)
    f=[0,cnt[1]]
    for i in range(2,maxim+1):
        f.append(max(f[i-1],f[i-2]+cnt[i]*i))
    stdout.write(str(f[maxim]))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,k,l,c,d,p,nl,np=map(int,stdin.readline().split())
    stdout.write(str(min((k*l//nl,c*d,p//np))//n))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    tup=()
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        counter=0
        for i in range(a-1,b-1):
            if s[i]==s[i+1]:
                counter+=1
        tup+=(counter,)
    for i in tup:
        stdout.write(str(i)+'\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    x,a,b=map(int,stdin.readline().split())
    c,y,d=map(int,stdin.readline().split())
    e,f,z=map(int,stdin.readline().split())
    x=(2*b+d-c)//2
    z=b+e-x
    y=x+c+e-f-a
    stdout.write(str(x)+' '+str(a)+' '+str(b)+'\n')
    stdout.write(str(c)+' '+str(y)+' '+str(d)+'\n')
    stdout.write(str(e)+' '+str(f)+' '+str(z))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m,k=map(int,stdin.readline().split())
    x,s=map(int,stdin.readline().split())
    a=tuple(map(int,stdin.readline().split()))
    b=tuple(map(int,stdin.readline().split()))
    c=tuple(map(int,stdin.readline().split()))
    d=tuple(map(int,stdin.readline().split()))
    bDic={}
    for i in range(m):
        bDic[a[i]]=min(bDic.get(a[i],1e10),b[i])
    dDic={}
    for i in range(k):
        dDic[c[i]]=min(dDic.get(c[i],1e10),d[i])
    t=0
    for i in sorted(dDic.keys(),reverse=True):
        if dDic[i]<=s:
            n-=i
            s-=dDic[i]
            break
    #print(n,s)
    if n>0:
        if s:
            for i in sorted(bDic.keys()):
                if bDic[i]<=s:
                    x=i
                    break
        t=n*x
    stdout.write(str(t))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    arr=[]
    for _ in range(n):
        arr.append(list(map(int,stdin.readline().split())))
    flag1=False
    flag2=False
    for i in range(n):
        if any(arr[i]):
            flag1=True
        if all(arr[i]):
            for j in range(m):
                flag=True
                for k in range(n):
                    flag&=arr[k][j]
                if flag:
                    break
            if flag:
                flag2=True
    if not(flag1 ^ flag2):
        stdout.write('YES\n')
        for i in range(n):
            for j in range(m):
                a=int(all(arr[i]))
                b=1
                for k in range(n):
                    b&=arr[k][j]
                stdout.write(str(int(a and b))+' ')
            stdout.write('\n')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import collections
    n,m,k=map(int,stdin.readline().split())
    x,s=map(int,stdin.readline().split())
    a=list(map(int,stdin.readline().split()))
    b=list(map(int,stdin.readline().split()))
    c=list(map(int,stdin.readline().split()))
    d=list(map(int,stdin.readline().split()))
    myDica=collections.defaultdict(set)
    myDicb=collections.defaultdict(set)
    for i in range(m):
        myDica[a[i]].add(b[i])
    alist=sorted(myDica)
    for i in range(k):
        myDicb[d[i]].add(c[i])
    myDicA={}
    myDicB={}
    for i in myDica:
        myDicA[i]=min(myDica[i])
    for i in myDicb:
        myDicB[i]=max(myDicb[i])
    minim=x*n
    flag=1
    #print(alist,myDicA,myDicB,minim)
    for i in myDicB:
        if i<=s:
            d1=s-i
            d2=n-myDicB[i]
            if d2<=0:
                minim=0
                break
            else:
                for j in range(m):
                    if myDicA[alist[j]]<=d1:
                        minim=min(minim,d2*alist[j])
                        break
        elif flag:
            for j in range(m):
                if myDicA[alist[j]]<=s:
                    minim=min(minim,n*alist[j])
                    break
            flag=0
    stdout.write(str(minim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    r,g,b=map(int,stdin.readline().split())
    if all((r,g,b)):
        minim=(r+g+b)//3
    else:
        minim=0
        l=list(filter(lambda x: x,(r,g,b)))
        if len(l)==2:
            n=(l[0]+l[1])//3
            if n <=min(l[0],l[1]):
                minim+=n
            else:
                minim+=min(l[0],l[1])
    stdout.write(str(minim))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import bisect
    n,m,k=map(int,stdin.readline().split())
    x,s=map(int,stdin.readline().split())
    a=tuple(map(int,stdin.readline().split()))
    b=tuple(map(int,stdin.readline().split()))
    c=tuple(map(int,stdin.readline().split()))
    d=tuple(map(int,stdin.readline().split()))
    myDic={}
    time=n*x
    for i in range(m):
        myDic[b[i]]=max(myDic.get(b[i],0),a[i])
    index=bisect.bisect_left(d,s)
    alist=sorted(myDic)
    #print(index)
    if index:
        for i in range(index):
            d1=s-d[i]
            d2=n-c[i]
            time=min(time,x*d2)
            index2=bisect.bisect_left(alist,d1)
            for j in range(index2):
                time=min(time,d2*myDic[alist[j]])
    else:
        for i in range(bisect.bisect_left(alist,s)):
            time=min(time,n*myDic[alist[i]])
    stdout.write(str(time))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    import bisect
    n,m,k=map(int,stdin.readline().split())
    x,s=map(int,stdin.readline().split())
    a=tuple(map(int,stdin.readline().split()))
    b=tuple(map(int,stdin.readline().split()))
    c=tuple(map(int,stdin.readline().split()))
    d=tuple(map(int,stdin.readline().split()))
    myDic={}
    for i in range(k):
        myDic[d[i]]=max(myDic.get(d[i],0),c[i])
    time=n*x
    for i in range(m):
        if b[i]<=s:
            index=bisect.bisect_left(d,s-b[i])
            if index:
                reduced=n-myDic[d[index-1]]
            else:
                reduced=n
            if index<k:
                if d[index]==s-b[i]:
                    reduced=n-myDic[d[index]]
            time=min(time,a[i]*reduced)
    for j in myDic:
        if j<=s:
            time=min(time,(n-myDic[j])*x)
    if time<0:
        time=0
    stdout.write(str(time))
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    s=stdin.readline().strip()
    l=[0]
    for i in range(1,len(s)):
        l.append(l[i-1]+(s[i-1]==s[i]))
    #print(l)
    ans=()
    for _ in range(int(stdin.readline())):
        a,b=map(int,stdin.readline().split())
        a-=1
        b-=1
        ans+=(l[b]-l[a],)
    for i in ans:
        stdout.write(str(i)+'\n')
if __name__=='__main__':
    main()
'''

'''
def main():
    from sys import stdin,stdout
    n,m=map(int,stdin.readline().split())
    b=[]
    for _ in  range(n):
        b.append(list(map(int,stdin.readline().split())))
    col=[]
    row=[]
    for i in range(n):
        col.append(all(b[i]))
    for j in range(m):
        x=1
        for k in range(n):
            x&=b[k][j]
        row.append(x)
    a=[]
    for i in range(n):
        sub=[]
        for j in range(m):
            sub.append(col[i]&row[j])
        a.append(sub)
    row=[]
    col=[]
    for i in range(n):
        row.append(any(a[i]))
    for i in range(m):
        x=0
        for j in range(n):
            x|=a[j][i]
        col.append(x)
    b_new=[]
    for i in range(n):
        sub=[]
        for j in range(m):
            sub.append(row[i]|col[j])
        b_new.append(sub)
    #print(a)
    #print(b)
    #print(b_new)
    if b==b_new:
        stdout.write('YES\n')
        for i in range(n):
            for j in range(m):
                stdout.write(str(a[i][j])+' ')
            stdout.write('\n')
    else:
        stdout.write('NO')
if __name__=='__main__':
    main()
'''

def main():
    from sys import stdin,stdout
    import collections
    n=int(stdin.readline())
    home=list(n-1 for x in range(n))
    away=list(n-1 for x in range(n))
    team=[]
    homeDic=collections.Counter()
    awayDic=collections.Counter()
    for _ in range(n):
        a,b=map(int,stdin.readline().split())
        homeDic[a]+=1
        awayDic[b]+=1
        team.append((a,b))
    for i in range(n):
        d=homeDic[team[i][1]]
        home[i]+=d
        away[i]-=d
    for i in range(n):
        stdout.write(str(home[i])+' '+str(away[i])+'\n')
if __name__=='__main__':
    main()
