



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































package main

import (
	"bufio"
	"fmt"
	"os"
)



type Edge struct {
	From  Vertex
	To    Vertex
	Value Rel 

}
type Vertex struct {
	Value interface{}
}
var cost []int64
type Rel string
type DirectedGraph struct {
	Outs map[Vertex]map[Vertex][]Rel
	Ins  map[Vertex][]Vertex
}



func (g *DirectedGraph) Vertices() []Vertex {
	vertices := []Vertex{}

	for key := range g.Outs {
		vertices = append(vertices, key)
	}
	return vertices
	
}



func (g *DirectedGraph) In(v Vertex) []Vertex {
	_, ok := g.Ins[v]
	if !ok {
		return []Vertex{}
	} else {
		return g.Ins[v]
	}
}



func (g *DirectedGraph) Out(v Vertex) []Vertex {
	_, ok := g.Outs[v]
	if !ok {
		return []Vertex{}
	}

	vertices := []Vertex{}

	for key := range g.Outs[v] {
		vertices = append(vertices, key)
	}
	return vertices
}



func (g *DirectedGraph) Edges(a, b Vertex) []Edge {
	_, oka := g.Outs[a]
	_, okb := g.Ins[b]
	if !oka || !okb {
		return nil
	}

	_, ok := g.Outs[a][b]
	if !ok {
		return nil
	}

	edges := []Edge{}
	for _, rel := range g.Outs[a][b] {
		edges = append(edges, Edge{
			From:  a,
			To:    b,
			Value: rel,
		})
	}
	return edges
}



func (g *DirectedGraph) Link(v Vertex, succ Vertex, rel Rel) {
	_, ok := g.Outs[v]
	if !ok {
		g.Outs[v] = make(map[Vertex][]Rel)
	}
	_, ok = g.Outs[succ]
	if !ok {
		g.Outs[succ] = make(map[Vertex][]Rel)
	}

	_, ok = g.Ins[v]
	if !ok {
		g.Ins[v] = []Vertex{}
	}
	_, ok = g.Ins[succ]
	if !ok {
		g.Ins[succ] = []Vertex{}
	}

	haveRel := false
	for _, item := range g.Outs[v][succ] {
		if item == rel {
			haveRel = true
			break
		}
	}
	if haveRel == false {
		g.Outs[v][succ] = append(g.Outs[v][succ], rel)
	}

	

	if _, ok:= g.Outs[v][succ] ; ok ==false{
		g.Ins[succ] = append(g.Ins[succ], v)
	}
}



func (g *DirectedGraph) LinkToAll(x Vertex, ys []Vertex, rel Rel) {
	for _, y := range ys {
		g.Link(x, y, rel)
	}
}



func (g *DirectedGraph) LinkAllTo(xs []Vertex, y Vertex, rel Rel) {
	for _, x := range xs {
		g.Link(x, y, rel)
	}
}

func (g *DirectedGraph) UnLink(a, b Vertex) {
	delete(g.Outs[a], b)
	

	for id , vertex := range g.Ins[b] {
		if vertex == a {
			g.Ins[b] = append(g.Ins[b][:id], g.Ins[b][id+1:]...)
			break
		}
	}
	
}



func (g *DirectedGraph) Fork() *DirectedGraph {
	return g
	

	

}


func IntersectionRel(rels1 []Rel,rels2 []Rel) []Rel{
	rel := []Rel{}
	for _, rel1 := range rels1 {
		both := false
		for _, rel2 := range rels2{
			if rel1 == rel2 {
				both = true
				break
			}
		}
		if both == true {
			rel = append(rel, rel1)
		}
	}
	return rel
}



func (g *DirectedGraph) ProjectRelationship(rel Rel) *DirectedGraph {
	fg := g.Fork()

	vertices := fg.Vertices()
	for _, x := range vertices {
		_, ok := g.Outs[x]
		if ok == true {
			for y, _:= range g.Outs[x] {
				rels := IntersectionRel(g.Outs[x][y], []Rel{rel})
				fg.UnLink(x, y)
				for _, item := range rels {
					fg.Link(x, y, item)
				}
			}
		}
	}

	return fg
}





func (g *DirectedGraph) FilterRelationships(rels []Rel) *DirectedGraph {
	fg := g.Fork()

	vertices := fg.Vertices()
	for _, x := range vertices {
		_, ok := g.Outs[x]
		if ok == true {
			for y, _:= range g.Outs[x] {
				rels := IntersectionRel(g.Outs[x][y], rels)
				fg.UnLink(x, y)
				for _, item := range rels {
					fg.Link(x, y, item)
				}
			}
		}
	}

	return fg
}





func (g *DirectedGraph) BfsOut(initV []Vertex) []Vertex {
	queue := initV
	V := []Vertex{}
	haveVisited := make(map[Vertex]bool)
	for _, vertex := range initV {
		haveVisited[vertex] = true
		V = append(V, vertex)
	}

	for len(queue) > 0 {
		cur := queue[0]
		if haveVisited[cur] == false {
			haveVisited[cur] = true
			V = append(V, cur)
		}
		queue = queue[1:]

		for next, _ := range g.Outs[cur] {
			if haveVisited[next] == true {
				continue
			}
			queue = append(queue, next)
		}
	}
	return V
}





func (g *DirectedGraph) BfsIn(initV []Vertex) []Vertex {
	queue := initV
	V := []Vertex{}
	haveVisited := make(map[Vertex]bool)
	for _, vertex := range initV {
		haveVisited[vertex] = true
		V = append(V, vertex)
	}

	for len(queue) > 0 {
		cur := queue[0]
		if haveVisited[cur] == false {
			haveVisited[cur] = true
			V = append(V, cur)
		}
		queue = queue[1:]

		for _, next := range g.Ins[cur] {
			if haveVisited[next] == true {
				continue
			}
			queue = append(queue, next)
		}
	}
	return V
}







func (g *DirectedGraph) Bfs(initV []Vertex, out bool) []Vertex {
	if out == true {
		return g.BfsOut(initV)
	} else {
		return g.BfsIn(initV)
	}
}



type SCC struct {
	Vertices []Vertex
}



func (g *DirectedGraph) StronglyConnectedComponents() []SCC {
	dfn := make(map[Vertex]int)
	low := make(map[Vertex]int)
	cnt := 0
	belong := make(map[Vertex]int)
	in := make(map[Vertex]bool)
	tag := make(map[Vertex]map[Vertex]bool)
	s2 := []Vertex{}
	vertices := g.Vertices()
	index := 0
	for _, v := range vertices {
		if dfn[v] == 0 {
			s1 := []Vertex{v}
			

			for len(s1) > 0 {
				x := s1[len(s1)-1]
				s1 = s1[:len(s1)-1]
				if dfn[x] == 0 {
					index = index + 1
					dfn[x] = index
					low[x] = index
					s2 = append(s2, x)
					in[x] = true;
				}
				finish := true
				for next, _ := range g.Outs[x] {
					

					if dfn[next] == 0 {
						s1 = append(s1, x)
						s1 = append(s1, next)
						_, ok := tag[x]
						if !ok {
							tag[x] = make(map[Vertex]bool)
						}
						tag[x][next] = true
						finish = false
						break
					} else {
						if in[next] == true {
							if low[x] > dfn[next] {
								low[x] = dfn[next]
							}
						}
					}
				}
				if finish == true {
					

					for next, _ := range g.Outs[x] {
						_, ok := tag[x]
						if !ok {
							tag[x] = make(map[Vertex]bool)
						}
						if tag[x][next] == true {
							if low[x] > low[next] {
								low[x] = low[next]
							}
						}
					}
					

					if low[x] == dfn[x] {
						var t Vertex
						cnt = cnt + 1
						for {
							t = s2[len(s2)-1]
							s2 = s2[:len(s2)-1]
							in[t] = false
							belong[t] = cnt;
							if t == x {
								break
							}
						}
					}
				}
			}
		}
	}
	


	minc:=make(map[int]int64)
	nway:=make(map[int]int64)

	var sum,sumn int64
	sum=0
	sumn=1

	
	scc := make([]SCC, cnt)
	for i := 1; i <= cnt; i++ {
		minc[i]=2147483647
	}



	for _, v := range vertices {
		
		id := belong[v]
		scc[id-1].Vertices = append(scc[id-1].Vertices, v)
		if cost[v.Value.(int)]<minc[id] {
			minc[id]=cost[v.Value.(int)];
			nway[id]=1;
		} else {
			if cost[v.Value.(int)] == minc[id] {
				nway[id]++;
			}
		}
	}
	for i := 1; i <= cnt; i++ {
				sum+=minc[i];
				sumn=(sumn*nway[i])%1000000007;
			}
	fmt.Println(sum,sumn)

	return scc
}





func (g *DirectedGraph) MapVertices(f func(interface{}) interface{}) *DirectedGraph {
	

	fg := id0()

	vertices := g.Vertices()
	for _, x := range vertices {
		_, ok := g.Outs[x]
		if ok == true {
			for y, _:= range g.Outs[x] {
				rels := g.Outs[x][y]
				for _, item := range rels {
					fg.Link(Vertex{f(x.Value)}, Vertex{f(y.Value)}, item)
				}
			}
		}
	}

	return fg
}

var id1 = map[string]string{
	"consistent-view":         "PL-2+",
	"conflict-serializable":   "PL-3",
	"cursor-stability":        "PL-CS",
	"forward-consistent-view": "PL-FCV",
	"monotonic-snapshot-read": "PL-MSR",
	"monotonic-view":          "PL-2L",
	"read-committed":          "PL-2",
	"read-uncommitted":        "PL-1",
	"repeatable-read":         "PL-2.99",
	"serializable":            "PL-3",
	"snapshot-isolation":      "PL-SI",
	"strict-serializable":     "PL-SS",
	"update-serializable":     "PL-3U",
	"0": "A",
	"1": "B",
	"2": "C",
}



func id2(name interface{}) interface{} {
	if cname, ok := id1[name.(string)]; ok {
		return cname
	}
	return name
}



func id0() *DirectedGraph {
	var g DirectedGraph
	g.Ins = make(map[Vertex][]Vertex)
	g.Outs = make(map[Vertex]map[Vertex][]Rel)
	return &g
}







func (g *DirectedGraph) RenumberGraph() (*DirectedGraph, func(interface{}) interface{}) {
	dg := id0()
	ref := make(map[Vertex]int)
	numberToVertices := make(map[interface{}]interface{})
	vertices := g.Vertices()

	for id, v := range vertices {
		ref[v] = id
		numberToVertices[id] = v.Value
	}

	for _, x := range vertices {
		for y, rels := range g.Outs[x] {
			for _, rel := range rels{
				dg.Link(Vertex{ref[x]}, Vertex{ref[y]}, rel)
			}
		}
	}

	return dg, func(number interface{}) interface{} {
		return numberToVertices[number]
	}
}

func (g *DirectedGraph) scctest() [][]int {
	dfn := make(map[Vertex]int)
	low := make(map[Vertex]int)
	cnt := 0
	belong := make(map[Vertex]int)
	in := make(map[Vertex]bool)
	tag := make(map[Vertex]map[Vertex]bool)
	s2 := []Vertex{}
	vertices := g.Vertices()
	ans := [][]int{}
	father := make(map[Vertex]Vertex)
	vv := Vertex{-1}
	index := 0
	for _, v := range vertices {
		if dfn[v] == 0 {
			s1 := []Vertex{v}
			father[v] = vv
			for len(s1) > 0 {
				x := s1[len(s1)-1]
				s1 = s1[:len(s1)-1]
				if dfn[x] == 0 {
					index = index + 1
					dfn[x] = index
					low[x] = index
					s2 = append(s2, x)
					in[x] = true;
				}
				finish := true
				for next, _ := range g.Outs[x] {
					if dfn[next] == 0 {
						s1 = append(s1, x)
						s1 = append(s1, next)
						father[next]=x
						_, ok := tag[x]
						if !ok {
							tag[x] = make(map[Vertex]bool)
						}
						tag[x][next] = true
						finish = false
						break
					} else {
						if in[next] == true {
							if low[x] > dfn[next] {
								low[x] = dfn[next]
								

								

							}
						}
					}
				}
				if finish == true {
					for next, _ := range g.Outs[x] {
						_, ok := tag[x]
						if !ok {
							tag[x] = make(map[Vertex]bool)
						}
						if tag[x][next] == true {
							if low[x] > low[next] {
								low[x] = low[next]
								

								

							}
						}
					}
					if low[x] == dfn[x] {
						var t Vertex
						cnt = cnt + 1
						for {
							t = s2[len(s2)-1]
							s2 = s2[:len(s2)-1]
							in[t] = false
							belong[t] = cnt;
							if t == x {
								break
							}
						}
					}
				}
			}
		}
	}
	for i := 1; i <= cnt; i++ {
		ts := SCC{
			Vertices: []Vertex{},
		}
		for _, v := range vertices {
			if belong[v] == i {
				ts.Vertices = append(ts.Vertices, v)
			}
		}
		

	}

	
	for _, i:= range vertices{
		v:= father[i]
		

		if v != vv {
			fmt.Println(low[i]," ",dfn[v])
			

		}
	}

	return ans
}


func criticalConnections(n int, connections [][]int) [][]int {
	g := id0()
	for _, b := range connections{
		g.Link(Vertex{b[0]},Vertex{b[1]},"")
		g.Link(Vertex{b[1]},Vertex{b[0]},"")
	}

	return g.scctest()
}

func main () {
	
	

	



	

	


	
	var n int
	var m int
	in := bufio.NewReader(os.Stdin)

	fmt.Fscan(in, &n)
	

	cost = make([]int64, n+5)
	g := id0()
	for i:=1 ; i<=n; i++ {
		fmt.Fscan(in, &cost[i])

		_, ok := g.Outs[Vertex{i}]
		if !ok {
			g.Outs[Vertex{i}] = make(map[Vertex][]Rel)
		}
		_, ok = g.Ins[Vertex{i}]
		if !ok {
			g.Ins[Vertex{i}] = []Vertex{}
		}

	}
	fmt.Fscan(in, &m)
	var a,b int
	for i:=1 ; i<=m; i++ {
		fmt.Fscan(in, &a)
		fmt.Fscan(in, &b)
		g.Link(Vertex{a}, Vertex{b}, "")
	}
	g.StronglyConnectedComponents()
}