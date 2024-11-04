
import java.util.*;
import java.util.concurrent.CompletableFuture;

import javax.swing.text.Segment;

import java.io.*;
import java.math.*;
import java.sql.Array;



public class Main {
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

	static long mod_mul(long a , long b ,long mod) {
		return ((a%mod)*(b%mod))%mod;
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
	    	  long invrsNum(long n) {
	    		  return z2[(int)n];
	    	  }
	    	  long invrsFac(long n) {
	    		  return invrsFac((int)n);
	    	  }
	    	  long ncr(long N, long R, long mod)
	    	  {		if(R<0 || R>N ) return 0;
	    		    long ans = ((z[(int)N] * z1[(int)R])
	    		              % mod * z1[(int)(N - R)])
	    		             % mod;
	    		    return ans;
	    		}
	      }
	      static class DisjointUnionSets {
			    int[] rank, parent;
			    int n;
			  
			    public DisjointUnionSets(int n)
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
	    					else st[i][j] = Math.min(st[i][j-1] , st[ i + ( 1 << (j-1) ) ][ j-1 ] );
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
	    			return Math.min(st[l][power],st[r - (1<<power) + 1][power]);
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
		for(int i =0 ; i<n ; i++) arr[i] = sc.nextInt();
		MyTreeSetLong tree = new MyTreeSetLong(true);
		long ans = 0;
		Map<Integer , Long> map  = new HashMap<>();
		for(int e:arr) {
			if(map.containsKey(e)) map.put(e, map.get(e)+1);
			else map.put(e, 1l);
			tree.add(e);
			long c1 = tree.size() - tree.countFloorNodeLongs(e);
			long c2 = tree.size() - c1 - map.get(e);
			ans += Math.min(c1, c2);
		}
		sb.append(ans+"\n");		
	}
}

  
class MyTreeSetLong implements Iterable<Long> {
	private static class NodeLong {
	    NodeLong parent;
	    NodeLong left;
	    NodeLong right;
	    long value;
	    int size;
	    int height;

	    NodeLong(long v) {
	        value = v;
	        size = height = 1;
	    }

	    NodeLong finalisePosition(NodeLong root) {
	        int lheight = findDepth(left), rheight = findDepth(right);

	        if (lheight > rheight + 1) {
	            if (findDepth(left.right) > findDepth(left.left))
	                root = left.rotateLeft(root);
	            root = rotateRight(root);
	        } else if (lheight + 1 < rheight) {
	            if (findDepth(right.left) > findDepth(right.right))
	                root = right.rotateRight(root);
	            root = rotateLeft(root);
	        } else {
	            setParameters();
	        }

	        return root;
	    }

	    NodeLong rotateRight(NodeLong root) {
	        NodeLong A = this, B = left, P = parent;

	        if (P != null) {
	            if (P.left == this) P.left = B;
	            else if (P.right == this) P.right = B;
	            else System.exit(7 / 0);
	        } else root = B;
	        B.parent = A.parent;

	        A.left = B.right;
	        if (B.right != null) B.right.parent = A;
	        B.right = A;
	        A.parent = B;

	        A.setParameters();
	        B.setParameters();

	        return root;
	    }

	    NodeLong rotateLeft(NodeLong root) {
	        NodeLong A = this, B = right, P = parent;

	        if (P != null) {
	            if (P.left == this) P.left = B;
	            else if (P.right == this) P.right = B;
	            else System.exit(7 / 0);
	        } else root = B;
	        B.parent = A.parent;

	        A.right = B.left;
	        if (B.left != null) B.left.parent = A;
	        B.left = A;
	        A.parent = B;

	        A.setParameters();
	        B.setParameters();

	        return root;
	    }

	    void setParameters() {
	        size = 1 + findSize(left) + findSize(right);
	        height = 1 + Math.max(findDepth(left), findDepth(right));
	    }

	    int size() {
	        return size;
	    }

	    int findDepth(NodeLong node) {
	        return node == null ? 0 : node.height;
	    }

	    static int findSize(NodeLong node) {
	        return node == null ? 0 : node.size();
	    }

	    public int compareTo(NodeLong node) {
	        return Long.compare(value, node.value);
	    }

	    public String toString() {
	        return value + "";
	    }

	}
    NodeLong root;
    boolean allowDuplicates;
    private int itrInd;
    private ArrayList<NodeLong> dfsTrav = new ArrayList<>();

    public MyTreeSetLong() {
        root = null;
    }

    public MyTreeSetLong(boolean allowDupli) {
        root = null;
        allowDuplicates = allowDupli;
    }

    public boolean add(long value) {
        return add(new NodeLong(value));
    }

    public int countFloorNodeLongs(long value) {
        return countFloorNodeLongs(root, new NodeLong(value));
    }

    public int size() {
        return root == null ? 0 : root.size();
    }

    private boolean add(NodeLong toAdd) {
        if (root == null) {
            root = toAdd;
            return true;
        }

        NodeLong tr = root;
        while (true) {
            if (toAdd.compareTo(tr) < 0) {
                if (tr.left == null) {
                    tr.left = toAdd;
                    toAdd.parent = tr;
                    break;
                } else tr = tr.left;
            } else if (allowDuplicates || toAdd.compareTo(tr) > 0) {
                if (tr.right == null) {
                    tr.right = toAdd;
                    toAdd.parent = tr;
                    break;
                } else tr = tr.right;
            } else return false;
        }

        while (toAdd != null) {
            root = toAdd.finalisePosition(root);
            toAdd = toAdd.parent;
        }
        return true;
    }

    private int countFloorNodeLongs(NodeLong node, NodeLong key) {
        if (node == null) return 0;
        else if (node.compareTo(key) > 0)
            return countFloorNodeLongs(node.left, key);
        else
            return NodeLong.findSize(node.left) + 1 + countFloorNodeLongs(node.right, key);
    }

    public Iterator<Long> iterator() {
        dfsTrav.clear();
        dfs(root);
        itrInd = 0;
        Iterator<Long> iterator = new Iterator<Long>() {

            public boolean hasNext() {
                return itrInd < size();
            }


            public Long next() {
                return dfsTrav.get(itrInd++).value;
            }
        };
        return iterator;
    }

    private void dfs(NodeLong node) {
        if (node == null) return;
        dfs(node.left);
        dfsTrav.add(node);
        dfs(node.right);
    }

    public String toString() {
        dfsTrav.clear();
        dfs(root);
        return dfsTrav.toString();
    }

}
 












