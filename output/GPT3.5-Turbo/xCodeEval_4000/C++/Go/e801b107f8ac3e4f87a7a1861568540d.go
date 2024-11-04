package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pii struct {
	first  int
	second int
}

type pll struct {
	first  int64
	second int64
}

type pdb struct {
	first  float64
	second float64
}

func make_pair(a int, b int) pii {
	return pii{a, b}
}

func make_pair(a int64, b int64) pll {
	return pll{a, b}
}

func make_pair(a float64, b float64) pdb {
	return pdb{a, b}
}

func main() {
	adskiy_razgon()
	t := 1
	fmt.Scan(&t)
	for i := 1; i <= t; i++ {
		solve()
	}
}

func adskiy_razgon() {
	// Set the input/output buffering to be synchronized with the standard C streams.
	// It is a common optimization technique for C++ programs.
	// However, it is not necessary in Go.
	// So, this function can be removed in the Go version.
}

func solve() {
	m := make(map[int64]int64)
	var n, s, k int64
	fmt.Scan(&n, &s, &k)
	ans := int64(1e9 + 7)
	cnt := int64(0)
	for i := int64(1); i <= n; i++ {
		var a int64
		fmt.Scan(&a)
		if i >= k {
			m[a-k]--
			if m[a-k] == 0 {
				cnt--
			}
			m[a]++
			if m[a] == 1 {
				cnt++
			}
			ans = min(ans, cnt)
		} else {
			m[a]++
			if m[a] == 1 {
				cnt++
			}
		}
	}
	ans = min(ans, cnt)
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func readLine() string {
	reader := bufio.NewReader(os.Stdin)
	str, _ := reader.ReadString('\n')
	return strings.TrimSpace(str)
}

func readInt(str string) int {
	num, _ := strconv.Atoi(str)
	return num
}

func readInt64(str string) int64 {
	num, _ := strconv.ParseInt(str, 10, 64)
	return num
}

func readFloat64(str string) float64 {
	num, _ := strconv.ParseFloat(str, 64)
	return num
}

func readIntArray(str string) []int {
	strArr := strings.Fields(str)
	arr := make([]int, len(strArr))
	for i, s := range strArr {
		arr[i] = readInt(s)
	}
	return arr
}

func readInt64Array(str string) []int64 {
	strArr := strings.Fields(str)
	arr := make([]int64, len(strArr))
	for i, s := range strArr {
		arr[i] = readInt64(s)
	}
	return arr
}

func readFloat64Array(str string) []float64 {
	strArr := strings.Fields(str)
	arr := make([]float64, len(strArr))
	for i, s := range strArr {
		arr[i] = readFloat64(s)
	}
	return arr
}

func writeInt(num int) {
	fmt.Print(num)
}

func writeInt64(num int64) {
	fmt.Print(num)
}

func writeFloat64(num float64) {
	fmt.Print(num)
}

func writeIntArray(arr []int) {
	for i, num := range arr {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num)
	}
}

func writeInt64Array(arr []int64) {
	for i, num := range arr {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num)
	}
}

func writeFloat64Array(arr []float64) {
	for i, num := range arr {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(num)
	}
}

func println() {
	fmt.Println()
}

func printArray(arr []interface{}) {
	for i, val := range arr {
		if i > 0 {
			fmt.Print(" ")
		}
		fmt.Print(val)
	}
	fmt.Println()
}

func yes(ok bool) {
	if ok {
		fmt.Println("YES")
	} else {
		fmt.Println("Yes")
	}
}

func no(ok bool) {
	if ok {
		fmt.Println("NO")
	} else {
		fmt.Println("No")
	}
}
