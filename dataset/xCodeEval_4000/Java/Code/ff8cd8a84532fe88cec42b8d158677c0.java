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
		int arr[]=new int[n];
		for(int i=0;i<n;i++) {
			arr[i]=sc.nextInt();
		}
		
		int min=arr[0];
		for(int i=1;i<n;i++) {
			min=min&arr[i];
		}
		System.out.println(min);
		
		



		
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
