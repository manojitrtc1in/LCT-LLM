package main

import (
	"fmt"
	"strings"
)

func zz(x string) int {
	q := "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ!"
	a := 0
	for _, i := range x {
		a = a*len(q) + strings.IndexRune(q, i)
	}
	return a
}

func main() {
	z := `"""6"k"="3,"iG"17G"6m?"C@f"2<6z"ki1,"1Y[{s"dnF)N"1j.&{o"aZ>k}1"173exa+"atUi,},"1canZ35z"b*-!Ps6l"1z<F!WJlC"fQrp~1])H"1}8l0AiPTl"nXgm`
	k := []int{}
	for _, x := range strings.Split(z, `"`) {
		k = append(k, zz(x))
	}

	var n, m int
	fmt.Scanf("%d %d", &n, &m)

	fmt.Println(k[n] % m)
}
