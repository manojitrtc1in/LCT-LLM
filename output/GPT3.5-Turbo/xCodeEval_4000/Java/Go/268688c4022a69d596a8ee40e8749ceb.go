package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := NewScanner()
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	for t := sc.NextInt(); t > 0; t-- {
		solve(sc, out)
	}
}

func solve(sc *Scanner, out *bufio.Writer) {
	n := sc.NextInt()
	dq := make([]int, n)
	for i := 0; i < n; i++ {
		dq[i] = sc.NextInt()
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

	fmt.Fprintf(out, "%d %d %d\n", cnt, a, b)
}

type Scanner struct {
	sc *bufio.Scanner
}

func NewScanner() *Scanner {
	sc := &Scanner{sc: bufio.NewScanner(os.Stdin)}
	sc.sc.Split(bufio.ScanWords)
	return sc
}

func (sc *Scanner) Next() string {
	sc.sc.Scan()
	return sc.sc.Text()
}

func (sc *Scanner) NextInt() int {
	n, _ := strconv.Atoi(sc.Next())
	return n
}

func (sc *Scanner) NextInt64() int64 {
	n, _ := strconv.ParseInt(sc.Next(), 10, 64)
	return n
}

func (sc *Scanner) NextFloat64() float64 {
	n, _ := strconv.ParseFloat(sc.Next(), 64)
	return n
}
