package main

import (
	"fmt"
)

type MCMF_CS2 struct {
	n, m int
	cap  []int
	nodes []Node
	arcs  []Arc
}

type Node struct {
	excess int
	price  int
	first  *Arc
	current *Arc
	suspended *Arc
	qNext *Node
	bNext *Node
	bPrev *Node
	rank int
	inp int
}

type Arc struct {
	rezCapacity int
	cost int
	head *Node
	sister *Arc
}

func NewMCMF_CS2(numNodes, numArcs int) *MCMF_CS2 {
	return &MCMF_CS2{
		n:     numNodes,
		m:     numArcs,
		cap:   make([]int, numArcs),
		nodes: make([]Node, numNodes+2),
		arcs:  make([]Arc, 2*numArcs+1),
	}
}

func (m *MCMF_CS2) SetArc(tailNodeID, headNodeID, lowBound, upBound, cost int) {
	m.nodes[tailNodeID].first--
	m.nodes[headNodeID].first--
	m.arcs[m.nodes[tailNodeID].first].head = &m.nodes[headNodeID]
	m.arcs[m.nodes[tailNodeID].first].rezCapacity = upBound - lowBound
	m.cap[m.nodes[tailNodeID].first] = upBound
	m.arcs[m.nodes[tailNodeID].first].cost = cost
	m.arcs[m.nodes[tailNodeID].first].sister = &m.arcs[m.nodes[headNodeID].first+1]
	m.arcs[m.nodes[headNodeID].first+1].head = &m.nodes[tailNodeID]
	m.arcs[m.nodes[headNodeID].first+1].rezCapacity = 0
	m.cap[m.nodes[headNodeID].first+1] = 0
	m.arcs[m.nodes[headNodeID].first+1].cost = -cost
	m.arcs[m.nodes[headNodeID].first+1].sister = &m.arcs[m.nodes[tailNodeID].first]
	m.nodes[tailNodeID].excess -= lowBound
	m.nodes[headNodeID].excess += lowBound
}

func (m *MCMF_CS2) SetSupplyDemandOfNode(id, excess int) {
	m.nodes[id].excess = excess
}

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	grid := make([][]int, n)
	for i := 0; i < n; i++ {
		grid[i] = make([]int, m)
		for j := 0; j < m; j++ {
			fmt.Scan(&grid[i][j])
		}
	}
	a, b, c := make([]int, 0), make([]int, 0), make([]int, 0)
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 == 1 {
				if i > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i-1, j))
					c = append(c, grid[i][j] != grid[i-1][j])
				}
				if j > 0 {
					a = append(a, f(i, j))
					b = append(b, f(i, j-1))
					c = append(c, grid[i][j] != grid[i][j-1])
				}
				if i+1 < n {
					a = append(a, f(i, j))
					b = append(b, f(i+1, j))
					c = append(c, grid[i][j] != grid[i+1][j])
				}
				if j+1 < m {
					a = append(a, f(i, j))
					b = append(b, f(i, j+1))
					c = append(c, grid[i][j] != grid[i][j+1])
				}
			}
		}
	}
	numNodes := n * m * 4
	numArcs := len(a)
	myMCMFProblem := NewMCMF_CS2(numNodes, numArcs)
	for i := 0; i < numArcs; i++ {
		myMCMFProblem.SetArc(a[i], b[i], 0, 1, c[i])
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if (i+j)%2 == 1 {
				myMCMFProblem.SetSupplyDemandOfNode(f(i, j), 1)
			} else {
				myMCMFProblem.SetSupplyDemandOfNode(f(i, j), -1)
			}
		}
	}
	myMCMFProblem.RunCS2()
}

func f(r, c int) int {
	return r*m + c + 1
}
