
import java.util.*;


import java.io.*;
import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;



	public class Solution {










	static class ListNode {
		      int val;
		      ListNode next;
		       ListNode() {}
		      ListNode(int val) { this.val = val; }
		      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
		  }

		
		
		static class TreeNode {
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
		 
		 
		 
		
		    
		    
		       
		          
		       
		    
		    
		    public static int max(int []nums, int s, int e) {
		    	int max = Integer.MIN_VALUE;
		    	
		    	for(int i = s; i <= e; i++) {
		    		max = Math.max(max, nums[i]);
		    	}
		    	
		    	return max;
		    }
		 

		    
		    
		   static int depth(TreeNode root) {
		    	
			   if(root == null)return 0;
			   int a = 1+ depth(root.left);
			   int b = 1+ depth(root.right);
			   
			   return Math.max(a,b);
		    }

		   
		   static HashSet<Integer>set = new HashSet<>();
		   static void deepestLeaves(TreeNode root, int cur_depth, int depth) {
			   
			   if(root == null)return;
			   if(cur_depth == depth)set.add(root.val);
			   
			  deepestLeaves(root.left,cur_depth+1,depth);
			   deepestLeaves(root.right,cur_depth+1,depth);
			   
			   
			   
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
			   deepestLeaves(root,0,d);
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
		   public static void smallest_subTree(TreeNode root) {
			   
			   if(root == null)return;
			   
			   smallest_subTree(root.left);
			   smallest_subTree(root.right);
			   
			   
			   set1 = new HashSet<>();
			   leaves(root);
			   boolean smallest = check(set,set1);
			   
			  if(smallest) {
				  subTree = root;
				  return;
			   
		   }
		 }
		   
		   public static TreeNode answer(TreeNode root) {
			   smallest_subTree(root);
			   
			   return subTree;
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
		
		
		        public static int sumOfDigits (long n) {
			 
		      	 int sum = 0;
			 
		     	 while(n > 0) {
			   	 sum += n%10;
		   		 n /= 10;
			   }
			 
			    return sum;
		 
		    }
		 

		 
	            public static void swap(int []ar, int i, int j) {
			    	 
			    	 
			    	 for(int k= j; k >= i; k--) {
			    		 int temp = ar[k];
			    		 ar[k] = ar[k+1];
			    		 ar[k+1] = temp;
			    	 }
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
			
			
		

		
			
			  public static boolean[] getSieve(int n) {
			        boolean[] isPrime = new boolean[n+1];
			        for (int i = 2; i <= n; i++) isPrime[i] = true;
			        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
			                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
			        return isPrime;
			    }
			  

			  public static Long gcd(Long a, Long b)
			    {
			        if (a == 0)
			            return b;
			          
			        return gcd(b%a, a);
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



			

	          static Long lcm(Long a, Long b)
	          {
	              return (a / gcd(a, b)) * b;
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
		    
		    
		    
		    static int countGreater(int arr[], int n, int k){
	  
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
	 
	     
	     
	     
	     
	     
	      static ArrayList<Integer>printDivisors(int n){
	   
		  
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


	  
	     
	     
	   static  void leftRotate(int l, int r,int arr[], int d)
	     {
	         for (int i = 0; i < d; i++)
	             leftRotatebyOne(l,r,arr);
	     }
	  
	   
	     static void leftRotatebyOne(int l, int r,int arr[])
	     {
	         int i, temp;
	         temp = arr[l];
	         for (i = l; i < r; i++)
	             arr[i] = arr[i + 1];
	         arr[r] = temp;
	     }
	     
	    
			
	  static   class pairInPq<F extends Comparable<F>, S extends Comparable<S>>
	     implements Comparable<pairInPq<F, S>> {
	    	    private F first;
			    private S second;
			    public pairInPq(F first, S second){
			        this.first = first;
			        this.second = second;
			    }
			    
			    public F getFirst(){return first;}
			    public S getSecond(){return second;}
			
	     

	    	
	     @Override
	     public int compareTo(pairInPq<F, S> o) {
	         int retVal =  getSecond().compareTo(o.getSecond());
	         if (retVal != 0) {
	             return retVal;
	         }
	         return getFirst().compareTo(o.getFirst());
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
	              
	           
	              
	        
	              
	              
	              
	              
	              static int LIS(int arr[], int n)
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
	        
	            		   
	            		   
	            	
	              
	        
	               static void permuteString(String s , String answer)
	               {  
	                   if (s.length() == 0)
	                   {
	                       System.out.print(answer + "  ");
	                       return;
	                   }         
	                    
	                   for(int i = 0 ;i < s.length(); i++)
	                   {
	                       char ch = s.charAt(i);
	                       String left_substr = s.substring(0, i);
	                       String right_substr = s.substring(i + 1);
	                       String rest = left_substr + right_substr;
	                       permuteString(rest, answer + ch);
	                   }
	               }
	              
	           
	          
	               static boolean isPowerOfTwo(long n)
	               {
	                   if(n==0)
	                   return false;
	                
	               return (int)(Math.ceil((Math.log(n) / Math.log(2)))) ==
	                      (int)(Math.floor(((Math.log(n) / Math.log(2)))));
	               }
	               
	               
	           static class Pair1{
	        	   long x;
	        	   long y;
	        	   
	        	      public Pair1(long x, long y) {
	        	    	  this.x = x;
	        	    	  this.y = y;
	        	      }
	           }
	             
	     
	             static  class Pair {
	       	    int x;
	       	    int y;
	       	    
	       	    

	       public	 Pair(int x, int y)
	       	    {
	       	        this.x = x;
	       	        this.y = y;
	     
	       	   
	       	    }
	             }
	       
	       static class Sorting implements Comparator<Pair>{
	           public int compare(Pair p1, Pair p2){
	               if(p1.x==p2.x){
	                   return p1.y-p2.y;
	               }
	               return p1.x - p2.x;
	           } 
	       }
	       
	 
	       	
	           static class Compare1{
	         	  
	       	    static void compare(Pair arr[], int n)
	       	    {
	       	        

	       	        Arrays.sort(arr, new Comparator<Pair>() {
	       	            @Override public  int compare(Pair p1, Pair p2)
	       	            {
	       	                return p1.x - p2.x;
	       	            }
	       	        });
	       	  
	       	      
	       	    }
	       	}
	           
	        
	            
	     
	        static int min;
	        static int max;
	      static  LinkedList<Integer>[]adj;
	      static int n;
	        static void insertlist(int n) {
	        	for(int i = 0; i <= n; i++) {
	        		adj[i] = new LinkedList<>();
	        	}
	        }
	        
	      
	      static  int []ar;
	      static boolean []vis;
	      static   HashMap<Key,Integer>map;
	      static ArrayList<Integer>list;
	        static int dfs(int parent, int child,LinkedList<Integer>[]adj) {
	   
	            
	              list.add(parent);
	        	  for(int a : adj[parent]) {
	        		   if(vis[a] == false) {
	        			   vis[a] = true;
	        			   return 1+dfs(a,parent,adj);
	        		   }
	        	  }
	        	  return 0;
	        	  
	        }
	        
	        static StringTokenizer st;	 
	        static BufferedReader ob;
	       
	      static int [] readarrayInt( int n)throws IOException	{
	    	  st = new StringTokenizer(ob.readLine());
	    	  int []ar = new int[n];
	    	  for(int i = 0; i < n; i++) {
	    		  ar[i] = Integer.parseInt(st.nextToken());
	    	  }
	    	  return ar;
	      }
	      
	      static long [] readarrayLong( int n)throws IOException	{
	    	  st = new StringTokenizer(ob.readLine());
	    	  long []ar  = new long[n];
	    	  for(int i = 0; i < n; i++) {
	    		  ar[i] = Long.parseLong(st.nextToken());
	    	  }
	    	  return ar;
	      }
	      
	      static int readInt()throws IOException {
	    
	    	return  Integer.parseInt(ob.readLine());
	    	 
	      }
	        		 
	      static long readLong()throws IOException {
	    	
	    	  return Long.parseLong(ob.readLine());
	    	  
	     }
	      
	      static int nextTokenInt() {
	    	  
	    	  return Integer.parseInt(st.nextToken());
	      }
	      
	      static long nextTokenLong() {
	    	  return Long.parseLong(st.nextToken());
	      }
	      
	      static int root(int u) {
	    	   if(ar[u] == -1)return -1;
	    	    if(u == ar[u]) {
	    	    	return u;
	    	    }
	    	    return root(ar[u]);
	      }
	   static  Pair []pairar;
	     
	      static int numberOfDiv(long num) {
	    	  
	    	  int c = 0;
	    	  for(int i = 1; i <= Math.sqrt(num	); i++) {
	    		  if(num%i == 0) {
	    			  long d = num/i;
	    			  if( d == i)c++; else c += 2;
	    		  }
	    	  }
	    	  return c;
	      }
	      static long ans;
	      static int count;
	     
	    static  boolean []computed;
	      static void NoOfWays(int n) {
	    	
	    	  if(n == 0 ) {
	    	
	    		  count++;
	    	  }
	    	  if(n <= 0)return;
	    	 
	    	  
	    	  for(int i = 1; i <= n; i++) {
	    		  if(n+i <= n)
	    		  NoOfWays(n-i);
	    		
	    		
	    	  }
	    	  }
	    	 
	    	 
	         static boolean binarylistsearch( List<Integer>list, int l, int r, int s, int e) {
	        	   
	        	 if(s > e)return false;
	        	   int mid = (s+e)/2;
	        	   
	        	   if(list.get(mid) >= l && list.get(mid) < r) {
	        		   return true;
	        	   }else if(list.get(mid) > r) {
	        		   return binarylistsearch(list,l,r,s,mid-1);
	        	   }else if(list.get(mid) < l) {
	        		   return binarylistsearch(list,l,r,mid+1,e);
	        	   }
	        	   
	        	   return false;
	        	   
	         }
	      
	        static int [][] readmatrix(int r, int c)throws IOException{
	        	int [][]mat = new int[r][c];
	        	
	        	
	        	for(int i = 0; i < r; i++) {
	        		st = new StringTokenizer(ob.readLine());
	        		for(int j = 0; j < c; j++) {
	        			mat[i][j]  = nextTokenInt();
	        		}
	        	}
	        	return mat;
	        }
	      
	         static HashSet<Integer>set1;
	         static boolean possible;
	         static int c = 0;
	        static void isbeautiful(HashSet<Integer>s,int num, List<Integer>good, int i, int x, int count) {
	        	
	        	  if(c == 2) {
	        		  possible = true;
	        		  return;
	        	  }
	        	  
	        	
	        
	        	  if(num >x || i == good.size())return;
	        	
	        	
	        
	        	if(num > x)return;
	        	if(i >= good.size())return;
	        
	        	for(int j = i; j < good.size(); j++) {
	        		 
	                  if(!map.containsKey(new Key(num,good.get(j))) && 
	                		  !map.containsKey(new Key(good.get(j),num))){
	                	  if(s.contains(num) && s.contains(good.get(j)))
	                	  map.put(new Key (num,good.get(j)),1);
	                	isbeautiful(s,num*good.get(j),good,i,x,count);
	                  }
	        	}
	        }
	        static long sum;
	        static long mod;
	    
	      static void recur(HashSet<Integer>set,HashMap<Integer,HashSet<Integer>>map, int n, int j) {
	    	  
	    	       if(j > n)return;
	            	int v = 0;
	            	
	            	for(int a : set) {
	            		if(map.get(j).contains(a)) {
	            			v++;
	            		}
	            	}
	            
	            	long d = map.get(j).size()-v;
	            	
	            	sum = (sum*d)%mod;
	            	
	            	HashSet<Integer> temp = map.get(j);
	            	
	            	  for(int num : temp) {
	            		  if(!set.contains(num)) {
	            			  set.add(num);
	            			  recur(set,map,n,j+1);
	            			  set.remove(num);
	            		  }
	            	  }
	            	  
	            	  
	            	  
	            }
	      
	    	  
	      static int key1;
		   static int key2;
	    	
		   
		   static HashSet<Integer>set;
	    	  
	     public static TreeNode lowestCommonAncestor(TreeNode root) {
	    	 
	    	 
	    	 if(root == null)return null;
	    	 
	    	 TreeNode left = lowestCommonAncestor(root.left);
	    	 TreeNode right =lowestCommonAncestor(root.right);
	    	
	    	
	    	 
	    	 if(left == null && right != null) {
	    		  System.out.println(right.val);
	    		 return right;
	    	 }else if(right == null && left != null) {
	    	System.out.println(left.val);
	    		 return left;
	     }else if(left == null && right == null) {
	    	 return null;
	     }else {
	    	 System.out.println(root.val);
	    	 return root;
	     }
	     }
	     
	     
	    static ArrayList<Integer>res;
	 
	    static boolean poss = false;
	    public static void recur1 (char []ar, int i) {
	    	
	    	if(i >= ar.length) {
	    	
	    	  boolean isPalindrome  = false;	
	    	 for(int k = 0; k < ar.length; k++) {
	    		for(int j = 0; j < ar.length; j++) {
	    	      if(j-k+1 >= 5) {
	    	    	  int x = k;
	    	    	  int y = j;
	    	    	  while(x < y && ar[x] == ar[y]) {
	    	    		  x++;
	    	    		  y--;
	    	    	  }
	    	    	  if(x == y || x > y) {
	    	    		  isPalindrome = true;
	    	    		  
	    	    		
	    	    	  }
	    	      }
	    		}
	    	
	    		}
	    	    if(!isPalindrome) {
	    	    	poss = true;
	    	    }
	    	 
	    	}
	    		
	    			 
			
	    			
	    if(i < ar.length && ar[i] == '?' ) {
	    	ar[i] = '0';
	    	recur1(ar,i+1);
	    	ar[i] = '?';
	    }
	   
	    if(i < ar.length && ar[i] == '?') {
	    	ar[i] = '1';
	    	recur1(ar,i+1);
	    	ar[i] = '?';
	    }
	    if(i < ar.length && ar[i] != '?') {
	    	recur1(ar,i+1);
	    }
	    }
	    
	    static int []theArray;

	    
	    
	    static int rotate(int []ar, int element, int i) {
	         int count = 0;
	    	while(ar[i] != element) {
	    		int last = ar[i];
	    		count++;
	    		int prev = ar[1];
	    		for(int j = 2; j <= i; j++) {
	    			int temp  = ar[j];
	    			ar[j] = prev;
	    			prev = temp;
	    		}
	    		ar[1] = prev;
	    		
	    	}
	    	return count;
	    }
	    
	    
	    static int []A;
	    
	    static long nth(long max, long min, int n){
	        
	        
	        
	        long mod = 1000000007;
	        if(max%min == 0){
	            System.out.println(min*n);
	        	return (min*n)%mod;
	            
	        }else{
	           
	            long d = max/min;
	            d++;
	            long e = n/d;
	            long ans = (max*e)%mod;
	            long r = n%d;
	            long div = (ans/min);
	      
	            long temp = (div*min);
	            long f = (temp*r)%mod;
	            ans = f;
	            if(temp == ans){
	                ans += min;
	            }
	            
	            System.out.println(ans);
	            return ans;
	        }
	    }
	    
	    
	    
	     public static int index(int k, int l, int r) {
	    
	    	 if(r-l == 1) {
	    		 if(ar[r] >= k && ar[l] < k) {
	    			
	    			 return l;
	    		 }
	    	 }else if(l >=  r){
	    		 return l;
	    	 }
	    	 int mid = (l+r)/2;
	    	
	    	 
	    	 if(ar[mid] >= k) {
	    		 return index(k,l,mid-1);
	    	 }else {
	    		 return index(k,mid+1,r);
	    	 }
	    	 
	    	
	    	 
	    	 
	     }
	     
	     public static int remSnakes(int start, int end, int k) {
	    	
	    	 int rem = k-ar[end];
	    	 
	    	 if(start+rem > end ) {
	    		 return 0;
	    	 }else {
	    		 return 1+ remSnakes(start+rem,end-1,k);
	    	 }
	     }
	     
	    	  
	    	static int N;
	   
	    	static int []tree =  new int[2*N];
	    	
	    	static void build(int []arr,boolean odd) {
	    		
	    		for(int i = 0; i < N; i++) {
	    			tree[N+i] = arr[i];
	    		}
	    		
	    		
	    		for(int i = N-1; i > 0; --i) {
	    			int left = i << 1;
	    			int right = i << 1|1;
	    			if(odd)
	    			tree[i] = tree[i<<1]|tree[i<<1|1];
	    			else
	    			tree[i] = tree[i<<1]^tree[i<<1|1];
	    		}
	    		
	    	}
	    	
	    	 

	        static void updateTreeNode(int p, int value, boolean odd)
	        {
	             
	            

	            tree[p + N] = value;
	            p = p + N;
	             
	            

	            for (int i = p; i > 1; i >>= 1)
	                if(odd) 
	            	tree[i >> 1] = tree[i] | tree[i^1];
	                else
	                tree[i >> 1] = tree[i]^tree[i^1];
	        }
	    	
	    	
	    	
	    	static int query(int l ,int r) {
	    		int res = 0;
	    		
	    		

	    	     
	    		 for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
	    			 if((l&1) > 0) {
	    				 res += tree[--r];
	    			 }
	    			 if((r&1) > 0) {
	    				 res += tree[l++];
	    			 }
	    		 }
	    		 
	    		 return res;
	    	}
	    	
	        static int sum1;
	    	static  void min_line(int u, int min) {
	          
	    	      for(int i : adj[u]) {
	    	    	  min_line(i,min);
	    	    	 
	    	      }
	    	      System.out.println(u);                        
	    	    
	    	
	}
	    			  
	    	static class Key1 {

	    		  public final int X;
	    		  public final int Y;

	    		  public Key1(final int X, final int Y) {
	    		    this.X = X;
	    		    this.Y = Y;
	    		  }

	    		  public boolean equals (final Object O) {
	    		    if (!(O instanceof Key1)) return false;
	    		    if (((Key1) O).X != X) return false;
	    		    if (((Key1) O).Y != Y) return false;
	    		    return true;
	    		  }

	    		  public int hashCode() {
	    		    return (X << 16) + Y;
	    		  }

	    		}
	    	
	    	static void solve() {
	            
	    		  int []points = new int[26];
	    		  int []top_pos = new int[26];
	    		  
	    		  
	    		  String []ar = {"ABC"};
	    		  Arrays.fill(top_pos, Integer.MAX_VALUE);
	    		  
	    		  for(int i  = 0; i < ar.length; i++) {
	    			  String s = ar[i];
	    			   
	    			   for(int j = 0; j < s.length(); j++) {
	    				   int pos = 97-(s.charAt(j)-'0');
	    				   points[pos] += (j);
	    				   if(j < top_pos[pos]) {
	    					   top_pos[pos] = j;
	    				   }
	    			   }
	    		  }
	    		  
	    		 
	    		  
	    		
	    		   int i = 0;
	    		   boolean []vis = new boolean[26];
	    		   StringBuilder sb = new StringBuilder();
	    		   while(true) {
	    			   
	    			     int min = Integer.MAX_VALUE;
	    			     
	    			     for(int j = 0; j < 26; j++) {
	    			    	 if(vis[j] == false) { 
	    			    	 min = Math.min(min, points[j]);
	    			     }
	    			     }
	    			     if(min == Integer.MAX_VALUE)break;
	    			     PriorityQueue<pairInPq>pq = new PriorityQueue<>();
	    			     for(int j = 0; j < 26; j++) {
	    			    	 if(points[j] == min) {
	    			    		 vis[j] = true;
	    			    		 char c = (char)(j + 'a');
	    			    		 pq.add(new pairInPq(c,top_pos[j]));
	    			    		 
	    			    	 }
	    			     }
	    			     while(pq.size() > 0) {
	    			    	pairInPq p = pq.poll();
	    			    	char c = (char)p.first;
	    			    	sb.append(c);
	    			     
	    			     
	    			     }
	    			     
	    			     
	    		   }
	    		   String res = sb.toString();
	    		   res = res.toUpperCase();
	    		   
	    		   System.out.println(res);
	    		  
	    	}
	    	
	    	static boolean al_sub(String s, String a) {
	    		
	    		int k = 0;
	    		
	    		for(int i = 0; i < s.length(); i++) {
	    			if(k == a.length())break;
	    			if(s.charAt(i) == a.charAt(k)) {
	    				k++;
	    			}
	    		}
	    		return k == a.length();
	    	}
	    	
	    	static String result(String s, String a) {
	    		
	    		char []s_ar = s.toCharArray();
	    		char []a_ar = a.toCharArray();
	    		
	    		StringBuilder sb = new StringBuilder();
	    		
	    	   if(s.length() < a.length()) {
	    		   for(int i = 0; i < s.length(); i++) {
	    			   if(s_ar[i]  == '?')s_ar[i] = 'a';
	    		   }
	    		
	    	   }else {
	    		   if(al_sub(s,a)) {
	    			   return "-1";
	    		   }else {
	    			 int k = 0;
	    			 char element = 'z';
	    			 for(char i = 'a'; i <= 'e'; i++) {
	    				 char []temp = s.toCharArray();
	    				 boolean pos = true;;
	    				 for(int j = 0; j < s.length(); j++) {
	    					 if(temp[j] == '?') {
	    						 temp[j] = i;
	    					 }
	    				 }
	    				
	    				
	    				 boolean sub = false;
	    				
	    				 k = 0;
	    				 for(int j = 0; j < s.length(); j++) {
	    					 if(k == a.length()) {
	    						 pos = false;
	    						 break;
	    							
	    					 }
	    					
	    					 if(a_ar[k] == temp[j]) {
	    						 k++;
	    					 }
	    				 }
	    				
	    				 if(pos && k < a.length()) {
	    					 element = i;
	    					 break;
	    				 }
	    				 
	    			 }
	    		   
	    	  
	    	   
	    			 
	    			 if(element == 'z')return "-1";
	    			 
	    			 for(int i = 0; i < s.length(); i++) {
	    			  if(s_ar[i] == '?') {
	    				  s_ar[i] = element;
	    			  }
	    			  sb.append(s_ar[i]);
	    			 }
	    			 return sb.toString();
	    			 
	    		   }
	    	   }
	    	   return "-1";
	    	}
	    	
	    	static void addNodes(ListNode l, int k) {
	    		if(k > 10 )return;
	    		ListNode temp = new ListNode(k);
	    		l.next = temp;
	    		addNodes(l.next,k+1);
	    		
	    	}

	        static ListNode head;
	    	static int listnode_recur(ListNode tail) {
	    	
	    	      if(tail == null )return 0;
	    	      
	    	       
	    	    	int n =  listnode_recur(tail.next);
	    	     
	    
	    	    
	    	    
	    	    	max =  Math.max(max, tail.val+head.val);
	    	    	
	    	    	head = head.next;
	    	    	
	    	    	return max;
	    	}

	    
	    	 static void recursion(int []fill, int len, int []valid, int k) {
	    	
	    		 if(k == len) {
	    			 int num = 0;
	    				
	    			 for(int i = 0; i < fill.length; i++) {
	    				 num = (num*10)+fill[i];
	    			 }
	    			 System.out.println(num);
	    			 
	    			 if(!set.contains(num)) {
	    				 set.add(num);
	    			 }
	    			 return;
	    		 }
	    		 
	    		 for(int i = 0; i < valid.length; i++) {
	    			 if(fill[k] == 0) {
	    				 fill[k] = valid[i];
	    				 recursion(fill,len,valid,k+1);
	    			     fill[k] = 0;
	    		 }else {
	    			 recursion(fill,len,valid,k+1);
	    		 }
	    		 }
	    	 }
	    	 
	    	    	static long minans(Long []ar,Long max) {
	    	    		  Long one = 0l;
	    	    	      Long two = 0l;
	    	    	      
	    	    		  
	    	    	      for(int i = 0; i < ar.length; i++) {
	    	    	    	 Long d = (max-ar[i])/2;
	    	    	    	 two += d;
	    	    	    	 one += (max-ar[i])%2;
	    	    	      }
	    	    	      Long ans = 0l;
	    	    	                                                   
	    	    	      if(one >= two) {
	    	    	        ans += (two*2);
	    	    	 

	    	    	        one -= two;
	    	    	        if(one > 0)
	    	    	        ans += (one*2)-1;      
	    	    	      }else {
	    	    	    	  ans += (one*2);
	    	    	    	  if(two > 0) {
	    	    	    	  two -= one;
	    	    	    	  Long d = two/3;
	    	    	    	  Long temp = d*3;
	    	    	    	  Long r = two%3;
	    	    	    	  ans += temp;
	    	    	    	  ans += d;
	    	    	    	  if(r == 2) {
	    	    	    		  ans += 3;
	    	    	    	  }else if(r == 1){
	    	    	    		  ans += 2;
	    	    	    	  }
	    	    	    	  }
	    	    	 	}
	    	    	      
	    	    	      if(ans < 0)ans = 0l;
	    	    	    

	    	    	      return ans;
	    	    	}
	    	    	
	    	    	
	    	    	static int binarySearch(long []dif,long left, int s, int e) {
	    	    		if(s > e)return s;
	    	    		int mid = (s+e)/2;
	    	    		
	    	    		if(dif[mid] > left) {
	    	    			return binarySearch(dif,left,s,mid-1);
	    	    		}else {
	    	    			return binarySearch(dif,left,mid+1,e);
	    	    		}
	    	    	}
	    	    	
	    	    	
	    	    	public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	    	    		
	    	    		int size1 = getLength(l1);
	    	    		int size2 = getLength(l2);
	    	    		
	    	    		ListNode head = new ListNode(1);
	    	    		

	    	    		
	    	    		head.next = size1 < size2?helper(l2,l1,size2-size1):helper(l1,l2,size1-size2);
	    	    		
	    	    		if(head.next.val > 9) {
	    	    			head.next.val = head.next.val%10;
	    	    			return head;
	    	    		}
	    	    		
	    	    		return head.next;
	    	    		
	    	    	}
	    	    	
	    	    	
	    	    	
	    	    	public static int getLength(ListNode l1) {
	    	    		int count = 0;
	    	    		
	    	    		while(l1 != null) {
	    	    			l1 = l1.next;
	    	    			count++;
	    	    		}
	    	    		
	    	    		return count;
	    	    	}
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	public static ListNode helper(ListNode l1, ListNode l2, int offset) {
	    	    		
	    	    		if(l1 == null)return null;
	    	    		
	    	    		
	    	    		ListNode result = offset == 0?new ListNode(l1.val+l2.val):new ListNode(l1.val);
	    	    		
	    	    		System.out.println(l1.val+" "+l2.val);
	    	    		
	    	    		ListNode post = offset == 0?helper(l1.next,l2.next,0):helper(l1.next,l2,offset-1);
	    	    	
	    	    		if(post != null && post.val > 9) {
	    	    			result.val += 1;
	    	    			post.val = post.val%10;
	    	    		}
	    	    		
	    	    		result.next = post;
	    	    		
	    	    		return result;
	    	    	}
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	public static ListNode arrayToLinkedList(int []ar, ListNode head) {
	    	    	
	    	    		head = new ListNode(0);
	    	    	   head.next = null;
	    	    		ListNode h = head;
	    	    	
	    	    		for(int i = 0; i < ar.length; i++) {
	    	    			ListNode cur = new ListNode(ar[i]);
	    	    			if(h == null) {
	    	    				h = cur;
	    	    			}else{
	    	    			  h.next = cur;
	    	    			  h = h.next;
	    	    			}
	    	    		}
	    	    	
	    	    		return head.next;
	    	    	}
	    	    	
	    	    	static Long numLessThanN(Long n, int s, int e,Long []powerful) {
	    	    		if(s >= e) {
	    	    			if(powerful[s] > n)return powerful[s-1];
	    	    			return powerful[s];
	    	    		}
	    	    		int mid = (s+e)/2;
	    	    		
	    	    	   if(powerful[mid] == n) {
	    	    		   return powerful[mid];
	    	    	   }else if(powerful[mid] > n && powerful[mid-1] < n) {
	    	    		   return powerful[mid-1];
	    	    	   }else if(powerful[mid] > n){
	    	    		   return numLessThanN(n,0,mid-1,powerful);
	    	    	   }else {
	    	    		   return numLessThanN(n,mid+1,e,powerful);
	    	    	   }
	    	    	}
	                static Long minimumX;
	    	    	static void minX(Long x, Long c) {
	    	    		
	    	    		Long p = 2l;
	    	    		Long a = x;
	    	    		if(x > minimumX)return;
	    	    		if(x == 1)return;
	    	    		while(p*p <= x) {
	    	    			int count = 0;
	    	    			Long num = (long)Math.pow(p, c);
	    	    			
	    	    			
	    	    				Long minx = lcm(num,x);
	    	    		        minx = minx/(gcd(num,x));
	    	    				minimumX = Math.min(minimumX, minx);
	    	    		

	    	    		
	    	    		    	

	    	    		    
	    	    		    if(minx < x) {
	    	    		    	minX(minx,c);
	    	    		    }
	    	    			
	    	    		
	    	    			p++;
	    	    		
	    	    		}
	    	    	}
	    	    	
	    	    	
	    	    	
	    	    	
	    	    	
	    	  static boolean isConsecutive (List<Integer>list) {
	    		  
	    		  for(int i : list) {
	    			  if(i > 3)return false;
	    		  }
	    		  
	    		  int x = 0;
	    		  int y = 0;
	    		  
	    		  for(int i = 0; i < list.size(); i++) {
	    			  if(list.get(i) == 2) {
	    				  x++;
	    				
	    			  }else if(list.get(i) == 3)y++;
	    		  }
	    		  
	    		  
	    		  if(y >= 2 || x >= 3)return false;
	    		  if(x > 0 && y > 0)return false;
	    		  
	    		 
	    		  
	    		  
	    		 return true;
	    	  }
	    	  
	    	  static int []ismean(int []ar, int one, int minusone, int []temp){
	    		  int n = ar.length;
	    		  for(int i = 1; i < n-1; i++) {
	    			  if(temp[i] == 1 && temp[i-1] == -1 && one > 0) {
	    				  one--;
	    				  temp[i+1] = 1;
	    			  }else if(temp[i-1] == -1 && temp[i] == -1 && one > 0) {
	    				  temp[i+1] = 1;
	    				  one--;
	    			  }else if(temp[i] == -1 && temp[i-1] == 1 && minusone > 0) {
	    				  minusone--;
	    				  temp[i+1] = -1;
	    			  }else if(temp[i] == 1 && temp[i-1] == 1 && minusone > 0) {
	    				  minusone--;
	    				  temp[i+1] = -1;
	    			  }else {
	    				  return temp;
	    			  }
	    		  }
	    		  
	    		  return temp;
	    		  
	    	  }
	    	    	static boolean isnottwo(int []ar, int one, int minusone,int temp[]) {
	    	    		int n = ar.length;
	    	    		int []ans = ismean(ar,one,minusone,temp);
	    	    	
	    	    		if(ans[n-1] != -2)return true;
	    	    		return false;
	    	    	}
	    	    	
	    	    	   public static long findClosest(long arr[], long target)
	    	    	    {
	    	    	        int n = arr.length;
	    	    	 
	    	    	        

	    	    	        if (target <= arr[0])
	    	    	            return arr[0];
	    	    	        if (target >= arr[n - 1])
	    	    	            return arr[n - 1];
	    	    	 
	    	    	        

	    	    	        int i = 0, j = n, mid = 0;
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
	    	    	 
	    	    	    

	    	    	    

	    	    	    

	    	    	    

	    	    	    

	    	    	    public static long getClosest(long val1, long val2,
	    	    	                                         long target)
	    	    	    {
	    	    	        if (target - val1 >= val2 - target)
	    	    	            return val2;       
	    	    	        else
	    	    	            return val1;       
	    	    	    }
	    	    	    
	    	    	    
	    	            static int gain(int i) {
	    	            	
	    	            	if(i == 0 || i == n) {
	    	            		return 0;
	    	            	}
	    	            	
	    	            	if(ar[i] > ar[i-1] && ar[i] > ar[i+1] || ar[i] < ar[i-1] && ar[i] < ar[i+1])return 1;
	    	            	
	    	            	return 0;
	    	            }
	    	   
	    	    	   static int number_of_theif(String s ) {
	    	    		   int c = 0;
	    	    		   int n = s.length();
	    	    		   int zero = 0;
	    	    		   
	    	    		   for(char i : s.toCharArray()) {
	    	    			   if(i == '?')c++;
	    	    			   if(i == '0')zero++;
	    	    		   }
	    	    		   
	    	    					   
	    	    		   
	    	    		   if(c == n)return n;
	    	    		   if(zero == n)return 1;
	    	    		   int index = -1;
	    	    		   
	    	    		   for(int i = 0; i < n; i++) {
	    	    			   if(s.charAt(i) == '1') {
	    	    				   index = i;
	    	    			   }
	    	    		   }
	    	    		   
	    	    		   if(index != -1) {
	    	    			   int zero_index = -1;
	    	    			   for(int j = index+1; j < n; j++) {
	    	    				   if(s.charAt(j) == '0') {
	    	    					   zero_index = j;
	    	    					   break;
	    	    				   }
	    	    			   }
	    	    			   if(zero_index == -1) {
	    	    				   return n-index;
	    	    			   }else {
	    	    				  return  zero_index-index+1;
	    	    			   }
	    	    		   }else {
	    	    			  
	    	    			   for(int i = 0; i < n; i++) {
	    	    				   if(s.charAt(i) == '0') {
	    	    					   return i+1;
	    	    				   }
	    	    			   }
	    	    			   
	    	    			  
	    	    		   }
	    	    		   
	    	    		   
	    	    		   return 1;
	    	    		   
	    	    	   }
	    	      
	    	    	   static List<List<Integer>>res0;
	    	    	   static int minpath;
	    	    	   
	    	    	   static void recursion(List<Integer>l, int parent, LinkedList<Integer>[]adj) {
	    	    		   
	    	    		   if(adj[parent].size() == 0) {
	    	    			   l.add(parent);
	    	    			   res0.add(new ArrayList(l));
	    	    			   minpath++;
	    	    			   return;
	    	    		   }else {
	    	    			   l.add(parent);
	    	    			   recursion(l,adj[parent].get(0),adj);
	    	    			    
	    	    			      for(int i = 1; i < adj[parent].size(); i++) {
	    	    			    	    recursion(new ArrayList<>(), adj[parent].get(i),adj);
	    	    			      }
	    	    		   }
	    	    	   }
	    	    		   
	    	    	   static class FastReader {
	    	    	        BufferedReader br; StringTokenizer st;
	    	    	        public FastReader(){
	    	    	            br = new BufferedReader(new InputStreamReader(System.in));
	    	    	        }
	    	    	        String next(){
	    	    	            while (st == null || !st.hasMoreElements()) {
	    	    	                try {st = new StringTokenizer(br.readLine());}
	    	    	                catch (IOException e) {e.printStackTrace();}
	    	    	            }
	    	    	            return st.nextToken();
	    	    	        }
	    	    	        int nextInt(){ return Integer.parseInt(next()); }
	    	    	        long nextLong(){ return Long.parseLong(next()); }
	    	    	        double nextDouble(){ return Double.parseDouble(next()); }
	    	    	        String nextLine(){
	    	    	            String str = "";
	    	    	            try {str = br.readLine();}
	    	    	            catch (IOException e) {e.printStackTrace();}
	    	    	            return str;
	    	    	        }
	    	    	    }
	    	    	   
	    	    	   
	    	    	   static HashMap<Integer,Integer>Amap;
	    	    	   static HashMap<Integer,Integer>Bmap;
	    	    	
	    	    	  static void numberOfPerm(int index, int []A, int []B, int []C, long cur_ans, int n) {
	    	    		  
	    	    		if(index == n) {
	    	    			sum += cur_ans%mod;
	    	    			

	    	    			return;
	    	    		}
	    	    		Amap.remove(A[index]);
	    	    		Bmap.remove(B[index]);
	    	    		
	    	    	  
	    	    		

	    	    	   
	    	    	
	    	    		if(C[index] != 0) {
	    	    			numberOfPerm(index+1,A,B,C,cur_ans,n);
	    	    		

	    	    		}else 
	    	    		if(!set.contains(Amap.get(A[index])) && !set.contains(Bmap.get(A[index])) && 
	    	    		   !set.contains(Amap.get(B[index])) && !set.contains(Bmap.get(B[index])) &&
	    	    		   !set.contains(A[index]) && !set.contains(B[index])){
	    	    			set.add(A[index]);
	    	    			set.add(B[index]);
	    	    			numberOfPerm(index+1,A,B,C,(cur_ans*2)%mod,n);
	    	    		
	    	    		}else {
	    	    			
	    	    			if((!set.contains(Amap.get(A[index])) && !set.contains(Bmap.get(A[index]))
	    	    		
	    	    				&& !set.contains(A[index]))) {
	    	    				  set.add(A[index]);
	    	    				  numberOfPerm(index+1,A,B,C,cur_ans,n);
	    	    			  }else if (!set.contains(Amap.get(B[index])) && !set.contains(Bmap.get(A[index]))
	  	    	    				&& !set.contains(B[index])) {
	    	    				  set.add(B[index]);
	    	    			

	    	    				  numberOfPerm(index+1,A,B,C,cur_ans,n);
	    	    			  }else {
	    	    				  numberOfPerm(index+1,A,B,C,cur_ans,n);
	    	    			  }
	    	    		}
	    	    	  }
	    	    	
	    	    	
	    	    	
	    	    	  
	    	    	  
	    	    	  
	    	    	  
	 	public static void main(String args[])throws IOException {
		        	   			
		 	  

			   ob = new BufferedReader(new InputStreamReader(System.in));
		  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		  BufferedOutputStream out = new BufferedOutputStream(System.out);
		  FastReader sc = new FastReader();
	     	
		
	      
	    int n = sc.nextInt();
	    long q = sc.nextLong();
	    
	    
	    long []ar = new long[n];
	    long sum = 0;
	    HashMap<Integer,Long>map  = new HashMap<>();
	    
	    for(int i = 0;i < n; i++) {
	    	ar[i] = sc.nextLong();
	    	sum += ar[i];
	    	map.put(i, ar[i]);
	    }
	    long cur = -1;
	    
	    while(q --> 0) {
	    	int type = sc.nextInt();
	    	if(type == 2) {
	    		long x = sc.nextLong();
	    		sum = x*n;
	    		cur = x;
	    		map = new HashMap<>();
	    		bw.write(sum+"\n");
	    	}else {
	    		int index = sc.nextInt();
	    		long x = sc.nextLong();
	    		index--;
	    		if(!map.containsKey(index)) {
	    			sum -= cur;
	    			sum += x;
	    			map.put(index, x);
	    		}else {
	    			sum -= map.get(index);
	    			sum += x;
	    			map.put(index, x);
	    		}
	    		bw.write(sum+"\n");
	    		
	    	}
	    }
	    bw.close();
	      }
	 	}
	    
	    
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  
	    	  

