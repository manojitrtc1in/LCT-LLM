import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
		public class Solution123{
				public static void main(String[] args) throws IOException{
					FastReader sc = new FastReader();
					int n = sc.nextInt();
					int[] arr = new int[n];
					long[] store = new long[n+1];
					for(int i = 0;i < n;i++){
						arr[i] = sc.nextInt();
					}
					for(int i = 1;i <= n;i++){
						store[i] = store[i-1] + arr[i-1];
					}
					if(store[n] % 3 != 0){
						System.out.println("0");
						System.exit(0);
					}
					long rem = store[n]/3;
					long rem2 = store[n] * 2/3;
					long count1 = 0;
					long ans = 0;
					for(int i = 1;i < n;i++){
						if(store[i] == rem2){
							ans += count1;
						}if(store[i] == rem){
							count1++;
						}
					}
					System.out.println(ans);
				}
				static class qComparator implements Comparator<Trainer>{
					@Override
					public int compare(Trainer a,Trainer b){
						return b.value.compareTo(a.value);
					}
				}
				static class Trainer implements Comparable<Trainer>{
					Long day;
					Long total;
					Long value;
					public Trainer(long day,long total,long value){
						this.day = day;
						this.total = total;
						this.value = value;
					}
					public int compareTo(Trainer t){
						return this.day.compareTo(t.day);
					}
				}
				public static String add (String num1, String num2, int base) {
	
				        if (base <  2) throw new IllegalArgumentException("The base should at least be 2. Input base is: " + base);
				        if (base > 26) throw new IllegalArgumentException("The base should be less than 26. Input base is: " + base);
				        final StringBuilder stringBuilder = new StringBuilder();
				        int carry = 0;
				        for (int i = num1.length() - 1; i >= 0; i--) {
				            int x =  id6(num1.charAt(i), base) +   id6(num2.charAt(i), base) + carry;
	
				            if (x >= base) { 
				                carry = 1;
				                x = x - base;
				            } else {
				                carry = 0;
				            }
				            stringBuilder.append(id1(x, base));
				        }
	
				        if (carry == 1) stringBuilder.append(1);
	
				        return stringBuilder.reverse().toString();
				   }
				public static int id6(char ch, int base) {
			        if (ch > id1(base - 1, base)) {
			            throw new IllegalArgumentException(" invalid character " + ch + " for input base " + base);
			        }
	
			        if (ch >= '0' &&  ch <= '9') {
			            return ch - '0';
			        } 
			        Character.toUpperCase(ch);
			        return ch - 'A' + 10;
			    }
	
	
			    public static char id1(int x, int base) {
			        if (x >= base) {
			            throw new IllegalArgumentException(" invalid number " + x + " for input base " + base);
			        }
	
			        if (x >= 0 &&  x <= 9) {
			            return (char) (x + '0');
			        } 
	
			        return (char)(x + 'A' - 10);
			    }
		
				public static int[] id7(int[] f)
				{
					int[] to = new int[f.length];
					{
						int[] b = new int[65537];
						for(int i = 0;i < f.length;i++)
							b[1+(f[i]&0xffff)]++;
						for(int i = 1;i <= 65536;i++)
							b[i]+=b[i-1];
						for(int i = 0;i < f.length;i++)
							to[b[f[i]&0xffff]++] = f[i];
						int[] d = f; f = to;to = d;
					}
					{
						int[] b = new int[65537];
						for(int i = 0;i < f.length;i++)
							b[1+(f[i]>>>16)]++;
						for(int i = 1;i <= 65536;i++)
							b[i]+=b[i-1];
						for(int i = 0;i < f.length;i++)
							to[b[f[i]>>>16]++] = f[i];
						int[] d = f; f = to;to = d;
					}
					return f;
				}
				static long goodNum(int l,int r,int p){
					if(p > r){
						return 0;
					}else{
						int mod = l % p;
						if(mod != 0){
							l = l - mod + p;
						}
						int mod2 = r % p;
						r = r - mod2;
						return ((r - l) >= 0 ? (r-l)/p + 1: 0);
					}
				}
				static class Pair implements Comparable<Pair>{
					int x;
			        int y; 
			        Integer cost;
			        Integer duration;
			        public Pair (int x, int y,int cost) {
			            this.x = x;
			            this.y = y;
			            this.cost = cost;
			            this.duration = y - x + 1;
			        }
			        @Override
			        public int compareTo(Pair p) {
			        	

			        	

			            return duration.compareTo(p.duration);
			       }
				}
				static class MyDs{
					ArrayList<Integer> arr;
					HashMap<Integer,LinkedList<Integer>> hmap;
					public MyDs(){
						arr = new ArrayList<Integer>();
						hmap = new HashMap<Integer,LinkedList<Integer>>();
					}
					void add(int x){
						if(!hmap.containsKey(x)){
							hmap.put(x,new LinkedList());
						}
						int s = arr.size();
						arr.add(x);
						hmap.get(x).add(s);
					}
					void remove(int x){
						if(!hmap.containsKey(x)){
							return;
						}
						Integer index = hmap.get(x).get(0);
						hmap.get(x).poll();
						int size = arr.size();
						Integer last = arr.get(arr.size() - 1);
						Collections.swap(arr,index,arr.size() - 1);
						arr.remove(size - 1);
						hmap.get(last).set(hmap.get(last).indexOf(size),index);
					}
					LinkedList<Integer> search(int x){
						return hmap.get(x);
					}
				}
				public static boolean compare(int[] arr,int[] arr2){
					boolean ans = true;
					for(int i = 0;i < 26;i++){
						if(arr[i] < arr2[i]){
							ans = false;
							break;
						}
					}
					return ans;
				}
				int gcd(int a, int b)
				{
				    if (b==0)
				        return a;
				    return gcd(b, a%b);
				}
				 
				 

				static long id4(int arr[], int n)
				{
				    

				    long ans = arr[0];
				 
				    

				    

				    for (int i=1; i<n; i++)
				        ans = ( ((arr[i]*ans)) /
				                (gcd(arr[i], ans)) );
				 
				    return ans;
				}
				public static boolean isPalindrome(String s){
					StringBuilder st = new StringBuilder(s);
					if(st.reverse().toString().equals(s)){
						return true;
					}
					return false;
				}
				public static int digits(int a){
					int count = 0;
					while(a != 0){
						count++;
						a = a/10;
					}
					return count;
				}
				public static long min(long n,long k){
					long ans = 0;
					long calc = n/k;
					long calc2 = n % k;
					long recalc = k - calc2;
					ans += calc * (calc - 1)/2 * recalc;
					ans += (calc + 1) * calc/2 * calc2;
					return ans;
				}
				public static long max(long n,long k){
					long ans = 0;
					long calc = n - k + 1;
					ans += calc * (calc - 1)/2;
					return ans;
				}
				public static boolean isOk(int[] arr,int size){
					if(size % 2 == 0){
						for(int i = 0;i < arr.length;i++){
							if(arr[i] % 2 != 0){
								return false;
							}
						}
						return true;
					}else{
						int count = 0;
						for(int i = 0;i < arr.length;i++){
							if(arr[i] % 2 != 0){
								count++;
							}
						}
						if(count > 1){
							return false;
						}
						return true;
					}
				}
				public static int complement(int index){
					if(index == 0){
						return 1;
					}
					return 0;
				}
				private static long gcd(long a, long b)
				{
				    while (b > 0)
				    {
				        long temp = b;
				        b = a % b; 

				        a = temp;
				    }
				    return a;
				}
				void convertDegree(){
					
				}
				private static long gcd(long[] input)
				{
				    long result = input[0];
				    for(int i = 1; i < input.length; i++) result = gcd(result, input[i]);
				    return result;
				}
				private static long lcm(long a, long b)
				{
				    return a * (b / gcd(a, b));
				}
			
				private static long lcm(long[] input)
				{
				    long result = input[0];
				    for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
				    return result;
				}
				public static boolean[] id0(int n){
					boolean isPrime[] = new boolean[n + 1];
					for (int i = 2; i <= n; i++) {
			            isPrime[i] = true;
			        }
			
			        

			        for (int factor = 2; factor*factor <= n; factor++) {
			
			            

			            

			            if (isPrime[factor]) {
			                for (int j = factor; factor*j <= n; j++) {
			                    isPrime[factor*j] = false;
			                }
			            }
			        }
			        return isPrime;
				}
				public static int binarySearch(int[] arr,int low,int high,int key){
					while(low <= high){
						int mid = (low + high)/2;
						if(arr[mid] == key){
							return mid;
						}else if(arr[mid] < key){
							low = mid + 1;
						}else{
							high = mid - 1;
						}
					}
					return -1;
				}
				public static int id2(int[] arr,int l,int r,int key){
					if(r >= l){
						int mid1 = l + (r-1)/3;
						int mid2 = r - (r-1)/3;
						if(arr[mid1] == key){
							return mid1;
						}else if(arr[mid2] == key){
							return mid2;
						}
						if(key < arr[mid1]){
							return id2(arr,l,mid1-1,key);
						}else if(key > arr[mid2]){
							return id2(arr,mid2 + 1,r,key);
						}else{
							return id2(arr,mid1 + 1,mid2 - 1,key);
						}
					}
					return -1;
				}
				public static double fun(double x){
					return 2 * x * x - 12 * x + 7;
				}
				
				public static double tsModified(double start,double end){
					double l = start;
					double r = end;
					for(int i = 0;i < 200;i++){
						double mid1 = (l * 2 + r)/3;
						double mid2 = (l + 2 * r)/3;
						if(fun(mid1) < fun(mid2)){
							r = mid2;
						}else{
							l = mid1;
						}
					}
					double x = l;
					return fun(x);
				}
				public static String fmt(double d)
				{
				    if(d == (long) d)
				        return String.format("%d",(long)d);
				    else
				        return String.format("%s",d);
				}
				public static String[][] comparator(String[][] arr){
					Arrays.sort(arr, new Comparator<String[]>() {
			            @Override
			            public int compare(String[] a,String[] b) {
			                Integer a1 = Integer.parseInt(a[1]);
			                Integer b1 = Integer.parseInt(b[1]);
			            	return b1.compareTo(a1);
			            }
			        });
					return arr;
				}
				public static StringBuilder[][] id5(StringBuilder[][] arr){
					Arrays.sort(arr, new Comparator<StringBuilder[]>() {
			            @Override
			            public int compare(StringBuilder[] a,StringBuilder[] b) {
			                StringBuilder a1 = a[0];
			                StringBuilder b1 = b[0];
			            	return a1.toString().compareTo(b1.toString());
			            }
			        });
					return arr;
				}
				public static int[][] id5(int[][] arr){
					Arrays.sort(arr, new Comparator<int[]>() {
			            @Override
			            public int compare(int[] a,int[] b) {
			                Integer a1 = a[0];
			                Integer b1 = b[0];
			            	return b1.compareTo(a1);
			            }
			        });
					return arr;
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
			    }
				public static String min(int m,int n){
					int[] arr = new int[m];
					arr[0] = 1;
					int sum = 1;
					int j = m - 1;
					for(int i = 1;i <= 18* m + 10;i++){
						if(sum != n){
							if(arr[j] == 9){
								j--;
							}else{
								arr[j]++;
								sum++;
							}
						}
						else{
							break;
						}
					}
					StringBuilder min = new StringBuilder("");
					for(int i = 0;i < arr.length;i++){
						min.append(arr[i]);
					}
					return min.toString();
				}
				
				public static String max(int m,int n){
					int[] arr = new int[m];
					arr[0] = 1;
					int sum = 1;
					int j = 0;
					for(int i = 1;i <= 9 * m + 10;i++){
						if(sum != n){
							if(arr[j] == 9){
								j++;
							}else{
								arr[j]++;
								sum++;
							}
						}
						else{
							break;
						}
					}
					StringBuilder min = new StringBuilder("");
					for(int i = 0;i < arr.length;i++){
						min.append(arr[i]);
					}
					return min.toString();
				}
			    public static int id8(String txt,String pat){
					int m = pat.length();
					int n = txt.length();
					int lps[] = new int[m];
					int j = 0;
					int count = 0;
					PrefixTable(pat,m,lps);
					int i = 0;
					while (i < n)
				        {
				            if (pat.charAt(j) == txt.charAt(i))
				            {
				                j++;
				                i++;
				            }
				            if (j == m)
				            {
				            	count++;
				                j = lps[j-1];
				            }
				            else if (i < n && pat.charAt(j) != txt.charAt(i))
				            {
				                if (j != 0)
				                    j = lps[j-1];
				                else
				                    i = i+1;
				            }
				        }
					return count;
				}
				public static void PrefixTable(String pat,int m,int[] lps){
					int len = 0;
					int i = 1;
					lps[0] = 0;
					while(i < m){
						if(pat.charAt(i) == pat.charAt(len)){
							lps[i] = len + 1;
							i++;
							len++;
						}else if(len > 0){
							len = lps[len - 1];
						}else{
							lps[i] = 0;
							i++;
						}
					}
				}
			    public int digit(int x){
			    	int temp = x;
			    	int count = 0;
			    	while(temp != 0){
			    		count++;
			    		temp = temp/10;
			    	}
			    	return count;
			    }
			    public int sum(int x){
			    	int temp = x;
			    	int count = 0;
			    	while(temp != 0){
			    		count += temp % 10;
			    		temp = temp/10;
			    	}
			    	return count;
			    }
			    public int product(int x){
			    	int temp = x;
			    	int count = 1;
			    	while(temp != 0){
			    		count*=temp % 10;
			    		temp = temp/10;
			    	}
			    	return count;
			    }
			    public boolean id3(int x){
			    	int temp = x;
			    	while(temp != 0){
			    		if(temp % 10 == 0){
			    			return false;
			    		}
			    		temp = temp/10;
			    	}
			    	return true;
			    }
			    public boolean isValid(int x){
			    	if(!id3(x)){
			    		return false;
			    	}else{
			    		if(product(x) <= sum(x)){
			    			return true;
			    		}
			    		return false; 
			    	}
			    }
			    
			}