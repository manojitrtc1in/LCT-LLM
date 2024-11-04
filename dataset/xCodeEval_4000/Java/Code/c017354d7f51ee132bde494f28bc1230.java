

import java.util.*;
import java.io.*;
import java.lang.*;


public class Main {
    static int k=0;
   
    
    
    
    
    
    static class FastReader {
        
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(
                new InputStreamReader(System.in));
        }
 
        String next()
        {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt() { return Integer.parseInt(next()); }
 
        long nextLong() { return Long.parseLong(next()); }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try {
                str = br.readLine();
            }
            catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
   static class Node
{
    int data;
    Node left;
    Node right;

        Node(int value)
    {
        data = value;
        left = null;
        right = null;
    }
    
    }
    
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    static class graph implements Comparable<graph>{
        long x;long y;long z;
        graph()
        {
            
        }
        graph(long x,long y,long z)
        {
            this.x=x;this.y=y;this.z=z;
        }
        public int compareTo(graph c)
        {
            

            if(c.z>this.z)
                return -1;
            else if(c.z<this.z)
                return 1;
            else return 0;
        }
    }
    static class pair{
        String word;int freq;
        pair p;
        pair(String xe,int ye)
        {
            this.word=xe;this.freq=ye;
        }
        String getKey()
        {
            return word;
        }
        int getValue()
        {
            return freq;
        }
            
    }
    static class TrieNode{
        TrieNode[] children=new TrieNode[26];
        boolean is_end;int freq;
        TrieNode(){
            is_end=false;
            for(int i=0;i<26;i++)
                children[i]=null;
            freq=0;
        }
        public void insert(String word) {
        TrieNode r=root;
        char ch1[]=word.toCharArray();
        for(int i=0;i<word.length();i++){
            int ch=ch1[i]-'a';
            if(r.children[ch]==null){
                r.children[ch]=new TrieNode();
            }
            r=r.children[ch];
            
        }
        r.is_end=true;
            r.freq++;
        }

        public boolean search(String word) {
            if(word.length()==0)
                return true;
            TrieNode r=root;
            char ch1[]=word.toCharArray();
            for(int i=0;i<word.length();i++){
                int ch=ch1[i]-'a';
                if(r.children[ch]==null){
                    return false;
                }
                r=r.children[ch];
            }
            return r.is_end;
        }

        public boolean startsWith(String word) {
            if(word.length()==0)
                return true;
            TrieNode r=root;
            for(int i=0;i<word.length();i++){
                int ch=word.charAt(i)-'a';
                if(r.children[ch]==null){
                    return false;
                }
                r=r.children[ch];
            }
        return true;
        }
        public List<pair> options(String word){
            TrieNode r=root;
            List<pair> ans=new ArrayList<>();
            for(int i=0;i<word.length();i++){
                int ch=word.charAt(i)-'a';
                r=r.children[ch];
            }

           

            if(r.is_end){
                        ans.add(new pair(word,r.freq));
                    }
            op(word,ans,r);
            Collections.sort(ans,(v1,v2)-> v2.getValue()-v1.getValue());

            return ans;
        }
        public void op(String word,List<pair> ls,TrieNode t){
            

            

            

            for(int i=0;i<26;i++){
                if(t.children[i]!=null){
                    word+=(char)(i+'a');

                    if(t.children[i].is_end){
                        ls.add(new pair(word,t.children[i].freq));
                    }
                    op(word,ls,t.children[i]);
                    word=word.substring(0,word.length()-1);
                }
            }
        }
    }
    static TrieNode root=new TrieNode();
    static void initializeDiffArray(int A[], int D[])
	{
		
		int n = A.length;

		D[0] = A[0];
		D[n] = 0;
		for (int i = 1; i < n; i++)
			D[i] = A[i] - A[i - 1];
	}

	

	static void update(int D[], int l, int r, int x)
	{
		D[l] += x;
		D[r + 1] -= x;


			




		


	}

	

	static int printArray(int A[], int D[])
	{
		for (int i = 0; i < A.length; i++) {
			
			if (i == 0)
				A[i] = D[i];

			

			

			else
				A[i] = D[i] + A[i - 1];

			System.out.print(A[i] + " ");
		}
		
		System.out.println();
		
		return 0;
	}
    
    public static int solve(int[] A, int B) {
      

        if(B>=A.length){
            for(int i=0;i<A.length;i++){
              if(A[i]==1)
              {
                  return 1; 
              }
               
            }
            return -1;
        }
        int prev=-1;int ans=0;int b=0;
        for(int i=0;i<A.length;i++){
            if(A[i]!=1)
            {
                b++;
            }
            else{
                prev=i;
                b++;
            }
            if(b==B){
                if(prev!=-1){
                   ans++;
                   prev=-1;
                   b=-B+1;
                }
                else
                return -1;
            }
           

        }
        if(b>0)
        {
            if(prev!=-1)
            ans++;
            else
            return -1;
        }
        return ans;
    }

  

      

       

         
    public static int minimizeMemory(List<Integer> processes,int m){
        int i=0;int j=0;
        int n=processes.size();
        int sum=0;int temp=0;
        while(j<n){
            temp+=processes.get(j);
            if(j-i+1>m){
                temp-=processes.get(i);i++;
            }
            if(temp>sum){
                sum=temp;
            }
            j++;
        }temp=0;
        for(i=0;i<n;i++){
            temp+=processes.get(i);
        }
        return temp-sum;
    }
    
    public static void main(String[] args) {
         try{
                FastReader sc = new FastReader();
                  int t=sc.nextInt();
                  while(t-->0){
                      int n=sc.nextInt();
                      if(n==3)
                          System.out.println(-1);
                     else if(n%2!=0){
                          for(int i=n;i>n/2+1;i--){
                              System.out.print(i+" ");
                          }
                          for(int i=1;i<=n/2+1;i++){
                              System.out.print(i+" ");
                          }
                          System.out.println();
                      }
                      else{
                          for(int i=n;i>0;i--){
                              System.out.print(i+" ");
                          }
                          System.out.println();
                      }
                  }
                
            }
           catch(Exception e)
        {
            System.out.println("sdf");
        }
    }
    static boolean check(String s){
        char ch[]=s.toCharArray();
        int i=0;int j=ch.length-1;
        while(i<j){
            if(ch[i]!=ch[j])
                return false;
            i++;j--;
        }
        return true;
    }
    static void print(ArrayList<Integer> a,int n)
    {
        

        for (int i=1; i<=Math.sqrt(n); i++)
        {
            if (n%i==0)
            {
                

                if (n/i == i)
                    a.add(i);
      
                else 

                { a.add(i);a.add(n/i);}
            }
        }
    }
   static int count=1;
    static void go(int i,ArrayList<ArrayList<Integer>> arr,int a1[],int al,ArrayList<Integer> ans)
    {
        a1[i]=1;
        ans.add(i);
        for(int j=0;j<arr.get(i).size();j++)
        {
            if(a1[arr.get(i).get(j)]!=1)
            {
                 go(arr.get(i).get(j),arr,a1,al,ans);
                 ans.add(i);
            }
        }
    }
    static class h{
        int ans;
    }
    static int numChild=0;
    static void dfs(int i,int par,ArrayList<ArrayList<Integer>> arr,h a,int c,int m,int a1[]){
        
        if(a1[i]==1)
           c++;
        else
            c=0;
        if(c>m)
            return;
        numChild=0;
        for(int j=0;j<arr.get(i).size();j++)
        {
            if(arr.get(i).get(j)!=par)
            {
              dfs(arr.get(i).get(j),i,arr,a,c,m,a1);  
              numChild++;
            }
        }
       if(numChild==0)
        {
            if(c<=m)
            a.ans++;
            return;
        }
    }
    

    

    

    

    

    

    static int find(int x,int []par)
    {
        if(x==par[x])
            return x;
        return par[x]=find(par[x],par);
    }
    static void union(int x,int y,int []par,int []s)
    {
        x=find(x,par);y=find(y,par);
        if(s[x]<s[y])
        {
            int temp=y;y=x;x=temp;
        }
        par[y]=x;s[x]+=s[y];
    }
    static int solve(boolean vis[][],int i,int j,int n,int m,char ch[][],char prev)
    { 

        if(i<0||j<0||i>=n||j>=m)
            return -1;
        if(ch[i][j]!=prev+1)
            return -1;
        

       
        int x1=1+solve(vis,i+1,j,n,m,ch,ch[i][j]); 

        x1=Math.max(x1,1+solve(vis,i-1,j,n,m,ch,ch[i][j])); 

        x1=Math.max(x1,1+solve(vis,i,j-1,n,m,ch,ch[i][j])); 

        x1=Math.max(x1,1+solve(vis,i,j+1,n,m,ch,ch[i][j])); 

        x1=Math.max(x1,1+solve(vis,i-1,j-1,n,m,ch,ch[i][j])); 

        x1=Math.max(x1,1+solve(vis,i-1,j+1,n,m,ch,ch[i][j]));

        x1=Math.max(x1,1+solve(vis,i+1,j-1,n,m,ch,ch[i][j]));

        x1=Math.max(x1,1+solve(vis,i+1,j+1,n,m,ch,ch[i][j])); 

        return x1;
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    static void preorder(Node node)
    {
        if(node==null)
            return;
        System.out.print(node.data+" ");
        preorder(node.left);
        preorder(node.right);
    }
    static ArrayList<Node> solve(int start,int end)
    {
        ArrayList<Node> arr=new ArrayList<>();
        if(start>end)
        {
          arr.add(null);
              return arr;
        }
        for(int i=start;i<=end;i++)
        {
            ArrayList<Node> left=solve(start,i-1);
            ArrayList<Node> right=solve(i+1,end);
            

            
            for(int j=0;j<left.size();j++)
            {
                Node l=left.get(j);
                for(int k=0;k<right.size();k++)
                {
                    Node r=right.get(k);
                    Node node=new Node(i);
                    node.left=l;node.right=r;
                    arr.add(node);
                 

                }
            }
        }
        return arr;
    }
    static boolean check(int i,int p,ArrayList<Integer> arr)
    {
        for(int i1=1;i1<=arr.size();i1++)
        {
            int x=arr.get(i1-1);
            int x1=Math.abs(x-i);
            int y1=Math.abs(p-i1);
           

            if(x1==y1)
            return false;
            if(x==i)
            return false;
        }
        return true;
    }
  static  void put(int []a,int p,int n)
    {
        if(n==0)
        {
            a[0]=p;
            return;
        }
        int x=a[n-1];
        if(p>x)
        {
            a[n]=p;
            return;
        }
        else
        {
            put(a,p,n-1);
            a[n]=x;
        }
    }
  static  class byValue implements Comparator<Map.Entry<Integer,Integer>> {
    public int compare(Map.Entry<Integer,Integer> e1, Map.Entry<Integer,Integer> e2) {
        if ((int)e1.getValue() < (int)e2.getValue()){
            return 1;
        } else if ((int)e1.getValue() == (int)e2.getValue()) {
            return 0;
        } else {
            return -1;
        }
    }
}
   static class Student {
int a; 

static int b; 


  Student(){
   

   b++;
  }

   public void showData(){
      System.out.println("Value of a = "+a);
      System.out.println("Value of b = "+b);
   }







}

    public static boolean prime[] =new boolean[100000 + 1];
    public static int store[]=new int[100000+1];
    static void sieveOfEratosthenes(int n)
    {
        for (int i = 0; i <= n; i++)
            prime[i] = true;
 
        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }
        int k=0;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i] == true)
            {store[k]=i;k++;}
        }
    }
    
    
    static long gcd(long a, long b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
     
    

    static long lcm(long a, long b)
    {
        return (a / gcd(a, b)) * b;
    }
  }   