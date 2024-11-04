#include <iostream> 
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <deque>
#include <set>
using namespace std;
vector<pair<long long, long long>> summ;

long long main1(int a, string h, string h1)
{

#define int long long
	
	
	
	
	
	set<pair<int, int>> chet_minus;
	set<pair<int, int>> chet_plus;
	set<pair<int, int>> nechet_minus;
	set<pair<int, int>> nechet_plus;
	for (int d = 0; d < a; d++)
	{
		int plus= 9 - h[d] + 48;
		int minus = h[d] - 48;
		if ((d + 1) % 2 == 1)
		{
			pair<int, int> b;	
			b.first = d + 1;
			if (plus != 0)
			{
			
				b.second = plus;
				chet_plus.insert(b);
				nechet_minus.insert(b);
				
			}
			if (minus != 0)
			{
				b.second = minus;
				chet_minus.insert(b);
				nechet_plus.insert(b);	
				
			}
		}
		else
		{
			pair<int, int> b;
			b.first = d + 1;
			if (plus != 0)
			{
				
				b.second = plus;
				nechet_plus.insert(b);
				chet_minus.insert(b);
				
			}
			if (minus != 0)
			{
				b.second = minus;
				nechet_minus.insert(b);
				chet_plus.insert(b);
				
			}
		}
	}
	
	long long summa = 0;
	for (int y = 1; y < a; y++)
	{
		
		int number1 = h[y - 1] - 48;
		int number2 = h1[y -1] - 48;
		if (number1 > number2)
		{
			
			
			int need_minus = number1 - number2;
			if ((y) % 2 == 0)
			{
				
				
				while (need_minus != 0)
				{
					
					set<pair<int, int>>::iterator p = chet_minus.begin();
					if (p == chet_minus.end())
					{
						
						
						return -1;
					}

					if (p != chet_minus.end())
					{
						
						pair<int, int> l = *p;
						chet_minus.erase(chet_minus.begin());
						nechet_plus.erase(nechet_plus.begin());
						
						if (l.first > y)
						{
							
							if (l.second > need_minus)
							{
								summa = summa + need_minus * (y - l.first) * -1;
								if ((l.first - y) % 2 == 1)
								{
									
									h[l.first - 1] = h[l.first - 1] - need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = h[l.first - 1] + need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								

								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_minus;
								chet_minus.insert(pp);
								nechet_plus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;
								need_minus = 0;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_minus.erase(nechet_minus.find(r));
									chet_plus.erase(chet_plus.find(r));

								}
								r.second = 9 - pp.second;
								nechet_minus.insert(r);
								chet_plus.insert(r);
							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_minus = need_minus - l.second;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_minus.erase(nechet_minus.find(r));
									chet_plus.erase(chet_plus.find(r));
								}
								r.second = 9;
								nechet_minus.insert(r);
								chet_plus.insert(r);
							}
						}
						
						
					}
					
				}
				
			}
			
			
			else
			{
				
				while (need_minus != 0)
				{
					
					set<pair<int, int>>::iterator p = nechet_minus.begin();
					if (p == nechet_minus.end())
					{
					
						return -1;
					}
					if (p != nechet_minus.end())
					{
						

						pair<int, int> l = *p;
						nechet_minus.erase(nechet_minus.begin());
						chet_plus.erase(chet_plus.begin());
						if (l.first > y)
						{
							
							if (l.second > need_minus)
							{
								
								summa = summa + need_minus * (y - l.first) * -1;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = h[l.first - 1] - need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = h[l.first - 1] + need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								
								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_minus;
								nechet_minus.insert(pp);
								chet_plus.insert(pp);
								pair<int, int> r;
								need_minus = 0;
								r.first = pp.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_minus.erase(chet_minus.find(r));
									nechet_plus.erase(nechet_plus.find(r));

								}
								r.second = 9 - pp.second;
								chet_minus.insert(r);
								nechet_plus.insert(r);
							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_minus = need_minus - l.second;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_minus.erase(chet_minus.find(r));
									nechet_plus.erase(nechet_plus.find(r));
								}
								r.second = 9;
								chet_minus.insert(r);
								nechet_plus.insert(r);
							}
						}
						
					}
						
					
				}

			}
			
		}
		if(number1 < number2)
		{
			
			int need_plus = number2 - number1;
			if ((y) % 2 == 0)
			{
				
			
				while (need_plus != 0)
				{
					
					set<pair<int, int>>::iterator p = chet_plus.begin();
					
					if (p == chet_plus.end())
			        {
						
				   
					return -1;
			        }
					if (p != chet_plus.end())
					{
						
						pair<int, int> l = *p;
						chet_plus.erase(chet_plus.begin());
						nechet_minus.erase(nechet_minus.begin());
						if (l.first > y)
						{
							
							
							
							if (l.second > need_plus)
							{
								
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = h[l.first - 1] + need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = h[l.first - 1] - need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								summa = summa + need_plus * (y - l.first) * -1;
								
								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_plus;
								chet_plus.insert(pp);
								nechet_minus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;
								need_plus = 0;

								if (l.second != 9)
								{
									r.second = 9 - l.second;

									nechet_plus.erase(nechet_plus.find(r));

									chet_minus.erase(chet_minus.find(r));

								}
								r.second = 9 - pp.second;
								nechet_plus.insert(r);
								chet_minus.insert(r);
								
							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_plus = need_plus - l.second;
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_plus.erase(nechet_plus.find(r));
									chet_minus.erase(chet_minus.find(r));
								}
								r.second = 9;
								nechet_plus.insert(r);
								chet_minus.insert(r);
								
								if ((l.first - y) % 2 == 1)
								{
									h[r.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									
									h[r.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
							}

						}
					}
						
					
				}
			
				
			}
			else
			{
				while (need_plus != 0)
				{
					
					set<pair<int, int>>::iterator p = nechet_plus.begin();
					if (p == nechet_plus.end())
					{
					
						
					
						return -1;
					
					}
					if (p != nechet_plus.end())
					{
						pair<int, int> l = *p;
						nechet_plus.erase(nechet_plus.begin());
						chet_minus.erase(chet_minus.begin());
						if (l.first > y)
						{
							
							if (l.second > need_plus)
							{
								summa = summa + need_plus * (y - l.first) * -1;
								if ((l.first - y) % 2 == 1)
								{
									
									h[l.first - 1] = h[l.first - 1] + need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									
									h[l.first - 1] = h[l.first - 1] - need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								
								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_plus;
								nechet_plus.insert(pp);
								chet_minus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;
								need_plus = 0;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_plus.erase(chet_plus.find(r));
									nechet_minus.erase(nechet_minus.find(r));

								}
								r.second = 9 - pp.second;
								chet_plus.insert(r);
								nechet_minus.insert(r);
								
							}
							else

							{

								summa = summa + l.second * (y - l.first) * -1;
								need_plus = need_plus - l.second;
								
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									
									chet_plus.erase(chet_plus.find(r));

									nechet_minus.erase(nechet_minus.find(r));
								}
								r.second = 9;
								chet_plus.insert(r);
								nechet_minus.insert(r);
								
								if ((l.first - y) % 2 == 1)
								{
									h[r.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									
									h[r.first - 1] = '0';
									
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
							}
							

						}
						
					}
						
					
				}

			}

        }
	}
	
	if (h[a - 1] != h1[a - 1])
	{
		
		return -1;
	}
	return summa;
	
}


vector<pair<int, int>> summ1;
#define int int
long long main2(int a, string h, string h1)
{
#define int long long



	


	set<pair<int, int>> chet_minus;
	set<pair<int, int>> chet_plus;
	set<pair<int, int>> nechet_minus;
	set<pair<int, int>> nechet_plus;
	for (int d = 0; d < a; d++)
	{
		int plus = 9 - h[d] + 48;
		int minus = h[d] - 48;
		if ((d + 1) % 2 == 1)
		{
			pair<int, int> b;
			b.first = d + 1;
			
			if (plus != 0)
			{
				
				b.second = plus;
				chet_plus.insert(b);
				nechet_minus.insert(b);

			}
			if (minus != 0)
			{
				b.second = minus;
				chet_minus.insert(b);
				nechet_plus.insert(b);

			}
		}
		else
		{
			pair<int, int> b;
			b.first = d + 1;
			if (plus != 0)
			{
				
				b.second = plus;
				nechet_plus.insert(b);
				chet_minus.insert(b);

			}
			if (minus != 0)
			{
				b.second = minus;
				nechet_minus.insert(b);
				chet_plus.insert(b);

			}
		}
	}

	long long summa = 0;
	for (int y = 1; y < a; y++)
	{
		
		int number1 = h[y - 1] - 48;
		int number2 = h1[y - 1] - 48;
		if (number1 > number2)
		{


			int need_minus = number1 - number2;
			if ((y) % 2 == 0)
			{


				while (need_minus != 0)
				{

					set<pair<int, int>>::iterator p = chet_minus.begin();
					if (p == chet_minus.end())
					{
						

						return -1;
					}

					if (p != chet_minus.end())
					{

						pair<int, int> l = *p;
						chet_minus.erase(chet_minus.begin());
						nechet_plus.erase(nechet_plus.begin());

						if (l.first > y)
						{

							if (l.second > need_minus)
							{
								summa = summa + need_minus * (y - l.first) * -1;
								if ((l.first - y) % 2 == 1)
								{
									
									h[l.first - 1] = h[l.first - 1] - need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = h[l.first - 1] + need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
							

								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_minus;
								chet_minus.insert(pp);
								nechet_plus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;
								need_minus = 0;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_minus.erase(nechet_minus.find(r));
									chet_plus.erase(chet_plus.find(r));

								}
								r.second = 9 - pp.second;
								nechet_minus.insert(r);
								chet_plus.insert(r);
							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_minus = need_minus - l.second;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}

								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_minus.erase(nechet_minus.find(r));
									chet_plus.erase(chet_plus.find(r));
								}
								r.second = 9;
								nechet_minus.insert(r);
								chet_plus.insert(r);
							}
						}


					}

				}

			}


			else
			{

				while (need_minus != 0)
				{

					set<pair<int, int>>::iterator p = nechet_minus.begin();
					if (p == nechet_minus.end())
					{
						
						return -1;
					}
					if (p != nechet_minus.end())
					{


						pair<int, int> l = *p;
						nechet_minus.erase(nechet_minus.begin());
						chet_plus.erase(chet_plus.begin());
						if (l.first > y)
						{

							if (l.second > need_minus)
							{

								summa = summa + need_minus * (y - l.first) * -1;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = h[l.first - 1] - need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									summ;
									h[l.first - 1] = h[l.first - 1] + need_minus;
									for (int r = 0; r < need_minus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								pair<int, int> pp;
								pp.second = l.second - need_minus;
								need_minus = 0;
								
								pp.first = l.first;
								
								nechet_minus.insert(pp);
								chet_plus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_minus.erase(chet_minus.find(r));
									nechet_plus.erase(nechet_plus.find(r));

								}
								r.second = 9 - pp.second;
								chet_minus.insert(r);
								nechet_plus.insert(r);
							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_minus = need_minus - l.second;
								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_minus.erase(chet_minus.find(r));
									nechet_plus.erase(nechet_plus.find(r));
								}
								r.second = 9;
								chet_minus.insert(r);
								nechet_plus.insert(r);
							}
						}

					}


				}

			}

		}
		if (number1 < number2)
		{

			int need_plus = number2 - number1;
			if ((y) % 2 == 0)
			{


				while (need_plus != 0)
				{

					set<pair<int, int>>::iterator p = chet_plus.begin();

					if (p == chet_plus.end())
					{

						
						return -1;
					}
					if (p != chet_plus.end())
					{

						pair<int, int> l = *p;
						chet_plus.erase(chet_plus.begin());
						nechet_minus.erase(nechet_minus.begin());
						if (l.first > y)
						{



							if (l.second > need_plus)
							{

								if ((l.first - y) % 2 == 1)
								{
									h[l.first - 1] = h[l.first - 1] + need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									h[l.first - 1] = h[l.first - 1] - need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								summa = summa + need_plus * (y - l.first) * -1;
								pair<int, int> pp;
								pp.second = l.second - need_plus;
								need_plus = 0;
								
								pp.first = l.first;
								
								chet_plus.insert(pp);
								nechet_minus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;

								if (l.second != 9)
								{
									r.second = 9 - l.second;

									nechet_plus.erase(nechet_plus.find(r));

									chet_minus.erase(chet_minus.find(r));

								}
								r.second = 9 - pp.second;
								nechet_plus.insert(r);
								chet_minus.insert(r);

							}
							else
							{
								summa = summa + l.second * (y - l.first) * -1;
								need_plus = need_plus - l.second;
								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;
									nechet_plus.erase(nechet_plus.find(r));
									chet_minus.erase(chet_minus.find(r));
								}
								r.second = 9;
								nechet_plus.insert(r);
								chet_minus.insert(r);

								if ((l.first - y) % 2 == 1)
								{
									h[r.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{

									h[r.first - 1] = '0';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
							}

						}
					}


				}


			}
			else
			{
				while (need_plus != 0)
				{

					set<pair<int, int>>::iterator p = nechet_plus.begin();
					if (p == nechet_plus.end())
					{

						

						return -1;

					}
					if (p != nechet_plus.end())
					{
						pair<int, int> l = *p;
						nechet_plus.erase(nechet_plus.begin());
						chet_minus.erase(chet_minus.begin());
						if (l.first > y)
						{

							if (l.second > need_plus)
							{summa = summa + need_plus * (y - l.first) * -1;

								if ((l.first - y) % 2 == 1)
								{
									
									h[l.first - 1] = h[l.first - 1] + need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{
									
									h[l.first - 1] = h[l.first - 1] - need_plus;
									for (int r = 0; r < need_plus; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								
								pair<int, int> pp;
								pp.first = l.first;
								pp.second = l.second - need_plus;
                                need_plus = 0;
								nechet_plus.insert(pp);
								chet_minus.insert(pp);
								pair<int, int> r;
								r.first = pp.first;

								if (l.second != 9)
								{
									r.second = 9 - l.second;
									chet_plus.erase(chet_plus.find(r));
									nechet_minus.erase(nechet_minus.find(r));

								}
								r.second = 9 - pp.second;
								chet_plus.insert(r);
								nechet_minus.insert(r);

							}
							if (l.second <= need_plus)
							{

								summa = summa + l.second * (y - l.first) * -1;
								need_plus = need_plus - l.second;

								pair<int, int> r;
								r.first = l.first;
								if (l.second != 9)
								{
									r.second = 9 - l.second;

									chet_plus.erase(chet_plus.find(r));

									nechet_minus.erase(nechet_minus.find(r));
								}
								r.second = 9;
								chet_plus.insert(r);
								nechet_minus.insert(r);

								if ((l.first - y) % 2 == 1)
								{
									h[r.first - 1] = '9';
									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = 1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
								else
								{

									h[r.first - 1] = '0';

									for (int r = 0; r < l.second; r++)
									{
										int number = l.first - 1;
										int bite = -1;
										while (number != y - 1 && summ1.size() <= 100000)
										{
											pair<int, int> ji;
											ji.first = number;
											ji.second = bite;
											summ1.push_back(ji);
											bite = -1 * bite;
											number--;
										}
									}
								}
							}


						}

					}


				}

			}

		}
	}

	if (h[a - 1] != h1[a - 1])
	{
		
		return -1;
		
	}
	return summa;
	
}
#define int int
int main()
{
	
	int a;
	cin >> a;
	string h;
	string h1;
	cin >> h;
	cin >> h1;
	
	long long i1 = main1(a, h, h1);

	reverse(h.begin(), h.end());
	reverse(h1.begin(), h1.end());
	long long i2 = main2(a, h, h1);
	
	if (i1 != -1 && i2 == -1)
	{
		cout << i1 << endl;
		for (int v = 0; v < min(i1, (long long) 100000); v++)
		{
			cout << summ[v].first << " " << summ[v].second << endl;
		}
	}
	if (i1 == -1 && i2 != -1)
	{
		cout << i2 << endl;;
		for (int v = 0; v < min(i2, (long long)100000); v++)
		{
			cout << a - summ1[v].first << " " << summ1[v].second << endl;
		}
	}
	if (i1 != -1 && i2 != -1)
	{
		if (i1 <= i2)
		{
			cout << i1 << endl;
			for (int v = 0; v < min(i1, (long long)100000); v++)
			{
				cout << summ[v].first << " " << summ[v].second << endl;
			}
		}
		else
		{
			cout << i2 << endl;
			for (int v = 0; v < min(i2, (long long)100000); v++)
			{
				cout << a- summ1[v].first << " " << summ1[v].second << endl;
			}
		}
	}
	if (i1 == -1 && i2 == -1)
	{
		cout << -1 << endl;
	}
}