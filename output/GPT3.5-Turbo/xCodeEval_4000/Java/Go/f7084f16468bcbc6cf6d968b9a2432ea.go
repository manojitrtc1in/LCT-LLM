package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

type FastReader struct {
	br *bufio.Reader
}

func NewFastReader(br *bufio.Reader) *FastReader {
	return &FastReader{br: br}
}

func (fr *FastReader) Next() string {
	for {
		line, err := fr.br.ReadString('\n')
		if err != nil {
			return ""
		}
		line = strings.TrimSpace(line)
		if line != "" {
			return line
		}
	}
}

func (fr *FastReader) NextInt() int {
	num, _ := strconv.Atoi(fr.Next())
	return num
}

func (fr *FastReader) NextLong() int64 {
	num, _ := strconv.ParseInt(fr.Next(), 10, 64)
	return num
}

func (fr *FastReader) NextDouble() float64 {
	num, _ := strconv.ParseFloat(fr.Next(), 64)
	return num
}

func (fr *FastReader) NextLine() string {
	line, _ := fr.br.ReadString('\n')
	return strings.TrimSpace(line)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	in := NewFastReader(reader)

	nt := 1
	sb := strings.Builder{}

	for it := 0; it < nt; it++ {
		n := in.NextLong()
		k := in.NextLong()

		if k == 1 {
			fmt.Println(n)
			return
		}

		lo := int64(1)
		hi := n / 2

		for lo <= hi {
			mid := (hi + lo) / 2
			val := mid*2 - 1

			if cnt(val, n) >= k {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		cand := hi*2 - 1
		if cnt(cand, n) < k {
			cand = 0
		}

		lo = 1
		hi = n / 2

		for lo <= hi {
			mid := (hi + lo) / 2
			val := mid * 2
			if cnt(val, n) >= k {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}

		cand = int64(math.Max(float64(cand), float64(hi*2)))
		fmt.Println(cand)
	}

	fmt.Print(sb.String())
}

func cnt(v, n int64) int64 {
	if v > n {
		return 0
	}

	cnt := int64(0)
	if v%2 == 1 {
		segSize := int64(1)
		start := v
		for start <= n {
			end := int64(math.Min(float64(n), float64(start+segSize-1)))
			cnt += end - start + 1

			segSize *= 2
			start *= 2
		}

	} else {

		segSize := int64(2)
		start := v
		for start <= n {
			end := int64(math.Min(float64(n), float64(start+segSize-1)))
			cnt += end - start + 1

			segSize *= 2
			start *= 2
		}

	}

	return cnt
}
