package main

import (
	"fmt"
	"strconv"
	"strings"
)

func intToString(n int64) string {
	return strconv.FormatInt(n, 10)
}

func sum(a, b string) string {
	k := 0
	if len(a) > len(b) {
		k = len(a) - len(b)
		for i := 0; i < k; i++ {
			b = "0" + b
		}
	} else {
		k = len(b) - len(a)
		for i := 0; i < k; i++ {
			a = "0" + a
		}
	}

	vect := make([]int64, 0)
	for i := len(a) - 1; i >= 0; i-- {
		numA, _ := strconv.ParseInt(string(a[i]), 10, 64)
		numB, _ := strconv.ParseInt(string(b[i]), 10, 64)
		vect = append(vect, numA+numB)
	}

	for i := 0; i < len(vect); i++ {
		if vect[i] > 9 {
			if i == len(vect)-1 {
				vect = append(vect, vect[i]/10)
				vect[i] %= 10
				break
			}
			vect[i+1] += vect[i] / 10
			vect[i] %= 10
		}
	}

	res := make([]byte, len(vect))
	for i := 0; i < len(vect); i++ {
		res[i] = byte(vect[i]) + '0'
	}
	return string(res)
}

func multiply(a, b string) string {
	vect := make([][]int64, 7000)
	for i := len(a) - 1; i >= 0; i-- {
		for u := 0; u < len(a)-i-1; u++ {
			vect[len(a)-i-1] = append(vect[len(a)-i-1], 0)
		}
		for j := len(b) - 1; j >= 0; j-- {
			numA, _ := strconv.ParseInt(string(a[i]), 10, 64)
			numB, _ := strconv.ParseInt(string(b[j]), 10, 64)
			vect[len(a)-i-1] = append(vect[len(a)-i-1], numA*numB)
		}
		for u := 0; u < len(vect[len(a)-i-1]); u++ {
			if vect[len(a)-i-1][u] > 9 {
				if u == len(vect[len(a)-i-1])-1 {
					vect[len(a)-i-1] = append(vect[len(a)-i-1], vect[len(a)-i-1][u]/10)
					vect[len(a)-i-1][u] = vect[len(a)-i-1][u] % 10
					break
				}
				vect[len(a)-i-1][u+1] += vect[len(a)-i-1][u] / 10
				vect[len(a)-i-1][u] = vect[len(a)-i-1][u] % 10
			}
		}
	}

	res := make([]string, 7000)
	for i := 0; i < len(a); i++ {
		for p := len(vect[i]) - 1; p >= 0; p-- {
			h := string(vect[i][p] + '0')
			res[i] += h
		}
	}

	ans := "0"
	for i := 0; i < len(a); i++ {
		ans = sum(ans, res[i])
	}
	return ans
}

func rec1(n int64) int64 {
	ans := int64(0)
	if n == 1 {
		for i := 0; i < 10; i++ {
			if i != 0 {
				ans++
			}
		}
	} else if n == 2 {
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				if i != 0 && i != k {
					ans++
				}
			}
		}
	} else if n == 3 {
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					if i != 0 && i != k && i != c && k != c {
						ans++
					}
				}
			}
		}
	} else if n == 4 {
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
	} else if n == 5 {
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
	} else if n == 6 {
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
	} else if n == 7 {
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
	} else if n == 8 {
		ans = 1632960
	} else if n == 9 {
		ans = 3265920
	} else if n == 10 {
		ans = 3265920
	}
	return ans
}

func rec(n int64) int64 {
	ans := int64(0)
	if n == 1 {
		for i := 0; i < 10; i++ {
			ans++
		}
	} else if n == 2 {
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				if i != k {
					ans++
				}
			}
		}
	} else if n == 3 {
		for i := 0; i < 10; i++ {
			for k := 0; k < 10; k++ {
				for c := 0; c < 10; c++ {
					if i != k && i != c && k != c {
						ans++
					}
				}
			}
		}
	} else if n == 4 {
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
	} else if n == 5 {
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
	} else if n == 6 {
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
	} else if n == 7 {
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
	} else if n == 8 {
		ans = 1814400
	} else if n == 9 {
		ans = 3628800
	} else if n == 10 {
		ans = 3628800
	}
	return ans
}

func main() {
	var x string
	for {
		_, err := fmt.Scan(&x)
		if err != nil {
			break
		}

		ans := "1"

		vis := make([]int, 101)
		for i := 0; i < 101; i++ {
			vis[i] = 0
		}

		CHn := int64(0)
		F := int64(0)
		for i := 0; i < len(x); i++ {
			if (x[i] >= 'A' && x[i] <= 'J') && i != 0 && vis[x[i]-'A'] == 0 {
				CHn++
				vis[x[i]-'A'] = 1
			} else if (x[i] >= 'A' && x[i] <= 'J') && i == 0 && vis[x[i]-'A'] == 0 {
				F++
				vis[x[i]-'A'] = 1
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
			ans = multiply(intToString(rec1(F+CHn)), ans)
		} else if CHn > 0 {
			ans = multiply(intToString(rec(CHn)), ans)
		}

		fmt.Print(ans)
		for i := int64(0); i < Zeros; i++ {
			fmt.Print("0")
		}
		fmt.Println()
	}
}
