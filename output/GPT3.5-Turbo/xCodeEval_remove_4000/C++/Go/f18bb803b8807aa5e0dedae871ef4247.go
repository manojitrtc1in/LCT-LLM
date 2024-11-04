package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

var bit [100007]int
var x [100007]float64
var y [100007]float64
var w int
var cnt map[float64]int
var as [100007]float64
var cnta int
var bs [100007]struct {
	first  float64
	second int
}

func readInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func readFloat(scanner *bufio.Scanner) float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n := readInt(scanner)
	w = readInt(scanner)

	cnt = make(map[float64]int)

	for i := 0; i < n; i++ {
		a := readInt(scanner)
		b := readInt(scanner)
		x[i] = float64(a) / float64(b+w)
		y[i] = float64(a) / float64(b-w)
		cnt[y[i]]++
	}

	ans := 0

	for i := 0; i < n; i++ {
		ans += cnt[y[i]] - 1
	}

	ans /= 2

	for i := 0; i < n; i++ {
		as[i] = x[i]
	}

	sort.Float64s(as[:n])
	cnta = 0

	for i := 0; i < n; i++ {
		if i == 0 || as[i] != as[i-1] {
			as[cnta] = as[i]
			cnta++
		}
	}

	for i := 0; i < n; i++ {
		bs[i].first = y[i]
		bs[i].second = i
	}

	sort.Slice(bs[:n], func(i, j int) bool {
		return bs[i].first < bs[j].first
	})

	now := 0

	for i := 0; i < n; i++ {
		for bs[now].first < bs[i].first {
			id := sort.SearchFloat64s(as[:cnta], x[bs[now].second])
			bit[100006-id]++
			now++
		}

		id := sort.SearchFloat64s(as[:cnta], x[bs[i].second])
		ans += sum(100006 - id)
	}

	fmt.Println(ans)
}

func add(djg, x int) {
	for djg <= 100006 {
		bit[djg] += x
		djg += djg & -djg
	}
}

func sum(djg int) int {
	id0 := 0
	for djg > 0 {
		id0 += bit[djg]
		djg -= djg & -djg
	}
	return id0
}
