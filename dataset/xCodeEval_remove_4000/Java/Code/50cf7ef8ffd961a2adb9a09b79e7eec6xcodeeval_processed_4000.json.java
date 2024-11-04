import java.util.*;
import java.io.*;
import java.math.*;
public class ost {
	InputStream is;
	PrintWriter out;
	static long mod=pow(10,9)+7;
	int dx[]= {0,0,1,-1},dy[]={+1,-1,0,0};
	void solve()
	{
		int max=1000;
		id1<Integer> os=new id1<Integer>();
		TreeSet<Integer> ts[]=new TreeSet[max+1];
		for(int i=0;i<=max;i++)
			ts[i]=new TreeSet<Integer>();
		int n=ni();
		int q=ni();
		String s=ns();
		for(int i=0;i<s.length();i++)
		{
			ts[s.charAt(i)].add(i);
			os.insert(i);
		}
		while(q--!=0)
		{
			int l=ni();
			int r=ni();
			char ch=ns().charAt(0);
			int ll=os.id4(l);
			int rr=os.id4(r);
			Integer right=ts[ch].ceiling(ll);
			while(right!=null&&right<=rr)
			{
				ts[ch].remove(right);
				os.delete(right);
				right=ts[ch].ceiling(ll);
			}
		}
		boolean visited[]=new boolean[n];
		for(int i=0;i<=max;i++)
		{
			Iterator<Integer> it=ts[i].iterator();
			while(it.hasNext())
			{
				int index=it.next();
				visited[index]=true;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(visited[i])
				out.print(s.charAt(i));
		}
	}
	static class id1<T extends Comparable<T>>
	{
		static class Node<T extends Comparable<T>>
		{
			Node<T> left, right;
			T value;
			int id7;
			int height;
		}

		static class id17<T extends Comparable<T>>
		{

			public static <T extends Comparable<T>> void printNode(Node<T> root)
			{
				int maxLevel = id17.maxLevel(root);

				id13(Collections.singletonList(root), 1, maxLevel);
			}

			private static <T extends Comparable<T>> void id13(
					List<Node<T>> roots, int level, int maxLevel)
			{
				if (roots.isEmpty() || id17.id19(roots))
					return;

				int floor = maxLevel - level;
				int id6 = (int) Math.pow(2, (Math.max(floor - 1, 0)));
				int firstSpaces = (int) Math.pow(2, (floor)) - 1;
				int betweenSpaces = (int) Math.pow(2, (floor + 1)) - 1;

				id17.id22(firstSpaces);

				List<Node<T>> newNodes = new ArrayList<Node<T>>();
				for (Node<T> root : roots)
				{
					if (root != null)
					{
						System.out.print(root.value);
						newNodes.add(root.left);
						newNodes.add(root.right);
					}
					else
					{
						newNodes.add(null);
						newNodes.add(null);
						System.out.print(" ");
					}

					id17.id22(betweenSpaces);
				}
				System.out.println("");

				for (int i = 1; i <= id6; i++)
				{
					for (int j = 0; j < roots.size(); j++)
					{
						id17.id22(firstSpaces - i);
						if (roots.get(j) == null)
						{
							id17.id22(id6
									+ id6 + i + 1);
							continue;
						}

						if (roots.get(j).left != null)
							System.out.print("/");
						else
							id17.id22(1);

						id17.id22(i + i - 1);

						if (roots.get(j).right != null)
							System.out.print("\\");
						else
							id17.id22(1);

						id17.id22(id6 + id6
								- i);
					}

					System.out.println("");
				}

				id13(newNodes, level + 1, maxLevel);
			}

			private static void id22(int count)
			{
				for (int i = 0; i < count; i++)
					System.out.print(" ");
			}

			private static <T extends Comparable<T>> int maxLevel(Node<T> root)
			{
				if (root == null)
					return 0;

				return Math.max(id17.maxLevel(root.left),
						id17.maxLevel(root.right)) + 1;
			}

			private static <T> boolean id19(List<T> list)
			{
				for (Object object : list)
				{
					if (object != null)
						return false;
				}

				return true;
			}

		}

		private Node<T> root;

		public id1()
		{
			root = null;
		}

		public Integer id9(T value)
		{
			return id10(root, value);
		}

		public Integer id10(Node<T> root, T value)
		{
			if (root == null)
				return -1;

			if (value.equals(root.value))
			{
				return root.id7;
			}
			else if (root.value.compareTo(value) > 0)
			{
				return id10(root.left, value);
			}
			else if (root.value.compareTo(value) < 0)
			{
				int ind = id10(root.right, value);

				if (ind != -1)
					return root.id7 + 1 + ind;
				else
					return -1;
			}

			return -1;
		}

		public Node<T> search(T value)
		{
			return searchHelper(root, value);
		}

		public Node<T> searchHelper(Node<T> root, T value)
		{
			if (root == null)
				return null;

			if (value.equals(root.value))
			{
				return root;
			}
			else if (root.value.compareTo(value) > 0)
			{
				return searchHelper(root.left, value);
			}
			else if (root.value.compareTo(value) < 0)
			{
				return searchHelper(root.right, value);
			}

			

			return null;
		}

		public Node<T> insert(T value)
		{
			return root = insertHelper(root, value);
		}

		

		int height(Node<T> N)
		{
			if (N == null)
				return 0;

			return N.height;
		}

		

		int max(int a, int b)
		{
			return (a > b) ? a : b;
		}

		

		

		Node<T> rightRotate(Node<T> y)
		{
			Node<T> x = y.left;
			Node<T> T2 = x.right;

			

			x.right = y;
			y.left = T2;

			

			y.height = max(height(y.left), height(y.right)) + 1;
			x.height = max(height(x.left), height(x.right)) + 1;

			y.id7 -= (x.id7 + 1);

			

			return x;
		}

		

		

		Node<T> leftRotate(Node<T> x)
		{
			Node<T> y = x.right;
			Node<T> T2 = y.left;

			

			y.left = x;
			x.right = T2;

			

			x.height = max(height(x.left), height(x.right)) + 1;
			y.height = max(height(y.left), height(y.right)) + 1;

			y.id7 += (x.id7 + 1);
			

			return y;
		}

		

		int getBalance(Node<T> N)
		{
			if (N == null)
				return 0;

			return height(N.left) - height(N.right);
		}

		public Node<T> insertHelper(Node<T> root, T value)
		{
			if (root == null)
			{
				Node<T> nn = new Node<T>();
				nn.value = value;
				nn.id7 = 0;
				nn.height = 1;

				return nn;
			}

			else if (root.value.compareTo(value) > 0)
			{
				root.left = insertHelper(root.left, value);
				root.id7++;
			}
			else if (root.value.compareTo(value) < 0)
			{
				root.right = insertHelper(root.right, value);
			}
			else
				

				return root;

			root.height = 1 + max(height(root.left), height(root.right));

			
			int balance = getBalance(root);

			

			

			if (balance > 1 && root.left.value.compareTo(value) > 0)
				return rightRotate(root);

			

			if (balance < -1 && root.right.value.compareTo(value) < 0)
				return leftRotate(root);

			

			if (balance > 1 && root.left.value.compareTo(value) < 0)
			{
				root.left = leftRotate(root.left);
				return rightRotate(root);
			}

			

			if (balance < -1 && root.right.value.compareTo(value) > 0)
			{
				root.right = rightRotate(root.right);
				return leftRotate(root);
			}

			return root;
		}

		public void delete(T value)
		{
			root = deleteHelper(root, value);
		}

		private Node<T> id2(Node<T> root)
		{
			Node<T> current = root;

			while (current.left != null)
			{
				current = current.left;
			}

			return current;
		}

		private Node<T> deleteHelper(Node<T> root, T value)
		{
			

			if (root == null)
				return null;

			if (value.equals(root.value))
			{
				if (root.left == null && root.right == null)
				{
					return null;
				}
				else if (root.left != null && root.right == null)
				{
					return root.left;
				}
				else if (root.left == null && root.right != null)
				{
					return root.right;
				}
				else
				{
					Node<T> temp = id2(root.right);

					root.value = temp.value;

					root.right = deleteHelper(root.right, temp.value);
				}
			}
			else if (root.value.compareTo(value) > 0)
			{
				root.left = deleteHelper(root.left, value);
				root.id7--;
			}
			else if (root.value.compareTo(value) < 0)
			{
				root.right = deleteHelper(root.right, value);
			}

			root.height = 1 + max(height(root.left), height(root.right));

			
			int balance = getBalance(root);

			if (balance > 1 && getBalance(root.left) >= 0)
				return rightRotate(root);

			

			if (balance > 1 && getBalance(root.left) < 0)
			{
				root.left = leftRotate(root.left);
				return rightRotate(root);
			}

			

			if (balance < -1 && getBalance(root.right) <= 0)
				return leftRotate(root);

			

			if (balance < -1 && getBalance(root.right) > 0)
			{
				root.right = rightRotate(root.right);
				return leftRotate(root);
			}

			return root;
		}

		public T id4(int n)
		{
			return id8(root, n);
		}

		public T id8(Node<T> root, int n)
		{
			if (root == null)
			{
				return null;
			}

			if (root.id7 + 1 == n)
			{
				return root.value;
			}
			else if (root.id7 + 1 < n)
			{
				return id8(root.right, n - root.id7
						- 1);
			}
			else
			{
				return id8(root.left, n);
			}
		}

		public int id14(T n, int def)
		{
			return id15(root, n, def);
		}

		public int id15(Node<T> root, T value,
				int def)
		{
			if (root == null)
			{
				return def;
			}

			if (root.value.equals(value))
			{
				return root.id7;
			}

			if (root.value.compareTo(value) < 0)
			{
				int ceil = id15(root.right, value,
						def);

				if (ceil != def)
				{
					return root.id7 + 1 + ceil;
				}
				else
				{
					return def;
				}
			}
			else
			{
				int ceil = id15(root.left, value,
						def);

				if (ceil != def)
				{
					return ceil;
				}
				else
				{
					return root.id7;
				}
			}
		}

		public T id5(T n)
		{
			return id0(root, n);
		}

		private T id0(Node<T> root, T value)
		{
			if (root == null)
			{
				return null;
			}

			if (root.value.equals(value))
			{
				return root.value;
			}

			if (root.value.compareTo(value) < 0)
			{
				return id0(root.right, value);
			}
			else
			{
				T ceil = id0(root.left, value);

				if (ceil != null && ceil.compareTo(value) >= 0)
				{
					return ceil;
				}
				else
				{
					return root.value;
				}
			}
		}

		public Integer id12(T value)
		{
			return id16(root, value);
		}

		public Integer id16(Node<T> root, T value)
		{
			if (root == null)
			{
				return -1;
			}

			if (root.value.equals(value))
			{
				return root.id7;
			}

			if (root.value.compareTo(value) > 0)
			{
				return id16(root.left, value);
			}
			else
			{
				int floor = id16(root.right, value);
				if (floor != -1)
				{
					return root.id7 + 1 + floor;
				}
				else
				{
					return root.id7;
				}
			}
		}

		public T id18(T value)
		{
			return id20(root, value);
		}

		private T id20(Node<T> root, T value)
		{
			if (root == null)
			{
				return null;
			}
			if (root.value.equals(value))
			{
				return root.value;
			}

			if (root.value.compareTo(value) > 0)
			{
				return id20(root.left, value);
			}
			else
			{
				T floor = id20(root.right, value);
				if (floor != null && floor.compareTo(value) <= 0)
				{
					return floor;
				}
				else
				{
					return root.value;
				}
			}
		}

		int size()
		{
			return sizeHelper(root);
		}

		int sizeHelper(Node<T> root)
		{
			if (root == null)
				return 0;

			return root.id7 + 1 + sizeHelper(root.right);
		}

		void print()
		{
			id17.printNode(root);
		}
	}
	int small[];
	void pre(int n)
	{
		small=new int[n+1];
		for(int i=2;i*i<=n;i++)
		{
			for(int j=i;j*i<=n;j++)
			{
				if(small[i*j]==0)
					small[i*j]=i;
			}
		}
		for(int i=0;i<=n;i++)
		{
			if(small[i]==0)
				small[i]=i;
		}
	}
	public static int count(int x)
	{
		int num=0;
		while(x!=0)
		{
			x=x&(x-1);
			num++;
		}
		return num;
	}
	static long d, x, y;
	void id21(long A, long B) {
	    if(B == 0) {
	        d = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        id21(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	long modInverse(long A,long M) 

	{
	    id21(A,M);
	    return (x%M+M)%M;    

	}
	public static void mergeSort(int[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(int arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		int left[] = new int[n1];
		int right[] = new int[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	public static void mergeSort(long[] arr, int l ,int r){
		if((r-l)>=1){
			int mid = (l+r)/2;
			mergeSort(arr,l,mid);
			mergeSort(arr,mid+1,r);
			merge(arr,l,r,mid);
		}
	}
	public static void merge(long arr[], int l, int r, int mid){
		int n1 = (mid-l+1), n2 = (r-mid);
		long left[] = new long[n1];
		long right[] = new long[n2];
		for(int i =0 ;i<n1;i++) left[i] = arr[l+i];
		for(int i =0 ;i<n2;i++) right[i] = arr[mid+1+i];
		int i =0, j =0, k = l;
		while(i<n1 && j<n2){
			if(left[i]>right[j]){
				arr[k++] = right[j++];
			}
			else{
				arr[k++] = left[i++];
			}
		}
		while(i<n1) arr[k++] = left[i++];
		while(j<n2) arr[k++] = right[j++];
	}
	 static class Pair implements Comparable<Pair>{
		 
	      int x,y,k,i;
		Pair (int x,int y,int k){
			this.x=x;
			this.y=y;
			this.k=k;
		}
	        
		public int compareTo(Pair o) {
			return this.y-o.y;
		}
		public boolean equals(Object o) {
			if (o instanceof Pair) {
				Pair p = (Pair)o;
				return p.x == x && p.y == y;
			}
			return false;
		}
		public int hashCode() {
			return new Long(x).hashCode()*31 + new Long(y).hashCode() ;
		}
	           
	 
	        @Override
	        public String toString() {
	            return  "("+x + " " + y +" "+k+" "+i+" )";
	        }
	    
	    } 
	    
	    public static boolean isPal(String s){
	        for(int i=0, j=s.length()-1;i<=j;i++,j--){
	                if(s.charAt(i)!=s.charAt(j)) return false;
	        }
	        return true;
	    }
	    public static String rev(String s){
			StringBuilder sb=new StringBuilder(s);
			sb.reverse();
			return sb.toString();
	    }
	    
	    public static long gcd(long x,long y){
		if(x%y==0)
			return y;
		else
			return gcd(y,x%y);
	    }
	    
	    public static int gcd(int x,int y){
	    	if(y==0) 
	    		return x; 
	    	return gcd(y,x%y);
	    }
	    
	    public static long id11(long a,long b,long[] x){
	        
	        if(a==0){
	            x[0]=0;
	            x[1]=1;
	            return b;
	        }
	        long[] y=new long[2];
	        long gcd=id11(b%a, a, y);
	        
	        x[0]=y[1]-(b/a)*y[0];
	        x[1]=y[0];
	        
	        return gcd;
	    }
	    
	    public static int abs(int a,int b){
		return (int)Math.abs(a-b);
	    }
	 
	    public static long abs(long a,long b){
		return (long)Math.abs(a-b);
	    }
	    
	    public static int max(int a,int b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static int min(int a,int b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	    
	    public static long max(long a,long b){
		if(a>b)
			return a;
		else
			return b;
	    }
	 
	    public static long min(long a,long b){
		if(a>b)
			return b;
		else 
			return a;
	    }
	 
	    public static long pow(long n,long p,long m){
		 long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;
		    if(result>=m)
		    result%=m;
		    p >>=1;
		    n*=n;
		    if(n>=m)
		    n%=m;
		}
		return result;
	    }
	    
	    public static long pow(long n,long p){
		long  result = 1;
		  if(p==0)
		    return 1;
		if (p==1)
		    return n;
		while(p!=0)
		{
		    if(p%2==1)
		        result *= n;	    
		    p >>=1;
		    n*=n;	    
		}
		return result;
	    }
	    public static void debug(Object... o) {
			System.out.println(Arrays.deepToString(o));
		}
	    void run() throws Exception {
			is = System.in;
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		}
	   
	    public static void main(String[] args) throws Exception {
			new Thread(null, new Runnable() {
				public void run() {
					try {
						new ost().run();
					} catch (Exception e) {
						e.printStackTrace();
					}
				}
			}, "1", 1 << 26).start();

		}
	    private byte[] inbuf = new byte[1024];
		public int lenbuf = 0, ptrbuf = 0;
	 
		private int readByte() {
			if (lenbuf == -1)
				throw new InputMismatchException();
			if (ptrbuf >= lenbuf) {
				ptrbuf = 0;
				try {
					lenbuf = is.read(inbuf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return -1;
			}
			return inbuf[ptrbuf++];
		}
	 
		private boolean id3(int c) {
			return !(c >= 33 && c <= 126);
		}
	 
		private int skip() {
			int b;
			while ((b = readByte()) != -1 && id3(b));
			return b;
		}
	 
		private double nd() {
			return Double.parseDouble(ns());
		}
	 
		private char nc() {
			return (char) skip();
		}
	 
		private String ns() {
			int b = skip();
			StringBuilder sb = new StringBuilder();
			while (!(id3(b))) { 

				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
	 
		private char[] ns(int n) {
			char[] buf = new char[n];
			int b = skip(), p = 0;
			while (p < n && !(id3(b))) {
				buf[p++] = (char) b;
				b = readByte();
			}
			return n == p ? buf : Arrays.copyOf(buf, p);
		}
	 
		private char[][] nm(int n, int m) {
			char[][] map = new char[n][];
			for (int i = 0; i < n; i++)
				map[i] = ns(m);
			return map;
		}
	 
		private int[] na(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = ni();
			return a;
		}
	 
		private int ni() {
			int num = 0, b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
		private long nl() {
			long num = 0;
			int b;
			boolean minus = false;
			while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
				;
			if (b == '-') {
				minus = true;
				b = readByte();
			}
	 
			while (true) {
				if (b >= '0' && b <= '9') {
					num = num * 10 + (b - '0');
				} else {
					return minus ? -num : num;
				}
				b = readByte();
			}
		}
	 
}