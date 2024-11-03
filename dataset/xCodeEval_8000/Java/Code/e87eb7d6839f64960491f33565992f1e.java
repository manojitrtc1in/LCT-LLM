

import java.util.*;
import java.io.*;
public class Main {

	static Scanner inp= new Scanner(System.in);
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	Main g=new Main();
	   	g.main();
	   	out.close();
	}
	
	int dp[];
	
	

	void main() {
		
		int n=inp.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) a[i]=inp.nextInt();
		MyStack pos=new MyStack();
		MyStack neg=new MyStack();
		pos.push(0, a[0]);
		neg.push(0, -a[0]);
		dp=new int[n];
		dp[0]=0;
		for(int i=1;i<n;i++) {
			dp[i]=1+Math.min(pos.minReachableValue(i, a[i]), neg.minReachableValue(i, -a[i]));
			pos.push(i, a[i]);
			neg.push(i, -a[i]);
		}
		out.println(dp[n-1]);
	}
	
	class MyStack {
		Stack<Integer> indexes=new Stack<Integer>(), heights=new Stack<Integer>();
		
		int minReachableValue(int i, int height) {
			int gg=Integer.MAX_VALUE;
			while(!indexes.isEmpty() && heights.peek() < height) {
				gg=Math.min(gg, dp[indexes.peek()]);
				pop();
			}
			if(!indexes.isEmpty()) {
				gg=Math.min(gg,dp[indexes.peek()]);
				if(heights.peek()==height) pop();
			}
			return gg;
		}
		
		void push(int i, int height) {
			indexes.push(i);
			heights.push(height);
		}
		
		void pop(){
			if(!indexes.isEmpty()) {
				indexes.pop();
				heights.pop();
			}
		}
	}
	
	
	
	










































































	
	
	

		
}
