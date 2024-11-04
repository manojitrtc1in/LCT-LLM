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

func getAnswer(need int, maxTime int, freeDefaultTime int,
	firstDefaultSize int, firstDefaultTime int, firstDefaultCost int,
	secondDefaultSize int, secondDefaultTime int, secondDefaultCost int) []int {
	answer := []int{1<<31 - 1, 0, 0}

	for firstCount := 0; ; firstCount++ {
		firstSize := min(need, firstCount*firstDefaultSize)
		if firstSize >= need {
			firstSize = need
		}

		firstTime := firstSize * firstDefaultTime
		firstCost := firstCount * firstDefaultCost

		needUseSize := need - firstSize
		for secondCount := 0; ; secondCount++ {
			secondSize := min(needUseSize, secondCount*secondDefaultSize)
			if secondSize >= needUseSize {
				secondSize = needUseSize
			}

			secondTime := secondSize * secondDefaultTime
			secondCost := secondCount * secondDefaultCost

			freeSize := needUseSize - secondSize
			freeTime := freeSize * freeDefaultTime

			if firstTime+secondTime+freeTime <= maxTime {
				if answer[0] > firstCost+secondCost {
					answer[0] = firstCost + secondCost
					answer[1] = firstCount
					answer[2] = secondCount
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

	if answer[0] == 1<<31-1 {
		answer[0] = -1
	}

	return answer
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func readString() string {
	str, _ := in.ReadString('\n')
	return strings.TrimRight(str, "\r\n")
}

func readInt() int {
	str := readString()
	num, _ := strconv.Atoi(str)
	return num
}
