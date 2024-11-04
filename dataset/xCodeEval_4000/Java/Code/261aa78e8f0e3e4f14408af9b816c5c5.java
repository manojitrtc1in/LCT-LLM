import java.io.*;
import java.util.*;
import java.math.BigDecimal;
import java.math.*;

public class Main{
	static int min=Integer.MAX_VALUE;
	public static void main(String[] args) {
	    
	      TaskA solver = new TaskA();
	      
	      int t = in.nextInt();
	      for (int i = 1; i <= t ; i++) {
	          solver.solve(i, in, out);
	      }
	     
	      


	      
	      
	      out.flush();
	    out.close();
	  }
	
	static Set<Integer>[]graph;
	 static class TaskA {
	      public void solve(int testNumber, InputReader in, PrintWriter out) {
	    		 long n= in.nextInt();
	    		 long m= in.nextInt();
	    		 long k =in.nextInt();
	    		 
	    		 if(m<n-1||m>(n*(n-1)/2)) {println("NO");return;}
	    		 
	    		 if(n==1) {if(k>1) {println("YES");}else{println("NO");}}
	    		 else if(m<(n*(n-1)/2)) {if(k>3) {println("YES");return;}else{println("NO");return;}
	    		 }
	    		 else if(k>2) {println("YES");}
	    		 else {println("NO");}
	      }
	 }
	static void dfs(int curr,int par) {
		if(graph[curr].size()==1) {
			
		}
	}
	 static int[] shift (int[]inp,int i,int j){
		 int[]arr=new int[j-i+1];
		 int n=j-i+1;
		 for(int k=i;k<=j;k++) {
			 arr[(k-i+1)%n]=inp[k];
		 }
		 for(int k=0;k<n;k++ ) {
			 inp[k+i]=arr[k];
		 }
		 return inp;
	 }
	 static int sumDigits(long n) {
		 int total=0;
		 while(n!=0) {
			 total+=n%10;
			 n=n/10;
		 }
		 return total;
	 }
	 
	 static long[] fac;
	    static long mod = (long) 998244353;
	 
	    static void initFac(long n) {
	        fac = new long[(int)n + 1];
	        fac[0] = 1;
	        for (int i = 1; i <= n; i++) {
	            fac[i] = (fac[i - 1]  * i) % mod;
	        }
	    }
	 
	 
	 
	    static long nck(int n, int k) {
	        if (n < k)
	            return 0;
	        long den = inv((int) (fac[k] * fac[n - k] % mod));
	        return fac[n] * den % mod;
	    }
	 
	    static long pow(long b, long e) {
	        long ans = 1;
	        while (e > 0) {
	            if (e % 2 == 1)
	                ans = ans * b % mod;
	            e >>= 1;
	            b = b * b % mod;
	        }
	        return ans;
	    }
	 
	    static long inv(long x) {
	        return pow(x, mod - 2);
	    }
	 
	 
	    static void sort(int[] a) {
	        ArrayList<Integer> q = new ArrayList<>();
	        for (int i : a) q.add(i);
	        Collections.sort(q);
	        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
	    }
	 
	    static void sort(long[] a) {
	        ArrayList<Long> q = new ArrayList<>();
	        for (long i : a) q.add(i);
	        Collections.sort(q);
	        for (int i = 0; i < a.length; i++) a[i] = q.get(i);
	    }
	    
	 public static int bfsSize(int source,LinkedList<Integer>[]a,boolean[]visited) {
			Queue<Integer>q=new LinkedList<>();
			q.add(source);
			visited[source]=true;
			int distance=0;
			while(!q.isEmpty()) {
				int curr=q.poll();
				distance++;
				for(int neighbour:a[curr]) {
					if(!visited[neighbour]) {
						visited[neighbour]=true;
						q.add(neighbour);
					}
				}
			}
			return distance;
		}
	 public static Set<Integer>factors(int n){
		 Set<Integer>ans=new HashSet<>();
		 ans.add(1);
		 for(int i=2;i*i<=n;i++) {
			 if(n%i==0) {
				 ans.add(i);
				 ans.add(n/i);
			 }
		 }
		 return ans;
	 }
	public static int bfsSp(int source,int destination,ArrayList<Integer>[]a) {
		boolean[]visited=new boolean[a.length];
		int[]parent=new int[a.length];
		Queue<Integer>q=new LinkedList<>();
		int distance=0;
		q.add(source);
		visited[source]=true;
		parent[source]=-1;
		while(!q.isEmpty()) {
			int curr=q.poll();
			if(curr==destination) {
				break;
			}
			for(int neighbour:a[curr]) {
				if(neighbour!=-1&&!visited[neighbour]) {
					visited[neighbour]=true;
					q.add(neighbour);
					parent[neighbour]=curr;
				}
			}
		}
		int cur=destination;
		while(parent[cur]!=-1) {
			distance++;
			cur=parent[cur];
		}
		return distance;
	}
	 static int bs(int size,int[]arr) {
		 int x = -1;
    	 for (int b = size/2; b >= 1; b /= 2) {
        	 while (!ok(arr));
        	 }
    	 int k = x+1;
    	 return k;
	 }
	 
	 static boolean ok(int[]x) {
		 return false;
	 }
	 
	 public static int solve1(ArrayList<Integer> A) {
		 long[]arr =new long[A.size()+1];
		 int n=A.size();
		 for(int i=1;i<=A.size();i++) {
			 arr[i]=((i%2)*((n-i+1)%2))%2;
			 arr[i]%=2;
		 }
		 int ans=0;
		 for(int i=0;i<A.size();i++) {
			 if(arr[i+1]==1) {
				 ans^=A.get(i);
			 }
		 }
		 return ans;
	   }
	 
	     public static String printBinary(long a) {
	    	 String str="";
	    	 for(int i=31;i>=0;i--) {
	    		 if((a&(1<<i))!=0) {
	    			 str+=1;
	    		 }
	    		 
	    		 if((a&(1<<i))==0 && !str.isEmpty()) {
	    			 str+=0;
	    		 }
	    		 
	    	 }
	    	 return str;
	     }
	     
		 public static String reverse(long a) {
		        long rev=0;
		        String str="";
		        int x=(int)(Math.log(a)/Math.log(2))+1;
		        for(int i=0;i<32;i++) {
		        	rev<<=1;
		        	if((a&(1<<i))!=0) {
		        		rev|=1;
		        		str+=1;
		        	}
		        	else {
		        		str+=0;
		        	}
		        }
		        return str;
			}
		
	 
	 

	 static void sortF(Pair arr[])
	    {
	        

	        Arrays.sort(arr, new Comparator<Pair>() {
	            @Override public int compare(Pair p1, Pair p2)
	            {	if(p1.first==p2.first) {
	            	return p1.second-p2.second;
	            }
	                return p1.first - p2.first;
	            }
	        });
	    }
	 static void sortS(Pair arr[])
	    {
	        

	        Arrays.sort(arr, new Comparator<Pair>() {
	            @Override public int compare(Pair p1, Pair p2)
	            {
	                return p1.second - p2.second;
	            }
	        });
	    }
	 
	 static class Pair implements Comparable<Pair>
	 {
	   int first ;int second  ;
	  
	   public  Pair(int x, int y)
	   {
	       this.first = x ;this.second = y ;
	   }
	   
	   @Override
	  public boolean equals(Object obj)
	  {
	      if(obj == this)return true  ;
	      
	      if(obj == null)return false  ;
	      
	      if(this.getClass() != obj.getClass()) return false ;
	      
	      Pair other  = (Pair)(obj) ;
	      
	      if(this.first != other.first)return false  ;
	      if(this.second != other.second)return false  ;
	      
	      return true  ;
	      
	  }
	     
	     @Override
	     
	     public int hashCode()
	     {
	         return this.first^this.second  ;
	     }
	       
	 @Override
	 	public String toString() {
	 	
	 	String ans = "" ;ans  += this.first ;	ans += " ";	ans += this.second ;
	 	return ans  ;
	 	}

	

	@Override
	public int compareTo(Main.Pair o) {
		{	if(this.first==o.first) {
        	return this.second-o.second;
        }
            return this.first - o.first;
        }
	}
	 	

	 }
	 

	
	    
	 
	
	 static int nD(long num) {
		 String s=String.valueOf(num);
		 return s.length();
	 }
	 
	 
	 static int CommonDigits(int x,int y) {
		 String s=String.valueOf(x);
		 String s2=String.valueOf(y);
		 return 0;
	 }
	 
	 
	 
	 static int lcs(String str1, String str2, int m, int n)
	    {
	        int L[][] = new int[m + 1][n + 1];
	        int i, j;
	 
	        

	        

	        

	        

	        for (i = 0; i <= m; i++) {
	            for (j = 0; j <= n; j++) {
	                if (i == 0 || j == 0)
	                    L[i][j] = 0;
	 
	                else if (str1.charAt(i - 1)
	                         == str2.charAt(j - 1))
	                    L[i][j] = L[i - 1][j - 1] + 1;
	 
	                else
	                    L[i][j] = Math.max(L[i - 1][j],
	                                       L[i][j - 1]);
	            }
	        }
	 
	        

	        

	        return L[m][n];
	    }
	 
	 

	 boolean IsPowerOfTwo(int x)
	 {
	     return (x != 0) && ((x & (x - 1)) == 0);
	 }
	 

	 
	 static long power(long a,long b,long m ) {
		 long ans=1;
		 while(b>0) {
			 if(b%2==1) {
				 ans=((ans%m)*(a%m))%m; b--;
			 }
			 else {
				 a=(a*a)%m;b/=2;
			 }
			 
		 }
		 return ans%m;
	 }
	 

	 public static boolean repeatedSubString(String string) {
		    return ((string + string).indexOf(string, 1) != string.length());
		}
	 static int search(char[]c,int start,int end,char x) {
		 for(int i=start;i<end;i++) {
			 if(c[i]==x) {return i;}
		 }
		 return -2;
	 }
	 

	 
	
	 
	 static int gcd(int a, int b) {
	        while (b != 0) {
	            int t = b;
	            b = a % b;
	            a = t;
	        }
	        return a;
	    }
	
	 
	
	 
	 static long fac(long a)
	 {
	     if(a== 0L || a==1L)return 1L ;
	     
	     return a*fac(a-1L) ;
	 }
	 
	 
	 
	 static ArrayList al() {
		 ArrayList<Integer>a =new ArrayList<>();
			return a;
		}
	 
	static HashSet h() {
			return new HashSet<Integer>();
		}
	static void debug(int[][]a) {
		int n= a.length;
		for(int i=1;i<=n;i++) {
	  		for(int j=1;j<=n;j++) {
	  			out.print(a[i][j]+" ");
	  		}
	  		out.print("\n");
	  	}
	}
	static void debug(int[]a) {
			out.println(Arrays.toString(a));
		}
	
	static void debug(ArrayList<Integer>a) {
				out.println(a.toString());
		}
	
	static boolean[]seive(int n){
		boolean[]b=new boolean[n+1];
		 for (int i = 2; i <= n; i++)
	            b[i] = true;
		 
		for(int i=2;i*i<=n;i++) {
			if(b[i]) {
				for(int j=i*i;j<=n;j+=i) {
					b[j]=false;
				}
			}
		}
		return b;
	}
	
	 static int longestIncreasingSubseq(int[]arr) {
		  int[]sizes=new int[arr.length];
		  Arrays.fill(sizes, 1);
		  int max=1;
		  for(int i=1;i<arr.length;i++) {
			  for(int j=0;j<i;j++) {
				  if(arr[j]<arr[i]) {
					  sizes[i]=Math.max(sizes[i],sizes[j]+1);
					  max=Math.max(max, sizes[i]);
				  }
			  }
		  }
		  return max;
	 }
	 
	 public static ArrayList primeFactors(long n)
	    {
		    ArrayList<Long>h= new ArrayList<>();
	        

	        if(n%2 ==0) {h.add(2L);}
	 
	        

	        

	        for (long i = 3; i <= Math.sqrt(n); i+= 2)
	        {
	            if(n%i==0) {h.add(i);}
	        }
	        if (n > 2)
	            h.add(n);
	        return h;
	    }
	 
	 static boolean Divisors(long n){
		 if(n%2==1) {
			 return true;
		 }
	     for (long i=2; i<=Math.sqrt(n); i++){
	            if (n%i==0 && i%2==1){
	                   return true;
	            } 
	        }
	     return false;
	    }
	
	static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static InputReader in = new InputReader(inputStream);
    static PrintWriter out = new PrintWriter(outputStream);
    
    public static void superSet(int[]a,ArrayList<String>al,int i,String s) {
    	if(i==a.length) {
    		al.add(s);
    		return;
    	}
    	superSet(a,al,i+1,s);
    	superSet(a,al,i+1,s+a[i]+" ");
    }
    
	public static long[] makeArr() {
		long size=in.nextInt();
		long []arr=new long[(int)size];
		for(int i=0;i<size;i++) {
			arr[i]=in.nextInt();
		}
		return arr;
	}
	
	public static long[] arr(int n) {
		long []arr=new long[n+1];
		for(int i=1;i<n+1;i++) {
			arr[i]=in.nextLong();
		}
		return arr;
	}
	
  public static void sort(long arr[], int l, int r)
  {
      if (l < r)
      {
          

          int m = (l+r)/2;

          

          sort(arr, l, m);
          sort(arr , m+1, r);

          

          merge(arr, l, m, r);
      }
  }

  static void print(int c) {
		 out.print(c);
	 }
	 static void println(int x) {
		 out.println(x);
	 }
	 static void print(String s) {
		 out.print(s);
	 }
	 static void println(String s) {
		 out.println(s);
	 }
public static void merge(long arr[], int l, int m, int r)
  {
      

      int n1 = m - l + 1;
      int n2 = r - m;

      
      long L[] = new long[n1];
      long R[] = new long[n2];

      

      for (int i=0; i<n1; ++i)
          L[i] = arr[l + i];
      for (int j=0; j<n2; ++j)
          R[j] = arr[m + 1+ j];


      

      

      int i = 0, j = 0;

      

      int k = l;
      while (i < n1 && j < n2)
      {
          if (L[i] <= R[j])
          {
              arr[k] = L[i];
              i++;
          }
          else
          {
              arr[k] = R[j];
              j++;
          }
          k++;
      }

      
      while (i < n1)
      {
          arr[k] = L[i];
          i++;
          k++;
      }

      
      while (j < n2)
      {
          arr[k] = R[j];
          j++;
          k++;
      }
  }

public static void reverse(int[] array)
{
    int n = array.length;
    for (int i = 0; i < n / 2; i++) {
        int temp = array[i];
        array[i] = array[n - i - 1];
        array[n - i - 1] = temp;
    }
}

  public static long nCr(int n,int k)
  {
      long ans=1L;
      k=k>n-k?n-k:k;
     
      for( int j=1;j<=k;j++,n--)
      {
          if(n%j==0)
          {
              ans*=n/j;
          }else
          if(ans%j==0)
          {
              ans=ans/j*n;
          }else
          {
              ans=(ans*n)/j;
          }
      }
      return ans;
  }

  static int searchMax(int index,long[]inp) {
	  while(index+1<inp.length &&inp[index+1]>inp[index]) {
		  index+=1;
	  }
	  return index;
  }
  static int searchMin(int index,long[]inp) {
	  while(index+1<inp.length &&inp[index+1]<inp[index]) {
		  index+=1;
	  }
	  return index;
  }
  public class ListNode {
	       int val;
	       ListNode next;
	       ListNode() {}
	       ListNode(int val) { this.val = val; }
	       ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	   }
  static class Pairr implements Comparable<Pairr>{
		 private int index;
		 private int cumsum;
		 private ArrayList<Integer>indices;
		 public Pairr(int index,int cumsum) {
			 this.index=index;
			 this.cumsum=cumsum;
			 indices=new ArrayList<Integer>();
		 }
		 public int compareTo(Pairr other) {
			 return Integer.compare(cumsum, other.cumsum);
		 }
	 }
	 
  
  static class InputReader {
      public BufferedReader reader;
      public StringTokenizer tokenizer;

      public InputReader(InputStream stream) {
          reader = new BufferedReader(new InputStreamReader(stream), 32768);
          tokenizer = null;
      }

      public String next() {
          while (tokenizer == null || !tokenizer.hasMoreTokens()) {
              try {
                  tokenizer = new StringTokenizer(reader.readLine());
              } catch (IOException e) {
                  throw new RuntimeException(e);
              }
          }
          return tokenizer.nextToken();
      }

      public int nextInt() {
          return Integer.parseInt(next());
      }
      public long nextLong() {
    	  return Long.parseLong(next());
      }
  }
}