

using namespace std;
int main()
{
	int a, b;
	cin >> a >>b;
	int count = 0;
	char c[50][50];
	int row, cow;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < b; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == 'S')
			{
				row = i;
				cow = j;
			}
		}
	string d;
	cin >> d;
	int k;
	int len = d.size();
	int ro = row;
	int co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
    co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	} 
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			co++;
			if (co > b - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			co--;
			if (co < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else if (d[k] == '2')
		{
			co--;
			if (co < 0)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro--;
			if (ro < 0)
				break;
		}
		else
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	ro = row;
	co = cow;
	k = 0;
	for (int i = 0; i < len; i++)
	{
		if (d[k] == '0')
		{
			co++;
			if (co > b - 1)
				break;
		}
		else if (d[k] == '1')
		{
			co--;
			if (co < 0)
				break;
		}
		else if (d[k] == '2')
		{
			ro++;
			if (ro > a - 1)
				break;
		}
		else
		{
			ro--;
			if (ro < 0)
				break;
		}
		if (c[ro][co] == 'E')
		{
			count++;
			break;
		}
		else if (c[ro][co] == '
			break;
		k++;
	}
	cout << count << endl;
	return 0;
}