





















  












































































def main():
	from sys import stdin,stdout
	n,k=map(int,stdin.readline().split())
	arr=tuple(map(int,stdin.readline().split()))
	minim=0
	
	for i in range(1,k):
		
		if sum(arr[i::k]) < sum(arr[minim::k]):
			minim=i
	stdout.write(str(minim+1))
if __name__=='__main__':
	main()
