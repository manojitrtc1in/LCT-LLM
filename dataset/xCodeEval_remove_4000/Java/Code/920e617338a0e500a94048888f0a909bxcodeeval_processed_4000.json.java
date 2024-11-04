

import java.util.*;
import java.lang.*;
import java.io.*;
public class Main
{ 
  

  

   static FastReader sc=new FastReader(System.in);
  
  static long mod = (long)(1e9)+ 7;
  static int max_num=(int)1e5+5;
  static long val(char a[],int n)
   {
      long ans=0;
      for(int i=0;i<n-1;i++)
       {
          String s=""+a[i]+a[i+1];
          ans+=Long.parseLong(s);
       }
      return ans;
   }
  static long res(String s,int n, int k)
   {
      int temp=k;
		       
	          char a[]=s.toCharArray();
		       for(int i=0;i<n-2;i++)
		        {
		           if(k==0)
		             break;
		           if(a[i]=='0' && a[i+1]=='1' && a[i+2]=='1')
		            {
		               a[i]='1';
		               a[i+1]='0';
		               i++;
		               k--;
		            }
		           if(k==0)
		            break;
		        }
		       for(int i=n-1;i>=2;i--)
		        {
		           if(k==0)
		            break;
		           if(a[i]=='0' && a[i-1]=='1' && a[i-2]=='1')
		            {
		               a[i]='1';
		               a[i-1]='0';
		               i--;
		               k--;
		            }
		           if(k==0)
		            break;
		        }
		       long ans1=val(a,n);
		       k=temp;
		       char b[]=s.toCharArray();
		       int min=Math.min(k+1,n);
		       

		       ArrayList<Integer> al=new ArrayList<>();
		       for(int i=0;i<n;i++)
		        {
		           if(b[i]=='1') al.add(i);
		        }
		       int end=n-1;
		       for(int i=n-1;i>=0;i--)
		        {
		           if(b[i]=='0')
		            break;
		           else
		            end--;
		        }
		       for(int i=al.size()-1;i>=0;i--)
		        {
		           int ind=al.get(i);
		           int op=end-ind;
		           if(k>=op)
		            {
		               b[end]='1';
		               b[ind]='0';
		               k-=op;
		               end--;
		              

		            }
		           else
		            break;
		        }
		       

		       long ans2=val(b,n);
		       char c[]=s.toCharArray();
		       for(int i=0;i<n;i++)
		        {
		           c[i]=b[i];
		        }
		        for(int i=0;i<n-2;i++)
		        {
		           if(k==0)
		             break;
		           if(c[i]=='0' && c[i+1]=='1' && c[i+2]=='1')
		            {
		               c[i]='1';
		               c[i+1]='0';
		               i++;
		               k--;
		            }
		           if(k==0)
		            break;
		        }
		       for(int i=n-1;i>=2;i--)
		        {
		           if(k==0)
		            break;
		           if(c[i]=='0' && c[i-1]=='1' && c[i-2]=='1')
		            {
		               c[i]='1';
		               c[i-1]='0';
		               i--;
		               k--;
		            }
		           if(k==0)
		            break;
		        }
		       long ans3=val(c,n);
		       

		       

		       
		       long ans=Math.min(Math.min(ans1,ans2),ans3);
		       return ans;
   }
 
 public static void main (String[] args) throws java.lang.Exception
   {
	try{
	    
		  int t = sc.nextInt();
		  for(int tt=1;tt<=t;tt++)
		    { 
		       int n=sc.nextInt();
		       int k=sc.nextInt();
		       String s=sc.next();
		       
		       int temp=k;
		       StringBuilder sb=new StringBuilder();
		       sb.append(s);
		       sb=sb.reverse();
		       String r=sb.toString();
		       

		       

	          

	          

	          char a[]=s.toCharArray();
	          ArrayList<Integer> al=new ArrayList<>();
		       for(int i=0;i<n;i++)
		        {
		           if(a[i]=='1') al.add(i);
		        }
		       if(a[0]=='0' && al.size()>0)
		        {
		           int first=al.get(0);
		           if(k>=first)
		             {
		                a[first]='0';
		                a[0]='1';
		                k-=first;
		             }
		        }
		       if(a[n-1]=='0' && al.size()>1 )
		        {
		           int last=al.get(al.size()-1);
		           int need=n-1-last;
		           if(k>=need)
		             {
		                a[last]='0';
		                a[n-1]='1';
		                k-=need;
		             }
		        }
		       long ans3=val(a,n);
		      

		      

		       
		       char b[]=s.toCharArray();
		       k=temp;
	          ArrayList<Integer> all=new ArrayList<>();
		       for(int i=0;i<n;i++)
		        {
		           if(b[i]=='1') all.add(i);
		        }
		      

		       if(b[n-1]=='0' && all.size()>0 )
		        {
		           int last=all.get(all.size()-1);
		           int need=n-1-last;
		           if(k>=need)
		             {
		                b[last]='0';
		                b[n-1]='1';
		                k-=need;
		             }
		        }
		        

		        if(b[0]=='0' && all.size()>1)
		        {
		           int first=all.get(0);
		           if(k>=first)
		             {
		                b[first]='0';
		                b[0]='1';
		                k-=first;
		             }
		        }
		       long ans4=val(b,n);
		       

		       long res=Math.min(ans3,ans4);
		       

		       out.println(res);
		       
		     
		    }
	     out.flush();
	     out.close();
	   }     
	catch(Exception e)
		 {}
	}
 static long fun(String s,int n,int k)
  {
    char a[]=s.toCharArray();
		       for(int i = 2; i< n; i++) 
		       {
                if (a[i] < a[i - 1] && a[i]<a[i-2] && k>0) 
                {
                   char temp=a[i-1];
                   a[i-1]=a[i];
                   a[i]=temp;
                   k--;
                   
                }
               else if (a[i - 1] < a[i] && a[i - 2] < a[i] && k > 0)
                {
                   char temp=a[i-1];
                   a[i-1]=a[i-2];
                   a[i-2]=temp;
                   k--;
                }
               if (k == 0)break;
              }
             long ans=val(a,n);
             return ans;
  }
 
 
static void flag(boolean flag)
   {
       out.println(flag ? "YES" : "NO");
       out.flush();
   }
   
 
   



















   

   

   

   

   

   

   

   

   

   

   

   

   


static void print(int a[])
  {
     int n=a.length;
     for(int i=0;i<n;i++)
       {
          out.print(a[i]+" ");
       }
     out.println();
     out.flush();
  }
static void print(long a[])
  {
     int n=a.length;
     for(int i=0;i<n;i++)
       {
          out.print(a[i]+" ");
       }
     out.println();
     out.flush();
  } 
static void print_int(ArrayList<Integer> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
static void print_long(ArrayList<Long> al)
  {
     int si=al.size();
     for(int i=0;i<si;i++)
       {
          out.print(al.get(i)+" ");
       }
     out.println();
     out.flush();
  }
  
static int LowerBound(int a[], int x) 
 { 

  int l=-1,r=a.length;
  while(l+1<r) {
    int m=(l+r)>>>1;
    if(a[m]>=x) r=m;
    else l=m;
  }
  return r;
}

 static int UpperBound(int a[], int x)
  {

    int l=-1,r=a.length;
    while(l+1<r) {
       int m=(l+r)>>>1;
       if(a[m]<=x) l=m;
       else r=m;
    }
    return l+1;
 }
static void DFS(ArrayList<Integer> graph[],boolean[] visited, int u)
	{
        visited[u]=true;
        int v=0;
        for(int i=0;i<graph[u].size();i++)
        {
            v=graph[u].get(i);
            if(!visited[v])
               DFS(graph,visited,v);
        }
  } 
static boolean[] prime(int num)
 {
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
static long nCr(long a,long b,long mod)
{
 return (((fact[(int)a] * modInverse(fact[(int)b],mod))%mod * modInverse(fact[(int)(a - b)],mod))%mod + mod)%mod;
}
static long fact[]=new long[max_num];
static void fact_fill()
 {
   fact[0]=1l;
	for(int i=1;i<max_num;i++)
	  {
	    fact[i]=(fact[i-1]*(long)i);
	    if(fact[i]>=mod)
	      fact[i]%=mod;
	  } 
 }
static long modInverse(long a, long m)
	    {
	       return power(a, m - 2, m);
	    }
static long power(long x, long y, long m)
	    {
	        if (y == 0)
	            return 1;
	        long p = power(x, y / 2, m) % m;
	        p = (long)((p * (long)p) % m);
	        if (y % 2 == 0)
	            return p;
	        else
	            return (long)((x * (long)p) % m);
	    }
static long sum_array(int a[])
 {
    int n=a.length;
    long sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    return sum;
 }
static long sum_array(long a[])
 {
    int n=a.length;
    long sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i];
    return sum;
 }

static void sort(int[] a) 
   {
		ArrayList<Integer> l=new ArrayList<>();
		for (int i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}
static void sort(long[] a) 
   {
		ArrayList<Long> l=new ArrayList<>();
		for (long i:a) l.add(i);
		Collections.sort(l);
		for (int i=0; i<a.length; i++) a[i]=l.get(i);
	}

static void reverse_array(int a[])
 {
    int n=a.length;
    int i,t; 
    for (i = 0; i < n / 2; i++) { 
            t = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = t; 
        } 
 }
static void reverse_array(long a[])
 {
    int n=a.length;
    int i; long t; 
    for (i = 0; i < n / 2; i++) { 
            t = a[i]; 
            a[i] = a[n - i - 1]; 
            a[n - i - 1] = t; 
        } 
 }

static long gcd(long a, long b) 
    { 
        if (a == 0) 
            return b; 
          
        return gcd(b%a, a); 
    } 
static int gcd(int a, int b) 
    { 
        if (a == 0) 
            return b; 
          
        return gcd(b%a, a); 
    } 

   static class FastReader{
 
        byte[] buf = new byte[2048];
        int index, total;
        InputStream in;
 
        FastReader(InputStream is) {
            in = is;
        }
 
        int scan() throws IOException {
            if (index >= total) {
                index = 0;
                total = in.read(buf);
                if (total <= 0) {
                    return -1;
                }
            }
            return buf[index++];
        }
 
        String next() throws IOException {
            int c;
            for (c = scan(); c <= 32; c = scan());
            StringBuilder sb = new StringBuilder();
            for (; c > 32; c = scan()) {
                sb.append((char) c);
            }
            return sb.toString();
        }
 
        int nextInt() throws IOException {
            int c, val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
 
        long nextLong() throws IOException {
            int c;
            long val = 0;
            for (c = scan(); c <= 32; c = scan());
            boolean neg = c == '-';
            if (c == '-' || c == '+') {
                c = scan();
            }
            for (; c >= '0' && c <= '9'; c = scan()) {
                val = (val << 3) + (val << 1) + (c & 15);
            }
            return neg ? -val : val;
        }
    }
   
    static class Reader 
    { 
        final private int BUFFER_SIZE = 1 << 16; 
        private DataInputStream din; 
        private byte[] buffer; 
        private int bufferPointer, bytesRead; 
  
        public Reader() 
        { 
            din = new DataInputStream(System.in); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public Reader(String file_name) throws IOException 
        { 
            din = new DataInputStream(new FileInputStream(file_name)); 
            buffer = new byte[BUFFER_SIZE]; 
            bufferPointer = bytesRead = 0; 
        } 
  
        public String readLine() throws IOException 
        { 
            byte[] buf = new byte[64]; 

            int cnt = 0, c; 
            while ((c = read()) != -1) 
            { 
                if (c == '\n') 
                    break; 
                buf[cnt++] = (byte) c; 
            } 
            return new String(buf, 0, cnt); 
        } 
  
        public int nextInt() throws IOException 
        { 
            int ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do
            { 
                ret = ret * 10 + c - '0'; 
            }  while ((c = read()) >= '0' && c <= '9'); 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public long nextLong() throws IOException 
        { 
            long ret = 0; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        public double nextDouble() throws IOException 
        { 
            double ret = 0, div = 1; 
            byte c = read(); 
            while (c <= ' ') 
                c = read(); 
            boolean neg = (c == '-'); 
            if (neg) 
                c = read(); 
  
            do { 
                ret = ret * 10 + c - '0'; 
            } 
            while ((c = read()) >= '0' && c <= '9'); 
  
            if (c == '.') 
            { 
                while ((c = read()) >= '0' && c <= '9') 
                { 
                    ret += (c - '0') / (div *= 10); 
                } 
            } 
  
            if (neg) 
                return -ret; 
            return ret; 
        } 
  
        private void fillBuffer() throws IOException 
        { 
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE); 
            if (bytesRead == -1) 
                buffer[0] = -1; 
        } 
  
        private byte read() throws IOException 
        { 
            if (bufferPointer == bytesRead) 
                fillBuffer(); 
            return buffer[bufferPointer++]; 
        } 
  
        public void close() throws IOException 
        { 
            if (din == null) 
                return; 
            din.close(); 
        } 
    }
  static  PrintWriter out=new PrintWriter(System.out);
  static int int_max=Integer.MAX_VALUE;
  static int int_min=Integer.MIN_VALUE;
  static long long_max=Long.MAX_VALUE;
  static long long_min=Long.MIN_VALUE;
}

