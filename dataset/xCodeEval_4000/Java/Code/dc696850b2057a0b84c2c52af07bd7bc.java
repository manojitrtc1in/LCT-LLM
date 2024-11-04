

import java.util.*;
import java.io.*;
import java.lang.reflect.Array;
public class Main {

	static FastReader inp= new FastReader();
	static PrintWriter out= new PrintWriter(System.out);
	public static void main(String args[]) {		    	
	   	
		Main g=new Main();
		g.main();
		out.close();
		
	}
	
	
	
	void main() {
		
		int n=inp.nextInt();
		int q=inp.nextInt();
		Trash trash =new Trash();
		for(int i=0;i<n;i++) {
			trash.work(1,inp.nextInt());
		}
		out.println(trash.gg());
		while(q-->0) {
			int type=inp.nextInt();
			int x=inp.nextInt();
			trash.work(type,x);
			out.println(trash.gg());
		}
		
	}
	
	class Trash {
		TreeSet<Integer> set=new TreeSet<>();
		TreeMap<Integer,Integer> diff=new TreeMap<>();
		public void work(int type, int x) {
			if(type==1) add(x);
			else remove(x);
		}
		void remove(int x) {
			set.remove(x);
			if(set.size()==0) return;
			Integer next =set.ceiling(x);
			Integer prev =set.floor(x);
			if(next==null) {
				removeDiff(x-prev);
			}else if (prev==null) {
				removeDiff(next-x);
			}else {
				addDiff(next-prev);
				removeDiff(x-prev);
				removeDiff(next-x);
			}
		}
		void add(int x) {
			if(set.size()==0) set.add(x);
			else {
				Integer next=set.ceiling(x);
				Integer prev=set.floor(x);
				if(next==null) {
					addDiff(x-prev);
				}else if(prev==null) {
					addDiff(next-x);
				}else {
					removeDiff(next-prev);
					addDiff(x-prev);
					addDiff(next-x);
				}
				set.add(x);
			}
		}
		void addDiff(int d) {
			diff.put(d, diff.getOrDefault(d,0)+1);
		}
		void removeDiff(int d) {
			int x=diff.get(d);
			if(x==1) diff.remove(d);
			else diff.put(d, x-1);
		}
		int gg() {
			if(diff.isEmpty()) return 0;
			return set.last()-set.first()-diff.lastKey();
		}
	}
	
	static class FastReader { 
        BufferedReader br; 
        StringTokenizer st;
        public FastReader() { 
            br = new BufferedReader(new InputStreamReader(System.in)); 
        } 
        String next() { 
            while (st==null || !st.hasMoreElements()) { 
                try { 
                    st = new StringTokenizer(br.readLine()); 
                } 
                catch (IOException  e) { 
                    e.printStackTrace(); 
                } 
            } 
            return st.nextToken(); 
        } 
        int nextInt() { 
            return Integer.parseInt(next()); 
        } 
        long nextLong() { 
            return Long.parseLong(next()); 
        } 
        double nextDouble() { 
            return Double.parseDouble(next()); 
        } 
        String nextLine() { 
            String s=""; 
            try { 
                s=br.readLine(); 
            } 
            catch (IOException e) { 
                e.printStackTrace(); 
            } 
            return s; 
        } 
    } 
	
	
	

		
}
