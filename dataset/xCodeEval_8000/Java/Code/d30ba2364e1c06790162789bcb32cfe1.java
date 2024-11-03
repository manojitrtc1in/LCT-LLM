import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{
































































		System.out.println(arrivalOfTheGeneral());
	}

	private static int arrivalOfTheGeneral()
	{
		Scanner scanner = new Scanner(System.in);
		int input = scanner.nextInt();
		List<Integer> soldiers = new ArrayList<Integer>();
		int max = 0;
		int min = Integer.MAX_VALUE;
		int seconds = 0;

		for (int i = 0; i < input; i++)
		{
			int temp = scanner.nextInt();
			soldiers.add(temp);
			if (temp > max)
			{
				max = temp;
			}
			if (temp < min)
			{
				min = temp;
			}
		}

		int minIndex = soldiers.lastIndexOf(min);
		int maxIndex = soldiers.indexOf(max);
		int maxTemp = 0;
		int minTemp = soldiers.size();




		while (maxIndex > 0 || minIndex < soldiers.size() - 1)
		{
			if (maxIndex != 0)
			{
				maxTemp = soldiers.get(soldiers.indexOf(max) - 1);
			}
			if (minIndex != soldiers.size() - 1)
			{
				minTemp = soldiers.get(soldiers.lastIndexOf(min) + 1);
			}

			if (maxIndex != 0 && (maxIndex - 1 != minIndex))
			{






				soldiers.set(maxIndex, maxTemp);
				soldiers.set(maxIndex - 1, max);
				maxIndex--;
				seconds++;




			}
			if (minIndex != soldiers.size() - 1 && (minIndex + 1 != maxIndex))
			{






				soldiers.set(minIndex, minTemp);
				soldiers.set(minIndex + 1, min);
				minIndex++;
				seconds++;




			}
			if (maxIndex - 1 == minIndex && minIndex + 1 == maxIndex)
			{




				soldiers.set(minIndex, max);
				soldiers.set(maxIndex, min);
				minIndex++;
				maxIndex--;
				seconds++;




			}
		}
		scanner.close();
		return seconds;
	}

	

	

	
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
}
