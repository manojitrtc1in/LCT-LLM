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
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := nextInt(scanner)
	for t > 0 {
		n := nextInt(scanner)
		k := nextInt(scanner)
		d := nextInt(scanner)
		a := make([]int, n)
		hm := make(map[int]int)
		occ := make([]int, n+1)
		id := 0
		for i := 0; i < n; i++ {
			a[i] = nextInt(scanner)
			if _, ok := hm[a[i]]; !ok {
				hm[a[i]] = id
				id++
			}
		}
		for i := 0; i < n; i++ {
			a[i] = hm[a[i]]
		}
		ans := 0
		for i := 0; i < d; i++ {
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans++
			}
		}
		ansl := ans
		for i := d; i < n; i++ {
			ans1 := ansl
			occ[a[i]]++
			if occ[a[i]] == 1 {
				ans1++
			}
			occ[a[i-d]]--
			if occ[a[i-d]] == 0 {
				ans1--
			}
			if ans1 < ans {
				ans = ans1
			}
			ansl = ans1
		}
		fmt.Fprintln(out, ans)
		t--
	}
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
