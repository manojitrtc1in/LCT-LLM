package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"sort"
)

const MODULO = 1000*1000*1000 + 7
const MAX_T = 1000 * 1000 * 1000

type Query struct {
	Type int
	Args []int
}

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

		if tree.index < mid {
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
	found := false
	foundIndex := -1
	tree.getTreeInterval(1, 0, tree.size, start, end, value, &found, &foundIndex)
	return foundIndex
}

func (tree *SegmentTree) getTreeInterval(v, left, right, start, end int, value int64, found *bool, foundIndex *int) {
	if start <= left && right <= end {
		if !*found {
			if value+tree.mins[v] <= 0 {
				tree.findTreeIndex(v, left, right, foundIndex)
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
			tree.getTreeInterval(vLeft, left, mid, start, end, value, found, foundIndex)
		}
		if mid < end {
			tree.getTreeInterval(vRight, mid, right, start, end, value, found, foundIndex)
		}
	}
}

func (tree *SegmentTree) findTreeIndex(v, left, right int, foundIndex *int) {
	if left+1 == right {
		*foundIndex = left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if tree.value+tree.mins[vLeft] <= 0 {
			tree.findTreeIndex(vLeft, left, mid, foundIndex)
		} else {
			tree.value += tree.sums[vLeft]
			tree.findTreeIndex(vRight, mid, right, foundIndex)
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
	id, exists := idMap.mapping[key]
	if !exists {
		id = len(idMap.mapping)
		idMap.mapping[key] = id
	}
	return id
}

func (idMap *IdMap) GetId(key int) int {
	return idMap.mapping[key]
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

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	var x int
	fmt.Sscan(scanner.Text(), &x)
	return x
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	q := readInt(scanner)
	queries := make([]Query, q)

	for i := 0; i < q; i++ {
		queryType := readInt(scanner)
		if queryType == 1 {
			arg1 := readInt(scanner)
			arg2 := readInt(scanner)
			queries[i] = Query{Type: 1, Args: []int{arg1, arg2}}
		} else if queryType == 2 {
			arg1 := readInt(scanner)
			queries[i] = Query{Type: 2, Args: []int{arg1}}
		} else {
			arg1 := readInt(scanner)
			arg2 := readInt(scanner)
			arg3 := readInt(scanner)
			queries[i] = Query{Type: 3, Args: []int{arg1, arg2, arg3}}
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

	minTime := ids.GetId(0)
	maxTime := ids.GetId(MAX_T + 1)

	timeSpeeds := make(map[int]int)
	timeSpeeds[minTime] = 0
	timeSpeeds[maxTime] = 0

	for i, query := range queries {
		query.Args[0] = ids.GetId(query.Args[0])
		if query.Type == 3 {
			query.Args[1] = ids.GetId(query.Args[1])
		}
	}

	tree := NewSegmentTree(len(ids.mapping))

	for _, query := range queries {
		switch query.Type {
		case 1:
			time := query.Args[0]
			realTime := times[time]
			speed := query.Args[1]

			entryBefore := timeSpeeds[time-1]
			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore
			realTimeBefore := times[timeBefore]
			speedBefore := timeSpeeds[timeBefore]

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-realTimeBefore))
			tree.UpdateIndex(time, speed*(realTimeAfter-realTime))

			timeSpeeds[time] = speed
		case 2:
			time := query.Args[0]
			realTime := times[time]

			entryBefore := timeSpeeds[time-1]
			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore
			realTimeBefore := times[timeBefore]
			speedBefore := timeSpeeds[timeBefore]

			tree.UpdateIndex(timeBefore, speedBefore*(realTimeAfter-realTimeBefore))
			tree.UpdateIndex(time, 0)

			delete(timeSpeeds, time)
		case 3:
			start := query.Args[0]
			end := query.Args[1]
			value := query.Args[2]

			if value == 0 {
				fmt.Println(times[start])
				continue
			}

			foundIndex := tree.GetInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Println(-1)
			} else {
				value = tree.value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					fmt.Println(realTime)
				} else {
					speed := timeSpeeds[time]

					timeAfter := min(end, timeSpeeds[time+1])
					realTimeAfter := times[timeAfter]

					delta := realTimeAfter - realTime
					total := delta * speed

					if value+total > 0 {
						fmt.Println(-1)
					} else {
						badTime := float64(realTime) + float64(value)/math.Abs(float64(speed))
						fmt.Println(badTime)
					}
				}
			}
		}
	}
}
