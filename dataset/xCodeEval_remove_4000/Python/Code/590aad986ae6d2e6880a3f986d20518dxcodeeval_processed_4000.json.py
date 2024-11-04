





















	























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
