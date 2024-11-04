















primes = map(int, .split())

sqf = {}

def id0(n):
	"returns the squarefree part of a number. keeps the sign of the number if it's negative, and returns 0 for 0"
	global sqf
	if n in sqf:
		return sqf[n]
	if n == 0:
		return 0
	n_orig = n
	for p in primes:
		if p*p > abs(n):
			sqf[n_orig] = n
			return n
		while n % p == 0 and (n/p) % p == 0:
			n /= p
			n /= p

line1 = raw_input()
line2 = raw_input()

n = int(line1)
l = map(int, line2.split())
l = map(id0, l)

d,k={0:0},1
for i in xrange(n):
	if l[i] not in d:
		d[l[i]]=k
		k+=1
	l[i]=d[l[i]]
ct,tmp=[0]*(n+2),[0]*(n+2)
for i in xrange(n):
	k=0
	for j in xrange(i,n):
		ss=l[j]
		if tmp[ss]==0 and ss!=0:
			k+=1
		tmp[ss]=1
		ct[k]+=1
	for j in xrange(i,n):
		tmp[l[j]] = 0
print ct[0]+ct[1],
for i in ct[2:-1]:print i,