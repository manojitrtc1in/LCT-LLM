
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.Collections;


public class algorithms{

    public static void main(String[] args) throws IOException {
    	MyScanner in = new MyScanner();
    	id2 task = new id2();
    	task.slove(in);
    }
    
    public static class id2 {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int t = in.nextInt();
    		int arr [] = new int [n-1];
    		String answer = "NO";
    		for (int i = 0; i < n-1;i++) {
    			arr[i] = in.nextInt();
    		}
    		int index = 1;
    		while (index <= n-1){
    			if (index == t) {
    				answer = "YES";
    				break;
    			}
    			index = arr[index-1] + index;
    		}
    		if (index == t) {
				answer = "YES";
			}
    		System.out.println(answer);
    	}
    	
    }
    
    public static class id8 {
    	public int arr [];
    	public int mat [][];
    	public int n;
    	public void slove(MyScanner in) {
    		n = in.nextInt();
    		arr = new int [n];
    		mat = new int [n][n];
    		for (int i = 0; i < n;i++) {
    			arr[i] = in.nextInt();
    		}
    		for (int i = 0; i < n;i++) {
    			String t = in.nextLine();
    			for (int j = 0; j < n; j++) {
    				if (t.charAt(j) == '0') {
    					mat[i][j] = 0;
    				} else {
    					mat[i][j] = 1;
    				}
    			}
    		}
    		mutable(0,0,n,n);
    		for (int i = 0; i < n;i++) {
    			System.out.print(arr[i] + " ");
    		}
    	}
    	public void mutable(int i_, int j_, int ni, int nj) {
    		for (int i = i_; i < ni;i++) {
    			for (int j = i+1; j < nj; j++) {






    				if (mat[i][j] == 1 && arr[j] < arr[i]) {
	    				int tmp = arr[i];
	    				arr[i] = arr[j];
	    				arr[j] = tmp;
	    				for (int k = 0; k < i; k++) {
	    					if (mat[i][k] == 1) {
	    						mutable(k, 0, k+1, n);
	    					}
	    				}
    				}
    			}

    		}
    	}
    	
    }
    






































    
    public static class id7 {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int x = in.nextInt();
    		int l, r, count = 0, current = 1, b2;
    		for (int i = 0; i < n;i++) {
    			l = in.nextInt();
    			r = in.nextInt();
    			b2 = (l - current)/x;
    			if (b2 >= 1) {
    				current += x*b2; 
    			}
    			count += r - current + 1;
    			current = r+1;
    		}
    		System.out.println(count);
    	}
    	
    }
    
    public static class id6 {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int m = in.nextInt();
    		Map<String, String> map = new HashMap<String, String>();
    		String s, answer = "";
    		for (int i = 0; i < m;i++) {
    			s = in.nextLine();
    			String arr [] = s.split(" ");
    			if (arr[1].length() < arr[0].length()) {
    				map.put(arr[0], arr[1]);
    			} else {
    				map.put(arr[0], arr[0]);
    			}
    		}
    		s = in.nextLine();
    		for (String retval: s.split(" ")){
    			answer += map.get(retval) + " ";
    		}
    		System.out.println(answer);
    	}
    	
    }
    
    public static class id9 {
    	public void slove(MyScanner in) {
    		long x = in.nextInt();
    		long y = in.nextInt();
    		Point pa = new Point(x, y);
    		x = in.nextInt();
     		y = in.nextInt();
    		Point pb = new Point(x, y);
    		int count = 0;
    		int n = in.nextInt();
    		long a, b, c;
    		for (int i = 0; i < n;i++) {
        		a = in.nextInt();
         		b = in.nextInt();
         		c = in.nextInt();
         		if (pa.id1(pb, a, b, c) == false) {
         			count++;
         		}
    		}
    		System.out.println(count);
    	}
    	
    }
    
    public static class Point {
    		   
    	public long x;
    	public long y;
    	
    	public Point(long x, long y) {
    		this.x = x;
    		this.y = y;
    	}
    	
    	public boolean id1(Point p, long a, long b, long c) {
    		long d2 = a*p.x + b*p.y + c;
    		long d1 = a*this.x + b*this.y + c;
    		if ((d2 > 0 && d1 < 0) || (d1 > 0 && d2 < 0)) {
    			return false;
    		}
    		return true;
    	}
    }
    
    public static class TaskA {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int prev = 0, prevprev = 0, diff, answer;
    		int min = 1000, max = 0;
    		int imin = 1;
    		int arr [] = new int [n];
    		for (int i = 0; i < n;i++) {
    			arr[i] = in.nextInt();
    			if (i != 0) {
    				if (i > 1) {
		    			diff = arr[i] - prevprev;
		    			if (diff < min) {
		    				min = diff;
		    				imin = i;
		    			}
    				}
	    			if ((arr[i] - prev) > max) {
	    				max = arr[i] - prev;
	    			}
    			}
    			prevprev = prev;
    			prev = arr[i];
    		}
    		diff = arr[imin] - arr[imin-2];
    		if (diff > max) {
    			answer = diff;
    		} else {
    			answer = max;
    		}
    		
    		System.out.println(answer);
    	}
    	
    }
    
    public static class TaskB {
    	public int arr [];
    	public int n;
    	public void slove(MyScanner in) {
    		n = in.nextInt();
    		arr = new int [n];
    		int count[] = new int [10];
    		String s = in.nextLine();
    		String min = s, num;
    		for (int i = 0; i < n;i++) {
    			arr[i] = Character.getNumericValue(s.charAt(i));
    			count[arr[i]] += 1;
    		}
    		for (int i = 0; i < 10;i++) {
    			if (count[i] == 0) {
    				continue;
    			}
    			num = id3(10 - i);
    			for (int j = 0; j < num.length();j++) {
	    			if (num.charAt(j) < min.charAt(j)) {
	    				min = num;
	    			}
	    			if (num.charAt(j) != min.charAt(j)) {
	    				break;
	    			}
    			}
    			
    		}
    		String answer = "";
    		answer += min;
    		System.out.println(answer);
    	}
    	
    	public String id3(int offset) {
    		StringBuffer tmp = new StringBuffer();
    		long newvalue;
    		ArrayList<Integer> al = new ArrayList<Integer>();
			for (int i = 0; i < n;i++) {
				newvalue = arr[i] + offset;
				if (newvalue >= 10) {
					newvalue -= 10;
					if (newvalue == 0) {
						al.add(i);
					}
				}
				tmp.append((int)newvalue);
    		}
			String str = tmp.toString();
			String newstr;
			String min = String.format("%0" + n + "d", 0).replace("0","9");
			for(int i = 0; i < al.size(); i++) {
				newstr = str.substring(al.get(i)) + str.substring(0, al.get(i));
	    		for (int j = 0; j < newstr.length();j++) {
	    			if (newstr.charAt(j) < min.charAt(j)) {
	    				min = newstr;
	    			}
	    			if (newstr.charAt(j) != min.charAt(j)) {
	    				break;
	    			}
	    		}
			}
    		return min;
    	}
    	
    }
    
    public static class TaskC {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int m = in.nextInt();
    		String arr [] = new String [n];
    		char prev = ' ';
    		int count = 0;
    		for (int i = 0; i < n;i++) {
    			arr[i] = in.nextLine();
    		}
    		char c;
    		ArrayList<Integer> ignore = new ArrayList<Integer>();
    		ArrayList<Integer> id5 = new ArrayList<Integer>();
    		for (int i = 0; i < m;i++) {
    			prev = ' ';
    			for (int j = 0; j < n;j++) {
    				c = arr[j].charAt(i);
        			if (ignore.contains(j)) {
        				prev = c;
        				continue;
        			}
    				if (c > prev && prev != ' ') {
    					if (id5.contains(j) == false) {
    						id5.add(j);
    					}
    				}
    				if (c < prev) {
    					count++;
    					id5.clear();
    					break;
    				}
    				prev = c;
    			}
    			ignore.addAll(id5);
    			id5.clear();
    		}
    		System.out.println(count);
    	}
    	
    }
    
    
    public static class TaskD {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		int s = 0, t = 0;
    		int count1 = 0, count2 = 0;
    		int max = 0;
    		int arr[] = new int [n];
    		for (int i = 0; i < n; i++) {
    			arr[i] = in.nextInt();
    			if (arr[i] == 1) {
    				count1++;
    			} else {
    				count2++;
    			}
    		}
    		if (count1 != count2) {
    			if (count1 > count2) {
    				max = count1;
    			} else {
    				max = count2;
    			}
    			int x = 1, y = max;
    			while (max/x >= 1) {
    				if (max%x == 0) {
    					y = max/x;
    					System.out.println(x + " " + y);
    				}
    				x++;
    			}
    		}

    		System.out.println(s + " " + t);
    	}
    	
    }
    
    public static class Pair implements Comparable<Pair> {
	  public final Comparator<Pair> id4 = new Comparator<Pair>() {
		   

		       public int compare(Pair p1, Pair p2) {
		    	   return p1.compareTo(p2);
		       }
		};
    		   
    	private long min;
    	public long max;
    	private long count;
    	private int num;
    	
    	public Pair(long min, long max, long count, int num) {
    		this.min = min;
    		this.max = max;
    		this.count = count;
    		this.num = num;
    	}
    	
    	public void decrease() {
    		count--;
    	}
    	
    	public long count() {
    		return count;
    	}
    	
    	public int num() {
    		return num;
    	}
    	
		public int compareTo(Pair that) {
	       if ((this.min == that.min) && (this.max == that.max)) {
	           return 0;
	       }
	       if ((this.min < that.min) || (this.min == that.min && this.max < that.max)) {
	           return -1;
	       } 
	       return 1;
		}
		
		public int contain(Pair that) {








		       if ((this.min <= that.min) && (this.max >= that.max)) {
		           return 1;
		       }
		       if (this.min <= that.min) {
		    	   return 0;
		       }
		       return -1;
			}
    }
    
    public static class TaskE {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		Pair parties[] = new Pair [n];
    		int p_a[] = new int [n];
    		long min, max;
    		long count;
    		for (int i = 0; i< n;i++) {
    			min = in.nextLong();
    			max = in.nextLong();
    			parties[i] = new Pair(min, max, 0, i+1);
    		}
    		Arrays.sort(parties);






    		int m = in.nextInt();
    		Pair actors[] = new Pair [m];
    		for (int i = 0; i< m;i++) {
    			min = in.nextLong();
    			max = in.nextLong();
    			count = in.nextLong();
    			actors[i] = new Pair(min, max, count, i+1);
    		}
    		Arrays.sort(actors);






    		int j = 0;
    		Pair partie;
    		String answer = "YES\n";
    		for (int i = 0; i< n;i++) {
    			partie = parties[i];




    			if (actors[j].count() <= 0) {
    				if (j == (m)) {
    					answer = "NO";
    					break;
    				}
    				j++;


    			}




    			int index_actor = -1;
    			long min_max = 10000000000L;
    			for(int k = j; k< m; k++) {
    				if (actors[k].count() <= 0) {
    					continue;
    				}
	    			int contain = actors[k].contain(partie);
	    			if (contain == 1) {


	    				if (actors[k].max < min_max){
	    					index_actor = k;
	    					min_max = actors[k].max;
	    				}
	    				












	    			} else if (contain == -1){


						break;
	    			}
    			}
    			if (index_actor == -1) {
    				answer = "NO";
    				break;
    			}


    			actors[index_actor].decrease();
    			p_a[partie.num()-1] = actors[index_actor].num();
    			
    		}
    		if (answer != "NO") {
    			for (int i = 0; i< n;i++) {
    				if (p_a[i] == 0) {
    					answer = "NO";
    					break;
    				}
    				answer += p_a[i] + " ";
    			}
    		}
    		System.out.println(answer);
    	}
    	
    }
    
    public static class id0 {
    	public void slove(MyScanner in) {
    		int n = in.nextInt();
    		Boolean ok = true;
    		int arr [][] = new int [n][n];
    		int minj [] = new int [n];
    		int min = 1000000000;
    		int min_j = 0;
    		for (int i =0; i< n;i++) {
    			min = 1000000001;
    			min_j = 0;
    			for (int j=0; j< n; j++) {
    				arr[i][j] = in.nextInt();
    				if (arr[i][j] < min && (i != j)) {
    					min = arr[i][j];
    					min_j = j;
    				}
    				if ((i == j) && (arr[i][j] != 0)) {
    					ok = false;
    				}
    				if ((i > j) && (arr[i][j] != arr[j][i])) {
    					ok = false;
    				}
    				if ((i != j) && (arr[i][j] == 0)) {
    					ok = false;
    				}
    			}
    			minj[i] = min_j;
    			for (int j =0; j< i;j++) {
    				if ((j == min_j) && (minj[j] == i))
    				{
    					
    				}
    			}
    		}
    		if (!ok) {
    			System.out.println("NO");
    			return;
    		}
    		int j;
    		for (int i =0; i< n;i++) {
    			min_j = minj[i];


    			for (j =0; j< i;j++) {
					if ((j == min_j) && (minj[j] == i))
					{
						
					}
    				if (minj[j] == min_j) {






    					if (arr[i][j] != (arr[j][minj[j]] + arr[i][min_j])) {
    						System.out.println("NO");
    		    			return;
    					}
    				}
    			}
    			
    		}
    		
    		System.out.println("YES");
    	}
    	
    }
    
    
    public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
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
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}

}