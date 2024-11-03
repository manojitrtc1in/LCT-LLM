import random
import math
from collections import deque

class C:
    def __init__(self):
        self.MAX_RND = 10
        self.MODULO = 1000 * 1000 * 1000 + 7
        self.rnd = random.Random()
        self.fileName = ""

    def solve1(self):
        for it in range(10):
            need = self.rnd.randint(1, 10000)
            maxTime = self.rnd.randint(1, 10000000)
            freeDefaultTime = self.rnd.randint(1, 10)

            firstDefaultSize = self.rnd.randint(1, 100)
            firstDefaultTime = self.rnd.randint(1, 10)
            firstDefaultCost = self.rnd.randint(1, 10)

            secondDefaultSize = self.rnd.randint(1, 100)
            secondDefaultTime = self.rnd.randint(1, 10)
            secondDefaultCost = self.rnd.randint(1, 10)

            answer = self.getAnswer(need, maxTime, freeDefaultTime,
                                    firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                    secondDefaultSize, secondDefaultTime, secondDefaultCost)

            bruteAnswer = self.getBruteAnswer(need, maxTime, freeDefaultTime,
                                            firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                            secondDefaultSize, secondDefaultTime, secondDefaultCost)

            if answer[0] != bruteAnswer[0]:
                print("GOTCHA")
                print(answer)
                print(bruteAnswer)
                print(need, maxTime, firstDefaultTime)
                print(firstDefaultSize, firstDefaultTime, firstDefaultCost)
                print(secondDefaultSize, secondDefaultTime, secondDefaultCost)

    def solve(self):
        need = self.readInt()
        maxTime = self.readInt()
        freeDefaultTime = self.readInt()

        firstDefaultSize = self.readInt()
        firstDefaultTime = self.readInt()
        firstDefaultCost = self.readInt()

        secondDefaultSize = self.readInt()
        secondDefaultTime = self.readInt()
        secondDefaultCost = self.readInt()

        answer = self.getAnswer(need, maxTime, freeDefaultTime,
                                firstDefaultSize, firstDefaultTime, firstDefaultCost,
                                secondDefaultSize, secondDefaultTime, secondDefaultCost)

        print(answer[0])

    def getAnswer(self, need, maxTime, freeDefaultTime,
                    firstDefaultSize, firstDefaultTime, firstDefaultCost,
                    secondDefaultSize, secondDefaultTime, secondDefaultCost):
        answer = float('inf')
        firstOptimal, secondOptimal = 0, 0

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

        for secondCount in range(0, self.MAX_RND):
            secondSize = 0
            secondCost = 0
            secondTime = 0
            while True:
                secondCount += 1
                secondSize += secondDefaultSize
                secondCost += secondDefaultCost
                secondTime += secondDefaultTime * secondDefaultSize

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

    def getBruteAnswer(self, need, maxTime, freeDefaultTime,
                        firstDefaultSize, firstDefaultTime, firstDefaultCost,
                        secondDefaultSize, secondDefaultTime, secondDefaultCost):
        answer = float('inf')
        firstOptimal, secondOptimal = 0, 0

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

        for secondCount in range(0, self.MAX_RND):
            secondSize = 0
            secondCost = 0
            secondTime = 0
            while True:
                secondCount += 1
                secondSize += secondDefaultSize
                secondCost += secondDefaultCost
                secondTime += secondDefaultTime * secondDefaultSize

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

    def getBruteAnswer(self, need, maxTime, freeDefaultTime,
                        firstDefaultSize, firstDefaultTime, firstDefaultCost,
                        secondDefaultSize, secondDefaultTime, secondDefaultCost):
        answer = float('inf')
        firstOptimal, secondOptimal = 0, 0

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

        for secondCount in range(0, self.MAX_RND):
            secondSize = 0
            secondCost = 0
            secondTime = 0
            while True:
                secondCount += 1
                secondSize += secondDefaultSize
                secondCost += secondDefaultCost
                secondTime += secondDefaultTime * secondDefaultSize

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

