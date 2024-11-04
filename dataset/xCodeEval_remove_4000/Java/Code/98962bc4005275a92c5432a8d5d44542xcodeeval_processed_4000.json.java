
import java.util.*;

import javax.swing.text.Segment;

import java.io.*;
import java.math.*;
import java.sql.Array;
import java.sql.ResultSet;
import java.sql.SQLException;



public class Main {
	 private static class MyScanner {
	        private static final int BUF_SIZE = 2048;
	        BufferedReader br;
	 
	        private MyScanner() {
	            br = new BufferedReader(new InputStreamReader(System.in));
	        }
	 
	        private boolean isSpace(char c) {
	            return c == '\n' || c == '\r' || c == ' ';
	        }
	 
	        String next() {
	            try {
	                StringBuilder sb = new StringBuilder();
	                int r;
	                while ((r = br.read()) != -1 && isSpace((char)r));
	                if (r == -1) {
	                    return null;
	                }
	 
	                sb.append((char) r);
	                while ((r = br.read()) != -1 && !isSpace((char)r)) {
	                    sb.append((char)r);
	                }
	                return sb.toString();
	            } catch (IOException e) {
	                e.printStackTrace();
	            }
	            return null;
	        }
	 
	        int nextInt() {
	            return Integer.parseInt(next());
	        }
	 
	        long nextLong() {
	            return Long.parseLong(next());
	        }
	 
	        double nextDouble() {
	            return Double.parseDouble(next());
	        }
	    }
	  static class Reader{
		  
			BufferedReader br;
			StringTokenizer st;
			public Reader() {
				br = new BufferedReader(new InputStreamReader(System.in));
			}
			String next() 
		    { 
		        while (st == null || !st.hasMoreElements()) 
		        { 
		            try
		            { 
		                st = new StringTokenizer(br.readLine()); 
		            } 
		            catch (IOException  e) 
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
		        String str = ""; 
		        try
		        { 
		            str = br.readLine(); 
		        } 
		        catch (IOException e) 
		        { 
		            e.printStackTrace(); 
		        } 
		        return str; 
		    } 
		}
	 
	  static long mod = (long)(1e9 + 7);
	 
	static void sort(long[] arr ) {
		 ArrayList<Long> al = new ArrayList<>();
		 for(long e:arr) al.add(e);
		 Collections.sort(al);
		 for(int i = 0 ; i<al.size(); i++) arr[i] = al.get(i);
	 }
	static void sort(int[] arr ) {
		 ArrayList<Integer> al = new ArrayList<>();
		 for(int e:arr) al.add(e);
		 Collections.sort(al);
		 for(int i = 0 ; i<al.size(); i++) arr[i] = al.get(i);
	 }
	
	static void sort(char[] arr) {
		ArrayList<Character> al = new ArrayList<Character>();
		for(char cc:arr) al.add(cc);
		Collections.sort(al);
		for(int i = 0 ;i<arr.length ;i++) arr[i] = al.get(i);
	}
	static void rvrs(int[] arr) {
		int i =0 , j = arr.length-1;
		while(i>=j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}
	static void rvrs(long[] arr) {
		int i =0 , j = arr.length-1;
		while(i>=j) {
			long temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	static long mod_mul(  long mod , long... a) {
		long ans = a[0]%mod;
		for(int i = 1 ; i<a.length ; i++) {
			ans = (ans * (a[i]%mod))%mod;
		}
		
		return ans;
	}
	static long mod_sum(long mod , long... a) {
		long ans = 0;
		for(long e:a) {
			ans = (ans + e)%mod;
		}
		return ans;
	}
	 static long gcd(long a, long b)
	  {      
	     if (b == 0)
	        return a;
	     return gcd(b, a % b); 
	  }
	 static boolean[] prime(int num) {
			boolean[] bool = new boolean[num];
		     
		      for (int i = 0; i< bool.length; i++) {
		         bool[i] = true;
		      }
		      for (int i = 2; i< Math.sqrt(num); i++) {
		         if(bool[i] == true) {
		            for(int j = (i*i); j<num; j = j+i) {
		               bool[j] = false;
		            }
		         }
		      }
		      if(num >= 0) {
		    	  bool[0] = false;
		    	  bool[1] = false;
		      }
		      
		      return bool;
		}

	 static long modInverse(long a, long m)
	    {
	        long g = gcd(a, m);
	       
	          return   power(a, m - 2, m);
	        
	    }
	   static long lcm(long a , long b) {
		   return (a*b)/gcd(a, b);
	   }
	   static int lcm(int a , int b) {
		   return (int)((a*b)/gcd(a, b));
	   }
	 static long power(long x, long y, long m){
	        if (y == 0) return 1; long p = power(x, y / 2, m) % m; p = (int)((p * (long)p) % m);
	        if (y % 2 == 0) return p; else return (int)((x * (long)p) % m); }
	   
     static class Combinations{
	    	 private long[] z;
	    	 private long[] z1;
	    	 private long[] z2;
	    	  public Combinations(long N , long mod) {
				z = new long[(int)N+1];
				z1 = new long[(int)N+1];
				z[0] = 1;
				for(int i =1 ; i<=N ; i++) z[i] = (z[i-1]*i)%mod;
			     z2 = new long[(int)N+1];
				z2[0] = z2[1] = 1;
			    for (int i = 2; i <= N; i++)
			        z2[i] = z2[(int)(mod % i)] * (mod - mod / i) % mod;
			    
			    
			    z1[0] = z1[1] = 1;
			    
			    for (int i = 2; i <= N; i++)
			        z1[i] = (z2[i] * z1[i - 1]) % mod;
			}
	    	  long fac(long n) {
	    		  return z[(int)n];
	    	  }
	    	  long id0(long n) {
	    		  return z2[(int)n];
	    	  }
	    	  long id4(long n) {
	    		  return id4((int)n);
	    	  }
	    	  long ncr(long N, long R, long mod)
	    	  {		if(R<0 || R>N ) return 0;
	    		    long ans = ((z[(int)N] * z1[(int)R])
	    		              % mod * z1[(int)(N - R)])
	    		             % mod;
	    		    return ans;
	    		}
	      }
	      static class id1 {
			    int[] rank, parent;
			    int n;
			  
			    public id1(int n)
			    {
			        rank = new int[n];
			        parent = new int[n];
			        this.n = n;
			        makeSet();
			    }
			  
			    void makeSet()
			    {
			        for (int i = 0; i < n; i++) {
			          
			            parent[i] = i;
			        }
			    }
			  
			    int find(int x)
			    {
			        if (parent[x] != x) {
			        
			            parent[x] = find(parent[x]);
			  
			        }
			  
			        return parent[x];
			    }
			  
			    void union(int x, int y)
			    {
			        int xRoot = find(x), yRoot = find(y);
			  
			        if (xRoot == yRoot)
			            return;
			  
			        if (rank[xRoot] < rank[yRoot])
			  
			            parent[xRoot] = yRoot;
			  
			        else if (rank[yRoot] < rank[xRoot])
			  
			            parent[yRoot] = xRoot;
			  
			        else
			        {
			            parent[yRoot] = xRoot;
			  
			            rank[xRoot] = rank[xRoot] + 1;
			        }
			    }
			}
	      static int max(int... a ) {
	    	  int max = a[0];
	    	  for(int e:a) max = Math.max(max, e);
	    	  return max;
	      }
	      static long max(long... a ) {
	    	  long max = a[0];
	    	  for(long e:a) max = Math.max(max, e);
	    	  return max;
	      }
	      static int min(int... a ) {
	    	  int min = a[0];
	    	  for(int e:a) min = Math.min(e, min);
	    	  return min;
	      }
	      static long min(long... a ) {
	    	  long min = a[0];
	    	  for(long e:a) min = Math.min(e, min);
	    	  return min;
	      }
	      static int[] KMP(String str) {
	    	  int n = str.length();
	    	  int[] kmp = new int[n];
	    	  for(int i = 1 ; i<n ; i++) {
	    		  int j = kmp[i-1];
	    		  while(j>0 && str.charAt(i) != str.charAt(j)) {
	    			  j = kmp[j-1];
	    		  }
	    		  if(str.charAt(i) == str.charAt(j)) j++;
	    		  kmp[i] = j;
	    	  }
	    	  
	    	  return kmp;
	      }
	      
	      
	  
	 

	      static class SparseTable{
	    		
	    		private long[][] st;
	    		
	    		SparseTable(long[] arr){
	    			int n = arr.length;
	    			st = new long[n][25];
	    			log = new int[n+2];
	    			build_log(n+1);
	    			build(arr);
	    		}
	    		
	    		private void build(long[] arr) {
	    			int n = arr.length;
	    			
	    			for(int i = n-1 ; i>=0 ; i--) {
	    				for(int j = 0 ; j<25 ; j++) {
	    					int r = i + (1<<j)-1;
	    					if(r>=n) break;
	    					if(j == 0 ) st[i][j] = arr[i];
	    					else st[i][j] = Math.max(st[i][j-1] , st[ i + ( 1 << (j-1) ) ][ j-1 ] );
	    				}
	    			}
	    		}
	    		public long gcd(long a  ,long b) {
	    			if(a == 0) return b;
	    			return gcd(b%a , a);
	    		}
	    		public long query(int l ,int r) {
	    			int w = r-l+1;
	    			int power = log[w];
	    			return Math.max(st[l][power],st[r - (1<<power) + 1][power]);
	    		}
	    		private int[] log;
	    		void build_log(int n) {
	    			log[1] = 0;
	    			for(int i = 2 ; i<=n ; i++) {
	    				log[i] = 1 + log[i/2];
	    			}
	    		}
	    	}
	      
	      



	 
	 


	      static Reader sc = new Reader();
	 static StringBuilder sb = new StringBuilder();
	 public static void main(String args[]) throws IOException {

		 int tc = 1;
		  tc = sc.nextInt();

		 for(int i = 1 ; i<=tc ; i++) {



			 TEST_CASE();
			  
		 }
		 System.out.println(sb);
	 }
	
	 static void TEST_CASE() {
		int n = sc.nextInt();
		int[] arr = new int[n];
		for(int i = 0 ; i<n ; i++)
			arr[i] = sc.nextInt();
		
		PBDS pbds = new PBDS(true , arr);
		long tot = 0;
		for(int e:arr) {
			

			int last_count = pbds.count_floor(e-1);
			

			int first_count = pbds.id2(e+1);
			pbds.add(e);
			if(last_count  < first_count) tot += last_count;
			else tot += first_count;
		}
		sb.append(tot+"\n");
		
	 }
	}
class PBDS{
	private int N;	

	
	private int[] key; 

	
	private int[] bit; 

	
	private int tot; 

	
	private int[] count; 

	
	private boolean duplicate; 

	
	PBDS(boolean duplicate , int[]... ele){
		this.duplicate = duplicate;
		TreeSet<Integer> tree = new TreeSet<>();
		for(int[] arr:ele) {
			for(int e:arr) tree.add(e);
		}
	
		this.N = tree.size()+1;
		key = new int[N];
		for(int i = 1 ; i<N ; i++) {
			key[i] = tree.first();
			tree.remove(key[i]);
		}
		bit = new int[N];
		this.tot = 0;
		count = new int[N];
	}
	
	

	private void update(int ind , int val ) {
		for( ; ind<N  ;ind += (ind & (-ind))) {
			bit[ind] += val;
		}
	}
	
	

	private int val(int ind) {
		int tot = 0;
		while(ind > 0) {
			tot += bit[ind];
			ind -= (ind & (-ind));
		}	
		return tot;
	}
	
	

	private Integer index(int ele) {
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(key[m] > ele) r = m-1;
			else l = m+1;
		}
		if(r > 0 && key[r] == ele) return r;
		else return null;
	}
	
	void add(int ele) {
		Integer ind = index(ele);
		if(ind == null) return;
		if(!duplicate && count[ind] > 0) return;
		update(ind , 1);
		count[ind]++;
		tot++;
	}
	boolean contains(int ele) {
		Integer ind = index(ele);
		if(ind == null) return false;
		return count[ind] > 0;
	}
	boolean remove(int ele) {
		Integer ind = index(ele);
		if(ind == null) return false;
		if(count[ind] == 0 ) return false;
		update(ind , -1);
		count[ind]--;
		tot--;
		return true;
	}
	int size() {
		return tot;
	}
	
	Integer id3(int index) {
		if(index > tot || index < 1) return null;
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(val(m) < index) l = m+1;
			else r = m-1;
		}
		return key[l]; 
	}
	
	int id2(int ele) {
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(key[m] < ele) l = m+1;
			else r = m-1;
		}
		int ind = l-1;
		
		int count = val(ind);
		return tot - count;
	}
	
	Integer ceil(int ele) {
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(key[m] < ele) l = m+1;
			else r = m-1;
		}
		int ind = l;
		if(ind == N) return null;
		int v = val(ind);
		if(count[ind] == 0) v++;
		System.out.println(ind +" "+key[ind] +" "+v);
		l = 1 ; r = N-1;
		 l = 1 ; r = N-1;
			while(l<=r) {
				int m = (l+r)/2;
				if(val(m) < v) l = m+1;
				else r = m-1;
			}
		if(l == N) return null;
		return key[l];
	}
	
	
	int count_floor(int ele) {
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(key[m] > ele) r = m-1;
			else l = m+1;
		}
		int ind = r;
		int count = val(ind);
		return count;
	}
	
	Integer floor(int ele) {
		int l = 1 , r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(key[m] > ele) r = m-1;
			else l = m+1;
		}
		int ind = r;
		int v = val(ind);  
		if(v == 0) return null;
		 l = 1 ; r = N-1;
		while(l<=r) {
			int m = (l+r)/2;
			if(val(m) < v) l = m+1;
			else r = m-1;
		}
		if(l == N) return null;
		return key[l];
	}

	
	public String toString() {
		StringBuilder sb = new StringBuilder();
		for(int i  = 1 ; i<N ; i++) {
			int c = count[i];
			int ele = key[i];
			while(c -- >0) {
				sb.append(ele +",");
			}
		}
		return String.valueOf(sb);
	}
	
}





 

