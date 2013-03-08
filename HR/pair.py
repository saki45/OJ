def findPair(nums, k):

	ht = {}
	pairCount = 0

	for i in nums:
		if i not in ht.keys():
			ht[i] = 1
			if (i-k) in ht.keys():
				pairCount += 1
			if (i+k) in ht.keys():
				pairCount += 1
	print(pairCount)

if __name__ == '__main__':
	N, k = [int(i) for i in input().split(' ')]
	nums = [int(i) for i in input().split(' ')]

	findPair(nums, k)
