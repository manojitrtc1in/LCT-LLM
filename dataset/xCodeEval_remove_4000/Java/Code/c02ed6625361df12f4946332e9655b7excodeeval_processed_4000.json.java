import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.stream.IntStream;





import java.util.Comparator;
import java.util.PriorityQueue;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;

import java.util.Arrays;
import java.util.List;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.LinkedList;
import java.util.List;
import java.math.BigInteger;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeMap;
import java.util.TreeSet;

public class  Dragons{
    static class Pair {
        long a;
        long b;
        public Pair(long a, long b2){
            this.a=a;
            this.b=b2;
        }
    }
	class Sol
	{
	    int countRev (String x)
	    {
	         Stack<Character> st=new Stack<Character>();
	            for(int i=0;i<x.length();i++){
	                
	                if(x.charAt(i)=='{'||x.charAt(i)=='('||x.charAt(i)=='['){
	                    st.add(x.charAt(i));
	                }else{
	                    if(st.size()>0){
	                    if(x.charAt(i)=='}' && st.peek()=='{'){
	                        st.pop();
	                    }else if(  x.charAt(i)==')' && st.peek()=='('){
	                        st.pop();
	                    }else if(x.charAt(i)==']' && st.peek()=='['){
	                    st.pop();
	                    }else{
	                       st.add(x.charAt(i));
	                    }
	                    }else{
	                       st.add(x.charAt(i));
	                    }
	                    
	                }
	                
	                
	            }
	             int count1=0;
	  int count2=0;
	            if(st.size()%2!=0){
	              return -1;
	            }else{
	                 Iterator value = st.iterator();
	 
	        while (value.hasNext()) {
	            if((char)value.next()=='}'){
	                count1++;
	            }
	        }
	        count2=st.size()-count1;
	        if(count1%2==0){
	            count1=count1/2;
	            
	        }else{
	            count1=count1/2;
	            count1+=2;
	            count2--;
	        }
	       
	        
	            }
	            return count1+((count2)/2);
	            
	    }
	}
	static ArrayList<ArrayList<Integer>> adjList;
	static boolean[] visit;
	static int max=0;


	
	
    public static HashSet<Long> visited= new HashSet<>();
    public static long n;
    public static long m;
    public static boolean vis[][];
    public static int[] dist = new int[(int) 1e4+1];
    static long id0(long N)
    {
     long w=0;
       while(N!=1) {
    	   N=N/2;
    	   w++;
        }
       return w;
     
        
    }
	public static void main(String[] args) throws IOException {
		  Scanner sc=new Scanner(System.in);
		  int k=sc.nextInt();
		  while(k>0){
			
			 long a=sc.nextLong();
			 long b=sc.nextLong();
			 long c=sc.nextLong();
			 long d=sc.nextLong();
			System.out.println('1'+" "+"1 "+a+" "+b);
		    k--;
		}
	
	}
	static int Max(int arr[])
	{
		int max = arr[0];
		for(int i = 1; i < arr.length; i++)
			if(arr[i] > max)max = arr[i];
		
		return max;
	}
		
	

	

	static int id6(int arr[], int n)
	{
		int maxi = Max(arr);
		
		

		int[] M = new int[2 * maxi + 1];
		
		
		for(int i = 0; i < M.length; i++)M[i] = 0;
	 
		

		

		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				M[(arr[i] + arr[j])] += 1;
			}}
		for(int i=0;i<M.length;i++) {
			System.out.print(M[i]+" ");
		}
		System.out.println();
		int max_count = 0;
	 
		

		for (int i = 0; i < 2 * maxi; i++)
			if (max_count < M[i])
				max_count = M[i];
	 
		return max_count;
	}
























	public static long bs(ArrayList<Long> arr, long x , int l , long r) {
		
		while(l<=r) {
		int m = (int) ((l+r)/2);
		if(arr.get(m)>=x) {
			r = m-1;
		}else {
			l = m+1;
		}
		}
		return l;
		
	}
	public static long gs(ArrayList<Long> arr, long x , long l , long r) {
		
		while(l<=r) {
		int m = (int) ((l+r)/2);
		if(arr.get(m)<=x) {
			r = m+1;
		}else {
			l = m-1;
		}
		}
		return r;
		
	}
	 public static HashMap<Integer, Integer>
	    insertPF(HashMap<Integer, Integer> primeFact,
	             long fact)
	    {
	        if (primeFact.containsKey(fact)) {
	 
	            int freq;
	            freq = primeFact.get(fact);
	            primeFact.replace((int) fact, ++freq);
	        }
	        else {
	            primeFact.put((int) fact, 1);
	        }
	        return primeFact;
	    }
	 
	    

	    

	    public static HashMap<Integer, Integer>
	    primeFactors(long n)
	    {
	 
	        HashMap<Integer, Integer> primeFact
	            = new HashMap<>();
	 
	        

	        

	        while (n % 2 == 0) {
	            primeFact = insertPF(primeFact, 2);
	            n /= 2;
	        }
	 
	        

	        

	        for (int i = 3; i <= Math.sqrt(n);
	             i += 2) {
	 
	            

	            

	            while (n % i == 0) {
	                primeFact = insertPF(primeFact, i);
	                n /= i;
	            }
	        }
	 
	        

	        

	        

	        if (n > 2)
	            primeFact = insertPF(primeFact, n);
	 
	        return primeFact;
	    }
	 
	    

	    

	    public static boolean perfectCube(long n)
	    {
	 
	        HashMap<Integer, Integer> primeFact;
	        primeFact = primeFactors(n);
	 
	        

	        

	        for (int freq : primeFact.values()) {
	            if (freq % 3 != 0)
	                return false;
	        }
	        return true;
	    }
	static String id1(String p,int n) {
		StringBuilder sb=new StringBuilder(p);
		if(p.length()>2) {
		for(int i=0;i<sb.length();i++) {
			
			if(i==0&& sb.charAt(i)=='?') {
				if(sb.charAt(i+1)=='0') {
					sb.setCharAt(i,'1');
				}else if(sb.charAt(i+1)=='1'){
					sb.setCharAt(i,'0');
				}else {
					if(sb.charAt(i+2)=='0') {
						sb.setCharAt(i,'0');
					}else if(sb.charAt(i+2)=='1') {
						sb.setCharAt(i,'1');
					}else {
						sb.setCharAt(i,'1');
					}
				}
			}else if(i==sb.length()-1 && sb.charAt(i)=='?') {
				if(sb.charAt(i-1)=='0') {
					sb.setCharAt(i,'1');
				}else {
					sb.setCharAt(i,'0');
				}
			}else if(sb.charAt(i)=='?'){
				if(sb.charAt(i+1)=='0') {
					
						sb.setCharAt(i,'1');
					
				}else if(sb.charAt(i+1)=='1'){
					sb.setCharAt(i,'0');
				}else if(sb.charAt(i+1)=='?') {
				
					if(sb.charAt(i-1)=='0') {
						sb.setCharAt(i,'1');
					}else {
						sb.setCharAt(i,'0');
					}
				}
			}
		}
		}else {
			if(p.contains("?") && p.length()==1) {
				return "0";
			}else if(p.contains("?")){
				return "01";
			}
		}
		return sb.toString();
		
	}
	 static void addEdge(ArrayList<ArrayList<Integer> > adj,
             int u, int v)
{
adj.get(u).add(v);
adj.get(v).add(u);
}

	static long id5(long n, long l) {
        long res = 1;
        
        if (l > n - l) l = n - l;
        
        for (var i = 0; i < l; ++i) {
            res *= 1L*(n - i);
            res /= 1L*(i + 1);
        }
        
        return res;
    }
	static long nCr(long n, long r)
	{
	    return fact(n) / (fact(r) *
	                  fact(n - r));
	}
	static long fact(long n)
	{
	    long res = 1;
	    for (int i = 2; i <= n; i++)
	        res = res * i;
	    return res;
	}
	 

	static void  dfs(int m) {
		
		
		
		visit[m]=true;
		for(int i=0;i<adjList.get(m).size();i++) {
			int v=adjList.get(m).get(i);
			
			if(!visit[v]) {
				
				max++;
			 dfs(v);
			}
		}
		
		
	}
	static boolean id4(long n) {
		while(n!=1) {
			if(n%2==0) {
				n=n/2;
			}else if(n%3==0){
				n=n/3;
			}else {
				return false;
			}
			
			
		}
		return true;
	}
	static boolean id7(int n){
		while(n>0) {
			int y=n%10;
			n=n/10;
			if(y!=4 && y!=7) {
				return false;
			}
		}
		return true;
	}
	static boolean isInteger(double N)
	{
	 
	    

	    

	    long X = (long)N;
	    double temp2 = N - X;
	 
	    

	    

	    if (temp2 > 0)
	    {
	        return false;
	    }
	    return true;
	}
	static long isrecursive(long p) {
		if(p==0) {
			return 0;
		}else if(p%2==0) {
			return isrecursive(p/2);
		}else {
			return isrecursive(p/2)+1;
		}
		
	}
	static boolean islucky(long  r) {
		String temp = Long.toString(r);
		long[] newGuess = new long[temp.length()];
		long tu=0;
		boolean flag=false;
		
		for (int i = 0; i < temp.length(); i++)
		{
		    newGuess[i] = temp.charAt(i) - '0';
		    if(newGuess[i]==4 || newGuess[i]==7) {
		    	continue;
		    }else {
		    	flag=true;
		    	break;
		    }
		}
		if(flag) {
			return false;
		}
		return  true;
	}
	static int distance(long l,long m) {
		return (int) (Math.pow(l,2)+Math.pow(m,2));
	}
	static int id8(int N)
	{
	  
	    

	    if (N == 0)
	        return 2;
	    if (N == 1)
	        return 1;
	  
	    int prime = N, counter = 0;
	    boolean found = false;
	  
	    

	    

	    while (!found) {
	        if (isPrime(prime))
	            found = true;
	        else {
	  
	            

	            

	            

	            

	            prime++;
	            counter++;
	        }
	    }
	  
	    return counter;
	}
	static boolean isPrime(int n)
	{
	    

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
	
	
		static int mod(int a, int m)
		{
		    return (a%m + m) % m;
		}
		
	static long getSum(long y)
    {
       long sum = 0;
 
        while (y != 0) {
            sum = sum + y % 10;
            y = y / 10;
        }
 
        return sum;
    }
	static boolean detect(int arr[],int x) {
		long sum=0;
		for(int i=0;i<arr.length;i++) {
			sum+=arr[i];
			if(sum==x) {
				return true;
			}
			
		}
		return false;
	}
	
    static class Node {
        String s;
        int val;
 
        public Node(String a, int v) {
            val = v;
            s = a;
        }
    }
	  
	 public static HashMap<Integer,Long> id2(HashMap<Integer,Long> hm)
	    {
	        

	        List<Map.Entry<Integer,Long> > list =
	               new LinkedList<Map.Entry<Integer,Long> >(hm.entrySet());
	 
	        

	        Collections.sort(list, new Comparator<Map.Entry<Integer,Long> >() {
				@Override
				public int compare(Entry<Integer,Long> o1, Entry<Integer,Long> o2) {
					return (int)-(o1.getValue()-o2.getValue());
				}
	        });
	         
	        

	        HashMap<Integer,Long> temp = new LinkedHashMap<Integer,Long>();
	        for (Map.Entry<Integer,Long> aa : list) {
	            temp.put(aa.getKey(), aa.getValue());
	        }
	        return temp;
	    }
	
	 static long lcm(long a, long b)
	    {
	        return (a / gcd(a, b)) * b;
	    }
static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int nextInt() {
			return Integer.parseInt(next());
		}
		int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		long nextLong() {
			return Long.parseLong(next());
		}
	}
	
	


























	
	static long gcd(long a, long b) {
		return a%b == 0 ? b : gcd(b,a%b);
	}
	 static int getSum(int n)
	    {
	        int sum = 0;
	 
	        while (n != 0) {
	            sum = sum + n % 10;
	            n = n / 10;
	        }
	 
	        return sum;
	    }
	
	static boolean[] sieve(int n) {
		
		
		boolean isPrime[] = new boolean[n+1];
		for(int i = 2; i <= n; i++) {
			if(isPrime[i]) continue;
			for(int j = 2*i; j <= n; j+=i) {
				isPrime[j] = true;
			}
		
		} 
		return isPrime;
		
	}
	public static long SubString(String str, int n,long count)
	{
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j <= n; j++) {
			
				String y=id1(str.substring(i, j),str.substring(i, j).length());
				
				if(y.length()==1) {
					count++;
				}else if(y.contains("00")||y.contains("11") ) {
					continue;
				}else {
					count++;
				}
		}
	}
	return count;
	}
    

    

    static boolean id3(int[] arr)
    {
        int n = arr.length;
 
        

        

        int[] count = new int[10000];
        int visited[] = new int[10000];
 
        for (int i = 0; i < n; i++)
            count[arr[i]]++;
 
        

        

        PriorityQueue<Key> pq
            = new PriorityQueue<>(new KeyComparator());
 
        

        for (int i = 0; i < n; i++)
        {
            int val = arr[i];
 
            if (count[val] > 0 && visited[val] != 1)
                pq.add(new Key(count[val], val));
            visited[val] = 1;
        }
 
        

        int result[] = new int[n];
 
        

        

        

        Key prev = new Key(-1, -1);
 
        

        int l = 0;
        while (pq.size() != 0)
        {
            

            

            Key k = pq.peek();
            pq.poll();
            result[l] = k.num;
 
            

            

            

            if (prev.freq > 0)
                pq.add(prev);
 
            

            

            (k.freq)--;
            prev = k;
            l++;
        }
 
        

        

        if (l != result.length)
        {
           return false;
        }
        

        else
        	{int j=0;
            for (int i : result)
            {
                arr[j++]=i;
            }
            return true;
        }
    }
  
}
class KeyComparator implements Comparator<Key>
{
 
    

    public int compare(Key k1, Key k2)
    {
        if (k1.freq < k2.freq)
            return 1;
        else if (k1.freq > k2.freq)
            return -1;
        return 0;
    }
}
 


class Key
{
    int freq; 

    int num;
    Key(int freq, int num)
    {
        this.freq = freq;
        this.num = num;
    }
}