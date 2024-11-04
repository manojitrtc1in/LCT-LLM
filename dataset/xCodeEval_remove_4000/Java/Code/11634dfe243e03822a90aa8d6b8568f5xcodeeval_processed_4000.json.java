



import java.util.*;


import java.io.*;
import java.io.*;
import java.util.*;
import java.math.*;

import static java.lang.Math.sqrt;
import static java.lang.Math.floor;




public class run_code {
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
	   public static void id9(TreeNode root) {
		   
		   if(root == null)return;
		   
		   id9(root.left);
		   id9(root.right);
		   
		   
		   set1 = new HashSet<>();
		   leaves(root);
		   boolean smallest = check(set,set1);
		   
		  if(smallest) {
			  subTree = root;
			  return;
		   
	   }
	 }
	   
	   public static TreeNode answer(TreeNode root) {
		   id9(root);
		   
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
		
		
	

	
		
		  public static boolean[] id4(int n) {
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
 
     
     
     
     
     
      static ArrayList<Integer>id17(int n){
   
	  
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
             id15(l,r,arr);
     }
  
   
     static void id15(int l, int r,int arr[])
     {
         int i, temp;
         temp = arr[l];
         for (i = l; i < r; i++)
             arr[i] = arr[i + 1];
         arr[r] = temp;
     }
     
    
		
  static   class id13<F extends Comparable<F>, S extends Comparable<S>>
     implements Comparable<id13<F, S>> {
    	    private F first;
		    private S second;
		    public id13(F first, S second){
		        this.first = first;
		        this.second = second;
		    }
		    
		    public F getFirst(){return first;}
		    public S getSecond(){return second;}
		
     

    	
     @Override
     public int compareTo(id13<F, S> o) {
         int retVal = getFirst().compareTo(o.getFirst());
         if (retVal != 0) {
             return retVal;
         }
         return getSecond().compareTo(o.getSecond());
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
        
            		   
            		   
            	
              
        
               static void id10(String s , String answer)
               {  
                   if (s.length() == 0)
                   {
                       System.out.print(answer + "  ");
                       return;
                   }         
                    
                   for(int i = 0 ;i < s.length(); i++)
                   {
                       char ch = s.charAt(i);
                       String id16 = s.substring(0, i);
                       String id0 = s.substring(i + 1);
                       String rest = id16 + id0;
                       id10(rest, answer + ch);
                   }
               }
              
           
          
               static boolean id8(long n)
               {
                   if(n==0)
                   return false;
                
               return (int)(Math.ceil((Math.log(n) / Math.log(2)))) ==
                      (int)(Math.floor(((Math.log(n) / Math.log(2)))));
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
       
      static int [] id7( int n)throws IOException	{
    	  st = new StringTokenizer(ob.readLine());
    	  int []ar = new int[n];
    	  for(int i = 0; i < n; i++) {
    		  ar[i] = Integer.parseInt(st.nextToken());
    	  }
    	  return ar;
      }
      
      static long [] id11( int n)throws IOException	{
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
      
      static int id18() {
    	  
    	  return Integer.parseInt(st.nextToken());
      }
      
      static long id6() {
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
    		  int u = id18();
    		  int v = id18();
    		  pairar[i] = new Pair(u,v);
    		  adj[u].add(v);
    		  adj[v].add(u);
    	  }
      }
      static int id14(long num) {
    	  
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
      static void id12(int n) {
    	
    	  if(n == 0 ) {
    	
    		  count++;
    	  }
    	  if(n <= 0)return;
    	 
    	  
    	  for(int i = 1; i <= n; i++) {
    		  if(n+i <= n)
    		  id12(n-i);
    		
    		
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
        			mat[i][j]  = id18();
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
    	  
     public static TreeNode id5(TreeNode root) {
    	 
    	 
    	 if(root == null)return null;
    	 
    	 TreeNode left = id5(root.left);
    	 TreeNode right =id5(root.right);
    	
    	
    	 
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
     
     
    static int res;
   
     static int search(int start, int end,  long x) {
    	
    	 int mid = (start+end)/2;
    	 if(start > end)return mid;;
    	 long temp = (mid*(mid+1))/2;
    	 int mid1 = mid-1;
    	 long r = (mid1*(mid1+1))/2;
    	 temp += r;
    	 System.out.println(temp);
    	 if(temp == x) {
    		 return mid;
    	 }else if(temp > x) {
    		return search(start,mid-1,x);
    	 }else {
    		return search(mid+1,end,x); 
    	 }
     }
        
    	 
    	 
    	private static long calc(long l, long k) {
    		long cnt = 0;
    		if(l <= k) {
    			cnt = l*(l+1)/2;
    			
    		}else {
    			cnt = k*(k+1)/2;
    			l -= k;
    			cnt +=  l*(k-1 + k-l)/2;
    			
    		}
    		return cnt;
    	}
   
   
    	 
    	 public static boolean isPos(int mid, int a, int b) {
    		 
    		 if(a > mid && b > mid)
    			 return false;
    		 
    		 if(a <= mid && b <= mid )
    			 return false;
    		 
    		 if(a >= mid+2)return false;
    		 if(b <= mid-1)return false;
    		 
    		 return true;
    	 }
    	 
    	 
 	public static void main(String args[])throws IOException {

	   ob = new BufferedReader(new InputStreamReader(System.in));
	  BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	
	  int t = readInt();
	  
	  while(t --> 0){
		  
		st = new StringTokenizer(ob.readLine());
		int n = id18();
		int a = id18();
		int b = id18();
		
		int mid = n/2;
		
		boolean ans = isPos(mid,a,b);
		if(!ans) {
			System.out.println(-1);
		}else {
			System.out.print(a+" ");
			
			int k = n;
			int i = 0;
			while(i < mid-1) {
				if(k != a && k != b) {
				System.out.print(k+" ");
				i++;
				}
				k--;
				
			}
			i = 0;
           k = 1;
          
           
     
           
           
           System.out.print(b+" ");
           while(i < mid-1) {
        	   if(k != a && k != b) {
        		   System.out.print(k+" ");
        		   i++;
        	   }
        		   k++;
        		 
           }
           
           System.out.println();
		}
	  }
 	}
}
