





















  












































def main():
	from sys import stdin, stdout
	import collections
	n = int(stdin.readline())
	t=tuple(map(int,stdin.readline().split()))
	dic=collections.defaultdict(list)
	for i in range(n):
		dic[t[i]].append(i)
	counter=0
	for i in dic:
		mylist=dic[i]
		if len(mylist)==1:
			counter+=1
		else:
			c=mylist[1]-mylist[0]
			flag=True
			for j in range(2,len(mylist)):
				if mylist[j]-mylist[j-1]!=c:
					flag=False
					break
			if flag:
				counter+=1
	stdout.write(str(counter)+'\n')
	for i in sorted(dic):
		mylist = dic[i]
		if len(mylist) == 1:
			stdout.write(str(i)+' 0\n')
		else:
			c = mylist[1] - mylist[0]
			flag = True
			for j in range(2, len(mylist)):
				if mylist[j] - mylist[j - 1] != c:
					flag = False
					break
			if flag:
				stdout.write(str(i)+' '+str(c)+'\n')
if __name__ == '__main__':
	main()
