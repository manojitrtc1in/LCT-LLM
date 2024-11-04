import sys,bisect,string,math,time,functools,random,fractions
from heapq import heappush,heappop,heapify
from collections import deque,defaultdict,Counter
from itertools import permutations,combinations,groupby
rep=range
def Golf():n,*t=map(int,open(0).read().split())
def I():return int(input())
def S_():return input()
def IS():return input().split()
def LS():return [i for i in input().split()]
def MI():return map(int,input().split())
def LI():return [int(i) for i in input().split()]
def LI_():return [int(i)-1 for i in input().split()]
def NI(n):return [int(input()) for i in range(n)]
def NI_(n):return [int(input())-1 for i in range(n)]
def StoLI():return [ord(i)-97 for i in input()]
def ItoS(n):return chr(n+97)
def id3(ls):return ''.join([chr(i+97) for i in ls])
def RA():return map(int,open(0).read().split())
def GI(V,E,ls=None,Directed=False,index=1):
    id9=[];g=[[] for i in range(V)]
    id25=True if ls==None else False
    for i in range(E):
        if id25:
            inp=LI()
            id9.append(inp)
        else:
            inp=ls[i]
        if len(inp)==2:
            a,b=inp;c=1
        else:
            a,b,c=inp
        if index==1:a-=1;b-=1
        aa=(a,c);bb=(b,c);g[a].append(bb)
        if not Directed:g[b].append(aa)
    return g,id9
def GGI(h,w,search=None,id16='.',mp_def={'
    
    mp=[boundary]*(w+2);found={}
    for i in range(h):
        s=input()
        for char in search:
            if char in s:
                found[char]=((i+1)*(w+2)+s.index(char)+1)
                mp_def[char]=mp_def[id16]
        mp+=[boundary]+[mp_def[j] for j in s]+[boundary]
    mp+=[boundary]*(w+2)
    return h+2,w+2,mp,found
def TI(n):return GI(n,n-1)
def accum(ls):
    rt=[0]
    for i in ls:rt+=[rt[-1]+i]
    return rt
def bit_combination(n,base=2):
    rt=[]
    for tb in range(base**n):s=[tb//(base**bt)%base for bt in range(n)];rt+=[s]
    return rt
def gcd(x,y):
    if y==0:return x
    if x%y==0:return y
    while x%y!=0:x,y=y,x%y
    return y
def YN(x):print(['NO','YES'][x])
def Yn(x):print(['No','Yes'][x])
def show(*inp,end='\n'):
    if id13:print(*inp,end=end)

mo=10**9+7
inf=float('inf')
FourNb=[(-1,0),(1,0),(0,1),(0,-1)];EightNb=[(-1,0),(1,0),(0,1),(0,-1),(1,1),(-1,-1),(1,-1),(-1,1)];compas=dict(zip('WENS',FourNb));id17=dict(zip('LRUD',FourNb))
id18=string.ascii_lowercase

read=sys.stdin.buffer.read
readline=sys.stdin.buffer.readline
input=lambda: sys.stdin.readline().rstrip()

class Tree:
    def __init__(self,inp_size=None,ls=None,init=True,index=1):
        self.LCA_init_stat=False
        self.ETtable=[]
        if init:
            if ls==None:
                self.stdin(inp_size,index=index)
            else:
                self.node_size=len(ls)+1
                self.edges,_=GI(self.node_size,self.node_size-1,ls,index=index)
        return
 
    def stdin(self,inp_size=None,index=1):
        if inp_size==None:
            self.node_size=int(input())
        else:
            self.node_size=inp_size
        self.edges,_=GI(self.node_size,self.node_size-1,index=index)
        return
    
    def listin(self,ls,index=0):
        self.node_size=len(ls)+1
        self.edges,_=GI(self.node_size,self.node_size-1,ls,index=index)
        return
 
    def dfs(self,x,func=lambda pr,prv,nx,dist:prv+dist,root_v=0):
        q=deque([x])
        v=[None]*self.node_size
        v[x]=root_v
        while q:
            c=q.pop()
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=func(c,v[c],nb,d)
        return v
 
    def bfs(self,x,func=lambda pr,prv,nx,dist:prv+dist,root_v=0):
        q=deque([x])
        v=[None]*self.node_size
        v[x]=root_v
        while q:
            c=q.popleft()
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=func(c,v[c],nb,d)
        return v
 
    def parent(self,x):
        return self.dfs(0,func=lambda pr,prv,nx,dist:pr,root_v=-1)
 
    def id6(self,x):  
        tps=[]
        q=deque([x])
        v=[None]*self.node_size
        v[x]=0
        while q:
            c=q.popleft()
            tps.append(c)
            for nb,d in self.edges[c]:
                if v[nb]==None:
                    q.append(nb)
                    v[nb]=0
        return tps
 
    def EulerTour(self,x):
        q=deque()
        q.append(x)
        self.depth=[None]*self.node_size
        self.depth[x]=0
        self.ETtable=[]
        self.ETdepth=[]
        self.ETin=[-1]*self.node_size
        self.ETout=[-1]*self.node_size
        cnt=0
        while q:
            c=q.pop()
            if c<0:
                ce=~c
            else:
                ce=c
                for nb,d in self.edges[ce]:
                    if self.depth[nb]==None:
                        q.append(~ce)
                        q.append(nb)
                        self.depth[nb]=self.depth[ce]+1
            self.ETtable.append(ce)
            self.ETdepth.append(self.depth[ce])
            if self.ETin[ce]==-1:
                self.ETin[ce]=cnt
            else:
                self.ETout[ce]=cnt
            cnt+=1
        return
    
    def id23(self,root):
        self.EulerTour(root)
        self.st=SparseTable(self.ETdepth,init_func=min,id15=inf)
        
        self.LCA_init_stat=True
        return
    
    def LCA(self,root,x,y):
        if self.LCA_init_stat==False:
            self.id23(root)
        xin,xout=self.ETin[x],self.ETout[x]
        yin,yout=self.ETin[y],self.ETout[y]
        a=min(xin,yin)
        b=max(xout,yout,xin,yin)
        id24=self.st.query_id(a,b+1)
        return self.ETtable[id24]
 
    def id8(self):
        return  str(self.edges)
 
    def show(self):
        if all([all([d==1 for nd,d in e]) for e in self.edges]):
            print( [[nd for nd,d in e] for e in self.edges] )
        else:
            print(self)

class SparseTable: 
    def __init__(self,ls,init_func=min,id15=float('inf')):
        self.func=init_func
        self.idl=id15
        self.size=len(ls)
        self.N0=self.size.bit_length()
        self.table=[ls[:]]
        self.index=[list(range(self.size))]
        self.lg=[0]*(self.size+1)
        
        for i in range(2,self.size+1):
            self.lg[i]=self.lg[i>>1]+1
 
        for i in range(self.N0):
            tmp=[self.func(self.table[i][j],self.table[i][min(j+(1<<i),self.size-1)]) for j in range(self.size)]
            tmp_id=[self.index[i][j] if self.table[i][j]==self.func(self.table[i][j],self.table[i][min(j+(1<<i),self.size-1)]) else self.index[i][min(j+(1<<i),self.size-1)] for j in range(self.size)]
            self.table+=[tmp]
            self.index+=[tmp_id]
    
    
    def query(self,l,r):
        if r>self.size:r=self.size
        
        N=self.lg[r-l]
        return self.func(self.table[N][l],self.table[N][max(0,r-(1<<N))])
    
    
    def query_id(self,l,r):
        if r>self.size:r=self.size
        
        N=self.lg[r-l]
        a,b=self.index[N][l],self.index[N][max(0,r-(1<<N))]
        if self.table[0][a]==self.func(self.table[N][l],self.table[N][max(0,r-(1<<N))]):
            b=a
        return b
    
    
    def right_bound(self,pos,x):
        k=(self.size-pos).bit_length()
        for j in range(k)[::-1]:
            nx=pos+(1<<j)
            if nx<n and self.query(pos,nx+1)<=x:
                pos+=(1<<j)
        return pos
    
    
    def left_bound(self,pos,x):
        k=pos.bit_length()
        for j in range(k)[::-1]:
            nx=pos-(1<<j)
            if 0<=nx and self.query(nx,pos+1)<=x:
                pos-=(1<<j)
        return pos
 
    def id8(self):
        return str(self.table[0])
 
    def print(self):
        for i in self.table:
            print(*i)















class matrix:
    class id4(Exception):
        "mult is not applicable between the two matrices given"
        pass

    def __init__(self,arr_input):
        if hasattr(arr_input[0],"id20"):
            self.arr=arr_input
        else:
            self.arr=[arr_input]
        self.shape=(len(self.arr),len(self.arr[0]))

    def id20(self,key):
        return self.arr[key]

    def id14(self,key,value):
        self.arr[key]=value

    def id26(self):
        return iter(self.arr)
        
    def id1(self,B):
        if type(B)!=matrix:
            return NotImplemented
        if B.shape!=self.shape:
            return NotImplemented
        rt=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[i][j]=self.arr[i][j]+B.arr[i][j]
        return matrix(rt)

    def id21(self,B):
        return self.id1(B)

    def id5(self,B):
        if type(B)!=matrix:
            return NotImplemented
        if B.shape!=self.shape:
            return NotImplemented
        rt=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[i][j]=self.arr[i][j]-B.arr[i][j]
        return matrix(rt)

    def id11(self,B):
        return self.id5(B)

    def id7(self,M):
        if type(M) in [int,float,complex]:
            M=matrix([[M*(i==j) for j in range(self.shape[1])] for i in range(self.shape[1])])
        if type(M)!=matrix:
            return NotImplemented
        if M.shape[0]!=self.shape[1]:
            raise matrix.id4("mult is not applicable between the matrices of shape "+str(self.shape)+" and "+str(M.shape))
        ra,ca=self.shape
        rb,cb=M.shape
        c=[[0]*cb for i in range(ra)]
        for i in range(ra):
            for j in range(cb):
                for k in range(ca):
                    c[i][j]+=self.arr[i][k]*M.arr[k][j]
        return matrix(c)

    def id12(self,M):
        return self.id7(M)

    def id2(self,M):
        if type(M) in [int,float,complex]:
            M=matrix([[M*(i==j) for j in range(self.shape[1])] for i in range(self.shape[1])])
        if type(M)!=matrix:
            return NotImplemented
        if M.shape[0]!=self.shape[1]:
            raise matrix.id4("mult is not applicable between the matrix shape "+str(self.shape)+" and "+str(M.shape))
        ra,ca=M.shape
        rb,cb=self.shape
        c=[[0]*cb for i in range(ra)]
        for i in range(ra):
            for j in range(cb):
                for k in range(ca):
                    c[i][j]+=M.arr[i][k]*self.arr[k][j]
        return matrix(c)

    def id19(self,p):
        if type(p)!=int:
            return NotImplemented
        c=[[0]*self.shape[1] for i in range(self.shape[0])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                c[i][j]=self.arr[i][j]%p
        return matrix(c)

    def id22(self,p):
        return self.id19(p)

    def id0(self,p,mod=10**9+7):
        if type(p)!=int or self.shape[0]!=self.shape[1]:
            return NotImplemented
        A=matrix(self.arr)
        R=matrix([[1*(i==j) for j in range(self.shape[0])] for i in range(self.shape[0])])
        while p>0:
            if p&1:
                R*=A
                R%=mod
            A*=A
            A%=mod
            p>>=1
        return R

    def id10(self):
        return self.id7(-1)

    def id8(self):
        rt='['
        for i in self.arr:
            rt=rt+str(i)+",\n"
        return rt[:-2]+']'

    def T(self):
        rt=[[0]*self.shape[0] for i in range(self.shape[1])]
        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                rt[j][i]=self.arr[i][j]
        return matrix(rt)

    def resize(self,new_shape,fill=0):
        t_arr=[]
        for i in self.arr:
            t_arr+=i
        t_arr.reverse()
        n,m=new_shape
        self.shape=(n,m)
        self.arr=[[fill]*m for i in range(n)]

        for i in range(self.shape[0]):
            for j in range(self.shape[1]):
                if t_arr:
                    self.arr[i][j]=t_arr.pop()
        return

    def view(self):
        for i in self.arr:
            print(i)


id13=False
id13=True

def solvef(n):
    ans=0
    mt=matrix([1,2,0,1,0,0,0,1,0])
    mt.resize((3,3))
    show(mt)
    x=matrix([1,0,0])
    x.resize((3,1))
    for i in rep(n):
        a,b,c=a+2*b,a,b
        a%=mo
        b%=mo
        c%=mo
        if i%3==(n-2)%3:
            ans+=c
            ans%=mo
    mt**=n
    show(mt)
    show(mt*x)
    return ans    


ans=0
def solve(n):
    ans=0
    D=2*10**6+1
    
    a,b,c=1,0,0
    for i in rep(n):
        a,b,c=a+2*b,a,b
        a%=mo
        b%=mo
        c%=mo
        if i%3==(n-2)%3:
            ans+=c*4
            ans%=mo
    return ans

def solve2(n):
    ans=0
    a,b,c=1,0,0
    ans=[0]*(n+10)
    ans[2]=4
    ans[3]=4
    for i in rep(n):
        a,b,c=a+2*b,a,b
        a%=mo
        b%=mo
        c%=mo
        
        d=1
        if i>-1+d+1:
            ans[i+d]=ans[i+d-3]+c*4
            ans[i+d]%=mo
    return ans


pre=solve2(2*10**6+5)

for _ in range(int(input())):
    ans=0
    n=I()
    
    print(pre[n-1])

