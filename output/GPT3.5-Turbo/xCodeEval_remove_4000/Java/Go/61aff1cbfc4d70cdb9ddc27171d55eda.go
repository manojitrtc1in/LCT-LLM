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
	var firstOptimal, secondOptimal int64

	for firstCount := int64(0); ; firstCount++ {
		var firstSize, firstTime, firstCost int64
		for {
			firstSize += int64(id43)
			firstCost += int64(id77)
			firstTime += int64(id16 * id43)

			if firstSize >= int64(need) {
				firstSize = int64(need)
				firstTime = int64(id16 * firstSize)
			}

			id42 := maxTime - firstTime
			id74 := int64(need) - firstSize
			if id42 >= 0 {
				if id45 <= id90 {
					freeTime := id45 * id74
					if freeTime+firstTime <= maxTime {
						if answer > firstCost {
							answer = firstCost
							firstOptimal = firstCount
							secondOptimal = 0
						}
					}
				} else {
					id68 := id74 / id7
					id63 := id7 * id68
					id50 := id74 - id63

					id81 := id63 * id90
					id15 := id50 * id45

					if id81+id15 <= id42 {

						if answer > firstCost+id68*id51 {
							answer = firstCost + id68*id51
							firstOptimal = firstCount
							secondOptimal = id68
						}
					}

					id41 := id74 / id7
					if id74%id7 != 0 {
						id41++
					}
					id80 := min(id74, id7*id41)
					id21 := id74 - id80

					id97 := id80 * id90
					id98 := id21 * id45

					if id97+id98 <= id42 {
						if answer > firstCost+id41*id51 {
							answer = firstCost + id41*id51
							firstOptimal = firstCount
							secondOptimal = id41
						}

						id31 := ((id74*id45 - id42))
						id96 := (id45 - id90) * id7

						id14 := id31 / id96
						if id31 < 0 {
							id14 = 0
						} else if id31%id96 != 0 {
							id14++
						}
						if id14 >= 0 {
							id29 := min(id74, id7*id14)
							id38 := id74 - id29

							id48 := id29 * id90
							id70 := id38 * id45

							if id48+id70 <= id42 {

								if answer > firstCost+id14*id51 {
									answer = firstCost + id14*id51
									firstOptimal = firstCount
									secondOptimal = id14
								}
							}
						}
					}
				}
			}

			if firstSize >= int64(need) {
				break
			}
		}

		if firstSize >= int64(need) {
			break
		}
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
