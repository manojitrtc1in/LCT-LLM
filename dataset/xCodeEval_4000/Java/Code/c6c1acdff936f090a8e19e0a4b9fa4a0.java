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
         if(st.charAt(j) == '#')
         {
            grid[i][j] = 1;
         }
         else
         {
            grid[i][j] = 0;
         }
      }
   } 
   
   if(!bwb_check(grid))
   {
      System.out.println("-1");
      return;
   }
   if(!row_col_check(grid))
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
   public static boolean bwb_check(int[][] grid)
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
   public static boolean row_col_check(int[][] grid)
   {
      boolean a = existsEmptyRow(grid);
      boolean b = existsEmptyCol(grid);
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
   public static boolean existsEmptyRow(int[][] grid)
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
   public static boolean existsEmptyCol(int[][] grid)
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
      
      
























