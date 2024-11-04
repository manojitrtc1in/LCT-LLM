package main

import (
	"fmt"
	"math"
)

type id2 struct {
	data []int
}

func (a *id2) add(b int) {
	if len(a.data) == 0 {
		a.data = append(a.data, 0)
	}
	last := len(a.data) - 1
	if a.data[last] < 10 {
		a.data[last] = b
	} else {
		a.data[last] = a.data[last]%10 + 10*b
	}
}

func (a *id2) clear() {
	a.data = nil
}

func (a *id2) t() int64 {
	if len(a.data) == 1 {
		return int64(a.data[0])
	}
	return int64(a.data[1])*100000000 + int64(a.data[0])
}

func (a *id2) size() int {
	res := 0
	for _, v := range a.data {
		res += 8
	}
	last := a.data[len(a.data)-1]
	if last >= 10000 {
		if last >= 1000000 {
			if last >= 10000000 {
			} else {
				res--
			}
		} else {
			if last >= 100000 {
				res -= 2
			} else {
				res -= 3
			}
		}
	} else {
		if last >= 100 {
			if last >= 1000 {
				res -= 4
			} else {
				res -= 5
			}
		} else {
			if last >= 10 {
				res -= 6
			} else {
				res -= 7
			}
		}
	}
	return res
}

func (a *id2) doTrim() {
	for len(a.data) > 1 && a.data[len(a.data)-1] == 0 {
		a.data = a.data[:len(a.data)-1]
	}
}

func (a *id2) output() {
	for i := len(a.data) - 1; i >= 0; i-- {
		if i == len(a.data)-1 {
			fmt.Printf("%d", a.data[i])
		} else {
			fmt.Printf("%08d", a.data[i])
		}
	}
}

func solve() int {
	var ch byte
	fmt.Scanf("%c\n", &ch)
	if ch == '0' {
		return 1 << 0
	}
	if ch == '1' {
		return 1 << 15
	}
	if ch == '?' {
		return (1 << 3) | (1 << 12)
	}

	x := solve()
	fmt.Scanf("%c\n", &ch)
	y := solve()

	res := 0
	for i := 0; i < 16; i++ {
		if (x & (1 << i)) == 0 {
			continue
		}
		for j := 0; j < 16; j++ {
			if (y & (1 << j)) == 0 {
				continue
			}
			var k int
			if ch == '^' {
				k = i ^ j
			} else if ch == '&' {
				k = i & j
			} else if ch == '|' {
				k = i | j
			}
			res |= 1 << k
		}
	}
	return res
}

func main() {
	var n int
	fmt.Scan(&n)
	if ^0x8421&solve() != 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
