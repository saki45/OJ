T = int(input())
while T>0:
	N = int(input())
	a = [int(i) for i in input().split(' ')]
	p = N-1
	curSum, curMax = 0, a[N-1]
	while p>=0:
		if a[p] > curMax:
			curMax = a[p]
		curSum += curMax-a[p]
		p -= 1
	print(curSum)
	T -= 1
