





















  


































































def main():
	from sys import stdin,stdout
	w=[]
	h=[]
	width_sum=0
	maxim=-100
	for _ in range(int(stdin.readline())):
		x,y=map(int,stdin.readline().split())
		w.append(x)
		h.append(y)
		width_sum+=x
		if y>maxim:
			maxim=y
			maxindex=_
	id0=maxim
	id1=max(h[:maxindex]+h[maxindex+1:])
	for i in range(len(w)):
		if i==maxindex:
			stdout.write(str((width_sum-w[i])*id1)+' ')
		else:
			stdout.write(str((width_sum-w[i])*id0)+' ')
if __name__=='__main__':
	main()
