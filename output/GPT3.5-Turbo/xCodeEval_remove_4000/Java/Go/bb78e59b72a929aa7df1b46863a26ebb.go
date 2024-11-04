package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var MODULO int64 = 1000 * 1000 * 1000 + 7

type id23 struct {
	values []int
}

func (id *id23) addValue(value int) {
	id.values = append(id.values, value)
}

func (id *id23) build() map[int]int {
	sort.Ints(id.values)

	ids := make(map[int]int)
	uniqueValues := make([]int, 0)

	for index := 0; index < len(id.values); index++ {
		value := id.values[index]
		if index == 0 || id.values[index-1] != value {
			ids[value] = len(ids)
			uniqueValues = append(uniqueValues, value)
		}
	}

	id.values = uniqueValues

	return ids
}

type SegmentTree struct {
	size int
	sums []int64
	mins []int64
}

func newSegmentTree(n int) *SegmentTree {
	tree := &SegmentTree{
		size: n,
		sums: make([]int64, n<<2),
		mins: make([]int64, n<<2),
	}
	return tree
}

func (tree *SegmentTree) updateIndex(index int, value int64) {
	tree.index = index
	tree.value = value
	tree.id26(1, 0, tree.size)
}

func (tree *SegmentTree) id26(v, left, right int) {
	if left+1 == right {
		tree.sums[v] = tree.value
		tree.mins[v] = min(0, tree.value)
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.index < mid {
			tree.id26(vLeft, left, mid)
		} else {
			tree.id26(vRight, mid, right)
		}

		tree.updateVertex(v, vLeft, vRight)
	}
}

func (tree *SegmentTree) updateVertex(v, vLeft, vRight int) {
	tree.sums[v] = tree.sums[vLeft] + tree.sums[vRight]
	tree.mins[v] = min(tree.mins[vLeft], tree.sums[vLeft]+tree.mins[vRight])
}

func (tree *SegmentTree) getInterval(start, end int, value int64) int {
	tree.start = start
	tree.end = end
	tree.value = value

	tree.found = false
	tree.foundIndex = -1

	tree.id12(1, 0, tree.size)

	return tree.foundIndex
}

func (tree *SegmentTree) id12(v, left, right int) {
	if tree.start <= left && right <= tree.end {
		if !tree.found {
			if tree.value+tree.mins[v] <= 0 {
				tree.id19(v, left, right)
				tree.found = true
			} else {
				tree.value += tree.sums[v]
			}
		}
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.start < mid {
			tree.id12(vLeft, left, mid)
		}
		if mid < tree.end {
			tree.id12(vRight, mid, right)
		}
	}
}

func (tree *SegmentTree) id19(v, left, right int) {
	if left+1 == right {
		tree.foundIndex = left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.value+tree.mins[vLeft] <= 0 {
			tree.id19(vLeft, left, mid)
		} else {
			tree.value += tree.sums[vLeft]
			tree.id19(vRight, mid, right)
		}
	}
}

type C struct {
	in   *bufio.Reader
	out  *bufio.Writer
	tok  []string
	rnd  *Random
	file *os.File
}

func newC() *C {
	return &C{
		in:  bufio.NewReader(os.Stdin),
		out: bufio.NewWriter(os.Stdout),
		rnd:  newRandom(),
	}
}

func (c *C) run() {
	defer c.out.Flush()

	const MAX_T = 1000 * 1000 * 1000

	q := c.readInt()
	queries := make([][]int, q)
	for i := 0; i < q; i++ {
		queryType := c.readInt()
		if queryType == 1 {
			queries[i] = []int{1, c.readInt(), c.readInt()}
		} else if queryType == 2 {
			queries[i] = []int{2, c.readInt()}
		} else {
			queries[i] = []int{3, c.readInt(), c.readInt(), c.readInt()}
		}
	}

	mapper := &id23{}
	mapper.addValue(0)
	mapper.addValue(MAX_T + 1)

	for _, query := range queries {
		mapper.addValue(query[1])
		if query[0] == 3 {
			mapper.addValue(query[2])
		}
	}

	ids := mapper.build()
	times := ids.values

	minTime := ids[0]
	maxTime := ids[MAX_T+1]

	id33 := make(map[int]int)
	id33[minTime] = 0
	id33[maxTime] = 0

	for _, query := range queries {
		query[1] = ids[query[1]]
		if query[0] == 3 {
			query[2] = ids[query[2]]
		}
	}

	tree := newSegmentTree(len(ids))

	for _, query := range queries {
		queryType := query[0]
		if queryType == 1 {
			time := query[1]
			realTime := times[time]
			speed := int64(query[2])

			entryBefore := c.lowerEntry(id33, time)

			timeAfter := c.higherKey(id33, time)
			id10 := times[timeAfter]

			timeBefore := entryBefore.Key
			id38 := times[timeBefore]
			speedBefore := int64(entryBefore.Value)

			tree.updateIndex(timeBefore, speedBefore*(realTime-id38))
			tree.updateIndex(time, speed*(id10-realTime))

			id33[time] = int(speed)
		} else if queryType == 2 {
			time := query[1]
			realTime := times[time]

			entryBefore := c.lowerEntry(id33, time)

			timeAfter := c.higherKey(id33, time)
			id10 := times[timeAfter]

			timeBefore := entryBefore.Key
			id38 := times[timeBefore]
			speedBefore := int64(entryBefore.Value)

			tree.updateIndex(timeBefore, speedBefore*(id10-id38))
			tree.updateIndex(time, 0)

			delete(id33, time)
		} else {
			start := query[1]
			end := query[2]
			value := int64(query[3])

			foundIndex := tree.getInterval(start, end, value)
			if foundIndex == -1 {
				c.out.println(-1)
			} else {
				value = tree.value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					c.out.println(realTime)
				} else {
					speed := id33[time]

					timeAfter := min(end, c.higherKey(id33, time))
					id10 := times[timeAfter]

					delta := id10 - realTime
					total := delta * int64(speed)

					if value+total > 0 {
						c.out.println(-1)
					} else {
						badTime := realTime + float64(value)/float64(abs(speed))
						c.out.println(badTime)
					}
				}
			}
		}
	}
}

func (c *C) lowerEntry(m map[int]int, key int) (entry mapEntry) {
	for k, v := range m {
		if k < key && (entry.Key == 0 || k > entry.Key) {
			entry.Key = k
			entry.Value = v
		}
	}
	return
}

func (c *C) higherKey(m map[int]int, key int) (higherKey int) {
	for k := range m {
		if k > key && (higherKey == 0 || k < higherKey) {
			higherKey = k
		}
	}
	return
}

func (c *C) lowerKey(m map[int]int, key int) (lowerKey int) {
	for k := range m {
		if k < key && (lowerKey == 0 || k > lowerKey) {
			lowerKey = k
		}
	}
	return
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func (c *C) readInt() int {
	token, _ := c.nextToken()
	num, _ := strconv.Atoi(token)
	return num
}

func (c *C) nextToken() (string, bool) {
	if len(c.tok) == 0 {
		for {
			line, err := c.in.ReadString('\n')
			if err != nil {
				return "", false
			}
			c.tok = strings.Split(strings.TrimSpace(line), " ")
			if len(c.tok) > 0 {
				break
			}
		}
	}
	token := c.tok[0]
	c.tok = c.tok[1:]
	return token, true
}

func main() {
	c := newC()
	c.run()
}
