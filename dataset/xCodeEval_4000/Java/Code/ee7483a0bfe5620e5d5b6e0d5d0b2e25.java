
import java.awt.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.*;


 
 
public class cool {

	private static InputStream stream;
	private static PrintWriter pw;
	
	
	






	static int n;
	static int m;


	

	
	static int Arr[];
	static int tree[];
	
	static int time = 0;
	
	static int[][] dir = {{-1,0},{0,1},{1,0},{0,-1}};

	static int visited[];
	static int visited2[][];
	static Stack<Integer> stack;
	







	static char[][] arr;
	static char[][] ans;








	static ArrayList[] adj;




	static int red[];
	static int black[];
	static int color[];



	static int f = 0;
	static int k = 0;
	static int count = 0;
	static int total = 0;
	static int ini[];
	
	static ArrayList<Node> list;
	static ArrayList<Integer> ind;


	
	public static void main(String[] args){
		

		pw = new PrintWriter(System.out);
		
		Scanner in = new Scanner(System.in);

		int n = in.nextInt();
		int m = in.nextInt();
		in.nextLine();
		
		int[][] a = new int[n][m];
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) 
				a[i][j] = in.nextInt();

		long[][] dp1 = new long[n][m];
		long[][] dp2 = new long[n][m];
		long[][] dp3 = new long[n][m];
		long[][] dp4 = new long[n][m];

		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < m - 1; j++)
				dp1[i][j] = Math.max(i > 0 ? dp1[i - 1][j] : 0L,
						j > 0 ? dp1[i][j - 1] : 0L)
						+ a[i][j];
		
		for (int i = n - 1; i > 0; i--)
			for (int j = m - 1; j > 0; j--)
				dp2[i][j] = Math.max(i < n - 1 ? dp2[i + 1][j] : 0L,
						j < m - 1 ? dp2[i][j + 1] : 0L)
						+ a[i][j];
		
		for (int i = n - 1; i > 0; i--)
			for (int j = 0; j < m - 1; j++)
				dp3[i][j] = Math.max(i < n - 1 ? dp3[i + 1][j] : 0L,
						j > 0 ? dp3[i][j - 1] : 0L)
						+ a[i][j];
		
		for (int i = 0; i < n - 1; i++)
			for (int j = m - 1; j >= 0; j--)
				dp4[i][j] = Math.max(i > 0 ? dp4[i - 1][j] : 0L,
						j < m - 1 ? dp4[i][j + 1] : 0L)
						+ a[i][j];
		
		long max = 0L;
		for (int i = 1; i < n - 1; i++) {
			for (int j = 1; j < m - 1; j++) {
				max = Math.max(max, dp1[i - 1][j] + dp2[i + 1][j] + dp3[i][j - 1] + dp4[i][j + 1]);
				max = Math.max(max, dp1[i][j - 1] + dp2[i][j + 1] + dp3[i + 1][j] + dp4[i - 1][j]);
			}
		}
		System.out.println(max);
		
		
		pw.close();
	}
	
	
	public static void dfs(int i){
		
		if(visited[i] == 1)
			return;
		
		if(color[i] == 1){
			return;
		}
		
		visited[i] = 1;
		

	
		for(int j = 0;j<adj[i].size();j++){
			
			Node p = (Node)adj[i].get(j);
			
			if(color[p.a-1] == 0){
				dfs(p.a-1);
			}else{
				count = 0;
				total = p.b;
				bfs(p.a-1);
				
				red[i] += total;
				black[i] += count;
			}
			
			
		}
		
	}
	
	
	public static long ansf(int i){
    	
		if(color[i] == 1)
			return 0;
		
		if(visited[i] == 1){
			return 0;
		}
		
		visited[i] = 1;
		for(int j = 0;j<adj[i].size();j++){
			Node p = (Node)adj[i].get(j);
			
			if(color[p.a-1] == 0 && visited[p.a-1] == 0){
				red[i] += ansf(p.a-1) + p.b*black[p.a-1]+ red[p.a-1];
				black[i] += black[p.a - 1];
			}
		
		}
		

		return red[i];
	
    	
    }
	
	
	public static void bfs(int i){
		if(visited[i] == 1){
			return;
		}
		if(color[i] == 0){
			return;
		}
		visited[i] = 1;
		count++;
		
		
		

		for(int j = 0;j<adj[i].size();j++){
			
			Node p = (Node)adj[i].get(j);
			
			if(color[p.a-1] == 1 && visited[p.a-1] == 0){
				

				total += p.b;
				bfs(p.a-1);
			}
		}
		
	}
	
	
	public static long pow(long n,long p,long m){
        long  result = 1;
         if(p==0)
           return 1;
       if (p==1)
           return n;
       while(p!=0)
       {
           if(p%2==1)
               result *= n;
           if(result>=m)
           result%=m;
           p >>=1;
           n*=n;
           if(n>=m)
           n%=m;
       }
       return result;
       }
	

	
	public static int cs(ArrayList<Integer> arr, int low, int high, int x)
	{
	  int mid;    
	 
	  if(x <= arr.get(low))
	    return low; 
	 
	  if(x > arr.get(high))
	    return -1;  
	 
	 
	  mid = (low + high)/2; 
	 
	  if(arr.get(mid) == x)
	    return mid;
	    
	  else if(arr.get(mid) < x)
	  {
	    if(mid + 1 <= high && x <= arr.get(mid+1))
	      return mid + 1;
	    else
	      return cs(arr, mid+1, high, x);
	  }
	   
	  else
	  {
	    if(mid - 1 >= low && x > arr.get(mid-1))
	      return mid;
	    else    
	      return cs(arr, low, mid - 1, x);
	  }
	}
	
	
	public static int fs(int arr[], int low, int high, int x)
	{
	   
	    if (low > high)
	        return -1;
	 
	    if (x >= arr[high])
	        return high;
	 
	    

	    int mid = (low+high)/2;
	 
	    

	    if (arr[mid] == x)
	        return mid;
	 
	    

	    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
	        return mid-1;
	 
	    

	    

	    if (x < arr[mid])
	        return fs(arr, low, mid-1, x);
	 
	    

	    

	    return fs(arr, mid+1, high, x);
	}
	 

	public static long gcd(long x, long y) {
		if (x == 0)
			return y;
		else
			return gcd( y % x,x);
	}
	
























































	
	
	
	
	
	public static int prev(int i,boolean[] arr){
		
		while(arr[i]){
			if(i == 0){
				if(arr[i]){
					return -1;
				}else{
					return 0;
				}
				
				
			}
			
			
			i--;
			
		}
		
		return i;
		
		
	}
	
	
	public static int next(int i,boolean[] arr){
		
		
		while(arr[i]){
			if(i == arr.length-1){
				if(arr[i]){
					return -1;
				}else{
					return 0;
				}
			}
			
			i++;
		}
		
		
		return i;
	}
	

	
	private static Map<String, Integer> sortByValue(Map<String, Integer> unsortMap) {

        

        LinkedList<Entry<String, Integer>> list =
                new LinkedList<Map.Entry<String, Integer>>(unsortMap.entrySet());

        

        

        Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
            public int compare(Map.Entry<String, Integer> o1,
                               Map.Entry<String, Integer> o2) {
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });

        

        Map<String, Integer> sortedMap = new LinkedHashMap<String, Integer>();
        for (Map.Entry<String, Integer> entry : list) {
            sortedMap.put(entry.getKey(), entry.getValue());
        }

        


        return sortedMap;
    }

	
	public static ArrayList<Integer> Range(int[] numbers, int target) {
	  

	    int low = 0, high = numbers.length - 1;
	    

	    int startIndex = -1;
	    while (low <= high) {
	        int mid = (high - low) / 2 + low;
	        if (numbers[mid] > target) {
	            high = mid - 1;
	        } else if (numbers[mid] == target) {
	            startIndex = mid;
	            high = mid - 1;
	        } else
	            low = mid + 1;
	    }

	    

	    int endIndex = -1;
	    low = 0;
	    high = numbers.length - 1;
	    while (low <= high) {
	        int mid = (high - low) / 2 + low;
	        if (numbers[mid] > target) {
	            high = mid - 1;
	        } else if (numbers[mid] == target) {
	            endIndex = mid;
	            low = mid + 1;
	        } else
	            low = mid + 1;
	    }

	    ArrayList<Integer> list = new ArrayList<Integer>();
	    int c = 0;
	    if (startIndex != -1 && endIndex != -1){
	        for(int i = startIndex;i<=endIndex;i++){
	        	list.add(i);
	        }
	    }
	    
	    
	    return list;
	    
	    
	}

	
	
	 private static int root(int Arr[],int i)
	    {
	        while(Arr[ i ] != i)           

	        {
	            Arr[ i ] = Arr[ Arr[ i ] ] ; 
	            i = Arr[ i ];
	        }
	        return i;
	    }
	 
	 private static void union(int Arr[],int size[],int A,int B)
	    {
	        int root_A = root(Arr,A);
	        int root_B = root(Arr,B);
	     
	       System.out.println(root_A + " " + root_B);
	        if(root_A != root_B){
	        	 if(size[root_A] < size[root_B ])
	 	        {
	        		 Arr[ root_A ] = Arr[root_B];
	        		 size[root_B] += size[root_A];	 	
	 	        }
	 	        else
	 	        {   	
	 	        	Arr[ root_B ] = Arr[root_A];
	 	        	size[root_A] += size[root_B];	 	   
	 	        }	
	        }
	    }
	 
	 private static boolean find(int A,int B)
	    {
	        if( root(Arr,A)==root(Arr,B) )       

	        return true;
	        else
	        return false;
	    }
	 
	
	






















































	
	
	


































































































	
	
	
	
	
	
	public static boolean isPrime(int n) {
		

		if (n <= 1)
			return false;
		if (n <= 3)
			return true;
 
		

		

		if (n % 2 == 0 || n % 3 == 0)
			return false;
 
		for (int i = 5; i * i <= n; i = i + 6)
			if (n % i == 0 || n % (i + 2) == 0)
				return false;
 
		return true;
	}
	
		 
	 

	
	
	 
	 

	
	
	 

























































































































}

class Stone implements Comparable<Stone>{
	
	int a;
	int b;
	int c;
	int i;
	
	Stone(int a,int b,int c,int d){
		this.a = a;
		this.b = b;
		this.c = c;
		this.i = d;
	}

	@Override
	public int compareTo(Stone b) {

		if(this.c > b.c){
			return 1;
		}else if(this.c < b.c){
			return -1;
		}else if(this.b > b.b){
			return 1;
		}else if(this.b < b.b){
			return -1;
		}else if(this.a > b.a){
			return 1;
		}else if(this.a < b.a){
			return -1;
		}
		
		return 0;
	}
	

	
	
}


class Node{
	int a;
	int b;
}

class point{
	int a;
	int b;
}


class MyComp2 implements Comparator<Node>{
    
	@Override
	public int compare(Node o1, Node o2) {
		
		if( o1.b > o2.b){
			return 1;
		}else if( o1.b < o2.b){
			return -1;
		}else{
			if(o1.a == o2.a){
				return 0;
			}else if(o1.a > o2.a){
				return 1;
			}else if(o1.a < o2.a){
				return -1;
			}
		}
		
		return 0;
	}
}


class Card implements Comparable<Card>
{
	int a,b;
	public Card(int w,int h)
	{
		this.a=w;
		this.b=h;
		
	}
	public int compareTo(Card that)
	{
		return this.a-that.a;
	}
}
