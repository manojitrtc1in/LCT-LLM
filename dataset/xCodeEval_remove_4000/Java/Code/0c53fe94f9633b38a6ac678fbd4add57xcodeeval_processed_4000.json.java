

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
	
	
	
	

	void main() {
		
		int n=inp.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) a[i]=inp.nextInt();
		MyStack pos=new MyStack();
		MyStack neg=new MyStack();
		pos.push(n-1, 0, a[n-1]);
		neg.push(n-1, 0, -a[n-1]);
		int dp[]=new int[n];
		dp[n-1]=0;
		for(int i=n-2;i>=0;i--) {
			dp[i]=1+Math.min(pos.id0(i, a[i]), neg.id0(i, -a[i]));
			pos.push(i, dp[i], a[i]);
			neg.push(i, dp[i], -a[i]);
		}
		out.println(dp[0]);
	}
	
	class MyStack {
		Stack<Integer> indexes=new Stack<Integer>(), steps=new Stack<Integer>(), heights=new Stack<Integer>();
		
		int id0(int i, int height) {
			int gg=Integer.MAX_VALUE;
			while(!indexes.isEmpty() && heights.peek() < height) {
				gg=Math.min(gg, steps.peek());
				pop();
			}
			if(!indexes.isEmpty()) {
				gg=Math.min(gg,steps.peek());
				if(heights.peek()==height) pop();
			}
			return gg;
		}
		
		void push(int i, int minSteps, int height) {
			indexes.push(i);
			steps.push(minSteps);
			heights.push(height);
		}
		
		void pop(){
			if(!indexes.isEmpty()) {
				indexes.pop();
				steps.pop();
				heights.pop();
			}
		}
	}
	
	
	
	










































































	
	
	

		
}
