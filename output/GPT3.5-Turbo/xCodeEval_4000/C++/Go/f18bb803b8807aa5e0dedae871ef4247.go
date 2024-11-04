package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
)

type B1T struct {
	bit []int
	n   int
}

func (b *B1T) add(djg, x int) {
	for djg <= b.n {
		b.bit[djg] += x
		djg += (djg & -djg)
	}
}

func (b *B1T) sum(djg int) int {
	s0m := 0
	for djg > 0 {
		s0m += b.bit[djg]
		djg -= (djg & -djg)
	}
	return s0m
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := nextInt(scanner)
	w := nextInt(scanner)

	x := make([]float64, n)
	y := make([]float64, n)
	cnt := make(map[float64]int)

	for i := 0; i < n; i++ {
		a := nextInt(scanner)
		b := nextInt(scanner)
		x[i] = float64(a) / float64(b+w)
		y[i] = float64(a) / float64(b-w)
		cnt[y[i]]++
	}

	ans := 0
	for i := 0; i < n; i++ {
		ans += cnt[y[i]] - 1
	}
	ans /= 2

	as := make([]float64, n)
	copy(as, x)
	sort.Float64s(as)
	cnta := 0
	for i := 0; i < n; i++ {
		if i == 0 || as[i] != as[i-1] {
			as[cnta] = as[i]
			cnta++
		}
	}

	bs := make([]pair, n)
	for i := 0; i < n; i++ {
		bs[i] = pair{y[i], i}
	}
	sort.Slice(bs, func(i, j int) bool {
		return bs[i].first < bs[j].first
	})

	bit := B1T{bit: make([]int, 100007), n: 100007}
	now := 0
	for i := 0; i < n; i++ {
		for bs[now].first < bs[i].first {
			id := sort.SearchFloat64s(as, x[bs[now].second])
			bit.add(100006-id, 1)
			now++
		}
		id := sort.SearchFloat64s(as, x[bs[i].second])
		ans += bit.sum(100006 - id)
	}

	fmt.Println(ans)
}

type pair struct {
	first  float64
	second int
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
