



import java.util.*;


import java.io.*;
import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;





public class run_code {

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
	   static void id2(TreeNode root, int cur_depth, int depth) {
		   
		   if(root == null)return;
		   if(cur_depth == depth)set.add(root.val);
		   
		  id2(root.left,cur_depth+1,depth);
		   id2(root.right,cur_depth+1,depth);
		   
		   
		   
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
		   id2(root,0,d);
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
	   public static void id11(TreeNode root) {
		   
		   if(root == null)return;
		   
		   id11(root.left);
		   id11(root.right);
		   
		   
		   set1 = new HashSet<>();
		   leaves(root);
		   boolean smallest = check(set,set1);
		   
		  if(smallest) {
			  subTree = root;
			  return;
		   
	   }
	 }
	   
	   public static TreeNode answer(TreeNode root) {
		   id11(root);
		   
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
	
	
	        public static int id1 (long n) {
		 
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
		
		
	

	
		
		  public static boolean[] id6(int n) {
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
 
     
     
     
     
     
      static ArrayList<Integer>id24(int n){
   
	  
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
             id20(l,r,arr);
     }
  
   
     static void id20(int l, int r,int arr[])
     {
         int i, temp;
         temp = arr[l];
         for (i = l; i < r; i++)
             arr[i] = arr[i + 1];
         arr[r] = temp;
     }
     
    
		
  static   class id15<F extends Comparable<F>, S extends Comparable<S>>
     implements Comparable<id15<F, S>> {
    	    private F first;
		    private S second;
		    public id15(F first, S second){
		        this.first = first;
		        this.second = second;
		    }
		    
		    public F getFirst(){return first;}
		    public S getSecond(){return second;}
		
     

    	
     @Override
     public int compareTo(id15<F, S> o) {
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
              
              
              
              public static int getClosest(int val1, int val2, int target)        {
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
        
            		   
            		   
            	
              
        
               static void id12(String s , String answer)
               {  
                   if (s.length() == 0)
                   {
                       System.out.print(answer + "  ");
                       return;
                   }         
                    
                   for(int i = 0 ;i < s.length(); i++)
                   {
                       char ch = s.charAt(i);
                       String id23 = s.substring(0, i);
                       String id0 = s.substring(i + 1);
                       String rest = id23 + id0;
                       id12(rest, answer + ch);
                   }
               }
              
           
          
               static boolean id10(long n)
               {
                   if(n==0)
                   return false;
                
               return (int)(Math.ceil((Math.log(n) / Math.log(2)))) ==
                      (int)(Math.floor(((Math.log(n) / Math.log(2)))));
               }
               
               
         
             
     
             static  class Pair {
       	    int x;
       	    int y;
       	    int z;
       	    

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
       	                return p1.y - p2.y;
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
       
      static int [] id9( int n)throws IOException	{
    	  st = new StringTokenizer(ob.readLine());
    	  int []ar = new int[n];
    	  for(int i = 0; i < n; i++) {
    		  ar[i] = Integer.parseInt(st.nextToken());
    	  }
    	  return ar;
      }
      
      static long [] id13( int n)throws IOException	{
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
      
      static int id25() {
    	  
    	  return Integer.parseInt(st.nextToken());
      }
      
      static long id8() {
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
     
      static int id16(long num) {
    	  
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
      static void id14(int n) {
    	
    	  if(n == 0 ) {
    	
    		  count++;
    	  }
    	  if(n <= 0)return;
    	 
    	  
    	  for(int i = 1; i <= n; i++) {
    		  if(n+i <= n)
    		  id14(n-i);
    		
    		
    	  }
    	  }
    	 
    	 
         static boolean id3( List<Integer>list, int l, int r, int s, int e) {
        	   
        	 if(s > e)return false;
        	   int mid = (s+e)/2;
        	   
        	   if(list.get(mid) >= l && list.get(mid) < r) {
        		   return true;
        	   }else if(list.get(mid) > r) {
        		   return id3(list,l,r,s,mid-1);
        	   }else if(list.get(mid) < l) {
        		   return id3(list,l,r,mid+1,e);
        	   }
        	   
        	   return false;
        	   
         }
      
        static int [][] readmatrix(int r, int c)throws IOException{
        	int [][]mat = new int[r][c];
        	
        	
        	for(int i = 0; i < r; i++) {
        		st = new StringTokenizer(ob.readLine());
        		for(int j = 0; j < c; j++) {
        			mat[i][j]  = id25();
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
    	  
     public static TreeNode id7(TreeNode root) {
    	 
    	 
    	 if(root == null)return null;
    	 
    	 TreeNode left = id7(root.left);
    	 TreeNode right =id7(root.right);
    	
    	
    	 
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
    public static void id18 (char []ar, int i) {
    	
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
    	id18(ar,i+1);
    	ar[i] = '?';
    }
   
    if(i < ar.length && ar[i] == '?') {
    	ar[i] = '1';
    	id18(ar,i+1);
    	ar[i] = '?';
    }
    if(i < ar.length && ar[i] != '?') {
    	id18(ar,i+1);
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
     
     public static int id5(int start, int end, int k) {
    	
    	 int rem = k-ar[end];
    	 
    	 if(start+rem > end ) {
    		 return 0;
    	 }else {
    		 return 1+ id5(start+rem,end-1,k);
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
    	
    	 

        static void id19(int p, int value, boolean odd)
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
    			     PriorityQueue<id15>pq = new PriorityQueue<>();
    			     for(int j = 0; j < 26; j++) {
    			    	 if(points[j] == min) {
    			    		 vis[j] = true;
    			    		 char c = (char)(j + 'a');
    			    		 pq.add(new id15(c,top_pos[j]));
    			    		 
    			    	 }
    			     }
    			     while(pq.size() > 0) {
    			    	id15 p = pq.poll();
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
    	static int id22(ListNode tail) {
    	
    	      if(tail == null )return 0;
    	      
    	       
    	    	int n =  id22(tail.next);
    	     
    
    	    
    	    
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
    	    	
    	    	
    	    	public static ListNode id4(ListNode l1, ListNode l2) {
    	    		
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
    	    	
    	    	
    	    	
    	    	
    	    	
    	    	
    	    	public static ListNode id17(int []ar, ListNode head) {
    	    	
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
    	    	
    	    	static Long id21(Long n, int s, int e,Long []powerful) {
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
    	    		   return id21(n,0,mid-1,powerful);
    	    	   }else {
    	    		   return id21(n,mid+1,e,powerful);
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
    	    	
    	    			
    	    			
    	    			
    	    			
    	    			
 	public static void main(String args[])throws IOException {
	        	   			
	 	  

	   ob = new BufferedReader(new InputStreamReader(System.in));
	  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

			
			
			
		   int t = Integer.parseInt(ob.readLine());
		   
		   while(t --> 0) {
			 
			   
			   int n = Integer.parseInt(ob.readLine());
			   int []ar = id9(n);
			   
			   
			   HashSet<Integer>set = new HashSet<>();
			   int []dis = new int[1000000];
			   
			   Arrays.fill(dis, -1);
               int max = Integer.MIN_VALUE;
               
 			   for(int i = 0; i < n; i++) {
				   if(dis[ar[i]] == -1) {
					   dis[ar[i]] = i;
				   }else {
				      int d = i-dis[ar[i]];
				      max = Math.max(max, n-d);
				      dis[ar[i]] = i;
				   }
			   }
 			   if(max == Integer.MIN_VALUE) {
 				   System.out.println(-1);
 			   }else {
 			   System.out.println(max);
	        
		   }
 	}
 	}
}
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
	        
			
	        
	        
	        
			
			
			
	