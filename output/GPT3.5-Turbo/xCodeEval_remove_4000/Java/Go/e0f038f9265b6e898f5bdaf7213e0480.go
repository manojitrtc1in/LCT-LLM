package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	sc := bufio.NewScanner(os.Stdin)
	sc.Split(bufio.ScanWords)

	for i := nextInt(sc); i > 0; i-- {
		solve(sc)
	}
}

func solve(sc *bufio.Scanner) {
	n := nextInt(sc)
	dq := make([]int, n)
	for i := 0; i < n; i++ {
		dq[i] = nextInt(sc)
	}

	a := dq[0]
	b := 0
	pre := a
	cnt := 1

	for len(dq) > 0 {
		now := 0
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

	fmt.Printf("%d %d %d\n", cnt, a, b)
}

func nextInt(sc *bufio.Scanner) int {
	sc.Scan()
	num, _ := strconv.Atoi(sc.Text())
	return num
}
