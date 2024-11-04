
T = int(input())
while T:
	T -= 1
	n = int(input())
	s = input()
	if len(s) == 1:
		print(s)
		continue
	ans = []
	cur = ""
	for i in range(n):
		if i + 1 < n and s[i] != s[i + 1]:
			cur += s[i]
			ans.append(cur)
			cur = ""
			continue
		cur += s[i]
	if cur != "":
		ans.append(cur)
	finalAns = ""
	check = False
	if len(ans) > 1 and ans[0][0] == '1' and ans[1][0] == '0':
		finalAns += '0'
	if ans[0][0] == '0':
		finalAns += ans[0]
		check = True
	if len(ans) > 2 and ans[1][0] == '1' and ans[2][0] == '0':
		finalAns += '0'
		check = True
	if ans[len(ans) - 1][0] == '1':
		finalAns += ans[len(ans) - 1]
		check = True
	if not check:
		print(0)
		continue
	print(finalAns)


