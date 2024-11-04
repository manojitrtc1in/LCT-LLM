import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.StringTokenizer;


public class id7 {

	
	private class Cell {


		private int row, col; 	






		Cell(int type,int row, int col) {


			this.row = row;
			this.col = col;




		}

		
		@Override
		public String toString() {


			return String.format("(%s, %s)", row, col);
		}









	}
	


	
	
	private int n, m, p;
	private Cell[][] roomArr;		

	private int[][] id4;	


	
	LinkedList<Integer>[] id2;

	
	Cell[][] id8;

	
	Cell destinationCell;

	
	@SuppressWarnings("unchecked")
	public id7() {
		try {
			BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));

            

            String line = rd.readLine();

            StringTokenizer tokenizer = new StringTokenizer(line);
            this.n = Integer.parseInt(tokenizer.nextToken());
            this.m = Integer.parseInt(tokenizer.nextToken());
            this.p = Integer.parseInt(tokenizer.nextToken());

            
            

            this.id2 = (LinkedList<Integer>[])new LinkedList<?>[this.p + 1];

            
            this.roomArr = new Cell[n][m];

            
            for (int i = 0; i < n; i++) {
            	line = rd.readLine();
            	tokenizer = new StringTokenizer(line);
            	for (int j = 0; j < m; j++) {
            		int id0 = Integer.parseInt(tokenizer.nextToken());
            		this.roomArr[i][j] = new Cell(id0, i, j);	


            		LinkedList<Integer> tempList = id2[id0];

            		
    				if (tempList == null) {
    					tempList = new LinkedList<>();
    					id2[id0] = tempList;
    				}
    				tempList.add(i * m + j);	


    				
    				if (id0 == this.p) {
    					this.destinationCell = this.roomArr[i][j];
    				}
            	}
            	

            }
            


            this.id4 = new int[n][m];
            for (int i = 0; i < id4.length; i++) {
            	Arrays.fill(id4[i], 99999999);
            }

            this.id8 = new Cell[p][];

            

            System.out.println(this.id3());

            rd.close();
		} catch (IOException ioe) {
			ioe.printStackTrace();
		}
	}

	private int id3() {
		
		Cell[] id1 = id8[0];
		if (id1 == null || id1.length == 0) {	

			id1 = id5(0, true);	

			id8[0] = id1;	

		}
		for (Cell cellWithChestType1 : id1) {
			id4[cellWithChestType1.row][cellWithChestType1.col] = cellWithChestType1.row + cellWithChestType1.col;
		}

		for (int i = 1; i < p; ++i) {
			Cell[] neighbors = id8[i];
			if (neighbors == null) {	

				neighbors = id5(i, true);	

				id8[i] = neighbors;	

			}

			Cell[] prevNeighbors = id8[i - 1];

			
			if (prevNeighbors.length * neighbors.length >= this.n * this.m) {
				this.id6(prevNeighbors, neighbors);
			
			} else {
				for (Cell neighbor : neighbors) {
					for (Cell prevNeighbor : prevNeighbors) {
						id4[neighbor.row][neighbor.col] = Math.min(id4[neighbor.row][neighbor.col],
								id4[prevNeighbor.row][prevNeighbor.col] + getDist(prevNeighbor, neighbor));
					}
				}
				

			}
			

		}
		

		return id4[this.destinationCell.row][this.destinationCell.col];
	}
	


	
	private void id6(Cell[] prevNeighbors, Cell[] neighbors) {
		
		int[][] distance = new int[n][m];
	    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++)
	        distance[i][j] = 99999999;

	    
	    for (Cell p : prevNeighbors)
	        distance[p.row][p.col] = id4[p.row][p.col];

	    
	    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
	        if (i+1 < n) distance[i + 1][j] = Math.min(distance[i + 1][j], distance[i][j] + 1);
	        if (j+1 < n) distance[i][j + 1] = Math.min(distance[i][j + 1], distance[i][j] + 1);
	    }

	    
	    for (int i = n-1; i >= 0; i--) for (int j = m-1; j >= 0; j--) {
	        if (i-1 >= 0) distance[i - 1][j] = Math.min(distance[i - 1][j], distance[i][j] + 1);
	        if (j-1 >= 0) distance[i][j - 1] = Math.min(distance[i][j - 1], distance[i][j] + 1);
	    }

	    
	    for (Cell cell : neighbors)
	        id4[cell.row][cell.col] = distance[cell.row][cell.col];
	}

	
















































































	


	











































	
	private Cell[] id5(int id0, boolean ascending) {
		
		LinkedList<Integer> neighborRooms = this.id2[ascending? id0 + 1 : id0 - 1];
		if (neighborRooms == null) {
			return new Cell[0];
		}
		Cell[] neighbors = new Cell[neighborRooms.size()];
		ListIterator<Integer> iter = neighborRooms.listIterator();
		for (int i = 0; i < neighbors.length; i++) {
			int thisRoom = iter.next();
			int thisRow = thisRoom / this.m;
			int thisCol = thisRoom % this.m;
			neighbors[i] = this.roomArr[thisRow][thisCol];
		}
		return neighbors;
	}

	private int getDist(Cell c1, Cell c2) {
		return Math.abs(c1.row - c2.row) + Math.abs(c1.col - c2.col);
	}

	









































































































































































	public static void main(String[] args) {
		new id7();


	}
}
