package main

import (
	"bufio"
	"fmt"
	"os"
)

var tr [1010101][2]int

func merge(a, b [2]int) [2]int {
	if b[0] == 0 {
		a[1] += b[1]
		return a
	} else {
		b[0] += a[0]
		return b
	}
}

func build(cur, l, r int, s string) {
	if l == r {
		if s[l] == 'A' {
			tr[cur] = [2]int{0, 1}
		} else {
			tr[cur] = [2]int{1, 0}
		}
	} else {
		m := (l + r) / 2
		dcur := cur + cur
		build(dcur, l, m, s)
		build(dcur+1, m+1, r, s)
		tr[cur] = merge(tr[dcur], tr[dcur+1])
	}
}

func get(cur, l, r, x, y int) [2]int {
	if x > r || y < l {
		return [2]int{}
	}
	if x <= l && r <= y {
		return tr[cur]
	}
	m := (l + r) / 2
	dcur := cur + cur
	return merge(get(dcur, l, m, x, y), get(dcur+1, m+1, r, x, y))
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var s string
	fmt.Fscan(reader, &s)
	var t string
	fmt.Fscan(reader, &t)
	n := len(s)
	s += t
	sn := len(s)
	build(1, 0, sn-1, s)
	var q int
	fmt.Fscan(reader, &q)
	var ans string
	for i := 0; i < q; i++ {
		l := make([]int, 2)
		r := make([]int, 2)
		for j := 0; j < 2; j++ {
			fmt.Fscan(reader, &l[j], &r[j])
			l[j]--
			r[j]--
		}
		l[1] += n
		r[1] += n
		a := get(1, 0, sn-1, l[0], r[0])
		b := get(1, 0, sn-1, l[1], r[1])
		if a[0] > b[0] || a[0]%2 != b[0]%2 || a[1] < b[1] {
			ans += "0"
			continue
		}
		if (a[0] == b[0] && a[1]%3 == b[1]%3) || (a[0] != b[0] && a[0] > 0) || (a[1] > b[1] && a[0] != b[0]) {
			ans += "1"
		} else {
			ans += "0"
		}
	}
	fmt.Fprintln(writer, ans)
}
