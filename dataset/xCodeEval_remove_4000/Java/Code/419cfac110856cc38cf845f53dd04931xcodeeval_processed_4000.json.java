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
		int arr[]=new int[n+1];
		
		for(int i=1;i<=n;i++) {
			arr[i]=sc.nextInt();
		}
		
		int count=0;
		for(int i=1;i<=2*n;i++) {
			

			boolean isSorted=true;
			for(int j=1;j<=n;j++) {
				if(arr[j]!=j) {
					isSorted=false;
				}
			}
			
			if(isSorted) {
				break;
			}
			
			if(i%2==1) {
				for(int j=1;j<=n-2;j+=2) {
					if(arr[j]>arr[j+1]) {
						arr[j]=(arr[j]+arr[j+1])-(arr[j+1]=arr[j]);
						

					}
				}
			}else {
				for(int j=2;j<=n-1;j+=2) {
					if(arr[j]>arr[j+1]) {
						arr[j]=(arr[j]+arr[j+1])-(arr[j+1]=arr[j]);
						

					}
				}
			}
			
			count++;
			
		}
		System.out.println(count);
		
		
		



		
	}



	private static int id0(int i, int j) {
		if(i%j==0) {
			return j;
		}

		return id0(j, i%j );
	}

	private static void fill(int[][] arr) {



		
	}



}
