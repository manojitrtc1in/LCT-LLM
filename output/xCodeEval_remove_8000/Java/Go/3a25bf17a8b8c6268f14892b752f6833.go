package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	scanner *bufio.Scanner
	writer  *bufio.Writer
)

func main() {
	scanner = bufio.NewScanner(os.Stdin)
	writer = bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	t := 1
	for tc := 0; tc < t; tc++ {
		sOG := nextString()
		n := len(sOG)

		if n == 1 {
			if sOG[0] == '0' || sOG[0] == '_' || sOG[0] == 'X' {
				fmt.Fprintln(writer, 1)
			} else {
				fmt.Fprintln(writer, 0)
			}
			continue
		}

		answer := 0

		{
			s := make([]byte, n)
			copy(s, sOG)

			shit := (s[n-1] != '_' && s[n-1] != 'X' && s[n-1] != '0')
			shit = shit || (s[n-2] != '_' && s[n-2] != 'X' && s[n-2] != '0')

			if !shit {
				if s[n-1] == 'X' || s[n-2] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '0'
						}
					}
				}
				s[n-1] = '0'
				s[n-2] = '0'

				answer += check([]byte("00"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []byte(strconv.Itoa(num) + "00")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := make([]byte, n)
			copy(s, sOG)

			shit := (s[n-1] != '_' && s[n-1] != 'X' && s[n-1] != '5')
			shit = shit || (s[n-2] != '_' && s[n-2] != 'X' && s[n-2] != '2')
			shit = shit || (s[n-1] == 'X' && s[n-2] == 'X')

			if !shit {
				if s[n-1] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '5'
						}
					}
				} else if s[n-2] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '2'
						}
					}
				}

				s[n-1] = '5'
				s[n-2] = '2'

				answer += check([]byte("25"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []byte(strconv.Itoa(num) + "25")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := make([]byte, n)
			copy(s, sOG)

			shit := (s[n-1] != '_' && s[n-1] != 'X' && s[n-1] != '0')
			shit = shit || (s[n-2] != '_' && s[n-2] != 'X' && s[n-2] != '5')
			shit = shit || (s[n-1] == 'X' && s[n-2] == 'X')

			if !shit {
				if s[n-1] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '0'
						}
					}
				} else if s[n-2] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '5'
						}
					}
				}

				s[n-1] = '0'
				s[n-2] = '5'

				answer += check([]byte("50"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []byte(strconv.Itoa(num) + "50")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := make([]byte, n)
			copy(s, sOG)

			shit := (s[n-1] != '_' && s[n-1] != 'X' && s[n-1] != '5')
			shit = shit || (s[n-2] != '_' && s[n-2] != 'X' && s[n-2] != '7')
			shit = shit || (s[n-1] == 'X' && s[n-2] == 'X')

			if !shit {
				if s[n-1] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '5'
						}
					}
				} else if s[n-2] == 'X' {
					for i := 0; i < n; i++ {
						if s[i] == 'X' {
							s[i] = '7'
						}
					}
				}

				s[n-1] = '5'
				s[n-2] = '7'

				answer += check([]byte("75"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []byte(strconv.Itoa(num) + "75")
					answer += check(tgt, s)
				}
			}
		}

		fmt.Fprintln(writer, answer)
	}
}

func check(tgt, src []byte) int {
	n := len(tgt)
	if len(src) != n {
		return 0
	}

	xDig := byte(0)
	for i := 0; i < n; i++ {
		if src[i] == 'X' {
			if xDig == 0 {
				xDig = tgt[i]
			} else {
				if tgt[i] != xDig {
					return 0
				}
			}
		}
	}

	if tgt[0] == '0' {
		return 0
	}

	for i := 0; i < n; i++ {
		if src[i] != '_' && src[i] != 'X' && tgt[i] != src[i] {
			return 0
		}
	}

	return 1
}

func nextString() string {
	scanner.Scan()
	return scanner.Text()
}

func nextInt() int {
	scanner.Scan()
	num, _ := strconv.Atoi(scanner.Text())
	return num
}

func nextLong() int64 {
	scanner.Scan()
	num, _ := strconv.ParseInt(scanner.Text(), 10, 64)
	return num
}

func nextDouble() float64 {
	scanner.Scan()
	num, _ := strconv.ParseFloat(scanner.Text(), 64)
	return num
}

func nextChar() byte {
	scanner.Scan()
	return scanner.Bytes()[0]
}

func nextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextInt()
	}
	return arr
}

func nextLongArray(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextLong()
	}
	return arr
}

func nextStringArray(n int) []string {
	arr := make([]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextString()
	}
	return arr
}

func nextCharArray() []byte {
	scanner.Scan()
	return scanner.Bytes()
}

func nextInt2DArray(n, m int) [][]int {
	arr := make([][]int, n)
	for i := 0; i < n; i++ {
		arr[i] = nextIntArray(m)
	}
	return arr
}

func nextLong2DArray(n, m int) [][]int64 {
	arr := make([][]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = nextLongArray(m)
	}
	return arr
}

func nextString2DArray(n, m int) [][]string {
	arr := make([][]string, n)
	for i := 0; i < n; i++ {
		arr[i] = nextStringArray(m)
	}
	return arr
}

func nextChar2DArray(n int) [][]byte {
	arr := make([][]byte, n)
	for i := 0; i < n; i++ {
		arr[i] = nextCharArray()
	}
	return arr
}
