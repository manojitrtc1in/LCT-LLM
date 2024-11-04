package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var (
	MODULO = 1000*1000*1000 + 7
)

type id36 struct {
	value int
	index int
}

type id23 struct {
	values []int
}

type SegmentTree struct {
	size  int
	sums  []int64
	mins  []int64
	index int
	value int64
}

type IdMap map[int]int

func (m IdMap) register(key int) int {
	id, ok := m[key]
	if !ok {
		id = len(m)
		m[key] = id
	}
	return id
}

func (m IdMap) getId(key int) int {
	return m[key]
}

func (t *SegmentTree) updateIndex(index int, value int64) {
	t.index = index
	t.value = value
	t.id26(1, 0, t.size)
}

func (t *SegmentTree) id26(v, left, right int) {
	if left+1 == right {
		t.sums[v] = t.value
		t.mins[v] = min64(0, t.value)
	} else {
		mid := (left + right) >> 1
		vLeft := (v << 1)
		vRight := vLeft + 1

		if t.index < mid {
			t.id26(vLeft, left, mid)
		} else {
			t.id26(vRight, mid, right)
		}

		t.updateVertex(v, vLeft, vRight)
	}
}

func (t *SegmentTree) updateVertex(v, vLeft, vRight int) {
	t.sums[v] = t.sums[vLeft] + t.sums[vRight]
	t.mins[v] = min64(t.mins[vLeft], t.sums[vLeft]+t.mins[vRight])
}

func (t *SegmentTree) getInterval(start, end int, value int64) int {
	t.start = start
	t.end = end
	t.value = value

	t.found = false
	t.foundIndex = -1

	t.id12(1, 0, t.size)

	return t.foundIndex
}

func (t *SegmentTree) id12(v, left, right int) {
	if t.start <= left && right <= t.end {
		if !t.found {
			if t.value+t.mins[v] <= 0 {
				t.id19(v, left, right)
				t.found = true
			} else {
				t.value += t.sums[v]
			}
		}
	} else {
		mid := (left + right) >> 1
		vLeft := (v << 1)
		vRight := vLeft + 1

		if t.start < mid {
			t.id12(vLeft, left, mid)
		}
		if mid < t.end {
			t.id12(vRight, mid, right)
		}
	}
}

func (t *SegmentTree) id19(v, left, right int) {
	if left+1 == right {
		t.foundIndex = left
	} else {
		mid := (left + right) >> 1
		vLeft := (v << 1)
		vRight := vLeft + 1

		if t.value+t.mins[vLeft] <= 0 {
			t.id19(vLeft, left, mid)
		} else {
			t.value += t.sums[vLeft]
			t.id19(vRight, mid, right)
		}
	}
}

func min64(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solve() {
	const MAX_T = 1000 * 1000 * 1000

	q := readInt()
	queries := make([][]int, q)
	for i := 0; i < q; i++ {
		queryType := readInt()
		if queryType == 1 {
			queries[i] = []int{1, readInt(), readInt()}
		} else if queryType == 2 {
			queries[i] = []int{2, readInt()}
		} else {
			queries[i] = []int{3, readInt(), readInt(), readInt()}
		}
	}

	mapper := make(IdMap)
	mapper.register(0)
	mapper.register(MAX_T + 1)

	for _, query := range queries {
		mapper.register(query[1])
		if query[0] == 3 {
			mapper.register(query[2])
		}
	}

	ids := mapper
	times := mapper.values()

	minTime := ids.getId(0)
	maxTime := ids.getId(MAX_T + 1)

	id33 := make(map[int]int)
	id33[minTime] = 0
	id33[maxTime] = 0

	for _, query := range queries {
		query[1] = ids.getId(query[1])
		if query[0] == 3 {
			query[2] = ids.getId(query[2])
		}
	}

	tree := NewSegmentTree(ids.size())

	for _, query := range queries {
		queryType := query[0]
		if queryType == 1 {
			time := query[1]
			realTime := times[time]
			speed := int64(query[2])

			entryBefore := lowerEntry(id33, time)

			timeAfter := higherKey(id33, time)
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

			entryBefore := lowerEntry(id33, time)

			timeAfter := higherKey(id33, time)
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

			if value == 0 {
				fmt.Println(times[start])
				continue
			}

			foundIndex := tree.getInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Println(-1)
			} else {
				value = tree.value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					fmt.Println(realTime)
				} else {
					speed := id33[time]

					timeAfter := min(end, higherKey(id33, time))
					id10 := times[timeAfter]

					delta := id10 - realTime
					total := delta * int64(speed)

					if value+total > 0 {
						fmt.Println(-1)
					} else {
						badTime := realTime + float64(value)/float64(abs(speed))
						fmt.Println(badTime)
					}
				}
			}
		}
	}
}

func lowerEntry(m map[int]int, key int) (entry mapEntry) {
	for k, v := range m {
		if k < key && (entry.Key == 0 || k > entry.Key) {
			entry = mapEntry{k, v}
		}
	}
	return entry
}

func higherKey(m map[int]int, key int) (higher int) {
	for k := range m {
		if k > key && (higher == 0 || k < higher) {
			higher = k
		}
	}
	return higher
}

type mapEntry struct {
	Key   int
	Value int
}

func NewSegmentTree(n int) *SegmentTree {
	treeSize := n << 2
	return &SegmentTree{
		size: n,
		sums: make([]int64, treeSize),
		mins: make([]int64, treeSize),
	}
}

func readInt() int {
	s := readString()
	n, _ := strconv.Atoi(s)
	return n
}

func readString() string {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	return scanner.Text()
}

func main() {
	solve()
}
