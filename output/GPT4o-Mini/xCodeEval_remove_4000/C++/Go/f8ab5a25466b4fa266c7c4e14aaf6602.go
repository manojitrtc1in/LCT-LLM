package main

import (
	"fmt"
	"math/big"
	"strings"
)

func id0(n int64) string {
	return fmt.Sprintf("%d", n)
}

func sum(a, b string) string {
	maxLen := max(len(a), len(b))
	a = padLeft(a, maxLen)
	b = padLeft(b, maxLen)

	vect := make([]int64, maxLen)
	for i := maxLen - 1; i >= 0; i-- {
		vect[i] = int64(a[i]-'0') + int64(b[i]-'0')
	}

	for i := len(vect) - 1; i > 0; i-- {
		if vect[i] > 9 {
			vect[i-1] += vect[i] / 10
			vect[i] %= 10
		}
	}

	res := strings.Builder{}
	for _, v := range vect {
		res.WriteByte(byte(v + '0'))
	}
	return strings.TrimLeft(res.String(), "0")
}

func multiply(a, b string) string {
	if a == "0" || b == "0" {
		return "0"
	}

	res := big.NewInt(0)
	aInt := new(big.Int)
	bInt := new(big.Int)

	aInt.SetString(a, 10)
	bInt.SetString(b, 10)

	res.Mul(aInt, bInt)
	return res.String()
}

func rec1(n int64) int64 {
	ans := int64(0)
	switch n {
	case 1:
		for i := 0; i < 10; i++ {
			if i != 0 {
				ans++
			}
		}
	case 2:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				if i != 0 && i != k {
					ans++
				}
			}
		}
	case 3:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					if i != 0 && i != k && i != c && k != c {
						ans++
					}
				}
			}
		}
	case 4:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						if i != 0 && i != k && i != c && i != d && k != c && k != d && c != d {
							ans++
						}
					}
				}
			}
		}
	case 5:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							if i != 0 && i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e {
								ans++
							}
						}
					}
				}
			}
		}
	case 6:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							for f := 0; f < 10; f++ {
								if i != 0 && i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f {
									ans++
								}
							}
						}
					}
				}
			}
		}
	case 7:
		for i := 1; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							for f := 0; f < 10; f++ {
								for g := 0; g < 10; g++ {
									if i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g {
										ans++
									}
								}
							}
						}
					}
				}
			}
		}
	case 8:
		ans = 1632960
	case 9:
		ans = 3265920
	case 10:
		ans = 3265920
	}
	return ans
}

func rec(n int64) int64 {
	ans := int64(0)
	switch n {
	case 1:
		for i := 0; i < 10; i++ {
			ans++
		}
	case 2:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				if i != k {
					ans++
				}
			}
		}
	case 3:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					if i != k && i != c && k != c {
						ans++
					}
				}
			}
		}
	case 4:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						if i != k && i != c && i != d && k != c && k != d && c != d {
							ans++
						}
					}
				}
			}
		}
	case 5:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							if i != k && i != c && i != d && i != e && k != c && k != d && k != e && c != d && c != e && d != e {
								ans++
							}
						}
					}
				}
			}
		}
	case 6:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							for f := 0; f < 10; f++ {
								if i != k && i != c && i != d && i != e && i != f && k != c && k != d && k != e && k != f && c != d && c != e && c != f && d != e && d != f && e != f {
									ans++
								}
							}
						}
					}
				}
			}
		}
	case 7:
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					for d := 0; d < 10; d++ {
						for e := 0; e < 10; e++ {
							for f := 0; f < 10; f++ {
								for g := 0; g < 10; g++ {
									if i != k && i != c && i != d && i != e && i != f && i != g && k != c && k != d && k != e && k != f && k != g && c != d && c != e && c != f && c != g && d != e && d != f && d != g && e != f && e != g && f != g {
										ans++
									}
								}
							}
						}
					}
				}
			}
		}
	case 8:
		ans = 1814400
	case 9:
		ans = 3628800
	case 10:
		ans = 3628800
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func padLeft(s string, length int) string {
	return strings.Repeat("0", length-len(s)) + s
}

func main() {
	var x string
	for {
		if _, err := fmt.Scan(&x); err != nil {
			break
		}

		ans := "1"
		vis := make([]int, 101)
		CHn, F := int64(0), int64(0)

		for i := 0; i < len(x); i++ {
			if x[i] >= 'A' && x[i] <= 'J' {
				if i != 0 && vis[x[i]-'A'] == 0 {
					CHn++
					vis[x[i]-'A'] = 1
				} else if i == 0 && vis[x[i]-'A'] == 0 {
					F++
					vis[x[i]-'A'] = 1
				}
			}
		}

		Zeros := int64(0)
		if x[0] == '?' {
			ans = "9"
		}
		for i := 1; i < len(x); i++ {
			if x[i] == '?' {
				Zeros++
			}
		}

		if F != 0 {
			ans = multiply(id0(rec1(F + CHn)), ans)
		} else if CHn > 0 {
			ans = multiply(id0(rec(CHn)), ans)
		}

		fmt.Print(ans)
		for i := int64(0); i < Zeros; i++ {
			fmt.Print("0")
		}
		fmt.Println()
	}
}
