









	





	

 





















































s = input()
w = len(s)
n=int(input())
b=[]
for i in range(n):
  wd=input()
  if wd[:w]==s:
    b.append(wd)
b.sort()
if len(b)==0:
  print(s)
else:
  print(min(b))
