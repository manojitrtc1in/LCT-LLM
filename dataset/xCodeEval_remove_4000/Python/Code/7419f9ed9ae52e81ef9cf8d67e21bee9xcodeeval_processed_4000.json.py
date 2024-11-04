





















  

















































def main():
	from sys import stdin,stdout
	ip=stdin.readline().strip()
	t=ip[0]
	for ch in ip[1:]:
		if len(t)>2:
			if (ch==t[-1] and t[-2]==t[-3] ) or (ch==t[-1] and t[-1]==t[-2]):
				continue
			else:
				t+=ch
		elif len(t)==2:
			if ch==t[-1] and ch==t[-2]:
				continue
			else:
				t+=ch
		else:
			t+=ch
	stdout.write(t)
if __name__=='__main__':
	main()
