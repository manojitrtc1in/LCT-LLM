import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Hashtable;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class testMemory {
	static boolean f=false;
	static Scanner sc =new Scanner(System.in);
	public static boolean check(int x,int y) {
		    if(y==(x+1)||y==(x-1))
		        return true;
		    else
		        return false;
	}
	
	public static void run() {
		int k=sc.nextInt();
		int key[]=new int[k];
		for(int i=0;i<k;i++)
			key[i]=sc.nextInt();
		

		int l=sc.nextInt();
		int lock[]=new int[l];
		for(int i=0;i<l;i++)
			lock[i]=sc.nextInt();
		


	

		for(int i=0;i<k;i++) {
           for(int j=0;j<l;j++) {
        	   if(check(key[i],lock[j]))
        		   System.out.println(key[i]);
        	   return;
           }
		}
	}
	
	public static void EhabTheXorcist() {
		long u=sc.nextLong();
		long v=sc.nextLong();
		if(v<u) {
			System.out.println(-1);
			return;
		}
		if(u==0&&v==0) {
			System.out.println(0);
			return;
		}
			
		if(u==v) {
			System.out.println(1);
			System.out.println(u);
			return;
		}
		if((u&1)!=0&&(v&1)==0) {
			System.out.println(-1);
			return;
		}
		if((u&1)==0&&(v&1)!=0) {
			System.out.println(-1);
			return;
		}
		long x=(v>>1)-(u>>1);
		if(u==0) {
			System.out.println(2);
			System.out.println(x+" "+x);
			return;
		}
		long l=u;
		long r=v;
		while(l < r) {
			

			long m = (l>>1)+(r>>1);
			long t=m^u;
			long s=t+m;
			

			if(s==v) {
				System.out.println(2);
				System.out.println(m+" "+t);
				return;
			}
			else if(s>v) {
				r=m-1;
			}
			else {
				l=m+1;
			}
		}
		if(l==r) {
			if((l^r)==u&&l+r==v) {
				System.out.println(2);
				System.out.println(l+" "+r);
				return;
			}
		}
		System.out.println(3);
		System.out.println(u+" "+x+" "+x);
		
		
		
		
		
	}
	public static String input() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {
			return br.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	public static int inputInt() {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int x=0;
		try {
			st = new StringTokenizer(br.readLine());
			 x= Integer.parseInt(st.nextToken());
		} catch (IOException e) {
			

			e.printStackTrace();
		}
		
		return x;
	}
	public static void Hotelier() {
		 int n=Integer.parseInt(sc.nextLine());
		 StringBuilder s = new StringBuilder();
		 s.append(input());
		 

		 int []mask=new int[10];
		 for(int i=0;i<s.length();i++) {
			 
			 if(s.charAt(i)=='R') {
				 

				 for(int j=mask.length-1;j>=0;j--) {
					 if(mask[j]==0) {
						 mask[j]=1;
						 break;
					 }
				 }

			 }
			 

			 

			 else if(s.charAt(i)=='L') {
				 

				 for(int j=0;j<mask.length;j++) {
					 if(mask[j]==0) {
						 mask[j]=1;
						 break;
					 }
				 }
			 }
			 else {
				 System.out.println((char)s.charAt(i)+" "+i);
				 

				
			 }
			 

			 
		 }
		 for(int i=0;i<10;i++) {
			 System.out.print(mask[i]);
		 }
		 System.out.println();
	}
	public static void  GameWithString() {
		String s=input();
		Stack <Character>s1=new Stack<Character>();
		Stack <Character>s2=new Stack<Character>();
		for(int i=0;i<s.length();i++) {
			s1.push(s.charAt(i));
		}
		boolean f=true;
		while(!s1.isEmpty()) {
			if(!s2.isEmpty()) {
				if(s1.peek()==s2.peek()) {
					s1.pop();
					s2.pop();
					f=!f;
					continue;
				}
			}
		

				s2.push(s1.pop());

			
		}
		if(f)
			System.out.println("NO");
		else
			System.out.println("YES");


	}
	public static void SerejaAndSuffixes() {
		int n=sc.nextInt();
		int m=sc.nextInt();

		int a[]=new int[n];
		int max=0;
		for(int i=0;i<a.length;i++) {
			a[i]=sc.nextInt();
			if(a[i]>max)max=a[i];
			


		}
		boolean []mask=new boolean[max+1];
		int []temp=new int[n];
		temp[n-1]=1;
		mask[a[n-1]]=true;
		for(int i=n-2;i>=0;i--) {
			int x=temp[i+1];
			if(!mask[a[i]]) {
				mask[a[i]]=true;
				x++;
			}
			temp[i]=x;
		}
		for(int i=0;i<m;i++) {
			int y=sc.nextInt();
			System.out.println(temp[y-1]);
		}
		
		
	}
	public static void HitTheLottery() {
		int n=sc.nextInt();
		int count=0;
		int [] m= {100,20,10,5,1};
		for(int i=0;i<5;i++) {
			if(n>=m[i]) {
				int x=n/m[i];
				count+=x;
				n=n-x*m[i];
			}
		}
		System.out.println(count);

		
	}
	public static int lg(long x) {
		return (int)(Math.log10(x)/Math.log10(2));
	}
	public static void ANDORAndSquareSum() {
		int n=sc.nextInt();
		long m[]=new long[n];
		int a[]=new int[20];
		int maxb=0;
		for(int i=0;i<n;i++) {
			m[i]=sc.nextInt();
			long t=m[i];
			int bit=0;
			while(t>0) {
				if((t&1)!=0) {
					a[bit]++;
					if(a[bit]>maxb)
						maxb=a[bit];
				}
				bit++;
				t>>=1;
			}
		}
		long num[]=new long[maxb];
		for(int i=0;i<a.length;i++) {
			int j=0;
			while(a[i]>0) {
				num[j]=num[j]|(1<<i);
				j++;
				a[i]--;
			}
		}
		long sum=0;
		for(int i=0;i<num.length;i++) {
			sum+=(num[i]*num[i]);
		}
		System.out.println(sum);


		

		
	}
	public static void PolycarpTraining() {
		int n=sc.nextInt();
		

		

		LinkedList <Integer>l=new LinkedList<Integer>();
		for(int i=0;i<n;i++) {
			

			l.add(sc.nextInt());
		}
		
		Collections.sort(l);
		

		

		int days=1;
		for(int i=0;i<n;i++) {
			if(l.remove()>=days) {
				days++;
			}

		}
		System.out.println(days-1);
	}
	public static void PolycarpTraining2() {
		int n=sc.nextInt();
		int a[]=new int[n];
		

		

		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
			

		}
		
		

		

		Arrays.sort(a);
		int days=1;
		for(int i=0;i<n;i++) {
			if(a[i]>=days) {
				days++;
			}

		}
		System.out.println(days-1);
	}

	
	public static void RequiredRemainder() {
		int t=sc.nextInt();
		for(int o=0;o<t;o++) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			int n=sc.nextInt();
			int c1=(n-y)%x;

			System.out.println(n-c1);
			int c=((n-y)/x)*x+y;
			System.out.println(c);
	
			
		}
	}
    static int binarySearch( int arr[],int x,int l,int r) 
    { 

        while (l <= r) { 
            int m = l + (r - l) / 2; 
            
  
            

            if (arr[m] == x) 
                return m; 
  
            

            if (arr[m] < x) 
                l = m + 1; 
  
            

            else
                r = m - 1; 
        } 
  
        

        

        return -1; 
    } 
    
    public static void MultiplyBy2DivideBy6() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    		int n=sc.nextInt();
    		int c2=0;
    		int c3=0;
    		while(n%3==0) {
    			c3++;
    			n/=3;
    		}
    		while(n%2==0) {
    			c2++;
    			n>>=1;
    		}
    		if(n==1) {
    			if(c3>=c2) {
    				

    				System.out.println(c3+(c3-c2));
    			}
    			else
    				System.out.println(-1);
    			
    		}
    		else
    			System.out.println(-1);
    	}
    }
    public static void GameWithArray() {
    	int n=sc.nextInt();
    	int s=sc.nextInt();
		 PrintWriter out = new PrintWriter(System.out);
    	if((2*n)>=(s+1)) {
    	    out.println("NO");  

            out.flush();
    		
    	}
    	else {
             out.println("YES");  

             out.flush();
    		

    		for(int i=0;i<n-1;i++) {
                out.print(1+" ");  

                

    			s--;
    		}
            out.print(s);  

            out.flush();
            
    		

    		System.out.println();
    		System.out.println(s-1);
    	}
    }
    public static void GameWithArray2() {
    	int n=sc.nextInt();
    	int s=sc.nextInt();
		PrintWriter out = new PrintWriter(System.out);
		int d=s/n;
		int mod=s%n;
		if(d<=1) {
    	    out.println("NO");  

            out.flush();
		}
		else {
			 out.println("YES");  

             out.flush();
    		

    		for(int i=0;i<n-1;i++) {
                out.print(d+" ");  

                

    			

    		}
            out.print(d+mod);  

            out.flush();
            
    		

    		System.out.println();
    		System.out.println(1);
		}
		
    }
    public static void MagicalSticks() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    		long a=sc.nextLong();
    		long x =(a*(a+1))/(2*a);
    		System.out.println(x);
    	}
    }
    
    public static void  QAQ() {
    	String s=sc.nextLine();
    	String word=s;
    	

    	

    	int count=0;
    	int []a=new int[s.length()];
    	for(int i=0;i<s.length();i++) {
    		if(word.charAt(i)=='Q') {
    			for(int j=i+1;j<s.length();j++) {
    				if(word.charAt(j)=='A') {
    	    			


    					if(a[j]!=0) {
    						count+=a[j]-1;
    					}
    					else {
    						a[j]=1;
    					for(int k=j+1;k<s.length();k++) {
    						if(word.charAt(k)=='Q') {
    						

    							a[j]++;
    							count++;
    						}
    					}
    					}
    				}
    			}
    		}
    	}
    	System.out.println(count);
    	
    }
    
    public static void PetrAndACombinationLock() {
    	int n=sc.nextInt();
    	int a[]=new int[n];
    	for(int i=0;i<n;i++) {
    		a[i]=sc.nextInt();
    	}
    	helper(0,a,n,0);
		System.out.println("NO");

    }
    private static void helper(int i,int a[],int n,int degree) {
    	if(f)return;
    	if(n==0) {
    		
    		

    		if(degree==0||degree==360||degree==-360) {
    			System.out.println("YES");
    			f=true;
    			System.exit(0);
    			
    		}
    		
    	}
    	else if(i>=a.length)return;
    	else {
    		

    		int dl=degree+a[i];
    		if(dl>360)
    			dl=dl-360;
    		int dr=degree-a[i];
    		if(dr<0)
    			dr=dr+360;
    		helper(i+1,a,n-1,dr);
    		helper(i+1,a,n-1,dl);

    	}
    }
    public static void Equalize() {
    	int x=Integer.parseInt(sc.nextLine());
    	String s=sc.nextLine();
    	String s2=sc.nextLine();
    	int count =0;
    	for(int i=0;i<x;i++) {
    		if(s.charAt(i)!=s2.charAt(i)) {
    			if(i<x-1) {
    				if(s.charAt(i+1)!=s2.charAt(i+1)&&s.charAt(i+1)!=s.charAt(i)) {
    					count++;
    					i++;
    				}
    				else {
    					count++;
    				}
    			}
    			else {
    				count++;
    			}
    		}
    	}
    	System.out.println(count);
    }
	private static double daysAtindex(long sum) {
		double t=(Math.sqrt(1+((sum)*8))-1)/2;
		return t;
	}
	
	public static void Packets() {
		double x=sc.nextDouble();
		System.out.println(((int)(Math.log10(x)/Math.log10(2)))+1);
		


		
	}
	
	public static void ReachMedian() {
		int n=sc.nextInt();
		int s=sc.nextInt();
		int a[]=new int[n];
		for(int i=0;i<n;i++) {
			a[i]=sc.nextInt();
		}
		Arrays.sort(a);
		long count=0;
		if(a[n/2]<=s) {
			for(int i=n/2;i<n;i++) {
				if(s>a[i]) {
					count+=s-a[i];
				}
			}
		}
		else {
			for(int i=0;i<=n/2;i++) {
				if(s<a[i]) {
					count+=a[i]-s;
				}
			}
			
		}
		System.out.println(count);
	}
	public static void NumberGame() {
		int t=sc.nextInt();
		for(int p=0;p<t;p++) {
			int n=sc.nextInt();
			

			if(n==1) {
			   System.out.println("FastestFinger");

			}
			else if(n==2) {
				System.out.println("Ashishgup");

			}
			else if(n==3) {
				System.out.println("Ashishgup");

			}
			else if((n&1)==1) {
				System.out.println("Ashishgup");
			}
			else if(isPowerOfTwoMe(n)) {
				System.out.println("FastestFinger");
			}
			else if((n&2)==0) {
				System.out.println("Ashishgup");
			}
			else if(isPrime(n/2)){
				System.out.println("FastestFinger");

			}
			else {
				System.out.println("Ashishgup");

			}
		}

	}
	static boolean isPowerOfTwo(int n) 
	{ 
	    if(n==0) 
	    return false; 
	  
	return (int)(Math.ceil((Math.log10(n) / Math.log10(2)))) ==  
	       (int)(Math.floor(((Math.log10(n) / Math.log10(2))))); 
	} 
	static boolean isPowerOfTwoMe(int n) {
		return(n&-n)==n;
	}
    static boolean isPrime(int n) { 
    

    if (n%2==0) return false; 
    

    for(int i=3;i<=Math.sqrt(n);i+=2) { 
        if(n%i==0) 
            return false; 
    } 
    return true; 
} 
    
    public static void CodeforcesSubsequences() {
		PrintWriter out = new PrintWriter(System.out);
    	long k=sc.nextLong();
        char [] c= {'c','o','d','e','f','o','r','c','e','s'};
        int [] r= {1,1,1,1,1,1,1,1,1,1};
        int n=2;
        long s=1;
        int i=0;
        while(s<k) {
        	if(i>=10) {
        		i=0;
        		n++;
        	}
        	s/=r[i];
        	r[i]=n;
        	s*=r[i];
        	i++;
        	
        }
        

        for(int z=0;z<10;z++) {
        	for(int j=r[z];j>0;j--) {
        		out.print(c[z]);
        	}
        }
        out.flush();
    }
    public static void RationalLee() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    	  int n=sc.nextInt();
    	  int k=sc.nextInt();
    	  ArrayList <Integer> a=new ArrayList <Integer>(n+1);
    	  for(int i=0;i<n;i++) {
    		  a.add(sc.nextInt());
    	  }
    	  ArrayList <Integer> w=new ArrayList <Integer>(k+1);
    	  int countOnes=0;
    	  for(int i=0;i<k;i++) {
    		  int x=sc.nextInt();
    		  w.add(x);
    		  if(x==1)countOnes++;
    		 
    	  }
    	  Collections.sort(a);
    	  Collections.sort(w);
    	  long c=0;
    	  int r=a.size()-1;
    	  int l=0;
    	

    	  for(int i=w.size()-1;i>=0;) {
    		  if(countOnes>0) {
    			

    			  c+=(a.get(r)*2);
    			 

    			  r--;
    			  countOnes--;
    			  continue;
    		  }
    		  else if(w.get(i)!=1){
    			 

    			 c+=a.get(l)+a.get(r);
    			 r--;
    			 l+=(w.get(i)-1);
    			  
    		  }
    		  else {
    			  break;
    		  }
    		  i--;
    	  }
    	  System.out.println(c);
    	}
    }
    
    public static void RationalLee2() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    	  int n=sc.nextInt();
    	  int k=sc.nextInt();
    	  Integer a[]=new Integer[n];
    	  for(int i=0;i<n;i++) {
    		  a[i]=sc.nextInt();
    	  }
    	  Integer w[]=new Integer[k];
    	  int countOnes=0;
    	  for(int i=0;i<k;i++) {
    		  w[i]=sc.nextInt();
    		  if(w[i]==1)countOnes++;
    	  }
    	  Arrays.sort(a);
    	  Arrays.sort(w);
    	  long c=0;
    	  int r=a.length-1;
    	  int l=0;
    	

    	  for(int i=w.length-1;i>=0;) {
    		  if(countOnes>0) {
    			

    			  c+=(a[r]*2);
    			 

    			  r--;
    			  countOnes--;
    			  continue;
    		  }
    		  else if(w[i]!=1){
    			 

    			 c+=a[l]+a[r];
    			 r--;
    			 l+=(w[i]-1);
    			  
    		  }
    		  else {
    			  break;
    		  }
    		  i--;
    	  }
    	  System.out.println(c);
    	}
    }
    
    public static void EvenPicture() {
		PrintWriter out = new PrintWriter(System.out);
    	int n=sc.nextInt();
    	System.out.println(4+n*3);
    	int x=1;
    	int y=1;
    	System.out.println(0+" "+0);
    	System.out.println(0+" "+1);
    	System.out.println(1+" "+0);
    	System.out.println(1+" "+1);
    	while(n>0) {
    		n--;
    		int py=y+1;
    		int px=x+1;
    		out.println(x+" "+py);
    		out.println(px+" "+y);
    		out.println(px+" "+px);
    		x++;
    		y++;
    		
    	}
    	out.flush();
    	
    }
    
    public static void MoveBrackets() {
    	int t=Integer.parseInt(sc.nextLine());
    	for(int k=0;k<t;k++) {
    		int n=Integer.parseInt(sc.nextLine());
    		String s=sc.nextLine();
    		Stack<Character> lB=new Stack<Character>();
    		Stack<Character> rB=new Stack<Character>();
    		for(int i=0;i<n;i++) {
    			if(s.charAt(i)==')')lB.push(s.charAt(i));
    			else {
    				rB.push(s.charAt(i));
    				i++;
    				while(!rB.isEmpty()&&i<n) {	
    					if(s.charAt(i)==')')
    						rB.pop();
    					else
    						rB.push(s.charAt(i));
    					i++;
    				}
    				if(rB.isEmpty()&&i<n)
    					i--;
    			}
    		}
    		int f=(lB.size()+rB.size())/2;
    		System.out.println(f);
    	}
    }
    
    public static void ZeroRemainderArray() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		long n=sc.nextInt();
    		long k=sc.nextInt();
    		

    		HashMap <Long,Long> mask=new HashMap<Long,Long>();
    		long x=0;
    		for(int i=0;i<n;i++) {
    			long in=sc.nextLong();
    			Long mod=in%k;
    			if(mod!=0) {
    				if(mask.get(mod)==null) {
    					mask.put(mod, 0l);
    				}
    				mask.put(mod, mask.get(mod)+1);
    				

    				long temp=k-mod+(mask.get(mod)-1)*k;
    				if(temp>x)x=temp;
    			}

    		}
    		if(x==0)
    	    	System.out.println(0);
    		else
    	    	System.out.println(x+1);

    	}
    			
    }
    
    public static void LongestIncreasingSubsequence() {
    	int n=5;
    	int[] nums = {11, 23, 10, 37, 21};
    	LongestIncreasingSubsequenceDp(nums);
    	
    }
    private static void LongestIncreasingSubsequenceDp(int []nums) {
    	int LIS[]=new int[nums.length];
    	int m =0;
    	for(int i=nums.length-1;i>=0;i--) {
    		if(LIS[i]==0)
    	        LongestIncreasingSubsequenceDp(nums,LIS,i);
    		if(LIS[i]>m) {
    			m=LIS[i];
    			

    		}
    		}
    			
    	

    	System.out.println(m);

    	
    }
    
    public static int LongestIncreasingSubsequenceDp(int []nums,int[]LIS,int k) {
    	if(LIS[k]!=0)
    		return LIS[k];
    	else {
    		int max=0;
    		for(int i=k-1;i>=0;i--) {
    			if(nums[i]<nums[k]) {
    				max=Math.max(max,LongestIncreasingSubsequenceDp(nums,LIS,i) );
    			}
    		}
    		
    		LIS[k]=max+1;
    		return max+1;
    		
    	}
    	
    }
    public static boolean isSafe(int [][]n,int x,int y) {
    	for(int i=0;i<n.length;i++) {
    		if(n[x][i]==1&&i!=y) 
    			return false;   		
    	}
    	for(int i=0;i<n.length;i++) {
    		if(n[i][y]==1&&i!=x)
    			return false;
    	}
    	int m=Math.min(x, y);
    	for(int i=x-m,j=y-m;i<n.length&&j<n.length;i++,j++) {
    		
    		if(n[i][j]==1&&i!=x&&j!=y)
    			return false;
    	}

    	int m2=Math.min(x, n.length-1-y);
    	for(int i=x-m2,j=y+m2;i<n.length&&j>=0;i++,j--) {
    		

    		if(n[i][j]==1)
    			return false;
    	}
    	return true;
    
    }
    
    public static void NQueen(int n[][],int k) {
    	if(k==n.length||k<0)return;
    	boolean f=false;
    	

    	for(int i=0;i<n.length;i++) {
    		if(n[k][i]==1) {
    			n[k][i]=0;
    			continue;
    		}
    		if(isSafe(n,k,i)) {
    		

    			n[k][i]=1;
    			f=true;
    			break;
    		}
    	}
    	if(f) {

    		NQueen(n,k+1);
    	}
    	else {
        	


    		NQueen(n,k-1);
    	}
    }
    
    public static void NQueen(int q) {
    	int n[][]=new int[q][q];
    	NQueen(n,0);
    	display(n);
    }
    public static void display(int [][]n) {
    	for(int i=0;i<n.length;i++) {
    		System.out.println(Arrays.toString(n[i]));
    	}
    }
    
    public static void PalindromicPaths() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		int n=sc.nextInt();
    		int m=sc.nextInt();
    		int [][]b=new int[n][m];
    		for(int i=0;i<n;i++) {
    			for(int j=0;j<m;j++) {
    				b[i][j]=sc.nextInt();
    			}
    		}
    		
    		int xh=0;
    		int yh=0;
    		int count=0;
    		while(xh<n&&yh<m) {
    			int countOnes=0;
    			int countZeros=0;
    			boolean safe=true;
				


    			for(int i=xh,j=yh;i<n&&j>=0;i++,j--) {
    				if(b[i][j]==0)countZeros++;
    				else countOnes++;
    				

    				int tempx=n-1-i;
    				int tempy=m-1-j;
    			

    				if((i+j>=tempx+tempy)) {
    					safe =false;
    					break;
    				}
    				if(b[tempx][tempy]==0)countZeros++;
    				else  countOnes++;
    				

    				
    			}
    		

    			if(safe) {
    				if(countZeros>countOnes)
    					count+=countOnes;
    				else
    					count+=countZeros;
    				if(yh+1<m) 
    					yh++;
    				else 
    					xh++;
    				
    			}
    			else break;
    		}
    		System.out.println(count);
    	}
    }
    
    public static void  ReadingBooks() {
    	int n=sc.nextInt();
    	int k=sc.nextInt();
    	ArrayList<Integer>a=new ArrayList<Integer>();
    	ArrayList<Integer>b=new ArrayList<Integer>();
    	ArrayList<Integer>both=new ArrayList<Integer>();
    	for(int i=0;i<n;i++) {
    		int t=sc.nextInt();
    		int ai=sc.nextInt();
    		int bi=sc.nextInt();
    		if(ai==1&&bi==0)a.add(t);
    		else if(ai==0&&bi==1)b.add(t);
    		else if(ai==1&&bi==1)both.add(t);
    	}
    	Collections.sort(a);
    	Collections.sort(b);
    	Collections.sort(both);
        int count=0;
    	for(int i=0,j=0,w=0;k>0;) {
    		if(i<a.size()&&j<b.size()&&w<both.size()&&(a.get(i)+b.get(j)<both.get(w))) {
    			count+=a.get(i)+b.get(j);
    			i++;j++;k--;
    		}
    		else if(w<both.size()) {
    			count+=both.get(w);

    			w++;k--;
    		}
    		else if(i<a.size()&&j<b.size()) {
    			count+=a.get(i)+b.get(j);
    			i++;j++;k--;
    		}
    		else {
    			System.out.println(-1);
    			return;
    		}
    	}
    	System.out.println(count);
    			

    	
    	
    	
    }
    
    public static void ShovelsAndSwords() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		long a=sc.nextLong();
    		long b=sc.nextLong();
    		int d3= (int)(a+b)/3;
    		System.out.println((int)Math.min(Math.min(a, b), d3));

   
    	}
    }
    
    public static void MagicalCalendar() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    	long n=sc.nextLong();
    	long r=sc.nextLong();
    	long f=0;
    	if(r<n) {
    		f=r*(r+1)/2;
			

    		
    	}
    	else {
    		
    		f=((n-1)*n)/2;
    		

    		f++;
    	}
    	System.out.println(f);
    	}
    	
    }
    
    public static void MagicalCalendar2() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    	long n=sc.nextLong();
    	long r=sc.nextLong();
    	long f=0;
    	if(r<n) {
    		f=((r*(r+1))/2);
    		
    	}
    	else {
    		f=(n*(n-1)/2);
    		

    		f++;
    	}
    	System.out.println((long)f);
    	}
    	
    }
    
    public static void ACookieForYou() {
    	int t=sc.nextInt();
    	for(int i=0;i<t;i++) {
    		long a=sc.nextLong();
    		long b=sc.nextLong();
    		long n=sc.nextLong();
    		long m=sc.nextLong();
    		if(Math.min(a, b)<m)
    			System.out.println("NO");
    		else if((a+b)<(n+m))
    			System.out.println("NO");
    		else
    			System.out.println("YES");
    	}
    }
    
    public static void PlusesAndMinuses() {
    	int t=Integer.parseInt(sc.nextLine());
    	

    	for(int o=0;o<t;o++) {
    		String s=sc.nextLine();
    		int [] c=new int[s.length()];
    		int count=0;
    		for(int i=0;i<s.length();i++) {
    			if(s.charAt(i)=='-')
    				c[i]=--count;
    			else
    				c[i]=++count;				
    		}

    		int ref=0;
    		if(count<0) 
    			ref=(count*-1)-1;
    		else
    			ref=0;




    		long finalCount=s.length();
    		long m=-1;
    		for(int i=0;i<s.length();i++) {
    			if(c[i]==m) {
    				finalCount+=(i+1);
    				m--;
    			}
    		}
    		System.out.println(finalCount);
    	}
    }
    
    public static void BuyingShovels() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		int n=sc.nextInt();
    		int k=sc.nextInt();
    		if(k>=n) {
    			System.out.println(1);
    			continue;
    		}
    		int root=(int) Math.ceil(Math.sqrt(n));
    		int min=Integer.MAX_VALUE;
    		for(int i=root;i>0;i--) {
    			if(n%i==0) {
    				int j=n/i;
    				int mx=Math.max(i, j);
    				int mn=Math.min(i, j);
    				if(mx<=k&&mn<min) {
                         min=mn;
    				}
    				else if(mn<=k&&mx<min){
                         min=mx;
    				}
    				
    			}
    		}
    		System.out.println(min);
    	}
    }
    
    public static void SimilarPairs() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		int n=sc.nextInt();
    		ArrayList<Integer>even=new ArrayList<Integer>();
    		ArrayList<Integer>odd=new ArrayList<Integer>();
    		for(int i=0;i<n;i++) {
    			int in =sc.nextInt();
    			if((in&1)==0)even.add(in);
    			else odd.add(in);
    		}
    		if((even.size()&1)==0) {
    			System.out.println("YES");
    			continue;
    		}
    		boolean yes=false;
    		for(int i=0;i<even.size()&&!yes;i++) {
    			for(int j=0;j<odd.size()&&!yes;j++) {
    				if(Math.abs(even.get(i)-odd.get(j))==1)
    					yes=true;
    			}
    		}
    		if(yes)
    			System.out.println("YES");
    		else
    			System.out.println("NO");
    		

    	}
    }
    
    public static void HonestCoach() {
    	int t=sc.nextInt();
    	for(int o=0;o<t;o++) {
    		int n=sc.nextInt();
    		int []s=new int[n];

    		for(int i=0;i<n;i++) {
    			s[i]=sc.nextInt();
    		}
    		Arrays.sort(s);
    		int m=Integer.MAX_VALUE;
    		for(int i=s.length-1;i>0;i--) {
    			if(s[i]-s[i-1]<m)
    				m=s[i]-s[i-1];
    		}
    		System.out.println(m);
    		
    	}
    }
    
    public static boolean check(char[][]c,char jc,int ind) {
    	char temp=c[0][ind];
    	c[0][ind]=jc;
    	

    

    	for(int i=1;i<c.length;i++) {
    		int count=0;
    		for(int j=0;j<c[i].length;j++) {
    			if(c[0][j]!=c[i][j]) {
    				

    				count++;
    			}
    				
    		}
    		if(count>1) {
    			c[0][ind]=temp;
    			return false;
    		}
    	}
    	c[0][ind]=temp;
    	return true;
    	
    }
    
    public static void SpyString(){
    	int t=Integer.parseInt(sc.nextLine());
    	for(int i=0;i<t;i++)
    		SpyStringHelper();
    }
    private static void SpyStringHelper(){
    	

    	

    	int n=sc.nextInt();
    	

    	int m=sc.nextInt();
    	sc.nextLine();

    	
    	char[][]c=new char[n][m];
    	for(int i=0;i<n;i++) {
    		String s=sc.nextLine();
    		c[i]=s.toCharArray();
    	}
    	char[][]p=new char[26*m][m];
    	for(int i=0;i<m;i++) {
    		for(char j ='a';j<='z';j++) {
    			if(check(c,j,i)) {
    				c[0][i]=j;
    				for(int k=0;k<m;k++) {
    					System.out.print(c[0][k]);
    				}
    				System.out.println();
    				return;
    			}
    		}
    	}
    	System.out.println(-1);
    }
    
    public static void Polygon() {
    	int t=sc.nextInt();
    	

    	for(int o=0;o<t;o++) {
    		

    		int n=sc.nextInt();
    		sc.nextLine();
    		

    		int [][]m=new int[n][n];
    		for(int i=0;i<n;i++) {
    			String temp=sc.nextLine();
    			for(int j=0;j<n;j++) {
    				m[i][j]=Integer.parseInt(temp.charAt(j)+"");
    			}
    			
    		}
    		boolean f=true;
    		outer: for(int i=0;i<n;i++) {
    			for(int j=0;j<n;j++) {
    				if(m[i][j]==0||i==n-1||j==n-1)continue;
    				if(m[i][j+1]+m[i+1][j]==0) {
    					f=false;
    					break outer;
    				}
    			}
    				
    		}
    		if(f)
    			System.out.println("YES");
    		else
    			System.out.println("NO");
    		

            
    	}
    }
    
   public static void ABMatrix(){
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int m=sc.nextInt();
		   int a=sc.nextInt();
		   int b=sc.nextInt();
		   int [][]grid=new int[n][m];
		   int []mask=new int [m];
		   ABMHelper(grid,a,b,n,m,mask);

	   }
   }
   
   public static void ABMHelper(int [][]grid,int a,int b,int n,int m,int[]mask) {
		PrintWriter out = new PrintWriter(System.out);

		 for(int i=0;i<n;i++) {
			   for(int j=0;j<a;j++) {
				   boolean f=false;
				   int ind=i;
				   for(int k=0;k<mask.length;k++) {
					   ind=(i+k)%m;
					   if(mask[ind]+1<=b&&grid[i][ind]==0) {
						   mask[ind]++;
						   grid[i][ind]++;
						   f=true;
						   break;
					   }
				   }
				   if(!f) {
					   System.out.println("NO");
					   return;
				   }
				   
			   }
		   }
		 for(int i=0;i<mask.length;i++) {
			 if(mask[i]!=b) {
				 System.out.println("NO");
				 return;
			 }
		 }

		   out.println("YES");
		   for(int i=0;i<n;i++){
			   for(int j=0;j<m;j++)
				   out.print(grid[i][j]);
			   out.println();
		   }
		   out.flush();
   }
   
   public static char getC(int size,LinkedList<Character>c) {
	   Object b2[]=c.toArray();
	   LinkedList <Character>temp =new LinkedList<Character>();
	   int i2=0;
	   char f2='0';
	   for (i2=0;i2<b2.length;i2++) {
		   if(b2[i2].equals(b2[size-1])) {
			   f2=(char)b2[i2];
			   break;
		   }
		   temp.add((char)b2[i2]);
	   }
	   for(int j2=size;j2<b2.length;j2++) {
		   temp.add((char)b2[j2]);
	   }
	   c=temp;
	   return f2;
   }
   
   public static void TaskOnTheBoard() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   sc.nextLine();
		   String s=sc.nextLine();
		   LinkedList<Character>c=new LinkedList<Character>();
		   for(int i=0;i<s.length();i++) {
			   c.add(s.charAt(i));
		   }
		  

		   int m=sc.nextInt();
		   int b[]=new int[m];
		   LinkedList<Integer>zeroInd =new LinkedList <>();
		   for(int i=0;i<m;i++) {
			   b[i]=sc.nextInt();
			   if(b[i]==0)
				   zeroInd.add(i);
		   }
		   Collections.sort(c);
		   char []f=new char[m];
		  

		   for(int i=0;i<m;) {
			   

			   int size=zeroInd.size();
			  

			   Object b2[]=c.toArray();
			  

			   LinkedList <Character>temp =new LinkedList<Character>();
			   int i2=0;
			   char f2='0';
			   for (i2=b2.length-1;i2>=0;i2--) {
				 

				   if(b2[i2].equals(b2[i2-size+1])) {
					   f2=(char)b2[i2];
					   break;
				   }
				 
				   temp.addFirst((char)b2[i2]);
			   }
			   for(int j2=i2-size;j2>=0;j2--) {
				   temp.addFirst((char)b2[j2]);
			   }
			   c=temp;
			   
			   
			   for(int j=0;j<size;j++) {
				   int ZI=zeroInd.removeFirst();
				   f[ZI]=f2;
				   i++;
				   for(int k=0;k<b.length;k++) {
					   if(b[k]!=0) {
						   b[k]-=Math.abs(ZI-k);
						   if(b[k]==0)
							   zeroInd.add(k);
					   }
				   }
			   }
		   }
		  

		   for(int i=0;i<f.length;i++)
			   System.out.print(f[i]);
		   System.out.println();
	   }
   }
   
   public static void Shuffle() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int x=sc.nextInt();
		   int m=sc.nextInt();
		   int a=x;
		   int b=x;
		   for(int i=0;i<m;i++) {
			   int c=sc.nextInt();
			   int d=sc.nextInt();
			   if(c<=a&&d>=a) {
				   a=c;
				   b=Math.max(b, d);
			   }
			   else if(c<=b&&d>=b) {
				   Math.min(a, c);
				   b=d;
			   }
		   }
		   System.out.println(b-a+1);
	   }
	   
   }
   
   public static void SocialDistance() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int k=sc.nextInt();
		   sc.nextLine();
		   String s=sc.nextLine();
		   char []seats=s.toCharArray();
		   int count=0;
		   boolean f=true;
		   for(int i=0;i<seats.length;i++) {
			   if(seats[i]=='1') {
				   i+=(k);
				   continue;
			   }
			   
			   f=true;
			   for(int j=i+1;j<=i+k&&j<seats.length;j++) {
				   if(seats[j]=='1') {
					   f=false;




					   i=(j+k);
					  

					   break;
				   }
			   }
			   if(f) {
				   count++;
				   i+=(k);
			   }


			   }

		   
		   System.out.println(count);
	   }
   }
   public static void SocialDistance2() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int k=sc.nextInt();
		   sc.nextLine();
		   String s=sc.nextLine();
		   LinkedList<Integer>l=new LinkedList<Integer>();
		   int start=0;
		   int end=0;
		   int count=0;
		   for(int i=0;i<s.length();i++) {
			   if(s.charAt(i)=='1')continue;
			   start=i;
			   if(s.charAt(i)=='0') {
				   int c=0;
				   for(i=i;i<s.length()&&s.charAt(i)=='0';i++) {
					   c++;
				   }
				   if(c<(2*k+1))continue;
				   end=i;
				   

				   if(start==0&&end==s.length()-1) {
					   count++;
					   c--;
					   count+=(c/(k));
				   }
				   else if(start==0) {
					   c-=k;
					   count++;
					   c--;
					   count+=(c/(k));
					   

				   }
				   else if(end==s.length()-1) {
					   

					   c-=k;
					   count+=(c/(k));
				   }
				   else {
					   c-=2*k;
					   count+=(c/(k));
				   }
			   }
		   }
		   System.out.println(count);
	   }
	   
   }
   
   public static void SocialDistance3() {
	   
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int k=sc.nextInt();
		   sc.nextLine();
		   String s=sc.nextLine();
		   int count=0;
		   boolean open=false;
		   int test=0;
		   for(int i=0;i<s.length();i++) {
			   if(s.charAt(i)=='1') {
				   i+=k;
				   open=false;
				   test=0;
			   }
			   else if(open) {
				   test--;
				   if(test==0) {
					   open=false;
					   test=0;
					   count++;
					   

				   }
			   }
			   else {
				   open=true;
				   test=k;
			   }
		   }
		   if(open)count++;
		   System.out.println(count);
		   
		   
	   }
	   
   }
   
   
   public static void OddSelection() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int x=sc.nextInt();
		   int oddSum=0;
		   int evenSum=0;
		   for(int i=0;i<n;i++) {
			   int temp=sc.nextInt();
			   if(temp%2==0) evenSum++;
			   else oddSum++;		   
		   }
		   if(oddSum+evenSum<x){
			   System.out.println("No");
		   }
		   else if(oddSum==0) {
			   System.out.println("No");
		   }
		   else if(oddSum+evenSum==x) {
			   if(oddSum%2==0)
				   System.out.println("No");
			   else
				   System.out.println("Yes");
		   }
		   else if(oddSum+evenSum>x) {
			   if(x%2==0&&evenSum==0)
				   System.out.println("No");
			   else
				   System.out.println("Yes");
		   }

		   
	   }
   }
   
   public static void SubsequenceHate() {
	   int t=sc.nextInt();
	   sc.nextLine();
	   for(int o=0;o<t;o++) {
		   String s=sc.nextLine();
		   

		   int[]ZF=new int[s.length()];
		   int[]OF=new int[s.length()];
		   int[]ZL=new int[s.length()];
		   int[]OL=new int[s.length()];
		   if(s.charAt(0)=='1')OF[0]=1;
		   else ZF[0]=1;
		   for(int i=1;i<s.length();i++) {
			   if(s.charAt(i)=='1') {
				   ZF[i]=ZF[i-1];
				   OF[i]=OF[i-1]+1;
			   }
			   else {
				   ZF[i]=ZF[i-1]+1;
				   OF[i]=OF[i-1];
			   }
				   
		   }
		   if(s.charAt(s.length()-1)=='1')OL[s.length()-1]=1;
		   else ZL[s.length()-1]=1;
		   for(int i=s.length()-2;i>=0;i--) {
			   if(s.charAt(i)=='1') {
				   ZL[i]=ZL[i+1];
				   OL[i]=OL[i+1]+1;
			   }
			   else {
				   ZL[i]=ZL[i+1]+1;
				   OL[i]=OL[i+1];
			   }
				   
		   }
		   int min=Integer.MAX_VALUE;
		   for(int i=0;i<ZF.length;i++) {
			   if(s.charAt(i)=='1') {
				   int temp=Math.min(ZF[i],OF[i])+Math.min(ZL[i],OL[i]-1);
				   if(temp<min)
					   min=temp;
			   }
			   else {
				   int temp=Math.min(ZF[i],OF[i])+Math.min(ZL[i]-1,OL[i]);
				   if(temp<min)
					   min=temp;
			   }
		   }








		   System.out.println(min);

		   
		   

		   



		   
		   
 
		   
	   }
   }
   
   public static void GameOnLeaves() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int x=sc.nextInt();
		   int countx=0;
		   int count=0;
		 

		   for(int i=0;i<n-1;i++) {
			   int u=sc.nextInt();
			   int v=sc.nextInt();
			   if(u==x||v==x)
				   countx++;
			   else
				   count++;




		   }
		   if(countx<2) {
			   System.out.println("Ayush");
		   }
		   else {
			   if((count-countx)%2==0) {
				   System.out.println("Ashish");
			   }
			   else {
				   System.out.println("Ayush");
			   }
		   }
	   }
	   
   }
   
   public static void MagicalSticks2() {
   	int t=sc.nextInt();
   	for(int i=0;i<t;i++) {
   		long a=sc.nextLong();
   		long x =(a*(a+1))/(2*a);
   		

   		System.out.println(x);
   	}
   }
   
   public static void XXXXX() {
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int x=sc.nextInt();
		   int a[]=new int [n];
		   int sum1=0;
		   for(int i=0;i<n;i++) {
			   a[i]=sc.nextInt();
			   sum1+=a[i];
		   }
		   int sum2=sum1;
		   int sum3=sum1;
		   int sum4=sum1;
		   int c=a.length;
		   

		   for(int i=0;i<a.length&&sum1%x==0&&sum2%x==0&&sum3%x==0&&sum4%x==0;i++) {
			  

			   if((i&1)==0) {
				   sum3-=a[i];
				   sum4-=a[a.length-1-i];
			   }
			   else {
				   sum4-=a[i];
				   sum3-=a[a.length-1-i];
			   }
			   sum1-=a[i];
			   c--;
			   sum2-=a[a.length-1-i];
			  

		   }
		   if(c==0)
			   System.out.println(-1);
		   else 
			   System.out.println(c);
	   }
   }
   
   public static void  EhabAndPrefixMEXs() {
	   int n=sc.nextInt();
	   LinkedList<Integer>o=new LinkedList<Integer>();
	   HashSet<Integer>s=new HashSet<Integer>();
	   int[]a=new int[n];
	   boolean stop=false;
	   for(int i=0;i<n;i++) {
		   a[i]=sc.nextInt();
		   s.add(a[i]);
		   if((a[i]-i)>1)
			   stop=true;
	   }
	   if(stop) {
		   System.out.println(-1);
		   return;
	   }
	   for(int i=0;i<=n;i++) {
		   if(!s.contains(i))
			   o.add(i);
	   }
	  

	   int f[]=new int[n];
	   if(a[0]==1) {
		   f[0]=0;
		   if(o.peek()==0)o.remove();
	   }
	   else f[0]=o.remove();
	  
	   


	   for(int i=0;i<n-1;i++) {
		   if(a[i]!=a[i+1]) {
			   f[i+1]=a[i];
		   }
		   else {
			   f[i+1]=o.remove();
		   }
	   }
	  

	   for(int i=0;i<f.length;i++) {
		   System.out.print(f[i]+" ");
	   }
	   System.out.println();
   }
   
   public static void MostSociallyDistancedSubsequence(){
		PrintWriter out = new PrintWriter(System.out);
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int []p=new int[n];
		   for(int i=0;i<n;i++) {
			   p[i]=sc.nextInt();
		   }
		   int count=0;
		   for(int i=0;i<n;i++) {
			   if(i==0 || i==n-1 || (p[i-1]<p[i])!=(p[i]<p[i+1])) {
				  count++;
				  out.print(p[i]+" ");
				  
			   }

		   }
		   out.println();
		   System.out.println(count);
		   out.flush();
		   

		   

	   }
   }
   
   public static void MostSociallyDistancedSubsequence3() {
		PrintWriter out = new PrintWriter(System.out);
	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   int []p=new int[n+1];
		   for(int i=1;i<=n;i++) {
			   p[i]=sc.nextInt();
		   }
		   
	        ArrayList<Integer>ans=new ArrayList<Integer>();
	        for (int i=1;i<=n;i++)
	        {
	            if (i==1 || i==n || (p[i-1]<p[i])!=(p[i]<p[i+1]))
	            ans.add(p[i]);
	        }
	        System.out.println(ans.size());
	        for(int i=0;i<ans.size();i++) {
	        	out.print(ans.get(i)+" ");
	        }
	        out.println();
	        out.flush();
		   
	   }
	   
   }
   
   public static void MostSociallyDistancedSubsequence2(){
 		PrintWriter out = new PrintWriter(System.out);
 	   int t=sc.nextInt();
 	   for(int o=0;o<t;o++) {
 		   int n=sc.nextInt();
 		   int []p=new int[n];
 		   for(int i=0;i<n;i++) {
 			   p[i]=sc.nextInt();
 		   }
 		   if(n<3) {
 			   
 		   }
 		   int l=0;
 		   int r=2;
 		   int mid=1;
 		   int count=2;
 		   out.print(p[0]+" ");
 		   while(r<n) {
 			   if(Math.abs(p[r]-p[l])>=(Math.abs(p[l]-p[mid])+Math.abs(p[r]-p[mid]))) {
 				   mid=r;
 				   r++;
 			   }
 			   else {
 				   out.print(p[mid]+" ");
 				   l=mid;
 				   mid=r;
 				   r++;
 				   count++;
 			   }
 		   }
 		   out.print(p[mid]);
 		   out.println();

 		   System.out.println(count);
 		   out.flush();
 		   

 		   

 	   }
    }
   
   public static void MostSociallyDistancedSubsequence4(){
		

	   int t=sc.nextInt();
	   for(int o=0;o<t;o++) {
		   int n=sc.nextInt();
		   
		   int []p=new int[n];
		   for(int i=0;i<n;i++) {
			   p[i]=sc.nextInt();
		   }
















		   

		  

		   ArrayList <Integer> ans=new ArrayList<Integer>();
		   ans.add(p[0]);
		   for(int i=1;i<n-1;i++) {
			   if(p[i]>p[i+1]&&p[i]>p[i-1]) {
                     ans.add(p[i]);
			   }
			   else if(p[i]<p[i+1]&&p[i]<p[i-1]) {
				   ans.add(p[i]);
			   }

		   }
		   ans.add(p[n-1]);
		   System.out.println(ans.size());
		   for(int i=0;i<ans.size();i++)
			   System.out.print(ans.get(i)+" ");
		   System.out.println();


		   
 
		   
 
	   }
   }
   


  
	

	public static void main(String[] args) {
		

		

		















		

		

		 

		

		

		

		

		

		

		

		

		

		

	

		

		

		

		

		

		

		

		

		





		

		

		

		

		

		

		

		

		

		

		





		

		

		



























		

		

		

		

		

		

		

		

		

		MostSociallyDistancedSubsequence4();



		
		

		

	}

}
