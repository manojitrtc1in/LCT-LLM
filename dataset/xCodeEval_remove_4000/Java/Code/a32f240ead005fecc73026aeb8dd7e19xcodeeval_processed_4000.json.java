import java.io.*;import java.util.*;import java.math.*;
public class Main
{
	static long mod=1000000007l;
    static int max=Integer.MAX_VALUE,min=Integer.MIN_VALUE;
    static long maxl=Long.MAX_VALUE,minl=Long.MIN_VALUE;
    static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    static StringBuilder sb;
    
    static public void main(String[] args)throws Exception
    {
    	st=new StringTokenizer(br.readLine());
    	int t=i();
    	sb=new StringBuilder(100000);
    	o:
    	while(t-->0)
    	{
    		int n=i();
    		int m=i();
    		char ar[][]=arc(n,m);
    		int nn=n%2==0?n:n-1;
    		int mm=m%2==0?m:m-1;
    		LinkedList<int[][]> l=new LinkedList<>();
    		for(int x=0;x<nn;x+=2)
    		{
    			for(int y=0;y<mm;y+=2)
    			{
    				int c=0;
    				if(ar[x][y]=='1')c++;
    				if(ar[x][y+1]=='1')c++;
    				if(ar[x+1][y]=='1')c++;
    				if(ar[x+1][y+1]=='1')c++;
    				if(c==1)
    				{
    					int i=-1;
    					int a[][]=new int[3][2];
    					int aa=2;
    					int bb=1;
    					if(bb>0&&ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x][y]=='0')
    					{
    						ar[x][y]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}

    					if(bb>0&&ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x][y+1]=='0')
    					{
    						ar[x][y+1]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					
    					if(bb>0&&ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x+1][y]=='0')
    					{
    						ar[x+1][y]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					
    					if(bb>0&&ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x+1][y+1]=='0')
    					{
    						ar[x+1][y+1]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					
    					l.add(a);
    					a=new int[3][2];
    					i=-1;
    					aa=2;
    					bb=1;
    					if(bb>0&&ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x][y]=='0')
    					{
    						ar[x][y]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}

    					if(bb>0&&ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x][y+1]=='0')
    					{
    						ar[x][y+1]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					
    					if(bb>0&&ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x+1][y]=='0')
    					{
    						ar[x+1][y]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					
    					if(bb>0&&ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x+1][y+1]=='0')
    					{
    						ar[x+1][y+1]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					
    					l.add(a);
    					a=new int[3][2];
    					i=-1;
    					if(ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					if(ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					if(ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					if(ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					l.add(a);
    				}
    				else if(c==2)
    				{
    					int i=-1;
    					int a[][]=new int[3][2];
    					int aa=2;
    					int bb=1;
    					if(bb>0&&ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x][y]=='0')
    					{
    						ar[x][y]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					if(bb>0&&ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x][y+1]=='0')
    					{
    						ar[x][y+1]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					if(bb>0&&ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x+1][y]=='0')
    					{
    						ar[x+1][y]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					
    					if(bb>0&&ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x+1][y+1]=='0')
    					{
    						ar[x+1][y+1]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					
    					l.add(a);
    					a=new int[3][2];
    					i=-1;
    					if(ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					if(ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					if(ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					if(ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					l.add(a);
    				}
    				else if(c==3)
    				{
    					int i=-1;
    					int a[][]=new int[3][2];
    					if(ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					if(ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					if(ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					if(ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					l.add(a);
    				}
    				else if(c==4)
    				{
    					int i=-1;
    					int a[][]=new int[3][2];
    					ar[x][y]='0';
    					a[0][0]=x;
    					a[0][1]=y;
    					
    					ar[x][y+1]='0';
    					a[1][0]=x;
    					a[1][1]=y+1;
    					
    					ar[x+1][y]='0';
    					a[2][0]=x+1;
    					a[2][1]=y;
    					
    					
    					l.add(a);
    					
    					i=-1;
    					a=new int[3][2];
    					int aa=2;
    					int bb=1;
    					if(bb>0&&ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x][y]=='0')
    					{
    						ar[x][y]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}

    					if(bb>0&&ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x][y+1]=='0')
    					{
    						ar[x][y+1]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					
    					if(bb>0&&ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x+1][y]=='0')
    					{
    						ar[x+1][y]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					
    					if(bb>0&&ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x+1][y+1]=='0')
    					{
    						ar[x+1][y+1]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					
    					l.add(a);
    					a=new int[3][2];
    					i=-1;
    					aa=2;
    					bb=1;
    					if(bb>0&&ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x][y]=='0')
    					{
    						ar[x][y]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}

    					if(bb>0&&ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						bb--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x][y+1]=='0')
    					{
    						ar[x][y+1]^=1;
    						aa--;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					
    					if(bb>0&&ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					else if(aa>0&&ar[x+1][y]=='0')
    					{
    						ar[x+1][y]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					
    					if(bb>0&&ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						bb--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					else if(aa>0&&ar[x+1][y+1]=='0')
    					{
    						ar[x+1][y+1]^=1;
    						aa--;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					
    					l.add(a);
    					a=new int[3][2];
    					i=-1;
    					if(ar[x][y]=='1')
    					{
    						ar[x][y]^=1;
    						a[++i][0]=x;
    						a[i][1]=y;
    					}
    					if(ar[x][y+1]=='1')
    					{
    						ar[x][y+1]^=1;
    						a[++i][0]=x;
    						a[i][1]=y+1;
    					}
    					if(ar[x+1][y]=='1')
    					{
    						ar[x+1][y]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y;
    					}
    					if(ar[x+1][y+1]=='1')
    					{
    						ar[x+1][y+1]^=1;
    						a[++i][0]=x+1;
    						a[i][1]=y+1;
    					}
    					l.add(a);
    				}
    				if(y+2==mm&&m!=mm)y--;
    			}
    			if(x+2==nn&&n!=nn)x--;
    		}
    		sl(l.size());
    		for(int a[][]:l)
    		{
    			for(int e[]:a)
    			{
    				s(e[0]+1);
    				ss();
    				s(e[1]+1);
    				ss();
    			}
    			sl();
    		}
    		

    	}
    	p(sb);
    }
    
    static void s(String s){sb.append(s);}
    static void s(int s){sb.append(s);}
    static void s(long s){sb.append(s);}
    static void s(char s){sb.append(s);}
    static void s(double s){sb.append(s);}
    static void ss(){sb.append(' ');}
    static void sl(String s){sb.append(s);sb.append("\n");}
    static void sl(int s){sb.append(s);sb.append("\n");}
    static void sl(long s){sb.append(s);sb.append("\n");}
    static void sl(char s){sb.append(s);sb.append("\n");}
    static void sl(double s){sb.append(s);sb.append("\n");}
    static void sl(){sb.append("\n");}
    static int max(int a,int b){return a>b?a:b;}
    static int min(int a,int b){return a<b?a:b;}
    static int abs(int a){return Math.abs(a);}
    static long max(long a,long b){return a>b?a:b;}
    static long min(long a,long b){return a<b?a:b;}
    static long abs(long a){return Math.abs(a);}
    static int sq(int a){return (int)Math.sqrt(a);}
    static long sq(long a){return (long)Math.sqrt(a);}
    static int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
    static boolean pa(String s,int i,int j)
    {
    	while(i<j)if(s.charAt(i++)!=s.charAt(j--))return false;
    	return true;
    }
    static int ncr(int n,int c,long m)
    {
        long a=1l;
        for(int x=n-c+1;x<=n;x++)a=((a*x)%m);
        long b=1l;
        for(int x=2;x<=c;x++)b=((b*x)%m);
        return (int)((a*(mul((int)b,m-2,m)%m))%m);
    }
    static boolean[] sieve(int n)
    {
        boolean bo[]=new boolean[n+1];
        bo[0]=true;bo[1]=true;
        for(int x=4;x<=n;x+=2)bo[x]=true;
        for(int x=3;x*x<=n;x+=2)if(!bo[x])for(int y=x*x;y<=n;y+=x)bo[y]=true;
        return bo;
    }
    static int[] fac(int n)
    {
        int bo[]=new int[n+1];
        for(int x=1;x<=n;x++)for(int y=x;y<=n;y+=x)bo[y]++;
        return bo;
    }
    static long mul(long a,long b,long m) 
    {
        long r=1l;
        a%=m;  
        while(b>0)
        {
            if((b&1)==1)r=(r*a)%m; 
            b>>=1;
            a=(a*a)%m;  
        } 
        return r; 
    }
    static int i()throws IOException
    {
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        return Integer.parseInt(st.nextToken());
    }
    static long l()throws IOException
    {
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        return Long.parseLong(st.nextToken());
    }
    static String s()throws IOException
    {
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    static double d()throws IOException
    {
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        return Double.parseDouble(st.nextToken());
    }
    static void p(Object p){System.out.print(p);}
    static void p(String p){System.out.print(p);}
    static void p(int p){System.out.print(p);}
    static void p(double p){System.out.print(p);}
    static void p(long p){System.out.print(p);}
    static void p(char p){System.out.print(p);}
    static void p(boolean p){System.out.print(p);}
    static void pl(Object p){System.out.println(p);}
    static void pl(String p){System.out.println(p);}
    static void pl(int p){System.out.println(p);}
    static void pl(char p){System.out.println(p);}
    static void pl(double p){System.out.println(p);}
    static void pl(long p){System.out.println(p);}
    static void pl(boolean p){System.out.println(p);}
    static void pl(){System.out.println();}
    static void s(int a[])
    {
    	for(int e:a)
    	{
    		sb.append(e);
    		sb.append(' ');
    	}
    	sb.append("\n");
    }
    static void s(int ar[][])
    {
    	for(int a[]:ar)
    	{
	    	for(int e:a)
	    	{
	    		sb.append(e);
	    		sb.append(' ');
	    	}
	    	sb.append("\n");
    	}
    }
    static void s(char a[])
    {
    	for(char e:a)
    	{
    		sb.append(e);
    		sb.append(' ');
    	}
    	sb.append("\n");
    }
    static void s(char ar[][])
    {
    	for(char a[]:ar)
    	{
	    	for(char e:a)
	    	{
	    		sb.append(e);
	    		sb.append(' ');
	    	}
	    	sb.append("\n");
    	}
    }
    static int[] ari(int n)throws IOException
    {
        int ar[]=new int[n];
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        for(int x=0;x<n;x++)ar[x]=Integer.parseInt(st.nextToken());
        return ar;
    }
    static int[][] ari(int n,int m)throws IOException
    {
        int ar[][]=new int[n][m];
        for(int x=0;x<n;x++)
        {
        	if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
            for(int y=0;y<m;y++)ar[x][y]=Integer.parseInt(st.nextToken());
        }
        return ar;
    }
    static long[] arl(int n)throws IOException
    {
        long ar[]=new long[n];
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        for(int x=0;x<n;x++) ar[x]=Long.parseLong(st.nextToken());
        return ar;
    }
    static long[][] arl(int n,int m)throws IOException
    {
        long ar[][]=new long[n][m];
        for(int x=0;x<n;x++)
        {
        	if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
            for(int y=0;y<m;y++)ar[x][y]=Long.parseLong(st.nextToken());
        }
        return ar;
    }
    static String[] ars(int n)throws IOException
    {
        String ar[]=new String[n];
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        for(int x=0;x<n;x++) ar[x]=st.nextToken();
        return ar;
    }
    static double[] ard(int n)throws IOException
    {
        double ar[]=new double[n];
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        for(int x=0;x<n;x++)ar[x]=Double.parseDouble(st.nextToken());
        return ar;
    }
    static double[][] ard(int n,int m)throws IOException
    {
        double ar[][]=new double[n][m];
        for(int x=0;x<n;x++)
        {
        	if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
            for(int y=0;y<m;y++)ar[x][y]=Double.parseDouble(st.nextToken());
        }
        return ar;
    }
    static char[] arc(int n)throws IOException
    {
        char ar[]=new char[n];
        if(!st.hasMoreTokens())st=new StringTokenizer(br.readLine());
        for(int x=0;x<n;x++)ar[x]=st.nextToken().charAt(0);
        return ar;
    }
    static char[][] arc(int n,int m)throws IOException
    {
        char ar[][]=new char[n][m];
        for(int x=0;x<n;x++)
        {
            String s=br.readLine();
            for(int y=0;y<m;y++)ar[x][y]=s.charAt(y);
        }
        return ar;
    }
    static void p(int ar[])
    {
        StringBuilder sb=new StringBuilder(2*ar.length);
        for(int a:ar)
        {
        	sb.append(a);
        	sb.append(' ');
        }
        System.out.println(sb);
    }
    static void p(int ar[][])
    {
    	StringBuilder sb=new StringBuilder(2*ar.length*ar[0].length);
        for(int a[]:ar)
        {
            for(int aa:a)
            {
            	sb.append(aa);
            	sb.append(' ');
            }
            sb.append("\n");
        }
        p(sb);
    }
    static void p(long ar[])
    {
        StringBuilder sb=new StringBuilder(2*ar.length);
        for(long a:ar)
        {
        	sb.append(a);
        	sb.append(' ');
        }
        System.out.println(sb);
    }
    static void p(long ar[][])
    {
    	StringBuilder sb=new StringBuilder(2*ar.length*ar[0].length);
        for(long a[]:ar)
        {
            for(long aa:a)
            {
            	sb.append(aa);
            	sb.append(' ');
            }
            sb.append("\n");
        }
        p(sb);
    }
    static void p(String ar[])
    {
    	int c=0;
    	for(String s:ar)c+=s.length()+1;
        StringBuilder sb=new StringBuilder(c);
        for(String a:ar)
        {
        	sb.append(a);
        	sb.append(' ');
        }
        System.out.println(sb);
    }
    static void p(double ar[])
    {
        StringBuilder sb=new StringBuilder(2*ar.length);
        for(double a:ar)
        {
        	sb.append(a);
        	sb.append(' ');
        }
        System.out.println(sb);
    }
    static void p(double ar[][])
    {
    	StringBuilder sb=new StringBuilder(2*ar.length*ar[0].length);
        for(double a[]:ar)
        {
            for(double aa:a)
            {
            	sb.append(aa);
            	sb.append(' ');
            }
            sb.append("\n");
        }
        p(sb);
    }
    static void p(char ar[])
    {
        StringBuilder sb=new StringBuilder(2*ar.length);
        for(char aa:ar)
        {
        	sb.append(aa);
        	sb.append(' ');
        }
        System.out.println(sb);
    }
    static void p(char ar[][])
    {
        StringBuilder sb=new StringBuilder(2*ar.length*ar[0].length);
        for(char a[]:ar)
        {
            for(char aa:a)
            {
            	sb.append(aa);
            	sb.append(' ');
            }
            sb.append("\n");
        }
        p(sb);
    }
}