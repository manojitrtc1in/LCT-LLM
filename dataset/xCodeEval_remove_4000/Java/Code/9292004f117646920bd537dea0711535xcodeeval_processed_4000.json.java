

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		id0 trie = new id0();
		for(int i = 0;i < n;i++){
			trie.add(ns().toCharArray());
		}
		id0.Node[] nodes = trie.toArray();
		
		int m = nodes.length;
		int[][] ch = new int[m][];
		int[] nl = new int[m];
		for(int i = 0;i < m;i++){
			ch[i] = new int[nodes[i].p];
			nl[i] = nodes[i].hit;
			for(int j = 0;j < ch[i].length;j++){
				ch[i][j] = nodes[i].child[j].id;
			}
		}
		
		long ans = 0;
		for(int e : ch[0]){
			Node res = dfs(e, ch, nl, 1);
			ans += sum(res);
		}
		out.println(ans);
	}
	
	long sum(Node a)
	{
		if(a == null)return 0;
		return a.v + sum(a.left) + sum(a.right);
	}
	
	Node dfs(int cur, int[][] ch, int[] nl, int dep)
	{
		Node my = nl[cur] == 1 ? new Node(dep) : null;
		for(int e : ch[cur]){
			Node res = dfs(e, ch, nl, dep+1);
			my = id2(my, res);
		}
		
		if(nl[cur] == 0){
			Node[] sp = split(my, count(my)-1);
			sp[1].v = dep;
			my = merge(sp[1], sp[0]);
		}
		return my;
	}
	
	public static Random gen = new Random();
	
	static public class Node
	{
		public int v; 

		public long priority;
		public Node left, right, parent;
		
		public int count;
		
		public Node(int v)
		{
			this.v = v;
			priority = gen.nextLong();
			update(this);
		}

		@Override
		public String toString() {
			StringBuilder builder = new StringBuilder();
			builder.append("Node [v=");
			builder.append(v);
			builder.append(", count=");
			builder.append(count);
			builder.append(", parent=");
			builder.append(parent != null ? parent.v : "null");
			builder.append("]");
			return builder.toString();
		}
	}

	public static Node update(Node a)
	{
		if(a == null)return null;
		a.count = 1;
		if(a.left != null)a.count += a.left.count;
		if(a.right != null)a.count += a.right.count;
		
		

		return a;
	}
	
	public static void propagate(Node x)
	{
		for(;x != null;x = x.parent)update(x);
	}
	
	public static Node disconnect(Node a)
	{
		if(a == null)return null;
		a.left = a.right = a.parent = null;
		return update(a);
	}
	
	public static Node root(Node x)
	{
		if(x == null)return null;
		while(x.parent != null)x = x.parent;
		return x;
	}
	
	public static int count(Node a)
	{
		return a == null ? 0 : a.count;
	}
	
	public static void setParent(Node a, Node par)
	{
		if(a != null)a.parent = par;
	}
	
	public static Node merge(Node a, Node b, Node... c)
	{
		Node x = merge(a, b);
		for(Node n : c)x = merge(x, n);
		return x;
	}
	
	public static Node merge(Node a, Node b)
	{
		if(b == null)return a;
		if(a == null)return b;
		if(a.priority > b.priority){
			setParent(a.right, null);
			setParent(b, null);
			a.right = merge(a.right, b);
			setParent(a.right, a);
			return update(a);
		}else{
			setParent(a, null);
			setParent(b.left, null);
			b.left = merge(a, b.left);
			setParent(b.left, b);
			return update(b);
		}
	}
	
	public static Node[] split(Node x)
	{
		if(x == null)return new Node[]{null, null};
		if(x.left != null)x.left.parent = null;
		Node[] sp = new Node[]{x.left, x};
		x.left = null;
		update(x);
		while(x.parent != null){
			Node p = x.parent;
			x.parent = null;
			if(x == p.left){
				p.left = sp[1];
				if(sp[1] != null)sp[1].parent = p;
				sp[1] = p;
			}else{
				p.right = sp[0];
				if(sp[0] != null)sp[0].parent = p;
				sp[0] = p;
			}
			update(p);
			x = p;
		}
		return sp;
	}
	
	public static Node[] split(Node a, int... ks)
	{
		int n = ks.length;
		if(n == 0)return new Node[]{a};
		for(int i = 0;i < n-1;i++){
			if(ks[i] > ks[i+1])throw new IllegalArgumentException(Arrays.toString(ks));
		}
		
		Node[] ns = new Node[n+1];
		Node cur = a;
		for(int i = n-1;i >= 0;i--){
			Node[] sp = split(cur, ks[i]);
			cur = sp[0];
			ns[i] = sp[0];
			ns[i+1] = sp[1];
		}
		return ns;
	}
	
	

	public static Node[] split(Node a, int K)
	{
		if(a == null)return new Node[]{null, null};
		if(K <= count(a.left)){
			setParent(a.left, null);
			Node[] s = split(a.left, K);
			a.left = s[1];
			setParent(a.left, a);
			s[1] = update(a);
			return s;
		}else{
			setParent(a.right, null);
			Node[] s = split(a.right, K-count(a.left)-1);
			a.right = s[0];
			setParent(a.right, a);
			s[0] = update(a);
			return s;
		}
	}
	
	public static Node insertb(Node root, Node x)
	{
		int ind = lowerBound(root, x.v);
		return insert(root, ind, x);
	}
	
	public static Node insert(Node a, int K, Node b)
	{
		if(a == null)return b;
		if(b.priority < a.priority){
			if(K <= count(a.left)){
				a.left = insert(a.left, K, b);
				setParent(a.left, a);
			}else{
				a.right = insert(a.right, K-count(a.left)-1, b);
				setParent(a.right, a);
			}
			return update(a);
		}else{
			Node[] ch = split(a, K);
			b.left = ch[0]; b.right = ch[1];
			setParent(b.left, b);
			setParent(b.right, b);
			return update(b);
		}
	}
	
	

	public static Node erase(Node a, int K)
	{
		if(a == null)return null;
		if(K < count(a.left)){
			a.left = erase(a.left, K);
			setParent(a.left, a);
			return update(a);
		}else if(K == count(a.left)){
			setParent(a.left, null);
			setParent(a.right, null);
			Node aa = merge(a.left, a.right);
			disconnect(a);
			return aa;
		}else{
			a.right = erase(a.right, K-count(a.left)-1);
			setParent(a.right, a);
			return update(a);
		}
	}
	
	public static Node get(Node a, int K)
	{
		while(a != null){
			if(K < count(a.left)){
				a = a.left;
			}else if(K == count(a.left)){
				break;
			}else{
				K = K - count(a.left)-1;
				a = a.right;
			}
		}
		return a;
	}
	
	public static int index(Node a)
	{
		if(a == null)return -1;
		int ind = count(a.left);
		while(a != null){
			Node par = a.parent;
			if(par != null && par.right == a){
				ind += count(par.left) + 1;
			}
			a = par;
		}
		return ind;
	}
	
	public static Node id2(Node x, Node y)
	{
		if(x == null)return y;
		if(y == null)return x;
		if(count(x) > count(y)){
			Node d = x; x = y; y = d;
		}
		

		for(Node cur : nodesdfs(x))y = insertb(y, disconnect(cur));
		return y;
	}
	
	public static int lowerBound(Node a, int q)
	{
		int lcount = 0;
		while(a != null){
			if(a.v >= q){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return lcount;
	}
	
	public static int search(Node a, int q)
	{
		int lcount = 0;
		while(a != null){
			if(a.v == q){
				lcount += count(a.left);
				break;
			}
			if(q < a.v){
				a = a.left;
			}else{
				lcount += count(a.left) + 1;
				a = a.right;
			}
		}
		return a == null ? -(lcount+1) : lcount;
	}
	
	public static Node next(Node x)
	{
		if(x == null)return null;
		if(x.right != null){
			x = x.right;
			while(x.left != null)x = x.left;
			return x;
		}else{
			while(true){
				Node p = x.parent;
				if(p == null)return null;
				if(p.left == x)return p;
				x = p;
			}
		}
	}
	
	public static Node prev(Node x)
	{
		if(x == null)return null;
		if(x.left != null){
			x = x.left;
			while(x.right != null)x = x.right;
			return x;
		}else{
			while(true){
				Node p = x.parent;
				if(p == null)return null;
				if(p.right == x)return p;
				x = p;
			}
		}
	}
	
	public static Node build(int[] a, int l, int r)
	{
		if(l >= r)return null;
		
		int h = l+r>>1;
		Node root = new Node(a[h]);
		
		Node L = build(a, l, h);
		root.left = L;
		if(L != null)L.parent = root;
		
		Node R = build(a, h+1, r);
		root.right = R;
		if(R != null)R.parent = root;
		
		return update(root);
	}
	
	
	public static Node[] nodes(Node a) { return nodes(a, new Node[count(a)], 0, count(a)); }
	public static Node[] nodes(Node a, Node[] ns, int L, int R)
	{
		if(a == null)return ns;
		nodes(a.left, ns, L, L+count(a.left));
		ns[L+count(a.left)] = a;
		nodes(a.right, ns, R-count(a.right), R);
		return ns;
	}
	
	

	public static Node[] nodesdfs(Node a) { return nodesdfs(a, new Node[a.count], new int[]{0}); }
	public static Node[] nodesdfs(Node a, Node[] ns, int[] pos)
	{
		if(a == null)return ns;
		ns[pos[0]++] = a;
		nodesdfs(a.left, ns, pos);
		nodesdfs(a.right, ns, pos);
		return ns;
	}
	
	public static String toString(Node a, String indent)
	{
		if(a == null)return "";
		StringBuilder sb = new StringBuilder();
		sb.append(toString(a.left, indent + "  "));
		sb.append(indent).append(a).append("\n");
		sb.append(toString(a.right, indent + "  "));
		return sb.toString();
	}
	
	public static class id0 {
		public Node root = new Node((char)0, 0);
		public int gen = 1;
		
		public static class Node
		{
			public int id;
			public char c;
			
			public long ptn = 0;
			public int p = 0;
			public Node[] child = null;
			public int hit = 0;
			
			public Node fail;
			
			public Node(char c, int id)
			{
				this.id = id;
				this.c = c;
			}
			
			public int enc(char c)
			{


				return c-'a';
			}
			
			public void appendChild(Node n)
			{
				if(p == 0){
					child = new Node[1];
				}else if(p+1 >= child.length){
					child = Arrays.copyOf(child, child.length*2);
				}
				int z = enc(n.c);
				int nind = Long.bitCount(ptn<<~z);
				ptn |= 1L<<z;
				System.arraycopy(child, nind, child, nind+1, p-nind);
				child[nind] = n;
				p++;
			}
			
			public Node search(char c)
			{
				if(ptn<<~enc(c)<0){
					return child[Long.bitCount(ptn<<~enc(c))-1];
				}else{
					return null;
				}
			}
			
			public String toString(String indent)
			{
				StringBuilder sb = new StringBuilder();
				sb.append(indent + id + ":" + c);
				if(hit != 0)sb.append(" H:" + hit);
				if(fail != null)sb.append(" F:" + fail.id);
				sb.append("\n");
				for(int i = 0;i < p;i++){
					sb.append(child[i].toString(indent + "  "));
				}
				return sb.toString();
			}
		}
		
		public void add(char[] s)
		{
			Node cur = root;
			Node pre = null;
			for(char c : s){
				pre = cur;
				cur = pre.search(c);
				if(cur == null){
					cur = new Node(c, gen++);
					pre.appendChild(cur);
				}
			}
			cur.hit++;
		}
		
		public void buildFailure()
		{
			root.fail = null;
			Queue<Node> q = new ArrayDeque<Node>();
			q.add(root);
			while(!q.isEmpty()){
				Node cur = q.poll();
				inner:
				for(int i = 0;i < cur.p;i++){
					Node ch = cur.child[i];
					q.add(ch);
					for(Node to = cur.fail; to != null; to = to.fail){
						Node lch = to.search(ch.c);
						if(lch != null){
							ch.fail = lch;
							ch.hit += lch.hit; 

							continue inner;
						}
					}
					ch.fail = root;
				}
			}
		}
		
		public Node next(Node cur, char c)
		{
			for(;cur != null;cur = cur.fail){
				Node next = cur.search(c);
				if(next != null){
					return next;
				}
				

			}
			return root;
		}
		
		public int countHit(char[] q)
		{
			Node cur = root;
			int hit = 0;
			outer:
			for(char c : q){
				for(;cur != null;cur = cur.fail){
					Node next = cur.search(c);
					if(next != null){
						hit += next.hit;
						cur = next;
						continue outer;
					}
				}
				cur = root;
			}
			return hit;
		}
		
		public Node[] toArray()
		{
			Node[] ret = new Node[gen];
			ret[0] = root;
			for(int i = 0;i < gen;i++){
				Node cur = ret[i];
				for(int j = 0;j < cur.p;j++){
					ret[cur.child[j].id] = cur.child[j];
				}
			}
			return ret;
		}
		
		public String toString()
		{
			return root.toString("");
		}
	}

	
	void run() throws Exception
	{























		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean id1(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && id1(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(id1(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(id1(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}
