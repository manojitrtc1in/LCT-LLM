





















	




































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
