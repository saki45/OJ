# solution to google code jam 2008 qualification B

# convert time from format HH:MM to HH*24+MM and into integer
def convertTime(record):
	HH, MM = [int(i) for i in record.split(':')]
	return HH*60+MM

# convert a line of times into two integers stored in tuple
def processTime(line):
	times = line.split(' ')
	return (convertTime(times[0]), convertTime(times[1]))
		
# find the first available trip
def findNextTrip(edTime, tList, prev, label):
	# the next available trip is the one that dList[i][0]>=edTime and prev[i][0] != label
	st, ed = 0, len(tList) - 1
	while st<=ed:
		mid = (st+ed)//2
		if tList[mid][0] < edTime:
			st = mid+1
		else:
			ed = mid-1
	idx = st
	# cannot find the start
	if idx<0 or idx>=len(tList):
		return -1
	else:
		while idx<len(tList) and prev[idx][0] == label:
			idx += 1
		if idx >= len(tList):
			return -1
		else:
			return idx

fin = open('B-large-practice.in', mode = 'r')
fout = open('B-large-practice.out', mode = 'w')

# get number of cases
numOfCase = int(fin.readline().rstrip('\n'))
curCase = 1

# process each cases
while curCase <= numOfCase:
	# get turnaround time
	tTime = int(fin.readline().rstrip('\n'))

	# get NA and NB
	NA, NB = [int(i) for i in fin.readline().rstrip('\n').split(' ')]

	# num of trains needed starting from A and B
	nTA, nTB = 0, 0

	# if NA or NB is 0 then the answer is the number of trains starting from the other station
	if NA == 0:
		nTB = NB
	elif NB == 0:
		nTA = NA
	else:
		# general case

		# read in train timetable from A to B
		tA = []
		for i in range(0, NA):
			tA.append(processTime(fin.readline().strip('\n')))
		tB = []
		for i in range(0, NB):
			tB.append(processTime(fin.readline().strip('\n')))

		# sort the time periods to make sure early starting time comes first
		tA.sort()
		tB.sort()

		# startA, startB: the first trip of the same train for the current trip
		startA = [[0, 0] for i in range(0, NA)]
		startB = [[0, 0] for i in range(0, NB)]
		# prevA, prevB: the previous trip for the same train for the current trip
		prevA = [[0, 0] for i in range(0, NA)]
		prevB = [[0, 0] for i in range(0, NB)]

		# process the records from A to B, initially we need NA train from A to B
		pTrip = 0
		nTA = NA
		while pTrip < NA:
			# get the first available trip from B to A to follow the current trip
			idx = findNextTrip(tA[pTrip][1]+tTime, tB, prevB, 1)

			# if find, link that trip to the current trip
			if idx >= 0:
				prevB[idx][0] = 1
				prevB[idx][1] = pTrip
				startB[idx][0] = 1
				startB[idx][1] = pTrip

			startA[pTrip][0] = 1
			startA[pTrip][1] = pTrip
			pTrip += 1

		# process the records from B to A, link the corresponding Trips
		pTrip = 0
		while pTrip < NB:
			# if current trip cannot be reached by any trip from A to B then start a new trip from B
			if startB[pTrip][0] == 0:
				nTB += 1
				startB[pTrip][0] = 2
				startB[pTrip][1] = pTrip
			else:
			# update the starting trip of current trip
				prev = prevB[pTrip][1]
				startB[pTrip][0] = startA[prev][0]
				startB[pTrip][1] = startA[prev][1]
			
			# get the first available trip from A to B to follow the current trip
			idx = findNextTrip(tB[pTrip][1] + tTime, tA, prevA, 2)

			# if find, link that trip to current trip
			if idx >= 0:
				prevA[idx][0] = 2
				prevA[idx][1] = pTrip
				startA[idx][0] = startB[pTrip][0]
				startA[idx][1] = startB[pTrip][1]

				nTA -= 1

			pTrip += 1

	resultLine = 'Case #' + str(curCase)+ ": " + str(nTA) + ' ' + str(nTB)
	print(resultLine)
	fout.write(resultLine + '\n')
	curCase += 1

fin.close()
fout.close()
