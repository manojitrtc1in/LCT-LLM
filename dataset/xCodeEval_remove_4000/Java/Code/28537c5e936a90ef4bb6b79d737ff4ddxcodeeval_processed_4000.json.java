					
						
						
						
						
						            import java.util.*;
								    import java.math.*;
								    import java.io.*; 
								    import java.util.stream.Collectors;

								       public class A{
						            static FastScanner scan=new FastScanner();
									     public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));

static boolean isprime(int x)
{
	if(x%2==0)
		return false;
	if(x==1)
		return false;
	if(x==2||x==3)
		return true;
	for(int i=3;i*i<=x;i+=2)
		if(x%i==0)
			return false;
		return true;
}
static int hidden[]={0,181,21,53};
static Pair askand(int x)
{
	System.out.println("and "+x+" "+(x-1));
   

	int fi=hidden[x]&hidden[x-1];
	System.out.println("and "+x+" "+(x-2));
	int sec=hidden[x]&hidden[x-2];
	

	return new Pair(fi,sec);
}
static Pair askor(int x)
{
	System.out.println("or "+x+" "+(x-1));
	

int fi=hidden[x]|hidden[x-1];
	System.out.println("or "+x+" "+(x-2));
	int sec=hidden[x]|hidden[x-2];
	

	return new Pair(fi,sec);
}
static int id2(String n)
    {
        String num = n;
        int dec_value = 0;
 
        

        

        int base = 1;
 
        int len = num.length();
        for (int i = len - 1; i >= 0; i--) {
            if (num.charAt(i) == '1')
                dec_value += base;
            base = base * 2;
        }
 
        return dec_value;
    }
		public static void main(String[] args)  throws Exception 
						      {
						 
					

						

							

								 
								 							 
								 
									 
									 

								int tt =1;
								

								int T=1;
							 outer:while(tt-->0)
								    {	
								   
								  int n=scan.nextInt(),k=scan.nextInt();
								 int ans[]=new int[n+1];
								 System.out.println("and "+1+" "+2);
								 int and12=scan.nextInt();
								 

								 System.out.println("and "+1+" "+3);
								 int and13=scan.nextInt();
								

								 System.out.println("and "+2+" "+3);
								 int and23=scan.nextInt();
								


								 System.out.println("or "+1+" "+2);
								int or12=scan.nextInt();
								

								 System.out.println("or "+1+" "+3);
								 int or13=scan.nextInt();
								

								 System.out.println("or "+2+" "+3);
								 int or23=scan.nextInt();
								

								 StringBuilder first=new StringBuilder("");
								 StringBuilder second=new StringBuilder("");
								 StringBuilder third=new StringBuilder("");
								 for(int i=0;i<=29;i++)
								 {
								 	first.append(" ");
								 	second.append(" ");
								 	third.append(" ");
								 }
								 for(int i=0;i<=29;i++)
								 {
								 	

								 	

								 	{
								 		

								 		if((1&(or12>>i))==0&&(1&(or13>>i))==0){
								 			first.setCharAt(29-i,'0');
								 			second.setCharAt(29-i,'0');
								 			third.setCharAt(29-i,'0');
								 			continue;
								 		}
								 	}
								 	

								 	{
								 		

								 		if((1&(and12>>i))==1&&(1&(and13>>i))==1){
								 			first.setCharAt(29-i,'1');
								 			second.setCharAt(29-i,'1');
								 			third.setCharAt(29-i,'1');
								 			continue;
								 		}
								 	}
								 	

								 	{
								 		

								 		

								 		if((1&(and12>>i))==0&&(1&(and13>>i))==0&&(1&(and23>>i))==0&&(1&(or12>>i))==0&&(1&(or13>>i))==1&&(1&(or23>>i))==1)
								 		{
								 			first.setCharAt(29-i,'0');
								 			second.setCharAt(29-i,'0');
								 			third.setCharAt(29-i,'1');
								 			continue;
								 		}
								 		

								 		if((1&(and12>>i))==0&&(1&(and13>>i))==0&&(1&(and23>>i))==0&&(1&(or12>>i))==1&&(1&(or13>>i))==0&&(1&(or23>>i))==1)
								 		{
								 			first.setCharAt(29-i,'0');
								 			second.setCharAt(29-i,'1');
								 			third.setCharAt(29-i,'0');
								 			continue;
								 		}
								 		

								 		if((1&(and12>>i))==0&&(1&(and13>>i))==0&&(1&(and23>>i))==0&&(1&(or12>>i))==1&&(1&(or13>>i))==1&&(1&(or23>>i))==0)
								 		{
								 			first.setCharAt(29-i,'1');
								 			second.setCharAt(29-i,'0');
								 			third.setCharAt(29-i,'0');
								 			continue;
								 		}
								 	}
								 	

								 	{
								 		

								 		if((1&(and12>>i))==0&&(1&(and13>>i))==0&&(1&(and23>>i))==1&&(1&(or12>>i))==1&&(1&(or13>>i))==1&&(1&(or23>>i))==1)
								 		{
								 			first.setCharAt(29-i,'0');
								 			second.setCharAt(29-i,'1');
								 			third.setCharAt(29-i,'1');
								 			continue;
								 		}
								 		

								 		if((1&(and12>>i))==0&&(1&(and13>>i))==1&&(1&(and23>>i))==0&&(1&(or12>>i))==1&&(1&(or13>>i))==1&&(1&(or23>>i))==1)
								 		{
								 			first.setCharAt(29-i,'1');
								 			second.setCharAt(29-i,'0');
								 			third.setCharAt(29-i,'1');
								 			continue;
								 		}
								 		

								 		if((1&(and12>>i))==1&&(1&(and13>>i))==0&&(1&(and23>>i))==0&&(1&(or12>>i))==1&&(1&(or13>>i))==1&&(1&(or23>>i))==1)
								 		{
								 			first.setCharAt(29-i,'1');
								 			second.setCharAt(29-i,'1');
								 			third.setCharAt(29-i,'0');
								 			continue;
								 		}
								 	}
								 

								 }
								

								 ans[1]=id2(first.toString());
								 ans[2]=id2(second.toString());
								 ans[3]=id2(third.toString());
								

								int my=ans[1];
								 for(int i=4;i<=n;i++)
								 {
								 	System.out.println("and "+1+" "+i);
								 	int and=scan.nextInt();
								 	System.out.println("or "+1+" "+i);
								 	int or=scan.nextInt();
								 	StringBuilder now=new StringBuilder("");
								 	for(int j=0;j<=29;j++)
								 		now.append(" ");
								 	for(int j=0;j<=29;j++)
								 	{
								 		if((1&(and>>j))==1)
								 		{
								 			now.setCharAt(29-j,'1');
								 		}
								 		else if((1&(or>>j))==0)
								 		{
								 			now.setCharAt(29-j,'0');
								 		}
								 		else {
								 			if((1&(my>>j))==1)
								 				now.setCharAt(29-j,'0');
								 			else now.setCharAt(29-j,'1');
								 		}
								 	}
								 	int ok=id2(now.toString());
								 	ans[i]=ok;
								 }
								 ArrayList<Integer>res=new ArrayList<Integer>();
								 for(int i=1;i<=n;i++)
								 	res.add(ans[i]);
								 Collections.sort(res);
								System.out.println("finish "+res.get(k-1));




}

		out.close();
					}
					

					static class special implements Comparable<special>{
					int cnt,idx;
					String s;
					public special(int cnt,int idx,String s)
					{
						this.cnt=cnt;
						this.idx=idx;
						this.s=s;
					}

						 @Override
								            public int hashCode() {
								                return (int)42;
								            }
						  @Override
								            public boolean equals(Object o){
								            

								                if (o == this) return true;
								                if (o.getClass() != getClass()) return false;
								                special t = (special)o;
								                return t.cnt == cnt && t.idx == idx;
								            }
								            public int compareTo(special o1)
								            {
								            	if(o1.cnt==cnt)
								            	{
								            		return o1.idx-idx;
								            	}
								            	return o1.cnt-cnt;
								            }
					}
		
								   
								     static long binexp(long a,long n)
								    {
								        if(n==0)
								            return 1;
								        long res=binexp(a,n/2);
								        if(n%2==1)
								            return res*res*a;
								        else 
								            return res*res;
								    }
								     
								    static long powMod(long base, long exp, long mod) {
								           if (base == 0 || base == 1) return base;
								           if (exp == 0) return 1;
								           if (exp == 1) return (base % mod+mod)%mod;
								           long R = (powMod(base, exp/2, mod) % mod+mod)%mod;
								           R *= R;
								           R %= mod;
								           if ((exp & 1) == 1) {
								               return (base * R % mod+mod)%mod;
								           }
								           else return (R %mod+mod)%mod;
								       }
								    static double dis(double x1,double y1,double x2,double y2)
								    {
								        return Math.sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
								    }
								    static long mod(long x,long y)
								        {
								            if(x<0)
								                x=x+(-x/y+1)*y;
								            return x%y;
								        }
								     public static  long pow(long b, long e) {
								                long r = 1;
								                while (e > 0) {
								                    if (e % 2 == 1) r = r * b ;
								                    b = b * b;
								                    e >>= 1;
								                }
								                return r;
								            }
								    private static void sort(int[] arr) {
								            List<Integer> list = new ArrayList<>();
								            for (int object : arr) list.add(object);
								            Collections.sort(list);
								        

								            for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
								        }
								    private static void sort2(long[] arr) {
								            List<Long> list = new ArrayList<>();
								            for (Long object : arr) list.add(object);
								            Collections.sort(list);
								        Collections.reverse(list);
								            for (int i = 0; i < list.size(); ++i) arr[i] = list.get(i);
								        }
								     static class FastScanner
						{
						    private int BS = 1 << 16;
						    private char NC = (char) 0;
						    private byte[] buf = new byte[BS];
						    private int bId = 0, size = 0;
						    private char c = NC;
						    private double cnt = 1;
						    private BufferedInputStream in;
						 
						    public FastScanner() {
						        in = new BufferedInputStream(System.in, BS);
						    }
						 
						    public FastScanner(String s) {
						        try {
						            in = new BufferedInputStream(new FileInputStream(new File(s)), BS);
						        } catch (Exception e) {
						            in = new BufferedInputStream(System.in, BS);
						        }
						    }
						 
						    private char getChar() {
						        while (bId == size) {
						            try {
						                size = in.read(buf);
						            } catch (Exception e) {
						                return NC;
						            }
						            if (size == -1) return NC;
						            bId = 0;
						        }
						        return (char) buf[bId++];
						    }
						 
						    public int nextInt() {
						        return (int) nextLong();
						    }
						 
						    public int[] nextInts(int N) {
						        int[] res = new int[N];
						        for (int i = 0; i < N; i++) {
						            res[i] = (int) nextLong();
						        }
						        return res;
						    }
						 
						    public long[] id1(int N) {
						        long[] res = new long[N];
						        for (int i = 0; i < N; i++) {
						            res[i] = nextLong();
						        }
						        return res;
						    }
						 
						    public long nextLong() {
						        cnt = 1;
						        boolean neg = false;
						        if (c == NC) c = getChar();
						        for (; (c < '0' || c > '9'); c = getChar()) {
						            if (c == '-') neg = true;
						        }
						        long res = 0;
						        for (; c >= '0' && c <= '9'; c = getChar()) {
						            res = (res << 3) + (res << 1) + c - '0';
						            cnt *= 10;
						        }
						        return neg ? -res : res;
						    }
						 
						    public double nextDouble() {
						        double cur = nextLong();
						        return c != '.' ? cur : cur + nextLong() / cnt;
						    }
						 
						    public double[] id0(int N) {
						        double[] res = new double[N];
						        for (int i = 0; i < N; i++) {
						            res[i] = nextDouble();
						        }
						        return res;
						    }
						 
						    public String next() {
						        StringBuilder res = new StringBuilder();
						        while (c <= 32) c = getChar();
						        while (c > 32) {
						            res.append(c);
						            c = getChar();
						        }
						        return res.toString();
						    }
						 
						    public String nextLine() {
						        StringBuilder res = new StringBuilder();
						        while (c <= 32) c = getChar();
						        while (c != '\n') {
						            res.append(c);
						            c = getChar();
						        }
						        return res.toString();
						    }
						 
						    public boolean hasNext() {
						        if (c > 32) return true;
						        while (true) {
						            c = getChar();
						            if (c == NC) return false;
						            else if (c > 32) return true;
						        }
						    }
						}

								     static class Pair implements Comparable<Pair>{
								            public long x, y,z;
								            public Pair(long x1, long y1,long z1) {
								                x=x1;
								                y=y1;
								                z=z1;
								            }
								             public Pair(long x1, long y1) {
								                x=x1;
								                y=y1;
								    
								            }
								            
								            @Override
								            public int hashCode() {
								                return (int)(x + 31 * y);
								            }
								            public String toString() {
								                return x + " " + y+" "+z;
								            }
								            @Override
								            public boolean equals(Object o){
								                if (o == this) return true;
								                if (o.getClass() != getClass()) return false;
								                Pair t = (Pair)o;
								                return t.x == x && t.y == y&&t.z==z;
								            }
								    public int compareTo(Pair o)
								    {
								    								  	
								  
								    	return (int)(x-o.x);
								     
								        }
								     
								    }
								}
								
								    
								   

								     
