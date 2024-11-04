
import java.awt.Point;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;


public class N734 {
	static PrintWriter out;
	static Scanner sc;
	static ArrayList<Integer>q,w;
	static ArrayList<Integer>adj[];
	static HashSet<Integer>id2;
	static boolean prime[];
	

	static HashSet<Long>tmp;
	static boolean[]v;
	static int[]c,d;
	static int[][]dp;
	static char[][]mp;
	static int A,B,n,m,h,ans;
	static String a,b;
	public static void main(String[]args) throws IOException {
		sc=new Scanner(System.in);
		out=new PrintWriter(System.out);
		

		

		B2();
	   

	    

		

		

		

		

		out.close();
	}
	  private static void A() throws IOException {
		  	
		  int t=ni();
			while(t-->0) {
				int n=ni();
				int th=n/3;
				int a=th,b=th;
				if(n%3==1) {
					a++;
				}else if(n%3==2) {
					b++;
				}
				out.println(a+" "+b);
			}
	   }
		
		static void B1() throws IOException {
			int t=ni();
			a:while(t-->0) {
				String s=ns();
				int[]occ=new int[26];
				for(int i=0;i<s.length();i++)occ[s.charAt(i)-'a']++;
				int r=0,g=0;
				for(int i=0;i<26;i++) {
					if(occ[i]==0)continue;
					if(occ[i]==1) {
						if(r>=g)g++;
						else r++;
					}else {
						r++;
						g++;
					}
				}
				out.println(Math.min(r,g));
				
			}
		}
		static void B2() throws IOException {
			int t=ni();
			a:while(t-->0) {
				int n=ni(),k=ni();
				Integer[]a=new Integer[n];
				int[]ans=new int[n];
				HashMap<Integer,ArrayList<Integer>>hm=new HashMap<Integer, ArrayList<Integer>>();
				
				for(int i=0;i<n;i++) {
					a[i]=ni();
					ArrayList<Integer>pos=hm.getOrDefault(a[i], new ArrayList<Integer>());
					pos.add(i);
					hm.put(a[i], pos);
				}
				

				int col=1;
				for(int x:hm.keySet()) {
					ArrayList<Integer>arr=hm.get(x);
					for(int i=0;i<Math.min(k, arr.size());i++) {
						ans[arr.get(i)]=col++;
						if(col>k)col=1;
					}
				}
				
				if(col!=1) {
					boolean[] nd=new boolean[col];
					for(int i=0;i<n;i++) {
						if(ans[i]!=0&&ans[i]<col&&!nd[ans[i]]) {
							nd[ans[i]]=true;
							ans[i]=0;
						}
					}
				}
				for(int i=0;i<n;i++)out.print(ans[i]+" ");
				ol("");
				
			}
		}		
public static int id3(int i,Long[]a,long k) {
			int st=i+1,end=a.length-1;
			if(a[st]>=k)return st;
			if(a[end]<k)return -1;
			while(end-st>1) {
				int mid=(end+st)/2;

				if(a[mid]>=k)
					end=mid;
				else
					st=mid;
			}
			return end;

		}
		public static int id0(int i,Long[]a,long k) {
			int st=i+1,end=a.length-1;
			if(a[end]<=k)return end;
			if(a[st]>k)return -1;
			while(end-st>1) {
				int mid=(end+st)/2;

			    if(a[mid]<=k)
					st=mid;
				else
					end=mid;
			}
			return st;
		}
		static void C() throws IOException{
			 int t=ni();
			 a:while(t-->0) {
				 
			 }
		}
		static ArrayList<Integer>primes;
		static void sieve(int N)
		{
			primes = new ArrayList<Integer>();
			boolean[] isComposite = new boolean[N];
			for(int i = 2; i < N; ++i)
				if(!isComposite[i])
				{
					primes.add(i);
					if(1l*i*i<N) {
					for(int j = i * i; j < N; j += i)
						isComposite[j] = true;
					}
				}
		}
		static int gcd (int a, int b) {
		    return b==0?a:gcd (b, a % b);
		}
		static void D1() throws IOException {
			int t=ni();
			

			a:while(t-->0) {
				int n=ni(),m=ni(),k=ni();








				if(n%2==0&&m%2==0) {
					out.println(k%2==0?"yes":"no");
				}else if(n%2==0&&m%2==1) {
					m--;
					out.println(k%2==0&&k<=(n*m)/2?"yes":"no");
				}else {
					n--;
					int mn=m/2;
					k-=mn;
					out.println(k>=0&&k%2==0&&k<=(n*m/2)?"yes":"no");
				}
			}
			
		}
		static char[][]as;
		static void D2() throws IOException {
			int t=ni();
			

			a:while(t-->0) {
				int n=ni(),m=ni(),k=ni();








				as=new char[n][m];
				for(int i=0;i<n;i++)Arrays.fill(as[i], '
				if(n%2==0&&m%2==0) {
					if(k%2==0) {
						ol("YES");
						construct1(n,m,k);
					}else {
						ol("NO");
						continue a;
					}
					
				}else if(n%2==0&&m%2==1) {
					m--;
					char c='a';
					for(int i=0;i<n;i+=2) {
						as[i][m]=c;
						as[i+1][m]=c++;
						if(c>'z')c='a';
					}
					if(k%2==0&&k<=(n*m)/2) {
						ol("YES");
						construct1(n,m,k);
					}else {
						ol("NO");
						continue a;
					}
					

				}else {
					n--;
					char c='a';
					for(int i=0;i<m;i+=2) {
						as[n][i]=c;
						as[n][i+1]=c++;
						if(c>'z')c='a';
					}
					int mn=m/2;
					k-=mn;
					if(k>=0&&k%2==0&&k<=(n*m/2)) {
						ol("YES");
						construct1(n,m,k);
					}else {
						ol("NO");
						continue a;
					}
					

				}
				
				for(int i=0;i<as.length;i++) {
					for(int j=0;j<as[0].length;j++)out.print(as[i][j]);
					ol("");
				}
			}
			
		}

	private static void construct1(int n2, int m2, int k) {
			ArrayList<int[]>pts=new ArrayList<int[]>();
			for(int i=0;i<n2&&k>0;i+=2) {
				for(int j=0;j<m2&&k>0;j+=2) {
					fill(i,j);
					fill(i+1,j);
					k-=2;
				}
			}
			for(int i=0;i<n2;i+=2) {
				for(int j=0;j<m2;j++) {
					if(as[i][j]=='
						fill2(i,j);
					}
				}
			}
		}
	private static void fill2(int i, int j) {
		boolean v[]=new boolean[26];
		int[]dx=new int[] {0,-1,1,0,2,1};
		int[]dy=new int[] {-1,0,1,1,0,-1};
		for(int a=0;a<6;a++)
		{
			int nx=i+dx[a];
			int ny=j+dy[a];
			if(valid(nx,ny)&&as[nx][ny]!='
				v[as[nx][ny]-'a']=true;
			}
		}
		for(int a=0;a<26;a++) {
			if(!v[a]) {
				as[i][j]=(char) ('a'+a);
				as[i+1][j]=(char) ('a'+a);
				return;
			}
		}
	}
	private static void fill(int i, int j) {
		boolean v[]=new boolean[26];
		int[]dx=new int[] {0,1,-1,-1,1,0};
		int[]dy=new int[] {-1,0,0,1,1,2};
		for(int a=0;a<6;a++)
		{
			int nx=i+dx[a];
			int ny=j+dy[a];
			if(valid(nx,ny)&&as[nx][ny]!='
				v[as[nx][ny]-'a']=true;
			}
		}
		for(int a=0;a<26;a++) {
			if(!v[a]) {
				as[i][j]=(char) ('a'+a);
				as[i][j+1]=(char) ('a'+a);
				return;
			}
		}
	}
	private static boolean valid(int nx, int ny) {
		return nx>=0&&nx<as.length&&ny>=0&&ny<as[0].length;
	}
	private static int diff(int n, int g) {
			int idx=0,p=primes.get(0),tot=0;
			while(1l*p*p<=n) {
				int n1=0,n2=0;
				while(n%p==0) {
					n/=p;
					n1++;
				}
				while(g%p==0) {
					g/=p;
					n2++;
				}
				tot+=n1-n2;
				p=primes.get(++idx);
			}
			if(n!=g)tot++;
			return tot;
		}
	private static int fact(int n) {
			int idx=0,p=primes.get(0),tot=0;
			while(1l*p*p<=n) {
				while(n%p==0) {
					n/=p;tot++;
				}
				p=primes.get(++idx);
			}
			if(n!=1)tot++;
			return tot;
		}
	static void E() throws IOException {
		int t=ni();
		

		while(t-->0) {
			
		}
		
	}
	static HashSet<Integer> numDiv(int N)
	{
		int ans = 1, idx = 0, p = primes.get(0);
		HashSet<Integer>hs=new HashSet<Integer>();
		while(p * p <= N)
		{
			int e = 0;
			if(N%p==0)hs.add(p);
			while(N % p == 0) { N /= p; ++e; }
			ans *= (e + 1);
			p = primes.get(++idx);
		}
		if(N != 1) {
			ans <<= 1;
			hs.add(N);
		}
		
		return hs;
	}
	static void F() throws IOException {
		int t=ni();
		sieve(1000001);
		while(t-->0) {
			int n=ni();
			int[]a=nai(n);
			int g=0;
			for(int x:a) g=gcd(x,g);
			for(int i=0;i<n;i++)a[i]/=g;
			HashSet<Integer>fct[]=new HashSet[n];
			for(int i=0;i<n;i++)fct[i]=numDiv(a[i]);
			int ans=0;
			for(int i=0;i<n;i++) {
				for(int x:fct[i]) {
					int l=(i-1+n)%n,r=i;
					int cnt=0;
					while(fct[l].contains(x)) {
						fct[l].remove(x);
						l--;
						if(l<0)l=n-1;
						cnt++;
					}
					while(fct[r].contains(x)) {
						if(r!=i)
						fct[r].remove(x);
						r++;
						r%=n;
						cnt++;
					}
					ans=Math.max(ans, cnt);
					
				}
			}
			ol(ans);
			
			
		}
	}
	static int[]p,an,nv;
	static void G() throws IOException {
		int t=ni();
		while(t-->0) {
			int n=ni(),m=ni();
			adj=new ArrayList[n];
			for(int i=0;i<n;i++)adj[i]=new ArrayList<Integer>();
			for(int i=0;i<m;i++) {
				adj[ni()-1].add(ni()-1);
			}
			nv=new int[n];
			an=new int[n];
			p=new int[n];
			dfs(0);
			HashSet<Integer>adj2[]=new HashSet[n];
			for(int i=0;i<n;i++)adj2[i]=new HashSet<Integer>();
			
			for(int i=0;i<n;i++) {
				for(int x:adj[i])adj2[i].add(x);
			}
			for(int i=0;i<n;i++) {
				if(adj2[i].contains(i)&&nv[i]!=0) {
					

					for(int x:adj[i]) {
						an[x]=-1;
					}
				}
			}
			if(an[0]!=-1)an[0]=1;
			for(int x:an)out.print(x+" ");
			ol("");
		}
	}
	private static void dfs(int i) {
		nv[i]=1;
		for(int x:adj[i]) {
			if(nv[x]==0) {
				an[x]=1;
				p[x]=i;
				dfs(x);
			}else if(nv[x]==1&&an[x]!=-1) {
				p[x]=i;
				int lst=p[x];
				for(int v=x;p[v]!=x;v=p[v]) {
					an[v]=-1;
					lst=p[v];
				}
				an[lst]=-1;
			}else {
				if(an[x]!=-1)
					an[x]=2;
			}
		}
		nv[i]=2;
		
	}
	static long [][]d1,d2,map;
	static long W;
	static int []dx=new int[] {0,1,-1,0};
	static int []dy=new int[] {1,0,0,-1};

	private static void bfs(int i, int j,long[][]d) {
		d[i][j]=1;
		int[]q=new int[2*n*m];
		int e=0,s=0;
		q[e++]=i;q[e++]=j;
		while(s<e) {
			int x=q[s++],y=q[s++];
			for(int a=0;a<4;a++) {
				int nx=x+dx[a],ny=y+dy[a];
				if(nx>=0&&nx<n&&ny>=0&&ny<m&&d[nx][ny]==0&&map[nx][ny]!=-1) {
					q[e++]=nx;q[e++]=ny;
					d[nx][ny]=d[x][y]+1;
				}
			}
		}
		for(int a=0;a<d.length;a++)
			for(int b=0;b<d[0].length;b++)
				d[a][b]--;
		
	}
	static int ni() throws IOException {
		return sc.nextInt();
	}
	static double nd() throws IOException {
		return sc.nextDouble();
	}
	static long nl() throws IOException {
		return  sc.nextLong();
	}
	static String ns() throws IOException {
		return sc.next();
	}
	static int[] nai(int n) throws IOException {
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextInt();
		return a;
	}
	static long[] nal(int n) throws IOException {
		long[] a = new long[n];
		for (int i = 0; i < n; i++)
			a[i] = sc.nextLong();
		return a;
	}
	static int[][] nmi(int n,int m) throws IOException{
		int[][]a=new int[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=sc.nextInt();
			}
		}
		return a;
	}

	static long[][] nml(int n,int m) throws IOException{
		long[][]a=new long[n][m];
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				a[i][j]=sc.nextLong();
			}
		}
		return a;
	}
	static void o(String x) {
		out.print(x);
	}
	static void ol(String x) {
		out.println(x);
	}
	static void ol(int x) {
		out.println(x);
	}
	static void disp1(int []a) {
		for(int i=0;i<a.length;i++) {
			out.print(a[i]+" ");
		}
		out.println();
	}

	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public boolean hasNext() {return st.hasMoreTokens();}
		public int nextInt() throws IOException {return Integer.parseInt(next());}
		
		public double nextDouble() throws IOException {return Double.parseDouble(next());}
		
		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}
			
		public boolean ready() throws IOException {return br.ready(); }
		

	}
	static class id1 {

		long[]arr,seg,lazy;
		int N;
		long id4=(long)1e18,variant,pow;
		public id1(long[]a) {
			arr=a;
			N=a.length-1;
			seg=new long[2*N];
			lazy=new long[2*N];
			int tmp=N+1;
			while(tmp>0) {pow++;tmp>>=1;}
			build(1,1,N);
		}
		public int bst(int i, int x) {

			int idx=bst(1,1,N,i,N,x);
			return idx==-1?-1:idx-i;
		}
		private int bst(int node, int l, int r, int i, int j, int x) {
			if(l>j||r<i)return -1;
			if(l>=i&&r<=j) {
				int lv=l;
				if(seg[node]>=x)return -1;
				while(l!=r) {
					lv=l+r>>1;
					if(seg[node<<1|1]<x) {
						l=lv+1;
						node=node<<1|1;
					}else {
						r=lv;
						node=node<<1;
					}
				}
				return l;
			}
			int mid=l+r>>1;
			int right=bst(node<<1|1,mid+1,r,i,j,x);
			if(right!=-1)return right;
			return bst(node<<1,l,mid,i,j,x);
		
			

		}
		
		public void build(int node,int l,int r) {
			if(l==r) {seg[node]=get(l);return;}
			int mid=(l+r)/2;
			build(node<<1,l,mid);
			build(node<<1|1,mid+1,r);
			seg[node]=calc(seg[node<<1],seg[node<<1|1]);
		}
		private long get(int l) {
			return arr[l];
		}
		private long calc(long i, long j) {
			return Math.min(i, j);
		

		


		}
		public long query(int i,int j) {
			return query(1,1,N,i,j);
		}
		public long query(int node,int l,int r,int i,int j) {

			if(l>j||r<i)return (long)1e17;
			if(r<=j&&l>=i)return seg[node];
			int mid=l+r>>1;
			propagate(node, l, r);
			long left=query(node<<1,l,mid,i,j);
			long right=query(node<<1|1,mid+1,r,i,j);
			return calc(left,right);
		}
		public void updatePoint(int idx,int val) {
			int node=idx+N-1;
			arr[idx]=val;
			seg[node]=val;
			node>>=1;
			while(node>0) {
				seg[node]=calc(seg[node<<1],seg[node<<1|1]);
				node>>=1;
			}
		}
		void updateRange(int i,int j,int val) {
			updateRange(1, 1, N, i, j, val);
		}
		 void updateRange(int node,int l,int r,int i,int j,int val) {
				if(l>j||r<i)return ;
				if(l>=i&&r<=j) {
					seg[node]+=val;
					lazy[node]+=val;return;
				}
				int le=node<<1;
				int ri=node<<1|1,mid=l+r>>1;
				propagate(node, l, r);
				updateRange(le, l, mid, i, j, val);
				updateRange(ri, mid+1, r, i, j, val);
				seg[node]=calc(seg[le],seg[ri]);
		}
		void propagate(int node,int le,int ri) {
			int l=node<<1;
			int r=node<<1|1,mid=le+ri>>1;
			lazy[l]+=lazy[node];
			lazy[r]+=lazy[node];
			seg[l]+=lazy[node];
			seg[r]+=lazy[node];
			lazy[node]=0;
		}
	}
}
