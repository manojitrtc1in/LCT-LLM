





















  

























































































def main():
	from sys import stdin,stdout
	import collections
	inp = stdin.readline().strip()
	out = stdin.readline().strip()
	counter = 0
	flag = True
	inp = collections.Counter(inp)
	out = collections.Counter(out)
	for key in out:
		if inp[key]:
			counter += min(inp[key],out[key])
		else:
			flag = False
			break
	if flag:
		stdout.write(str(counter))
	else:
		stdout.write('-1')
if __name__=='__main__':
	main()
