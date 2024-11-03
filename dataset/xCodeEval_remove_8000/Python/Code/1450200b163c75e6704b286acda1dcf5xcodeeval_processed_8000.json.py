





















  
































































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
