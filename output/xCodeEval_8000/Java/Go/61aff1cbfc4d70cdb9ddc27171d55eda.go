package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	in  = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
)

func main() {
	defer out.Flush()

	solve()
}

func solve() {
	need := readInt()
	maxTime := readInt()
	freeDefaultTime := readInt()

	firstDefaultSize := readInt()
	firstDefaultTime := readInt()
	firstDefaultCost := readInt()

	secondDefaultSize := readInt()
	secondDefaultTime := readInt()
	secondDefaultCost := readInt()

	answer := getAnswer(need, maxTime, freeDefaultTime,
		firstDefaultSize, firstDefaultTime, firstDefaultCost,
		secondDefaultSize, secondDefaultTime, secondDefaultCost)

	fmt.Fprintln(out, answer[0])
}

func getAnswer(need int64, maxTime int64, freeDefaultTime int64,
	firstDefaultSize int64, firstDefaultTime int64, firstDefaultCost int64,
	secondDefaultSize int64, secondDefaultTime int64, secondDefaultCost int64) []int64 {
	answer := int64(1<<63 - 1)
	firstOptimal, secondOptimal := int64(0), int64(0)

	for firstCount, firstSize, firstTime, firstCost := int64(0), int64(0), int64(0), int64(0); ; firstCount++ {
		firstSize += firstDefaultSize
		firstCost += firstDefaultCost
		firstTime += firstDefaultTime * firstDefaultSize

		if firstSize >= need {
			firstSize = need
			firstTime = firstDefaultTime * firstSize
		}

		canUseTime := maxTime - firstTime
		needUseSize := need - firstSize

		if canUseTime >= 0 {
			if freeDefaultTime <= secondDefaultTime {
				freeTime := freeDefaultTime * needUseSize
				if freeTime+firstTime <= maxTime {
					if answer > firstCost {
						answer = firstCost
						firstOptimal = firstCount
						secondOptimal = 0
					}
				}
			} else {
				lowerSideCount := needUseSize / secondDefaultSize
				lowerSecondSize := secondDefaultSize * lowerSideCount
				lowerFreeSize := needUseSize - lowerSecondSize

				lowerSecondTime := lowerSecondSize * secondDefaultTime
				lowerFreeTime := lowerFreeSize * freeDefaultTime

				if lowerSecondTime+lowerFreeTime <= canUseTime {

					if answer > firstCost+lowerSideCount*secondDefaultCost {
						answer = firstCost + lowerSideCount*secondDefaultCost
						firstOptimal = firstCount
						secondOptimal = lowerSideCount
					}
				}

				upperSideCount := needUseSize / secondDefaultSize
				if needUseSize%secondDefaultSize != 0 {
					upperSideCount++
				}
				upperSecondSize := min(needUseSize, secondDefaultSize*upperSideCount)
				upperFreeSize := needUseSize - upperSecondSize

				upperSecondTime := upperSecondSize * secondDefaultTime
				upperFreeTime := upperFreeSize * freeDefaultTime

				if upperSecondTime+upperFreeTime <= canUseTime {
					if answer > firstCost+upperSideCount*secondDefaultCost {
						answer = firstCost + upperSideCount*secondDefaultCost
						firstOptimal = firstCount
						secondOptimal = upperSideCount
					}

					exactNumerator := ((needUseSize*freeDefaultTime - canUseTime))
					exactDenominator := (freeDefaultTime - secondDefaultTime) * secondDefaultSize

					exactSideCount := exactNumerator / exactDenominator
					if exactNumerator < 0 {
						exactSideCount = 0
					} else if exactNumerator%exactDenominator != 0 {
						exactSideCount++
					}
					if exactSideCount >= 0 {
						exactSecondSize := min(needUseSize, secondDefaultSize*exactSideCount)
						exactFreeSize := needUseSize - exactSecondSize

						exactSecondTime := exactSecondSize * secondDefaultTime
						exactFreeTime := exactFreeSize * freeDefaultTime

						if exactSecondTime+exactFreeTime <= canUseTime {

							if answer > firstCost+exactSideCount*secondDefaultCost {
								answer = firstCost + exactSideCount*secondDefaultCost
								firstOptimal = firstCount
								secondOptimal = exactSideCount
							}
						}
					}
				}
			}
		}

		if firstSize >= need {
			break
		}
	}

	for secondCount, secondSize, secondCost, secondTime := int64(0), int64(0), int64(0), int64(0); ; secondCount++ {
		secondSize += secondDefaultSize
		secondCost += secondDefaultCost
		secondTime += secondDefaultTime * secondDefaultSize

		if secondSize >= need {
			secondSize = need
			secondTime = secondDefaultTime * secondSize
		}

		canUseTime := maxTime - secondTime
		needUseSize := need - secondSize

		if canUseTime >= 0 {
			if freeDefaultTime <= firstDefaultTime {
				freeTime := freeDefaultTime * needUseSize
				if freeTime+secondTime <= maxTime {
					if answer > secondCost {
						answer = secondCost
						secondOptimal = secondCount
						firstOptimal = 0
					}
				}
			} else {
				lowerSideCount := needUseSize / firstDefaultSize
				lowerFirstSize := firstDefaultSize * lowerSideCount
				lowerFreeSize := needUseSize - lowerFirstSize

				lowerFirstTime := lowerFirstSize * firstDefaultTime
				lowerFreeTime := lowerFreeSize * freeDefaultTime

				if lowerFirstTime+lowerFreeTime <= canUseTime {

					if answer > secondCost+lowerSideCount*firstDefaultCost {
						answer = secondCost + lowerSideCount*firstDefaultCost
						secondOptimal = secondCount
						firstOptimal = lowerSideCount
					}
				}

				upperSideCount := needUseSize / firstDefaultSize
				if needUseSize%firstDefaultSize != 0 {
					upperSideCount++
				}
				upperFirstSize := min(needUseSize, firstDefaultSize*upperSideCount)
				upperFreeSize := needUseSize - upperFirstSize

				upperFirstTime := upperFirstSize * firstDefaultTime
				upperFreeTime := upperFreeSize * freeDefaultTime

				if upperFirstTime+upperFreeTime <= canUseTime {
					if answer > secondCost+upperSideCount*firstDefaultCost {
						answer = secondCost + upperSideCount*firstDefaultCost
						secondOptimal = secondCount
						firstOptimal = upperSideCount
					}

					exactNumerator := ((needUseSize*freeDefaultTime - canUseTime))
					exactDenominator := (freeDefaultTime - firstDefaultTime) * firstDefaultSize

					exactSideCount := exactNumerator / exactDenominator
					if exactNumerator < 0 {
						exactSideCount = 0
					} else if exactNumerator%exactDenominator != 0 {
						exactSideCount++
					}
					if exactSideCount >= 0 {
						exactFirstSize := min(needUseSize, firstDefaultSize*exactSideCount)
						exactFreeSize := needUseSize - exactFirstSize

						exactFirstTime := exactFirstSize * firstDefaultTime
						exactFreeTime := exactFreeSize * freeDefaultTime

						if exactFirstTime+exactFreeTime <= canUseTime {

							if answer > secondCost+exactSideCount*firstDefaultCost {
								answer = secondCost + exactSideCount*firstDefaultCost
								secondOptimal = secondCount
								firstOptimal = exactSideCount
							}
						}
					}
				}
			}
		}

		if secondSize >= need {
			break
		}
	}

	if answer == 1<<63-1 {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func readString() string {
	str, _ := in.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func readInt() int64 {
	str := readString()
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}
