

import java.io.*;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.*;
import java.io.*;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.*;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;
import java.math.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.Vector;
import static java.lang.Math.sqrt;
import static java.lang.Math.floor;






public class topcoder {
   
	static class pair{
		 
		 long first;
		 long second;
		  public pair(long first, long second) {
			  this.first = first;
			  this.second = second;
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
	
	public static HashMap<Integer,Integer>sortByValue(HashMap<Integer,Integer>hm){
	
		
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
	
	
	 public static int sumOfDigits (long n) {
		 
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
			  
			  static void simpleSieve(int limit, Vector<Integer> prime)
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
			      
			    

			public    static void segmentedSieve(int n, ArrayList<Integer>l)
			    {
			        

			        

			        int limit = (int) (floor(sqrt(n))+1);
			        Vector<Integer> prime = new Vector<>(); 
			  
			        simpleSieve(limit, prime);
			      
			        

			        

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
			    
			    public static int find_indexNum(long k) {
			    	
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
			    	return find_indexNum(rem);
			    }
			    
			 public static void sortPair(ArrayList<pair>l, int n) {
				  n = l.size();
				  
				  Compare obj = new Compare();
				  obj.compare(l, n);
			 }
               
            
			  public static int add(long n, long num, long a, int i) {
				

				  if(num > n)return -1;
				
				  if(num == n) {
					  
					  return i;
				  }
				  
				if(a < 2050)return -1;
				  
				
				 
				  long temp = num+a;
				  
				  if(temp <= n) {
				return	  add(n,temp,a,i+1);
				  }else if(temp > n){
					  a /= 10;
					  return add(n,num,a,i);
				  }
				  
			      return -1;
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
		
		  public static boolean[] getSieve(int n) {
		        boolean[] isPrime = new boolean[n+1];
		        for (int i = 2; i <= n; i++) isPrime[i] = true;
		        for (int i = 2; i*i <= n; i++) if (isPrime[i]) 
		                for (int j = i; i*j <= n; j++) isPrime[i*j] = false;
		        return isPrime;
		    }
		  

		   static long gcd(long a, long b) {
			   
			   if(a == 0)
				   return b;
			   
			   return gcd(b%a,a);
		   }
		    
		    
		
		
		public static boolean poss( int r, int c, int k, int n, int m,boolean [][]vis) {
			
			if(k < 0)return false;
			if(r > n || c > m || r < 1 || c < 1)return false;
			
			if(r == n &&  c == m &&  k == 0) {
			

				return true;
			}
              if(vis[r][c] == true) {
            	  return false;
              }
              vis[r][c] = true;
			
			
		return	poss(r+1,c,k-c,n,m,vis) || poss(r,c+1,k-r,n,m,vis);
			
			
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
	    public static boolean recur(int n, int a, int b) {
	    	
	    	if(n == 0)return true;
	    	if(n < 0)return false;
	    

	    	return recur(n-a,a,b) || recur(n-b,a,b);
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
	
	    public static void main(String args[])throws IOException{
			 
	    	

	    		 BufferedReader ob = new BufferedReader(new InputStreamReader(System.in));
	    	    
	    		 
	    		
	    		    		 
	    		    		 int t = Integer.parseInt(ob.readLine());
	    		    		 
	    		    		 
	    		    		while(t --> 0) {
	    		    		StringTokenizer st = new StringTokenizer(ob.readLine());
	    		    		int h = Integer.parseInt(st.nextToken());
	    		    		int m = Integer.parseInt(st.nextToken());
	    		    		String []ar = ob.readLine().split(":");
	    		    			   
	    		    		int hour = Integer.parseInt(ar[0]);
	    		    		int minute = Integer.parseInt(ar[1]);
	    		    	
	    		    		
	    		    		while (true) {
	    						if (isValid(h, m, hour, minute)) break;
	    						minute++;
	    						
	    						if (minute == m) {
	    							minute = 0;
	    							hour++;
	    						}
	    						
	    						if (hour == h) {
	    							hour = 0;
	    						}
	    					}
	    					
	    				
	    		    		System.out.printf("%02d:%02d\n", hour, minute);
	    		    		}
	    }
	    
	    }
	    
	    		    		
	    		    		
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			
	    		    			