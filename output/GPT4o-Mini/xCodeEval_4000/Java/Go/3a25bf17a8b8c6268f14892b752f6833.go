package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const gigamod = 1000000007

var fr *FastReader
var out *bufio.Writer

func main() {
	fr = NewFastReader()
	out = bufio.NewWriter(os.Stdout)
	defer out.Flush()

	t := 1

	for tc := 0; tc < t; tc++ {
		sOG := fr.Next()
		n := len(sOG)

		if n == 1 {
			if sOG[0] == '0' || sOG[0] == '_' || sOG[0] == 'X' {
				fmt.Fprintln(out, 1)
			} else {
				fmt.Fprintln(out, 0)
			}
			continue
		}

		answer := 0

		{
			s := []rune(sOG)

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

				answer += check([]rune("00"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []rune(strconv.Itoa(num) + "00")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := []rune(sOG)

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

				answer += check([]rune("25"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []rune(strconv.Itoa(num) + "25")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := []rune(sOG)

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

				answer += check([]rune("50"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []rune(strconv.Itoa(num) + "50")
					answer += check(tgt, s)
				}
			}
		}

		{
			s := []rune(sOG)

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

				answer += check([]rune("75"), s)

				for num := 0; num < 1e6; num++ {
					tgt := []rune(strconv.Itoa(num) + "75")
					answer += check(tgt, s)
				}
			}
		}

		fmt.Fprintln(out, answer)
	}
}

func check(tgt, src []rune) int {
	n := len(tgt)
	if len(src) != n {
		return 0
	}

	var xDig rune
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

type FastReader struct {
	bfr *bufio.Reader
}

func NewFastReader() *FastReader {
	return &FastReader{bfr: bufio.NewReader(os.Stdin)}
}

func (fr *FastReader) Next() string {
	line, _ := fr.bfr.ReadString('\n')
	return strings.TrimSpace(line)
}

func (fr *FastReader) NextInt() int {
	val, _ := strconv.Atoi(fr.Next())
	return val
}

func (fr *FastReader) NextLong() int64 {
	val, _ := strconv.ParseInt(fr.Next(), 10, 64)
	return val
}

func (fr *FastReader) NextDouble() float64 {
	val, _ := strconv.ParseFloat(fr.Next(), 64)
	return val
}

func (fr *FastReader) NextChar() rune {
	return []rune(fr.Next())[0]
}

func (fr *FastReader) NextString() string {
	return fr.Next()
}

func (fr *FastReader) NextIntArray(n int) []int {
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		arr[i] = fr.NextInt()
	}
	return arr
}

func (fr *FastReader) NextDoubleArray(n int) []float64 {
	arr := make([]float64, n)
	for i := 0; i < n; i++ {
		arr[i] = fr.NextDouble()
	}
	return arr
}

func (fr *FastReader) NextLongArray(n int) []int64 {
	arr := make([]int64, n)
	for i := 0; i < n; i++ {
		arr[i] = fr.NextLong()
	}
	return arr
}
