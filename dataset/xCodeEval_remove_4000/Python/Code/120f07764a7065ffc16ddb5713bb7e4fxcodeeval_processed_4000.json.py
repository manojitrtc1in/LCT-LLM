tabela = 

def sd(x):
	return sum(map(int, str(x)))

def ans(x):
	print(x)
	exit(0)

def id1(a):
	if a == 2:
		ans(6)
	if a == 4:
		ans(75)
	if a == 8:
		ans(125)

def id0(x):
	if 10**18 % x == 0:
		ans(-1)

def single_test(x, drange):
	found = False
	for d in drange:
		t = 10**d // x + 1
		ad = sd(t) - sd(t*x)*x
		if ad > 0:
			print(x, d, ad)
			found = True
			break
	if not found:
		print(x, 'Failed')
		return

def test1(x):
	plus = None
	minus = None

	ir = [1, 2, 11]
	ir = [1, 2, 11, 9, 99, 999]

	for d in range(1, 6400, 1):
		for i in ir:
			t = i*10**d // x + 1
			ad = sd(t) - sd(t*x)*x
			if ad > 0:
				if ad < 40:
					plus = (i, d, ad)
			else:
				if -ad < 40:
					minus = (i, d, -ad)

			if plus != None and minus != None:
				print(x, *plus, *minus)
				return True

	return False

def test_f(f):
	for x in range(990, 1001):
		if 10**18 % x == 0:
			continue
		if not f(x):
			print(x, 'Error')
			return

def id2(x):
	a = map(lambda t: list(map(int, t.split(' '))), tabela.strip().split('\n'))
	for red in a:
		(idx, i1, d1, ad1, i2, d2, ad2) = red
		if idx == x:
			s1 = str(i1*10**d1 // x + 1)
			s2 = str(i2*10**d2 // x + 1)
			ans((s1 + '000000') * ad2 + (s2 + '000000') * ad1)

def precompute():
	test_f(test1)

def task():
	n = int(input())
	id1(n)
	id0(n)
	id2(n)

task()
