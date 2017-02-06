input = raw_input()
for a in range(int(input)):
	x1, x2 = raw_input().split()
	print int(str(int(str(x1)[::-1]) + int(str(x2)[::-1]))[::-1])
