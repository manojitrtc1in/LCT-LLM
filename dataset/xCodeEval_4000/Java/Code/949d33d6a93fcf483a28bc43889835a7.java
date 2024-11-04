

import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.lang.Math.abs;
import static java.lang.System.out;
import java.io.*;
import java.util.*;
import java.math.*;



public class Main {

	

class Node {
	int data;
	Node next;

	Node(int data){
		this.data = data;
		next = null;
	}
}
	
	static int N = 1000007;
	static int M = 1000000007;
	static int X = 998244353;
	
	public static void main(String[] args) throws Exception{
		fileConnect();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      

        StringTokenizer st = new StringTokenizer(br.readLine());
     	int t = Integer.parseInt(st.nextToken());

     	int ab = 0;

     	while(t--> 0){
     		st = new StringTokenizer(br.readLine());
     		int n = Integer.parseInt(st.nextToken());
     		
     		int i = n/2, j=n;
     		if(n%2 == 1){
     			i++;
     		}
     		int temp = i;

     		while(temp < j){
     			System.out.print(i + " " + j + " ");
     			i--; j--;
     		}

     		while(i >= 1) {
     			System.out.print(i + " ");
     			i--;
     		}
     		
     		System.out.println();
     	
     	} 


     		
}



 static int upper_bound(long arr[], long key)
    {
        int mid, N = arr.length;
  
      
        int low = 0;
        int high = N;
  
       
        while (low < high && low != N) {
            

            mid = low + (high - low) / 2;
  
            
            if (key >= arr[mid]) {
                low = mid + 1;
            }
  
            

            

            else {
                high = mid;
            }
        }
  
        
        if (low == N ) {
            

             return N;      
        }
  
          

          

        return low;
    }
  

static boolean check(int n, int[] arr){
	for(int ln = 2; ln <= n; ln *= 2)
	{
		for(int i=0; i<n; i+= ln){
			HashSet<Integer> s = new HashSet<>();
			int min = Integer.MAX_VALUE;
			int max = Integer.MIN_VALUE;

			for(int j=i; j<i+ln; j++)
			{
				s.add(arr[j]%ln);
				min = Math.min(min, arr[j]);
				max = Math.max(max, arr[j]);
			}

			if(s.size() != ln || (max-min != ln-1)) return false;
		}
	}
	return true;
}

	 static long nCr(int n, int r)
    {
        

        
         long[][] dp = new long[n+1][r+1];
        
        for(int i=0; i<r+1; i++){
            dp[0][i] = 0;
        }
        
        for(int i=0; i<n+1; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<n+1; i++){
            for(int j=1; j<r+1; j++){
                if(i >= j){
                    dp[i][j] = ((dp[i-1][j-1]%M)*i)%M;
                    
                }else {
                    dp[i][j] = 0;
                }
            }
        }
        
        

        

        

        

        

        

        
        return (dp[n][r]);
    }

	
     static int lcs(int ind1, int ind2, char[] str1, char[] str2, int[][] dp)
    {
        if(ind1 < 0 || ind2 < 0) return 0;
        
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        
        if(str1[ind1] == str2[ind2]){
            return dp[ind1][ind2] = 1 + lcs(ind1-1, ind2-1, str1, str2, dp);
        }else {
            return dp[ind1][ind2] = Math.max(lcs(ind1-1, ind2, str1, str2, dp), lcs(ind1, ind2-1, str1, str2, dp));
        }
    }


	static boolean isPalindrome(char[] s){

		int i=0;
		int j = s.length -1;
		while(i<=j){
			if(s[i++] != s[j--]) return false;
		}

		return true;
	}

	static long calc(long[] a, int i) {
        return Math.max(0, Math.max(a[i-1], a[i+1])+1 - a[i]);
    }

	static boolean sub(int target, int s){

		if(s >= target){
			if(s == target){
				return true;
			}
			return false;
		}

		s += 2;
		target -= 2;
		if(sub(target, s) == true) return true;

		
		s += 5;
		target += 5;

		if(sub(target, s) == true) return true;

		return false;
	}


	static int compareFourNumber(int a1, int a2, int b1, int b2){

			if(a1 > a2){
     				if(a1 > b1){
     					if(a1 > b2){
     						return 1;
     					}else {
     						return 4;
     					}
     				}else {
     					if(b1 > b2){
     						return 3;
     					}else {
     						return 4;
     					}
     				}
     			}else {
     				if(a2 > b1){
     					if(a2 > b2){
     						return 2;
     					}else {
     						return 4;
     					}
     				}else {
     					if(b1 > b2){
     						return 3;
     					}else {
     						return 4;
     					}
     				}
			}
		}


	








 

 


 

 

 

 

     			
 


 


	


	


	

	

	

	

	

	

	


	static void subsequence(String s, String ans){

		if(s.length() == 0){

			if(!ans.isEmpty()) {
				System.out.println(ans);
			}
			
			return;
		}

		

		subsequence(s.substring(1), ans);
		subsequence(s.substring(1), ans + s.charAt(0));
	}








	static BigInteger factorial(int N)
    {
        

        BigInteger f
            = new BigInteger("1"); 

 
        

        for (int i = 2; i <= N; i++)
            f = f.multiply(BigInteger.valueOf(i));
 
        return f;
    }



	static void rightRotate(int[] arr, int start, int end)	{
		int temp = arr[end];
		for(int i=end; i>start; i--){
			arr[i] = arr[i-1];
		}
		arr[start] = temp;

		
	}




	static int binarySearch(int[] arr, int n, int start, int k){
		
		int l = start;
		int r = n-1;
		int index = -1;
		

		while(l<=r){
			int mid = l + (r-l)/2;
			if(arr[mid] < k){
				l = mid + 1;
			}else if(arr[mid] > k){
				r = mid -1;
			}else return mid;
		}

		return index;

	}

	


	static long mergeSort(long arr[], long l, long r){
        long cnt = 0;
        
        if(r > l){
            long m = l + (r-l)/2;
            cnt += mergeSort(arr, l, m);
            cnt += mergeSort(arr, m+1, r);
            cnt += merge(arr, l, m, r);
        }
        return cnt;
    }
    
    static long merge(long arr[], long l, long m, long r){
        
        long cnt = 0;
        long n1 = m-l+1;
        long n2 = r-m;
        long left[] = new long[(int)n1];
        long right[] = new long[(int)n2];
        
        for(int i=0; i<n1; i++){
            left[i] = arr[i+(int)l];
        }
        for(int i=0; i<n2; i++){
            right[i] = arr[i+(int)m+1];
        }
        
        int i=0, j=0, k=(int)l;
        
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k++] = left[i++];
            }else {
                arr[k++] = right[j++];
                cnt = cnt + (m - i+1-l);
            }
        }
        while(i<n1){
            arr[k++] = left[i++];
        }
        while(j<n2){
            arr[k++] = right[j++];
        }
        
        return cnt;
    }
	
	

	 static void reverse(int[] array)
    {
  
        
        int n = array.length;
  
        
        for (int i = 0; i < n / 2; i++) {
  
   
            int temp = array[i];
  
         
            array[i] = array[n - i - 1];
  
            array[n - i - 1] = temp;
        }
    }

	

	 static int[] readArr(int N, BufferedReader br, StringTokenizer st) throws Exception
    {
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i < N; i++)
            arr[i] = Integer.parseInt(st.nextToken());
        return arr;
    }

     static long[] readArr2(int N, BufferedReader br, StringTokenizer st) throws Exception
    {
        long[] arr = new long[N];
        st = new StringTokenizer(br.readLine());
        for(int i=0; i < N; i++)
            arr[i] = Long.parseLong(st.nextToken());
        return arr;
    }

	

	static void printArr(int[] arr, int n){
		for(int i=0; i<n; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	static void printArr2(long[] arr, int n){
		for(int i=0; i<n; i++){
			System.out.print(arr[i] + " ");
		}
		System.out.println();
	}

	

	static long gcd(long a, long b){
		
		if(b == 0) return a;
	
		return gcd(b, a%b);
	}

	

	public static long lcm(long a, long b){
	
		return (a * b)/gcd(a, b);
	}

	

	 static long binaryExp(long x, long n){


		if(n == 0){
		return 1;
		}
		else if(n%2 == 0){
			return binaryExp(x*x, n/2);
		}else {
			return x * binaryExp(x*x, (n-1)/2);
		}

	}

	

	 static long modExp(long x, long n, long m){
	

		if(n == 0){
		return 1;
		}
		else if(n%2 == 0){
			long temp = (x * x)%m;
			return modExp(temp, n/2, m)%m;
		}else {
			long temp = (x * x)%m;
			return (x * modExp(temp, (n-1)/2, m))%m;
		}

	}

	

	 static boolean isPrime(int n){
		if(n == 0 || n == 1) return false;
		if(n == 2 || n == 3) return true;

		
		for(int i=2; i*i<=n; i++){
			if(n%i == 0){
				return false;
			}
		}

		return true;
	}

	

	 static void seiveOfEroth(){

		int maxN = 1000000;	
		boolean[] prime = new boolean[maxN + 1];
		


		prime[0] = prime[1] = true;
		for(int i=2; i<=maxN; i++){
			if(!prime[i]){
				for(int j=i*i; j<=maxN; j+=i){
					prime[j] = true;
				}
			}
		}
	}

	
	static void primeFactor(int n){
		if(n == 1) System.out.print(n);
		for(int i=2; i*i<=n; i++){
			if(n == 1) return;
			int cnt = 0;
			if(n%i == 0){
				while(n%i == 0){
					cnt++;
					n = n/i;
				}
				if(n != 1)
				System.out.print(i + " ^ " + cnt + " + ");
				else {
					System.out.print(i + " ^ " + cnt);
				}
			}
			
		}
		if(n > 1){
			System.out.print(n + " ^ 1");
		}
	}

	

	 static void primeFactor2(int n){

		if(n == 1) System.out.print(1);

		int[] seive = new int[N+1];
		seive[0] = 0;
		seive[1] = 1;

		

		for(int i=2; i<=N; i++){
			if(seive[i] == 0){
				for(int j=i; j<=N; j+=i){
					if(seive[j] == 0){
						seive[j] = i;
					}
				}
			}
		} 




		while(n != 1){
			if(n/seive[n] != 1)
				System.out.print(seive[n] + "*");
			else 
				System.out.print(seive[n]);
			n = n/seive[n];
		}


	}

	
	static long[][] powerMatix(long[][] matrix, int dim, int n){
		

		long[][] identity = new long[dim][dim];
		for(int i=0; i<dim; i++){
			identity[i][i] = 1;
		}
		


		

		if(n==0) return identity;

		if(n==1) return matrix;

		

		


		

		

		


		

		


		long[][] temp = identity;
		int cnt = 0;

		while(n > 1){
			if(n%2 == 1){
				temp = multimat(matrix, temp, dim);
				n--;
			}else {
				matrix = multimat(matrix, matrix, dim);
				n = n/2;
			}
		}

		matrix = multimat(matrix, temp, dim);

		return matrix;
		
	}

	

	static void printMatrix(long[][] matrix, int dim){
		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){
				System.out.print(matrix[i][j] + " ");
			}
			System.out.println();
		}
	}

	

	

	

	static long[][] multimat(long[][] matrix, long[][] matrix2, int dim){

		long[][] result = new long[dim][dim];

		for(int i=0; i<dim; i++){
			for(int j=0; j<dim; j++){

				for(int k=0; k<dim; k++){

					result[i][j] = (result[i][j] + ((matrix[i][k] % M)* (matrix2[k][j]%M))%M)%M;
				}
			}
		}

		
		return result;
		
	}

	

	 static void fileConnect(){
		try {
			System.setIn(new FileInputStream("input.txt"));
			System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		} catch (Exception e) {

			System.err.println("Error");
		}
	}

	
	
	
}