

import java.util.*;


import java.io.*;
import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;




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
	   public static void id7(TreeNode root) {
		   
		   if(root == null)return;
		   
		   id7(root.left);
		   id7(root.right);
		   
		   
		   set1 = new HashSet<>();
		   leaves(root);
		   boolean smallest = check(set,set1);
		   
		  if(smallest) {
			  subTree = root;
			  return;
		   
	   }
	 }
	   
	   public static TreeNode answer(TreeNode root) {
		   id7(root);
		   
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
		
		
	

	
		
		  public static boolean[] id3(int n) {
		        boolean[] isPrime = new boolean[n+1];
		        for (int i = 2; i <= n; i++) isPrime[i] = true;
		        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
		                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
		        return isPrime;
		    }
		  

		  public static long gcd(long a, long b)
		    {
		        if (a == 0)
		            return b;
		          
		        return gcd(b%a, a);
		    }

		    
		

          static long lcm(long a, long b)
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
 
     
     
     
     
     
      static ArrayList<Integer>id13(int n){
   
	  
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
             id11(l,r,arr);
     }
  
   
     static void id11(int l, int r,int arr[])
     {
         int i, temp;
         temp = arr[l];
         for (i = l; i < r; i++)
             arr[i] = arr[i + 1];
         arr[r] = temp;
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
        
            		   
            		   
            	
              
        
               static void id8(String s , String answer)
               {  
                   if (s.length() == 0)
                   {
                       System.out.print(answer + "  ");
                       return;
                   }         
                    
                   for(int i = 0 ;i < s.length(); i++)
                   {
                       char ch = s.charAt(i);
                       String id12 = s.substring(0, i);
                       String id0 = s.substring(i + 1);
                       String rest = id12 + id0;
                       id8(rest, answer + ch);
                   }
               }
              
           
          
               static boolean id6(long n)
               {
                   if(n==0)
                   return false;
                
               return (int)(Math.ceil((Math.log(n) / Math.log(2)))) ==
                      (int)(Math.floor(((Math.log(n) / Math.log(2)))));
               }
               
               
         
             
     
             static  class Pair {
       	    int x;
       	    int y;
       	  
       	    

       	 Pair(int x, int y)
       	    {
       	        this.x = x;
       	        this.y = y;
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
        
        static boolean []vis;
      static  int []ar;
      static   HashMap<Integer,Integer>map;
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
       
      static int [] id5( int n)throws IOException	{
    	  st = new StringTokenizer(ob.readLine());
    	  int []ar = new int[n];
    	  for(int i = 0; i < n; i++) {
    		  ar[i] = Integer.parseInt(st.nextToken());
    	  }
    	  return ar;
      }
      
      static long [] id9( int n)throws IOException	{
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
      
      static int id14() {
    	  
    	  return Integer.parseInt(st.nextToken());
      }
      
      static long id4() {
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
      static void addEdges(int m)throws IOException {
    	
    	  
    	  for(int i = 0; i < m; i++) {
    		  st = new StringTokenizer(ob.readLine());
    		  int u = id14();
    		  int v = id14();
    		  pairar[i] = new Pair(u,v);
    		  adj[u].add(v);
    		  adj[v].add(u);
    	  }
      }
      static int id10(long num) {
    	  
    	  int c = 0;
    	  for(int i = 1; i <= Math.sqrt(num	); i++) {
    		  if(num%i == 0) {
    			  long d = num/i;
    			  if( d == i)c++; else c += 2;
    		  }
    	  }
    	  return c;
      }
      static int ans;
 	public static void main(String args[])throws IOException {
	        	   			
	 	  
	
	   ob = new BufferedReader(new InputStreamReader(System.in));
	  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	  int t = readInt();
	  
	  while(t --> 0) {
		 
		  st = new StringTokenizer(ob.readLine());
		  long l = id4();
		  long r = id4();
		  long a  = id4();
		  
		  
		 if(r < a) {
			 System.out.println(r);
		 }else if(l == r && r == a) {
			 
			 System.out.println(1);
		 }else if(a == r){
			 System.out.println(r-1);
		 }else {
			 long max = (r/a)+(r%a);
			 
			 long d = r/a;
			 long x = d*a;
			 if(l < (d)*a) {
				 long temp = (d-1)+(a-1);
				 max = Math.max(max, temp);
			 }
			 System.out.println(max);
		 }
	  }
 	}
}
		  
		  
		  
		  