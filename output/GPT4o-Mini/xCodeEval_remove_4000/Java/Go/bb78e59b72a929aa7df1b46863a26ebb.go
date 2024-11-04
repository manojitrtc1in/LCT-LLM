package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const MODULO = 1000000007

type SegmentTree struct {
	size  int
	sums  []int64
	mins  []int64
	index int
	value int64
}

func NewSegmentTree(n int) *SegmentTree {
	treeSize := n << 2
	return &SegmentTree{
		size: n,
		sums: make([]int64, treeSize),
		mins: make([]int64, treeSize),
	}
}

func (tree *SegmentTree) UpdateIndex(index int, value int64) {
	tree.index = index
	tree.value = value
	tree.update(1, 0, tree.size)
}

func (tree *SegmentTree) update(v, left, right int) {
	if left+1 == right {
		tree.sums[v] = tree.value
		tree.mins[v] = min(0, tree.value)
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.index < mid {
			tree.update(vLeft, left, mid)
		} else {
			tree.update(vRight, mid, right)
		}

		tree.updateVertex(v, vLeft, vRight)
	}
}

func (tree *SegmentTree) updateVertex(v, vLeft, vRight int) {
	tree.sums[v] = tree.sums[vLeft] + tree.sums[vRight]
	tree.mins[v] = min(tree.mins[vLeft], tree.sums[vLeft]+tree.mins[vRight])
}

func (tree *SegmentTree) GetInterval(start, end int, value int64) int {
	found := false
	foundIndex := -1
	tree.getInterval(1, 0, tree.size, start, end, value, &found, &foundIndex)
	return foundIndex
}

func (tree *SegmentTree) getInterval(v, left, right, start, end int, value int64, found *bool, foundIndex *int) {
	if start <= left && right <= end {
		if !*found {
			if value+tree.mins[v] <= 0 {
				tree.id19(v, left, right, foundIndex)
				*found = true
			} else {
				value += tree.sums[v]
			}
		}
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if start < mid {
			tree.getInterval(vLeft, left, mid, start, end, value, found, foundIndex)
		}
		if mid < end {
			tree.getInterval(vRight, mid, right, start, end, value, found, foundIndex)
		}
	}
}

func (tree *SegmentTree) id19(v, left, right int, foundIndex *int) {
	if left+1 == right {
		*foundIndex = left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.value+tree.mins[vLeft] <= 0 {
			tree.id19(vLeft, left, mid, foundIndex)
		} else {
			tree.value += tree.sums[vLeft]
			tree.id19(vRight, mid, right, foundIndex)
		}
	}
}

type IdMap struct {
	mapping map[int]int
}

func NewIdMap() *IdMap {
	return &IdMap{mapping: make(map[int]int)}
}

func (idMap *IdMap) Register(key int) int {
	if id, exists := idMap.mapping[key]; exists {
		return id
	}
	id := len(idMap.mapping)
	idMap.mapping[key] = id
	return id
}

func (idMap *IdMap) GetId(key int) int {
	return idMap.mapping[key]
}

type Id23 struct {
	values []int
}

func NewId23() *Id23 {
	return &Id23{values: []int{}}
}

func (id23 *Id23) AddValue(value int) {
	id23.values = append(id23.values, value)
}

func (id23 *Id23) Build() *IdMap {
	sort.Ints(id23.values)
	idMap := NewIdMap()
	uniqueValues := []int{}

	for i, value := range id23.values {
		if i == 0 || id23.values[i-1] != value {
			idMap.Register(value)
			uniqueValues = append(uniqueValues, value)
		}
	}

	id23.values = uniqueValues
	return idMap
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var q int
	fmt.Fscan(reader, &q)
	queries := make([][]int, q)

	for i := 0; i < q; i++ {
		var typ, a, b, c int
		fmt.Fscan(reader, &typ)
		if typ == 1 {
			fmt.Fscan(reader, &a, &b)
			queries[i] = []int{1, a, b}
		} else if typ == 2 {
			fmt.Fscan(reader, &a)
			queries[i] = []int{2, a}
		} else {
			fmt.Fscan(reader, &a, &b, &c)
			queries[i] = []int{3, a, b, c}
		}
	}

	const MAX_T = 1000000000
	mapper := NewId23()
	mapper.AddValue(0)
	mapper.AddValue(MAX_T + 1)

	for _, query := range queries {
		mapper.AddValue(query[1])
		if query[0] == 3 {
			mapper.AddValue(query[2])
		}
	}

	ids := mapper.Build()
	times := make([]int, len(mapper.values))
	for i, v := range mapper.values {
		times[i] = v
	}

	minTime := ids.GetId(0)
	maxTime := ids.GetId(MAX_T + 1)

	id33 := make(map[int]int)
	id33[minTime] = 0
	id33[maxTime] = 0

	for _, query := range queries {
		query[1] = ids.GetId(query[1])
		if query[0] == 3 {
			query[2] = ids.GetId(query[2])
		}
	}

	tree := NewSegmentTree(len(ids.mapping))

	for _, query := range queries {
		typ := query[0]
		if typ == 1 {
			time := query[1]
			realTime := times[time]
			speed := query[2]

			entryBefore := getLowerEntry(id33, time)

			timeAfter := getHigherKey(id33, time)
			id10 := times[timeAfter]

			timeBefore := entryBefore.key
			id38 := times[timeBefore]
			speedBefore := entryBefore.value

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-id38))
			tree.UpdateIndex(time, speed*(id10-realTime))

			id33[time] = int(speed)
		} else if typ == 2 {
			time := query[1]
			realTime := times[time]

			entryBefore := getLowerEntry(id33, time)

			timeAfter := getHigherKey(id33, time)
			id10 := times[timeAfter]

			timeBefore := entryBefore.key
			id38 := times[timeBefore]
			speedBefore := entryBefore.value

			tree.UpdateIndex(timeBefore, speedBefore*(id10-id38))
			tree.UpdateIndex(time, 0)

			delete(id33, time)
		} else {
			start := query[1]
			end := query[2]
			value := query[3]

			foundIndex := tree.GetInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Fprintln(writer, -1)
			} else {
				value = tree.value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					fmt.Fprintln(writer, realTime)
				} else {
					speed := id33[time]

					timeAfter := min(end, getHigherKey(id33, time))
					id10 := times[timeAfter]

					delta := id10 - realTime
					total := delta * speed

					if value+total > 0 {
						fmt.Fprintln(writer, -1)
					} else {
						badTime := float64(realTime) + float64(value)/math.Abs(float64(speed))
						fmt.Fprintln(writer, badTime)
					}
				}
			}
		}
	}
}

type Entry struct {
	key   int
	value int
}

func getLowerEntry(m map[int]int, key int) Entry {
	var entry Entry
	for k, v := range m {
		if k < key {
			entry = Entry{k, v}
		}
	}
	return entry
}

func getHigherKey(m map[int]int, key int) int {
	for k := range m {
		if k > key {
			return k
		}
	}
	return -1
}
