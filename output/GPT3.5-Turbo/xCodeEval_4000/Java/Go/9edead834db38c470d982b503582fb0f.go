package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var mod int = int(math.Pow(10, 9)) + 7
var n int
var m int
var a [][][]int
var st []string

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	n = nextInt(scanner)
	m = nextInt(scanner)
	a = make([][][]int, n)
	st = make([]string, n)

	for i := 0; i < n; i++ {
		st[i] = nextString(scanner)
	}

	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if st[i][j] == '1' {
				ans++
			}
		}
	}

	fmt.Println(ans)

}

func nextInt(scanner *bufio.Scanner) int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextString(scanner *bufio.Scanner) string {
	scanner.Scan()
	return scanner.Text()
}
