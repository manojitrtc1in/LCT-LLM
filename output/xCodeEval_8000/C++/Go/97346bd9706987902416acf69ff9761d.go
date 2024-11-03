package main

import (
	"fmt"
	"math"
)

const MaxN = 30000
const MaxM = 100000

var f [MaxN]bool
var fd [MaxM + 100]bool
var p [MaxN]int
var pn int
