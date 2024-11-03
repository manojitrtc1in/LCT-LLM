import java.io.*;
import java.util.*;

public class Main
{
    public static void main(String[] args) throws IOException
    {
        Reader in = new Reader();
        int t = in.nextInt();
        StringBuilder stringBuilder = new StringBuilder();
        while (t-- > 0)
        {
            long n = in.nextLong();
            long x = in.nextLong();
            long y = in.nextLong();
            long lx = x - 1;
            long ly = y - 1;
            long gx = n - x;
            long gy = n - y;
            long minn = 0L;
            long temp = Math.min(lx, gy);
            if (temp > 0)
            {
                minn += temp;
                lx -= temp;
                gy -= temp;
            }

            temp = Math.min(gx, ly);
            if (temp > 0)
            {
                minn += temp;
                gx -= temp;
                ly -= temp;
            }

            temp = Math.min(lx, ly);
            minn += Math.min(lx, ly);
            lx -= temp;
            ly -= temp;
            lx = x - 1;
            ly = y - 1;
            gx = n - x;
            gy = n - y;
            long maxx = 0L;
            temp = Math.min(lx, gy - 1);
            if (temp > 0)
            {
                maxx += temp;
                lx -= temp;
                gy -= temp;
            }

            temp = Math.min(gx - 1, ly);
            if (temp > 0)
            {
                maxx += temp;
                gx -= temp;
                ly -= temp;
            }

            temp = Math.min(gx, gy);
            maxx += Math.min(gx, gy);
            gx -= temp;
            gy -= temp;
            stringBuilder.append(n - maxx).append(" ").append(1 + minn).append("\n");
        }
        System.out.println(stringBuilder);
    }
}
class DSU
{
    int[] parent;
    int[] size;
    

    DSU(int n)
    {
        this.parent = new int[n];
        this.size = new int[n];
        Arrays.fill(parent, -1);
    }

    public void makeSet(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    public int findSet(int v)
    {
        if (v == parent[v]) return v;
        return parent[v] = findSet(parent[v]);
    }

    public void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (size[a] < size[b])
            {
                int temp = a;
                a = b;
                b = temp;
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
}
class id22
{
    private void fft(double[] a, double[] b, boolean invert)
    {
        int count = a.length;
        for (int i = 1, j = 0; i < count; i++)
        {
            int bit = count >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
            {
                double temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
        for (int len = 2; len <= count; len <<= 1)
        {
            int halfLen = len >> 1;
            double angle = 2 * Math.PI / len;
            if (invert)
                angle = -angle;
            double id21 = Math.cos(angle);
            double id4 = Math.sin(angle);
            for (int i = 0; i < count; i += len)
            {
                double wA = 1;
                double wB = 0;
                for (int j = 0; j < halfLen; j++)
                {
                    double uA = a[i + j];
                    double uB = b[i + j];
                    double vA = a[i + j + halfLen] * wA - b[i + j + halfLen] * wB;
                    double vB = a[i + j + halfLen] * wB + b[i + j + halfLen] * wA;
                    a[i + j] = uA + vA;
                    b[i + j] = uB + vB;
                    a[i + j + halfLen] = uA - vA;
                    b[i + j + halfLen] = uB - vB;
                    double nextWA = wA * id21 - wB * id4;
                    wB = wA * id4 + wB * id21;
                    wA = nextWA;
                }
            }
        }
        if (invert)
        {
            for (int i = 0; i < count; i++)
            {
                a[i] /= count;
                b[i] /= count;
            }
        }
    }

    public long[] multiply(long[] a, long[] b)
    {
        int resultSize = Integer.highestOneBit(Math.max(a.length, b.length) - 1) << 2;
        resultSize = Math.max(resultSize, 1);
        double[] aReal = new double[resultSize];
        double[] id12 = new double[resultSize];
        double[] bReal = new double[resultSize];
        double[] id34 = new double[resultSize];
        for (int i = 0; i < a.length; i++)
            aReal[i] = a[i];
        for (int i = 0; i < b.length; i++)
            bReal[i] = b[i];
        fft(aReal, id12, false);
        fft(bReal, id34, false);
        for (int i = 0; i < resultSize; i++)
        {
            double real = aReal[i] * bReal[i] - id12[i] * id34[i];
            id12[i] = id12[i] * bReal[i] + id34[i] * aReal[i];
            aReal[i] = real;
        }
        fft(aReal, id12, true);
        long[] result = new long[resultSize];
        for (int i = 0; i < resultSize; i++)
            result[i] = Math.round(aReal[i]);
        return result;
    }
}
class NumberTheory
{
    public boolean isPrime(long n)
    {
        if(n < 2)
            return false;
        for(long x = 2;x * x <= n;x++)
        {
            if(n % x == 0)
                return false;
        }
        return true;
    }
    public ArrayList<Long> id31(long n)
    {
        ArrayList<Long> f = new ArrayList<>();
        for(long x=2;x * x <= n;x++)
        {
            while(n % x == 0)
            {
                f.add(x);
                n /= x;
            }
        }
        if(n > 1)
            f.add(n);
        return f;
    }
    public int[] id23(int n)
    {
        

        int[] sieve = new int[n + 1];
        for(int x=2;x * x <= n;x++)
        {
            if(sieve[x] != 0)
                continue;
            for(int u=x*x;u<=n;u+=x)
            {
                if(sieve[u] == 0)
                {
                    sieve[u] = x;
                }
            }
        }
        return sieve;
    }
    public long gcd(long a, long b)
    {
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }
    public long phi(long n)
    {
        double result = n;

        for(long p=2;p*p<=n;p++)
        {
            if(n % p == 0)
            {
                while (n % p == 0)
                    n /= p;
                result *= (1.0 - (1.0 / (double)p));
            }
        }
        if(n > 1)
            result *= (1.0 - (1.0 / (double)n));
        return (long)result;
    }
    public Name id26(long a, long b)
    {
        if(b == 0)
            return new Name(a, 1, 0);
        Name n1 = id26(b, a % b);
        Name n2 = new Name(n1.d, n1.y, n1.x - (long)Math.floor((double)a / b) * n1.y);
        return n2;
    }
    public long id28(long a, long b, long n)
    {
        long d = 1L;
        String bString = Long.toBinaryString(b);
        for(int i=0;i<bString.length();i++)
        {
            d = (d * d) % n;
            if(bString.charAt(i) == '1')
                d = (d * a) % n;
        }
        return d;
    }
}
class Name
{
    long d;
    long x;
    long y;

    public Name(long d, long x, long y)
    {
        this.d = d;
        this.x = x;
        this.y = y;
    }
}
class SuffixArray
{
    int id8 = 256, N;
    int[] T, lcp, sa, sa2, rank, tmp, c;

    public SuffixArray(String str)
    {
        this(id14(str));
    }

    private static int[] id14(String s)
    {
        int[] text = new int[s.length()];
        for (int i = 0; i < s.length(); i++) text[i] = s.charAt(i);
        return text;
    }

    public SuffixArray(int[] text)
    {
        T = text;
        N = text.length;
        sa = new int[N];
        sa2 = new int[N];
        rank = new int[N];
        c = new int[Math.max(id8, N)];
        construct();
        kasai();
    }

    private void construct()
    {
        int i, p, r;
        for (i = 0; i < N; ++i) c[rank[i] = T[i]]++;
        for (i = 1; i < id8; ++i) c[i] += c[i - 1];
        for (i = N - 1; i >= 0; --i) sa[--c[T[i]]] = i;
        for (p = 1; p < N; p <<= 1)
        {
            for (r = 0, i = N - p; i < N; ++i) sa2[r++] = i;
            for (i = 0; i < N; ++i) if (sa[i] >= p) sa2[r++] = sa[i] - p;
            Arrays.fill(c, 0, id8, 0);
            for (i = 0; i < N; ++i) c[rank[i]]++;
            for (i = 1; i < id8; ++i) c[i] += c[i - 1];
            for (i = N - 1; i >= 0; --i) sa[--c[rank[sa2[i]]]] = sa2[i];
            for (sa2[sa[0]] = r = 0, i = 1; i < N; ++i)
            {
                if (!(rank[sa[i - 1]] == rank[sa[i]]
                        && sa[i - 1] + p < N
                        && sa[i] + p < N
                        && rank[sa[i - 1] + p] == rank[sa[i] + p])) r++;
                sa2[sa[i]] = r;
            }
            tmp = rank;
            rank = sa2;
            sa2 = tmp;
            if (r == N - 1) break;
            id8 = r + 1;
        }
    }

    private void kasai()
    {
        lcp = new int[N];
        int[] inv = new int[N];
        for (int i = 0; i < N; i++) inv[sa[i]] = i;
        for (int i = 0, len = 0; i < N; i++)
        {
            if (inv[i] > 0)
            {
                int k = sa[inv[i] - 1];
                while ((i + len < N) && (k + len < N) && T[i + len] == T[k + len]) len++;
                lcp[inv[i] - 1] = len;
                if (len > 0) len--;
            }
        }
    }
}
class ZAlgorithm
{
    public int[] calculateZ(char input[])
    {
        int Z[] = new int[input.length];
        int left = 0;
        int right = 0;
        for(int k = 1; k < input.length; k++) {
            if(k > right) {
                left = right = k;
                while(right < input.length && input[right] == input[right - left]) {
                    right++;
                }
                Z[k] = right - left;
                right--;
            } else {
                

                int k1 = k - left;
                

                if(Z[k1] < right - k + 1) {
                    Z[k] = Z[k1];
                } else { 

                    left = k;
                    while(right < input.length && input[right] == input[right - left]) {
                        right++;
                    }
                    Z[k] = right - left;
                    right--;
                }
            }
        }
        return Z;
    }
    public ArrayList<Integer> matchPattern(char text[], char pattern[])
    {
        char newString[] = new char[text.length + pattern.length + 1];
        int i = 0;
        for(char ch : pattern) {
            newString[i] = ch;
            i++;
        }
        newString[i] = '$';
        i++;
        for(char ch : text) {
            newString[i] = ch;
            i++;
        }
        ArrayList<Integer> result = new ArrayList<>();
        int Z[] = calculateZ(newString);

        for(i = 0; i < Z.length ; i++) {
            if(Z[i] == pattern.length) {
                result.add(i - pattern.length - 1);
            }
        }
        return result;
    }
}
class id2
{
    public int[] id7(char[] pattern)
    {
        int[] lps = new int[pattern.length];

        int index = 0;
        for(int i=1;i<pattern.length;)
        {
            if(pattern[i] == pattern[index])
            {
                lps[i] = index + 1;
                index++;
                i++;
            }
            else
            {
                if(index != 0)
                {
                    index = lps[index - 1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    public ArrayList<Integer> id5(char[] text, char[] pattern)
    {
        int[] lps = id7(pattern);

        int j = 0;
        int i = 0;
        int n = text.length;
        int m = pattern.length;
        ArrayList<Integer> indices = new ArrayList<>();
        while(i < n)
        {
            if(pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if(j == m)
            {
                indices.add(i - j);
                j = lps[j - 1];
            }
            else if(i < n && pattern[j] != text[i])
            {
                if(j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return indices;
    }
}
class Hashing
{
    public long[] id10(long p, int n, long m)
    {
        long[] powers = new long[n];
        powers[0] = 1;
        for(int i=1;i<n;i++)
        {
            powers[i] = (powers[i - 1] * p) % m;
        }
        return powers;
    }
    public long computeHash(String s)
    {
        long p = 31;
        long m = 1_000_000_009;
        long hashValue = 0L;
        long[] powers = id10(p, s.length(), m);
        for(int i=0;i<s.length();i++)
        {
            char ch = s.charAt(i);
            hashValue = (hashValue + (ch - 'a' + 1) * powers[i]) % m;
        }
        return hashValue;
    }
}
class BasicFunctions
{
    public int id24(int[] A)
    {
        int max = Integer.MIN_VALUE;
        for (int i=0;i<A.length;i++)    max = Math.max(max, A[i]);
        return max;
    }
    public long id27(long[] A)
    {
        long max = Long.MIN_VALUE;
        for (int i=0;i<A.length;i++)    max = Math.max(max, A[i]);
        return max;
    }
    public int id0(int[] A)
    {
        int min = Integer.MAX_VALUE;
        for (int i=0;i<A.length;i++)    min = Math.min(min, A[i]);
        return min;
    }
    public long id15(long[] A)
    {
        long min = Long.MAX_VALUE;
        for (int i=0;i<A.length;i++)    min = Math.min(min, A[i]);
        return min;
    }

}
class id30
{
    

    

    

    void merge(int arr[], int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        int L[] = new int[n1];
        int R[] = new int[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(int arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }

}
class id9
{
    

    

    

    void merge(long arr[], int l, int m, int r) {
        

        int n1 = m - l + 1;
        int n2 = r - m;

        
        long L[] = new long[n1];
        long R[] = new long[n2];

        
        for (int i = 0; i < n1; ++i)
            L[i] = arr[l + i];
        for (int j = 0; j < n2; ++j)
            R[j] = arr[m + 1 + j];


        

        

        int i = 0, j = 0;

        

        int k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    

    

    void sort(long arr[], int l, int r) {
        if (l < r) {
            

            int m = (l + r) / 2;

            

            sort(arr, l, m);
            sort(arr, m + 1, r);

            

            merge(arr, l, m, r);
        }
    }
}
class Node
{

    int x;
    int y;

    public Node(int x, int y)
    {
        this.x = x;
        this.y = y;
    }

    @Override
    public boolean equals(Object ob)
    {
        if(ob == null)
            return false;
        if(!(ob instanceof Node))
            return false;
        if(ob == this)
            return true;
        Node obj = (Node)ob;
        if(this.x == obj.x && this.y == obj.y)
            return true;
        return false;
    }

    @Override
    public int hashCode()
    {
        return (int)this.x;
    }
}

class SegmentTree
{
    public int id29(int num)
    {
        if(num == 0)
            return 1;
        if(num > 0 && (num & (num - 1)) == 0)
            return num;
        while((num &(num - 1)) > 0)
        {
            num = num & (num - 1);
        }
        return num << 1;
    }
    public int[] id20(int[] input)
    {
        int np2 = id29(input.length);
        int[] segmentTree = new int[np2 * 2 - 1];

        for(int i=0;i<segmentTree.length;i++)
            segmentTree[i] = Integer.MIN_VALUE;

        id13(segmentTree,input,0,input.length-1,0);
        return segmentTree;

    }
    private void id13(int[] segmentTree,int[] input,int low,int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/ 2;
        id13(segmentTree,input,low,mid,2*pos + 1);
        id13(segmentTree,input,mid+1,high,2*pos + 2);
        segmentTree[pos] = Math.max(segmentTree[2*pos + 1],segmentTree[2*pos + 2]);
    }
    public int id6(int []segmentTree,int qlow,int qhigh,int len)
    {
        return id6(segmentTree,0,len-1,qlow,qhigh,0);
    }
    private int id6(int segmentTree[],int low,int high,int qlow,int qhigh,int pos)
    {
        if(qlow <= low && qhigh >= high){
            return segmentTree[pos];
        }
        if(qlow > high || qhigh < low){
            return Integer.MIN_VALUE;
        }
        int mid = (low+high)/2;
        return Math.max(id6(segmentTree, low, mid, qlow, qhigh, 2 * pos + 1),
                id6(segmentTree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
    }
}
class Trie
{

    private class TrieNode
    {
        Map<Character, TrieNode> children;
        boolean id16;
        public TrieNode()
        {
            children = new HashMap<>();
            id16 = false;
        }
    }

    private final TrieNode root;
    public Trie()
    {
        root = new TrieNode();
    }

    public void insert(String word)
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);
            if (node == null)
            {
                node = new TrieNode();
                current.children.put(ch, node);
            }
            current = node;
        }
        current.id16 = true;
    }

    public boolean search(String word)
    {
        TrieNode current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char ch = word.charAt(i);
            TrieNode node = current.children.get(ch);
            if (node == null)
            {
                return false;
            }
            current = node;
        }
        return current.id16;
    }

    public void delete(String word)
    {
        delete(root, word, 0);
    }

    private boolean delete(TrieNode current, String word, int index)
    {
        if (index == word.length())
        {
            if (!current.id16)
            {
                return false;
            }
            current.id16 = false;
            return current.children.size() == 0;
        }
        char ch = word.charAt(index);
        TrieNode node = current.children.get(ch);
        if (node == null)
        {
            return false;
        }
        boolean id17 = delete(node, word, index + 1);

        if (id17)
        {
            current.children.remove(ch);
            return current.children.size() == 0;
        }
        return false;
    }
}
class id19
{
    public int id29(int num)
    {
        if(num == 0)
            return 1;
        if(num > 0 && (num & (num - 1)) == 0)
            return num;
        while((num &(num - 1)) > 0)
        {
            num = num & (num - 1);
        }
        return num << 1;
    }

    public int[] id20(int input[])
    {
        int id25 = id29(input.length);
        int segmentTree[] = new int[id25*2 -1];

        for(int i=0; i < segmentTree.length; i++){
            segmentTree[i] = Integer.MAX_VALUE;
        }
        id1(segmentTree, input, 0, input.length - 1, 0);
        return segmentTree;
    }

    private void id1(int segmentTree[], int input[], int low, int high,int pos)
    {
        if(low == high)
        {
            segmentTree[pos] = input[low];
            return;
        }
        int mid = (low + high)/2;
        id1(segmentTree, input, low, mid, 2 * pos + 1);
        id1(segmentTree, input, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = Math.min(segmentTree[2*pos+1], segmentTree[2*pos+2]);
    }

    public void id11(int input[], int segmentTree[], int lazy[], int startRange, int endRange, int delta)
    {
        id11(segmentTree, lazy, startRange, endRange, delta, 0, input.length - 1, 0);
    }

    private void id11(int segmentTree[], int lazy[], int startRange, int endRange, int delta, int low, int high, int pos)
    {
        if(low > high)
        {
            return;
        }
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if (low != high)
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(startRange > high || endRange < low)
        {
            return;
        }

        if(startRange <= low && endRange >= high)
        {
            segmentTree[pos] += delta;
            if(low != high) {
                lazy[2*pos + 1] += delta;
                lazy[2*pos + 2] += delta;
            }
            lazy[pos] = 0;
        }

        int mid = (low + high)/2;
        id11(segmentTree, lazy, startRange, endRange, delta, low, mid, 2*pos+1);
        id11(segmentTree, lazy, startRange, endRange, delta, mid+1, high, 2*pos+2);
        segmentTree[pos] = Math.min(segmentTree[2*pos + 1], segmentTree[2*pos + 2]);
    }

    public int id33(int segmentTree[], int lazy[], int qlow, int qhigh, int len)
    {
        return id33(segmentTree, lazy, qlow, qhigh, 0, len - 1, 0);
    }

    private int id33(int segmentTree[], int lazy[], int qlow, int qhigh, int low, int high, int pos)
    {
        if(low > high)
        {
            return Integer.MAX_VALUE;
        }
        if (lazy[pos] != 0)
        {
            segmentTree[pos] += lazy[pos];
            if (low != high)
            {
                lazy[2 * pos + 1] += lazy[pos];
                lazy[2 * pos + 2] += lazy[pos];
            }
            lazy[pos] = 0;
        }

        if(qlow > high || qhigh < low)
        {
            return Integer.MAX_VALUE;
        }

        if(qlow <= low && qhigh >= high)
        {
            return segmentTree[pos];
        }

        int mid = (low+high)/2;
        return Math.min(id33(segmentTree, lazy, qlow, qhigh, low, mid, 2 * pos + 1), id33(segmentTree, lazy,  qlow, qhigh, mid + 1, high, 2 * pos + 2));
    }
}
class BIT
{
    int size;
    long[] table;
    public BIT(int size)
    {
        table = new long[size];
        this.size = size;
    }

    void update(int i, long delta)
    {
        while (i > 0)
        {
            table[i] += delta;
            i -= Integer.lowestOneBit(i);
        }
    }

    long sum(int i)
    {
        long sum = 0L;
        while (i < size)
        {
            sum += table[i];
            i += Integer.lowestOneBit(i);
        }
        return sum;
    }
}
class EulerPath
{
    private int n;
    private int edgeCount;
    private int[] in, out;
    private LinkedList<Integer> path = new LinkedList<>();
    private ArrayList<Integer>[] adj;

    public EulerPath(int n, ArrayList<Integer>[] adj)
    {
        this.n = n;
        this.adj = adj;
        in = new int[n];
        out = new int[n];
        edgeCount = 0;
        for (int i=0;i<n;i++)
        {
            out[i] = adj[i].size();
            for (int j: adj[i])
                in[j] ++;
            edgeCount += out[i];
        }
    }

    public boolean id32()
    {
        if (edgeCount == 0)
            return false;
        int startNodes = 0;
        int endNodes = 0;
        for (int i=0;i<n;i++)
        {
            if (out[i] - in[i] > 1 || in[i] - out[i] > 1)   return false;
            else if (out[i] - in[i] == 1)   startNodes++;
            else if (in[i] - out[i] == 1)   endNodes++;
        }
        return (endNodes == 0 && startNodes == 0) || (endNodes == 1 && startNodes == 1);
    }

    private int id18()
    {
        int start = 0;
        for (int i=0;i<n;i++)
        {
            if (out[i] - in[i] == 1)
                return i;
            if (out[i] > 0)
                start = i;
        }
        return start;
    }

    public int[] id3()
    {
        if (!id32()) return null;
        dfs(0);

        if (path.size() != edgeCount + 1)
            return null;
        int[] soln = new int[edgeCount + 1];
        for (int i=0;!path.isEmpty();i++)
            soln[i] = path.removeFirst();
        return soln;
    }

    private void dfs(int v)
    {
        while (out[v] != 0)
        {
            int next = adj[v].get(--out[v]);
            dfs(next);
        }
        path.addFirst(v);
    }
}
class Reader
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