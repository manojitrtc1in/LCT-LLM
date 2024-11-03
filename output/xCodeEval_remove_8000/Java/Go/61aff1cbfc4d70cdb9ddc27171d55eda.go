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
	id45 := readInt()

	id43 := readInt()
	id16 := readInt()
	id77 := readInt()

	id7 := readInt()
	id90 := readInt()
	id51 := readInt()

	answer := getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

	fmt.Fprintln(out, answer[0])
}

func getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51 int) []int64 {
	answer := int64(1<<63 - 1)
	firstOptimal, secondOptimal := int64(0), int64(0)

	for firstCount := int64(0); ; firstCount++ {
		firstSize := firstCount * int64(id43)
		if firstSize >= int64(need) {
			firstSize = int64(need)
		}

		firstTime := firstSize * int64(id16)
		firstCost := firstCount * int64(id77)

		id74 := int64(need) - firstSize
		for secondCount := int64(0); ; secondCount++ {
			secondSize := secondCount * int64(id7)
			if secondSize >= id74 {
				secondSize = id74
			}

			secondTime := secondSize * int64(id90)
			secondCost := secondCount * int64(id51)

			freeSize := id74 - secondSize
			freeTime := freeSize * int64(id45)

			if firstTime+secondTime+freeTime <= int64(maxTime) {
				if answer > firstCost+secondCost {
					answer = firstCost + secondCost
					firstOptimal = firstCount
					secondOptimal = secondCount
				}
			}

			if secondSize >= id74 {
				break
			}
		}

		if firstSize >= int64(need) {
			break
		}
	}

	if answer == int64(1<<63-1) {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
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
