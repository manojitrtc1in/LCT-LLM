package main

import (
	"fmt"
	"math"
)

const inf = 0x7FDFDFDF

var pr [32000]int
var epr int
var U1 [32000]bool
var U [105000]bool

var nakop = [32000]int{
