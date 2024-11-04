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
		String s=sc.next();

		char arr[]=s.toCharArray();

		int i=0;
		for(;i<n;i++) {
			if(arr[i]!='?') {
				break;
			}
		}
		if(i==n) {
			for(i=0;i<n;i++) {
				if(i%2==0) {
					arr[i]='B';
				}else {
					arr[i]='R';
				}
			}
			System.out.println(String.valueOf(arr));
			return;
		}
		for(int j=i-1;j>=0;j--) {
			if(arr[j+1]=='B') {
				arr[j]='R';
			}else {
				arr[j]='B';
			}
		}
		for(i=i+1;i<n;i++) {
			if(arr[i]=='?') {
				if(arr[i-1]=='B' ) {
					arr[i]='R';
				}else {
					arr[i]='B';
				}
			}
		}
		System.out.println(String.valueOf(arr));


		



		
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
