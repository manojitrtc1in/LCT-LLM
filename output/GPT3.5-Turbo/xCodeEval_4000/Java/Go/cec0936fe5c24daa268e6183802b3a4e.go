package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)
	A := make([]int64, n)
	B := make([]int, n)
	used := make([]bool, n)
	order := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &A[i])
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(reader, &B[i])
		order[i] = i
	}

	sort.Slice(order, func(i, j int) bool {
		return A[order[i]] > A[order[j]]
	})

	res := int64(0)
	for idx := 0; idx < n; {
		to := idx
		for to+1 < n && A[order[to+1]] == A[order[idx]] {
			to++
		}
		valid := to > idx
		if !valid {
			for i := 0; i < idx; i++ {
				if used[i] && (A[order[i]]&A[order[idx]]) == A[order[idx]] {
					valid = true
				}
			}
		}
		if valid {
			for i := idx; i <= to; i++ {
				res += int64(B[order[i]])
				used[i] = true
			}
		}
		idx = to + 1
	}

	fmt.Fprintln(writer, res)
}

