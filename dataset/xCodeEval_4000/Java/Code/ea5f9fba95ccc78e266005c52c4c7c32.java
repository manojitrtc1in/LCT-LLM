import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Map;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;

public class Codeforces {


	static Scanner sc=new Scanner(System.in);

	public static void main(String[] args) throws IOException {
		int t=1;
		t=sc.nextInt();

		while(t-->0) {
			solve();

		}

	}



	private static void solve() throws IOException {

		int n=sc.nextInt();
		
		int countZero=0;
		
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();
			if(arr[i]==0) {
				countZero++;
			}
		}
		if(countZero==n || arr[n-1]==0 ) {
			for(int i=0;i<=n;i++) {
				System.out.print(i+1+" ");
			}
			System.out.println();
			return ;
		}
		if(countZero==0 ||arr[0]==1 ) {
			System.out.print(n+1+" ");
			for(int i=1;i<=n;i++) {
				System.out.print(i+" ");
			}
			System.out.println();
			return;
		}
		
		int count=0;
		for(int i=0;i<n;i++) {
			if(count==0 && i+1<n && arr[i]==0 && arr[i+1]==1) {
				System.out.print((i+1) + " "+ (n+1)+" " );
				count++;
			}else {
				System.out.print(i+1+" ");
			}
		}
		System.out.println();
		



		
	}



	private static int __gcd(int i, int j) {
		if(i%j==0) {
			return j;
		}

		return __gcd(j, i%j );
	}

	private static void fill(int[][] arr) {



		
	}



}
