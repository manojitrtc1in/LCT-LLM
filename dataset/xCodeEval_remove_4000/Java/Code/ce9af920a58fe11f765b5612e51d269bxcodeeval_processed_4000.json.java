import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
    static long mod = (int)1e9+7;
    

	public static void main (String[] args) throws java.lang.Exception
	{
		FastReader sc =new FastReader();
		
	    int t=sc.nextInt();
	    
	   

	    
	    outer : while(t-->0)
	    {
	        int n = sc.nextInt();
	        int m = sc.nextInt();
	        int[][] arr = new int[n][n];
	        for(int i=0;i<m;i++)
	        {
	            int r = sc.nextInt() - 1;
	            int c = sc.nextInt() - 1;
	        }
	        
	        if(m < n)
	        {
	            System.out.println("YES");
	        }
	        else
	        {
	            System.out.println("NO");
	        }
	    }
	    
	}
	
	static boolean isValid(int i , int j , int[][] arr , int n , ArrayList<Pair> list)
	{
	    if(up(i - 1 , j , arr , n , list))
	    {
	        return true;
	    }
	    if(down(i + 1 , j , arr , n , list))
	    {
	        return true;
	    }
	    if(left(i , j - 1  , arr , n , list))
	    {
	        return true;
	    }
	    if(right(i , j + 1 , arr , n , list))
	    {
	        return true;
	    }
	    return false;
	}
	
	
	static boolean up(int i , int j , int[][] arr , int n , ArrayList<Pair> list)
	{
	    while(i >= 0)
	    {
	        for(Pair x:list)
	        {
	            int f = x.first;
	            int s = x.second;
	            if(f == i && s == j)
	            {
	                continue;
	            }
	            if(f != i && f != j && s != i && s != j)
	            {
	                return true;
	            }
	        }
	        i--;
	    }
	    return false;
	}
	
	static boolean down(int i , int j , int[][] arr , int n , ArrayList<Pair> list)
	{
	    while(i < n)
	    {
	        for(Pair x:list)
	        {
	            int f = x.first;
	            int s = x.second;
	            if(f == i && s == j)
	            {
	                continue;
	            }
	            if(f != i && f != j && s != i && s != j)
	            {
	                return true;
	            }
	        }
	        i++;
	    }
	    return false;
	}
	
	static boolean left(int i , int j , int[][] arr , int n , ArrayList<Pair> list)
	{
	    while(j >= 0)
	    {
	        for(Pair x:list)
	        {
	            int f = x.first;
	            int s = x.second;
	            if(f == i && s == j)
	            {
	                continue;
	            }
	            if(f != i && f != j && s != i && s != j)
	            {
	                return true;
	            }
	        }
	        j--;
	    }
	    return false;
	}
	
	static boolean right(int i , int j , int[][] arr , int n , ArrayList<Pair> list)
	{
	    while(j < n)
	    {
	        for(Pair x:list)
	        {
	            int f = x.first;
	            int s = x.second;
	            if(f == i && s == j)
	            {
	                continue;
	            }
	            if(f != i && f != j && s != i && s != j)
	            {
	                return true;
	            }
	        }
	        j++;
	    }
	    return false;
	}
	
	static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
        
        float nextFloat()
        {
            return Float.parseFloat(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
        
        int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		long[] id14(int n) {
			long[] a=new long[n];
			for (int i=0; i<n; i++) a[i]=nextLong();
			return a;
		}
		
    }
    
    static class id13
    {
        

        

        public int[] tree;
        public int size;
     
        public id13(int size)
        {
            this.size = size;
            tree = new int[size+5];
        }
        public void add(int i, int v)
        {
            while(i <= size)
            {
                tree[i] += v;
                i += i&-i;
            }
        }
        public int find(int i)
        {
            int res = 0;
            while(i >= 1)
            {
                res += tree[i];
                i -= i&-i;
            }
            return res;
        }
        public int find(int l, int r)
        {
            return find(r)-find(l-1);
        }
    }
    
    
    
    public static int[] id11(int[] a)
	{
		int n = a.length;
		int[] c0 = new int[0x101];
		int[] c1 = new int[0x101];
		int[] c2 = new int[0x101];
		int[] c3 = new int[0x101];
		for(int v : a) {
			c0[(v&0xff)+1]++;
			c1[(v>>>8&0xff)+1]++;
			c2[(v>>>16&0xff)+1]++;
			c3[(v>>>24^0x80)+1]++;
		}
		for(int i = 0;i < 0xff;i++) {
			c0[i+1] += c0[i];
			c1[i+1] += c1[i];
			c2[i+1] += c2[i];
			c3[i+1] += c3[i];
		}
		int[] t = new int[n];
		for(int v : a)t[c0[v&0xff]++] = v;
		for(int v : t)a[c1[v>>>8&0xff]++] = v;
		for(int v : a)t[c2[v>>>16&0xff]++] = v;
		for(int v : t)a[c3[v>>>24^0x80]++] = v;
		return a;
	}
	
	private static long id6(int[] arr, int l,
                                     int m, int r)
    {
 
        

        int[] left = Arrays.copyOfRange(arr, l, m + 1);
 
        

        int[] right = Arrays.copyOfRange(arr, m + 1, r + 1);
 
        int i = 0, j = 0, k = l;long swaps = 0;
 
        while (i < left.length && j < right.length) {
            if (left[i] < right[j])
                arr[k++] = left[i++];
            else {
                arr[k++] = right[j++];
                swaps += (m + 1) - (l + i);
            }
        }
        while (i < left.length)
            arr[k++] = left[i++];
        while (j < right.length)
            arr[k++] = right[j++];
        return swaps;
    }
 
    

    private static long id10(int[] arr, int l,
                                         int r)
    {
 
        

        

        long count = 0;
 
        if (l < r) {
            int m = (l + r) / 2;
 
            

            

 
            

            count += id10(arr, l, m);
 
            

            count += id10(arr, m + 1, r);
 
            

            count += id6(arr, l, m, r);
        }
 
        return count;
    }
	
	static void my_sort(long[] arr)
	{
	    ArrayList<Long> list = new ArrayList<>();
	    for(int i=0;i<arr.length;i++)
	    {
	        list.add(arr[i]);
	    }
	    Collections.sort(list);
	    for(int i=0;i<arr.length;i++)
	    {
	        arr[i] = list.get(i);
	    }
	}
	
	static void reverse_sorted(int[] arr)
	{
	    ArrayList<Integer> list = new ArrayList<>();
	    for(int i=0;i<arr.length;i++)
	    {
	        list.add(arr[i]);
	    }
	    Collections.sort(list , Collections.reverseOrder());
	    for(int i=0;i<arr.length;i++)
	    {
	        arr[i] = list.get(i);
	    }
	}
	
	static int LowerBound(int a[], int x) { 

        int l=-1,r=a.length;
        while(l+1<r) {
            int m=(l+r)>>>1;
            if(a[m]>=x) r=m;
            else l=m;
        }
        return r;
    }
    
    static int UpperBound(ArrayList<Integer> list, int x) {

        int l=-1,r=list.size();
        while(l+1<r) {
            int m=(l+r)>>>1;
            if(list.get(m)<=x) l=m;
            else r=m;
        }
        return l+1;
    }
    
    public static HashMap<Integer, Integer> id2(HashMap<Integer, Integer> hm)
    {
        

        List<Map.Entry<Integer, Integer> > list =
               new LinkedList<Map.Entry<Integer, Integer> >(hm.entrySet());
 
        

        Collections.sort(list, new Comparator<Map.Entry<Integer, Integer> >() {
            public int compare(Map.Entry<Integer, Integer> o1,
                               Map.Entry<Integer, Integer> o2)
            {
                return (o1.getValue()).compareTo(o2.getValue());
            }
        });
         
        

        HashMap<Integer, Integer> temp = new LinkedHashMap<Integer, Integer>();
        for (Map.Entry<Integer, Integer> aa : list) {
            temp.put(aa.getKey(), aa.getValue());
        }
        return temp;
    }
    
    static class id4 implements Comparable<id4> {
		int first , second;
		public id4(int first, int second) {
			this.first=first;
			this.second=second;
		}
		public int compareTo(id4 o) {
			return Integer.compare(o.first, first);
		}
	}
    
    static void leftRotate(int arr[], int d, int n)
    {
        for (int i = 0; i < d; i++)
            id7(arr, n);
    }
 
    static void id7(int arr[], int n)
    {
        int i, temp;
        temp = arr[0];
        for (i = 0; i < n - 1; i++)
            arr[i] = arr[i + 1];
        arr[n-1] = temp;
        
    }
    
    static boolean isPalindrome(String str)
    {
 
        

        

        int i = 0, j = str.length() - 1;
 
        

        while (i < j) {
 
            

            if (str.charAt(i) != str.charAt(j))
                return false;
 
            

            

            i++;
            j--;
        }
 
        

        return true;
    }
    
    static boolean id5(char arr[], int n)
    {
        

        int flag = 0;
 
        

        for (int i = 0; i <= n / 2 && n != 0; i++) {
 
            

            

            if (arr[i] != arr[n - i - 1]) {
                flag = 1;
                break;
            }
        }
 
        

        

        if (flag == 1)
            return false;
        else
            return true;
    }
    
	static boolean id0(int[] arr,int n)
	{
	    int z=0;
	        for(int i=0;i<n-1;i++)
		    {
		        if(arr[i]==arr[i+1])
		        {
		            z++;
		        }
		    }
		    if(z==n-1)
		    {
		        return true;
		    }
		    else
		    {
		        return false;
		    }
		    
	}
	
	static boolean id8(int[] arr,int n)
	{
	    int z=0;
	        for(int i=0;i<n-1;i++)
		    {
		        if(arr[i]!=arr[i+1])
		        {
		            z++;
		        }
		    }
		    if(z==n-1)
		    {
		        return true;
		    }
		    else
		    {
		        return false;
		    }
		    
		    
	}
	
	public static void reverse(int[] array)
    {
  
        

        int n = array.length;
  
        

        

        for (int i = 0; i < n / 2; i++) {
  
            

            int temp = array[i];
  
            

            array[i] = array[n - i - 1];
  
            

            array[n - i - 1] = temp;
        }
    }
    
    public static void reverse_Long(long[] array)
    {
  
        

        int n = array.length;
  
        

        

        for (int i = 0; i < n / 2; i++) {
  
            

            long temp = array[i];
  
            

            array[i] = array[n - i - 1];
  
            

            array[n - i - 1] = temp;
        }
    }
	
	static boolean isSorted(int[] a)
    {
        for (int i = 0; i < a.length - 1; i++)
        {
            if (a[i] > a[i + 1]) {
                return false;
            }
        }
 
        return true;
    }
    
    
    
    static boolean id3(int[] a)
    {
        for (int i = 0; i < a.length - 1; i++)
        {
            if (a[i] < a[i + 1]) {
                return false;
            }
        }
 
        return true;
    }
    
    static int[] id12(int arr[], int n)
    {
        ArrayList<Integer> list = new ArrayList<>();
		    
		    for(int i=0;i<n;i++)
		    {
		        if(arr[i]%2==0)
		        {
		            list.add(arr[i]);
		        }
		    }
		    
		    for(int i=0;i<n;i++)
		    {
		        if(arr[i]%2!=0)
		        {
		            list.add(arr[i]);
		        }
		    }
		    int len = list.size();
		    int[] array = list.stream().mapToInt(i->i).toArray();
		    return array;
    }
    
    static long[] id9(long arr[], int n)
    {
        ArrayList<Long> list = new ArrayList<>();
		    
		    for(int i=0;i<n;i++)
		    {
		        if(arr[i]%2==0)
		        {
		            list.add(arr[i]);
		        }
		    }
		    
		    for(int i=0;i<n;i++)
		    {
		        if(arr[i]%2!=0)
		        {
		            list.add(arr[i]);
		        }
		    }
		    int len = list.size();
		    long[] array = list.stream().mapToLong(i->i).toArray();
		    return array;
    }
	
	
    
    static boolean isPrime(long n)
    {
 
        

        

        if (n <= 1)
            return false;
 
        

        else if (n == 2)
            return true;
 
        

        else if (n % 2 == 0)
            return false;
 
        

        for (long i = 3; i <= Math.sqrt(n); i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    
    static long getSum(long n)
    {    
        long sum = 0;
          
        while (n != 0)
        {
            sum = sum + n % 10;
            n = n/10;
        }
      
    return sum;
    }
    
    static int gcd(int a, int b)
    {
      if (b == 0)
        return a;
      return gcd(b, a % b);
    }
     
    static long id1(long a, long b)
    {
        if (b == 0)
        return a;
      return id1(b, a % b);
    }
    
    static void swap(int i, int j)
    {
        int temp = i;
        i = j;
        j = temp;
    }
	
	static int countDigit(int n)
    {
        return (int)Math.floor(Math.log10(n) + 1);
    }
	
}

class Pair
{
    int first;
    int second;
    Pair(int first , int second)
    {
        this.first = first;
        this.second = second;
    }
}
