package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

var mod = int(math.Pow(10, 9) + 7)
var dx = []int{-1, 0, 1, 0}
var dy = []int{0, -1, 0, 1}
var dx8 = []int{-1, -1, -1, 0, 0, 1, 1, 1}
var dy8 = []int{-1, 0, 1, -1, 1, -1, 0, 1}
var dx9 = []int{-1, -1, -1, 0, 0, 0, 1, 1, 1}
var dy9 = []int{-1, 0, 1, -1, 0, 1, -1, 0, 1}
var eps = 1e-10
var primeNumbers = []int{}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanLines)

	scanner.Scan()
	str := scanner.Text()
	inp := []rune(str)
	n := len(inp)

	pos := []string{"00", "25", "50", "75"}
	count := 0

	if len(inp) == 1 {
		if inp[0] == '0' || inp[0] == 'X' || inp[0] == '_' {
			count++
		}
	} else {
		for _, cstr := range pos {
			X := -1
			idx := 0
			possible := true
			for i := n - 2; i < n; i++ {
				curr := inp[i]
				strcurr := rune(cstr[idx])
				idx++

				if curr == '_' {
					continue
				} else if curr == 'X' {
					if X == -1 {
						X = int(strcurr - '0')
					} else {
						if X != int(strcurr-'0') {
							possible = false
							break
						}
					}
				} else {
					if curr != strcurr {
						possible = false
						break
					}
				}
			}

			if !possible {
				continue
			}

			if len(str) == 2 {
				if cstr[0] == '0' {
					continue
				}

				count++
				continue
			}

			ninp := make([]rune, len(inp))
			copy(ninp, inp)

			cntX := 0
			for _, ch := range inp {
				if ch == 'X' {
					cntX++
				}
			}

			if X != -1 || cntX == 0 {
				if X != -1 {
					for k := 0; k < len(str); k++ {
						if ninp[k] == 'X' {
							ninp[k] = rune(X + '0')
						}
					}
				}

				if ninp[0] == '0' {
					continue
				}

				counter := 1
				for k := 0; k < len(str)-2; k++ {
					if ninp[k] == '_' {
						if k == 0 {
							counter = counter * 9
						} else {
							counter = counter * 10
						}
					}
				}

				count += counter
			} else {
				if ninp[0] == '0' {
					continue
				}

				counter := 1
				for k := 0; k < len(str)-2; k++ {
					if ninp[k] == '_' {
						if k == 0 {
							counter = counter * 9
						} else {
							counter = counter * 10
						}
					}
				}

				if ninp[0] == 'X' {
					counter = counter * 9
				} else {
					counter = counter * 10
				}

				count += counter
			}
		}
	}

	fmt.Println(count)
}
