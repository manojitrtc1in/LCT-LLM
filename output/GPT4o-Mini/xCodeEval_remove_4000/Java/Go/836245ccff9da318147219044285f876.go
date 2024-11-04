package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

const mod = 1000000007
const mod2 = 998244353

var pref []int64

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	n := readInt(reader)
	a := make([]int64, n)
	input(reader, a, n)

	if n > 66 {
		fmt.Fprintln(writer, 1)
		return
	}

	pref = make([]int64, n+1)
	pref[1] = a[0]
	for i := 1; i < n; i++ {
		pref[i+1] = pref[i] ^ a[i]
	}

	gg := 34
	for c := 0; c < n-1; c++ {
		for left := c; left >= 0; left-- {
			for right := c + 1; right < n; right++ {
				if xor(left, c) > xor(c+1, right) {
					gg = min(gg, right-left-1)
				}
			}
		}
	}
	if gg == 34 {
		fmt.Fprintln(writer, -1)
	} else {
		fmt.Fprintln(writer, gg)
	}
}

func xor(i, j int) int64 {
	return pref[j+1] ^ pref[i]
}

func input(reader *bufio.Reader, a []int64, n int) {
	for i := 0; i < n; i++ {
		a[i] = readInt64(reader)
	}
}

func readInt(reader *bufio.Reader) int {
	line, _ := reader.ReadString('\n')
	val, _ := strconv.Atoi(line[:len(line)-1])
	return val
}

func readInt64(reader *bufio.Reader) int64 {
	line, _ := reader.ReadString('\n')
	val, _ := strconv.ParseInt(line[:len(line)-1], 10, 64)
	return val
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sortInt(a []int) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func sortInt64(a []int64) {
	sort.Slice(a, func(i, j int) bool {
		return a[i] < a[j]
	})
}

func shuffleAndSortInt(a []int) {
	rand.Shuffle(len(a), func(i, j int) {
		a[i], a[j] = a[j], a[i]
	})
	sortInt(a)
}

func shuffleAndSortInt64(a []int64) {
	rand.Shuffle(len(a), func(i, j int) {
		a[i], a[j] = a[j], a[i]
	})
	sortInt64(a)
}
