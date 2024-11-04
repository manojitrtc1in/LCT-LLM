









using namespace std;




struct Set
{
  int *array;
  int cap;
};

class myset
{
  public: myset(){}

  private:
  set<int> internal_set;

};

int a;






















































































void log_insert(struct Set *seti, int left, int right, int key, int& size, int capacity)
{
  if (left == right)
  {
    if (key > seti->array[right])
    {
      if (!seti->cap)
      {
        seti->cap=(1<<22);
        int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
        seti->array = tmp;
      }
      else if (size+1>seti->cap)
      {
        seti->cap *= 2;
        int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
        seti->array = tmp;
      }
      memmove(seti->array+right+2, seti->array+right+1, sizeof(int) * (size-1-right));
      seti->array[right+1] = key;
      size++;
      return;
    }
    else
    {
      

      

      



      if (!seti->cap)
      {
        seti->cap=(1<<22);
        int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
        seti->array = tmp;
      }
      else if (size+1>seti->cap)
      {
        seti->cap *= 2;
        int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
        seti->array = tmp;
      }
      memmove(seti->array+left+1, seti->array+left, sizeof(int)* (size-left));
      seti->array[left]=key;
      size++;
      return;
    }
  }

  if (left>right)
  {
    

    if (!seti->cap)
    {
      seti->cap=(1<<22);
      int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
      seti->array = tmp;
    }
    else if (size+1>seti->cap)
    {
      seti->cap *= 2;
      int *tmp = (int *)realloc(seti->array, (seti->cap) * sizeof(int));
      seti->array = tmp;
    }
    seti->array[left] = key;
    size++;
    return;
    

  }

  int middle = (left + right)/2;

  if (key > seti->array[middle])
  {
    return log_insert(seti, middle + 1, right, key, size, capacity);
  }
  else
  {
    return log_insert(seti, left, middle, key, size, capacity);
  }
}

int id11(int *array, int left, int right, int size, int key)
{
  if(!array) return 0;

  if (left >= right)
  {
    if (array[left] == key)
      return left;
    else
      return array[right]>key?right:right+1;
      

  }

  int middle = (left + right)/2;

  if (key > array[middle])
  {
    return id11(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return id11(array, left, middle, size, key);
  }
  else
  {
    int i = middle;
    while(--i >= 0 && key == array[i]);
    return i+1;
    

  }
}

int id14(int *array, int left, int right, int size, int key)
{
  if(!array) return 0;

  if (left >= right)
  {
    if (array[left] == key)
    {
      

      return size-1-left;
    }
    else
      return array[right]>key?size-right:size-1-right;
      

  }

  int middle = (left + right)/2;

  if (key > array[middle])
  {
    return id14(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return id14(array, left, middle, size, key);
  }
  else
  {
    int i = middle;
    while(++i < size && key == array[i]);
    return size-1-(i-1);
    

  }
}

int id19(set<int>& array, int key)
{
  set<int>::iterator it    = array.find(key);
  set<int>::iterator begin = array.begin();
  if (it == array.end())
  {
    return 0;
  }
  int count = 0;
  while(it != begin)
  {
    count++;
    it--;
  }
  return count;
}

int id19(multiset<int>& array, int key)
{
  set<int>::iterator it    = array.find(key);
  set<int>::iterator begin = array.begin();
  if (it == array.end())
  {
    return 0;
  }
  while(key == *it && it != begin)
  {
    it--;
  }
  it++;
  int count = 0;
  while(it != begin)
  {
    count++;
    it--;
  }
  return count;
}

int id5(set<int>& array, int key)
{
  set<int>::iterator it  = array.find(key);
  set<int>::iterator end = array.end();
  if (it == array.end())
  {
    return 0;
  }
  int count = 0;
  set<int>::iterator tmp = it;
  while(it != end && (++tmp) != end)
  {
    count++;
    it++;
  }
  return count;
}

int id5(multiset<int>& array, int key)
{
  set<int>::iterator it  = array.find(key);
  set<int>::iterator end = array.end();
  if (it == array.end())
  {
    return 0;
  }
  int count = 0;
  while(it != end && key == *it)
  {
    it++;
  }
  if (it != end) it--;
  set<int>::iterator tmp = it;
  while(it != end && (++tmp) != end)
  {
    count++;
    it++;
  }
  return count;
}

int id8(vector<int>& array, int left, int right, int size, int key)
{
  if(array.empty()) return 0;

  if (left >= right)
  {
    if (array[left] == key)
      return left;
    else
      return array[right]>key?right:right+1;
      

  }

  int middle = (left + right)/2;

  if (key > array[middle])
  {
    return id8(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return id8(array, left, middle, size, key);
  }
  else
  {
    

    

    

    


    return id8(array, left, middle-1, size, key);
  }
}

int id23(vector<int>& array, int left, int right, int size, int key)
{
  if(array.empty()) return 0;

  if (left >= right)
  {
    if (array[left] == key)
    {
      

      return size-1-left;
    }
    else
      return array[right]>key?size-right:size-1-right;
      

  }

  int middle = (left + right)/2;

  if (key > array[middle])
  {
    return id23(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return id23(array, left, middle, size, key);
  }
  else
  {
    

    

    

    


    return id23(array, middle+1, right, size, key);
  }
}



int tt_left[N],tt_right[N];

int main()
{
  std::ios::sync_with_stdio(false);

  int n,m;
  int A,B,C;

  int a,b;

  unsigned long long answer = 0ULL;

  cin >> n>> m;
  cin >> A >> B >> C;

  int open = 0, close = 0;

  unsigned long long leftclose = 0, rightclose = 0;

  unsigned long long **team;
  

  

  

  

  set<int> *arrays = new set<int>[n];


  set<int> *arrays1 = new set<int>[n];
    int *arrays_sz;
    int *id7;

  vector<int> *vectorebi = new vector<int>[n];
  vector<int> *vectorebi1 = new vector<int>[n];

  

  


  

  

  

  

  

  


  

  


  vector<int> id2;
  vector<int> id17;

  

  


  int *open_arr = (int *)calloc(n, sizeof(int));
  int *misamatebeli_tanakveta_left = (int *)calloc(n, sizeof(int));
  int *misamatebeli_tanakveta_right = (int *)calloc(n, sizeof(int));

  arrays_sz = (int *)calloc(n, sizeof(int));
  id7 = (int *)calloc(n, sizeof(int));

  team = (unsigned long long **)malloc(n * sizeof(unsigned long long *));
  

  

  

  


  for (int i = 0; i < n; ++i)
  {
    team[i] = (unsigned long long *) calloc(2, sizeof(unsigned long long));
    

    

    

    

    

    

    

    

  }

  int *id20, *id3;

  id3 = (int *) calloc(n, sizeof(int));
  id20  = (int *) calloc(n, sizeof(int));

  int *open_conflict_both = (int *)calloc(n, sizeof(int));

  int *damxuravebis_seti_count = (int *)calloc(n, sizeof(int));
  int *gamxsnelebis_seti_count = (int *)calloc(n, sizeof(int));

  multiset<int> id4;
  multiset<int> id12;

  vector <pair<int, int> > v;

  for (int i = 0; i < m; i++)
  {
    
    cout<<"-------------\n";
    
    cin>>a>>b;





    pair<int, int> p(a, b);
    v.push_back(p);
  



    if (a > b)
    {
      vectorebi[b].push_back(a);
      vectorebi1[a].push_back(b);




      id12.insert(a);
      id4.insert(b);

      damxuravebis_seti_count[a]++;
      gamxsnelebis_seti_count[b]++;
  
      

      

      id17.push_back(a);
      id2.push_back(b);
      

      

      arrays[b].insert(a);
      arrays1[a].insert(b);


      team[a][0]++;
      team[b][1]++;
    }
    else
    {
      vectorebi[a].push_back(b);
      vectorebi1[b].push_back(a);




      

      

      arrays[a].insert(b);
      arrays1[b].insert(a);

      id12.insert(b);
      id4.insert(a);

      damxuravebis_seti_count[b]++;
      gamxsnelebis_seti_count[a]++;


      

      

      id17.push_back(b);
      id2.push_back(a);
      

      

      

      

      








      team[a][1]++;
      team[b][0]++;
    }
  }












  sort(id2.begin(), id2.end());
  sort(id17.begin(), id17.end());

  for (int i =0; i < n; i++)
  {
    sort(vectorebi[i].begin(), vectorebi[i].end());
    sort(vectorebi1[i].begin(), vectorebi1[i].end());
  }












  for (int i = 0; i < n; i++)
  {
    int id9 = id8(id2, 0, id2.size()-1, id2.size(), i);
    int id22 = id8(id17, 0, id17.size()-1, id17.size(), i+1);

    int allopen = id9 - id22;

    open_arr[i] = allopen;

    int common = 0;
    for (int yle = 0; yle < vectorebi1[i].size(); yle++)
    

    {
      int ylev = vectorebi1[i][yle];
      int ylesz = vectorebi[ylev].size();
      int yleval = vectorebi[ylev][ylesz-1];

      if (yleval > i)
      {
        

        

        


        

        

        

        

        

        


        


        int occ = 0;

        int id10 = vectorebi[ylev].size();
        id10--;

        for (; id10 >= 0 ; id10--)
        {
          if (vectorebi[ylev][id10] <= i) break;
          occ++;
          if (binary_search(vectorebi[i].begin(), vectorebi[i].end(), vectorebi[ylev][id10]))
          

          {
            common++;
            tt_left[ vectorebi[ylev][id10] ]++;
            tt_right[ylev]++;
          }
          

        }
        open_arr[i] -= occ;
      }
    }
    for (int yle = 0; yle < vectorebi[i].size(); yle++)
    

    {
      int ylev = vectorebi[i][yle];
      int yleval = vectorebi1[ylev][0];
      

      if (yleval < i)
      {
        int occ = id8(vectorebi1[ylev],0,vectorebi1[ylev].size()-1,vectorebi1[ylev].size(), i);
        open_arr[i] -= occ;
      }
    }
    open_arr[i] += common;
    
    cout<<"--------------id9[i]: " <<id9<<endl;
    cout<<"------------- id22[i]: " <<id22<<endl;
    cout<<"------------------------open_arr[i]: " <<open_arr[i]<<endl;
    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    


    


    


    
    cout<<"id20 [i]: " <<id20[i]<<endl;
    cout<<"id21    [i]: " <<id21<<endl;
    cout<<"id16      [i]: " <<id16<<endl;
    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    


    

    


    

    


    


    


    
    cout<<"id3[i]: " <<id3[i]<<endl;
    cout<<"id21    [i]: " <<id21<<endl;
    cout<<"id16      [i]: " <<id16<<endl;
    
  }

  for (int i = 0; i < n; ++i)
  {
    int id16 = 0;
    int id21 = 0;
    

    

    

    for (int j = 0; j < vectorebi1[i].size(); ++j)
    

    {
      int b = vectorebi1[i][j];
      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      


      id21 +=arrays1[b].size();

      int tmpcount=0;
      for (int k = 0; k < vectorebi[b].size(); k++)
      

      {
        int id0 = vectorebi[b][k];
        if (id0 >= i) break;
        

        

        

        

        

        

        

        tmpcount++;
      }

      id21 += tmpcount;
    }

    id16 /= 2;

    

    id20[i] = id21 - tt_left[i];


    

    

    


    id16 = 0;
    id21 = 0;
    for (int j = 0; j < vectorebi[i].size(); ++j)
    

    {
      int a = vectorebi[i][j];
      

      

      

      

      

      

      

      

      

      

      


      id21 += arrays[a].size();

      int tmpcount = 0;
      for (int k = 0; k < vectorebi1[a].size(); ++k)
      

      {
        int id6 = vectorebi1[a][k];
        if (id6 <= i) continue;
        

        

        

        

        

        

        


        tmpcount++;
      }

      id21 += tmpcount;
    }

    id16 /= 2;

    

    id3[i] = id21 - tt_right[i];
  }

  for (int i = 0; i < m; i++)
  {
    int a = v[i].first;
    int b = v[i].second;

    if (v[i].first > v[i].second)
    {
      a = v[i].first;
      b = v[i].second;
    }
    else
    {
      a = v[i].second;
      b = v[i].first;
    }

    if (a > b)
    {
      

      

      

      


      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      


      


      

      

      

      

      

      

      

      

      

      

      

      

      

      


      



      

      

      

      

      


      

      

      

      


      

      

      


      

      

      

      

      

      

      

      

      

      


      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      


      

      

      

      


      



      

      

      

      

      

      

      


      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      


      if (a == 3 || b == 3)
      {
        
        cout<<"=========1 a "<<a<<" b "<<b<<" deduct: "<<deduct<<" id18: "<<id18<<endl;
        
      }
    }
    else
    {
      

      

      

      


      

      

      

      


      int id24  = (A != 910258)?id8(id2, 0, id2.size()-1, id2.size(), a):0;
      int id15 = (A != 910258)?id23(id2, 0, id2.size()-1, id2.size(), a):0;
      int id13 = (A != 910258)?id19(arrays[a], b):0;
      id13++;
      int a_elements = id2.size() - (id24 + id15);
      int deduct = a_elements - id13;
      if (deduct > 0)
      {
        open_arr[b] -= (deduct);

        set<int>::iterator it = arrays[a].end();
        it--;
        for (;A != 910258;--it)
        {
          if (*it > b)
          {
            if (arrays[b].find(*it) != arrays[b].end())
            {
              open_conflict_both[b]++;
            }
          }
          else
          {
            break;
          }
        }
      }

      int b_elements = damxuravebis_seti_count[b];
      int id1 = (A != 910258)?id5(arrays1[b], a):0;
      id1++;
      int id18 = b_elements - id1;
      if (id18 > 0)
      {
        open_arr[a] -= id18;

        set<int>::iterator it = arrays1[b].begin();
        for (; it != arrays1[b].end() && A != 910258;++it)
        {
          if (*it < a)
          {
            if (arrays1[a].find(*it) != arrays1[a].end())
            {
              open_conflict_both[a]++;
            }
          }
          else
          {
            break;
          }
        }
      }

      if (a == 3 || b == 3)
      {
        
        cout<<"=========2 a "<<a<<" b "<<b<<" deduct: "<<deduct<<" id18: "<<id18<<endl;
        
      }
    }
  }









cout << "A: " << A << endl;
cout << "B: " << B << endl;
cout << "C: " << C << endl;

  for (int i = 0; i < n; ++i)
  {
    
    cout << "iteration: " << i << endl<<"---------------\n";
    
    unsigned long long left  = i;
    unsigned long long right = n-1-i;


cout << "left: " << left << endl;
cout << "right: " << right << endl;
cout << "team[i][0]: " << team[i][0] << endl;
cout << "team[i][1]: " << team[i][1] << endl;

    close += team[i][0];

    

    

    


    

    

    if (left - team[i][0] > 1)
    {
      answer += (unsigned long long)(((left - team[i][0]) * (left - team[i][0] - 1))/2 - (leftclose - id20[i])) * i * C;

      
      cout << "ans1: " << answer << endl;
      
    }

    open  -= team[i][0];

    rightclose = m - leftclose - team[i][0] - team[i][1] - open;

    



    cout<<"open: " << open << "\n";
    cout<<"open_arr[i]: " <<open_arr[i]<<"\n";
    cout<<"open_conflict_both[i]: "<<open_conflict_both[i]<<endl;
    cout<<"leftclose: " << leftclose << " shared " << id20[i] << "\n";
    cout<<"rightclose: " << rightclose << " shared " << id3[i] << "\n";





    

    

    


    

    

    if (right - team[i][1] > 1)
    {
      answer += (unsigned long long)(((right - team[i][1]) * (right - team[i][1] - 1)) / 2 - (rightclose - id3[i])) * i * A;

      
      cout << "ans2: " << answer << endl;
      
    }




    if (left - team[i][0] >= 1 && right - team[i][1] >= 1)
    {
      answer += (unsigned long long)((left - team[i][0]) * (right - team[i][1]) - open_arr[i]) * i * B;

      
      cout << "ans3: " << answer << endl;
      
    }

    open  += team[i][1];

    leftclose += team[i][0];
  }


  cout << answer << endl;
}