






























































using namespace std;

int id1(string& str, int cur)
{
	int res = 0;
	bool found = false;
	for (int i = cur + 1; i < str.length(); ++i)
	{
		if (str[i] == '0')
			++res;
		if (str[i] == '1')
		{
			found = true;
			break;
		}
	}
	if (found)
		return res;
	else
		return -1;
}

int id2(string& str, int cur1)
{
	int res = 0;
	for (int i = cur1; i < str.length(); ++i)
	{
		if (str[i] == '1')
			++res;
		else
			break;
	}
	return res;
}
int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;
		string str;
		cin >> str;
		bool found1 = false;
		unsigned int cost = 0;
		bool id0 = false;
		for (int j = 0; j < str.length(); ++j)
		{
			if (str[j] == '0')
			{
				if (found1)
				{
					if (id0)
					{
						

						int z = id1(str, j);
						if (z != -1)
						{
							int id3 = (z + 1) * b;
							if (id3 < a)
							{
								cost += id3;
								j += (z + 1);
							}
							else
							{
								id0 = false;
							}
						}
					}
					else
					{
						

						

						id0 = false;
					}
				}
			}
			else 

			{
				if (found1)
				{
					if (id0)
					{
						

					}
					else
					{
						

						id0 = true;
						cost += a;
					}
				}
				else
				{
					found1 = true;
					id0 = true;
					cost += a;
				}
			}
			
		}
		cout << cost << endl;
	}
	return 0;
}

















































































































































































































































































































































































































































































































































































































































































































































	

	

	

	

	

	

	

	

	

 

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	




















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































