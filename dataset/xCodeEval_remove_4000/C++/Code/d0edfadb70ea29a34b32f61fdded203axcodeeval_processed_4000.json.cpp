






using namespace std;

int32_t main()
{
  IOS;
  int n, k; cin >> n >> k;
  vector<int> a(n), b(n);
  for(auto i=0;i<n;i++)
    cin >> a[i];
  b = a;
  int max_count = 1, count = 1;
  sort(b.begin(), b.end());
  for(auto i=1;i<n;i++)
  {
    if(b[i] == b[i-1])
    {
      count++;
      max_count = max_count>count?max_count:count; 
    }
    else
    {
      max_count = max_count>count?max_count:count;
      count = 1;
    }
     

  }
  

  

  

  

  

  

  

  

  

  

  if(max_count > k)
  {
    cout << "NO";
    return 0;
  }
  cout << "YES" << endl;
  if(k==n)
  {
    for(auto i=1;i<n+1;i++)
      cout << i << " ";
    return 0;
  }
  vector<int> col_val(n); int k_dash = 1;
  col_val[0] = 1;
  for(auto i=1;i<n;i++)
  {
    if(b[i] == b[i-1])
    {
      if(k_dash == k)
      {
        k_dash = 1;
        col_val[i] = k_dash;
      }
      else
        col_val[i] = ++k_dash;
    }
    else
    {
      if(k_dash == k)
        k_dash = 1;
      else
        k_dash++;
      col_val[i] = k_dash;
    }
  }
  vector<int> temp(n);
  temp = col_val;
  for(auto i=0;i<n;i++)
  {
    for(auto j=0;j<n;j++)
    {
      if(b[j] == a[i])
      {
        if(col_val[j] == 0)
          continue;
        temp[i] = col_val[j];
        col_val[j] = 0;
        break;
      }
    }
  }
  for(auto i=0;i<n;i++)
  {
    cout << temp[i] << " ";
  }
  return 0;
  
  
}