package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	tot := 0
	data := make([][]int, n)

	for i := 0; i < n; i++ {
		k := nextInt(scanner)
		a := nextInt(scanner)
		x := nextInt(scanner)
		y := nextInt(scanner)
		m := nextInt(scanner)
		tot += k
		tmp := make([]int, k)
		tmp[0] = a
		for j := 1; j < k; j++ {
			tmp[j] = (tmp[j-1]*x + y) % m
		}
		data[i] = tmp
	}

	q := make([][3]int, 0)
	for i := 0; i < n; i++ {
		q = append(q, [3]int{data[i][0], i, 0})
	}

	ans := make([]int, 0)
	sol := make([][2]int, 0)
	p := 0
	for len(ans) < tot {
		idx := -1
		for i := 0; i < len(q); i++ {
			if q[i][0] == p {
				idx = i
				break
			}
		}
		if idx == -1 {
			idx = 0
		}
		v := q[idx][0]
		p = v
		o := q[idx][1:]
		ans = append(ans, v)
		sol = append(sol, [2]int{v, o[0] + 1})
		q = append(q[:idx], q[idx+1:]...)
		if o[1]+1 < len(data[o[0]]) {
			q = append(q, [3]int{data[o[0]][o[1]+1], o[0], o[1] + 1})
		}
	}

	bad := 0
	for i := 1; i < len(ans); i++ {
		if ans[i-1] > ans[i] {
			bad++
		}
	}
	fmt.Println(bad)
	if tot <= 200000 {
		for i := 0; i < len(sol); i++ {
			fmt.Println(sol[i][0], sol[i][1])
		}
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
