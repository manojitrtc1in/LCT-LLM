





















	



























def main():
	from sys import stdin,stdout
	n,o=map(int,stdin.readline().split())
	string=stdin.readline().strip()
	if n & 1:
		s1=string[:n//2]
		s2=string[n//2+1:]
		rev=s2[::-1]
		minim=0
		indexlist=[]
		for i in range(n//2):
			k=abs(ord(s1[i])-ord(rev[i]))
			minim+=min(k,26-k)
			if k:
				indexlist.append(i)
		if o>n//2:
			o=(n-o)
		else:
			o-=1
		if len(indexlist):
			indexlist+=[o]
			for i in range(len(indexlist)):
				indexlist[i]=indexlist[i]-o
			minia=min(indexlist)
			maxia=max(indexlist)
			minim+=min(abs(minia),abs(maxia))*2+max(abs(minia),abs(maxia))
		stdout.write(str(minim))
	else:
		s1=string[:n//2]
		s2=string[n//2:]
		rev=s2[::-1]
		
		minim=0
		indexlist=[]
		for i in range(n//2):
			k=abs(ord(s1[i])-ord(rev[i]))
			minim+=min(k,26-k)
			if k:
				indexlist.append(i)
		if o > n//2:
			o=(n-o)
		else:
			o-=1
		
		
		if len(indexlist):
			indexlist+=[o]
			for i in range(len(indexlist)):
				indexlist[i]=indexlist[i]-o
			
			minia=min(indexlist)
			maxia=max(indexlist)
			minim+=min(abs(minia),abs(maxia))*2+max(abs(minia),abs(maxia))
		stdout.write(str(minim))
if __name__=='__main__':
	main()




