'''
def main():
	from sys import stdin,stdout
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	import collections
	N,I =map(int,stdin.readline().split())
	visited=list(0 for x in range(N))
	G=collections.defaultdict(list)
	groups=[0]
	for _ in range(I):
		a,b=map(int,stdin.readline().split())
		G[a].append(b)
		G[b].append(a)
	q=collections.deque()
	flag=0
	for i in range(N):
		if not visited[i]:
			q.append(i)
			visited[i]=flag+1
			groups[flag]+=1
			while len(q):
				top=q.popleft()
				for j in G[top]:
					if visited[j]!=visited[top]:
						visited[j]=flag+1
						groups[flag]+=1
						q.append(j)
			flag+=1
			groups.append(0)
	counter=0
	for i in range(len(groups)-1):
		for j in range(i+1,len(groups)):
			counter+=groups[i]*groups[j]
	stdout.write(str(counter))
if __name__=='__main__':
	main()
'''

'''
import collections
class Graph:
	def __init__(self):
		self.nodes=set()
		self.edges=collections.defaultdict(list)
		self.distances = {}

	def add_node(self, value):
		self.nodes.add(value)

	def add_edge(self, from_node, to_node, distance):
		self.edges[from_node].append(to_node)
		self.edges[to_node].append(from_node)
		self.distances[(from_node, to_node)] = distance
		self.distances[(to_node, from_node)] = distance


def dijsktra(graph, initial):
	visited = {initial: 0}
	path = {}

	nodes = set(graph.nodes)

	while nodes:
		min_node = None
		for node in nodes:
			if node in visited:
				if min_node is None:
					min_node = node
				elif visited[node] < visited[min_node]:
					min_node = node

		if min_node is None:
			break

		nodes.remove(min_node)
		current_weight = visited[min_node]

		for edge in graph.edges[min_node]:
			weight = current_weight + graph.distances[(min_node, edge)]
			if edge not in visited or weight < visited[edge]:
				visited[edge] = weight
				path[edge] = min_node

	return visited, path

def main():
	from sys import stdin,stdout
	for _ in range(int(stdin.readline())):
		n,m=map(int,stdin.readline().split())
		G=Graph()
		for i in range(n):
			G.add_node(i+1)
		for i in range(m):
			a,b,c=map(int,stdin.readline().split())
			G.add_edge(a,b,c)
		initial=int(stdin.readline())
		v,p=dijsktra(G, initial)
		#print(v)
		#print(p)
		for i in range(1,n+1):
			if i!=initial:
				k=v.get(i,-1)
				stdout.write(str(k)+' ')
		stdout.write('\n')
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	string=stdin.readline().strip()
	l=len(string)
	#Triangle logic	
	
	arrlen=(l*(l-1))//2
	arr=list(0 for x in range(arrlen))
	f=0
	c=l-1
	for i in range(l-1):
		for j in range(i+1,l):
			if string[i]==string[j]:
				arr[f+j-i-1]=1
		f+=c
		c-=1
	#print(arr)
	if any(arr):
		
	else:
		if l & 1:
			stdout.write('First')
		else:
			stdout.write('Second')
	#2-d Array Logic
	arr=list(list(0 for i in range(l)) for j in range(l))
	for i in range(l):
		for j in range(l):
			if string[i]==string[j]:
				arr[i][j]=1
	maxim=0
	for i in range(0,l*(l-1)-2,l+1):
		a,b=i+1,i+2
		#print(a,b)
		acount=0
		x=a//5
		y=a%5
		acount=arr[x][y]		
		x-=1
		y-=1
		while x>=0 and y>=0:
			acount+=arr[x][y]
			x-=1
			y-=1
		x=b//5
		y=b%5
		bcount=arr[x][y]		
		x-=1
		y-=1
		while x>=0 and y>=0:
			bcount+=arr[x][y]
			x-=1
			y-=1
		maxim=max((acount,bcount,maxim))
	maxim=max(maxim,arr[l-2][l-1])
	maxim=(maxim<<1)^1
	delta=l-maxim
	if delta & 1:
		stdout.write('Second')
	else:
		stdout.write('First')
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	import collections
	s=stdin.readline().strip()
	count=collections.Counter(s)
	l=list(filter(lambda x: count[x] & 1,list(x for x in count)))
	removed=sum(list(count[x] for x in l))-max(list(count[x] for x in l)+[0])
	if removed & 1:
		stdout.write('Second')
	else:
		stdout.write('First')
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	n,m=map(int,stdin.readline().split())
	if m:
		dirty=sorted(map(int,stdin.readline().split()))
		if dirty[0]==1 or dirty[-1]==n:
			stdout.write('NO')
		else:
			flag=True
			for i in range(m-2):
				if dirty[i+1]==dirty[i]+1 and dirty[i+2]==dirty[i]+2:
					flag=False
					break
			if flag:
				stdout.write('YES')
			else:
				stdout.write('NO')
	else:
		stdout.write('YES')
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	n,t=map(int,stdin.readline().split())
	arr=list(map(int,stdin.readline().split()))
	maxim=0
	curr_sum=arr[0]
	i=0
	j=1
	if curr_sum <=t:
		count=1
	else:
		curr_sum=0
		count=0
		i=1
		j=2
	while j<n:
		if curr_sum+arr[j]<=t:
			count+=1
			curr_sum+=arr[j]
			j+=1
		else:
			maxim=max(count,maxim)
			if curr_sum:
				curr_sum-=arr[i]
				count-=1
			else:
				j+=1
			i+=1
	maxim=max(count,maxim)
	stdout.write(str(maxim))
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	p,q,l,r=map(int,stdin.readline().split())
	a=[]
	b=[]
	visited=list(0 for x in range(r-l+1))
	#print(visited)	
	for i in range(p):
		x,y=map(int,stdin.readline().split())
		a.append(x)
		b.append(y)
	for i in range(q):
		x,y=map(int,stdin.readline().split())
		x+=l
		y+=l
		for j in range(p):
			#print('x=',x,'y=',y)
			lower=max(0,a[j]-y)
			upper=min(b[j]-x,r)+1
			if upper > lower:
				delta=upper-lower
				#print('upper=',upper,'lower=',lower)
				visited[lower:upper]=list(1 for x in range(delta))
				#print('visited:\n',visited)
	#	print(visited)
	stdout.write(str(visited[:r-l+1].count(1)))
if __name__=='__main__':
	main()
'''
'''
def main():
	from sys import stdin,stdout
	#import numpy as np
	n,k=map(int,stdin.readline().split())
	a=tuple(map(int,stdin.readline().split()))
	minim=min(a)
	maxim=max(a)
	arr=list(a)	
	for i in range(n):
		arr[i]-=minim
	if max(arr) > k:
		stdout.write('NO')
	else:
		stdout.write('YES\n')
		for i in a:
			stdout.write('1 '*minim)
			for j in range(i-minim):
				stdout.write(str(j%k+1)+' ')
			stdout.write('\n')
if __name__=='__main__':
	main()
'''
'''
def main():
	from sys import stdin,stdout
	n,p=[],[]
	for _ in range(int(stdin.readline())):
		last=int(stdin.readline())
		if last<0:
			n.append(-1*last)
		else:
			p.append(last)
	if sum(p)>sum(n):
		stdout.write('first')
	elif sum(n)>sum(p):
		stdout.write('second')
	else:
		maxim=max(n,p)
		#print(maxim)
		if maxim==p:
			if maxim==n:
				if last<0:
					stdout.write('second')
				else:
					stdout.write('first')
			else:
				stdout.write('first')
		else:
			stdout.write('second')
		
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	m,n=map(int,stdin.readline().split())
	minim=min(m,n)
	stdout.write(str(minim+1)+'\n')
	if n==minim:
		for i in range(minim+1):
			stdout.write(str(m)+' '+str(i)+'\n')
			m-=1
	else:
		for i in range(minim+1):
			stdout.write(str(i)+' '+str(n)+'\n')
			n-=1
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	n,m=map(int,stdin.readline().split())
	a=tuple(map(int,stdin.readline().split()))
	b=tuple(map(int,stdin.readline().split()))
	i=0
	j=0
	while True:
		#print(i,j)
		if i>=n or j>=m:
			break
		if b[j]>=a[i]:
			i+=1
			j+=1
		else:
			j+=1
	stdout.write(str(n-i))
if __name__=='__main__':
	main()
'''

'''
def main():
	from sys import stdin,stdout
	n=int(stdin.readline())
	a=tuple(map(int,stdin.readline().split()))
	maxim=2
	count=2
	i=2
	while True:
		if i>=n:
			break
		if a[i]==a[i-1]+a[i-2]:
			count+=1
			maxim=max(count,maxim)
		else:
			count=2
		i+=1
	stdout.write(str(min(maxim,n)))
if __name__=='__main__':
	main()
'''  # 474D
'''
def main():
	from sys import stdin,stdout
	MOD=int(1e9)+7
	T,k=map(int,stdin.readline().split())
	fib=[x for x in range(1,k+1)]
	for i in range(k,100001):
		fib.append((fib[i-1]+fib[i-k]+1)%MOD)
	for _ in range(T):
		a,b=map(int,stdin.readline().split())
		stdout.write(str((fib[b]-fib[a-1])%MOD)+'\n')
if __name__=='__main__':
	main()
'''
# 330B
# not working
'''
def main():
	from sys import stdin,stdout
	import collections
	road_not=collections.defaultdict(set)
	n,m=map(int,stdin.readline().split())
	for _ in range(m):
		a,b=map(int,stdin.readline().split())
		road_not[a].add(b)
		road_not[b].add(a)
	counter=0
	road=collections.defaultdict(set)
	visited=[0 for x in range(n)]
	visited[0]=True
	for index in range(1,n+1):
		for i in range(1,n+1):
			if not visited[i-1]:
				if i not in road_not[index] and i!=index:
					counter+=1
					road[index].add(i)
					visited[i-1]=True
	stdout.write(str(counter)+'\n')
	for i in road:
		for j in road[i]:
			stdout.write(str(i)+' '+str(j)+'\n')
if __name__=='__main__':
	main()
'''
# 208D
'''
def main():
	from sys import stdin,stdout
	import bisect
	n=int(stdin.readline())
	p=tuple(map(int,stdin.readline().split()))
	P=tuple(map(int,stdin.readline().split()))
	record=[0 for x in range(5)]
	points=0
	for i in p:
		points+=i
		while points>=P[0]:
			index=bisect.bisect_right(P,points)
			if index:
				index-=1
				number=points//P[index]
				record[index]+=number
				points-=P[index]*number
	for i in record:
		stdout.write(str(i)+' ')
	stdout.write('\n'+str(points))
if __name__=='__main__':
	main()
'''
# 339D Using Al.Cash's Segment Trees
# Segment Tree
# not-working
'''
powers=1
t=[0 for x in range(3*int(1e5))]
def build(n):
	global t,powers
	flag=False
	for i in range(n-1,0,-1):
		if i==powers-1:
			flag=not flag
			powers>>=1
		if flag:
			t[i]=t[i<<1]^t[i<<1|1]
		else:
			t[i]=t[i<<1]|t[i<<1|1]

def modify(i,v,n):
	global t
	flag=False
	if t[i+n-1]==v or v|t[(i+n-1)^1]==t[(i+n-1)>>1]:
		
		
		
		t[i+n-1]=v		
		return
	t[i+n-1]=v
	p=i+n-1
	while p>1:
		if flag:
			if t[p>>1]==t[p]^t[p^1]:
				break
			t[p>>1]=t[p]^t[p^1]
			flag=not flag
		else:
			if t[p>>1]==t[p]|t[p^1]:
				break
			t[p>>1]=t[p]|t[p^1]
			flag=not flag
		p>>=1

def main():
	from sys import stdin,stdout
	global t,powers
	n,m=map(int,stdin.readline().split())
	p=tuple(map(int,stdin.readline().split()))
	powers=1<<(n-1)	
	n=1<<(n)	
	for i in range(n):
		t[i+n]=p[i]
	build(n)
	
	for _ in range(m):
		a,b=map(int,stdin.readline().split())
		modify(a,b,n)
		
		stdout.write(str(t[1])+'\n')
if __name__=='__main__':
	main()
'''
# 330B
'''
def main():
	from sys import stdin,stdout
	n,m=map(int,stdin.readline().split())
	start_not=set()
	for _ in range(m):
		a,b=map(int,stdin.readline().split())
		start_not.add(a-1)
		start_not.add(b-1)
	visited=[False for _ in  range(n)]
	for i in range(n):
		if i not in start_not:
			center=i
			break
	stdout.write(str(n-1)+'\n')
	for i in range(n):
		if i != center:
			stdout.write(str(center+1)+' '+str(i+1)+'\n')
if __name__=='__main__':
	main()
'''
# 116B
'''
def main():
	from sys import stdin,stdout
	n,m=map(int,stdin.readline().split())
	arr=[]
	for _ in range(n):
		arr.append(stdin.readline().strip())
	pigs=set()
	count=0
	for i in range(n):
		for j in range(m):
			if arr[i][j]=='W':
				flag=0
				if i>0:
					if arr[i-1][j]=='P':
						pigs.add((i-1,j))
						flag=1
				if i<n-1:
					if arr[i+1][j]=='P':
						pigs.add((i+1,j))
						flag=1
				if 	j>0:
					if arr[i][j-1]=='P':
						pigs.add((i,j-1))
						flag=1
				if j<m-1:
					if arr[i][j+1]=='P':
						pigs.add((i,j+1))
						flag=1
				if flag:
					count+=1
	stdout.write(str(min(len(pigs),count)))
if __name__=='__main__':
	main()
'''
# 339D using Al.Cash's Segment Tree Implementation
'''
def power(a,b):
	if b:
		if b &1:
			return a*power(a,b-1)
		else:
			return power(a*a,b//2)
	else:
		return 1;
def main():
	from sys import stdin,stdout
	answers=()
	n,m=map(int,stdin.readline().split())
	p=tuple(map(int,stdin.readline().split()))
	powers=power(2,n-1)
	n=powers<<1
	t=[0 for _ in range(n<<1)]
	for i in range(n):
		t[n+i]=p[i]
	flag=False
	for i in range(n-1,0,-1):
		if i==powers-1:
			flag=not flag
			powers>>=1
		if flag:
			t[i]=t[i<<1]^t[i<<1|1]
		else:
			t[i]=t[i<<1]|t[i<<1|1]
	for _ in range(m):
		a,b=map(int,stdin.readline().split())
		flag=False
		if t[a+n-1]==b or b|t[(a+n-1)^1]==t[(a+n-1)>>1]:
			t[a+n-1]=b
		else:
			t[a+n-1]=b
			p=a+n-1
			while p > 1:
				if flag:
					if t[p>>1]==t[p]^t[p^1]:
						break
					t[p>>1]=t[p]^t[p^1]
					flag=not flag
				else:
					if t[p>>1]==t[p]|t[p^1]:
						break
					t[p>>1]=t[p]|t[p^1]
					flag= not flag
				p>>=1
		stdout.write(str(t[1])+'\n')
if __name__=='__main__':
	main()
'''
# 515C
'''
def main():
	from sys import stdin,stdout
	import collections
	nc=[0 for x in range(10)]
	n=int(stdin.readline())
	num=stdin.readline().strip()
	for i in num:
		k=int(i)
		if k==9:
			nc[7]+=1
			nc[3]+=2
			nc[2]+=1
		elif k==8:
			nc[7]+=1
			nc[2]+=3
		elif k==7:
			nc[7]+=1
		elif k==6:
			nc[5]+=1
			nc[3]+=1
		elif k==5:
			nc[5]+=1
		elif k==4:
			nc[3]+=1
			nc[2]+=2
		elif k==3:
			nc[3]+=1
		elif k==2:
			nc[2]+=1
	ans=''
	for i in range(10):
		ans+=str(9-i)*nc[9-i]
	stdout.write(ans)		
if __name__=='__main__':
	main()
'''
# 313B
'''
def main():
	from sys import stdin,stdout
	s=stdin.readline().strip()
	flag=s[0]
	if flag=='.':
		anti='#'
	else:
		anti='.'
	n=len(s)
	l=[0 for x in range(n)]
	for i in range(1,n):
		if s[i]==flag:
			l[i]=l[i-1]+1
		else:
			flag,anti=anti,flag
			l[i]=l[i-1]
	
	for _ in range(int(stdin.readline())):
		a,b=map(int,stdin.readline().split())
		stdout.write(str(l[b-1]-l[a-1])+'\n')
if __name__=='__main__':
	main()
'''
# 431C
'''
def main():
	from sys import stdin,stdout
	MOD=int(1e9)+7
	n,k,d=map(int,stdin.readline().split())
	d-=1
	klist=[(1<<i)%MOD for i in range(k)]
	klist=[1]+klist
	for i in range(k+1,n+1):
		klist.append((klist[i-1]*2-klist[i-1-k])%MOD)
	if d:	
		dlist=[(1<<i)%MOD for i in range(d)]
		dlist=[1]+dlist
		for i in range(d+1,n+1):
			dlist.append((dlist[i-1]*2-dlist[i-1-d])%MOD)
	
	
		ans=klist[n]-dlist[n]
	else:
		ans=klist[n]
	stdout.write(str(ans%MOD))
if __name__=='__main__':
	main()
'''
# 441C
'''
def main():
	from sys import stdin,stdout
	n,m,k=map(int,stdin.readline().split())
	if n>=m:
		i=-1
		j=-1
		num=n*m
		while k:
			ans=num//k
			stdout.write(str(ans)+' ')
			counter=0
			while counter<ans:
				if j==-1:
					flag=True
					i+=1
					j+=1
				if j==m:
					flag=False
					i+=1
					j-=1
				stdout.write(str(i+1)+' '+str(j+1)+' ')
				if flag:
					j+=1
				else:
					j-=1
				counter+=1
			num-=ans
			k-=1
			stdout.write('\n')
	else:
		i=-1
		j=-1
		num=n*m
		while k:
			ans=num//k
			stdout.write(str(ans)+' ')
			counter=0
			while counter<ans:
				if i==-1:
					flag=True
					j+=1
					i+=1
				if i==n:
					flag=False
					j+=1
					i-=1
				stdout.write(str(i+1)+' '+str(j+1)+' ')
				if flag:
					i+=1
				else:
					i-=1
				counter+=1
			num-=ans
			k-=1
			stdout.write('\n')
if __name__=='__main__':
	main()
'''
# 538B
'''
def main():
	from sys import stdin,stdout
	n=int(stdin.readline())
	ans=[]
	while n:
		t=''
		num=str(n)
		for i in num:
			if int(i):
				t+='1'
			else:
				t+='0'
		ans.append(t)
		n-=int(t)
	stdout.write(str(len(ans))+'\n')
	for i in ans:
		stdout.write(i+' ')
if __name__=='__main__':
	main()
'''
# 486C
# Palidrome Transformation
'''
def main():
	from sys import stdin,stdout
	n,o=map(int,stdin.readline().split())
	string=stdin.readline().strip()
	if n & 1:
		s1=string[:n//2]
		s2=string[n//2+1:]
		rev=s2[::-1]
		minim=0
		indexlist=[]
		for i in range(n//2):
			k=abs(ord(s1[i])-ord(rev[i]))
			minim+=min(k,26-k)
			if k:
				indexlist.append(i)
		if o>n//2:
			o=(n-o)
		else:
			o-=1
		if len(indexlist):
			indexlist+=[o]
			for i in range(len(indexlist)):
				indexlist[i]=indexlist[i]-o
			minia=min(indexlist)
			maxia=max(indexlist)
			minim+=min(abs(minia),abs(maxia))*2+max(abs(minia),abs(maxia))
		stdout.write(str(minim))
	else:
		s1=string[:n//2]
		s2=string[n//2:]
		rev=s2[::-1]
		
		minim=0
		indexlist=[]
		for i in range(n//2):
			k=abs(ord(s1[i])-ord(rev[i]))
			minim+=min(k,26-k)
			if k:
				indexlist.append(i)
		if o > n//2:
			o=(n-o)
		else:
			o-=1
		
		
		if len(indexlist):
			indexlist+=[o]
			for i in range(len(indexlist)):
				indexlist[i]=indexlist[i]-o
			
			minia=min(indexlist)
			maxia=max(indexlist)
			minim+=min(abs(minia),abs(maxia))*2+max(abs(minia),abs(maxia))
		stdout.write(str(minim))
if __name__=='__main__':
	main()
'''
# 4B
'''
def main():	
	from sys import stdin,stdout
	n,sumtime=map(int,stdin.readline().split())
	a,b=[],[]
	for i in range(n):
		x,y=map(int,stdin.readline().split())
		a.append(x)
		b.append(y)
	if sum(b)<sumtime or sum(a)>sumtime:
		stdout.write('NO')
	else:
		stdout.write('YES\n')
		diff=sumtime-sum(a)
		for i in range(n):
			if diff:
				k=b[i]-a[i]
				minim=min(k,diff)
				a[i]+=minim
				diff-=minim
		for i in a:
			stdout.write(str(i)+' ')
if __name__=='__main__':
	main()
'''
# 282B
'''
def main():
	from sys import stdin,stdout
	n=int(stdin.readline())
	a,b=[],[]
	for i in range(n):
		x,y=map(int,stdin.readline().split())
		a.append(x)
		b.append(y)
	if a[0]>b[0]:
		total=-1*b[0]
		t='G'
	else:
		total=a[0]
		t='A'
	for i in range(1,n):
		if total+a[i]>=500:
			total-=b[i]
			t+='G'
		else:
			total+=a[i]
			t+='A'
	if total<-500 or total >500:
		stdout.write('-1')
	else:
		stdout.write(t)
if __name__=='__main__':
	main()
'''
# 122B
'''
def main():
	from sys import stdin,stdout
	s=stdin.readline().strip()
	for i in s:
		if i=='0':
			s=s[1:]
		else:
			break
	count4=s.count('4')
	count7=s.count('7')
	if count4 or count7:
		if count4>=count7:
			stdout.write('4')
		else:
			stdout.write('7')
	else:
		stdout.write('-1')
if __name__=='__main__':
	main()
'''
# 155B
'''
def main():
	from sys import stdin,stdout
	a,b=[],[]
	n=1
	total=int(stdin.readline())
	for _ in range(total):
		x,y=map(int,stdin.readline().split())
		n+=y
		if y:
			a.append(x)
		else:
			b.append(x)	
	a.sort(reverse=True)
	b.sort(reverse=True)
	alen=len(a)
	blen=len(b)
	minim=min(total,n)
	points=0
	if minim>alen:
		extra=minim-alen
		points+=sum(a)
		points+=sum(b[:extra])
	else:
		points=sum(a[:minim])
	stdout.write(str(points))
if __name__=='__main__':
	main()
'''
# 368B
'''
def main():
	from sys import stdin,stdout
	import collections
	n,m=map(int,stdin.readline().split())
	arr=list(map(int,stdin.readline().split()))
	s=set()
	ans=collections.deque([0])
	for i in range(n-1,-1,-1):
		if arr[i] in s:
			ans.appendleft(ans[0])
		else:
			ans.appendleft(ans[0]+1)
			s.add(arr[i])
	for _ in range(m):
		a=int(stdin.readline())-1
		stdout.write(str(ans[a])+'\n')
if __name__=='__main__':
	main()
'''
# 166E
''''
def main():
	from sys import stdin,stdout
	MOD=int(1e9)+7
	n=int(stdin.readline())
	if n&1:
		ans=0
		flag=3
		for _ in range(1,n,2):
			ans=(ans+flag)%MOD
			flag=(flag*9)%MOD
		ans<<=1
		stdout.write(str((ans)%MOD))
	else:
		ans=0
		flag=9
		for _ in range(2,n,2):
			ans=(ans+flag)%MOD
			flag=(flag*9)%MOD
		ans<<=1
		ans+=3
		stdout.write(str((ans)%MOD))
if __name__=='__main__':
	main()
'''
'''

def main():
	from sys import stdin, stdout
	import collections
	n = int(stdin.readline())
	t=tuple(map(int,stdin.readline().split()))
	dic=collections.defaultdict(list)
	for i in range(n):
		dic[t[i]].append(i)
	counter=0
	for i in dic:
		mylist=dic[i]
		if len(mylist)==1:
			counter+=1
		else:
			c=mylist[1]-mylist[0]
			flag=True
			for j in range(2,len(mylist)):
				if mylist[j]-mylist[j-1]!=c:
					flag=False
					break
			if flag:
				counter+=1
	stdout.write(str(counter)+'\n')
	for i in sorted(dic):
		mylist = dic[i]
		if len(mylist) == 1:
			stdout.write(str(i)+' 0\n')
		else:
			c = mylist[1] - mylist[0]
			flag = True
			for j in range(2, len(mylist)):
				if mylist[j] - mylist[j - 1] != c:
					flag = False
					break
			if flag:
				stdout.write(str(i)+' '+str(c)+'\n')
if __name__ == '__main__':
	main()
'''
'''
def main():
	from sys import stdin,stdout
	dic={'>':'1000','<':'1001','+':'1010', '-':'1011', '.':'1100',',':'1101','[':'1110',']':'1111'}
	s=stdin.readline().strip()
	t=''
	for i in s:
		t+=dic[i]
	num=int(t,2)
	stdout.write(str(num%(int(1e6)+3)))
if __name__=='__main__':
	main()
'''
#567C
'''
def main():
	from sys import stdin,stdout
	import collections
	import bisect
	index=collections.defaultdict(list)
	n,k=map(int,stdin.readline().split())
	t=tuple(map(int,stdin.readline().split()))
	for i in range(n):
		index[t[i]].append(i)
	mycounter=collections.Counter(t)
	print(mycounter)
	print(index)
	index=dict(index)
	counter=0
	flag=True
	for i in index:
		for j in index[i]:
			c=1
			n=index.get(i*k,[])
			if len(n):
				c*=(len(n)-bisect.bisect_left(n,j))
			else:
				flag=False
				break
			n=index.get(i*k*k,[])
			if len(n):
				c*=(len(n)-bisect.bisect_left(n,j))
			else:
				flag=False
				break
			counter+=c
			print(i,j,counter)
		if not flag:
			break
	stdout.write(str(counter))
if __name__=='__main__':
	main()
'''
'''
def main():
	from sys import stdin,stdout
	n,o1,o2=map(int,stdin.readline().split())
	m=set()
	for _ in range(n):
		a,b=map(int,stdin.readline().split())
		d1=a-o1
		d2=b-o2
		if d2:
			m.add(d1/d2)
		else:
			m.add('inf')
	stdout.write(str(len(m)))
if __name__=='__main__':
	main()
'''
#4C
'''
def main():
	from sys import stdin,stdout
	import collections
	namecounter=collections.Counter()
	for _ in range(int(stdin.readline())):
		ip=stdin.readline().strip()
		k=namecounter[ip]
		namecounter[ip]+=1
		if k:
			stdout.write(ip+str(k)+'\n')
		else:
			stdout.write('OK\n')
if __name__=='__main__':
	main()
'''
#363C
'''
def main():
	from sys import stdin,stdout
	ip=stdin.readline().strip()
	t=ip[0]
	for ch in ip[1:]:
		if len(t)>2:
			if (ch==t[-1] and t[-2]==t[-3] ) or (ch==t[-1] and t[-1]==t[-2]):
				continue
			else:
				t+=ch
		elif len(t)==2:
			if ch==t[-1] and ch==t[-2]:
				continue
			else:
				t+=ch
		else:
			t+=ch
	stdout.write(t)
if __name__=='__main__':
	main()
'''
#490C
#(STRING to NUMBER)DIGITS
#not working
'''
def main():
	from sys import stdin,stdout
	import bisect
	A=set()
	B=set()
	anum=0
	bnum=0
	p=1
	flag=False		
	s=stdin.readline().strip()
	a,b=map(int,stdin.readline().split())
	length=len(s)
	for i in range(length):
		n=ord(s[i])-48
		m=ord(s[length-i-1])-48
		anum=anum*10+n
		bnum=m*p+bnum
		if anum % a==0:
			A.add(i)
		if bnum % b==0:
			B.add(length-i-1)
		p*=10
	if len(A) and len(B):
		for i in A:
			if i<length-1:
				if i+1 in B and s[i+1]!='0':
					flag=True
					break
	if flag:
		stdout.write('YES\n'+s[:i+1]+'\n'+s[i+1:])
	else:
		stdout.write('NO')	
if __name__=='__main__':
	main()
'''
#Round-392
#758A
'''
def main():
	from sys import stdin,stdout
	n=int(stdin.readline())
	a=tuple(map(int,stdin.readline().split()))
	maxim=max(a)
	mysum=0
	for i in a:
		mysum+=(maxim-i)
	stdout.write(str(mysum))
if __name__=='__main__':
	main()
'''
#758B
'''
def main():
    from sys import stdin,stdout
    import collections
    counter=collections.Counter()
    s=list(stdin.readline().strip())
    for i in range(len(s)):
        if s[i]=='!':
            if i-4<0:
                if s[i+4]!='!':
                    counter[s[i+4]]+=1
                    s[i]=s[i+4]
                else:
                    sample=s[i:i+4]
                    for i in 'RBYB':
                        if i not in sample:
                            break
                    counter[i]+=1
                    s[i]=i
            else:
                if s[i-4]!='!':
                    counter[s[i-4]]+=1
                    s[i]=s[i-4]
                elif i+4<n:
                    if s[i+4]!='!':
                        counter[s[i+4]]+=1
                        s[i]=s[i+4]
    for i in 'RBYG':
        stdout.write(str(counter[i])+' ')
if __name__=='__main__':
    main()
'''
#758D
'''
def main():
    from sys import stdin,stdout
    base=int(stdin.readline())
    n=stdin.readline().strip()
    revn=n[::-1]
    p=1
    i=len(n)-2
    num=int(revn[0])
    ans=0
    while i>=0:
        if revn[i]=='0':
            if num or i==1:
                ans+=num*p
                p*=base
            p*=base
            num=0
            i+=1
            continue
        if num:
            ch=int(revn[i])*10+num
        else:
            ch=int(revn[i])
        if ch < base:
            num=ch
            i+=1
        else:
            ans+=num*p
            p*=base
            num=0
    if num:
        ans+=num*p
    stdout.write(str(ans))
if __name__=='__main__':
    main()
'''
#626B
'''
def main():
	from sys import stdin,stdout
	import collections
	n=int(stdin.readline())
	s=stdin.readline().strip()
	counter=collections.Counter(s)
	temp=''
	for i in 'BGR':
		if not counter[i]:
			temp+=i
	if len(temp)==2:
		if n>1:
			stdout.write(str(counter.most_common(1)[0][0]))
		else:
			stdout.write(s)
	elif len(temp)==1:
		if n>2:
			ans=list(temp+str(counter.most_common(2)[1][0]))
			ans.sort()
			stdout.write(''.join(x for x in ans))
		else:
			stdout.write(temp)
	else:
		stdout.write('BGR')
if __name__=='__main__':
	main()
'''

def man(a,b):
	return abs(a[0]-b[0])+abs(a[1]-b[1])
def euc(a,b):
	if a[0]==b[0]:
		return abs(a[1]-b[1])
	elif a[1]==b[1]:
		return abs(a[0]-b[0])
	else:
		return 0
def main():
	from sys import stdin,stdout
	import collections
	counter=collections.Counter()
	xcounter=collections.Counter()
	ycounter=collections.Counter()
	n=int(stdin.readline())
	for _ in range(n):
		x,y=map(int,stdin.readline().split())
		counter[(x,y)]+=1
		xcounter[x]+=1
		ycounter[y]+=1
	ans=0
	for i in xcounter:
		ans+=(xcounter[i]*(xcounter[i]-1))//2
	for i in ycounter:
		ans+=(ycounter[i]*(ycounter[i]-1))//2
	for i in counter:
		ans-=(counter[i]*(counter[i]-1))//2
	stdout.write(str(ans))
if __name__=='__main__':
	main()
