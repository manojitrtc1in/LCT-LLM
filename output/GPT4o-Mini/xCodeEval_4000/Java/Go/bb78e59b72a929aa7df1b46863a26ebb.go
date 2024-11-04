package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const MODULO = 1000000007
const MAX_T = 1000000000

type Query struct {
	Type int
	Args []int
}

type SegmentTree struct {
	size  int
	sums  []int64
	mins  []int64
	value int64
	start int
	end   int
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
	tree.start = index
	tree.updateTreeIndex(1, 0, tree.size)
}

func (tree *SegmentTree) updateTreeIndex(v, left, right int) {
	if left+1 == right {
		tree.sums[v] = tree.value
		tree.mins[v] = min(0, tree.value)
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.start < mid {
			tree.updateTreeIndex(vLeft, left, mid)
		} else {
			tree.updateTreeIndex(vRight, mid, right)
		}

		tree.updateVertex(v, vLeft, vRight)
	}
}

func (tree *SegmentTree) updateVertex(v, vLeft, vRight int) {
	tree.sums[v] = tree.sums[vLeft] + tree.sums[vRight]
	tree.mins[v] = min(tree.mins[vLeft], tree.sums[vLeft]+tree.mins[vRight])
}

func (tree *SegmentTree) GetInterval(start, end int, value int64) int {
	tree.start = start
	tree.end = end
	return tree.getTreeInterval(1, 0, tree.size)
}

func (tree *SegmentTree) getTreeInterval(v, left, right int) int {
	if tree.start <= left && right <= tree.end {
		if value+tree.mins[v] <= 0 {
			return tree.findTreeIndex(v, left, right)
		} else {
			value += tree.sums[v]
		}
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.start < mid {
			tree.getTreeInterval(vLeft, left, mid)
		}
		if mid < tree.end {
			tree.getTreeInterval(vRight, mid, right)
		}
	}
	return -1
}

func (tree *SegmentTree) findTreeIndex(v, left, right int) int {
	if left+1 == right {
		return left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if value+tree.mins[vLeft] <= 0 {
			return tree.findTreeIndex(vLeft, left, mid)
		} else {
			value += tree.sums[vLeft]
			return tree.findTreeIndex(vRight, mid, right)
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

type SortedIdMapper struct {
	values []int
}

func NewSortedIdMapper() *SortedIdMapper {
	return &SortedIdMapper{values: []int{}}
}

func (mapper *SortedIdMapper) AddValue(value int) {
	mapper.values = append(mapper.values, value)
}

func (mapper *SortedIdMapper) Build() *IdMap {
	sort.Ints(mapper.values)
	idMap := NewIdMap()
	uniqueValues := []int{}

	for i, value := range mapper.values {
		if i == 0 || mapper.values[i-1] != value {
			idMap.Register(value)
			uniqueValues = append(uniqueValues, value)
		}
	}

	mapper.values = uniqueValues
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
	queries := make([]Query, q)

	for i := 0; i < q; i++ {
		var typ int
		fmt.Fscan(reader, &typ)
		if typ == 1 {
			var a, b int
			fmt.Fscan(reader, &a, &b)
			queries[i] = Query{Type: typ, Args: []int{a, b}}
		} else if typ == 2 {
			var a int
			fmt.Fscan(reader, &a)
			queries[i] = Query{Type: typ, Args: []int{a}}
		} else {
			var a, b, c int
			fmt.Fscan(reader, &a, &b, &c)
			queries[i] = Query{Type: typ, Args: []int{a, b, c}}
		}
	}

	mapper := NewSortedIdMapper()
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

	minTime := ids.mapping[0]
	maxTime := ids.mapping[MAX_T+1]
	timeSpeeds := make(map[int]int)

	timeSpeeds[minTime] = 0
	timeSpeeds[maxTime] = 0

	for i := range queries {
		queries[i].Args[0] = ids.mapping[queries[i].Args[0]]
		if queries[i].Type == 3 {
			queries[i].Args[1] = ids.mapping[queries[i].Args[1]]
		}
	}

	tree := NewSegmentTree(len(ids.mapping))

	for _, query := range queries {
		switch query.Type {
		case 1:
			time := query.Args[0]
			realTime := times[time]
			speed := int64(query.Args[1])

			entryBefore := timeSpeeds[time-1]
			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore
			realTimeBefore := times[timeBefore]
			speedBefore := int64(timeSpeeds[timeBefore])

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-realTimeBefore))
			tree.UpdateIndex(time, speed*(realTimeAfter-realTime))

			timeSpeeds[time] = int(speed)

		case 2:
			time := query.Args[0]
			realTime := times[time]

			entryBefore := timeSpeeds[time-1]
			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore
			realTimeBefore := times[timeBefore]
			speedBefore := int64(timeSpeeds[timeBefore])

			tree.UpdateIndex(timeBefore, speedBefore*(realTimeAfter-realTimeBefore))
			tree.UpdateIndex(time, 0)

			delete(timeSpeeds, time)

		case 3:
			start := query.Args[0]
			end := query.Args[1]
			value := int64(query.Args[2])

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
					speed := int64(timeSpeeds[time])
					timeAfter := timeSpeeds[time+1]
					realTimeAfter := times[timeAfter]

					delta := realTimeAfter - realTime
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
