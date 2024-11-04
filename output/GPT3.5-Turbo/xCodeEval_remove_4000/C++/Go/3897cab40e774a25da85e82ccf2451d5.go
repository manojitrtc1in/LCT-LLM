package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const MAXLEN = 100000

var S [4]map[string]bool

func main() {
	var id int
	fmt.Scan(&id)

	S[1] = make(map[string]bool)
