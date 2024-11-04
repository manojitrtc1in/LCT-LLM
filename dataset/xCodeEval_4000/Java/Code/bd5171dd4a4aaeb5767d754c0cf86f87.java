import java.io.*;
import java.io.IOException;
import java.math.BigInteger;
import java.util.*;








	

	








		
	public  class Codeforces {
		
			
			public static long mod = 1000000007 ;
			public static double epsilon=0.00000000008854;

			public static InputReader sc = new InputReader(System.in);
			public static PrintWriter pw = new PrintWriter(System.out);
			
			public static int[] GetLps(String s){
				int n=s.length();
				int a[]=new int[n];
				int j=0;
				for(int i=1;i<n;i++){
					if(s.charAt(i)==s.charAt(j)){
						j++;
						a[i]=j;
					}
					else if(j>0){
						while(j>0&&s.charAt(i)!=s.charAt(j)){
							j=a[--j];
						}
						if(s.charAt(i)==s.charAt(j))
						a[i]=++j;
					}
				}
				

		
				return a;
		


			}
			
			
		   public static long cal(int val,int a[],int m){
			long moves=0;
			

			for(int j=0;j<a.length;j++){
				moves+=Math.min(Math.abs(a[j]-val), m-Math.abs(a[j]-val));
			}
			return moves;
		   }
		   public static int binary1(int start,int end,int val,int m,int a[]){
			   int l=start;
			   int r=end;
			   int ans=0;
			   
			   while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]-val<=m-a[mid]+val){
					ans=mid;
					l=mid+1;
				}
				else r=mid-1;
			   }
			   return ans;
		   }
		   public static int binary2(int start,int end,int val,int m,int a[]){
			int l=start;
			int r=end;
			int ans=0;
			
			while(l<=r){
			 int mid=(l+r)/2;
			 if(val-a[mid]<=m+a[mid]-val){
				 ans=mid;
				 r=mid-1;
			 }
			 else l=mid+1;
			}
			return ans;
		}
		public static int firstNode(int a,int p[]){
			if(a!=p[a]){
				p[a]=firstNode(p[a], p);
			}
			return p[a];
		}
		public static void Union(int a,int b,int p[]){
			 a=firstNode(a, p);
			 b=firstNode(b, p);
			
			if(a!=b)
			p[a]=b;

		}
		
		public static long pow(long x,long y,long mod){
			long ans=1;
			
			x%=mod;
			while(y>0){
				if((y&1)==1){
					ans=(ans*x)%mod;
				}
				y=y>>1;
				x=(x*x)%mod;
			}
			return ans;
		}
		public static long[][] multiply(long a[][], long b[][]) 
    { 
        long mul[][] = new long[a.length][b[0].length]; 
        for (int i = 0; i < a.length; i++) 
        { 
            for (int j = 0; j < b[0].length; j++) 
            { 
                mul[i][j] = 0; 
                for (int k = 0; k < a[0].length; k++) 
                    mul[i][j] += (a[i][k] * b[k][j])%mod;
                    mul[i][j] %= mod;
            } 
        } 
      
        return mul;
    
    } 
      
    public static long[][] power(long F[][], long n) 
    { 
        
    	long[][] result = new long[F.length][F.length];
    	for(int i=0; i<F.length; i++)
    		result[i][i] = 1;
    	
    	
    	while (n > 0) {
			if (n % 2 == 1)
				result = multiply(result, F);
			
			F = multiply(F, F);
			n = n / 2;
			

		}
    	return result;
	}
		   public static long brute(int n){
			   long dp[][]=new long[n][4];
			   dp[0][0]=1;
			   dp[0][1]=2;
			   dp[0][2]=2;
			   dp[0][3]=1;
			   long pre=6;
			   for(int i=1;i<n;i++){
				   long x=pow(2, 2*(i-1), mod);
				dp[i][0]=pre+1*x;
				dp[i][1]=pre+4*x;
				dp[i][2]=pre+4*x;
				dp[i][3]=pre+1*x;
				pre=dp[i][0]+dp[i][1]+dp[i][2]+dp[i][3];
				pre%=mod;
			   }
			   return pre;
		   }
		   public static ArrayList<ArrayList <Integer>> GetGraph(int n,int m){
			ArrayList<ArrayList <Integer>> a=new ArrayList<>();
			for(int i=0;i<n;i++){
				a.add(new ArrayList<>());
			}
			for(int i=0;i<m;i++){
				int u=sc.nextInt()-1;
				int v=sc.nextInt()-1;
				a.get(u).add(v);
				a.get(v).add(u);
			} 
			return a;
		}
		public static int getPer(ArrayList<ArrayList <Integer>> g1,ArrayList<ArrayList <Integer>> g2,int x,int y,int p[]){
			int n=g1.size();
			

			p[x]=y;
			int vis2[]=new int[n];
			int vis1[]=new int[n];
			vis2[y]=1;vis1[x]=1;
			Deque<Integer> q=new LinkedList<>();
			int c=0;
			q.add(x);
			while(q.size()>0){
				int r1=q.remove();
				int r2=p[r1];
				int m1=g1.get(r1).size();
				int m2=g2.get(r2).size();

				

				for(int i=0,j=0;i<m1&&j<m2;i++,j++){
					int v1=g1.get(r1).get(i);
					int v2=g2.get(r2).get(j);
					while(i<m1&&vis1[v1]==1){
						i++;
						if(i<m1)
						v1=g1.get(r1).get(i);
					}
					while(j<m2&&vis2[v2]==1){
						j++;
						if(j<m2)
						v2=g2.get(r2).get(j);
					}
					if(i>=m1||j>=m2)
					continue;
					q.add(v1);
					p[v1]=v2;
					vis1[v1]=1;
					vis2[v2]=1;
					c++;
				}
			}
			ArrayList<Integer> h1=new ArrayList<>();
			ArrayList<Integer> h2=new ArrayList<>();
			for(int i=0;i<n;i++){
				if(vis1[i]==0)h1.add(i);
				if(vis2[i]==0)h2.add(i);
			}
			int j=0;
			for(int i : h1){
				p[i]=h2.get(j++);
			}
			return c;


		}
		
			public static void main(String[] args) throws Exception {
				


				int q=sc.nextInt();
				while(q-->0){
					int n=sc.nextInt();
					int m=sc.nextInt();
					int a[]=scanArray(n);
					Arrays.sort(a);
					int sum=0;
					for(int i=0;i<n;i++){
						sum+=a[i];
					}
					if(sum==m)pw.println("YES");
					else pw.println("NO");
				}

				

				
				
				

				pw.flush();
				pw.close();
			}
			public static Comparator<Integer[]> MOquery(int block){
				return
				new Comparator<Integer[]>(){
					@Override
					public int compare(Integer a[],Integer b[]){
						int a1=a[0]/block;
						int b1=b[0]/block;
						if(a1==b1){
							if((a1&1)==1)
							return a[1].compareTo(b[1]);
							else{
								return b[1].compareTo(a[1]);
							}
						}
						return a1-b1;
					}
				};
			}
		
			public static Comparator<Long[]> column(int i){
				return 
				new Comparator<Long[]>() {
					@Override
					public int compare(Long[] o1, Long[] o2) {
						return o1[i].compareTo(o2[i]);

						

					}
				};
			}
			public static Comparator<Integer[]> column(){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						

						

						
						for(int i=0;i<o1.length;i++){
							if(o1[i].compareTo(o2[i])!=0)
							return o1[i].compareTo(o2[i]);
						}
						return 0;
					}
				};
			}
			public static Comparator<Integer[]> column2(){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						

						

						int l1=0,l2=0;
						for(int i=0;i<o1.length-1;i++){
							l1+=o1[i];
							l2+=o2[i];
						}
						return l2-l1;
					}
				};
			}
			public static Comparator<Integer[]> dis(int k,Integer a[][]){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						

						

						int l1=0,l2=0;
						for(int i=0;i<o1.length-1;i++){
							l1+=Math.abs(a[k][i]-o1[i]);
							l2+=Math.abs(a[k][i]-o2[i]);
						}
						return l2-l1;
					}
				};
			}
			public static Comparator<Integer[]> col(int i){
				return 
				new Comparator<Integer[]>() {
					@Override
					public int compare(Integer[] o1, Integer[] o2) {
						

						return o1[i].compareTo(o2[i]);

						

						

					}
				};
			}
			public static Comparator<Integer> des(){
				return 
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						

						return o2.compareTo(o1);

					}
				};
			}
			public static Comparator<Integer> des(int dp[]){
				return 
				new Comparator<Integer>() {
					@Override
					public int compare(Integer o1, Integer o2) {
						

						return dp[o2]-dp[o1];

					}
				};
			}
			
			
			
			
			public static String reverseString(String s){
				StringBuilder input1 = new StringBuilder(); 
				input1.append(s);  
				input1 = input1.reverse();
				return input1.toString();
			}
			public static int[] scanArray(int n){
				int a[]=new int [n];
				

				for(int i=0;i<n;i++){
					a[i]=sc.nextInt();
				}
				
		
				return a;
			}
			public static long[] scanLongArray(int n){
				long a[]=new long [n];
				for(int i=0;i<n;i++)
				a[i]=sc.nextLong();
		
				return a;
			}
			public static String [] scanStrings(int n){
				String a[]=new String [n];
				for(int i=0;i<n;i++)
				a[i]=sc.nextLine();
		
				return a;
			}
			public static class InputReader {
		
				private final InputStream stream;
				private final byte[] buf = new byte[8192];
				private int curChar, snumChars;
				private SpaceCharFilter filter;
		
				public InputReader(InputStream stream) {
					this.stream = stream;
				}
		
				public int snext() {
					if (snumChars == -1)
						throw new InputMismatchException();
					if (curChar >= snumChars) {
						curChar = 0;
						try {
							snumChars = stream.read(buf);
						} catch (IOException e) {
							throw new InputMismatchException();
						}
						if (snumChars <= 0)
							return -1;
					}
					return buf[curChar++];
				}
		
				public int nextInt() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					int sgn = 1;
					if (c == '-') {
						sgn = -1;
						c = snext();
					}
					int res = 0;
					do {
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						res *= 10;
						res += c - '0';
						c = snext();
					} while (!isSpaceChar(c));
					return res * sgn;
				}
		
				public long nextLong() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					int sgn = 1;
					if (c == '-') {
						sgn = -1;
						c = snext();
					}
					long res = 0;
					do {
						if (c < '0' || c > '9')
							throw new InputMismatchException();
						res *= 10;
						res += c - '0';
						c = snext();
					} while (!isSpaceChar(c));
					return res * sgn;
				}
		
				public int[] nextIntArray(int n) {
					int a[] = new int[n];
					for (int i = 0; i < n; i++) {
						a[i] = nextInt();
					}
					return a;
				}
		
				public String readString() {
					int c = snext();
					while (isSpaceChar(c)) {
						c = snext();
					}
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!isSpaceChar(c));
					return res.toString();
				}
		
				public String nextLine() {
					int c = snext();
					while (isSpaceChar(c))
						c = snext();
					StringBuilder res = new StringBuilder();
					do {
						res.appendCodePoint(c);
						c = snext();
					} while (!isEndOfLine(c));
					return res.toString();
				}
		
				public boolean isSpaceChar(int c) {
					if (filter != null)
						return filter.isSpaceChar(c);
					return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
				}
		
				private boolean isEndOfLine(int c) {
					return c == '\n' || c == '\r' || c == -1;
				}
		
				public interface SpaceCharFilter {
					public boolean isSpaceChar(int ch);
				}
			}
			
		}
		class SegmentTree{

			int s[],n;
			SegmentTree(int a[]){
				n=a.length;
				int l=(int)Math.ceil(Math.log(n)/Math.log(2));
				l=2*(int)Math.pow(2,l)-1;
				s=new int[l];
				

			}
			
			int createSegmentTreeUtil(int a[],int root,int l,int r){
				if(l==r)
				s[root]=a[l];
				else
				s[root]= Compare(createSegmentTreeUtil(a, 2*root+1, l, (l+r)/2), createSegmentTreeUtil(a,2*root+2, (l+r)/2+1,r));
				return s[root];
			}
			int getValue(int gl,int gr){
				return getValueUtil(0, 0, n-1, gl, gr);
			}
			int getValueUtil(int root,int l,int r,int gl,int gr){
				if(l>=gl&&r<=gr){
					return s[root];
				}
				if(l>gr||r<gl){
					return 0;
				}
				return Compare(getValueUtil(2*root+1, l, (l+r)/2, gl, gr), getValueUtil(2*root+2, (l+r)/2+1, r, gl, gr));
			}
			void update(int in,int val){
				updateUtil(val, in,0,0,n-1);
			}
			int updateUtil(int p,int k,int root,int l,int r){
				if(l==r&&l==k){
					return s[root]=p;
				}
				else if(l>k||r<k)
				return s[root];
				else{
					return s[root]=Compare(updateUtil(p, k, 2*root+1, l, (l+r)/2), updateUtil(p, k, 2*root+2,(l+r)/2+1,r ));
				}
			}
			int Compare(int a,int b){
				return Math.max(a, b);
			}
		}
		class Pair{
			int r;int w;
			Pair(int node,int weight){
				r=node;w=weight;
			}
		}
		
		