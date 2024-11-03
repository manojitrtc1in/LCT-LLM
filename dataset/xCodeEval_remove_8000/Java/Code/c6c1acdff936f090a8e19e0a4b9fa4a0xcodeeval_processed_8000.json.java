import java.util.*; 
public class D_639{
public static void main(String[] args)
{
   Scanner omkar = new Scanner(System.in);
   int n = omkar.nextInt();
   int m = omkar.nextInt();
   int[][] grid = new int[n][m];
   String st;
   char g;
   for(int i = 0; i < n; i++)
   {
      st = omkar.next();
      for(int j = 0; j < m; j++)
      {
         if(st.charAt(j) == '
         {
            grid[i][j] = 1;
         }
         else
         {
            grid[i][j] = 0;
         }
      }
   } 
   
   if(!id2(grid))
   {
      System.out.println("-1");
      return;
   }
   if(!id1(grid))
   {
      System.out.println("-1");
      return;
   }
   int first = -1;
   int last = -1;
   int count = 0;
   int firstTemp, lastTemp;
   for(int i = 0; i < grid.length; i++)
   {
      firstTemp = -1;
      lastTemp = -1;
      for(int j = 0; j < grid[0].length; j++)
      {
         if(grid[i][j] == 1)
         {
            if(firstTemp == -1)
            {
               firstTemp = j;
            }
            lastTemp = j;
         }  
      }
      if(firstTemp > -1 && (firstTemp > last || lastTemp < first)) 
      {
         count++;
      }
      first = firstTemp;
      last = lastTemp;
   }
   System.out.println(""+count);
   
   }
   public static boolean id2(int[][] grid)
   {
      boolean black = false;
      boolean white = false;
      for(int i = 0; i < grid.length; i++)
      {
         black = false;
         white = false;
         for(int j = 0; j < grid[0].length; j++)
         {
            if(grid[i][j] == 1 && !white)
            {
               black = true;
            }
            else if(grid[i][j] == 1 && white)
            {
               return false;
            }
            else if(grid[i][j] == 0 && black)
            {
               white = true;
            }
         }
      }
      for(int i = 0; i < grid[0].length; i++)
      {
         black = false;
         white = false;
         for(int j = 0; j < grid.length; j++)
         {
            if(grid[j][i] == 1 && !white)
            {
               black = true;
            }
            else if(grid[j][i] == 1 && white)
            {
               return false;
            }
            else if(grid[j][i] == 0 && black)
            {
               white = true;
            }
         }
      }
      return true;
   
   }
   public static boolean id1(int[][] grid)
   {
      boolean a = id0(grid);
      boolean b = id3(grid);
      if(a && b)
      {
         return true;
      }
      if(!a && !b)
      {
         return true;
      }
      return false;
   }
   public static boolean id0(int[][] grid)
   {
      for(int i = 0; i < grid.length; i++)
      {
         if(rowEmpty(grid, i))
         {
            return true;
         }
      }
      return false;
   }
   public static boolean id3(int[][] grid)
   {
      for(int i = 0; i < grid[0].length; i++)
      {
         if(colEmpty(grid, i))
         {
            return true;
         }
      }
      return false;
   }
   public static boolean rowEmpty(int[][] grid, int i)
   {
      for(int j = 0; j < grid[0].length; j++)
      {
         if(grid[i][j] == 1)
         {
            return false;
         }
      }
      return true;
   }
   public static boolean colEmpty(int[][] grid, int i)
   {
      for(int j = 0; j < grid.length; j++)
      {
         if(grid[j][i] == 1)
         {
            return false;
         }
      }
      return true;
   }
      }
      
      
























