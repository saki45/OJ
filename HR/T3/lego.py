MAX = 1000000007

def calcLevels(levels):
	N = len(levels)
	M = len(levels[1])

	levels[1][0] = 1
	p = 1
	while p<M:
		i = 1
		while i<=4 and p-i>=0:
			levels[1][p] = (levels[1][p] + levels[1][p-i]) % MAX
			#print(p, i, levels[1][p])
			i += 1
		p += 1
	n = 2
	while n<N:
		p = 1
		while p<M:
			levels[n][p] = (levels[n-1][p]*levels[1][p]) % MAX
			p += 1
		n += 1

def getDP(dp, levels, N, M):
	if dp[N][M] != 0 or N == 1:
		return dp[N][M]

	curTmp = levels[N][M]
	p = 1
	while p < M:
		if dp[N][p] == 0:
			curTmpLow = levels[N][p]
			q = 1
			while q<p:
				curTmpLow = (curTmpLow - dp[N][q]*levels[N][p-q]) % MAX
				q += 1
			dp[N][p] = curTmpLow
		curTmp = (curTmp - dp[N][p]*levels[N][M-p]) % MAX
		p += 1

	dp[N][M] = curTmp
	#print(N, M, dp[N])
	return dp[N][M]

if __name__ == '__main__':
	T = int(input())
	inputs = [[0, 0] for i in range(T)]
	maxN, maxM = 0, 0
	p = 0
	while p<T:
		N, M = [int(i) for i in input().split(' ')]
		if N>maxN:
			maxN = N
		if M>maxM:
			maxM = M
		inputs[p][:] = N, M
		p += 1

	levels = [[0 for i in range(maxM+1)] for j in range(maxN+1)]
	dp = [[0 for i in range(maxM+1)] for j in range(maxN+1)]

	calcLevels(levels)

	p = 0
	while p<=maxN:
		dp[p][1] = 1
		p += 1
	p = 1
	while p<=min(maxM,4):
		dp[1][p] = 1
		p += 1

	p = 0
	while p<T:
		N, M = inputs[p]
		if N == 1 and M>=1 and M<=4:
			print(1)
		elif N == 1:
			print(0)
		else:
			print(getDP(dp, levels, N, M))
		p += 1
