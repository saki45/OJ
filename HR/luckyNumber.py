def getPrimeMap(N):
	pMap = [True for i in range(N+1)]
	pMap[0:2] = [False]*2

	for i in range(2, int(N**0.5)+2):
		if pMap[i]:
			j = 2*i
			while j<=N:
				pMap[j] = False
				j += i
	return pMap

def preprocess(N):
	s1 = [0 for i in range(N)]
	s2 = [0 for i in range(N)]

	for i in range(N):
		ti = i
		while ti>0:
			digit = ti%10
			s1[i] += digit
			s2[i] += digit*digit
			ti = ti//10
	return s1, s2

if __name__ == '__main__':
	N = 1000000
	primeMap = getPrimeMap(81*18+1)
	sm1, sm2 = preprocess(N)

	T = int(input())
	while T>0:
		A, B = [int(i) for i in input().split(' ')]
		count = 0
		for i in range(A, B+1):
			s1, s2 = 0, 0
			ti = i
			while ti > 0:
				digit = ti%N
				s1 += sm1[digit]
				s2 += sm2[digit]
				ti = ti//N
			if primeMap[s1] and primeMap[s2]:
				count += 1
		print(count)
		T -= 1
