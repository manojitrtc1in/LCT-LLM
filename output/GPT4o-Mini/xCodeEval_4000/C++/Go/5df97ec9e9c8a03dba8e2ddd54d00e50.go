package main

import (
	"fmt"
)

const MAXSIZE = 300000000/2/8 + 1

var p [MAXSIZE]byte

var block = [...]int{
