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

	// Read input
	scanner.Scan()
	t, _ := strconv.Atoi(scanner.Text())

	for tc := 0; tc < t; tc++ {
		// Read input
		scanner.Scan()
		sOG := scanner.Text()
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
			copy(s, []byte(sOG))

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
			copy(s, []byte(sOG))

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
			copy(s, []byte(sOG))

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
			copy(s, []byte(sOG))

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
