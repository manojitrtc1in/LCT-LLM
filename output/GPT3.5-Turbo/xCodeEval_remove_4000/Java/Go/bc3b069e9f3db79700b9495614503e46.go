package main

import (
	"bufio"
	"fmt"
	"os"
)

var in *bufio.Scanner
var out *bufio.Writer

func init() {
	in = bufio.NewScanner(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
	in.Split(bufio.ScanWords)
}

func nextInt() int {
	in.Scan()
	val := 0
	for _, c := range in.Bytes() {
		val = val*10 + int(c-'0')
	}
	return val
}

func nextString() string {
	in.Scan()
	return in.Text()
}

func main() {
	pl := nextInt()
	pr := nextInt()
	ll := nextInt()
	lr := nextInt()
	k := nextInt()

	if pl > ll {
		tmp := pl
		pl = ll
		ll = tmp
		tmp = pr
		pr = lr
		lr = tmp
	}

