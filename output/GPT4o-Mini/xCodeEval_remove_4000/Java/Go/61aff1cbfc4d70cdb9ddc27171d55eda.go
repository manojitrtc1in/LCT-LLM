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
		id45 := rand.Int63n(10) + 1

		id43 := rand.Intn(100) + 1
		id16 := rand.Int63n(10) + 1
		id77 := rand.Int63n(10) + 1

		id7 := rand.Intn(100) + 1
		id90 := rand.Int63n(10) + 1
		id51 := rand.Int63n(10) + 1

		answer := c.getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

		id59 := c.id52(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

		if answer[0] != id59[0] {
			fmt.Fprintln(os.Stderr, "GOTCHA")
			fmt.Fprintln(os.Stderr, answer)
			fmt.Fprintln(os.Stderr, id59)
			fmt.Fprintln(os.Stderr, need, maxTime, id16)
			fmt.Fprintln(os.Stderr, id43, id16, id77)
			fmt.Fprintln(os.Stderr, id7, id90, id51)
		}
	}
}

func (c *C) solve() {
	need := c.readInt64()
	maxTime := c.readInt64()
	id45 := c.readInt64()

	id43 := c.readInt64()
	id16 := c.readInt64()
	id77 := c.readInt64()

	id7 := c.readInt64()
	id90 := c.readInt64()
	id51 := c.readInt64()

	answer := c.getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51)

	c.out.WriteString(fmt.Sprintf("%d\n", answer[0]))
}

func (c *C) getAnswer(need, maxTime, id45, id43, id16, id77, id7, id90, id51 int64) []int64 {
	answer := int64(math.MaxInt64)
	firstOptimal, secondOptimal := int64(0), int64(0)

	for firstCount, firstSize, firstTime, firstCost := int64(0), int64(0), int64(0), int64(0); ; firstCount++ {
		firstSize += id43
		firstCost += id77
		firstTime += id16 * id43

		if firstSize >= need {
			firstSize = need
			firstTime = id16 * firstSize
		}

		id42 := maxTime - firstTime
		id74 := need - firstSize
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

					id31 := (id74*id45 - id42)
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

		if firstSize >= need {
			break
		}
	}

	for secondCount, secondSize, secondCost, secondTime := int64(0), int64(0), int64(0), int64(0); ; secondCount++ {
		secondSize += id7
		secondCost += id51
		secondTime += id90 * id7

		if secondSize >= need {
			secondSize = need
			secondTime = id90 * secondSize
		}

		id42 := maxTime - secondTime
		id74 := need - secondSize
		if id42 >= 0 {
			if id45 <= id16 {
				freeTime := id45 * id74
				if freeTime+secondTime <= maxTime {
					if answer > secondCost {
						answer = secondCost
						secondOptimal = secondCount
						firstOptimal = 0
					}
				}
			} else {
				id68 := id74 / id43
				id79 := id43 * id68
				id50 := id74 - id79

				id23 := id79 * id16
				id15 := id50 * id45

				if id23+id15 <= id42 {
					if answer > secondCost+id68*id77 {
						answer = secondCost + id68*id77
						secondOptimal = secondCount
						firstOptimal = id68
					}
				}

				id41 := id74 / id43
				if id74%id43 != 0 {
					id41++
				}
				id39 := min(id74, id43*id41)
				id21 := id74 - id39

				id83 := id39 * id16
				id98 := id21 * id45

				if id83+id98 <= id42 {
					if answer > secondCost+id41*id77 {
						answer = secondCost + id41*id77
						secondOptimal = secondCount
						firstOptimal = id41
					}

					id31 := (id74*id45 - id42)
					id96 := (id45 - id16) * id43

					id14 := id31 / id96
					if id31 < 0 {
						id14 = 0
					} else if id31%id96 != 0 {
						id14++
					}
					if id14 >= 0 {
						id86 := min(id74, id43*id14)
						id38 := id74 - id86

						id92 := id86 * id16
						id70 := id38 * id45

						if id92+id70 <= id42 {
							if answer > secondCost+id14*id77 {
								answer = secondCost + id14*id77
								secondOptimal = secondCount
								firstOptimal = id14
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

	if answer == math.MaxInt64 {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
}

func (c *C) id52(need int64, maxTime, id45, id43, id16, id77, id7, id90, id51 int64) []int64 {
	answer := int64(math.MaxInt64)
	firstOptimal, secondOptimal := int64(0), int64(0)

	for firstCount := int64(0); ; firstCount++ {
		firstSize := min(need, firstCount*id43)
		if firstSize >= need {
			firstSize = need
		}

		firstTime := firstSize * id16
		firstCost := firstCount * id77

		id74 := need - firstSize
		for secondCount := int64(0); ; secondCount++ {
			secondSize := min(id74, secondCount*id7)
			if secondSize >= id74 {
				secondSize = id74
			}

			secondTime := secondSize * id90
			secondCost := secondCount * id51

			freeSize := id74 - secondSize
			freeTime := freeSize * id45

			if firstTime+secondTime+freeTime <= maxTime {
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

		if firstSize >= need {
			break
		}
	}

	if answer == math.MaxInt64 {
		answer = -1
	}

	return []int64{answer, firstOptimal, secondOptimal}
}

func (c *C) readInt64() int64 {
	line, _ := c.in.ReadString('\n')
	value, _ := strconv.ParseInt(strings.TrimSpace(line), 10, 64)
	return value
}

func (c *C) main() {
	c.in = bufio.NewReader(os.Stdin)
	c.out = bufio.NewWriter(os.Stdout)

	defer c.out.Flush()

	c.solve()
}

func main() {
	rand.Seed(0)
	c := &C{}
	c.main()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
