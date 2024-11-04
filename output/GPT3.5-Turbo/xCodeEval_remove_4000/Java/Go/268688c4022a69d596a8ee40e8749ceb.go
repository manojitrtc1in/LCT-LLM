package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc *bufio.Scanner
var out *bufio.Writer

func init() {
	sc = bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)
	out = bufio.NewWriter(os.Stdout)
}

func main() {
	defer out.Flush()
	for t := nextInt(); t > 0; t-- {
		solve()
	}
}

func solve() {
	n := nextInt()
	dq := make([]int, n)
	for i := 0; i < n; i++ {
		dq[i] = nextInt()
	}
	a := dq[0]
	b := 0
	pre := a
	var now, cnt int
	cnt = 1
	for len(dq) > 0 {
		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[len(dq)-1]
			dq = dq[:len(dq)-1]
		}
		if now != 0 {
			b += now
			pre = now
			cnt++
		}

		if len(dq) == 0 {
			break
		}

		now = 0
		for now <= pre && len(dq) > 0 {
			now += dq[0]
			dq = dq[1:]
		}
		if now != 0 {
			a += now
			pre = now
			cnt++
		}
	}
	fmt.Fprintln(out, cnt, a, b)
}

func nextInt() int {
	sc.Scan()
	val, _ := strconv.Atoi(sc.Text())
	return val
}
