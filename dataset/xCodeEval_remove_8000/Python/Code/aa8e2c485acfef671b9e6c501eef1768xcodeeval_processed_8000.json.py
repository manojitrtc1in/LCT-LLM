


PI = 3.141592653589793238460
INF =  float('inf')
MOD  = 1000000007



def bin32(num):
	return '{0:032b}'.format(num)

def add(x,y):
	return (x+y)%MOD

def sub(x,y):
	return (x-y+MOD)%MOD

def mul(x,y):
	return (x*y)%MOD

def gcd(x,y):
	if y == 0:
		return x
	return gcd(y,x%y)

def lcm(x,y):
	return (x*y)//gcd(x,y)

def power(x,y):
	res = 1
	x%=MOD
	while y!=0:
		if y&1 :
			res = mul(res,x)
		y>>=1
		x = mul(x,x)
		
	return res
























































































































































































		
def mod_inv(n):
	return power(n,MOD-2)


def prob(p,q):
	return mul(p,power(q,MOD-2))    
  

def ii():
	return int(input())


def li():
	return [int(i) for i in input().split()]


def ls():
	return [i for i in input().split()]


for t in range(ii()):

	t+=1

	n = ii()

	a = li()

	l = 0

	r = a[-1] + 1












	ans = 0
	while l <= r :
		mid = (l + r + 1)//2
		b = a[:]

		flag = 1






		for i in range( n-1,1,-1):
		











			
			x = (b[i]  - mid)

			x = min(x , a[i])
			if x < 0:
				flag = 0




				break
			

			d = x//3



			b[i-1]+=d

			b[i-2]+=2*d



			b[i] -= 3*d


		
		for i in b:

			if i < mid:
				flag = 0
		if flag:

			l = mid + 1

			ans = max(ans , mid)

		else:

			r = mid-1
	print(ans)

	