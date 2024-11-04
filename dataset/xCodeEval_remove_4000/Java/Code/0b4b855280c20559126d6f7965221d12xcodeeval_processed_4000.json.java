

import java.io.*;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.util.*;

public class Main{

    static long mod=1000000007;
    static int tennine=1000000000;
    

    static ArrayList<ArrayList<Integer>> listList;
    static ArrayList<Long> lolist;
    static ArrayList<pair> plist;
    static ArrayList<Integer> inList;
    static int n;
    static int ar[];
    static int size[];
    static StringBuilder dpp[][][][];
    static int arr[];
    static int m;
    static int fn;
    static int fen[];
    static HashMap<String,Integer> map;
    public static void main(String[] args) throws IOException {
        Reader sc = new Reader();
        

        StringBuilder sb = new StringBuilder("");
        int n=sc.ni();
        arr=new int[n];
        for(int i=0;i<n;i++)
        {
        	arr[i]=sc.ni();
        }
        int c=0;
        ArrayList<ArrayList<Integer>> lili=new ArrayList<>();
        for(int i=n-1;i>-1;i--)
        {
        	ArrayList<Integer>list=new ArrayList<>();
        	for(int j=0;j<i;j++)
        	{
        		if(arr[j]>arr[i]) {
        			list.add(j);
        		}
        	}
        	Collections.sort(list,new cust());
        	for(int j=0;j<list.size();j++)
        	{
        		sb.append((list.get(j)+1)+" "+(i+1));
        		sb.append("\n");
        		c++;
        	}
        }
        StringBuilder cs=new StringBuilder(c+"\n");
        sb=cs.append(sb);
        System.out.println(sb);
    }
    public static class cust implements Comparator<Integer>
    {
    	public int compare(Integer i1,Integer i2)
    	{
    		int ii1=i1;
    		int ii2=i2;
    		return arr[ii1]-arr[ii2];
    	}
    }
    public static boolean poss(int r,int c)
    {
    	return (r>-1&&c>-1&&r<n&&c<m);
    }
    static int cnt=0;
    static int max=100000;
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
    static final int MAXN = 1000001; 
    
    

    static int spf[] = new int[MAXN]; 
       
    

    

    

    static void sieve() 
    { 
        spf[1] = 1; 
        for (int i=2; i<MAXN; i++) 
       
            

            

            spf[i] = i; 
       
        

        

        for (int i=4; i<MAXN; i+=2) 
            spf[i] = 2; 
       
        for (int i=3; i*i<MAXN; i++) 
        { 
            

            if (spf[i] == i) 
            { 
                

                for (int j=i*i; j<MAXN; j+=i) 
       
                    

                    

                    if (spf[j]==j) 
                        spf[j] = i; 
            } 
        } 
    } 
       
    

    

    static ArrayList<Integer> id11(int x) 
    { 
        ArrayList<Integer> ret = new ArrayList<>(); 
        while (x != 1) 
        { 
            ret.add(spf[x]); 
            x = x / spf[x]; 
        } 
        return ret; 
    } 

    static int id8(ArrayList<Integer> list, int ele) {
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


    static class id5 {
        ArrayList<Integer> list;
        int left_sum;
        ArrayList<Integer> left_ele;

        id5() {
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
        public pair id1()
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

    static class id2 implements Comparator<pair> {
        public int compare(pair c1, pair c2) {
            return Long.compare(c1.a, c2.a);
        }
    }

    static class id9 implements Comparator<pair> {
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

    static void id4(int si, int ss, int se, int us,
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
        id4(si * 2 + 1, ss, mid, us, ue, diff);
        id4(si * 2 + 2, mid + 1, se, us, ue, diff);
        tree[si] = Math.max(tree[si * 2 + 1], tree[si * 2 + 2]);
    }

    static void id7(int si, int ss, int se, int us,
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
        id7(si * 2 + 1, ss, mid, us, ue, diff);
        id7(si * 2 + 2, mid + 1, se, us, ue, diff);
        tree2[si] = Math.min(tree2[si * 2 + 1], tree2[si * 2 + 2]);
    }
    static void updateRange(int n, int us, int ue, long diff)
    {
        id4(0, 0, n - 1, us, ue, diff);
        id7(0, 0, n - 1, us, ue, diff);
    }
    static long id6(int ss, int se, int qs, int qe, int si)
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
        return Math.max(id6(ss, mid, qs, qe, 2 * si + 1),
                id6(mid + 1, se, qs, qe, 2 * si + 2));
    }

    static long id10(int ss, int se, int qs, int qe, int si)
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
        return Math.min(id10(ss, mid, qs, qe, 2 * si + 1),
                id10(mid + 1, se, qs, qe, 2 * si + 2));
    }
    static long getMax(int n, int qs, int qe)
    {
        return id6(0, n - 1, qs, qe, 0);
    }
    static long getMin(int n, int qs, int qe)
    {
        return id10(0, n - 1, qs, qe, 0);
    }
    static void id0(long arr[], int ss, int se, int si)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            tree[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        id0(arr, ss, mid, si * 2 + 1);
        id0(arr, mid + 1, se, si * 2 + 2);
        tree[si] = Math.max(tree[si * 2 + 1], tree[si * 2 + 2]);
    }
    static void id3(long arr[], int ss, int se, int si)
    {
        if (ss > se)
            return;
        if (ss == se)
        {
            tree2[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        id3(arr, ss, mid, si * 2 + 1);
        id3(arr, mid + 1, se, si * 2 + 2);
        tree2[si] = Math.min(tree2[si * 2 + 1], tree2[si * 2 + 2]);
    }

    static void constructST(long arr[], int n)
    {
        id0(arr, 0, n - 1, 0);
        id3(arr, 0, n - 1, 0);
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
