import java.io.*;
import java.math.BigInteger;
import java.text.DecimalFormat;
import java.util.*;







 
 
 
 
public class Codeforces {
	static String ab,b;
	static class Node
	{
		int val;
		Node left;
		Node right;
		public Node(int x) {
			

			this.val=x;
			this.left=null;
			this.right=null;
			}
	}
	static class Pair<U, V> implements Comparable<Pair<U, V>> {
        public U x;
        public V y;
 
        public Pair(U x, V y) {
            this.x = x;
            this.y = y;
        }
 
        public int compareTo(Pair<U, V> o) {
            int value = ((Comparable<U>) x).compareTo(o.x);
            if (value != 0) return value;
            return ((Comparable<V>) y).compareTo(o.y);
        }
 
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            Pair<?, ?> pair = (Pair<?, ?>) o;
            return x.equals(pair.x) && y.equals(pair.y);
        }
 
        public int hashCode() {
            return Objects.hash(x, y);
        }
 
    }
	static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
        } 
  
        String next() 
        { 
            while (st == null || !st.hasMoreElements()) 
            { 
                try
                { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) 
                { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
  
        int nextInt() 
        { 
            return Integer.parseInt(next()); 
        } 
  
        long nextLong() 
        { 
            return Long.parseLong(next()); 
        } 
  
        double nextDouble() 
        { 
            return Double.parseDouble(next()); 
        } 
  
        String nextLine() 
        { 
            String str = ""; 
            try
            { 
                str = br.readLine(); 
            } 
            catch (IOException e) 
            { 
                e.printStackTrace(); 
            } 
            return str; 
        }
        int[] nextArray(int n)
        {
        	int arr[]=new int[n];
        	for(int i=0;i<n;i++)
        		arr[i]=nextInt();
        	return arr;
        }
    } 
	static String string;
	static int gcd(int a, int b)
    {
        

        if (a == 0)
          return b;
        if (b == 0)
          return a;
      
        

        if (a == b)
            return a;
      
        

        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
	static long gcd(long a, long b)
    {
        

   
        for(long i=2;i<=b;i++)
        {
        	if(a%i==0&&b%i==0)
        		return i;
        }
        return 1;
    }
	static int fac(int n)
	{
		int c=1;
		for(int i=2;i<n;i++)
		if(n%i==0)
			c=i;
		return c;
	}
	static boolean ab(int i,HashSet<Integer> hs,int n,int prev)
	{
		if(i==n)
			return true;
		int cur=2;
		while(i<4*n)
		{
			if(prev==-1)
			{
				hs.add(cur);
				if(ab(i+1, hs, n, cur))
				{
					
					string=cur+" "+string;
					return true;
				}
				else
					hs.remove(hs.size()-1);
			}
			else {
				if(!hs.contains(cur)&&gcd(cur, prev)>1)
				{
					hs.add(cur);
					Iterator<Integer> iterator=hs.iterator();
					int flag=0;
					while(iterator.hasNext())
					{
						int x=iterator.next();
						if(x%cur==0||cur%x==0)
						{
							flag=1;
							break;
						}
					}
						
					if(flag==0&&ab(i+1, hs, n, cur))
					{
					string=cur+" "+string;
					return true;
					}
					hs.remove(hs.size()-1);
				}
					
			}
			cur+=2;
		}
		return false;
	}
	static boolean check(String all,String ch,int i,int k,boolean flag)
	{
		

		if(i==all.length()||ch.length()==k)
		{
			if(ch.length()==k&&flag)
				return true;
			return false;
		}
		
		for(int j=i;j<all.length();j++)
		{
			if(i>0&&j!=i&&ch.charAt(k)==all.charAt(j)&&check(all, ch, j+1,k+1, true))
				return true;
			else if(ch.charAt(k)==all.charAt(j)&&check(all, ch, j+1,k+1, flag))
				return true;
				
		}
		return false;
	}
	static int lcm(int a,int b)
	{
		for(int i=Math.min(a, b);i<=a*b;i++)
			if(i%a==0&&i%b==0)
				return i;
		return 0;
	}
	static int maxheight(char[][] ch,int i,int j,String[] arr)
	{
		int h=1;
		if(i==ch.length-1||j==0||j==ch[0].length-1)
			return 1;
		while(i+h<ch.length&&j-h>=0&&j+h<ch[0].length&&ch[i+h][j-h]=='*'&&ch[i+h][j+h]=='*')
		{
			String whole=arr[i+h];
			

			if(whole.substring(j-h,j+h+1).replace("*","").length()>0)
				return h;
			h++;
		}
			
		return h;
	}
	static boolean all(BigInteger n)
	{
		BigInteger c=n;
		HashSet<Character> hs=new HashSet<>();
		while((c+"").compareTo("0")>0)
		{
			String d=""+c;
			char ch=d.charAt(d.length()-1);
			if(d.length()==1)
			{
				c=new BigInteger("0");
				
			}
			else
			c=new BigInteger(d.substring(0,d.length()-1));
			if(hs.contains(ch))
				continue;
			if(d.charAt(d.length()-1)=='0')
				continue;
			if(!(n.mod(new BigInteger(""+ch)).equals(new BigInteger("0"))))
				return false;
				hs.add(ch);
		}
		return  true;
	}
	
	static int cal(long n,long k)
	{
		System.out.println(n+","+k);
		if(n==k)
			return 2;
		if(n<k)
			return 1;
		if(k==1)
			return 1+cal(n, k+1);
		if(k>=32)
			return 1+cal(n/k, k);
		return 1+Math.min(cal(n/k, k),cal(n, k+1));
	}
	static Node buildTree(int i,int j,int[] arr)
	{
		if(i==j)
		{
			
			

			return new Node(arr[i]);
		}
		int max=i;
		for(int k=i+1;k<=j;k++)
		{
			if(arr[max]<arr[k])
				max=k;
		}
		Node root=new Node(arr[max]);
		

		if(max>i)
			root.left=buildTree(i, max-1, arr);
		else {
			root.left=null;
		}
		if(max<j)
			root.right=buildTree(max+1, j, arr);
		else {
			root.right=null;
		}
		return root;
	}
	static int height(Node root,int val)
	{
		if(root==null)
			return Integer.MAX_VALUE-32;
		if(root.val==val)
			return 0;
		if((root.left==null&&root.right==null))
			return Integer.MAX_VALUE-32;
		return Math.min(height(root.left, val), height(root.right, val))+1;
	}
	static void shuffle(int a[], int n) 
    { 
        for (int i = 0; i < n; i++) { 
  
            

            int t = (int)Math.random() * a.length; 
  
            

            

            int x = a[t]; 
            a[t] = a[i]; 
            a[i] = x; 
        } 
    }
	static void sort(int[] arr )
	{
		shuffle(arr, arr.length);
		Arrays.sort(arr);
	}
	static int helper(int i,boolean flag,int n,int c,int val,int[][][] dp)
	{
		if(i<=0||i>=n+1)
		{
			c++;
			return 1;
		}
		int last=flag?1:0;
		if(dp[i][val][last]!=0)
			return dp[i][val][last];
		int ans=0;
		if(flag)
		{
			ans=helper(i+1, flag, n, c, val,dp);
			if(val>1)
			ans+=helper(i-1, !flag, n, c, val-1,dp);
		}
		else {
			ans=helper(i-1, flag, n, c, val,dp);
			if(val>1)
			ans+=helper(i+1, !flag, n, c, val-1,dp);
		}
		return dp[i][val][last]=ans;	
	}
	static boolean valid(char[] arr,int k)
	{
		int[] count=new int[26];
		for(int i=0;i<arr.length;i++)
			count[(int)arr[i]-'a']++;
		for(int i=0;i<26;i++)
			if(count[i]%k!=0)
				return false;
		return true;
	}
	
	static int compute(int c,int r)
	{
		if(r<c/2)
			r=c-r;
		int ans=1;
		for(int i=c;i>r;i--)
			ans*=i;
		int fac=fac(c-r);
		return ans/fac;
	}
	static boolean id1(int arr[], int n)
    {
 
        

        if (n == 0 || n == 1)
            return true;
 
        for (int i = 1; i < n; i++)
 
            

            if (arr[i - 1] > arr[i])
                return false;
 
        

        return true;
    }
	static boolean id0(int arr[], int n)
    {
 
        

        if (n == 0 || n == 1)
            return true;
 
        for (int i = 1; i < n; i++)
 
            

            if (arr[i - 1] > arr[i])
                return false;
 
        

        return true;
    }
	static int largestPower(int n, int p) {
        

        int x = 0;
 
        

        while (n > 0) {
            n /= p;
            x += n;
        }
        return x;
    }
 




    static int power(int x, int y, int p) {
        int res = 1; 

        x = x % p; 

        

        while (y > 0) {
            

            if (y % 2 == 1) {
                res = (res * x) % p;
            }
 
            

            y = y >> 1; 

            x = (x * x) % p;
        }
        return res;
    }
 


    static int modFact(int n, int p) {
        if (n >= p) {
            return 0;
        }
 
        int res = 1;
 
        

        

        boolean isPrime[] = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
 
        

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                

                int k = largestPower(n, i);
 
                

                res = (res * power(i, k, p)) % p;
            }
        }
        return res;
    }
	static boolean helper(int[][] all,int row,int[] count)
	{


		if(row==all.length)
			return true;










		if(count[all[row][row]]==all[row][row])
			return helper(all, row+1, count);
		else {
			for(int i=0;i<all.length;i++)
			{
				for(int j=0;j<=i;j++)
				{
					if(all[i][j]==all[row][row])
					{


						if(j>0&&all[i][j-1]==0)
						{
							all[i][j-1]=all[row][row];
							count[all[row][row]]++;
							if(helper(all, row, count))
								return true;
							else {
								all[i][j-1]=0;
								count[all[row][row]]--;
							}
						}
						if(j<i&&all[i][j+1]==0)
						{
							all[i][j+1]=all[row][row];
							count[all[row][row]]++;
							if(helper(all, row, count))
								return true;
							else {
								all[i][j+1]=0;
								count[all[row][row]]--;
							}
						}
						if(i<all.length-1&&all[i+1][j]==0)
						{
							all[i+1][j]=all[row][row];
							count[all[row][row]]++;
							if(helper(all, row, count))
								return true;
							else {
								all[i+1][j]=0;
								count[all[row][row]]--;
							}
						}
						if(i>0&&j!=i&&all[i-1][j]==0)
						{
							all[i-1][j]=all[row][row];
							count[all[row][row]]++;
							if(helper(all, row, count))
								return true;
							else {
								all[i-1][j]=0;
								count[all[row][row]]--;
							}
						}
						
					}
				}
			}
			return false;
		}
	}
	static boolean helper(int[] arr,long[] val,int i,int x,StringBuilder sb,HashSet<String> hs)
	{
		String key=Arrays.toString(val);
		if(hs.contains(key))
			return false;
		hs.add(key);
		if(i==arr.length)
		{
			long max=val[0],min=val[0];
			for(long in:val)
			{
				max=Math.max(max,in);
				min=Math.min(min,in);
				if(in==0)
					return false;
			}


			if(max-min<=x)
				return true;
			return false;
		}
		for(int j=0;j<val.length;j++)
		{
			if(j>0&&val[j-1]==0)
				break;
			if(j<val.length-1&&Math.abs(val[j]+arr[i]-val[j+1])>x)
				continue;
			if(j>0&&Math.abs(val[j]+arr[i]-val[j-1])>x)
				continue;
			val[j]+=arr[i];
			if(helper(arr, val, i+1, x,sb,hs))
			{
				sb.append(j+1).append(" ");
				return true;
			}
			val[j]-=arr[i];
		}
		return false;
	}
	public static void main(String[] args)throws IOException
	{
		BufferedReader bReader=new BufferedReader(new InputStreamReader(System.in));
		FastReader fs=new FastReader();
		PrintWriter out=new PrintWriter(System.out);
		int T=fs.nextInt();
		StringBuilder sb=new StringBuilder();
		while(T-->0)
		{
			
			int n=fs.nextInt(),m=fs.nextInt(),x=fs.nextInt();
			int[] arr=fs.nextArray(n);
			ArrayList<Pair<Integer, Integer>> pairs=new ArrayList<>();
			for(int i=0;i<n;i++)
				pairs.add(new Pair<Integer, Integer>(arr[i], i));
			Collections.sort(pairs);
			
			long[] sum=new long[n];
			int[] ind=new int[n];
			int j=1;
			for(int i=0;i<n;i++,j++)
			{
				if(j==m+1)
					j=1;
				ind[pairs.get(i).y]=j;
				sum[j-1]+=pairs.get(i).x;
			}
			boolean found =false;
			for(int i=1;i<m;i++)
			{
				if(Math.abs(sum[i]-sum[i-1])>x)
				{
					found=true;
					break;
				}
			}
			if(found)
			{
				sb.append("NO\n");
				continue;
			}
			sb.append("YES\n");
			for(int i=0;i<n;i++)
				sb.append(ind[i]).append(" ");
			sb.append("\n");


		}
		System.out.println(sb);
	 }
}