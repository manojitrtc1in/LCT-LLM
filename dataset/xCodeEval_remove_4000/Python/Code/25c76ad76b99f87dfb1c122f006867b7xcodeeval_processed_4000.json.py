
n = int(input())
x, y = 0, 0
print(7 + 3 * (n - 1))
print(x, y)
print(x + 1, y)
print(x, y + 1)
print(x + 1, y + 1)
print(x + 2, y + 1)
print(x + 1, y + 2)
print(x + 2, y + 2)
x += 1
y += 1
for i in range(n - 1):
	print(x + 2, y + 1)
	print(x + 1, y + 2)
	print(x + 2, y + 2)
	x += 1
	y += 1
	
