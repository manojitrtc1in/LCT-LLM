package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var (
	in  *bufio.Reader
	out *bufio.Writer
)

func init() {
	in = bufio.NewReader(os.Stdin)
	out = bufio.NewWriter(os.Stdout)
}

func main() {
	defer out.Flush()
	run()
}

func run() {
	w, _ := strconv.Atoi(readString())
	if w == 2 {
		fmt.Fprint(out, "NO")
		return
	}
	if w%2 == 0 {
		fmt.Fprint(out, "YES")
	} else {
		fmt.Fprint(out, "NO")
	}
}

func readString() string {
	str, _ := in.ReadString('\n')
	return str[:len(str)-1]
}
