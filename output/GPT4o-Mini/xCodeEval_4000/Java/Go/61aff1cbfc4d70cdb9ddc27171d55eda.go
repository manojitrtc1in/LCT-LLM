package main

import (
	"bufio"
	"fmt"
	"math"
	"math/rand"
	"os"
	"strconv"
	"strings"
)

const MODULO = 1000 * 1000 * 1000 + 7

type C struct {
	in  *bufio.Reader
	out *bufio.Writer
}

func (c *C) solve1() {
	for it := 0; it < 10; it++ {
		need := rand.Intn(10000) + 1
		maxTime := rand.Int63n(10000000) + 1
		freeDefaultTime := rand.Int63n(10) + 1

		firstDefaultSize := rand.Intn(100) + 1
		firstDefaultTime := rand.Int63n(10) + 1
		firstDefaultCost := rand.Int63n(10) + 1

		secondDefaultSize := rand.Intn(100) + 1
		secondDefaultTime := rand.Int63n(10) + 1
		secondDefaultCost := rand.Int63n(10) + 1

		answer := c.getAnswer(int64(need), maxTime, freeDefaultTime,
			int64(firstDefaultSize), firstDefaultTime, firstDefaultCost,
			int64(secondDefaultSize), secondDefaultTime, secondDefaultCost)

		bruteAnswer := c.getBruteAnswer(need, maxTime, freeDefaultTime,
			firstDefaultSize, firstDefaultTime, firstDefaultCost,
			secondDefaultSize, secondDefaultTime, secondDefaultCost)

		if answer[0] != bruteAnswer[0] {
			fmt.Fprintln(os.Stderr, "GOTCHA")
			fmt.Fprintln(os.Stderr, answer)
			fmt.Fprintln(os.Stderr, bruteAnswer)
			fmt.Fprintln(os.Stderr, need, maxTime, firstDefaultTime)
			fmt.Fprintln(os.Stderr, firstDefaultSize, firstDefaultTime, firstDefaultCost)
			fmt.Fprintln(os.Stderr, secondDefaultSize, secondDefaultTime, secondDefaultCost)
		}
	}
}

func (c *C) solve() {
	need := c.readInt()
	maxTime := c.readInt()
	freeDefaultTime := c.readInt()

	firstDefaultSize := c.readInt()
	firstDefaultTime := c.readInt()
	firstDefaultCost := c.readInt()

	secondDefaultSize := c.readInt()
	secondDefaultTime := c.readInt()
	secondDefaultCost := c.readInt()

	answer := c.getAnswer(int64(need), int64(maxTime), int64(freeDefaultTime),
		int64(firstDefaultSize), int64(firstDefaultTime), int64(firstDefaultCost),
		int64(secondDefaultSize), int64(secondDefaultTime), int64(secondDefaultCost))

	c.out.WriteString(fmt.Sprintf("%d\n", answer[0]))
}

func (c *C) getAnswer(need, maxTime, freeDefaultTime,
	firstDefaultSize, firstDefaultTime, firstDefaultCost,
	secondDefaultSize, secondDefaultTime, secondDefaultCost int64) []int64 {
	answer := int64(math.MaxInt64)
	var firstOptimal, secondOptimal int64

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

					exactNumerator := (needUseSize * freeDefaultTime) - canUseTime
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
				lowerfirstSize := firstDefaultSize * lowerSideCount
				lowerFreeSize := needUseSize - lowerfirstSize

				lowerfirstTime := lowerfirstSize * firstDefaultTime
				lowerFreeTime := lowerFreeSize * freeDefaultTime

				if lowerfirstTime+lowerFreeTime <= canUseTime {
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
				upperfirstSize := min(needUseSize, firstDefaultSize*upperSideCount)
				upperFreeSize := needUseSize - upperfirstSize

				upperfirstTime := upperfirstSize * firstDefaultTime
				upperFreeTime := upperFreeSize * freeDefaultTime

				if upperfirstTime+upperFreeTime <= canUseTime {
					if answer > secondCost+upperSideCount*firstDefaultCost {
						answer = secondCost + upperSideCount*firstDefaultCost
						secondOptimal = secondCount
						firstOptimal = upperSideCount
					}

					exactNumerator := (needUseSize * freeDefaultTime) - canUseTime
					exactDenominator := (freeDefaultTime - firstDefaultTime) * firstDefaultSize

					exactSideCount := exactNumerator / exactDenominator
					if exactNumerator < 0 {
						exactSideCount = 0
					} else if exactNumerator%exactDenominator != 0 {
						exactSideCount++
					}
					if exactSideCount >= 0 {
						exactfirstSize := min(needUseSize, firstDefaultSize*exactSideCount)
						exactFreeSize := needUseSize - exactfirstSize

						exactfirstTime := exactfirstSize * firstDefaultTime
						exactFreeTime := exactFreeSize * freeDefaultTime

						if exactfirstTime+exactFreeTime <= canUseTime {
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

	if answer == int64(math.MaxInt64) {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
}

func (c *C) getBruteAnswer(need int, maxTime int64, freeDefaultTime int64,
	firstDefaultSize int, firstDefaultTime int64, firstDefaultCost int64,
	secondDefaultSize int, secondDefaultTime int64, secondDefaultCost int64) []int64 {
	answer := int64(math.MaxInt64)
	var firstOptimal, secondOptimal int64

	for firstCount := 0; ; firstCount++ {
		firstSize := min(need, firstCount*firstDefaultSize)
		if firstSize >= need {
			firstSize = need
		}

		firstTime := int64(firstSize) * firstDefaultTime
		firstCost := int64(firstCount) * firstDefaultCost

		needUseSize := need - firstSize
		for secondCount := 0; ; secondCount++ {
			secondSize := min(needUseSize, secondCount*secondDefaultSize)
			if secondSize >= needUseSize {
				secondSize = needUseSize
			}

			secondTime := int64(secondSize) * secondDefaultTime
			secondCost := int64(secondCount) * secondDefaultCost

			freeSize := needUseSize - secondSize
			freeTime := freeSize * freeDefaultTime

			if firstTime+secondTime+freeTime <= maxTime {
				if answer > firstCost+secondCost {
					answer = firstCost + secondCost
					firstOptimal = int64(firstCount)
					secondOptimal = int64(secondCount)
				}
			}

			if secondSize >= needUseSize {
				break
			}
		}

		if firstSize >= need {
			break
		}
	}

	if answer == int64(math.MaxInt64) {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
}

func (c *C) readInt() int {
	line, _ := c.in.ReadString('\n')
	num, _ := strconv.Atoi(strings.TrimSpace(line))
	return num
}

func (c *C) main() {
	c.in = bufio.NewReader(os.Stdin)
	c.out = bufio.NewWriter(os.Stdout)
	defer c.out.Flush()

	c.solve()
}

func main() {
	rand.Seed(1) // Seed for reproducibility
	c := &C{}
	c.main()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
