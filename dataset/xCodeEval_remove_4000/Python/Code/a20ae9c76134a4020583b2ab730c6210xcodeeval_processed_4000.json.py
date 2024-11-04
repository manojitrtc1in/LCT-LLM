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
aas = map(int, line2.split())
aas = map(id0, aas)


ids = {0:0}
for i, a in enumerate(aas):
	if a not in ids:
		ids[a] = i+1
aas = [ids[a] for a in aas]


d = [0]*(n+2)
ks = [0]*(n+1)
for i in range(n):
	k = 0
	for j in range(i,n):
		
		a = aas[j]
		if a != 0 and d[a] == 0:
			k += 1
		d[a] += 1
		ks[k] += 1

	
	for j in range(i,n):
		a = aas[j]
		d[a] = 0

print ks[0]+ks[1],
for k in ks[2:]:
	print k,