# solution for google code jam 2008 qualification A

# file I/O streams
fin = open('A-large-practice.in',mode='r')
fout = open('A-large-practice.out',mode='w')

# read in the number of test cases
numOfCase = int(fin.readline().rstrip('\n'))
curCase = 1

# solve result
while curCase <= numOfCase:
	# read in all the engines
	numOfEngine = int(fin.readline().rstrip('\n'))

	egNum = 0
	egHash = {}
	while egNum < numOfEngine:
		line = fin.readline()
		egHash[line] = egNum
		egNum += 1

	# read in number of queries
	numOfQuery = int(fin.readline().rstrip('\n'))
	qNum = 0
	
	# init variables
	prev = -1
	curMin = 0
	nMin = egNum
	status = [0 for i in range(0, numOfEngine)]

	# process the queries
	while qNum < numOfQuery:
		idx = egHash[fin.readline()]
		if idx != prev:
			# set value for prev
			if prev != -1:
				status[prev] = curMin + 1

			# set current value to MAX
			prev = idx
			if status[idx] == curMin:
				nMin -= 1
			status[idx] = 999999

			# find new minimum
			if nMin == 0:
				curMin = min(status)
				for i in status:
					if i == curMin:
						nMin += 1
		qNum += 1

	# output result for current case
	sol = "Case #" + str(curCase) + ": " + str(curMin)
	print(sol)
	fout.write(sol+'\n')
	curCase += 1		

fin.close()
fout.close()
