
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.util.*;


import java.math.*;
import java.io.*;
import java.text.*;
import java.math.BigInteger;
public class Main {

	static class pair{
		int a;
		int b;
		public pair(int a,int b) {
			this.a=a;
			this.b=b;
		}
	}
	 public static boolean[] sieve(long n)
	    {
	        boolean[] prime = new boolean[(int)n+1];
	        Arrays.fill(prime,true);
	        prime[0] = false;
	        prime[1] = false;
	        long m = (long)Math.sqrt(n);
	        for(int i=2;i<=m;i++)
	        {
	            if(prime[i])
	            {
	                for(int k=i*i;k<=n;k+=i)
	                {
	                    prime[k] = false;
	                }
	            }
	        }
	        return prime;
	    } 
	 
	    
	    static long GCD(long a,long b)
	    {
	        if(b==0)
	        {
	            return a;
	        }
	        return GCD(b,a%b);
	    }
	 
	    static long CountCoPrimes(long n)
	    {
	        long res = n;
	        for(int i=2;i*i<=n;i++)
	        {
	            if(n%i==0)
	            {
	                while(n%i==0)
	                {
	                    n/=i;
	                }
	                res-=res/i;
	            }
	        }
	        if(n>1)
	        {
	            res-=res/n;
	        }
	        return res;
	    }
	 
	 
	    
	 
	    
	 
	    static boolean prime(int n)
	    {
	        for(int i=2;i*i<=n;i++)
	        {
	            if(i%2==0 ||i%3==0)
	            {
	                return false;
	            }
	        }
	        return true;
	    }
   static String userIdGeneration(String input1,String input2,int input3,int input4) {
	    	if(input1.length()==input2.length()) {
	    		String arr[]=new String[2];
	    		
	    		arr[0]=input1;
	    		arr[1]=input2;
	    		
	    		Arrays.sort(arr);
	    	char c=arr[0].charAt(0);
	    	   String output=c+arr[1];
	    		
	    	   String k=Integer.toString(input3);
	    	
	    	char d=k.charAt(input4-1);
	    	
	    	output+=d;
	    		
	    	char e=k.charAt(k.length()-input4);
	    	output+=e;
	    	String res="";
	    	for(int i=0;i<output.length();i++) {
	    		if(Character.isUpperCase(output.charAt(i))){
	    			res+=Character.toLowerCase(output.charAt(i));
	    		}
	    		else {
	    			res+=Character.toUpperCase(output.charAt(i));
	    		}
	      	}
	    	return res;
	    	}
	    	
	    	
	    	else  {
String arr[]=new String[2];
	    		arr[0]=input1.length()>input2.length()?input2:input1;
	    		arr[1]=input1.length()>input2.length()?input1:input2;
	    		
	    		char c=arr[0].charAt(0);
	    		
	    		String output=c+arr[1];
	    		
	    	String k=Integer.toString(input3);
	    	
	    	char d=k.charAt(input4-1);
	    	
	    	output+=d;
	    		
	    	char e=k.charAt(k.length()-input4);
	    	output+=e;
	    	String res="";
	    	for(int i=0;i<output.length();i++) {
	    		if(Character.isUpperCase(output.charAt(i))){
	    			res+=Character.toLowerCase(output.charAt(i));
	    		}
	    		else {
	    			res+=Character.toUpperCase(output.charAt(i));
	    		}
	    	}
	    return res;
	    	}
	    	
	    }
	static int length(int len) {
		
		if(len==1) {
			return 1;
		}
		else if(len==2) {
			return 3;
		}
		else if(len==3) {
			return 6;
		}
		else if(len==4) {
			return 10;
		}
		return 0;
	}
	
	
public static int LargestFour(int arr[]) {
	Arrays.sort(arr);

	int n=arr.length;
	int count=0;
	int sum=0;
	for(int i=n-1;i>=1;i--) {
		sum+=arr[i];
	
			count++;
			if(count==4) {
				break;
			
		}
		
	}
	
	if(count<4) {
		sum+=arr[0];
	}
	
	return sum;
}


public static void insertionSort(int array[]) {  
    int n = array.length;  
    for (int j = 1; j < n; j++) {  
        int key = array[j];  
        int i = j-1;  
        while ( (i > -1) && ( array [i] > key ) ) {  
            array [i+1] = array [i];  
            i--;  
        }  
        array[i+1] = key;  
    }  
}  
static String cfsolve(int n) {
	

	if(n>45) {
	return "-1";
		
	}
	else {
		
		if(n<10) {
		return Integer.toString(n);
		

		}
		else if(n==10) {
			return "19";
		
		}
		else if(n>10&&n<=17) {
			for(int i=1;i<=8;i++) {
				for(int j=i+1;j<=9;j++) {
					int k=i+j;
					if(k==n) {
						String r=Integer.toString(i)+Integer.toString(j);
						return r;}
						
					}
					
				}
			}
		
		else if(n>17&&n<=24) {
			for(int i=1;i<=7;i++) {
				for(int j=i+1;j<=8;j++) {
					for(int q=j+1;q<=9;q++) {
					
					int k=i+j+q;
					if(k==n) {
						String r=Integer.toString(i)+Integer.toString(j)+Integer.toString(q);
						return r;}
						
					}
					
				}
			}
		
		}
		
		else if(n==25) {
			return "1789";
		}
		else if(n==26) {
			return "2789";
		}
		else if(n==27) {
			return "3789";
		}
		else if(n==28) {
			return "4789";
		}
		else if(n==29) {
			return "5789";
		}
		else if(n==30) {
			return "6789";
		}
		else if(n==31) {
		return "16789";
		}
		else if(n==32) {
			return "26789";	
		}
		else if(n==33) {
			return "36789";	
		}
		else if(n==34) {
			return "46789";	
		}
		else if(n==35) {
			return "56789";	
		}
		else if(n==36) {
			return "156789";
		}
		else if(n==37) {
			return "256789";
		}
		else if(n==38) {
			return "356789";
		}
		else if(n==39) {
			return "456789";
		}
		else if(n==40) {
			return "1456789";
		}else if(n==41) {
			return "2456789";
		}
		else if(n==42) {
			return "3456789";
		}
		else if(n==43) {
			return "13456789";
		}
		else if(n==44) {
			return "23456789";
		}
		else if(n==45) {
			return "123456789";
		}
		return "-1";
		
		}
	}


public static int lcm(int n1,int n2) {
	int lcm;
	lcm=(n1>n2)?n1:n2;
	
	while(true) {
		if(lcm%n1==0&&lcm%n2==0) {
			break;
		}
		lcm++;
	}
	
	return lcm;
	
}


public static String solve(String s1,String s2) {
	
	HashMap<Character,Integer>hm=new HashMap<>();
	HashMap<Character,Integer>hm2=new HashMap<>();
	if(s2.length()>s1.length()) {
	
	for(int i=0;i<s1.length();i++) {
		char ch=s1.charAt(i);
		hm.put(ch,hm.getOrDefault(ch,0)+1);
	}
	
	for(int i=0;i<s2.length();i++) {
		char ch=s2.charAt(i);
		hm2.put(ch,hm.getOrDefault(ch,0)+1);
		
		if(hm.containsKey(s2.charAt(i))) {
			int val=hm.get(s2.charAt(i));
			if(val>0) {
				hm.put(s2.charAt(i), val-1);
			}
		}else {
			return "-1";
		}
		
		
		
		
		
		
	}
	
	
	String sub1=s2.substring(0,s1.length());
	if(!sub1.equals(s1)) {
		return "-1";
	}
	else if(hm.size()==1&&hm2.size()==1) {
		int yo= lcm(s1.length(),s2.length());
	String res="";
	for(int u=0;u<yo;u++) {
		res+=s1.charAt(0);
	}
	
	return res;
	}
	else {
		int q=s1.length();
		int r=s2.length();
		if(r%q==0) {
			return s2;
		}
		else {
			return "-1";
		}
		
		
	}
	
			
	}else {
		for(int i=0;i<s2.length();i++) {
			char ch=s2.charAt(i);
			hm.put(ch,hm.getOrDefault(ch,0)+1);
		}
		
		for(int i=0;i<s1.length();i++) {
			char ch=s1.charAt(i);
			hm2.put(ch,hm.getOrDefault(ch,0)+1);
			if(hm.containsKey(s1.charAt(i))) {
				int val=hm.get(s1.charAt(i));
				if(val>0) {
					hm.put(s1.charAt(i), val-1);
				}
			}else {
				return "-1";
			}
			
			
		}

		String sub1=s1.substring(0,s2.length());
		if(!sub1.equals(s2)) {
			return "-1";
		}	
		
		
		else if(hm.size()==1&&hm2.size()==1) {
			int yo= lcm(s1.length(),s2.length());
		String res="";
		for(int j=0;j<yo;j++) {
			res+=s1.charAt(0);
		}
		return res;
		}
		int q=s2.length();
		int r=s1.length();
		if(r%q==0) {
			return s1;
		}
		else {
			return "-1";
		}
		
		
	}
	
  }
 

  static String solve23(int n) {
int k=0;
while(true) {
	if(n-2020*k<0) {
		return "NO";
	}
	if((n-2020*k)%2021==0) {
		return "YES";
	}
	k++;
}
	  
	
	}
	
	
	
	










static String solvingcode(String str,int a,int b,int c,char ch) {
	char max='p';
	if(a>=str.length()/2) {
		max='a';
	}else if(b>=str.length()/2) {
		max='b';
	}else if(c>=str.length()/2){
		max='c';
	}
		

	if(ch=='a') {
		Stack<Character>st=new Stack<>();
		
			if(max=='a') {
			  for(int i=0;i<str.length();i++) {
					if(str.charAt(i)=='A'){
						st.push('A');
					}else {
						if(st.size()>0) {
							st.pop();
						}
						else {
							return "NO";
						}
					}
					
				}
			

				if(st.size()==0) {
					return "YES";
				}else {
					return "NO";
				}
				
				
			}else {
				
			for(int j=0;j<str.length();j++) {
				if(str.charAt(j)=='A'||Character.toLowerCase(str.charAt(j))!=max) {
					st.push(str.charAt(j));
				}else {
					if(st.size()==0) {
						return "NO";
					}else {
						st.pop();
					}
				}
			}
			
			if(st.size()==0) {
				return "YES";
			}
			else {
				return "NO";
			}
				
			}
			
			
		}
		else if(ch=='b') {
			
			Stack<Character>st=new Stack<>();
			if(max=='b') {
		

				for(int i=0;i<str.length();i++) {
					if(str.charAt(i)=='B') {
						st.push('B');
					}else {
						if(st.size()>0) {
							st.pop();
						}
						else {
							return "NO";
						}
					}
					
				}
				if(st.size()==0) {
					return "YES";
				}else {
					return "NO";
				}
				
				
			}else {
				

			for(int j=0;j<str.length();j++) {
				if(str.charAt(j)=='B'||Character.toLowerCase(str.charAt(j))!=max) {
					st.push(str.charAt(j));
				}else {
					if(st.size()==0) {
						return "NO";
					}else {
						st.pop();
					}
				}
			}
			
			if(st.size()==0) {
				return "YES";
			}
			else {
				return "NO";
			}
				
			}
			
			
			
			
			
		}else {
			Stack<Character>st=new Stack<>();
			if(max=='c') {
			
				for(int i=0;i<str.length();i++) {
					if(str.charAt(i)=='C') {
						st.push('C');
					}else {
						if(st.size()>0) {
							st.pop();
						}
						else {
							return "NO";
						}
					}
					
				}
				if(st.size()==0) {
					return "YES";
				}else {
					return "NO";
				}
				
				
			}else {
				
			for(int j=0;j<str.length();j++) {
				if(str.charAt(j)=='C'||Character.toLowerCase(str.charAt(j))!=max) {
					st.push(str.charAt(j));
				}else {
					if(st.size()==0) {
						return "NO";
					}else {
						st.pop();
					}
				}
			}
	

			if(st.size()==0) {
				return "YES";
			}
			else {
				return "NO";
			}
				
			}
			
			
			
			
			
		}
		
		
		
	}
		
		






 public static void main(String[] args) throws Exception{

	Scanner s=new Scanner(System.in);
		
	int op=s.nextInt();
	while(op>0) {

		String str=s.next();
		int a=0;
		int b=0;
		int c=0;
		for(int k=0;k<str.length();k++) {
			if(str.charAt(k)=='A') {
				a++;
			}else if(str.charAt(k)=='B') {
				b++;
			}else {
				c++;
			}
			
		}
			char ch=Character.toLowerCase(str.charAt(0));
		
			if(a!=str.length()/2&&b!=str.length()/2&&c!=str.length()/2) {
				System.out.println("NO");
			}
		
			
			else {
			
	System.out.println(solvingcode(str,a,b,c,ch));
		}
			

			
			op--;
	}
			
	}
	
	
	
 


	


 
 
  
    
   
 private static boolean compare(HashMap<Character, Integer> smap, HashMap<Character, Integer> pmap) {
		

	 
	 for(char ch:smap.keySet()) {
		 if(smap.get(ch)!=pmap.get(ch)) {
			 return false;
		 }
	 }
		return true;
	}


private static boolean BinarySearch(int search, int[] val, int n)
 {
		

		
	 int start=0;
	 int end=val.length-1;
	 while(start<=end) {
		 int mid=(start+end)/2;
		 
		 
		 if(val[mid]==search) {
			 return true;
		 }
		 else if(val[mid]<search) {
			 start=mid+1;
		 }
		 else {
			 end=mid-1;
		 }
		 
	 }
	 return false;
	 }


	
 
 
 
 static long findGCD(ArrayList<Long> arr,long start, long n) 
	    { 
	        long result = arr.get((int)start); 
	        for (int i = (int)start+1; i < n; i++) 
	            result = GCD(arr.get(i), result); 
	  
	        return result; 
	    } 
	 
	   
	 
	   

	    static long re(long n)
	    {
	        n+=1;
	        while(n%10==0)
	        {
	            n/=10;
	        }
	        return n;
	    }
	   
	   


	    
	 
	 
	 
	 
	 
	 
	    
	 
	    

	    static long xor(long n)
	    {
	 
	        if(n%4==0)
	        {
	            return n;
	        }
	        if(n%4==1)
	        {
	            return  1;
	        }
	        if(n%4==2)
	        {
	            return n+1;
	        }
	        return 0;
	    }
	 
	    static long xor(long a,long b)
	    {
	        return xor(b)^xor(a-1);
	    }
	 
	 
	    
	 
	  
	   
	    
	 
	    
	       
	    
	 
	    
	   
	  
	 
	 

	   
	   
	    static void swap(char c,char p)
	    {
	        char t = c;
	        c = p;
	        p = t;
	    }
	 
	    static long max(long n,long m)
	    {
	        return Math.max(n,m);
	    }
	    static long min(long n,long m)
	    {
	        return Math.min(n,m);
	    }
	 








































	  
	   
	    static int abs(int n)
	    {
	        return Math.abs(n);
	    }
	 
	    static class Scanner 
	    {
	        StringTokenizer st;
	        BufferedReader br;
	 
	        public Scanner(InputStream s){  br = new BufferedReader(new InputStreamReader(s));}
	 
	        public String next() throws IOException 
	        {
	            while (st == null || !st.hasMoreTokens()) 
	            {
	                st = new StringTokenizer(br.readLine());
	            }
	            return st.nextToken();
	        }
	 
	        public int nextInt() throws IOException {return Integer.parseInt(next());}
	        
	        public long nextLong() throws IOException {return Long.parseLong(next());}
	 
	        public String nextLine() throws IOException {return br.readLine();}
	 
	        public boolean ready() throws IOException {return br.ready();}
	 
	 
	    }
	 
	    
	}
	 
	 
	 
	class Pair implements Comparable<Pair>
	{
	   int x,y;
	    public Pair(int x,int y)
	    {
	        this.x = x;
	        this.y = y;
	    }
	    public int compareTo(Pair o)
	    {
	        return this.y-o.y;
	    }
	}

