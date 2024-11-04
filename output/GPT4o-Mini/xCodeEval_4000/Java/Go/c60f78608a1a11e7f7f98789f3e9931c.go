package main

import (
	"bufio"
	"fmt"
	"math/big"
	"sort"
	"strconv"
	"strings"
)

const BIG = 1000000007

type Point struct {
	index int
	x     int
	y     int
}

func (p Point) GetX() int {
	return p.x
}

func (p Point) GetY() int {
	return p.y
}

type SortedSetAVL struct {
	points []Point
}

func NewSortedSetAVL() *SortedSetAVL {
	return &SortedSetAVL{points: []Point{}}
}

func (s *SortedSetAVL) Add(p Point) {
	s.points = append(s.points, p)
	sort.Slice(s.points, func(i, j int) bool {
		if s.points[i].x == s.points[j].x {
			return s.points[i].y < s.points[j].y
		}
		return s.points[i].x < s.points[j].x
	})
}

func (s *SortedSetAVL) Contains(p Point) bool {
	for _, point := range s.points {
