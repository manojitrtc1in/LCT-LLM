package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const MOD = 1000000007

type FastReader struct {
	scanner *bufio.Scanner
}

func NewFastReader() *FastReader {
	return &FastReader{scanner: bufio.NewScanner(os.Stdin)}
}

func (fr *FastReader) Next() string {
	fr.scanner.Scan()
	return fr.scanner.Text()
}

func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next())
	return val
}

func (fr *FastReader) NextLong() int64 {
	val, _ := strconv.ParseInt(fr.Next(), 10, 64)
	return val
}

func main() {
	fr := NewFastReader()
	
	nt := 1
	
	for it := 0; it < nt; it++ {
		n := fr.NextLong()
		k := fr.NextLong()
		
		if k == 1 {
			fmt.Println(n)
			return
		}
		
		lo, hi := int64(1), n/2
		
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
		
		lo, hi = 1, n/2
		
		for lo <= hi {
			mid := (hi + lo) / 2
			val := mid * 2
			if cnt(val, n) >= k {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
		
		cand = max(cand, hi*2)
		fmt.Println(cand)
	}
}

func cnt(v, n int64) int64 {
	if v > n {
		return 0
	}
	
	var count int64
	if v%2 == 1 {
		segSize := int64(1)
		start := v
		for start <= n {
			end := min(n, start+segSize-1)
			count += end - start + 1
			
			segSize *= 2
			start *= 2
		}
	} else {
		segSize := int64(2)
		start := v
		for start <= n {
			end := min(n, start+segSize-1)
			count += end - start + 1
			
			segSize *= 2
			start *= 2
		}
	}
	return count
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
