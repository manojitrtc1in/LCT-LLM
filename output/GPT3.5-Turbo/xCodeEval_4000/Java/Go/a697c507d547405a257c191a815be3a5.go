package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var (
	reader *bufio.Reader
	writer *bufio.Writer
)

func initIO() {
	reader = bufio.NewReader(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
}

func flush() {
	writer.Flush()
}

func readString() string {
	str, _ := reader.ReadString('\n')
	return str[:len(str)-1]
}

func readInt() int {
	num, _ := strconv.Atoi(readString())
	return num
}

func readInts() []int {
	str := readString()
	strs := make([]string, 0)
	strs = append(strs, str)
	return convertStringsToInts(strs)
}

func convertStringsToInts(strs []string) []int {
	nums := make([]int, 0)
	for _, str := range strs {
		num, _ := strconv.Atoi(str)
		nums = append(nums, num)
	}
	return nums
}

func writeString(str string) {
	writer.WriteString(str)
}

func writeInt(num int) {
	writer.WriteString(strconv.Itoa(num))
}

func writeInts(nums []int) {
	strs := convertIntsToStrings(nums)
	for _, str := range strs {
		writer.WriteString(str)
		writer.WriteString(" ")
	}
}

func convertIntsToStrings(nums []int) []string {
	strs := make([]string, 0)
	for _, num := range nums {
		strs = append(strs, strconv.Itoa(num))
	}
	return strs
}

func main() {
	initIO()
	defer flush()

	solve()
}

func solve() {
	const MAX_T = 1000000000

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

	mapper := NewSortedIdMapper()
	mapper.AddValue(0)
	mapper.AddValue(MAX_T + 1)

	for _, query := range queries {
		mapper.AddValue(query[1])
		if query[0] == 3 {
			mapper.AddValue(query[2])
		}
	}

	ids := mapper.Build()
	times := mapper.Values

	minTime := ids.GetId(0)
	maxTime := ids.GetId(MAX_T + 1)

	timeSpeeds := make(map[int]int)
	timeSpeeds[minTime] = 0
	timeSpeeds[maxTime] = 0

	for _, query := range queries {
		query[1] = ids.GetId(query[1])
		if query[0] == 3 {
			query[2] = ids.GetId(query[2])
		}
	}

	tree := NewSegmentTree(ids.Size())

	for _, query := range queries {
		queryType := query[0]
		if queryType == 1 {
			time := query[1]
			realTime := times[time]
			speed := int64(query[2])

			entryBefore := timeSpeeds[time-1]

			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore.Key
			realTimeBefore := times[timeBefore]
			speedBefore := entryBefore.Value

			tree.UpdateIndex(timeBefore, speedBefore*(realTime-realTimeBefore))
			tree.UpdateIndex(time, speed*(realTimeAfter-realTime))

			timeSpeeds[time] = int(speed)
		} else if queryType == 2 {
			time := query[1]
			realTime := times[time]

			entryBefore := timeSpeeds[time-1]

			timeAfter := timeSpeeds[time+1]
			realTimeAfter := times[timeAfter]

			timeBefore := entryBefore.Key
			realTimeBefore := times[timeBefore]

			speedBefore := entryBefore.Value

			tree.UpdateIndex(timeBefore, speedBefore*(realTimeAfter-realTimeBefore))
			tree.UpdateIndex(time, 0)

			delete(timeSpeeds, time)
		} else {
			start := query[1]
			end := query[2]
			value := int64(query[3])

			if value == 0 {
				fmt.Println(times[start])
				continue
			}

			foundIndex := tree.GetInterval(start, end, value)
			if foundIndex == -1 {
				fmt.Println(-1)
			} else {
				value = tree.Value

				time := foundIndex
				realTime := times[time]

				if value == 0 {
					fmt.Println(realTime)
				} else {
					speed := timeSpeeds[time]

					timeAfter := min(end, timeSpeeds[time+1])
					realTimeAfter := times[timeAfter]

					delta := realTimeAfter - realTime
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

type SortedIdMapper struct {
	Values []int
}

func NewSortedIdMapper() *SortedIdMapper {
	return &SortedIdMapper{
		Values: make([]int, 0),
	}
}

func (m *SortedIdMapper) AddValue(value int) {
	m.Values = append(m.Values, value)
}

func (m *SortedIdMapper) Build() *IdMap {
	sort.Ints(m.Values)

	ids := NewIdMap()
	uniqueValues := make([]int, 0)

	for i := 0; i < len(m.Values); i++ {
		value := m.Values[i]
		if i == 0 || m.Values[i-1] != value {
			ids.Register(value)
			uniqueValues = append(uniqueValues, value)
		}
	}

	m.Values = uniqueValues

	return ids
}

type IdMap struct {
	Values map[int]int
}

func NewIdMap() *IdMap {
	return &IdMap{
		Values: make(map[int]int),
	}
}

func (m *IdMap) Register(value int) int {
	id, ok := m.Values[value]
	if !ok {
		id = len(m.Values)
		m.Values[value] = id
	}

	return id
}

func (m *IdMap) GetId(value int) int {
	return m.Values[value]
}

type SegmentTree struct {
	Size int
	Sums []int64
	Mins []int64
}

func NewSegmentTree(n int) *SegmentTree {
	size := n << 2
	return &SegmentTree{
		Size: n,
		Sums: make([]int64, size),
		Mins: make([]int64, size),
	}
}

func (t *SegmentTree) UpdateIndex(index int, value int64) {
	t.updateTreeIndex(1, 0, t.Size, index, value)
}

func (t *SegmentTree) updateTreeIndex(v, left, right, index int, value int64) {
	if left+1 == right {
		t.Sums[v] = value
		t.Mins[v] = min(0, value)
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if index < mid {
			t.updateTreeIndex(vLeft, left, mid, index, value)
		} else {
			t.updateTreeIndex(vRight, mid, right, index, value)
		}

		t.updateVertex(v, vLeft, vRight)
	}
}

func (t *SegmentTree) updateVertex(v, vLeft, vRight int) {
	t.Sums[v] = t.Sums[vLeft] + t.Sums[vRight]
	t.Mins[v] = min(t.Mins[vLeft], t.Sums[vLeft]+t.Mins[vRight])
}

func (t *SegmentTree) GetInterval(start, end int, value int64) int {
	return t.getTreeInterval(1, 0, t.Size, start, end, value)
}

func (t *SegmentTree) getTreeInterval(v, left, right, start, end int, value int64) int {
	if start <= left && right <= end {
		if value+t.Mins[v] <= 0 {
			return t.findTreeIndex(v, left, right)
		} else {
			value += t.Sums[v]
		}
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if start < mid {
			t.getTreeInterval(vLeft, left, mid, start, end, value)
		}
		if mid < end {
			t.getTreeInterval(vRight, mid, right, start, end, value)
		}
	}

	return -1
}

func (t *SegmentTree) findTreeIndex(v, left, right int) int {
	if left+1 == right {
		return left
	} else {
		mid := (left + right) >> 1
		vLeft := v << 1
		vRight := vLeft + 1

		if t.Mins[vLeft] <= 0 {
			return t.findTreeIndex(vLeft, left, mid)
		} else {
			t.Value += t.Sums[vLeft]
			return t.findTreeIndex(vRight, mid, right)
		}
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}
