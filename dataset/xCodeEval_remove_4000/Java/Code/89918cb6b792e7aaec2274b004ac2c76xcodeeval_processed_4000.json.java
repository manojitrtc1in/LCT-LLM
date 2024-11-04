

import java.util.*;


import java.io.*;
import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;
import java.io.*;
import java.util.*;
import java.io.*;
import java.util.*;
import java.util.*;



public class topcoder {
	 public static class TreeNode {
	     int val;
	   TreeNode left;
	    TreeNode right;
	    TreeNode() {}
	    TreeNode(int val) { this.val = val; }
	    TreeNode(int val, TreeNode left, TreeNode right) {
	        this.val = val;
	        this.left = left;
	        this.right = right;
	   }
	       static int x = -1;
	       static int y = -1;
	       public static int  first_search(TreeNode root, TreeNode main_root) {
	    	   
	    	   if(root == null) return 0;
	    	   
	    
	    	 
	    	 int a = first_search(root.left,main_root);
	    	 int b = first_search(root.right,main_root);
	    	 
	    	 if(a > main_root.val)
	    		x = a;
	    	 
	    	 if(b < main_root.val) y = b;
	    	 
	    	   return root.val;
	    	   
	       }
	 
	       
 public static void  fix(TreeNode root, TreeNode main_root) {
	    	   
	    	   if(root == null) return;
	    	   
	    
	    	   fix(root.left,main_root);
	    	   if(root.val > main_root.val) {
	    		   root.val = y;
	    	   }
	    	  
	    	   fix(root.right,main_root);
	    	   
	    	   if(root.val < main_root.val);
	    	   root.val = x;
	    	   
	    	
	    	   
 }
 
	    
	    
	       
	          
	       
	    
	    
	    public static int max(int []nums, int s, int e) {
	    	int max = Integer.MIN_VALUE;
	    	
	    	for(int i = s; i <= e; i++) {
	    		max = Math.max(max, nums[i]);
	    	}
	    	
	    	return max;
	    }
	    
	    public static TreeNode new_node(int []nums, int s, int e) {
	    	
	    	
	    	
	    	int max = max(nums,s,e);
	    	TreeNode node = new TreeNode(max);
	    	
	    	return node;
	    
	    }
	   
	    public static TreeNode root;
	    public static void res(int []nums, int s, int e) {
	    	if(s > e)return;
	    	
	    	if(root == null) {
	    		root = new_node(nums,s,e);
	    	}
	    	root.left = new_node(nums,s,e);
	    	root.right = new_node(nums,s,e);
	    	
	    	return;
	    }
	    
	    
	    
	   static int depth(TreeNode root) {
	    	
		   if(root == null)return 0;
		   int a = 1+ depth(root.left);
		   int b = 1+ depth(root.right);
		   
		   return Math.max(a,b);
	    }

	   
	   static HashSet<Integer>set = new HashSet<>();
	   static void id1(TreeNode root, int cur_depth, int depth) {
		   
		   if(root == null)return;
		   if(cur_depth == depth)set.add(root.val);
		   
		  id1(root.left,cur_depth+1,depth);
		   id1(root.right,cur_depth+1,depth);
		   
		   
		   
	   }
	   
	   public static void print(TreeNode root) {
		   
		   if(root == null)return;
		   
		   System.out.print(root.val+" ");
		   System.out.println("er");
		   print(root.left);
		   print(root.right);
	   }
	   public static HashSet<Integer>original(TreeNode root){
		   int d = depth(root);
		   id1(root,0,d);
		   return set;
	   }
	   static HashSet<Integer>set1 = new HashSet<>();
	   static void leaves(TreeNode root) {
		   
		   if(root == null)return;
		    
		   if(root.left == null && root.right == null)set1.add(root.val);
		   
		   leaves(root.left);
		   leaves(root.right);
		   
		   
	   }
	  public static boolean check(HashSet<Integer>s, HashSet<Integer>s1) {
		  
		  if(s.size() != s1.size())return false;
		  
		  for(int a : s) {
			  if(!s1.contains(a))return false;
		  }
		  
		  return true;
	  }
	 static  TreeNode subTree;
	   public static void id6(TreeNode root) {
		   
		   if(root == null)return;
		   
		   id6(root.left);
		   id6(root.right);
		   
		   
		   set1 = new HashSet<>();
		   leaves(root);
		   boolean smallest = check(set,set1);
		   
		  if(smallest) {
			  subTree = root;
			  return;
		   
	   }
	 }
	   
	   public static TreeNode answer(TreeNode root) {
		   id6(root);
		   
		   return subTree;
	   }
	 }
	static class pair{
		 
		 int first;
		 int second;
		  public pair(int first, int second) {
			  this.first = first;
			  this.second = second;
		  }
		  public int compareTo(pair p) {
			 if(first == p.first)return second-p.second;
			 return first-p.first;
		  }
	}


	static class Compare{
		
		 static void compare(ArrayList<pair>arr, long n) {
			 
			 Collections.sort(arr,new Comparator<pair>() {
				 public int compare(pair p1, pair p2) {
					 return (int) (p1.first-p2.first);
				 }
			 });
		
	}
	}
	
	public static HashMap<Integer,Integer>id7(HashMap<Integer,Integer>hm){
	
		
		  List<Map.Entry<Integer,Integer>>list = new LinkedList<Map.Entry<Integer,Integer>>(hm.entrySet());

   Collections.sort(list,new Comparator<Map.Entry<Integer,Integer>>(){
	  public int compare(Map.Entry<Integer,Integer>o1,
	    Map.Entry<Integer,Integer>o2)
	  {
    return (o1.getValue()).compareTo(o2.getValue());
	  }});
   
 HashMap<Integer,Integer>temp = new LinkedHashMap<Integer,Integer>(); 
	for(Map.Entry<Integer,Integer>aa : list) {
   temp.put(aa.getKey(), aa.getValue());
	}
	
	return temp;
	}
		
	
		
	
static class pairr implements  Comparable<pairr>{
	static Long value;
	Long index;
	
	   public pairr(Long value, Long index) {
		    this.value = value;
		    this.index = index;
	   }
	   public int  compareTo(pairr o) {
		   return  (int)(value-o.value);
	  }
}



	 static class Key<K1, K2>
	{
	    public K1 key1;
	    public K2 key2;
	 
	    public Key(K1 key1, K2 key2)
	    {
	        this.key1 = key1;
	        this.key2 = key2;
	    }
	 
	    @Override
	    public boolean equals(Object o)
	    {
	        if (this == o) {
	            return true;
	        }
	 
	        if (o == null || getClass() != o.getClass()) {
	            return false;
	        }
	 
	        Key key = (Key) o;
	        if (key1 != null ? !key1.equals(key.key1) : key.key1 != null) {
	            return false;
	        }
	 
	        if (key2 != null ? !key2.equals(key.key2) : key.key2 != null) {
	            return false;
	        }
	 
	        return true;
	    }
	 
	    @Override
	    public int hashCode()
	    {
	        int result = key1 != null ? key1.hashCode() : 0;
	        result = 31 * result + (key2 != null ? key2.hashCode() : 0);
	        return result;
	    }
	 
	    @Override
	    public String toString() {
	        return "[" + key1 + ", " + key2 + "]";
	    }
	}
	
	
	 public static int id0 (long n) {
		 
		 int sum = 0;
		 
		 while(n > 0) {
			 sum += n%10;
			 n /= 10;
		 }
		 
		 return sum;
	 
	 }
	 
	 
	 public static long binary_search(int s, int e, long num, long []ar) {
		 
		 if(s > e) {
			 return -1;
		 }	 
			 
		 
		     int mid = (s+e)/2;
		     
		      if(s == e && ar[s] >= num) {
		    	  return ar[s];
		      }else if(s == e && ar[s] < num) {
		    	  return -1;
		      }else if(ar[mid] < num) {
		    	  return binary_search(mid+1,e,num,ar);
		      }else if(ar[mid] >= num) {
		    	    return binary_search(s,mid,num,ar);
		      }
		      
		      return -1;
		 
	 }
	 
	 
	 public static int index_search(int s, int e, long num, long []ar) {
		 
		 if(s > e) {
			 return -1;
		 }	 
			 
		 
		     int mid = (s+e)/2;
		     
		      if(s == e && ar[s] >= num) {
		    	  return s;
		      }else if(s == e && ar[s] < num) {
		    	  return -1;
		      }else if(ar[mid] < num) {
		    	  return index_search(mid+1,e,num,ar);
		      }else if(ar[mid] >= num) {
		    	    return index_search(s,mid,num,ar);
		      }
		      
		      return -1;
		 
	 }
		     public static void swap(int []ar, int i, int j) {
		    	 
		    	 
		    	 for(int k= j; k >= i; k--) {
		    		 int temp = ar[k];
		    		 ar[k] = ar[k+1];
		    		 ar[k+1] = temp;
		    	 }
		     }
		     
		     public static boolean digit_exists(long n) {
		    	 
		    	 while(n > 0) {
		    		 if(n%10 == 9)
		    			 return true;
		    		 n = n/10;
		    	 }
		    	 
		    	 return false;
		     }
		     public static int log(int n) {
		    	 
		    	 int c = 0;
		    	 while(n > 0) {
		    		 c++;
		    		 n /=2;
		    	 }
		    	 
		    	 return c;
		     }
			  public static int findOr(int[]bits){
	    	        int or=0;
	    	            for(int i=0;i<32;i++){
	    	                or=or<<1;
	    	                if(bits[i]>0)
	    	                    or=or+1;
	    	            }
	    	        return or;
	    	    }
			  
			  static void id3(int limit, Vector<Integer> prime)
			    {
			        

			        

			        

			        boolean mark[] = new boolean[limit+1];
			         
			        for (int i = 0; i < mark.length; i++)
			            mark[i] = true;
			      
			        for (int p=2; p*p<limit; p++)
			        {
			            

			            if (mark[p] == true)
			            {
			                

			                for (int i=p*p; i<limit; i+=p)
			                    mark[i] = false;
			            }
			        }
			      
			        

			        for (int p=2; p<limit; p++)
			        {
			            if (mark[p] == true)
			            {
			                prime.add(p);
			             
			            }
			        }
			    }
			      
			    

			public    static void id8(int n, ArrayList<Integer>l)
			    {
			        

			        

			        int limit = (int) (floor(sqrt(n))+1);
			        Vector<Integer> prime = new Vector<>(); 
			  
			        id3(limit, prime);
			      
			        

			        

			        int low  = limit;
			        int high = 2*limit;
			      
			        

			        

			        while (low < n)
			        {
			            if (high >= n)
			                high = n;
			 
			            

			            

			            

			            boolean mark[] = new boolean[limit+1];
			             
			            for (int i = 0; i < mark.length; i++)
			                mark[i] = true;
			      
			            

			            

			            for (int i = 0; i < prime.size(); i++)
			            {
			                

			                

			                

			                

			                int loLim = (int) (floor(low/prime.get(i)) * prime.get(i));
			                if (loLim < low)
			                    loLim += prime.get(i);
			      
			                
			                for (int j=loLim; j<high; j+=prime.get(i))
			                    mark[j-low] = false;
			            }
			      
			            

			            for (int i = low; i<high; i++)
			                if (mark[i - low] == true)
			                   l.add(i);
			      
			            

			            low  = low + limit;
			            high = high + limit;
			        }
			    }
			    
			    public static int id13(long k) {
			    	
			    	long k1 = k;
			    	int power = 0;
			    	
			    	while(k > 0) {
			    		power++;
			    		k /=2 ;
			    	}
			    	
			    	long check = (long)Math.pow(2, power-1);
			    	if(k1 == check) {
			    		return power;
			    	}
			

			    	long f = (long)Math.pow(2, power-1);
			    	long rem = k1-f;
			    	return id13(rem);
			    }
			    
			 public static void sortPair(ArrayList<pair>l, int n) {
				  n = l.size();
				  
				  Compare obj = new Compare();
				  obj.compare(l, n);
			 }
             
          
			 
				   
		public static void shuffle(int []array, int num,int t_index,  boolean []vis, int m ) {	  
			 
		
		for(int i = 0; i < m; i++) {
			if(vis[i] == false) {
				
				
				int temp = array[i];
		          if(i < t_index) {
		        	  vis[i] = true;
		          }
				array[i] = num;
				array[t_index] = temp;
			

				break;
			}
		}
		}
		
		public static void rotate(int []arr,int j, int times, int m) {
			
		
			
			 if(j == 0) {
				 int temp1 = arr[0];
				 arr[0] = arr[times];
				 arr[times] = temp1;
				 
			 }else {
			 int temp = arr[j];
			 int z = arr[0];
				
			 arr[0] = arr[times];
			
			 arr[j] = z;
			 arr[times] =  temp;
			    
			
			
		}

		}
		
		public static void recur(int i,int A, int B,int []dp,int []metal, int n, boolean took,int ind) {
			
		  if(i-A <= 0 && i-B <= 0)return;
		    int count = 0;
		    
		    for(int j = 1; j <= n; j++) {
		    	if(dp[j] >= metal[j]) {
		    		count++;
		    	}
		    }
		    
		    if(count == n)return;
			if(i-A >= 0 && i-B >= 0 && dp[i] > 0 && dp[i] > metal[i]) {
			dp[i]--;
		
			dp[i-A]++;
		
			dp[i-B]++;
			}
			
			
			if(ind == 6) {
		

			}
			recur(i-A,A,B,dp,metal,n,took,ind);
			recur(i-B,A,B,dp,metal,n,took,ind);
		}
		
		
		public static boolean isPrime(int n) { 
	        if (n <= 1) return false; 
	        if (n <= 3) return true; 
	        if (n % 2 == 0 || n % 3 == 0) return false; 
	        for (int i = 5; i * i <= n; i = i + 6) 
	            if (n % i == 0 || n % (i + 2) == 0) 
	            return false; 
	        return true; 
	    }
		
		  public static boolean[] id4(int n) {
		        boolean[] isPrime = new boolean[n+1];
		        for (int i = 2; i <= n; i++) isPrime[i] = true;
		        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
		                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
		        return isPrime;
		    }
		  

		   static int gcd(long a, long b) {
			   
			   if(a == 0)
				   return (int)b;
			   
			   return gcd(b%a,a);
		   }
		    
		    
		
	
			
	    public static void dfs(LinkedList<Integer>[]list, HashMap<Integer,Integer>map, int parent, int n) {
	    	
	    	Stack<Integer>st = new Stack<>();
	   
	    	
	    }
	   public static boolean pos(int n) {
		
		   
		   int i = 1;
		   boolean pos = false;
		   
		   while(i*i <= n) {
			   if(i*i*2 == n || i*i*4 == n) {
				   pos = true;
				   break;
			   }
			   i++;
		   }
		   if(pos)return true;
		    return false;
		   
	   }
	   static  long count = 0;
	    public static void pairs (int []ar, int s, int e) {
	    	
	    	    if(e <= s)return;
	       

	    	     if(ar[e]-ar[s] == e-s) {
		    	    	count++;
		    	    	

	    	     }
	    	    	
          pairs(ar,s+1,e);
          pairs(ar,s,e-1);
	    		 
	    }
	    
	    
	     static class Pair1 implements Comparable <Pair1>{
	    	 int value;
	    	 int index;
	    	 public Pair1(int value, int index) {
	    		 this.value = value;
	    		 this.index = index;
	    		 
	    	 }
	    	 public int compareTo(Pair1 o) {
	    		   return o.value-value;
	    	 }
	    	 
	    	    
	    	 
	     }
		
	    public static long ways(long n) {
	    	
	    	return (n*(n-1))/2;
	    }
	    
	  
	    
	    static boolean isPrime(long n) {
	    	
	    	if(n <= 1)return false;
	    	if(n <= 3)return true;
	    	
	    	if(n%2 == 0 || n%3 == 0)return false;
	    	
	    	
	    	for(int i = 5; i*i <= n; i+= 6) {
	    		if(n%i == 0 || n%(i+2) == 0)
	    			return false;
	    	}
	    	
	    	return true;
	    }
	    
	    static long nextPrime(long n) {
	    	
	    	boolean found = false;
	    	long prime = n;
	    	
	    	while(!found) {
	    		prime++;
	    		if(isPrime(prime))
	    			found = true;
	    	}
	    	
	    	return prime;
	    }
	    
	    public static boolean isValid(int h, int m, int hour, int minute) {
			int a = flip(hour / 10);
			if (a == -1) return false;
			int b = flip(hour % 10);
			if (b == -1) return false;
			int c = flip(minute / 10);
			if (c == -1) return false;
			int d = flip(minute % 10);
			if (d == -1) return false;
			if (10 * d + c >= h) return false;
			if (10 * b + a >= m) return false;
			return true;
		}
		
		public static int flip(int x) {
			if (x == 0) return 0;
			if (x == 1) return 1;
			if (x == 2) return 5;
			if (x == 5) return 2;
			if (x == 8) return 8;
			return -1;
		}
	    static long maximum(long a, long b, long c, long d) {
	    	
	    	long m = Math.max(a, b);
	    	long m1 = Math.max(c, d);
	    	return Math.max(m1, m1);
	    }
	    
 static long minimum(long a, long b, long  c,long  d) {
	    	
	    	long m = Math.min(a, b);
	    	 long m1 = Math.min(c, d);
	    	return Math.min(m, m1);
	    }
 static long ans = 0;
		public static void solve1(boolean [][]vis,long [][]mat, int r, int c, int r2, int c2, int r1, int c1, int r3, int c3) {
			
		 if(r > r1 || c > c1 || r > r2 || c > c2 || r1 > r3 || c1 > c3 || r3 < r2 || c3 < c2 ||
				 vis[r][c] || vis[r1][c1]|| vis[r2][c2] || vis[r3][c3])
			    return;
		 
		 vis[r][c] = true;
		 vis[r1][c1] = true;
		 vis[r2][c2] = true;
		 vis[r3][c3] = true;
		 long max = maximum(mat[r][c],mat[r1][c1],mat[r2][c2],mat[r3][c3]);
		 long min = minimum(mat[r][c],mat[r1][c1],mat[r2][c2],mat[r3][c3]);
		
		 long a = mat[r][c];
		 long b = mat[r1][c1];
		 long c4 = mat[r2][c2];
		 long d =mat[r3][c3];
		 long []p = {a,b,c4,d};
		 Arrays.sort(p);
		 long temp = (p[2]+p[3]-p[0]-p[1]);
	     if(r == r1 && r == r2 && r2 == r3 && r1 == r3)
	    	 temp /= 2;
		 System.out.println(Arrays.toString(p));
		 ans += temp;
		 
		 
		 
		  solve1(vis,mat,r+1,c,r2+1,c2,r1-1,c1,r3-1,c3); solve1(vis,mat,r,c+1,r2,c2-1,r1,c1+1,r3,c3-1); solve1
				 (vis,mat,r+1,c+1,r2+1,c2-1,r1-1,c1+1,r3-1,c3-1);
		 
			
		}
		
		
		
		
		
		
		
		
		
		
		
	    private static int solve(int[][] mat, int i, int c, int j, int c2, int k, int c1, int l, int c3) {
			

			return 0;
		}
      
	    public static int dfs(int parent, LinkedList<Integer>[]list) {
	    	
	    	
	    	for(int i : list[parent]) {
	    		if(list[parent].size() == 0) {
	    			return 0;
	    		}else {
	    			return 1 + dfs(i,list);
	    		}
	    	}
	    	
	    	return 0;
	    	
	    }
	    
	    
	    public static long answer = Integer.MAX_VALUE;
	    
	    
	    public static void min_Time(int [][]dp, int i, HashSet<Integer>set, int min, int r, int c) {
	    	
	    	if(i > r) {
	    		answer = Math.min(answer, min);
	    		return;
	    	}
	    	if(min > answer)return;
	    
	    	    for(int j = i; j <= c; j++) {
	    	    	if(!set.contains(j)) {
	    	    		set.add(j);
	    	    		min += dp[i][j];
	    	    		min_Time(dp,i+1,set,min,r,c);
	    	    		min -= dp[i][j];
	    	    		set.remove(j);
	    	    	}
	    	    }
	    }
	    
	    
	    public static void dp(int [][]dp, int r, int c, int o, int z, long sum) {
	    	  
	    	  if(r > o) {
	    		  answer = Math.min(answer, sum);
	    	  }
	    	  if(r > o || c > z) {
	    		  return;
	    	  }
	    	  if(sum > answer)return;
	    	  sum += dp[r][c];
	    	  
	    	  dp(dp,r+1,c+1,o,z,sum);
	    	  sum -= dp[r][c];
	    	  dp(dp,r,c+1,o,z,sum);
	    	  
	    }
	    
	static    HashSet<ArrayList<Integer>>l = new HashSet<>();
	    
	    
	    public static void fourSum(Deque<Integer>ll, int i, int target, int []ar, int n) {
	    	
	    	if(ll.size() == 4) {
	    		int sum = 0;
	    		ArrayList<Integer>list = new ArrayList<>();
	    
	    		for(int a : ll) {
	    			sum += a;
	    			list.add(a);
	    		}
	    		
	    		if(sum == target) {
	    			
	    			Collections.sort(list);
	    			
	    		
	    			l.add(list);
	    		

	    		}
	    		
	    		return;
	    	}
	    		
	    		   for(int j = i; j < n; j++) {
	    			       
	    			        ll.add(ar[j]);
	    				
	    				   fourSum(ll,j+1,target,ar,n);
	    				     ll.removeLast();
	    			   }
	    		   }
	    
	    	
	    
	     static int id9(int cur, int exchange, int n){
	    	   if(cur == exchange){
		             cur = 0;
		             n++;
		           
		         }
	         if(n == 0)return 0;
	         
	      
	         
	         return 1+ id9(cur+1,exchange,n-1);
	     }
	    
	     
	     
		    public static void fill(int [][]mat, List<Integer>ans, int row_start, int row_end, int col_start, int col_end) {
			    
		    	
		    	for(int i = col_start; i <= col_end; i++) {
		    		ans.add(mat[row_start][i]);
		    	}
		    	
		    	for(int i = row_start+1; i <= row_end; i++) {
		    		ans.add(mat[i][col_end]);
		    	}
		    	if(col_start == col_end)return;
		    	if(row_start == row_end)return;
		    	for(int i = col_end-1; i >= col_start; i--) {
		    		ans.add(mat[row_end][i]);
		    	}
		    	
		    	for(int i = row_end-1; i >= row_start+1; i--) {
		    		ans.add(mat[i][col_start]);
		    	}
		    }
		     
	
	    public static void create(int [][]mat, int j, int i, int k) {
	    	
	    	if(i < 1 || j >= mat.length)return;
	    	
	    	mat[j][i] = k;
	    	create(mat,j+1,i-1,k+1);
	    	
	    	
	    }
	    
	    public static long sum(int [][]mat, int x1, int y1, int x2, int y2) {
	    	
	    	
	    	   long sum = 0;
	    	   while(x1 <= x2) {
	    		   sum += mat[x1][y1];
	    		

	    		   x1++;
	    	   }
	    	   y1++;
	    	   while(y1 <= y2) {
	    		   sum += mat[x2][y1];
	    		   y1++;
	    	   }
	    	   
	    	   return sum;
	    }
	   
	     public static boolean allneg(int []ar, int n) {
	    	 
	    	 for(int i = 0; i < n; i++) {
	    		 if(ar[i] >= 0)return false;
	    	 }
	    	 
	    	 return true;
	     }
	     public static boolean allpos(int []ar, int n) {
	    	 
	    	 for(int i = 0; i < n; i++) {
	    		 if(ar[i] <= 0)return false;
	    	 }
	    	 
	    	 return true;
	     }
	
	     public static int max_pos(int []ar, int n) {
	    	
	    	 int min = Integer.MAX_VALUE;
	    	
	    	for(int i = 1; i < n; i++) {
	    		if(ar[i] > 0) {
	    			break;
	    		}
	    		int a = Math.abs(ar[i]-ar[i-1]);
	    		min = Math.min(min, a);
	    	}
	    	int c = 0;
	    	boolean zero = false;
	    	TreeSet<Integer>set = new TreeSet<>();
	    	int neg = 0;
	    	for(int i = 0; i < n; i++) {
	    		if(ar[i] <= 0) {neg++; if(ar[i] == 0) zero = true; continue;}
	    	    if(ar[i] <= min) {
	    	    	c = 1;
	    	    }
	    	}
	    	
	    	neg += c;
	    	return neg;
	    	
	    	
	    	
	    	
	     }
	
	      
	     static final int MAX = 10000000;
	     
	  

	  

	  static int prefix[] = new int[MAX + 1];
	   
	  static void buildPrefix() {
	       
	      

	      

	      

	      boolean prime[] = new boolean[MAX + 1];
	      Arrays.fill(prime, true);
	   
	      for (int p = 2; p * p <= MAX; p++) {
	   
	      

	      

	      if (prime[p] == true) {
	   
	          

	          for (int i = p * 2; i <= MAX; i += p)
	          prime[i] = false;
	      }
	      }
	   
	      

	      prefix[0] = prefix[1] = 0;
	      for (int p = 2; p <= MAX; p++) {
	      prefix[p] = prefix[p - 1];
	      if (prime[p])
	          prefix[p]++;
	      }
	  }
	  
	  static int query(int L, int R)
	  {
	      return prefix[R] - prefix[L - 1];
	  }
	    
	   static void alter(int n) {	 
	    	 
	  int ans = 0;
	  
	  
	  boolean []vis = new boolean[n+1];
	
	  
	  for(int i = 2; i <= n; i++){
		  boolean p = false;
		  if(vis[i] == false) {
		   for(int j = i; j <= n; j+=i) {
			       if(vis[j] == true) {
			    	   p = true;
			       }else {
			    	   vis[j] = true;
			       }
		   }
		   if(!p)ans++;
	  }
	  }
	  
	  System.out.println(ans);
}
	     
	     public static void solveDK(int []dp, int i, int D, int K) {
	    	 
	    	 int d = D/K;
	    	 int ans = -1;
	    	 int ind = d+1;
	    	 
	    	 while(ind < i) {
	    		 int temp = i/ind;
	    		 
	    		 temp--;
	    		 if(dp[temp*ind] == temp) {
	    			 ans = dp[temp*ind]+1;
	    			 dp[i] = ans;
	    			 break;
	    		 }
	    		 ind = ind*2;
	    	 }
	    	 if(ans == -1)
	    	 dp[i] = 1;
	    	 
	    	
	     }
	     
	     
public static void solveKD(int []dp, int i, int D, int K) {
	    	 
	    	 int d = K/D;
	    	 int ans = -1;
	    	 int ind = d+1;
	    	 
	    	 while(ind < i) {
	    		 int temp = i/ind;
	    		 
	    		 temp--;
	    		 if(dp[temp*ind] == temp) {
	    			 ans = dp[temp*ind]+1;
	    			 dp[i] = ans;
	    			 break;
	    		 }
	    		 ind = ind*2;
	    	 }
	    	 if(ans == -1)
	    	 dp[i] = 1;
	    	 
	    	  
	     }
static int countGreater(int arr[], int n, int k)
{
    int l = 0;
    int r = n - 1;
 
    

    

    int leftGreater = n;
 
    

    while (l <= r) {
        int m = l + (r - l) / 2;
 
        

        

        if (arr[m] > k) {
            leftGreater = m;
            r = m - 1;
        }
 
        

        

        else
            l = m + 1;
    }
 
    

    return (n - leftGreater);
}
 
static ArrayList<Integer>id14(int n)
{
    

	  
	  ArrayList<Integer>list = new ArrayList<>();
	  
    for (int i=1; i<=Math.sqrt(n); i++)
    {
        if (n%i==0)
        {
            

            if (n/i == i)
               list.add(i);
  
            else 

               list.add(i);
               list.add(n/i);
        }
    }
    
    return list;
}

static  List<List<Integer>>result = new ArrayList<>();
  
  public static void comb(List<Integer>list, int n, int i, int []ar) {
  	
  	if(i >= n)return;
  
  		result.add(new ArrayList<>(list));
  	
  	
  	
  	
  	   for(int j = i; j < n; j++) {
  		   list.add(ar[j]);
  		   comb(list,n,i+1,ar);
  		   list.remove(list.size()-1);
  	   }
  	   return;
  }
  
   static boolean isPossible(String s, String str, int i, int j) {
  

  	 int x = i;
  	 int y = j;
  	 while(i >= 0 && j < str.length()) {
  		 if(s.charAt(i) != str.charAt(j)) {
  			 break;
  		 }
  		 i--;
  		 j++;
  	 }
  	
  	 if(j == str.length()) {
  		 System.out.println(x+" "+y);
  		 return true;
  	 }
  	 
  	 return false;
   }
  
     
     
   static  void leftRotate(int l, int r,int arr[], int d)
     {
         for (int i = 0; i < d; i++)
             id12(l,r,arr);
     }
  
     static void id12(int l, int r,int arr[])
     {
         int i, temp;
         temp = arr[l];
         for (i = l; i < r; i++)
             arr[i] = arr[i + 1];
         arr[r] = temp;
     }
     
   static  class Pair {
    	    int x;
    	    int y;
    	  
    	    

    	public Pair(int x, int y)
    	    {
    	        this.x = x;
    	        this.y = y;
    	    }
    	}
    static class Compare1{
    	  
    	    static void compare(Pair arr[], int n)
    	    {
    	        

    	        Arrays.sort(arr, new Comparator<Pair>() {
    	            @Override public int compare(Pair p1, Pair p2)
    	            {
    	                return p2.x - p1.x;
    	            }
    	        });
    	  
    	      
    	    }
    	}
   
    
    static long modInverse(long a, long m)
    {
        long m0 = m;
        long y = 0, x = 1;
 
        if (m == 1)
            return 0;
 
        while (a > 1) {
            

            long q = a / m;
 
            long t = m;
 
            

            

            m = a % m;
            a = t;
            t = y;
 
            

            y = x - q * y;
            x = t;
        }
 
        

        if (x < 0)
            x += m0;
 
        return x;
    }
    static long power(long x, long y, long p)
    {
      long res = 1; 

   
      x = x % p; 

      

   
      if (x == 0)
        return 0; 

   
      while (y > 0)
      {
   
        

        if ((y & 1) != 0)
          res = (res * x) % p;
   
        

        y = y >> 1; 

        x = (x * x) % p;
      }
      return res;
    }
    
      static long id2(long n, long k)
      {
      
        long mod = 1000000007;

        long ansss = 0;
        while(n > 0)
        {
     
          

          long p = (long)(Math.log(n) / Math.log(2));;
     
          

           long temp = (long)power(k,p,mod);
           ansss += temp;
           ansss %= mod;
        		   
                
          

          n %= (long)Math.pow(2, p);
        }
     
        

      
      
      
        return ansss%mod
        		;
      } 
      
         static boolean pos (int [][]mat, int r, int c, int n, boolean [][]vis) {
        	 if(r <= 0 || c <= 0 || r > 2 || c > n )return false;
        	 if(r == 2 && c == n)return true;
        	 
        	 if(vis[r][c])return false;
        	 vis[r][c] = true;
        	 if(mat[r][c] == 1)return false;
        	 
        	 boolean a = pos(mat,r+1,c,n,vis);
        	 boolean b = pos(mat,r,c+1,n,vis);
        	 boolean d = pos(mat,r+1,c+1,n,vis);
        	 boolean e = pos(mat,r-1,c+1,n,vis);
        	 
        	 return a || b || d || e;
         }
         
         
         
         
         
      
         static long id5(long x, long y) {
        	    if(x <= y) {
               	 y = x-1;
                 }
               
                  long sq = (long)Math.sqrt(x);
            
               	  
               	   if(y <= sq) {
               		   y--;
               		   long ans = (y*(y+1))/2;
               		    return ans;
               	   }else {
               	       long ans = 0;
               		   long dif = y-sq;
               	   sq -= 2;
               	   if(sq >  1)
               	   ans += (sq*(sq+1))/2;
               	   long d = x/y;
               	   sq+=2;
               	   for(int i = (int)sq; i <= y; i++) {
               		  if(i > 1  ) {
               			  long temp = x/i;
               			  if(x%i < temp)temp--;
               			  ans += temp;
               		  }
               	   }
               	  
               	   return ans;
                  }
         }
         
              static int binary(long []ar, long element, int s, int e) {
            	   	
            	  int mid = (s+e)/2;	
            	

            	  if(s > e)return mid;
            	  if(ar[mid] == element) {
            		  return mid;
            	  }else if(ar[mid] > element) {
            		  return binary(ar,element,s,mid-1);
            	  }else {
            		  return binary(ar,element,mid+1,e);
            	  }
            	  
            	
              }
              
              static boolean id10(HashSet<String>set, String str, int j) {
            	  
            	  
            	    StringBuilder sb = new StringBuilder();
            	    if(j >= str.length()) {
            	    	return true;
            	    }
            	       for(int i = j; i < str.length(); i++) {
            	    	    sb.append(str.charAt(i));
            	    	    String temp = sb.toString();
            	    	    if(set.contains(temp)) {
            	    	    boolean test =	id10(set,str,i+1);
            	    	    if(test)return true;
            	    	    }
            	       }
            	       
            	       return false;
            	       
            	       
            		   
            	   }
                  
            
              static TreeNode buildTree(TreeNode root,int []ar, int l, int r){
                  
                      if(l > r)return null;
                      int len = l+r;
                      if(len%2 != 0)len++;
                      int mid = (len)/2;
                      int v = ar[mid];
                
                      
                      TreeNode temp = new TreeNode(v);
                      root = temp;
                      root.left = buildTree(root.left,ar,l,mid-1);
                      root.right = buildTree(root.right,ar,mid+1,r);
                      
                      return root;
                      
              }
              public static int getClosest(int val1, int val2,
                      int target)
{
if (target - val1 >= val2 - target)
return val2;       
else
return val1;       
}
              public static int findClosest(int start, int end, int arr[], int target)
              {
                  int n = arr.length;
           
                  

                  if (target <= arr[start])
                      return arr[start];
                  if (target >= arr[end])
                      return arr[end];
           
                  

                  int i = start, j = end+1, mid = 0;
                  while (i < j) {
                      mid = (i + j) / 2;
           
                      if (arr[mid] == target)
                          return arr[mid];
           
                      
                      if (target < arr[mid]) {
                  
                          

                          

                          if (mid > 0 && target > arr[mid - 1])
                              return getClosest(arr[mid - 1],
                                            arr[mid], target);
                           
                          
                          j = mid;             
                      }
           
                      

                      else {
                          if (mid < n-1 && target < arr[mid + 1])
                              return getClosest(arr[mid],
                                    arr[mid + 1], target);               
                          i = mid + 1; 

                      }
                  }
           
                  

                  return arr[mid];
              }
              static int lis(int arr[], int n)
              {
                  int lis[] = new int[n];
                  int i, j, max = 0;
           
                  
                  for (i = 0; i < n; i++)
                      lis[i] = 1;
           
                  
                  for (i = 1; i < n; i++)
                      for (j = 0; j < i; j++)
                          if (arr[i] >= arr[j] && lis[i] < lis[j] + 1)
                              lis[i] = lis[j] + 1;
           
                  
                  for (i = 0; i < n; i++)
                      if (max < lis[i])
                          max = lis[i];
           
                  return max;
              }
           static   List<List<Integer>>res = new ArrayList<>();
              public static void lists(List<Integer>list, List<Integer>temp, int target, int j) {
            	  
            	   int sum = 0;
            	   for(int i = 0;  i < temp.size(); i++) {
            		   sum += temp.get(i);
            	   }
            	   if(sum > target) {
            		   return;
            	   }else if(sum == target) {
            		    Collections.sort(temp);
            		   boolean exist = false;
            		   for(List<Integer>l : res) {
            		    	if(l.size() == temp.size()) {
            		    	    int c = 0;
            		    		for(int i = 0; i < l.size(); i++) {
            		    			if(l.get(i) == temp.get(i))c++;
            		    		}
            		    		if(c == l.size()) {exist = true; break;}
            		    	}
            		    }
            		    if(!exist) {
            		    	res.add(new ArrayList<>(temp));
            		    }
            		   
            		   
            	   }else if(j == list.size())return;
            	    for(int i = j; i < list.size(); i++){
            	    	temp.add(list.get(i));
            	    	lists(list,temp,target,i+1);
            	    	temp.remove(temp.size()-1);
            	    	
            	    }
            	    return;
            	     
              } 
              
             
              static int min_cost = 0;
              
              static void dfs(int p, int c, int vis[][], int [][]mat, int cost[][], LinkedList<Integer>[]list) {
            	  
            	  if(p != -1 && vis[p][c] == 0 && mat[p][c] == 0) {
            		 min_cost += cost[p][c];
            		 System.out.println("df");
            	  }
            	  System.out.println(p+" "+c);
            	   for(int i : list[c]) {
            		   if(i != p && vis[c][i] == 0) {
            			   vis[c][i] = 1;
            			 
            			   dfs(c,i,vis,mat,cost,list);
            		   }
            	   }
              }
              
              static void id11 () {
            	
            	  
              }
              
              
                      
	 	   		public static void main(String args[])throws IOException {
	        	   			 
	 	  
	 	       

	 	         	  BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
	 	             BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	 	            
	 	              
	 	            	   
	 	            	   int t = Integer.parseInt(ob.readLine());
	 	            	   
	 	            	   while(t --> 0) {
	 	            		 
	 	            		   
	 	            	  StringTokenizer st = new StringTokenizer(ob.readLine());
	 	            		  int n = Integer.parseInt(st.nextToken());
	 	            		  int m = Integer.parseInt(st.nextToken());
	 	            		  
	 	            		  int OR = 0;
	 	            		  for(int i = 0; i < m; i++) {
	 	            			  st = new StringTokenizer(ob.readLine());
	 	            			  int l = Integer.parseInt(st.nextToken());
	 	            			  int r = Integer.parseInt(st.nextToken());
	 	            			  int or = Integer.parseInt(st.nextToken());
	 	            			  OR |= or;
	 	            		  }
	 	            		  
	 	            		  long mod = 1000000007;
	 	            		  long ans = 1;
	 	            		  for(int i = 1; i <= n-1; i++) {
	 	            			  ans = (ans*2);
	 	            			  ans = ans%mod;
	 	            		  }
	 	            		  
	 	            		  ans = (ans*OR)%mod;
	 	            		  System.out.println(ans);
	 	            	   }
	 	   		}
}
	 	            		
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  
	 	            		  