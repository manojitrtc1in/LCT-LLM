package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var mod int = 1000000007

func solve() {
	n, m := ni(), ni()

	if m > n+1 {
		fmt.Println(0)
		return
	}

	dp := [][]int{
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
