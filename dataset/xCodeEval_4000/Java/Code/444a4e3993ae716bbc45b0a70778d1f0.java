

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Main{

    static long mod=1000000007;
    static int tennine=1000000000;
    static ArrayList<ArrayList<Integer>> listList;
    static ArrayList<Long> lolist;
    static ArrayList<pair> plist;
    static ArrayList<Integer> inList;
    static long ca[];
    static long wa[];
    static int fenL=1000000;
    static int result;
    static int count;
    static int low[];
    static int dfsOrder[];
    static int high[];
    static int fenLen;
    static long fen[];
    static long inverse[];
    static int hash[][];
    static int n;
    static int m;
    static int k;
    static int colors[];
    static int grundy[];
    static int comp[];
    static boolean visited[];
    static int arr1[];
    static int arr2[];
    static int dp[][];
    public static void main(String[] args) throws IOException {
        

    	SReader sc = new SReader();
    	StringBuilder sb=new StringBuilder();
    	n=sc.ni();
    	m=sc.ni();
    	arr1=new int[n];
    	arr2=new int[m];
    	for(int i=0;i<n;i++)
    	{
    		arr1[i]=sc.ni();
    	}
    	for(int i=0;i<m;i++)
    	{
    		arr2[i]=sc.ni();
    	}
    	dp=new int[n][513];
    	System.out.println(recurse(0,0));
        System.out.println(sb.toString().trim());
    }
    public static int recurse(int pos,int or)
    {
    	if(pos==n)
    	{
    		return or;
    	}
    	if(dp[pos][or]!=0)
    		return dp[pos][or]-1;
    	int min=Integer.MAX_VALUE/100;
    	for(int i=0;i<m;i++)
    	{
    		min=Math.min(min,recurse(pos+1,or|(arr1[pos]&arr2[i])));
    	}
    	dp[pos][or]=min+1;
    	return min;
    }
    public static int find(ArrayList<pair> list,pair p)
    {
    	int cnt=0;
    	for(pair pp:list)
    	{
    		if(pp.a==p.a&&pp.b==p.b)
    			return cnt;
    		cnt++;
    	}
    	return -1;
    }
    public static boolean poss(int r,int c)
    {
    	return (r>-1&&c>-1&&r<n&&c<m);
    }
    public static boolean possi(int r,int c)
    {
    	return (r>-1&&c>-1&&r<n&&c<m);
    }
    public static class comp implements Comparator<pair>
    {
    	public int compare(pair p1,pair p2)
    	{
    		if(p1.a!=p2.a)
    			return Long.compare(p1.a,p2.a);
    		return Long.compare(p1.b,p2.b);
    	}
    }
    public static void dfs(int node,int cur)
    {
    	if(visited[node])
    		return;
    	comp[node]=cur;
    	visited[node]=true;
    	ArrayList<Integer> li=listList.get(node);
    	for(int i:li)
    	{
    		dfs(i,cur);
    	}
    }
    public static int getGrundy(int n)
    {
    	HashSet<Integer> set=new HashSet<>();
    	for(int i=2;i<=6;i++)
    	{
    		set.add(grundy[n/i]);
    	}
    	

    	return getMex(set);
    }
    public static int recurse(int arr[],int turn)
    {
    	int max=0;
    	for(int i=0;i<26;i++)
    	{
    		max=Math.max(max,arr[i]);
    	}
    	if(max==1)
    		return 1-turn;
    	boolean poss=false;
    	for(int i=0;i<26;i++)
    	{
    		if(arr[i]>0)
    		{
    			arr[i]--;
    			poss=poss||recurse(arr,1-turn)==turn;
    			arr[i]++;
    		}
    	}
    	if(poss)
    		return turn;
    	return 1-turn;
    }
    public static int getGrundyFast(long n)
    {
    	return 1-(int)(n%2);
    }
    public static int getMex(HashSet<Integer>set)
    {
    	int ret=0;
    	while(set.contains(ret))
    		ret++;
    	return ret;
    }
    public static class cdata
    {
    	int a;
    	ArrayList<Integer> b;
    	cdata(int a)
    	{
    		this.a=a;
    		b=new ArrayList<>();
    	}
    }
    static int MAX=1000001;
    static int spf[]=new int[MAX];
    public static ArrayList<Integer> getFactorisation(int num)
    {
    	ArrayList<Integer> list=new ArrayList<>();
    	while(num!=1)
    	{
    		list.add(spf[num]);
    		num/=spf[num];
    	}
    	return list;
    }
    public static void sieve()
    {
    	spf=new int[MAX];
    	for(int i=0;i<MAX;i++)
    	{
    		spf[i]=i;
    	}
    	for(long i=2;i<MAX;i++)
    	{
    		if(spf[(int)i]!=i)
    			continue;
    		for(long j=i*i;j<MAX;j+=i)
    		{
    			if(spf[(int)j]==j)
    			{
    				spf[(int)j]=(int)i;
    			}
    		}
    	}
    }
    public static int getMobius(int ele)
    {
    	ArrayList<Integer> factor=getFactorisation(ele);
    	int hash[]=new int[MAX];
    	int max=0;
    	int cnt=0;
    	for(int i=0;i<factor.size();i++)
    	{
    		hash[factor.get(i)]++;
    		if(hash[factor.get(i)]==1)
    			cnt++;
    		max=Math.max(hash[factor.get(i)],max);
    	}
        if(max>1)
        {
        	return 0;
        }
        else if(cnt%2==0)
        {
        	return 1;
        }
        else
        {
        	return -1;
        }
    }
    public static void printMap(Map mp) {
        Iterator it = mp.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry) it.next();
            System.out.println(pair.getKey() + " = " + pair.getValue());
            it.remove(); 

        }
    }
    static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    

    static long lcm(long a, long b)
    {
        return (a*b)/gcd(a, b);
    }

    static void bin(int n)
    {
        if (n > 1)
            bin(n/2);
        System.out.print(n % 2);
    }
    static long power(long x, long y, long p)
    {
        long res = 1;
        x = x % p;

        while (y > 0)
        {
            if((y & 1)==1)
                res = (res * x) % p;
            y = y >> 1;
            x = (x * x) % p;
        }
        return res;
    }
    static int next(int a[],int start)
    {
        for(int i=start+1;i<a.length;i++)
        {
            if(a[i]!=-1) {
                return i;
            }
        }
        return 0;
    }
    static long g(long a, long b) {
        if (b == 0)
            return a;
        return g(b, a % b);
    }

    public static boolean equal(ArrayList<Integer> a, ArrayList<Integer> b) {
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++) {
            if (a.get(i) != b.get(i))
                return false;
        }
        return true;
    }

    static int bins_first_pos(ArrayList<Integer> list, int ele) {
        int pos1 = Collections.binarySearch(list, ele);
        if (pos1 > -1) {
            int pos2 = Collections.binarySearch(list, ele - 1);
            if (pos2 < 0) {
                pos2 = Math.abs(pos2) - 1;
                return pos2;
            } else {
                for (int i = pos2; i <= pos1; i++) {
                    if (ele == list.get(i))
                        return i;
                }
            }
        } else
            return pos1;
        return 0;
    }


    static class bfs_ele {
        ArrayList<Integer> list;
        int left_sum;
        ArrayList<Integer> left_ele;

        bfs_ele() {
            list = new ArrayList<>();
            left_ele = new ArrayList<>();
            left_sum = 0;
        }

        void init_sum(int a) {
            left_sum = a;
        }
    }

    static class trie {
        long a;
        long b;
        long c;

        trie(long a, long b, long c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public String toString()
        {
        	return a+" "+b+" "+c;
        }
        trie() {
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof trie)) return false;

            trie trie = (trie) o;

            if (a != trie.a) return false;
            if (b != trie.b) return false;
            return c == trie.c;
        }

        @Override
        public int hashCode() {
            int result = (int) (a ^ (a >>> 32));
            result = 31 * result + (int) (b ^ (b >>> 32));
            result = 31 * result + (int) (c ^ (c >>> 32));
            return result;
        }
    }

    static class pair {
        long a;
        long b;

        pair(long a, long b) {
            this.a = a;
            this.b = b;
        }
        public String toString()
        {
            return("a: "+a+" b: "+b);
        }
        pair() {
        }
        public pair getReversePair()
        {
            return new pair(b,a);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof pair)) return false;

            pair pair = (pair) o;

            if (a != pair.a) return false;
            return b == pair.b;
        }

        @Override
        public int hashCode() {
            int result = (int) (a ^ (a >>> 32));
            result = 31 * result + (int) (b ^ (b >>> 32));
            return result;
        }
    }

    static class TrieComparator implements Comparator<trie> {
        public int compare(trie c1, trie c2) {
            return Long.compare(c1.c, c2.c);
        }
    }

    static class PairComparatorpos implements Comparator<pair> {
        public int compare(pair c1, pair c2) {
            return Long.compare(c1.a, c2.a);
        }
    }

    static class PairComparatorval implements Comparator<pair> {
        public int compare(pair c1, pair c2) {
            return Long.compare(c1.b, c2.b);
        }
    }


    static class SReader {
        BufferedReader br;
        StringTokenizer st;

        public SReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        public static void pr(Object s) {
            System.out.println(s);
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int ni() {
            return Integer.parseInt(next());
        }

        long nl() {
            return Long.parseLong(next());
        }

        double nd() {
            return Double.parseDouble(next());
        }

        String rl() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
    static class SegmentTree
    {
        static int MAX =10000000;
        

    static long tree[] = new long[MAX];
    static long lazy[] = new long[MAX];
    

    static long tree2[] = new long[MAX];
    static long lazy2[] = new long[MAX];

    static void updateRangeUtil(int si, int ss, int se, int us,
                                int ue, long diff)
    {
        if (lazy[si] != 0)
        {
            tree[si] += lazy[si];
            if (ss != se)
            {
                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }
            lazy[si] = 0;
        }
        if (ss > se || ss > ue || se < us)
            return;

        if (ss >= us && se <= ue)
        {
            tree[si] += diff;
            if (ss != se)
            {
                lazy[si * 2 + 1] += diff;
                lazy[si * 2 + 2] += diff;
            }
            return;
        }
        int mid = (ss + se) / 2;
        updateRangeUtil(si * 2 + 1, ss, mid, us, ue, diff);
        updateRangeUtil(si * 2 + 2, mid + 1, se, us, ue, diff);
        tree[si] = Math.max(tree[si * 2 + 1], tree[si * 2 + 2]);
    }

    static void updateRangeUtil2(int si, int ss, int se, int us,
                                int ue, long diff)
    {
        if (lazy2[si] != 0)
        {
            tree2[si] += lazy2[si];
            if (ss != se)
            {
                lazy2[si * 2 + 1] += lazy2[si];
                lazy2[si * 2 + 2] += lazy2[si];
            }
            lazy2[si] = 0;
        }
        if (ss > se || ss > ue || se < us)
            return;
        if (ss >= us && se <= ue)
        {
            tree2[si] += diff;
            if (ss != se)
            {
                lazy2[si * 2 + 1] += diff;
                lazy2[si * 2 + 2] += diff;
            }
            return;
        }
        int mid = (ss + se) / 2;
        updateRangeUtil2(si * 2 + 1, ss, mid, us, ue, diff);
        updateRangeUtil2(si * 2 + 2, mid + 1, se, us, ue, diff);
        tree2[si] = Math.min(tree2[si * 2 + 1], tree2[si * 2 + 2]);
    }
    static void updateRange(int n, int us, int ue, long diff)
    {
        updateRangeUtil(0, 0, n - 1, us, ue, diff);
        updateRangeUtil2(0, 0, n - 1, us, ue, diff);
    }
    static long getMaxUtil(int ss, int se, int qs, int qe, int si)
    {
        if (lazy[si] != 0)
        {
            tree[si] += lazy[si];
            if (ss != se)
            {
                lazy[si * 2 + 1] += lazy[si];
                lazy[si * 2 + 2] += lazy[si];
            }
            lazy[si] = 0;
        }
        if (ss > se || ss > qe || se < qs)
            return Long.MIN_VALUE;
        if (ss >= qs && se <= qe)
            return tree[si];
        int mid = (ss + se) / 2;
        return Math.max(getMaxUtil(ss, mid, qs, qe, 2 * si + 1),
                getMaxUtil(mid + 1, se, qs, qe, 2 * si + 2));
    }

    static long getMinUtil(int ss, int se, int qs, int qe, int si)
    {
        if (lazy2[si] != 0)
        {
            tree2[si] += lazy2[si];
            if (ss != se)
            {
                lazy2[si * 2 + 1] += lazy2[si];
                lazy2[si * 2 + 2] += lazy2[si];
            }
            lazy2[si] = 0;
        }
        if (ss > se || ss > qe || se < qs)
            return Long.MAX_VALUE;
        if (ss >= qs && se <= qe)
            return tree2[si];
        int mid = (ss + se) / 2;
        return Math.min(getMinUtil(ss, mid, qs, qe, 2 * si + 1),
                getMinUtil(mid + 1, se, qs, qe, 2 * si + 2));
    }
    static long getMax(int n, int qs, int qe)
    {
        return getMaxUtil(0, n - 1, qs, qe, 0);
    }
    static long getMin(int n, int qs, int qe)
    {
        return getMinUtil(0, n - 1, qs, qe, 0);
    }
    static void constructSTUtil(long arr[], int ss, int se, int si)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            tree[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        constructSTUtil(arr, ss, mid, si * 2 + 1);
        constructSTUtil(arr, mid + 1, se, si * 2 + 2);
        tree[si] = Math.max(tree[si * 2 + 1], tree[si * 2 + 2]);
    }
    static void constructSTUtil2(long arr[], int ss, int se, int si)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            tree2[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        constructSTUtil2(arr, ss, mid, si * 2 + 1);
        constructSTUtil2(arr, mid + 1, se, si * 2 + 2);
        tree2[si] = Math.min(tree2[si * 2 + 1], tree2[si * 2 + 2]);
    }

    static void constructST(long arr[], int n)
    {
        constructSTUtil(arr, 0, n - 1, 0);
        constructSTUtil2(arr, 0, n - 1, 0);
    }
    }
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public static void pr(Object s) {
            System.out.println(s);
        }

        public int ni() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nl() throws IOException {
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

        public String rl() throws IOException {
            byte[] buf = new byte[1024]; 

            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public double nd() throws IOException {
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

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }
}
