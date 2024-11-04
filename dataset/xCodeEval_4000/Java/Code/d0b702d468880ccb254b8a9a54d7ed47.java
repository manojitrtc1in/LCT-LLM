import java.io.*;
import java.util.*;



public class ESubmit {
    int n, m, q;
    int[] ss, ff, first, next, qs, qe;

    boolean[] on_cycle;
    int[] parent;
    int cycle_vertex = -1;

    void dfs(int p, int v) {
	if(parent[v]>=0) {
	    if (cycle_vertex == -1) {
		cycle_vertex = v;
		parent[v] = p;
	    }
	    return;
	}
	parent[v] = p;
	for (int e = first[v]; e>=0; e = next[e]) {
	    int w = ff[e];
	    if (w==p) continue;
	    dfs(v,w);
	}
    }

    void treedfs(int p, int v) {
	parent[v] = p;
	for (int e = first[v]; e>=0; e = next[e]) {
	    int w = ff[e];
	    if (w==p || on_cycle[w]) continue;
	    treedfs(v,w);
	}
    }
    
    public void read_input_and_solve() throws IOException, MyException {
	m = n = nextInt();
	q = nextInt();

	

	ss = new int[2*m];  
	ff = new int[2*m];  
	qs = new int[q];
	qe = new int[q];

	first = new int[n];   
	next = new int[2*m];  
	Arrays.fill(first, -1);

	for (int i=0; i<m; i++) {
	    ss[i] = ff[i+m] = nextInt()-1;
	    ff[i] = ss[i+m] = nextInt()-1;
	}
	for (int i=0; i<2*m; i++) {
	    next[i] = first[ss[i]];
	    first[ss[i]] = i;
	}
	


	for (int i=0; i<q; i++) {
	    qs[i] = nextInt()-1;
	    qe[i] = nextInt()-1;	    
	}
	


	parent = new int[n];
	Arrays.fill(parent, -1);
	on_cycle = new boolean[n];
	int nc=0;  

	
	dfs(n,0);
	if (cycle_vertex < 0) throw new MyException ("no cycle");
	for (int v = parent[cycle_vertex]; true; v = parent[v]) {
	    on_cycle[v] = true;
	    nc++;
	    if (v==cycle_vertex) break;
	}

	int[] nodemap = new int[n];
	    


	Node[] cyclenodes = new Node[nc];
	for (int i=0, v = parent[cycle_vertex]; true; v = parent[v], i++) {
	    cyclenodes[i] = new Node(1, v);
	    if (i>0) LinkCut.link(cyclenodes[i-1], cyclenodes[i]);
	    nodemap[v] = i;
	    if (v==cycle_vertex) break;
	}

	Arrays.fill(parent, -1);
	for (int v=0; v<n; v++) if (on_cycle[v]) treedfs(-1,v);

	Node[] treenodes = new Node[n];
	for (int i=0; i<n; i++)
	    treenodes[i] = new Node((on_cycle[i])?0:1, i);
	for (int i=0; i<n; i++)
	    if (!on_cycle[i]) LinkCut.link(treenodes[i], treenodes[parent[i]]);

	int cycle_edges = 0;
	int tree_edges = 0;
	for (int i=0; i<q; i++) {
	    tree_edges += LinkCut.toggle(treenodes[qs[i]]);
	    int place1 = nodemap[LinkCut.rootid(treenodes[qs[i]])];
	    tree_edges += LinkCut.toggle(treenodes[qe[i]]);
	    int place2 = nodemap[LinkCut.rootid(treenodes[qe[i]])];

	    

	    

	    boolean path_right;
	    int right_length = (place2-place1+nc) % nc;
	    if (2*right_length < nc) path_right = true;
	    else if (2*right_length > nc) path_right = false;
	    else {
		int nf = (place1 + 1) % nc;
		int nb = (place1 - 1 + nc) % nc;
		int idf = cyclenodes[nf].id;
		int idb = cyclenodes[nb].id;
		path_right = (idf < idb);
	    }
	    cycle_edges += LinkCut.toggle(cyclenodes[place1]);
	    cycle_edges += LinkCut.toggle(cyclenodes[place2]);
	    if (path_right) {
		if (place1 > place2) cycle_edges += LinkCut.toggle(cyclenodes[0]);
	    } else {
		if (place1 < place2) cycle_edges += LinkCut.toggle(cyclenodes[0]);
	    }
	    int components = n - tree_edges - cycle_edges;
	    if (cycle_edges == nc) components++;
	    System.out.println(components);
	}
    }

    
    public static void main(String[] args) {
	(new ESubmit()).run();
    }
    
    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;
    
    public void run() {
	try {
	    reader = new BufferedReader(new InputStreamReader(System.in));
	    tokenizer = null;
	    writer = new PrintWriter(System.out);
	    read_input_and_solve();
	    reader.close();
	    writer.close();
	} catch (Exception e) {
	    e.printStackTrace();
	    System.exit(1);
	}
    }
    
    int nextInt() throws IOException {
	return Integer.parseInt(nextToken());
    }
    
    long nextLong() throws IOException {
	return Long.parseLong(nextToken());
    }
    
    double nextDouble() throws IOException {
	return Double.parseDouble(nextToken());
    }
    
    String nextToken() throws IOException {
	while (tokenizer == null || !tokenizer.hasMoreTokens()) {
	    tokenizer = new StringTokenizer(reader.readLine());
	}
	return tokenizer.nextToken();
    }
}

class MyException extends Exception {
    public String s;
    public MyException(String prob) {
	super(prob);
	s = prob;
    }
}




class Node {
    int s, my_s, on, id;
    boolean flip, my_flip;
    Node l, r, p;

    Node (int c, int i) {
	id = i;
	s = my_s = c;
	on = 0;
	l = r = p = null;
	flip = my_flip = false;
    }

    boolean isroot() {
	return p==null || (p.l != this && p.r != this);
    }

    
    void normalize() {
	if (flip) {
	    flip = false;
	    on = s-on;
	    my_flip = !my_flip;
	    if (l != null) l.flip = !l.flip;
	    if (r != null) r.flip = !r.flip;
	}
    }

    
    void update() {
	s = my_s;
	on = (my_flip)?my_s:0;
	if (l != null) {
	    s += l.s;
	    if (l.flip) on += l.s-l.on; else on += l.on;
	}
	if (r != null) {
	    s += r.s;
	    if (r.flip) on += r.s-r.on; else on += r.on;
	}
    }
}

class LinkCut {
    static void rotR (Node p) {
	Node q = p.p;
	Node r = q.p;
	q.normalize();
	p.normalize();
	if ((q.l=p.r) != null) q.l.p = q;
	p.r = q;
	q.p = p;
	if ((p.p=r) != null) {
	    if (r.l == q) r.l = p;
	    else if (r.r == q) r.r = p;
	}
	q.update();
    }

    static void rotL (Node p) {
	Node q = p.p;
	Node r = q.p;
	q.normalize();
	p.normalize();
	if ((q.r=p.l) != null) q.r.p = q;
	p.l = q;
	q.p = p;
	if ((p.p=r) != null) {
	    if (r.l == q) r.l = p;
	    else if (r.r == q) r.r = p;
	}
	q.update();
    }

    static void splay(Node p) {
	while (!p.isroot()) {
	    Node q = p.p;
	    if (q.isroot()) {
		if (q.l == p) rotR(p); else rotL(p);
	    } else {
		Node r = q.p;
		if (r.l == q) {
		    if (q.l == p) {rotR(q); rotR(p);}
		    else {rotL(p); rotR(p);}
		} else {
		    if (q.r == p) {rotL(q); rotL(p);}
		    else {rotR(p); rotL(p);}
		}
	    }
	}
	p.normalize(); 

	p.update();    

    }

    
    static void expose(Node q) {
	Node r = null;
	for (Node p=q; p != null; p=p.p) {
	    splay(p);
	    p.l = r;
	    p.update();
	    r = p;
	};
	splay(q);
    }

     
    static void link(Node p, Node q) throws MyException {
	expose(p);
	if (p.r != null) throw new MyException("non-root link"); 
	p.p = q;
    }

    
    static int toggle(Node p) {
	expose(p);
	int before = p.on;
	p.flip = !p.flip;
	p.normalize();
	int after = p.on;
	return after - before;
    }

    
    static int rootid(Node p) {
	expose(p);
	while(p.r != null) p = p.r;
	splay(p);
	return p.id;
    }
}