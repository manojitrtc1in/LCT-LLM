import random

MODULO = 1000 * 1000 * 1000 + 7

def solve1():
    for it in range(10):
        need = random.randint(1, 10000)
        maxTime = random.randint(1, 10000000)
        freeDefaultTime = random.randint(1, 10)

        firstDefaultSize = random.randint(1, 100)
        firstDefaultTime = random.randint(1, 10)
        firstDefaultCost = random.randint(1, 10)

        secondDefaultSize = random.randint(1, 100)
        secondDefaultTime = random.randint(1, 10)
        secondDefaultCost = random.randint(1, 10)

        answer = getAnswer(need, maxTime, freeDefaultTime,
                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                secondDefaultSize, secondDefaultTime, secondDefaultCost)

        bruteAnswer = getBruteAnswer(need, maxTime, freeDefaultTime,
                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                secondDefaultSize, secondDefaultTime, secondDefaultCost)

        if answer[0] != bruteAnswer[0]:
            print("GOTCHA")

            print(answer)
            print(bruteAnswer)
            print(need, maxTime, firstDefaultTime)
            print(firstDefaultSize, firstDefaultTime, firstDefaultCost)
            print(secondDefaultSize, secondDefaultTime, secondDefaultCost)

def solve():
    need = readInt()
    maxTime = readInt()
    freeDefaultTime = readInt()

    firstDefaultSize = readInt()
    firstDefaultTime = readInt()
    firstDefaultCost = readInt()

    secondDefaultSize = readInt()
    secondDefaultTime = readInt()
    secondDefaultCost = readInt()

    answer = getAnswer(need, maxTime, freeDefaultTime,
            firstDefaultSize, firstDefaultTime, firstDefaultCost,
            secondDefaultSize, secondDefaultTime, secondDefaultCost)

    print(answer[0])

def getAnswer(need, maxTime, freeDefaultTime,
                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                secondDefaultSize, secondDefaultTime, secondDefaultCost):
    answer = float('inf')
    firstOptimal = 0
    secondOptimal = 0

    firstCount = 0
    firstSize = 0
    firstTime = 0
    firstCost = 0
    while True:
        firstCount += 1
        firstSize += firstDefaultSize
        firstCost += firstDefaultCost
        firstTime += firstDefaultTime * firstDefaultSize

        if firstSize >= need:
            firstSize = need
            firstTime = firstDefaultTime * firstSize

        canUseTime = maxTime - firstTime
        needUseSize = need - firstSize
        if canUseTime >= 0:
            if freeDefaultTime <= secondDefaultTime:
                freeTime = freeDefaultTime * needUseSize
                if freeTime + firstTime <= maxTime:
                    if answer > firstCost:
                        answer = firstCost
                        firstOptimal = firstCount
                        secondOptimal = 0
            else:
                lowerSideCount = needUseSize // secondDefaultSize
                lowerSecondSize = secondDefaultSize * lowerSideCount
                lowerFreeSize = needUseSize - lowerSecondSize

                lowerSecondTime = lowerSecondSize * secondDefaultTime
                lowerFreeTime = lowerFreeSize * freeDefaultTime

                if lowerSecondTime + lowerFreeTime <= canUseTime:
                    if answer > firstCost + lowerSideCount * secondDefaultCost:
                        answer = firstCost + lowerSideCount * secondDefaultCost
                        firstOptimal = firstCount
                        secondOptimal = lowerSideCount

                upperSideCount = needUseSize // secondDefaultSize
                if needUseSize % secondDefaultSize != 0:
                    upperSideCount += 1
                upperSecondSize = min(needUseSize, secondDefaultSize * upperSideCount)
                upperFreeSize = needUseSize - upperSecondSize

                upperSecondTime = upperSecondSize * secondDefaultTime
                upperFreeTime = upperFreeSize * freeDefaultTime

                if upperSecondTime + upperFreeTime <= canUseTime:
                    if answer > firstCost + upperSideCount * secondDefaultCost:
                        answer = firstCost + upperSideCount * secondDefaultCost
                        firstOptimal = firstCount
                        secondOptimal = upperSideCount

                    exactNumerator = ((needUseSize * freeDefaultTime - canUseTime))
                    exactDenominator = (freeDefaultTime - secondDefaultTime) * secondDefaultSize

                    exactSideCount = exactNumerator // exactDenominator
                    if exactNumerator < 0:
                        exactSideCount = 0
                    elif exactNumerator % exactDenominator != 0:
                        exactSideCount += 1
                    if exactSideCount >= 0:
                        exactSecondSize = min(needUseSize, secondDefaultSize * exactSideCount)
                        exactFreeSize = needUseSize - exactSecondSize

                        exactSecondTime = exactSecondSize * secondDefaultTime
                        exactFreeTime = exactFreeSize * freeDefaultTime

                        if exactSecondTime + exactFreeTime <= canUseTime:
                            if answer > firstCost + exactSideCount * secondDefaultCost:
                                answer = firstCost + exactSideCount * secondDefaultCost
                                firstOptimal = firstCount
                                secondOptimal = exactSideCount

        if firstSize >= need:
            break

    for secondCount in range(0, 1000000000):
        secondSize = 0
        secondCost = 0
        secondTime = 0

        if secondSize >= need:
            secondSize = need
            secondTime = secondDefaultTime * secondSize

        canUseTime = maxTime - secondTime
        needUseSize = need - secondSize
        if canUseTime >= 0:
            if freeDefaultTime <= firstDefaultTime:
                freeTime = freeDefaultTime * needUseSize
                if freeTime + secondTime <= maxTime:
                    if answer > secondCost:
                        answer = secondCost
                        secondOptimal = secondCount
                        firstOptimal = 0
            else:
                lowerSideCount = needUseSize // firstDefaultSize
                lowerFirstSize = firstDefaultSize * lowerSideCount
                lowerFreeSize = needUseSize - lowerFirstSize

                lowerFirstTime = lowerFirstSize * firstDefaultTime
                lowerFreeTime = lowerFreeSize * freeDefaultTime

                if lowerFirstTime + lowerFreeTime <= canUseTime:
                    if answer > secondCost + lowerSideCount * firstDefaultCost:
                        answer = secondCost + lowerSideCount * firstDefaultCost
                        secondOptimal = secondCount
                        firstOptimal = lowerSideCount

                upperSideCount = needUseSize // firstDefaultSize
                if needUseSize % firstDefaultSize != 0:
                    upperSideCount += 1
                upperFirstSize = min(needUseSize, firstDefaultSize * upperSideCount)
                upperFreeSize = needUseSize - upperFirstSize

                upperFirstTime = upperFirstSize * firstDefaultTime
                upperFreeTime = upperFreeSize * freeDefaultTime

                if upperFirstTime + upperFreeTime <= canUseTime:
                    if answer > secondCost + upperSideCount * firstDefaultCost:
                        answer = secondCost + upperSideCount * firstDefaultCost
                        secondOptimal = secondCount
                        firstOptimal = upperSideCount

                    exactNumerator = ((needUseSize * freeDefaultTime - canUseTime))
                    exactDenominator = (freeDefaultTime - firstDefaultTime) * firstDefaultSize

                    exactSideCount = exactNumerator // exactDenominator
                    if exactNumerator < 0:
                        exactSideCount = 0
                    elif exactNumerator % exactDenominator != 0:
                        exactSideCount += 1
                    if exactSideCount >= 0:
                        exactFirstSize = min(needUseSize, firstDefaultSize * exactSideCount)
                        exactFreeSize = needUseSize - exactFirstSize

                        exactFirstTime = exactFirstSize * firstDefaultTime
                        exactFreeTime = exactFreeSize * freeDefaultTime

                        if exactFirstTime + exactFreeTime <= canUseTime:
                            if answer > secondCost + exactSideCount * firstDefaultCost:
                                answer = secondCost + exactSideCount * firstDefaultCost
                                secondOptimal = secondCount
                                firstOptimal = exactSideCount

        if secondSize >= need:
            break

    if answer == float('inf'):
        answer = -1

    return [answer, firstOptimal, secondOptimal]

def getBruteAnswer(need, maxTime, freeDefaultTime,
                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                secondDefaultSize, secondDefaultTime, secondDefaultCost):
    answer = float('inf')
    firstOptimal = 0
    secondOptimal = 0

    for firstCount in range(0, 1000000000):
        firstSize = min(need, firstCount * firstDefaultSize)
        if firstSize >= need:
            firstSize = need

        firstTime = firstSize * firstDefaultTime
        firstCost = firstCount * firstDefaultCost

        needUseSize = (need - firstSize)
        for secondCount in range(0, 1000000000):
            secondSize = min(needUseSize, secondCount * secondDefaultSize)
            if secondSize >= needUseSize:
                secondSize = needUseSize

            secondTime = secondSize * secondDefaultTime
            secondCost = secondCount * secondDefaultCost

            freeSize = needUseSize - secondSize
            freeTime = freeSize * freeDefaultTime

            if firstTime + secondTime + freeTime <= maxTime:
                if answer > firstCost + secondCost:
                    answer = firstCost + secondCost
                    firstOptimal = firstCount
                    secondOptimal = secondCount

            if secondSize >= needUseSize:
                break

        if firstSize >= need:
            break

    if answer == float('inf'):
        answer = -1

    return [answer, firstOptimal, secondOptimal]

def add(a, b):
    return (a + b) % MODULO

def subtract(a, b):
    return add(a, MODULO - b)

def mult(a, b):
    return (a * b) % MODULO

def main():
    solve()

if __name__ == "__main__":
    main()
