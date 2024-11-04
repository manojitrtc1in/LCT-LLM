package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	MODULO = 1000000007
)

type SortedIdMapper struct {
	values []int
}

func NewSortedIdMapper() *SortedIdMapper {
	return &SortedIdMapper{
		values: make([]int, 0),
	}
}

func (m *SortedIdMapper) AddValue(value int) {
	m.values = append(m.values, value)
}

func (m *SortedIdMapper) Build() map[int]int {
	sort.Ints(m.values)
	ids := make(map[int]int)
	uniqueValues := make([]int, 0)

	for _, value := range m.values {
		if _, ok := ids[value]; !ok {
			ids[value] = len(ids)
			uniqueValues = append(uniqueValues, value)
		}
	}

	m.values = uniqueValues

	return ids
}

type SegmentTree struct {
	size int
	sums []int
	mins []int
}

func NewSegmentTree(n int) *SegmentTree {
	treeSize := n << 2
	return &SegmentTree{
		size: n,
		sums: make([]int, treeSize),
		mins: make([]int, treeSize),
	}
}

func (st *SegmentTree) UpdateIndex(index, value int) {
	st.updateTreeIndex(1, 0, st.size, index, value)
}

func (st *SegmentTree) updateTreeIndex(v, left, right, index, value int) {
	if left+1 == right {
		st.sums[v] = value
		st.mins[v] = min(0, value)
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if index < mid {
			st.updateTreeIndex(vLeft, left, mid, index, value)
		} else {
			st.updateTreeIndex(vRight, mid, right, index, value)
		}

		st.updateVertex(v, vLeft, vRight)
	}
}

func (st *SegmentTree) updateVertex(v, vLeft, vRight int) {
	st.sums[v] = st.sums[vLeft] + st.sums[vRight]
	st.mins[v] = min(st.mins[vLeft], st.sums[vLeft]+st.mins[vRight])
}

func (st *SegmentTree) GetInterval(start, end, value int) int {
	return st.getTreeInterval(1, 0, st.size, start, end, value)
}

func (st *SegmentTree) getTreeInterval(v, left, right, start, end, value int) int {
	if start <= left && right <= end {
		if value+st.mins[v] <= 0 {
			return st.findTreeIndex(v, left, right)
		} else {
			value += st.sums[v]
		}
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if start < mid {
			st.getTreeInterval(vLeft, left, mid, start, end, value)
		}
		if mid < end {
			st.getTreeInterval(vRight, mid, right, start, end, value)
		}
	}

	return -1
}

func (st *SegmentTree) findTreeIndex(v, left, right int) int {
	if left+1 == right {
		return left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if st.mins[vLeft] <= 0 {
			return st.findTreeIndex(vLeft, left, mid)
		} else {
			return st.findTreeIndex(vRight, mid, right)
		}
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	q := nextInt(scanner)
	queries := make([][]int, q)
	for i := 0; i < q; i++ {
		queryType := nextInt(scanner)
		if queryType == 1 {
			queries[i] = []int{1, nextInt(scanner), nextInt(scanner)}
		} else if queryType == 2 {
			queries[i] = []int{2, nextInt(scanner)}
		} else {
			queries[i] = []int{3, nextInt(scanner), nextInt(scanner), nextInt(scanner)}
		}
	}

	mapper := NewSortedIdMapper()
	mapper.AddValue(0)
	mapper.AddValue(1000000001)

	for _, query := range queries {
		mapper.AddValue(query[1])
		if query[0] == 3 {
			mapper.AddValue(query[2])
		}
	}

	ids := mapper.Build()
	times := make([]int, len(mapper.values))
	for i, value := range mapper.values {
		times[i] = value
	}

	minTime := ids[0]
	maxTime := ids[1000000001]

	timeSpeeds := make(map[int]int)
	timeSpeeds[minTime] = 0
	timeSpeeds[maxTime] = 0

	for _, query := range queries {
		query[1] = ids[query[1]]
		if query[0] == 3 {
			query[2] = ids[query[2]]
		}
	}

	tree := NewSegmentTree(len(ids))

	for _, query := range queries {
		queryType := query[0]
		if queryType == 1 {
			time := query[1]
			realTime := times[time]
			speed := query[2]

			entryBefore := timeSpeeds[time-1]

			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore
			realTimeBefore := times[timeBefore]
			speedBefore := timeSpeeds[timeBefore]

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-realTimeBefore))
			tree.UpdateIndex(time, speed*(realTimeAfter-realTime))

			timeSpeeds[time] = speed
		} else if queryType == 2 {
			time := query[1]
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
		} else {
			start := query[1]
			end := query[2]
			value := query[3]

			foundIndex := tree.GetInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Println(-1)
			} else {
				value = tree.sums[foundIndex]

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
						badTime := realTime + float64(value)/float64(abs(speed))
						fmt.Println(badTime)
					}
				}
			}
		}
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}
