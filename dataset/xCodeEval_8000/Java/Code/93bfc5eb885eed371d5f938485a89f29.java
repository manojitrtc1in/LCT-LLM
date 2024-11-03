import java.io.*;
import java.util.*;




import java.math.*;
import java.math.BigInteger;


public final class A
{    
	static PrintWriter out = new PrintWriter(System.out); 
	static StringBuilder ans=new StringBuilder();
	static FastReader in=new FastReader();
	

	static ArrayList<Integer> g[];
	static long mod=(long)1e9+7,INF=Long.MAX_VALUE;
	static boolean set[];
	static int max=0;
	static int lca[][];
	static int par[],col[],D[];
	static long fact[];
	static int size[],dp[][],countW[],countB[],N;
	static long sum[][],f[];
	static long t[],max_depth[];
	static boolean sep[],isWhite[];
	static boolean marked[],visited[],recStack[];
	static int segR[],segC[],seg[];
	static HashMap<Long,Integer> mp[];
	public static void main(String args[])throws IOException
	{	
		
		int T=i();
		outer:while(T-->0)
		{
			char X[]=in.next().toCharArray();
			int N=X.length;
			if(N%2!=0)out.println("NO");
			else
			{
				int c=0;
				int ques=0;
				for(char x:X)
				{
					if(x=='(')c++;
					else if(x==')')c--;
					else ques++;
					if(c+ques<0)
					{
						out.println("NO");
						continue outer;
					}
				}
				c=0;
				int a=0,b=0;
				for(char x:X)
				{
					if(x=='(')a++;
					else if(x==')')b++;
					else
					{
						c++;
					}
				}
				int open=(N/2)-a;
				int close=(N/2)-b;


				if(open==0 || close==0)
				{
					out.println("YES");
					continue outer;
				}
				int last=-1,first=-1;
				for(int i=0; i<N; i++)
				{
					if(X[i]=='?')
					{
						if(open>=1) 
						{
							open--;
							X[i]='(';
							last=i;
						}
						else 
						{
							if(first==-1)first=i;
							X[i]=')';
						}
						
					}
				}




				char t=X[first];
				X[first]=X[last];
				X[last]=t;
				c=0;
				for(char x:X)
				{
					if(x=='(')c++;
					else c--;
					if(c<0)
					{
						out.println("YES");
						continue outer;
					}
				}
				out.println("NO");




			}
		}
		out.println(ans);
		out.close();





	}
	static void calculatePre(long A[][],int N,int M)
	{
		for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=M; j++)A[i][j]+=A[i][j-1];
		}
		for(int j=1; j<=M; j++)
		{
			for(int i=2; i<=N; i++)A[i][j]+=A[i-1][j];
		}
	}
	static boolean equals(char X[],char Y[])
	{
		for(int i=0; i<X.length; i++)if(X[i]!=Y[i])return false;
		return true;
	}
	static long nCr(long n,long r)
	{
		long s=0;
		long c=n-r;
		n=fact[(int)n];
		r=fact[(int)r];
		c=fact[(int)c];
		r=pow(r,mod-2)%mod;
		c=pow(c,mod-2)%mod;
		s=(r*c)%mod;
		s=(s*n)%mod;
		return s%mod;
	}
	static boolean isValid(int x,int y,int N,int M)
	{
		if(x>=N || y>=M)return false;
		if(x<0 || y<0)return false;
		return true;
	}
	static int f2(int n,int p)
	{
		ArrayList<Integer> X=new ArrayList<>();
		for(int c:g[n])
		{
			if(c!=p)
			{
				X.add(c);
			}
		}
		

		if(X.size()==0)return 0;
		if(X.size()==1)return size[n]-1;
		int a=X.get(0),b=X.get(1);
		

		return Math.max(size[a]+f2(b,n), size[b]+f2(a,n));
		

	}
	static void f(int n,int p)
	{
		for(int c:g[n])
		{
			if(c!=p)
			{
				f(c,n);
				size[n]+=size[c]+1;
			}
		}
		

	}
	static boolean isPower(long a,long b)
	{
		while(a%b==0)
		{

		}
		return a==1;
	}
	static String rotate(String X,int K)
	{
		StringBuilder sb=new StringBuilder();
		int N=X.length();
		int k=K%N;
		for(int i=N-k; i<N;i++)
		{
			sb.append(X.charAt(i));
		}
		for(int i=0; i<N-k; i++)
		{
			sb.append(X.charAt(i));
		}

		return sb.toString();
	}
	static int rounds(String X,String Y)
	{
		int n=Y.length();
		for(int i=1; i<Y.length(); i++)
		{
			if(X.charAt(0)==Y.charAt(0) && X.substring(i,i+n).equals(Y))return i;
		}
		return Y.length();
	}
	static int index(ArrayList<Long> X,long x)
	{
		int l=-1,r=X.size();
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(X.get(m)<=x)l=m;
			else r=m;
		}

		return l+1;
	}
	static void swap(int i,int j,long A[][])
	{
		for(int row=0; row<A.length; row++)
		{
			long t=A[row][i];
			A[row][i]=A[row][j];
			A[row][j]=t;
		}
	}
	static boolean isSorted(long A[])
	{
		for(int i=1; i<A.length; i++)if(A[i]<A[i-1])return false;
		return true;
	}
	static void dfs(int node,  int dp[],
			boolean visited[],long A[],long a)
	{
		

		visited[node] = true;
		

		for (int c:g[node]) 
		{

			

			if (A[c-1]<=a && !visited[c])
				dfs(c, dp, visited,A,a);

			

			dp[node] = Math.max(dp[node], 1 + dp[c]);
		}
	}
	static int findLongestPath( int n,long A[],long a)
	{
		

		int[] dp = new int[n+1];

		

		

		boolean[] visited = new boolean[n + 1];

		

		for (int i = 1; i <= n; i++) 
		{
			if (A[i-1]<=a && !visited[i])
				dfs(i, dp, visited,A,a);
		}

		int ans = 0;

		

		for (int i = 1; i <= n; i++) 
		{
			ans = Math.max(ans, dp[i]);
		}
		return ans;
	}
	static boolean isCyclicUtil(int n, boolean[] visited,
			boolean[] recStack,long A[],long a) 
	{

		if (recStack[n])
			return true;

		if (visited[n])
			return false;

		visited[n] = true;

		recStack[n] = true;


		for (int c: g[n])
		{
			if(A[c-1]<=a )
			{
				if (isCyclicUtil(c, visited, recStack,A,a))
					return true;
			}
		}

		recStack[n] = false;

		return false;
	}
	static void push(int v) {
		if (marked[v]) {
			t[v*2] = t[v*2+1] = t[v];
			marked[v*2] = marked[v*2+1] = true;
			marked[v] = false;
		}
	}

	static void update1(int v, int tl, int tr, int l, int r, int new_val) {
		if (l > r) 
			return;
		if (l == tl && tr == r) {
			t[v] = new_val;
			marked[v] = true;
		} else {
			push(v);
			int tm = (tl + tr) / 2;
			update1(v*2, tl, tm, l, Math.min(r, tm), new_val);
			update1(v*2+1, tm+1, tr, Math.max(l, tm+1), r, new_val);
		}
	}

	static long get1(int v, int tl, int tr, int pos) {
		if (tl == tr) {
			return t[v];
		}
		push(v);
		int tm = (tl + tr) / 2;
		if (pos <= tm) 
			return get1(v*2, tl, tm, pos);
		else
			return get1(v*2+1, tm+1, tr, pos);
	}
	static int cost=0;
	static void fmin(int i,int j,ArrayList<Integer> A,int cZ,int cO)
	{
		if(j-i>1)
		{
			int a=A.get(i),b=A.get(j);
			cO+=Math.min(a, b);
			if(a<b)
			{

			}
			else if(b>a)
			{

			}
			else
			{

			}
		}
	}
	static void fs(int n,int p)
	{
		if(isWhite[n])countW[n]=1;
		else countB[n]=1;
		for(int c:g[n])
		{
			if(c!=p)
			{
				fs(c,n);
				countB[n]+=countB[c];
				countW[n]+=countW[c];
			}
		}
	}
	static int f(char X[],char Y[])
	{
		int s=0;
		for(int i=0; i<Y.length; i++)
		{
			s+=Math.abs(X[i]-Y[i]);
		}
		return s;
	}
	public static long  mergeSort(int A[],int l,int r)
	{
		long a=0;
		if(l<r)
		{
			int m=(l+r)/2;
			a+=mergeSort(A,l,m);
			a+=mergeSort(A,m+1,r);
			a+=merge(A,l,m,r);
		}
		return a;
	}
	public  static long merge(int A[],int l,int m,int r)
	{
		long a=0;
		int i=l,j=m+1,index=0;
		long c=0;
		int B[]=new int[r-l+1];
		while(i<=m && j<=r)
		{
			if(A[i]<=A[j])
			{
				c++;
				B[index++]=A[i++];
			}
			else
			{
				long s=(m-l)+1;
				a+=(s-c);
				B[index++]=A[j++];
			}
		}

		while(i<=m)B[index++]=A[i++];
		while(j<=r)B[index++]=A[j++];
		index=0;
		for(; l<=r; l++)A[l]=B[index++];
		return a;
	}
	static int f(int A[])
	{
		int s=0;
		for(int i=1; i<4; i++)
		{
			s+=Math.abs(A[i]-A[i-1]);
		}
		return s;
	}
	static boolean f(int A[],int B[],int N)
	{
		for(int i=0; i<N; i++)
		{
			if(Math.abs(A[i]-B[i])>1)return false;
		}
		return true;
	}


	static int [] prefix(char  s[],int N) {
		

		

		N=s.length;
		int pi[]=new int[N];
		for (int i = 1; i < N; i++) {
			int j = pi[i-1];
			while (j > 0 && s[i] != s[j])
				j = pi[j-1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
		}
		return pi;
	}

	static int count(long N)
	{
		int cnt=0;
		long p=1L;
		while(p<=N)
		{
			if((p&N)!=0)cnt++;
			p<<=1;
		}
		return cnt;
	}
	static long kadane(long A[])
	{
		long lsum=A[0],gsum=0;
		gsum=Math.max(gsum, lsum);
		for(int i=1; i<A.length; i++)
		{
			lsum=Math.max(lsum+A[i],A[i]);
			gsum=Math.max(gsum,lsum);
		}
		return gsum;
	}


	public static void reverse(int i,int j,int A[])
	{
		while(i<j)
		{
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
			i++;
			j--;
		}
	}
	public  static int ask(int a,int b,int c)
	{
		System.out.println("? "+a+" "+b+" "+c);
		return i();
	}
	static int[] reverse(int A[],int N)
	{
		int B[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			B[N-i-1]=A[i];
		}
		return B;	
	}
	static boolean isPalin(char X[])
	{
		int i=0,j=X.length-1;
		while(i<=j)
		{
			if(X[i]!=X[j])return false;
			i++;
			j--;
		}
		return true;
	}

	static  int distance(int a,int b)
	{
		int d=D[a]+D[b];
		int l=LCA(a,b);
		l=2*D[l];
		return d-l;
	}
	static int LCA(int a,int b)
	{
		if(D[a]<D[b])
		{
			int t=a;
			a=b;
			b=t;
		}
		int d=D[a]-D[b];
		int p=1;
		for(int i=0; i>=0 && p<=d; i++)
		{
			if((p&d)!=0)
			{
				a=lca[a][i];
			}
			p<<=1;
		}
		if(a==b)return a;
		for(int i=max-1; i>=0; i--)
		{
			if(lca[a][i]!=-1 && lca[a][i]!=lca[b][i])
			{
				a=lca[a][i];
				b=lca[b][i];
			}
		}
		return lca[a][0];

	}

	static void dfs(int n,int p)
	{
		lca[n][0]=p;
		if(p!=-1)D[n]=D[p]+1;
		for(int c:g[n])
		{
			if(c!=p)
			{

				dfs(c,n);

			}
		}
	}

	static int[] prefix_function(char X[])

	{
		int N=X.length;
		int pre[]=new int[N];
		for(int i=1; i<N; i++)
		{
			int j=pre[i-1];
			while(j>0 && X[i]!=X[j])
				j=pre[j-1];
			if(X[i]==X[j])j++;
			pre[i]=j;
		}
		return pre;
	}


	static TreeNode start;
	public static void f(TreeNode root,TreeNode p,int r)
	{
		if(root==null)return;
		if(p!=null)
		{
			root.par=p;
		}
		if(root.val==r)start=root;
		f(root.left,root,r);
		f(root.right,root,r);
	}


	static int right(int A[],int Limit,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<Limit)l=m;
			else r=m;
		}
		return l;
	}
	static int left(int A[],int a,int l,int r)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]<a)l=m;
			else r=m;
		}
		return l;
	}

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	static void build(int v,int tl,int tr,int A[])
	{
		if(tl==tr)
		{
			seg[v]=A[tl];
			return;
		}
		int tm=(tl+tr)/2;
		build(v*2,tl,tm,A);
		build(v*2+1,tm+1,tr,A);
		seg[v]=seg[v*2]+seg[v*2+1];
	}
	static void update(int v,int tl,int tr,int index,int a)
	{
		if(index==tl && tl==tr)
		{
			seg[v]++;
			seg[v]%=2;
		}
		else
		{
			int tm=(tl+tr)/2;
			if(index<=tm)update(2*v,tl,tm,index,a);
			else update(2*v+1,tm+1,tr,index,a);
			seg[v]=seg[v*2]+seg[v*2+1];
		}
	}
	static int ask(int v,int tl,int tr,int k)
	{
		if(tl==tr)return tl;
		int tm=(tl+tr)/2;
		if(seg[v*2]>=k)
		{

			return ask(v*2,tl,tm,k);
		}
		return ask(v*2+1,tm+1,tr,k-seg[v*2]);
	}
	static int ask(int v,int tl,int tr,int l,int r)
	{
		if(l>r)return 0;
		if(tl==l && tr==r)return seg[v];
		int tm=(tl+tr)/2;
		return ask(v*2,tl,tm,l,Math.min(tm,r))+ask(v*2+1,tm+1,tr,Math.max(l, tm+1),r);
	}
	static void updateC(int v,int tl,int tr,int index)
	{
		if(index==tl && index==tr)
		{
			segC[v]+=1;
			segC[v]%=2;
		}
		else
		{
			int tm=(tl+tr)/2;
			if(index<=tm)updateC(v*2,tl,tm,index);
			else updateC(v*2+1,tm+1,tr,index);
			segC[v]=segC[v*2]+segC[v*2+1];
		}
	}
	static int askC(int v,int tl,int tr,int l,int r)
	{

		if(l>r)return 0;
		if(tl==l && r==tr)
		{
			return segC[v];
		}
		int tm=(tl+tr)/2;

		return askC(v*2,tl,tm,l,Math.min(tm, r))+askC(v*2+1,tm+1,tr,Math.max(tm+1, l),r);
	}
	static boolean f(long A[],long m,int N)
	{
		long B[]=new long[N];
		for(int i=0; i<N; i++)
		{
			B[i]=A[i];
		}
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<m)return false;
			if(i>=2)
			{
				long extra=Math.min(B[i]-m, A[i]);
				long x=extra/3L;
				B[i-2]+=2L*x;
				B[i-1]+=x;
			}
		}
		return true;
	}
	static int f(int l,int r,long A[],long x)
	{
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(A[m]>=x)l=m;
			else r=m;
		}
		return r;

	}
	static boolean f(long m,long H,long A[],int N)
	{
		long s=m;
		for(int i=0; i<N-1;i++)
		{
			s+=Math.min(m, A[i+1]-A[i]);
		}
		return s>=H;
	}

	static long ask(long l,long r)
	{
		System.out.println("? "+l+" "+r);
		return l();
	}
	static long f(long N,long M)
	{
		long s=0;
		if(N%3==0)
		{
			N/=3;
			s=N*M;
		}
		else
		{
			long b=N%3;
			N/=3;
			N++;
			s=N*M;
			N--;
			long a=N*M;
			if(M%3==0)
			{
				M/=3;
				a+=(b*M);
			}
			else
			{
				M/=3;
				M++;
				a+=(b*M);
			}
			s=Math.min(s, a);
		}
		return s;
	}
	static int ask(StringBuilder sb,int a)
	{
		System.out.println(sb+""+a);
		return i();
	}
	static void swap(char X[],int i,int j)
	{
		char x=X[i];
		X[i]=X[j];
		X[j]=x;
	}
	static int min(int a,int b,int c)
	{
		return Math.min(Math.min(a, b), c);
	}


	static long and(int i,int j)
	{
		System.out.println("and "+i+" "+j);
		return l();
	}
	static long or(int i,int j)
	{
		System.out.println("or "+i+" "+j);
		return l();
	}
	static int len=0,number=0;
	static void f(char X[],int i,int num,int l)
	{
		if(i==X.length)
		{
			if(num==0)return;
			

			if(isPrime(num))return;
			if(l<len)
			{
				len=l;
				number=num;				
			}
			return;
		}
		int a=X[i]-'0';
		f(X,i+1,num*10+a,l+1);
		f(X,i+1,num,l);
	}
	static boolean is_Sorted(int A[])
	{
		int N=A.length;
		for(int i=1; i<=N; i++)if(A[i-1]!=i)return false;
		return true;
	}
	static boolean f(StringBuilder sb,String Y,String order)
	{
		StringBuilder res=new StringBuilder(sb.toString());
		HashSet<Character> set=new HashSet<>();
		for(char ch:order.toCharArray())
		{
			set.add(ch);
			for(int i=0; i<sb.length(); i++)
			{
				char x=sb.charAt(i);
				if(set.contains(x))continue;
				res.append(x);
			}
		}

		String str=res.toString();
		return str.equals(Y);
	}
	static boolean all_Zero(int f[])
	{
		for(int a:f)if(a!=0)return false;
		return true;
	}
	static long form(int a,int l)
	{
		long x=0;
		while(l-->0)
		{
			x*=10;
			x+=a;
		}
		return x;
	}
	static int count(String X)
	{
		HashSet<Integer> set=new HashSet<>();
		for(char x:X.toCharArray())set.add(x-'0');
		return set.size();
	}

	static int f(long K)
	{
		long l=0,r=K;
		while(r-l>1)
		{
			long m=(l+r)/2;
			if(m*m<K)l=m;
			else r=m;
		}
		return (int)l;
	}


	static int [] sub(int A[],int B[])
	{
		int N=A.length;
		int f[]=new int[N];
		for(int i=N-1; i>=0; i--)
		{
			if(B[i]<A[i])
			{
				B[i]+=26;
				B[i-1]-=1;
			}
			f[i]=B[i]-A[i];
		}
		for(int i=0; i<N; i++)
		{
			if(f[i]%2!=0)f[i+1]+=26;
			f[i]/=2;
		}
		return f;
	}
	static int[] f(int  N)
	{
		char X[]=in.next().toCharArray();
		int A[]=new int[N];
		for(int i=0; i<N; i++)A[i]=X[i]-'a';
		return A;
	}




	static int max(int a ,int b,int c,int d)
	{
		a=Math.max(a, b);
		c=Math.max(c,d);
		return Math.max(a, c);
	}
	static int min(int a ,int b,int c,int d)
	{
		a=Math.min(a, b);
		c=Math.min(c,d);
		return Math.min(a, c);
	}



	static HashMap<Integer,Integer> Hash(int A[])
	{
		HashMap<Integer,Integer> mp=new HashMap<>();
		for(int a:A)
		{
			int f=mp.getOrDefault(a,0)+1;
			mp.put(a, f);
		}
		return mp;
	}
	static long mul(long a, long b)
	{
		return ( a %mod * 1L * b%mod )%mod;
	}
	static void swap(int A[],int a,int b)
	{
		int t=A[a];
		A[a]=A[b];
		A[b]=t;
	}


	static int find(int a)
	{
		if(par[a]<0)return a;
		return par[a]=find(par[a]);
	}
	static void union(int a,int b)
	{
		a=find(a);
		b=find(b);
		if(a!=b)
		{
			if(par[a]>par[b]) 

			{
				int t=b;
				b=a;
				a=t;
			}
			par[a]+=par[b];
			par[b]=a;
		}
	}
	static boolean isSorted(int A[])
	{
		for(int i=1; i<A.length; i++)
		{
			if(A[i]<A[i-1])return false;
		}
		return true;
	}

	static boolean isDivisible(StringBuilder X,int i,long num)
	{
		long r=0;
		for(; i<X.length(); i++)
		{
			r=r*10+(X.charAt(i)-'0');
			r=r%num;
		}
		return r==0;
	}    



	static int lower_Bound(int A[],int low,int high, int x) 
	{ 
		if (low > high) 
			if (x >= A[high]) 
				return A[high]; 

		int mid = (low + high) / 2; 

		if (A[mid] == x) 
			return A[mid]; 

		if (mid > 0 && A[mid - 1] <= x && x < A[mid]) 
			return A[mid - 1]; 

		if (x < A[mid]) 
			return lower_Bound( A, low, mid - 1, x); 

		return lower_Bound(A, mid + 1, high, x); 
	} 

	static String f(String A)
	{
		String X="";
		for(int i=A.length()-1; i>=0; i--)
		{
			int c=A.charAt(i)-'0';
			X+=(c+1)%2;
		}
		return X;
	}
	static void sortR(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		int N=a.length;
		for (int i=0; i<a.length; i++) a[i]=l.get(N-i-1);
	}
	static void sort(long[] a) 

	{
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static String swap(String X,int i,int j)
	{
		char ch[]=X.toCharArray();
		char a=ch[i];
		ch[i]=ch[j];
		ch[j]=a;
		return new String(ch);
	}

	static int sD(long n)  
	{  

		if (n % 2 == 0 )  
			return 2;  

		for (int i = 3; i * i <= n; i += 2) {  
			if (n % i == 0 )  
				return i;  
		}  

		return (int)n;  
	}  

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	




	static  long pow(long a,long b)
	{
		

		long pow=1;
		long x=a;
		while(b!=0)
		{
			if((b&1)!=0)pow=(pow*x)%mod;
			x=(x*x)%mod;
			b/=2;
		}
		return pow;
	}

	static long toggleBits(long x)

	{
		int n=(int)(Math.floor(Math.log(x)/Math.log(2)))+1;

		return ((1<<n)-1)^x;
	}

	static int countBits(long a)
	{
		return (int)(Math.log(a)/Math.log(2)+1);
	}

	static long fact(long N)
	{ 
		long n=2; 
		if(N<=1)return 1;
		else
		{
			for(int i=3; i<=N; i++)n=(n*i)%mod;
		}
		return n;
	}


	static void sort(int[] a) {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

	static boolean isPrime(long N)
	{
		if (N<=1)  return false; 
		if (N<=3)  return true; 
		if (N%2 == 0 || N%3 == 0) return false; 
		for (int i=5; i*i<=N; i=i+6) 
			if (N%i == 0 || N%(i+2) == 0) 
				return false; 
		return true; 
	}
	static void print(char A[])
	{
		for(char c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(boolean A[])
	{
		for(boolean c:A)System.out.print(c+" ");
		System.out.println();
	}
	static void print(int A[])
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();	
	}
	static void print(long A[])
	{
		for(long i:A)System.out.print(i+ " ");
		System.out.println();

	}
	static void print(boolean A[][])
	{
		for(boolean a[]:A)print(a);
	}
	static void print(long A[][])
	{
		for(long a[]:A)print(a);
	}
	static void print(int A[][])
	{
		for(int a[]:A)print(a);
	}
	static void print(ArrayList<Integer> A)
	{
		for(int a:A)System.out.print(a+" ");
		System.out.println();
	}

	static int i()
	{
		return in.nextInt();
	}

	static long l()
	{
		return in.nextLong();
	}

	static int[] input(int N){
		int A[]=new int[N];
		for(int i=0; i<N; i++)
		{
			A[i]=in.nextInt();
		}
		return A;
	}

	static long[] inputLong(int N)     {
		long A[]=new long[N];
		for(int i=0; i<A.length; i++)A[i]=in.nextLong();
		return A;
	}

	static long GCD(long a,long b) 
	{
		if(b==0)
		{
			return a;
		}
		else return GCD(b,a%b );
	}

}


class node 
{
	long pref,suff,max,sum,min;
	node(long a,long b,long c,long d)
	{
		pref=a;
		suff=b;
		max=c;
		sum=d;
		min=Long.MIN_VALUE;
	}
	node(long a,long b,long c,long d,long e)
	{
		pref=a;
		suff=b;
		max=c;
		sum=d;
		min=e;
	}
}
class project implements Comparable<project>
{
	int score,index;

	project(int s,int i)
	{
		

		index=i;
		score=s;
		

		

	}
	public int compareTo(project x)
	{
		return x.score-this.score;
	}
}
class post implements Comparable<post>
{
	long x,y,d,t;
	post(long a,long b,long c)
	{
		x=a;
		y=b;
		d=c;
	}
	public int compareTo(post X)
	{
		if(X.t==this.t)
		{
			return 0;
		}
		else
		{
			long xt=this.t-X.t;
			if(xt>0)return 1;
			return -1;
		}
	}
}
class TreeNode
{
	int val;
	TreeNode left, right,par;
	TreeNode() {}
	TreeNode(int item)
	{
		val = item;
		left =null;
		right = null;
		par=null;
	}
}

class pair implements Comparable<pair>
{
	int l,r,index;
	pair(int a,int b,int i)
	{
		l=a;
		r=b;
		index=i;
	}
	public int compareTo(pair x)
	{
		if(this.r==x.r)return this.l-x.l;
		return this.r-x.r;
	}
}








class FastReader
{
	BufferedReader br;
	StringTokenizer st;
	public FastReader()
	{
		br=new BufferedReader(new InputStreamReader(System.in));
	}

	String next()
	{
		while(st==null || !st.hasMoreElements())
		{
			try
			{
				st=new StringTokenizer(br.readLine());
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int nextInt()
	{
		return Integer.parseInt(next());
	}

	long nextLong()
	{
		return Long.parseLong(next());
	}

	double nextDouble()
	{
		return Double.parseDouble(next());
	}
	

	String nextLine()
	{
		String str="";
		try
		{
			str=br.readLine();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
		return str;
	}

}