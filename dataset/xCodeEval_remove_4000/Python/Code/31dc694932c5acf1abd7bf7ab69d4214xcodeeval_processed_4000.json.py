





















	
































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
