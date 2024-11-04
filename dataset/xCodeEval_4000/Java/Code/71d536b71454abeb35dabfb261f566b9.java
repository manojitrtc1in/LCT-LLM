

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.Random;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new int[]{ni(), ni()-1, ni(), i, -1, -1, -1, -1};
			if(qs[i][0] == 2)qs[i][2]--;
		}
		
		Node[] roots = new Node[n+1];
		Node[] nodes = new Node[n+1];
		for(int i = 0;i < n;i++){
			nodes[i] = new Node(i);
			roots[a[i]] = insert(roots[a[i]], count(roots[a[i]]), nodes[i]);
		}
		
		int[] b = Arrays.copyOf(a, n);
		for(int[] q : qs){
			if(q[0] == 1){
				q[3] = b[q[1]];
				Node prev = prev(nodes[q[1]]);
				Node next = next(nodes[q[1]]);
				q[4] = prev == null ? -1 : prev.v;
				q[5] = next == null ? -1 : next.v;
				roots[q[3]] = erase(roots[q[3]], index(nodes[q[1]]));
				
				roots[q[2]] = insertb(roots[q[2]], nodes[q[1]]);
				b[q[1]] = q[2];
				prev = prev(nodes[q[1]]);
				next = next(nodes[q[1]]);
				q[6] = prev == null ? -1 : prev.v;
				q[7] = next == null ? -1 : next.v;
			}
		}
		int[][] q2s = new int[Q][];
		int p = 0;
		for(int[] q : qs){
			if(q[0] == 2){
				q2s[p++] = q;
			}
		}
		q2s = Arrays.copyOf(q2s, p);
		int S = (int)Math.pow(Q, 2./3)*7/6;
		Arrays.sort(q2s, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[3]/S != b[3]/S)return a[3] - b[3];
				if(a[1]/S != b[1]/S)return a[1] - b[1];
				if((a[1]/S&1) == 0)return a[2] - b[2];
				return -(a[2] - b[2]);
			}
		});
		int L = 0, R = -1, T = -1;
		long sum = 0;
		int[] prev = new int[n];
		int[] next = new int[n];
		{
			int[] h = new int[n+3];
			Arrays.fill(h, -1);
			for(int i = 0;i < n;i++){
				prev[i] = h[a[i]];
				h[a[i]] = i;
			}
		}
		{
			int[] h = new int[n+3];
			Arrays.fill(h, n);
			for(int i = n-1;i >= 0;i--){
				next[i] = h[a[i]];
				h[a[i]] = i;
			}
		}
		long[] ans = new long[Q];
		for(int[] q : q2s){
			while(T < q[3]){
				T++;
				int[] z = qs[T];
				if(z[0] == 1){
					int bp = z[4];
					int bn = z[5];
					if(bp != -1)next[bp] = bn;
					if(bn != -1)prev[bn] = bp;
					if(L <= z[1] && z[1] <= R){
						if(bp == -1 || bp < L){
							if(bn != -1 && bn <= R){
								sum -= bn - z[1];
							}
						}
						if(bn == -1 || bn > R){
							if(bp != -1 && bp >= L){
								sum -= z[1] - bp;
							}
						}
					}
					
					int ap = z[6];
					int an = z[7];
					prev[z[1]] = ap;
					next[z[1]] = an;
					if(ap != -1)next[ap] = z[1];
					if(an != -1)prev[an] = z[1];
					
					if(L <= z[1] && z[1] <= R){
						if(ap == -1 || ap < L){
							if(an != -1 && an <= R){
								sum += an - z[1];
							}
						}
						if(an == -1 || an > R){
							if(ap != -1 && ap >= L){
								sum += z[1] - ap;
							}
						}
					}
				}
			}
			while(T > q[3]){
				int[] z = qs[T];
				if(z[0] == 1){
					int bp = z[6];
					int bn = z[7];
					if(bp != -1)next[bp] = bn;
					if(bn != -1)prev[bn] = bp;
					if(L <= z[1] && z[1] <= R){
						if(bp == -1 || bp < L){
							if(bn != -1 && bn <= R){
								sum -= bn - z[1];
							}
						}
						if(bn == -1 || bn > R){
							if(bp != -1 && bp >= L){
								sum -= z[1] - bp;
							}
						}
					}
					
					int ap = z[4];
					int an = z[5];
					prev[z[1]] = ap;
					next[z[1]] = an;
					if(ap != -1)next[ap] = z[1];
					if(an != -1)prev[an] = z[1];
					
					if(L <= z[1] && z[1] <= R){
						if(ap == -1 || ap < L){
							if(an != -1 && an <= R){
								sum += an - z[1];
							}
						}
						if(an == -1 || an > R){
							if(ap != -1 && ap >= L){
								sum += z[1] - ap;
							}
						}
					}
				}
				T--;
			}
			
			while(R < q[2]){
				R++;
				if(prev[R] != -1 && prev[R] >= L){
					sum += R-prev[R];
				}
			}
			while(L > q[1]){
				L--;
				if(next[L] != -1 && next[L] <= R){
					sum += next[L] - L;
				}
			}
			while(R > q[2]){
				if(prev[R] != -1 && prev[R] >= L){
					sum -= R-prev[R];
				}
				R--;
			}
			while(L < q[1]){
				if(next[L] != -1 && next[L] <= R){
					sum -= next[L] - L;
				}
				L++;
			}
			ans[q[3]] = sum;
		}
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2){
				out.println(ans[i]);
			}
		}
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
	
	public static Node mergeTechnically(Node x, Node y)
	{
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
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
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
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ 

			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
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