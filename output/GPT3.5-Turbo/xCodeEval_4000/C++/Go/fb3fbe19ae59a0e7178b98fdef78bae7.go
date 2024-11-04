package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

const Maxn = 100005

var l [Maxn]int
var r [Maxn]int
var n, m int
var sum [Maxn]int
var dp1 [Maxn]int
var dp2 [Maxn]int
var bit [Maxn]int

func modify(pos, val int) {
	for pos < Maxn {
		if bit[pos] < val {
			bit[pos] = val
		}
		pos += pos & -pos
	}
}

func query(pos int) int {
	ans := 0
	for pos > 0 {
		if ans < bit[pos] {
			ans = bit[pos]
		}
		pos -= pos & -pos
	}
	return ans
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n = nextInt(scanner)
	m = nextInt(scanner)

	for i := 0; i < n; i++ {
		l[i] = nextInt(scanner)
		r[i] = nextInt(scanner)
		sum[l[i]]++
		sum[r[i]+1]--
	}

	for i := 1; i <= m; i++ {
		sum[i] += sum[i-1]
	}

	dp1[0] = 0
	for i := 1; i <= m; i++ {
		dp1[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp1[i])
	}

	bit = [Maxn]int{}
	for i := m; i >= 1; i-- {
		dp2[i] = query(sum[i]+1) + 1
		modify(sum[i]+1, dp2[i])
	}

	ans := 0
	for i := 1; i <= m; i++ {
		if ans < dp1[i]+dp2[i]-1 {
			ans = dp1[i] + dp2[i] - 1
		}
	}

	fmt.Println(ans)
}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}
