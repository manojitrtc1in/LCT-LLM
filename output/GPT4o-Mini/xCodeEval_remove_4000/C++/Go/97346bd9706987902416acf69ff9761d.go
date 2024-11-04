package main

import (
	"fmt"
	"os"
)

const MaxN = 30000
const MaxM = 100000

var f [MaxN]bool
var fd [MaxM + 100]bool
var p [MaxN]int
var pn int

var s = [...]int{
