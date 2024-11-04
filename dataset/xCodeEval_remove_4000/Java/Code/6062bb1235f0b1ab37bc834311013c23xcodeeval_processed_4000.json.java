import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {

	public B() 
	{
		Scanner s = new Scanner();
	
		
		long n = s.nextLong();
		long xMin = Integer.MAX_VALUE;
		long xMax = Integer.MIN_VALUE;
		long yMin = Integer.MAX_VALUE;
		long yMax = Integer.MIN_VALUE;
		for (int i = 0; i < n; i++)
		{
			int x = s.nextInt();
			int y = s.nextInt();
			if (x > xMax)
				xMax = x;
			if (x < xMin)
				xMin = x;
			if (y > yMax)
				yMax = y;
			if (y < yMin)
				yMin = y;
		}
		long max = Long.max(xMax - xMin, yMax - yMin);
		System.out.println(max * max);
		
		
	}
	
	
	
	public static void main(String[] args) {
		new B();
	}

	public static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		public Scanner(Reader in) {
			br = new BufferedReader(in);
		}

		public Scanner() {
			this(new InputStreamReader(System.in));
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

		

		

		

		String id8() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

		public int[] id11(int id2) {
			int[] ints = new int[id2];
			for (int i = 0; i < id2; i++)
				ints[i] = nextInt();
			return ints;
		}
		
		public double[] id10(int id4) {
			double[] doubles = new double[id4];
			for (int i = 0; i < id4; i++)
				doubles[i] = nextDouble();
			return doubles;
		}
		

	}

	
	public boolean isPrime(int n)
	{
		for (int i = 2; i <= Math.sqrt(n);i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
	
	
	public ArrayList<Integer> id14(int n)
	{
		ArrayList<Integer> primes = new ArrayList<Integer>();
		
		int id13 = 2;
		
		while (primes.size() < n)
		{
			boolean prime = true;
			for (int i = 0; i < primes.size() && primes.get(i) <= Math.sqrt(id13); i++)
			{
				if (id13 % primes.get(i) == 0)
					prime = false;
			}
			if (prime)
			{
				primes.add(id13);
				System.out.println(id13);
			}
			id13++;
		}
		return primes;
	}
	
	public class Loc implements Comparable<Loc>, Cloneable
	{
		public int x, y;
		public Loc(int x, int y)
		{
			this.x = x;
			this.y = y;
		}
		
		public int compareTo(Loc other) {
			return this.x - other.x;
		}
		
		public boolean equals(Object other)
		{
			return other instanceof Loc && ((Loc)other).x == this.x
					&& ((Loc)other).y == this.y;
		}
		
		public Loc clone()
		{
			return new Loc(this.x, this.y);
		}
		
		public String toString()
		{
			return x + " " + y;
		}
	}
	
	








	
	
	
	public ArrayList<Integer> id1(ArrayList<Integer> ints)
	{
		ArrayList<Integer> toReturn = new ArrayList<Integer>();
		if (ints.size() == 0)
			return toReturn;
		toReturn.add(ints.get(0));
		for (int i = 1; i < ints.size(); i++)
			if (ints.get(i) > ints.get(i - 1))
				toReturn.add(ints.get(i));
			else
				break;
		return toReturn;
	}
	
	
	
	public ArrayList<Integer> id0(ArrayList<Integer> ints)
	{
		ArrayList<Integer> toReturn = new ArrayList<Integer>();
		if (ints.size() == 0)
			return toReturn;
		toReturn.add(0, ints.get(ints.size() - 1));
		for (int i = ints.size() - 2; i >= 0; i--)
		{
			if (ints.get(i) > ints.get(i + 1))
			{	
				toReturn.add(0, ints.get(i));
			}
			else
				break;
		}
		return toReturn;
	}
	
	
	public ArrayList<Integer> id7(ArrayList<Integer> ints)
	{
		ArrayList<Integer> toReturn = new ArrayList<Integer>();
		if (ints.size() == 0)
			return toReturn;
		toReturn.add(ints.get(0));
		for (int i = 1; i < ints.size(); i++)
			if (ints.get(i) >= ints.get(i - 1))
				toReturn.add(ints.get(i));
			else
				break;
		return toReturn;
	}
	
	public ArrayList<Integer> id9(ArrayList<Integer> ints)
	{
		ArrayList<Integer> toReturn = new ArrayList<Integer>();
		if (ints.size() == 0)
			return toReturn;
		toReturn.add(0, ints.get(ints.size() - 1));
		for (int i = ints.size() - 2; i >= 0; i--)
		{
			if (ints.get(i) >= ints.get(i + 1))
			{	
				toReturn.add(0, ints.get(i));
			}
			else
				break;
		}
		return toReturn;
	}
	
	public class BST<T extends Comparable<? super T>> 
	{
	    class BinaryNode 
	    {
	    	T element; 

			BinaryNode left; 

			BinaryNode right; 

	       

	       

	       

	       

	       

	       public BinaryNode( T elem ) 
	       {
	    	   this.element = elem;
	    	   this.left = null;
	    	   this.right = null;
	       }
	       

	       

	       

	       

	       

	       public BinaryNode( T elem, BinaryNode lt, BinaryNode rt ) 
	       {
	    	   this.element = elem;
	    	   this.left = lt;
	    	   this.right = rt;
	       }
	       
	       
	       private void removeLeft()
	       {
	    	   BinaryNode newLeft = null;

	    	   if (left.right != null && left.left == null)
	    		   

				   

	    		   

	    		   

	    	   {   
	    		   newLeft = left.right;
	    	   }
	    	   else if (left.left != null && left.right == null)

	    	   {
	    		   newLeft = left.left;
	    	   }
	    	   else if (left.left != null && left.right != null)

	    	   {
	    		   

	    		   

	    		   if (left.right.left == null)
	    		   {
	    			   newLeft = left.right;
	    			   newLeft.left = left.left;
	    		   }
	    		   else
	    		   {
	    			   newLeft = left.right.id3();
	    			   newLeft.left = left.left;
	    			   newLeft.right = left.right;
	    		   }
	    	   }
			   left.id5();

			   left = newLeft;

			   

	       }
	       
	       
	       private void removeRight()
	       {
	    	   BinaryNode newRight = null;

	    	   
	    	   if (right.right != null && right.left == null)
	    		   

	    		   

	    	   {   
	    		   newRight = right.right;
	    	   }
	    	   else if (right.left != null && right.right == null)

	    	   {
	    		   newRight = right.left;
	    	   }
	    	   else if (right.right != null && right.left != null)
	    		   

	    	   {
	    		   

	    		   

	    		   if (right.right.left == null)
	    		   {
	    			   newRight = right.right;
	    			   newRight.left = right.left;
	    		   }
	    		   else

	    		   {
	    			   newRight = right.right.id3();
	    			   newRight.left = right.left;
	    			   newRight.right = right.right;
	    		   }
	    	   }
			   right.id5();

			   right = newRight;

			   

	       }
	       
	       
	       private BinaryNode id3()
	       {
	    	   if (left.left == null)

	    	   {
	    		   	BinaryNode leftRef = left;

	    		    left = left.right; 

	    		    return leftRef;
	    	   }
	    	   return left.id3();

	       }
	     
	       
	       private void id5()
	       {
	    	   	left = null;
	    	   	element = null;
	   			if (id12 < pSize)

	   			{
	   				right = pool;
	   				pool = this;
	   				id12++;

	   			}
	   			else
	   			{
	   				right = null;
	   			}
	       }
	    }

	    BinaryNode root;        

	    BinaryNode pool;        

	    int        pSize;       

	    private int id12; 


	    

	    

	    

	    

	    public BST( )
	    {
	    	root = null;
	    	pool = null;
	    	pSize = 0;
	    	this.id12 = 0;
	    }

	    

	    

	    

	    

	    public BST( int Sz ) 
	    {
	    	root = null;
	    	pool = null;
	    	pSize = Sz;
	    	this.id12 = 0;
	    }

	    

	    

	    

	    public boolean isEmpty( ) 
	    {
	    	return root == null;
	    }

	    

	    

	    

	    

	    

	    public T find( T x ) 
	    {
	    	return this.findHelper(x, root);

	    }
	    
	    
	    private T findHelper(T x, BinaryNode current)
	    {
	    	if (current == null)

	    		return null;
	    	int result = x.compareTo(current.element);
	    	if (result < 0)

				return findHelper(x, current.left);
			else if (result > 0)

				return findHelper(x, current.right);
			else

				return current.element;	
	    }

	    

	    

	    

	    

	    public boolean insert( T x ) 
	    {
	    	

	    	if (root == null)
	    		root = id6(x);
	    	return insertHelper(x, root, null);

	    }
	    
	    private boolean insertHelper(T x, BinaryNode current, BinaryNode previous)
	    {
	    	int result = x.compareTo(current.element);
	    	if (result < 0)

	    	{
	    		if (current.left == null)

	    		{
	    			current.left = id6(x);
	    			return true;
	    		}
	    		else

	    		{
	    			return insertHelper(x, current.left, current);
	    		}
	    	}
			else if (result > 0)

			{
				if (current.right == null)

	    		{
	    			current.right = id6(x);
	    			return true;
	    		}
	    		else

	    		{
	    			return insertHelper(x, current.right, current);
	    		}
			}
			else 

				return false;	
	    }
	    
	    
	    private BinaryNode id6(T x)
	    {
	    	BinaryNode current;
	    	if (this.pool != null)
			{
				current = pool;

				pool = pool.right;

				current.right = null;

				current.element = x;
				id12--;
			}
			else 

			{
				current = new BinaryNode(x);
			}
	    	return current;
	    }

	    

	    

	    

	    

	    public boolean remove( T x ) 
	    {
	    	if (root == null)

	    		return false;
	    	int compareRes = x.compareTo(root.element);
	    	if (compareRes == 0)

	    	{
	    		BinaryNode top = new BinaryNode(null);
	    		top.left = root; 

	    		top.removeLeft();

	    		root = top.left;

	    		top.left = null;

	    		return true;
	    		
	    		














	    	}
	    	return removeHelper(x, root);

	    }
	    
	    
	    private boolean removeHelper(T x, BinaryNode parent)
	    { 
	    	

	    	
	    	int result = x.compareTo(parent.element);
	    	if (result < 0)

	    	{
	    		if (parent.left == null)
	    			return false; 

	    		if (x.compareTo(parent.left.element) == 0)

	    		{
	    			parent.removeLeft();
	    			return true;
	    		}
	    		return removeHelper(x, parent.left);

	    	}
			else if (result > 0)

			{
	    		if (parent.right == null)
	    			return false; 

	    		if (x.compareTo(parent.right.element) == 0)

	    		{
	    			parent.removeRight();

	    			return true;
	    		}
	    		return removeHelper(x, parent.right);

			}
	    	
	    	
	    	return false;
	    }
	    


	    

	    

	    

	    

	    

	    public void cap( T x ) 
	    {
	    	root = capHelper(x, root);

	    }
	    
	    
	    private BinaryNode capHelper( T x, BinaryNode current)
	    {
	    	if (current == null)

	    		return null;
	    	int result = current.element.compareTo(x);
	    	
	    	
	    	if (result > 0)
	    	{ 
	    		return capHelper(x, current.left);
	    	}
	    	else

	    	{
	    		current.right = capHelper(x, current.right);
	    		return current;
	    	}
	    }

	    

	    

	    

	    public void clear( ) 
	    {
	    	root = null;

	    }

	    

	    

	    

	    

	    

	    

	    @SuppressWarnings("unchecked")
		public boolean equals(Object other) 
	    {
	    	if (other == null)

	    		return false;
	    	
	    	
	    	if (!this.getClass().equals(other.getClass()))
	    		return false;
	    	
	    	return equalsHelper(this.root, ((BST<T>)other).root);

	    }
	    
	    
	    private boolean equalsHelper(BinaryNode current1, BinaryNode current2)
	    {
	    	if (current1 == null && current2 == null)

	    		return true;
	    	

	    	if ((current1 == null && current2 != null) || 
	    		(current1 != null && current2 == null) || 
	    		!current1.element.equals(current2.element))
	    		return false;
	    	return equalsHelper(current1.left, current2.left) && 

	    			equalsHelper(current1.right, current2.right);
	    }

	    

	    

	    

	    public int levels() 
	    {
	    	return levelsHelper(root);
	    }
	    
	    
	    private int levelsHelper(BinaryNode current)
	    {
	    	if (current == null)

	    		return 0;
	    	

	    	return Integer.max(levelsHelper(current.left), levelsHelper(current.right)) + 1;
	    }
}}
