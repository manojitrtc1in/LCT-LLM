import java.awt.List;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.ref.SoftReference;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Hashtable;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
	
	public static int as;
	
	public static void main(String[] args) throws IOException {
		f796_b();
	  }
	
	public static void f796_b() throws IOException {	


		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		int a = 0;
		int b = 0;
		int res = 0;
	

		int [] holes = new int[n+1];
				
		int bone = 1;
		for(int i=0; i <= n; i++)
			holes[i] = 0;
		
		st = new StringTokenizer(br.readLine());
		for(int i=0; i < m; i++) {
			a = Integer.parseInt(st.nextToken());
			holes[a] = 1;
			if(a == 1) {
				System.out.println(1);
				return ;
			}
		}
		
	

	

	

	

			
		for(int i=0; i < k; i++) {
			st = new StringTokenizer(br.readLine());
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			if(a == bone)
				bone = b;
			else if (b == bone)
				bone = a;
			if(holes[bone] == 1) {
				System.out.println(bone);
				return;
			}
		}
		System.out.println(bone);
}
	
	public static void full() {
		Scanner in = new Scanner(System.in);
		int k = in.nextInt();
		int ans = 0;
		
		switch(k)
	    {
	        case 1:ans = 4;break;
	        case 2:ans = 22;break;
	        case 3:ans = 27;break;
	        case 4:ans = 58;break;
	        case 5:ans = 85;break;
	        case 6:ans = 94;break;
	        case 7:ans = 121;break;
	        case 8:ans = 166;break;
	        case 9:ans = 202;break;
	        case 10:ans = 265;break;
	        case 11:ans = 274;break;
	        case 12:ans = 319;break;
	        case 13:ans = 346;break;
	        case 14:ans = 355;break;
	        case 15:ans = 378;break;
	        case 16:ans = 382;break;
	        case 17:ans = 391;break;
	        case 18:ans = 438;break;
	        case 19:ans = 454;break;
	        case 20:ans = 483;break;
	        case 21:ans = 517;break;
	        case 22:ans = 526;break;
	        case 23:ans = 535;break;
	        case 24:ans = 562;break;
	        case 25:ans = 576;break;
	        case 26:ans = 588;break;
	        case 27:ans = 627;break;
	        case 28:ans = 634;break;
	        case 29:ans = 636;break;
	        case 30:ans = 645;break;
		}
		System.out.println(ans);
	}
	
	public static void f767_a() {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(10, Collections.reverseOrder());
		Hashtable<Integer, Integer> dc = new Hashtable<Integer, Integer>();
		int [] nums = new int[n];
		for(int i=0; i<n; ++i) {
			nums[i] = in.nextInt();
			pq.add(nums[i]);
			dc.put(nums[i], i);
		}
		int cor ;
		int day = 0;
		int cDay = 0; 


		while(!pq.isEmpty()) {
			cor = pq.poll();
			day = dc.get(cor);
			for(int j=cDay; j<day; ++ j)
				System.out.println();
			System.out.print(cor);
			while (!pq.isEmpty()) {
				if(dc.get(pq.peek()) < day)
					System.out.print(" " + pq.poll());
				else break;
			}
			System.out.println();
			cDay = day+1;
		}




		
	}
	
	public static void f774_a(){
		Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int c1 = sc.nextInt();
        int c2 = sc.nextInt();
        String s = sc.next();
        int cnt = 0;
        for (int i = 0; i < n; i++) if (s.charAt(i) == '1') cnt++;
        long ans = (long)1e18;
        for (int i = 1; i <= cnt; i++) {
            int less = n - i;
            int k = less / i;
            int k2 = less % i;
            int k1 = i - k2;
            long tans = k1 * (c1 + (long)c2 * k * k) + k2 * (c1 + (long)c2 * (k + 1) * (k + 1));
            if (tans < ans) ans = tans;
        }
        System.out.println(ans);
	}
	
	public static void f776_a() {
		Scanner in = new Scanner(System.in);
		String a = in.next();
		String b = in.next();
		
		String a2;
		String b2;
		
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			System.out.println(a + " " + b);
			a2 = in.next();
			b2 = in.next();
			if(a.equals(a2))
				a = b2;
			else b = b2;
		}
		System.out.println(a + " " + b);
	}
	
	public static void f777_a() {
		Scanner in = new Scanner(System.in);
		long n = in.nextLong();
		int x = in.nextInt();
		
		n = n%12;
		
		int [] a = {0,1,2};
		int asd = 0;
		for(int i=1; i<=n; i++) {
			if (i%2 == 1) {
				asd = a[0];
				a[0] = a[1];
				a[1] = asd; 
			} else {
				asd = a[1];
				a[1] = a[2];
				a[2] = asd;
			}
		}
		System.out.println(a[x]);
	}
	
	public static void f785_a() {
		Scanner in = new Scanner(System.in);
		
		int n = in.nextInt();
		in.nextLine();
		String ad = "";
		long res=0;
		for ( int i=0; i<n; ++i) {
			ad = in.nextLine();
			if(ad.startsWith("T"))
				res += 4;
			else if(ad.startsWith("C"))
				res += 6;
			else if(ad.startsWith("O"))
				res += 8;
			else if(ad.startsWith("D"))
				res += 12;
			else if(ad.startsWith("I"))
				res += 20;
		}
		System.out.println(res);
	}
	
	public static void someFun(Integer a) {
		a=44;
	}
	public static void f711_a() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    int n = 0;
	    n = sc.nextInt();
	    String [] bus = new String[n];
	    String row = "";
	    boolean res = false;
	    sc.nextLine();
	    for(int i=0; i<n; i++) {
	    	row = sc.nextLine();
	    	if(row.contains("OO") && !res) {
	    		if(row.equals("OO|OO"))
	    			row = row.replaceFirst("OO", "++");
	    		res = true;
	    	}
	    	bus[i] = row;
	    }
	    if(res) {
	    	out.println("YES");
	    	for(int i=0; i<n; i++) 
	    		out.println(bus[i]);
	    }
	    else out.println("NO");
	    out.println();
	    out.close();
	    sc.close();
	}
	
	public static void f746_a() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    int a, b, c;
	    a = sc.nextInt();
	    b = sc.nextInt();
	    c = sc.nextInt();
	    b = b/2;
	    c = c/4;
	    if(b < a)
	    	a = b;
	    if(c < a)
	    	a = c;
	    
	    out.println(a*7);
	    out.close();
	    sc.close();
	}
	
	public static void f747_b() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    int n;
	    n = sc.nextInt();
	    int cA =0, cC = 0, cG =0, cT = 0, cQ=0;
	    String str = sc.next();
	    
	    for(int i=0; i < n; i++) {
	    	char a = str.charAt(i);
	    	if(a == 'A')
	    		cA++;
	    	if(a == 'C')
	    		cC++;
	    	if(a == 'G')
	    		cG++;
	    	if(a == 'T')
	    		cT++;
	    	if(a == '?')
	    		cQ++;
	    }
	    
	    int max = 0;
	    char c = 'A';
	    max = Math.max(Math.max(cA, cC), Math.max(cG, cT));
	    
	    int qalan = - cA - cC - cG - cT + 4 * max;
	    cA = max - cA;
	    cC = max - cC;
	    cG = max - cG;
	    cT = max - cT;
	    StringBuilder strB = new StringBuilder(str);
	    if(qalan == cQ) {
	    	for (int i = 0; i < n; i++) {
				if (strB.charAt(i) == '?') {
					if (cA > 0) {
						strB.setCharAt(i, 'A');
						cA--;
					} else if (cC > 0) {
						strB.setCharAt(i, 'C');
						cC--;
					} else if (cG > 0) {
						strB.setCharAt(i, 'G');
						cG--;
					} else if (cT > 0) {
						strB.setCharAt(i, 'T');
						cT--;
					}
					
				}
			}
	    	out.println(strB);
	    } else {
	    	if((cQ - qalan)%4 == 0 && ((cQ - qalan)) > 0) {
	    		for (int i = 0; i < n; i++) {
					if (strB.charAt(i) == '?') {
						if (cA > 0) {
							strB.setCharAt(i, 'A');
							cA--;
						} else if (cC > 0) {
							strB.setCharAt(i, 'C');
							cC--;
						} else if (cG > 0) {
							strB.setCharAt(i, 'G');
							cG--;
						} else if (cT > 0) {
							strB.setCharAt(i, 'T');
							cT--;
						}
						else { 
							strB.setCharAt(i, c);
							if(c == 'A') c = 'C';
							else if(c == 'C') c = 'G';
							else if(c == 'G') c = 'T';
							else if(c == 'T') c = 'A';
						}
					}
				}
	    		out.println(strB);
	    	} else {
	    		out.println("===");
	    	}
	    }
	    
	    out.close();
	    sc.close();
	}
	
	public static void f710_b() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    int res =0;
	    int n = 0;
	    n = sc.nextInt();
	    ArrayList<Integer> a = new ArrayList<>();
	    
	    for(int i=0; i<n; i++) {
	    	a.add(sc.nextInt());
	    }
	    Collections.sort(a);
	    
















































	    int k=(n-1)/2;
	    out.println(a.get(k));
	    out.close();
	    sc.close();
	}
	
	public static void f705_a() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    int num = sc.nextInt();
	    
	    out.print("I hate");
	    
	    for(int i=1; i < num; i++) {
	    	out.print(" that ");
	    	if(i%2 == 0) 
	    		out.print("I hate");
	    	else 
	    		out.print("I love");
	    	
	    }
	    
	    	out.println(" it");
	    
	    out.close();
	    sc.close();
	}
	
	public static void f680_a() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    
	    int maxMinus =0;
	    
	    int [] arr = new int[5];
	    int um = 0;
	    for(int i=0; i<5; i++) {
	    	int a = sc.nextInt();
	    	um += a;
	    	arr[i] = a;
	    	int c = 1;
	    	for(int j=0; j < i; j++) {
	    		if(arr[j] == a) {
	    			c++;
	    		}
	    	}
	    	
	    	if((c==2 || c == 3) && maxMinus < c*a)
	    		maxMinus = c*a;
	    	
	    }
	    out.println((um - maxMinus) + "");
	    out.close();
	    sc.close();
	}
	
	public static void f681_a() {
		Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    boolean res = false;
	    long num = sc.nextInt();
	    
	    for(long h=0; ; h++) {
	    	if(res || (h*1234567 > num))
	    		break;
	    	for(long car=0; ; car++) {
	    		if(res || ((car*123456 + h*1234567) > num) )
	    			break;
	    		long de = num - (car*123456 + h*1234567);
	    		if((de % 1234) == 0) {
	    			res = true;
    				out.println("YES");
	    		}






















	    	}
	    }
	    
	    if(!res)
	    	out.println("NO");
	    
	    out.close();
	    sc.close();
	}
	
	public static void test(){
		int a = Integer.valueOf("b0", 18);
		System.out.println(a);
	}
	
	public static void problem_333_a(){

	    Scanner sc = new Scanner(System.in);
	    PrintWriter out = new PrintWriter(System.out);
	    

	    
	    



	    int n, bx;
	    int m, by;
	    
	    
	    
	    n = sc.nextInt(); bx = sc.nextInt();
	    BigInteger nler = new BigInteger("0");
	    
	    BigInteger [] nn = new BigInteger[n]; 
	    
	    int temp=0;
	    for(int i=0; i<n; i++) {












	    	nn[i] = sc.nextBigInteger();
	    }
	    
	    m = sc.nextInt(); by = sc.nextInt();
	    BigInteger mler = new BigInteger("0");
	    BigInteger [] mm = new BigInteger[m]; 
	    for(int i=0; i<m; i++) {










	    	mm[i] = sc.nextBigInteger();
	    }
	    boolean equalFlag = false;
	    BigInteger nSelf = new BigInteger("0");
	    BigInteger nRadix = new BigInteger("1");
	    
	    BigInteger mSelf = new BigInteger("0");
	    BigInteger mRadix = new BigInteger("1");
	    
	    if(n>m && bx>by) {
	    	System.out.println(">");
	    	equalFlag = true;
	    } else if(n<m && bx<by) {
	    	System.out.println("<");
	    	equalFlag = true;
	    } else if(n==m && bx==by) {
	    	for(int i=0; i<n; i++){
	    		if(nn[i].equals(mm[i]))
	    			equalFlag = true;
	    		else {equalFlag = false; break;}
	    	}
	    	if(equalFlag) {
	    		System.out.println("<");
	    		
	    	}
	    }
	    if(!equalFlag) {
	    	for(int i=0; i<n; i++) {
    			nSelf = nSelf.add(nRadix.multiply(new BigInteger(nn[n-1-i] + "")));
    			nRadix = nRadix.multiply(new BigInteger(bx+""));
    		}
    		
    		for(int i=0; i<m; i++) {
    			mSelf = mSelf.add(mRadix.multiply(new BigInteger(mm[m-1-i] + "")));
    			mRadix = mRadix.multiply(new BigInteger(by+""));
    		}
    		int res = nSelf.compareTo(mSelf);
    		if( res < 0) 
    			System.out.println("<");
    		else if(res == 0) {
    			System.out.println("=");
    		}
    		else System.out.println(">");
	    }
	    

	    




	







	    
	    out.println();
	    
	    out.close();
	    sc.close();
	    
		
	}
 
  
}