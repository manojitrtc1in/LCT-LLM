

import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
public class Main {

	static long mod = 1000000007;
	static long mod2 = 998244353;
	static Scanner inp= new Scanner(System.in);
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
		Main g=new Main();
		g.main();
		out.close();
		
	}
	
	
	
	void main() {
		
		int tt=inp.nextInt();
		while(tt-->0) {
			int n=inp.nextInt();
			int a[]=new int[n];
			for(int i=0;i<n;i++) a[i]=inp.nextInt();
			HashMap<Integer,Integer> map=new HashMap<>();
			HashMap<Integer,Integer> dist=new HashMap<>();
			HashMap<Integer,Integer> r=new HashMap<>();
			for(int i=0;i<n;i++) {
				int num=a[i];
				if(!map.containsKey(num)) {
					dist.put(num,Math.max(dist.getOrDefault(num,0),i+1));
				}else {
					dist.put(num,Math.max(dist.getOrDefault(num,0),i-map.get(num)));
				}
				map.put(num,i);
			}
			for(int num: map.keySet()) {
				

				dist.put(num, Math.max(dist.getOrDefault(num,0),n-map.get(num)));
				

			}
			for(int x: dist.keySet()) {
				

				

				int num=dist.get(x);
				

				if(!r.containsKey(num)) {
					r.put(num, x);
					

				}else if(r.get(num)>x) {
					r.put(num, x);
					

				}
			}
			int min=Integer.MAX_VALUE;
			int gg[]=new int[n];
			Arrays.fill(gg, Integer.MAX_VALUE);
			for(int i=0;i<n;i++) {
				int num=i+1;
				if(!r.containsKey(num) || r.get(num)==0) {
					if(min!=Integer.MAX_VALUE) {
						gg[i]=min;
					}else {
						gg[i]=-1;
					}
				}else {
					gg[i]=r.get(num);
					min=Math.min(min,r.get(num));
					gg[i]=Math.min(min, gg[i]);
				}
			}
			for(int i=0;i<n;i++) out.print(gg[i]+" ");
			out.println();
		}
		
	}
	
	
	
	
	
	

		
}
