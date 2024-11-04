package main

import (
	"fmt"
)

type Mint int64

const MOD = 1000000007

func (m Mint) val() int64 {
	return int64(m)
}

func (m Mint) add(other Mint) Mint {
	return (m + other) % Mint(MOD)
}

func (m Mint) mul(other Mint) Mint {
	return (m * other) % Mint(MOD)
}

func main() {
	var q int64
	fmt.Scan(&q)
	for q > 0 {
		q--
		var n int64
