





















	



















def main():
	from sys import stdin,stdout
	s=stdin.readline().strip()
	flag=s[0]
	if flag=='.':
		anti='
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
