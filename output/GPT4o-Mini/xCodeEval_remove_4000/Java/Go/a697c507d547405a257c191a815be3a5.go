package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const MODULO = 1000*1000*1000 + 7

type Query struct {
	Type int
	Args []int
}

type SegmentTree struct {
	size  int
	sums  []int64
	mins  []int64
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

		if index < mid {
			tree.id26(vLeft, left, mid)
		} else {
			tree.id26(vRight, mid, right)
		}
		tree.UpdateVertex(v, vLeft, vRight)
	}
}

func (tree *SegmentTree) UpdateVertex(v, vLeft, vRight int) {
	tree.sums[v] = tree.sums[vLeft] + tree.sums[vRight]
	tree.mins[v] = min(tree.mins[vLeft], tree.sums[vLeft]+tree.mins[vRight])
}

func (tree *SegmentTree) GetInterval(start, end int, value int64) int {
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

var (
	in  *bufio.Reader
	out *bufio.Writer
)

func readInt() int {
	var x int
	fmt.Fscan(in, &x)
	return x
}

func solve() {
	const MAX_T = 1000 * 1000 * 1000

	q := readInt()
	queries := make([]Query, q)
	for i := 0; i < q; i++ {
		queryType := readInt()
		if queryType == 1 {
			queries[i] = Query{Type: 1, Args: []int{readInt(), readInt()}}
		} else if queryType == 2 {
			queries[i] = Query{Type: 2, Args: []int{readInt()}}
		} else {
			queries[i] = Query{Type: 3, Args: []int{readInt(), readInt(), readInt()}}
		}
	}

	mapper := NewId23()
	mapper.AddValue(0)
	mapper.AddValue(MAX_T + 1)

	for _, query := range queries {
		mapper.AddValue(query.Args[0])
		if query.Type == 3 {
			mapper.AddValue(query.Args[1])
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

	for i := range queries {
		queries[i].Args[0] = ids.GetId(queries[i].Args[0])
		if queries[i].Type == 3 {
			queries[i].Args[1] = ids.GetId(queries[i].Args[1])
		}
	}

	tree := NewSegmentTree(len(ids.mapping))

	for _, query := range queries {
		switch query.Type {
		case 1:
			time := query.Args[0]
			realTime := times[time]
			speed := query.Args[1]

			entryBefore := id33[time-1]
			timeAfter := id33[time+1]
			id10 := times[timeAfter]

			timeBefore := entryBefore
			id38 := times[timeBefore]
			speedBefore := id33[timeBefore]

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-id38))
			tree.UpdateIndex(time, speed*(id10-realTime))

			id33[time] = speed
		case 2:
			time := query.Args[0]
			realTime := times[time]

			entryBefore := id33[time-1]
			timeAfter := id33[time+1]
			id10 := times[timeAfter]

			timeBefore := entryBefore
			id38 := times[timeBefore]

			speedBefore := id33[timeBefore]

			tree.UpdateIndex(timeBefore, speedBefore*(id10-id38))
			tree.UpdateIndex(time, 0)

			delete(id33, time)
		case 3:
			start := query.Args[0]
			end := query.Args[1]
			value := query.Args[2]

			if value == 0 {
				fmt.Fprintln(out, times[start])
				continue
			}

			foundIndex := tree.GetInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Fprintln(out, -1)
			} else {
				value = tree.value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					fmt.Fprintln(out, realTime)
				} else {
					speed := id33[time]

					timeAfter := min(end, id33[time+1])
					id10 := times[timeAfter]

					delta := id10 - realTime
					total := delta * speed

					if value+total > 0 {
						fmt.Fprintln(out, -1)
					} else {
						badTime := float64(realTime) + float64(value)/math.Abs(float64(speed))
						fmt.Fprintln(out, badTime)
					}
				}
			}
		}
	}
}

func main() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	solve()
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
