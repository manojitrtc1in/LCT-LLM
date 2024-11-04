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

        

        return gcd(b, a % b);
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


    static int lcm(int a,int b)
    {
        for(int i=Math.min(a, b);i<=a*b;i++)
            if(i%a==0&&i%b==0)
                return i;
        return 0;
    }
    static int maxHeight(char[][] ch,int i,int j,String[] arr)
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
    static boolean arraySortedInc(int arr[], int n)
    {

        

        if (n == 0 || n == 1)
            return true;

        for (int i = 1; i < n; i++)

            

            if (arr[i - 1] > arr[i])
                return false;

        

        return true;
    }
    static boolean arraySortedDec(int arr[], int n)
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
    static List<Integer> helper(List<Integer> list)
    {
        int sum=0;
        for(int i:list)
            sum+=i;
        sum/=list.size();
        boolean in=false;
        List<Integer> temp=new ArrayList<>(list);
        for(Integer i:list)
        {
            if(i>sum)
            {
                in=true;
                temp.remove(i);
            }
        }
        if(temp.equals(list))
            return temp;
        return helper(temp);
    }
    
    static int helper(char[] arr,boolean reversed,int alice,int bob,int c)
    {
        int in=-1,count=0,st=-1;
        for(int i=0;i<=arr.length/2;i++)
        {
            if(arr[i]=='0'&&arr[arr.length-1-i]=='1')
            {
                in=i;
                break;
            }
            else if(arr[i]=='1'&&arr[arr.length-1-i]=='0')
            {
                in=arr.length-1-i;
                break;
            }
            if(arr[i]=='0')
            {
                if(st==-1)
                    st=i;
                count++;
            }
            if(arr[arr.length-i-1]=='0')
            {
                if(st==-1)
                    st=arr.length-1-i;
                count++;
            }
        }
        System.out.println(in);
        if(count==0)
        {
            return alice-bob;
        }
        else if(arr.length%2!=0&&arr[arr.length/2]=='0')
        {
            arr[arr.length/2]='1';
            return helper(arr, false, alice, bob, count);
        }
        if(in==-1||reversed)
        {
            arr[st]='1';
            if(c%2==0)
                return helper(arr, false, alice+1, bob, c+1);
            else {
                return helper(arr, false, alice, bob+1, c+1);
            }
        }
        else {
            arr[in]='1';
            return helper(arr, true, alice, bob, c+1);
        }
    }
    static boolean[] seiveOfErathnos(int n2)
    {
        boolean isPrime[] = new boolean[n2 + 1];
        Arrays.fill(isPrime, true);
        for (int i = 2; i * i <= n2; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n2; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    static boolean[] seiveOfErathnos2(int n2,int[] ans)
    {
        boolean isPrime[] = new boolean[n2 + 1];
        Arrays.fill(isPrime, true);
        for (int i = 2; i * i <= n2; i++) {
            if (isPrime[i]) {
                for (int j = 2 * i; j <= n2; j += i) {
                    if(isPrime[j])
                        ans[i]++;
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    static int calculatePower(PriorityQueue<Integer>[] list,int[] alive)
    {


    	for(int i=1;i<alive.length;i++)
    	{
    		if(alive[i]==1)
    		{
    			if(list[i].size()==0)
    			{
    				continue;
    			}
    			if(list[i].peek()>i)
    			{




    				alive[i]=0;
    				for(int j:list[i])
    				{


            			list[j].remove((Integer)i);
    				}
    				list[i].clear();
    				return 1+calculatePower(list,alive);
    			}
    		}
    	}
    	return 0;
    }
    static boolean helper(int i,int j,int[] index,int k,HashMap<String,String> hm)
    {


    	if(k<=0)
    		return false;
    	if(i==j)
    		return true;
    	String key=i+","+j;
    	if(hm.containsKey(key))
    	{
    		String[] all=hm.get(key).split(",");
    		int prev=Integer.parseInt(all[0]);


    		if(prev==k)
    			return all[1].equals("true")?true:false;
    		else if(prev>k&&all[1].equals("false"))
    			return false;
    		else if(prev<k&&all[1].equals("true"))
    			return true;
    	}
    	
    	if(i+1==j)
    	{
    		if(index[i]+1==index[j]||k>=2)
    			return true;
    		return false;
    	}
    	boolean flag=false;
    	for(int p=i;p<j;p++)
    	{
    		if(index[p]+1!=index[p+1])
    		{
    			flag=true;
    			break;
    		}
    	}
    	if(!flag)
    	{
    		hm.put(key,k+","+ true);
    		return true;
    	}
    	if(k==1)
    	{
    		hm.put(key,k+","+ false);
    		return false;
    	}
    	for(int p=i;p<j;p++)
    	{
    		if(helper(i,p,index,k-1,hm)&&helper(p+1,j,index,k-1,hm))
    		{
    			hm.put(key,k+","+ true);
        		return true;
    		}
    	}
    	hm.put(key, k+","+false);
		return false;	
    }
    static int solution()
    {
    	int[] A= {0,2,2,3},B= {1,1,4,4};
    	int n=A.length;
    	int[][] graph=new int[n+1][n+1];
    	Queue<Integer> leaves=new LinkedList<>();
    	boolean[] visited=new boolean[n+1];
    	visited[0]=true;
    	int ans=0;
    	for(int i=0;i<n;i++)
    	{
    		graph[A[i]][B[i]]=2;
    		graph[B[i]][A[i]]=1;
    		if(A[i]==0)
    		{
    			visited[B[i]]=true;
    			ans++;
    			leaves.add(B[i]);
    		}
    		else if(B[i]==0){
    			visited[A[i]]=true;
				leaves.add(A[i]);
			}
    	}
    	while (!leaves.isEmpty()) {
			int curr=leaves.poll();
			for(int j=1;j<=n;j++)
			{
				if(!visited[j]&&graph[curr][j]>0)
				{
					visited[j]=true;
					leaves.add(j);
					if(graph[curr][j]==2)
						ans++;
				}
			}
		}
    	return ans;
    }
    static int solution2(int[] X,int[] Y)
    {
    	HashMap<String,Integer> hs=new HashMap<>();
    	int ans=0;
    	for(int i=0;i<X.length;i++)
    	{
    		int gcd=gcd(X[i],Y[i]);
    		hs.put((X[i]/gcd)+","+(Y[i]/gcd),hs.getOrDefault((X[i]/gcd)+","+(Y[i]/gcd), 0)+1);
    		ans=Math.max(ans,hs.get((X[i]/gcd)+","+(Y[i]/gcd)));
    	}
    	return ans;
    }
    static boolean helper(List<Integer>[] graph,int st,int[] path,int c,boolean[] visited)
    {
    	if(visited[st])
    	{
    		return false;
    	}
    	if(c==graph.length-1)
    	{
    		path[c]=st;
    		return true;
    	}
    	visited[st]=true;


    	for(int j:graph[st])
    	{


    		{
    			if(helper(graph, j, path,c+1, visited))
    			{
    				path[c]=j;
    				return true;
    			}
    		}
    	}
    	visited[st]=false;
    	return false;
    	
    }
    public static void main(String[] args)throws IOException
    {
        BufferedReader bReader=new BufferedReader(new InputStreamReader(System.in));
        FastReader fs=new FastReader();


        int T=fs.nextInt();


        StringBuilder sb=new StringBuilder();
        
        while(T-->0)
        {
        	int n=fs.nextInt();
        	int[] arr=fs.nextArray(n);
        	List<Integer>[] graph=new ArrayList[n+2];
        	for(int i=0;i<n+2;i++)
        		graph[i]=new ArrayList<>();
        	for(int i=1;i<n;i++)
        	{
        		graph[i].add(i+1);
        	}
        	for(int i=0;i<n;i++)
        	{
        		if(arr[i]==0)
        			graph[i+1].add(n+1);
        		else {
					graph[n+1].add(i+1);
				}
        	}
        	boolean ans=false;
        	for(int i=1;i<=n+1;i++)
        	{
        		boolean visited[]=new boolean[n+2];
        		int[] path=new int[n+2];
        		
        		if(helper(graph, i, path, 1, visited))
        		{
        			ans=true;
        			sb.append(i);
        			for(int j=1;j<=n;j++)
        				sb.append(" ").append(path[j]);
        			break;
        		}
        	}
        	if(!ans)
        		sb.append(-1);
            sb.append("\n");
        }
        System.out.println(sb);
    }
}