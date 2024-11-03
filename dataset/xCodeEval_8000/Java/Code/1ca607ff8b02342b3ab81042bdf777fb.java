
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;
import java.util.StringTokenizer;
public class BoilerPlateNew {

	
	public static void operation1(int arr[], int n) {
		for(int i = 0;i<2*n-1;i+=2) {
			int temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
		}
	}
	public static void operation2(int arr[], int n) {
		for(int i = 0;i<n;i++) {
			int temp = arr[i];
			arr[i] = arr[n+i];
			arr[n+i] = temp;
		}
	}
	public static boolean isSorted(int arr[], int n) {
		for(int i = 0;i<2*n-1;i++) {
			if(arr[i] > arr[i+1]) {
				return false;
			}
		}
		return true;
	}
	public static void main(String[] args) {
		FastScanner sc = new FastScanner();
		int n = sc.nextInt();
		int arr[] = sc.readArray(2*n);
		int operation = 0;
		if(isSorted(arr, n)) {
			System.out.println(0);
			return;
		}
		while(true) {
			if(operation > 10000) {
				System.out.println(-1);
				return;
			}


			if(arr[0] > arr[n]) {
				operation2(arr, n);
				operation++;
				if(isSorted(arr, n)) {
					System.out.println(operation);
					return;
				}
			} else {
				operation1(arr, n);
				operation++;
				if(isSorted(arr, n)) {
					System.out.println(operation);
					return;
				}
			}
		}






















		
		
		
	}
	static long gcd(long a, long b) {
		if (b==0) return a;
		return gcd(b, a%b);
	}
 
	static void ruffleSort(long[] a) {
		int n=a.length;
		Random r=new Random();
		for (int i=0; i<a.length; i++) {
			int oi=r.nextInt(n); long temp=a[i];
			a[i]=a[oi];
			a[oi]=temp;
		}
		Arrays.sort(a);
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		
		int[] readArray(int n) {
			int[] a=new int[n]; 
			for (int i=0; i<n; i++) a[i]=nextInt();
			return a;
		}
		
		int nextInt () {
			return Integer.parseInt(next());
		}
	}
	
}
