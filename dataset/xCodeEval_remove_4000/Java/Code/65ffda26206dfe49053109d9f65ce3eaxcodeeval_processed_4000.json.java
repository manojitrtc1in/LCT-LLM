import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main
{

	public static void main(String[] args)
	{




























































		System.out.println(id0());


	}

	

	private static String id0()
	{
		Scanner scanner = new Scanner(System.in);
		int id1 = scanner.nextInt();
		String order = "";
		List<String> rats = new ArrayList<String>();
		List<String> womenChildren = new ArrayList<String>();
		List<String> men = new ArrayList<String>();
		List<String> captains = new ArrayList<String>();

		for (int i = 0; i <= id1; i++)
		{
			String input = scanner.nextLine();
			if (input.contains(" rat"))
			{
				rats.add(input);
			}
			if (input.contains(" woman") || input.contains(" child"))
			{
				womenChildren.add(input);
			}
			if (input.contains(" man"))
			{
				men.add(input);
			}
			if (input.contains(" captain"))
			{
				captains.add(input);
			}
		}



		for (int i = 0; i < rats.size(); i++)
		{
			order += rats.get(i).replace(" rat", "\n");
		}
		for (int i = 0; i < womenChildren.size(); i++)
		{
			if (womenChildren.get(i).contains(" woman"))
			{
				order += womenChildren.get(i).replace(" woman", "\n");
			} else
			{
				order += womenChildren.get(i).replace(" child", "\n");
			}
		}
		for (int i = 0; i < men.size(); i++)
		{
			order += men.get(i).replace(" man", "\n");
		}
		for (int i = 0; i < captains.size(); i++)
		{
			order += captains.get(i).replace(" captain", "\n");
		}

		scanner.close();
		return order.trim();
	}

	
	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	
}
