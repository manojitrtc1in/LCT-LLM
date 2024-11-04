package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

var mod int = 1000000007
var mod1 int = 998244353

type FastIO struct {
	reader *bufio.Reader
	writer *bufio.Writer
}

func NewFastIO() *FastIO {
	return &FastIO{reader: bufio.NewReader(os.Stdin), writer: bufio.NewWriter(os.Stdout)}
}

func (fio *FastIO) ReadInt() int {
	str, _ := fio.reader.ReadString('\n')
	num, _ := strconv.Atoi(str[:len(str)-1])
	return num
}

func (fio *FastIO) ReadInts() []int {
	str, _ := fio.reader.ReadString('\n')
	str = str[:len(str)-1]
	strs := split(str, " ")
	nums := make([]int, len(strs))
	for i, s := range strs {
		nums[i], _ = strconv.Atoi(s)
	}
	return nums
}

func (fio *FastIO) ReadString() string {
	str, _ := fio.reader.ReadString('\n')
	return str[:len(str)-1]
}

func (fio *FastIO) WriteInt(num int) {
	fio.writer.WriteString(strconv.Itoa(num))
	fio.writer.WriteByte('\n')
}

func (fio *FastIO) WriteInts(nums []int) {
	for _, num := range nums {
		fio.writer.WriteString(strconv.Itoa(num))
		fio.writer.WriteByte(' ')
	}
	fio.writer.WriteByte('\n')
}

func (fio *FastIO) WriteString(str string) {
	fio.writer.WriteString(str)
	fio.writer.WriteByte('\n')
}

func (fio *FastIO) Flush() {
	fio.writer.Flush()
}

func split(str, sep string) []string {
	strs := make([]string, 0)
	start := 0
	for i := 0; i < len(str); i++ {
		if str[i] == sep[0] {
			if i+len(sep) <= len(str) && str[i:i+len(sep)] == sep {
				strs = append(strs, str[start:i])
				i += len(sep) - 1
				start = i + 1
			}
		}
	}
	strs = append(strs, str[start:])
	return strs
}

func check(x int, n int, m int, l []int, t [][]int) bool {
	now := x
	c := sum(l)
	cur := 0
	last := 0
	ld := make(map[int]int)
	for i := 0; i < len(t); i++ {
		if t[i][0] <= x {
			ld[t[i][1]] = i
		}
	}
	for i := 0; i < m; i++ {
		if ld[t[i][1]] != i {
			continue
		}
		if t[i][0] > x {
			break
		}
		cur += t[i][0] - last
		rt := min(cur, l[t[i][1]-1])
		cur -= rt
		now -= rt
		c -= rt
		last = t[i][0]
	}
	if now >= 2*c {
		return true
	}
	return false
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(l []int) int {
	s := 0
	for _, num := range l {
		s += num
	}
	return s
}

func main() {
	fio := NewFastIO()
	defer fio.Flush()

	n, m := fio.ReadInts()
	l := fio.ReadInts()
	t := make([][]int, m)
	for i := 0; i < m; i++ {
		t[i] = fio.ReadInts()
	}
	sort.Slice(t, func(i, j int) bool {
		return t[i][0] < t[j][0]
	})

	st := 1
	end := 2 * sum(l)
	ans := end
	for st <= end {
		mid := (st + end) / 2
		if check(mid, n, m, l, t) {
			ans = mid
			end = mid - 1
		} else {
			st = mid + 1
		}
	}
	fio.WriteInt(ans)
}
