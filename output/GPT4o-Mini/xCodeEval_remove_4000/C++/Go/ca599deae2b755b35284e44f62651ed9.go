package main

import (
	"fmt"
	"math"
	"sort"
)

type int64 int64
type uint64 uint64

func assert(expr bool, msg string) {
	if !expr {
		panic(fmt.Sprintf("%s - %s", "file.go", msg))
	}
}

type ScopeTimer struct {
	msg string
}

func NewScopeTimer(msg string) *ScopeTimer {
	return &ScopeTimer{msg: msg}
}

func (st *ScopeTimer) Stop() {
	// Implement timing logic if needed
	fmt.Println(st.msg)
}

type AbsDiff struct{}

func (AbsDiff) Apply(x, y int) int {
	return int(math.Abs(float64(x - y)))
}

type IsIn struct {
	vals []int
}

func NewIsIn(vals []int) *IsIn {
	return &IsIn{vals: vals}
}

func (is *IsIn) Contains(x int) bool {
	for _, v := range is.vals {
		if v == x {
			return true
		}
	}
	return false
}

func CountInv(arr []int) int {
	l := []int{}
	cnt := 0

	for n := 0; n < len(arr); n++ {
		iter := 0
		cnt += n

		for iter < len(l) && l[iter] <= arr[n] {
			iter++
			cnt--
		}
		l = append(l[:iter], append([]int{arr[n]}, l[iter:]...)...)
	}

	return cnt
}

func Id27(first, last []int, val int) {
	for i := 0; first[i] != last[i]; i++ {
		first[i] = val
		val++
	}
}

func Remove(first, last []int, begin, end []int) []int {
	result := []int{}
	for _, v := range first {
		if !contains(end, v) {
			result = append(result, v)
		}
	}
	return result
}

func contains(slice []int, val int) bool {
	for _, v := range slice {
		if v == val {
			return true
		}
	}
	return false
}

func Tokenize(str string, sep rune) []string {
	var res []string
	var follow, lead int

	for {
		for lead < len(str) && rune(str[lead]) != sep {
			lead++
		}
		res = append(res, str[follow:lead])

		if lead < len(str) {
			follow = lead + 1
			lead++
		} else {
			break
		}
	}

	return res
}

func Chunk(first, last string, k int, id7 bool) []string {
	var strList []string

	if id7 {
		for j := len(last); j > 0; j -= k {
			i := j - k
			if i < 0 {
				i = 0
			}
			strList = append(strList, last[i:j])
		}
	} else {
		for i := 0; i < len(last); i += k {
			j := i + k
			if j > len(last) {
				j = len(last)
			}
			strList = append(strList, last[i:j])
		}
	}

	return strList
}

func Chmod(num string, n, m uint) string {
	// Implement the logic for converting number bases
	return ""
}

func main() {
	var str string
	var n int
	fmt.Scan(&str, &n)

	soln := make([][]int, 2)
	for i := range soln {
		soln[i] = make([]int, n+1)
	}

	if str[len(str)-1] == 'F' {
		for j := 0; j < n+1; j++ {
			if j%2 == 1 {
				soln[0][j] = 0
			} else {
				soln[0][j] = 1
			}
		}
	} else {
		for j := 0; j < n+1; j++ {
			if j%2 == 1 {
				soln[0][j] = 1
			} else {
				soln[0][j] = 0
			}
		}
	}

	copy(soln[1], soln[0])

	for i := len(str) - 2; i >= 0; i-- {
		id12 := make([][]int, 2)
		for i := range id12 {
			id12[i] = make([]int, n+1)
		}
		copy(id12[0], soln[0])
		copy(id12[1], soln[1])

		if str[i] == 'F' {
			soln[0][0] = 1 + id12[0][0]
			soln[1][0] = 1 + id12[1][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(1+id12[0][j], -id12[1][j-1])
				soln[1][j] = min(1+id12[1][j], -id12[0][j-1])
			}
		} else {
			soln[0][0] = -id12[1][0]
			soln[1][0] = -id12[0][0]

			for j := 1; j < n+1; j++ {
				soln[0][j] = max(-id12[1][j], 1+id12[0][j-1])
				soln[1][j] = min(-id12[0][j], 1+id12[1][j-1])
			}
		}
	}

	fmt.Println(max(soln[0][n], -soln[1][n]))
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
