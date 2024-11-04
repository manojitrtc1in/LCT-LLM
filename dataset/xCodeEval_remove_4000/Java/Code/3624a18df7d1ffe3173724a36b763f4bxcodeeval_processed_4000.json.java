import java.io.*;
import java.math.BigInteger;
import java.util.*;

import javax.swing.SwingConstants;

public class MainA {
	private static InputStream stream;
	private static byte[] buf = new byte[1024];
	private static int curChar;
	private static int numChars;
	private static id11 filter;
	private static PrintWriter pw;
	

	static long count=0;
	static int flag=-1;
	static int d[];
	static int ans[][];
	static int d2[];
	static int ans2[][];
	public static int[] dfs( int v, int vis[], ArrayList<Integer> arr[],int k ,int r[])
	{
		vis[v]=1;
		for(int i=0;i<k;i++)ans[v][i]=d[i]+1;
		ans[v][r[v]]=0;
		for(int i=0;i<arr[v].size();i++)
		{
			int x=arr[v].get(i);
		
			if(vis[x]==0)
			{
				
				int a[]=dfs(x,vis,arr,k,r);	
				for(int j=0;j<k;j++)
				{
					ans[v][j]=Math.min(ans[v][j],a[j]+1);
				}
				d=ans[v];
			}
		}
		return ans[v];
	}
	
	public static int[] dfs2( int v, int vis[], ArrayList<Integer> arr[],int k ,int r[])
	{
		vis[v]=1;
		for(int i=0;i<k;i++)ans2[v][i]=d2[i]+1;
		ans2[v][r[v]]=0;
		for(int i=arr[v].size()-1;i>=0;i--)
		{
			int x=arr[v].get(i);
		
			if(vis[x]==0)
			{
				
				int a[]=dfs(x,vis,arr,k,r);	
				for(int j=0;j<k;j++)
				{
					ans2[v][j]=Math.min(ans2[v][j],a[j]+1);
				}
				d2=ans2[v];
			}
		}
		return ans2[v];
	}
	
	static int MAXN=101;
	public static class Node
	{
		long val;
		Node left,right;
		Node()
		{
			
		}
		Node(Node l,Node r,int v)
		{
			left=l;right=r;val=v;
		}
	}

	public static int cost[];
	public static Node version[];
	
	public static void build(Node n,int low,int high)
	{
	    if (low==high)
	    {
	        n.val = cost[low];
	        

	        return;
	    }
	    int mid = (low+high) / 2;
	    n.left = new Node(null,null, 0);
	    n.right = new Node(null,null, 0);
	    build(n.left, low, mid);
	    build(n.right, mid+1, high);
	    n.val = n.left.val + n.right.val;
	}
	 
	public static void upgrade(Node prev, Node cur, int low, int high,
	                                   int idx, long value)
	{
	    if (idx > high || idx < low || low > high)
	        return;
	 
	    if (low == high)
	    {    
	        cur.val = prev.val+value;
	        return;
	    }
	    int mid = (low+high) / 2;
	    if (idx <= mid)
	    {
	        cur.right = prev.right;	 
	        cur.left = new Node(null, null, 0);
	        upgrade(prev.left,cur.left, low, mid, idx, value);
	    }
	    else
	    {
	        cur.left = prev.left;
	        cur.right = new Node(null, null, 0);
	        upgrade(prev.right, cur.right, mid+1, high, idx, value);
	    }
	    cur.val = cur.left.val + cur.right.val;
	}
	 
	public static long query(Node n, int low, int high, int l, int r)
	{
	    if (l > high || r < low || low > high)
	       return 0;
	    if (l <= low && high <= r)
	       return n.val;
	    int mid = (low+high) / 2;
	    long p1 = query(n.left,low,mid,l,r);
	    long p2 = query(n.right,mid+1,high,l,r);
	   

	    return p1+p2;
	}

	public static int time=0;
	public static void dfs(int x,int vis[],ArrayList<Integer> arr[],int in[],int out[])
	{
		vis[x]=1;
		in[x]=time++;
		for(int i=0;i<arr[x].size();i++)
		{
			int y=arr[x].get(i);
			if(vis[y]==0)
			{
				dfs(y,vis,arr,in, out);
			}
		}
		out[x]=time-1;
	}
	public static boolean equa(char c)
	{
		if(c=='f' ||c=='r' ||c=='i' ||c=='e' ||c=='z' ||c=='a')return true;
		return false;
	}
	
	public static long id7(int v,int n,int k, ArrayList<Pairs> arr[])
	{
		PriorityQueue<Pair> q=new PriorityQueue();
		q.add(new Pair(0,0));
		long dist[]=new long[n];
		boolean vis[]=new boolean[n];
		Arrays.fill(dist,Long.MAX_VALUE);
		dist[v]=0;
		

		
		while(!q.isEmpty())
		{
			
			Pair top=q.poll();
			
			

			if(vis[top.x])
			{
				continue;
			}
			pw.println(top.x +" "+dist[top.x]);
			vis[top.x]=true;
			for(int i=0;i<arr[top.x].size();i++)
			{
				Pairs p=arr[top.x].get(i);
				int xd=p.x;
				

				if(!vis[xd])
				{
					long di=0;
					long div=(dist[top.x]/k)%2;
					if(div==1 )
					{
						di=k-dist[top.x]%k;
					}				
					long dis=di+dist[top.x]+p.y;;
					if(dis< dist[xd])
					{
						dist[xd]=dis;
						q.add(new Pair(dist[xd],xd));
					}
				}
			}
			
		}
		

		
		return dist[n-1];
	}
	public static int vis[][];
	public static long dist[][];
	static int dx[]= {-1,0,1,0};
	static int dy[]= {0,1,0,-1};
	public static void id5(int n,int m, int x1,int y1,int x2,int y2)
	{
		Deque<Pairs> q=new LinkedList<Pairs>();
		q.addFirst(new Pairs(x1,y1));		
		for(int i=0;i<n;i++)
		{
			Arrays.fill(dist[i],Long.MAX_VALUE);
		}
		dist[x1][y1]=0;
		
		
		while(!q.isEmpty())
		{
			Pairs pp=q.pop();
			for(int i=0;i<4;i++)
			{
				int xd=pp.x+dx[i];
				int yd=pp.y+dy[i];
				

				if((xd>=0 && yd>=0 && xd<n && yd <m)&& vis[xd][yd]!=Integer.MAX_VALUE)
				{	
					long di=vis[xd][yd];
					long dis=di+dist[pp.x][pp.y];
					if(dis< dist[xd][yd])
					{
						dist[xd][yd]=dis;
						if(di==1)
							q.addLast(new Pairs(xd,yd));
						else
							q.addFirst(new Pairs(xd,yd));
					}
				}
			}
			
		}
	
	} 
	
	public static class Pairs 
	{
		int x,y;
		
		Pairs(int u,int v)
		{
			x=u;y=v;
		}
		
		
		
	}
	public static String s[];
	
	static int bc=0;
	public static int sum(int n)
	{	
		if(n==0)
		{
			bc=bc+1;
			return bc;
		}
		int r=sum(n-1);
		return r+(++bc);
	}
	 public static int f(int time,int c,int arr[])
	    {
	        int count=0;int i=0;int temp=0;
	        while(i<arr.length)
	        {
	            if(c*arr[i]>time)return Integer.MAX_VALUE;
	            temp+=c*arr[i];
	            if(temp>time)
	            {
	               temp=c*arr[i]; 
	               count++;
	            }
	            i++;
	        }
	        if(temp>0)count++;
	        return count;
	    }
	public static int paint(int A, int B, int C[]) {
        
	       int low=0;int high=(int)100;int mid;int r=-1;
	       while(low<=high)
	       {
	            mid=(low+high)/2;
	            

	           if(f(mid,B,C)<=A)
	           {
	        	   r=mid;
	               high=mid-1;
	           }
	           else
	           {
	               low=mid+1;
	           }
	       }
	       return (r%(10000003));
	    }
	
	
	   static ArrayList<ArrayList<Integer>> arr=new ArrayList<ArrayList<Integer>>();
	    public static ArrayList<ArrayList<Integer>> combine(int A, int B) {
	        co(A,B,0,1,new ArrayList<Integer>());
	        pw.println(arr.get(0).size());
	        for(int i=0;i<arr.size();i++)
	        {
	        	for(int j=0;j<arr.get(i).size();j++)
	        	{
	        		pw.print(arr.get(i).get(j));
	        	}
	        }
	        return arr;
	        
	    }
	    
	    public static void co(int n,int k,int pos,int cur,ArrayList<Integer> ar)
	    {
	        if(pos==k)
	        {
	        	for(int i=0;i<ar.size();i++)
	        	{
	        		pw.print(ar.get(i)+" ");
	        	}
	        	pw.println();
	            arr.add(ar);
	            return;
	        }
	        if(cur==n+1)
	        {
	            return;
	        }
	        ar.add(cur);
	        co(n,k,pos+1,cur+1,ar);
	        ar.remove((Integer)cur);
	        co(n,k,pos,cur+1,ar);
	    }
static void updateindex(int index[], int a, 
				int ai, int b, int bi) 
{
index[a] = ai;
index[b] = bi;
}







static int id2(int arr[], int pairs[],
				int index[], int i, int n) 
{




if (i >= n)
return 0;







if (pairs[arr[i]] == arr[i + 1])
return id2(arr, pairs, index, i + 2, n);












int one = arr[i + 1];



int indexone = index[pairs[arr[i]]];

int count=indexone-i-1;
for(int j=indexone;j>i+1;j--)
{
	int temp=arr[j];
	arr[j]=arr[j-1];
	arr[j-1]=temp;
	index[arr[j]]=j;
	index[arr[j-1]]=j-1;
}

int a =count+ id2(arr, pairs, index, i + 2, n);







for(int j=i+1;j<indexone;j++)
{
	int temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
	index[arr[j]]=j;
	index[arr[j+1]]=j+1;
}




























return  a;
}



static int id13(int n, int pairs[], int arr[]) 
{


int index[] = new int[2 * n + 1]; 



for (int i = 0; i < 2 * n; i++)
index[arr[i]] = i;



return id2(arr, pairs, index, 0, 2 * n);
}
	private static void soln() 
	{
		
		int n=2*nextInt();
		int a[]= new int[n];int count=0;
		HashMap<Integer,Integer> hm=new HashMap();int pairs[] = new int[n];
		for(int i=0;i<n;i++)
		{
			int x=nextInt()-1;
			if(hm.containsKey(x))
			{
				

				a[i]=x+n/2;
				

			}
			else {hm.put(x, i);a[i]=x;pairs[x]=x+n/2;pairs[x+n/2]=x;}
		}








		
		pw.println(
					id13(n/2, pairs, a));
















		
	}
	
		public static boolean fu(char a,char b,char c)
		{
			if(a=='0' && b=='0' && c=='0')return true;
			return false;
		}
	    static ArrayList<String> answ=new ArrayList<String>();
	    public static ArrayList<String> id6(int A) {
	        String res="";
	        pw.println("ji");
	        genP(0,0,A,res);
	        return answ;
	    }
	    
	    public static void genP(int i,int j,int n,String res)
	    {
	        if(i==n)
	        {
	            if(j<n)
	            {
	                genP(i,j+1,n,res+")");
	            }
	            if(j==n)
	            {
	            	pw.println("hi");
	            	pw.println(res);
	            	answ.add(res);
	            }
	        }
	        else if(i==j)
	        {
	        	pw.println("hi2");
	            genP(i+1,j,n,res+"(");
	        }
	        else if(i>j)
	        {
	            

	            genP(i+1,j,n,res+"(");
	            

	            

	            genP(i,j+1,n,res+")");
	            

	        }
	    }
	
	   
	        
	        public static ArrayList<String> id3(int A) {
	            genP(0,0,A,new ArrayList<Character>());
	            return answ;
	        }
	        
	        public static void genP(int i,int j,int n,ArrayList<Character> ar)
	        {
	            if(i==n)
	            {
	            	if(j<n)
		            {
	            		ar.add(')');
	 	                genP(i,j+1,n,ar);
	 	                ar.remove((Character)')');
		            }
		            if(j==n)
		            {
		            	

		            	String res="";
		            	for(int k=0;k<ar.size();k++)
		            	{
		            		res=res+ar.get(k);
		            	}
		            	

		            	answ.add(res);
		            }
	            	
	            }
	            else if(i==j)
	            {
	                ar.add('(');
	                genP(i+1,j,n,ar);
	                ar.remove((Character)'(');
	            }
	            else if(i>j)
	            {
	                ar.add('(');
	                genP(i+1,j,n,ar);
	                ar.remove((Character)'(');
	                

	                if(i==2 && j==1)
	                {
	                	for(int k=0;k<ar.size();k++)pw.print(ar.get(k));
	                	pw.println();
	                }
	                ar.add(')');
	                genP(i,j+1,n,ar);
	                ar.remove((Character)')');
	            }
	        }
	    

	static long d1, x, y;
	public static void id10(long A, long B) {
	    if(B == 0) {
	        d1 = A;
	        x = 1;
	        y = 0;
	    }
	    else {
	        id10(B, A%B);
	        long temp = x;
	        x = y;
	        y = temp - (A/B)*y;
	    }
	}
	public static long modInverse(long A, long M)
	{
	    id10(A,M);
	    return (x%M+M)%M;    

	}
	private static long powe(long x1, long y1,long p) {
		long res = 1;     
        
        

        

        x1 = x1 % p; 
     
        while (y1 > 0)
        {
            

            

            if((y1 & 1)==1)
                res = (res * x1) % p;
     
            

            

            y1 = y1 >> 1; 
            x1 = (x1 * x1) % p; 
        }
        return res;
	}
	public static int biSearch(long div[],long n)
	{
		int low=0;int high=div.length-1;int res=-1;
		while(low<=high)
		{
			int mid=(low+high)/2;
			if(div[mid]<n)
			{
				res=mid;
				low=mid+1;
			}
			else high=mid-1;
		}
		return res;
	}
	public static void sieve(int prime[],int k,long co[],ArrayList<Integer> arr,long mod)
	{
		for(int i=0;i<=k;i++)prime[i]=i;
		
		for(int i=2;i*i<=k;i++)
		{
			if(prime[i]==i)
			{
				
				for(int j=2*i;j<=k;j+=i)
				{
					prime[j]=i;
				}
			}
		}
		for(int i=2;i<=k;i++)if(prime[i]==i)arr.add(prime[i]);
		co[1]=1;
		for(int i=2;i<=k;i++)
		{
			int key=i;int prev=0;co[i]=i;
			while(key>1)
			{
				int p=prime[key];
				key/=p;
				if(prev!=p)
				{
					co[i]=(co[i]*(p-1));
					co[i]=(co[i]/p);
				}				
				prev=p;	
			}
			co[i]=(co[i]*i)/2;
			co[i]=(co[i]%mod);
			











		}
		
		
		
		
		
		
	}
	
	public static double dist(int x, int y,int a[], int b[])
	{
		return Math.sqrt(Math.pow(a[x]-a[y],2)+Math.pow(b[x]- b[y],2));
	}
	public static double bSearch(int a[],int b[],int n,long p)
	{
		double l=0;double r=(double)1e15;
		for(int i=0;i<200;i++)
		{
			double mid=(l+r)/2;
			

			if(f(mid,a,b,p,n))
			{
				l=mid;
				
				

			}
			else r=mid;
			

		}
		return l;
	}
	
	public static boolean f(double t,int a[],int b[],long p,int n)
	{
		double totalCons=0;
		for(int i=0;i<n;i++)
		{
			double total=a[i]*t-b[i];
			

			if(total>0)
			{
				totalCons+=total;
			}
		}
		

		if(totalCons<=p*t)return true;
		else return false;
	}
	public static int check(String s[],int x, int y,int n,int m)
	{
		int dx[]= {-1,0,1,1,1,0,-1,-1};
		int dy[]= {-1,-1,-1,0,1,1,1,0};
		int count=0;
		for(int i=0;i<8;i++)
		{
			int vx=x+dx[i];
			int vy=y+dy[i];
			if(vx<0 || vx>=n ||vy<0 || vy>=m)
			{
				
			}
			else
			{
				if(s[vx].charAt(vy)=='*')count++;
			}
		}
		return count;
	}

	public static class Pair implements Comparable<Pair>
	{
		long val;
		int x;
		Pair(long a,int b)
		{
			val=a;x=b;
		}
		
		@Override
		public int compareTo(Pair o)
		{
			
			return Long.compare(val,o.val);
		}
	}
	public static class Segment {
		private int[] tree;
		private boolean[] lazy;
		private int size;
		private int n;

		private class node {
			private int a;
			private int b;
			private int c;

			public node(int x, int y, int z) {
				a = x;
				b = y;
				c = z;
			}
		}

		public Segment(int n) {
			

			int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
			size = 2 * (int) Math.pow(2, x) - 1;
			tree = new int[size];
			lazy = new boolean[size];
			this.n = n;
			build(0, 0, n - 1);
		}

		public void build(int id, int l, int r) {
			if (l == r) {
				return;
			}
			int mid = (l + r) / 2;
			build(2 * id + 1, l, mid);
			build(2 * id + 2, mid + 1, r);
			tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
		}

		public int query(int l, int r) {
			return queryUtil(l, r, 0, 0, n - 1);
		}

		private int queryUtil(int x, int y, int id, int l, int r) {
			if (l > y || x > r)
				return 0;
			if (x <= l && r <= y) {
				

				return tree[id];
				

				

			}
			int mid = l + (r - l) / 2;
			shift(id);
			return queryUtil(x, y, 2 * id + 1, l, mid) + queryUtil(x, y, 2 * id + 2, mid + 1, r);
		}

		public void update(int x, int y, int colour, int id, int l, int r) {
			

			if (x > r || y < l)
				return;
			if (x <= l && r <= y) {

				return;
			}
			int mid = l + (r - l) / 2;
			shift(id);
			update(x, y, colour, 2 * id + 1, l, mid);
			update(x, y, colour, 2 * id + 2, mid + 1, r);
			tree[id] = tree[2 * id + 1] + tree[2 * id + 2];
		}

		public void shift(int id) {

		}
	}

	public static void fft(double[] a, double[] b, boolean invert) {
		int count = a.length;
		for (int i = 1, j = 0; i < count; i++) {
			int bit = count >> 1;
			for (; j >= bit; bit >>= 1)
				j -= bit;
			j += bit;
			if (i < j) {
				double temp = a[i];
				a[i] = a[j];
				a[j] = temp;
				temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
		for (int len = 2; len <= count; len <<= 1) {
			int halfLen = len >> 1;
			double angle = 2 * Math.PI / len;
			if (invert)
				angle = -angle;
			double id8 = Math.cos(angle), id0 = Math.sin(angle);
			for (int i = 0; i < count; i += len) {
				double wA = 1, wB = 0;
				for (int j = 0; j < halfLen; j++) {
					double uA = a[i + j], uB = b[i + j];
					double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
					double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
					a[i + j] = uA + vA;
					b[i + j] = uB + vB;
					a[i + j + halfLen] = uA - vA;
					b[i + j + halfLen] = uB - vB;
					double nextWA = wA * id8 - wB * id0;
					wB = wA * id0 + wB * id8;
					wA = nextWA;
				}
			}
		}
		if (invert) {
			for (int i = 0; i < count; i++) {
				a[i] /= count;
				b[i] /= count;
			}
		}
	}

	static void multiply(long[][] a, long[][] b, long m) {
		int n = a.length;
		long[][] mul = new long[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mul[i][j] = 0;
				for (int k = 0; k < n; k++)
					mul[i][j] = (mul[i][j] + (a[i][k] * b[k][j]) % m) % m;
			}
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = mul[i][j];
	}

	private static long pow(long a, long b, long c) {
		if (b == 0)
			return 1;
		long p = pow(a, b / 2, c);
		p = (p * p) % c;
		return (b % 2 == 0) ? p : (a * p) % c;
	}

	private static long gcd(long n, long l) {
		if (l == 0)
			return n;
		return gcd(l, n % l);
	}

	public static void main(String[] args) throws Exception {
		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		

		


		
		InputReader(System.in);
		pw = new PrintWriter(System.out);
		
		soln();
		pw.close();
	}

	public static void InputReader(InputStream stream1) {
		stream = stream1;
	}

	private static boolean isWhitespace(int c) {
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	private static boolean id9(int c) {
		return c == '\n' || c == '\r' || c == -1;
	}

	private static int read() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	private static int nextInt() {
		int c = read();
		while (id1(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		int res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id1(c));
		return res * sgn;
	}

	private static long nextLong() {
		int c = read();
		while (id1(c))
			c = read();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = read();
		}
		long res = 0;
		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = read();
		} while (!id1(c));
		return res * sgn;
	}

	private static String nextToken() {
		int c = read();
		while (id1(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id1(c));
		return res.toString();
	}

	private static String nextLine() {
		int c = read();
		while (id1(c))
			c = read();
		StringBuilder res = new StringBuilder();
		do {
			res.appendCodePoint(c);
			c = read();
		} while (!id9(c));
		return res.toString();
	}

	private static int[] id4(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextInt();
		}
		return arr;
	}

	private static long[] id12(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nextLong();
		}
		return arr;
	}

	private static void pArray(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static void pArray(long[] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		System.out.println();
		return;
	}

	private static boolean id1(int c) {
		if (filter != null)
			return filter.id1(c);
		return isWhitespace(c);
	}

	private static char nextChar() {
		int c = read();
		while (id1(c))
			c = read();
		char c1 = (char) c;
		while (!id1(c))
			c = read();
		return c1;
	}

	private interface id11 {
		public boolean id1(int ch);
	}
}