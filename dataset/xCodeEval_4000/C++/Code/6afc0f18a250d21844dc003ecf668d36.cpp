#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

#define DBG
#undef DBG

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

int less_than_number(int *array, int left, int right, int size, int key)
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
    return less_than_number(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return less_than_number(array, left, middle, size, key);
  }
  else
  {
    int i = middle;
    while(--i >= 0 && key == array[i]);
    return i+1;
    

  }
}

int greater_than_number(int *array, int left, int right, int size, int key)
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
    return greater_than_number(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return greater_than_number(array, left, middle, size, key);
  }
  else
  {
    int i = middle;
    while(++i < size && key == array[i]);
    return size-1-(i-1);
    

  }
}

int less_than_number_set(set<int>& array, int key)
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

int less_than_number_set(multiset<int>& array, int key)
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

int greater_than_number_set(set<int>& array, int key)
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

int greater_than_number_set(multiset<int>& array, int key)
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

int less_than_number_vector(vector<int>& array, int left, int right, int size, int key)
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
    return less_than_number_vector(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return less_than_number_vector(array, left, middle, size, key);
  }
  else
  {
    

    

    

    


    return less_than_number_vector(array, left, middle-1, size, key);
  }
}

int greater_than_number_vector(vector<int>& array, int left, int right, int size, int key)
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
    return greater_than_number_vector(array, middle+1, right, size, key);
  }
  else if (key < array[middle])
  {
    return greater_than_number_vector(array, left, middle, size, key);
  }
  else
  {
    

    

    

    


    return greater_than_number_vector(array, middle+1, right, size, key);
  }
}

#define N 200000

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
    int *arrays1_sz;

  vector<int> *vectorebi = new vector<int>[n];
  vector<int> *vectorebi1 = new vector<int>[n];

  

  


  

  

  

  

  

  


  

  


  vector<int> gamxsnelebi_arr;
  vector<int> damxuravebi_arr;

  

  


  int *open_arr = (int *)calloc(n, sizeof(int));
  int *misamatebeli_tanakveta_left = (int *)calloc(n, sizeof(int));
  int *misamatebeli_tanakveta_right = (int *)calloc(n, sizeof(int));

  arrays_sz = (int *)calloc(n, sizeof(int));
  arrays1_sz = (int *)calloc(n, sizeof(int));

  team = (unsigned long long **)malloc(n * sizeof(unsigned long long *));
  

  

  

  


  for (int i = 0; i < n; ++i)
  {
    team[i] = (unsigned long long *) calloc(2, sizeof(unsigned long long));
    

    

    

    

    

    

    

    

  }

  int *tanakveta_left, *tanakveta_right;

  tanakveta_right = (int *) calloc(n, sizeof(int));
  tanakveta_left  = (int *) calloc(n, sizeof(int));

  int *open_conflict_both = (int *)calloc(n, sizeof(int));

  int *damxuravebis_seti_count = (int *)calloc(n, sizeof(int));
  int *gamxsnelebis_seti_count = (int *)calloc(n, sizeof(int));

  multiset<int> gamxsnelebis_seti;
  multiset<int> damxuravebis_seti;

  vector <pair<int, int> > v;

  for (int i = 0; i < m; i++)
  {
    #ifdef DBG
    cout<<"-------------\n";
    #endif
    cin>>a>>b;





    pair<int, int> p(a, b);
    v.push_back(p);
  



    if (a > b)
    {
      vectorebi[b].push_back(a);
      vectorebi1[a].push_back(b);




      damxuravebis_seti.insert(a);
      gamxsnelebis_seti.insert(b);

      damxuravebis_seti_count[a]++;
      gamxsnelebis_seti_count[b]++;
  
      

      

      damxuravebi_arr.push_back(a);
      gamxsnelebi_arr.push_back(b);
      

      

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

      damxuravebis_seti.insert(b);
      gamxsnelebis_seti.insert(a);

      damxuravebis_seti_count[b]++;
      gamxsnelebis_seti_count[a]++;


      

      

      damxuravebi_arr.push_back(b);
      gamxsnelebi_arr.push_back(a);
      

      

      

      

      








      team[a][1]++;
      team[b][0]++;
    }
  }












  sort(gamxsnelebi_arr.begin(), gamxsnelebi_arr.end());
  sort(damxuravebi_arr.begin(), damxuravebi_arr.end());

  for (int i =0; i < n; i++)
  {
    sort(vectorebi[i].begin(), vectorebi[i].end());
    sort(vectorebi1[i].begin(), vectorebi1[i].end());
  }












  for (int i = 0; i < n; i++)
  {
    int a_gt_gamxsnels = less_than_number_vector(gamxsnelebi_arr, 0, gamxsnelebi_arr.size()-1, gamxsnelebi_arr.size(), i);
    int a_gt_damxuravs = less_than_number_vector(damxuravebi_arr, 0, damxuravebi_arr.size()-1, damxuravebi_arr.size(), i+1);

    int allopen = a_gt_gamxsnels - a_gt_damxuravs;

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

        int ramesz = vectorebi[ylev].size();
        ramesz--;

        for (; ramesz >= 0 ; ramesz--)
        {
          if (vectorebi[ylev][ramesz] <= i) break;
          occ++;
          if (binary_search(vectorebi[i].begin(), vectorebi[i].end(), vectorebi[ylev][ramesz]))
          

          {
            common++;
            tt_left[ vectorebi[ylev][ramesz] ]++;
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
        int occ = less_than_number_vector(vectorebi1[ylev],0,vectorebi1[ylev].size()-1,vectorebi1[ylev].size(), i);
        open_arr[i] -= occ;
      }
    }
    open_arr[i] += common;
    #ifdef DBG
    cout<<"--------------a_gt_gamxsnels[i]: " <<a_gt_gamxsnels<<endl;
    cout<<"------------- a_gt_damxuravs[i]: " <<a_gt_damxuravs<<endl;
    cout<<"------------------------open_arr[i]: " <<open_arr[i]<<endl;
    #endif

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    


    


    


    #ifdef DBG
    cout<<"tanakveta_left [i]: " <<tanakveta_left[i]<<endl;
    cout<<"gamosaklebi    [i]: " <<gamosaklebi<<endl;
    cout<<"tanakveta      [i]: " <<tanakveta<<endl;
    #endif

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    


    

    

    

    

    

    

    

    

    

    

    

    


    

    


    

    


    


    


    #ifdef DBG
    cout<<"tanakveta_right[i]: " <<tanakveta_right[i]<<endl;
    cout<<"gamosaklebi    [i]: " <<gamosaklebi<<endl;
    cout<<"tanakveta      [i]: " <<tanakveta<<endl;
    #endif
  }

  for (int i = 0; i < n; ++i)
  {
    int tanakveta = 0;
    int gamosaklebi = 0;
    

    

    

    for (int j = 0; j < vectorebi1[i].size(); ++j)
    

    {
      int b = vectorebi1[i][j];
      

      

      

      

      

      

      

      

      

      

      

      

      

      

      

      


      gamosaklebi +=arrays1[b].size();

      int tmpcount=0;
      for (int k = 0; k < vectorebi[b].size(); k++)
      

      {
        int b_s_damxuravi = vectorebi[b][k];
        if (b_s_damxuravi >= i) break;
        

        

        

        

        

        

        

        tmpcount++;
      }

      gamosaklebi += tmpcount;
    }

    tanakveta /= 2;

    

    tanakveta_left[i] = gamosaklebi - tt_left[i];


    

    

    


    tanakveta = 0;
    gamosaklebi = 0;
    for (int j = 0; j < vectorebi[i].size(); ++j)
    

    {
      int a = vectorebi[i][j];
      

      

      

      

      

      

      

      

      

      

      


      gamosaklebi += arrays[a].size();

      int tmpcount = 0;
      for (int k = 0; k < vectorebi1[a].size(); ++k)
      

      {
        int a_s_gamxsneli = vectorebi1[a][k];
        if (a_s_gamxsneli <= i) continue;
        

        

        

        

        

        

        


        tmpcount++;
      }

      gamosaklebi += tmpcount;
    }

    tanakveta /= 2;

    

    tanakveta_right[i] = gamosaklebi - tt_right[i];
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
        #ifdef DBG
        cout<<"=========1 a "<<a<<" b "<<b<<" deduct: "<<deduct<<" deduct1: "<<deduct1<<endl;
        #endif
      }
    }
    else
    {
      

      

      

      


      

      

      

      


      int a_left_elements  = (A != 910258)?less_than_number_vector(gamxsnelebi_arr, 0, gamxsnelebi_arr.size()-1, gamxsnelebi_arr.size(), a):0;
      int a_right_elements = (A != 910258)?greater_than_number_vector(gamxsnelebi_arr, 0, gamxsnelebi_arr.size()-1, gamxsnelebi_arr.size(), a):0;
      int a_s_damxuravta_ricxvi_left = (A != 910258)?less_than_number_set(arrays[a], b):0;
      a_s_damxuravta_ricxvi_left++;
      int a_elements = gamxsnelebi_arr.size() - (a_left_elements + a_right_elements);
      int deduct = a_elements - a_s_damxuravta_ricxvi_left;
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
      int b_s_gamxsnelta_ricxvi_right = (A != 910258)?greater_than_number_set(arrays1[b], a):0;
      b_s_gamxsnelta_ricxvi_right++;
      int deduct1 = b_elements - b_s_gamxsnelta_ricxvi_right;
      if (deduct1 > 0)
      {
        open_arr[a] -= deduct1;

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
        #ifdef DBG
        cout<<"=========2 a "<<a<<" b "<<b<<" deduct: "<<deduct<<" deduct1: "<<deduct1<<endl;
        #endif
      }
    }
  }








#ifdef DBG
cout << "A: " << A << endl;
cout << "B: " << B << endl;
cout << "C: " << C << endl;
#endif
  for (int i = 0; i < n; ++i)
  {
    #ifdef DBG
    cout << "iteration: " << i << endl<<"---------------\n";
    #endif
    unsigned long long left  = i;
    unsigned long long right = n-1-i;

#ifdef DBG
cout << "left: " << left << endl;
cout << "right: " << right << endl;
cout << "team[i][0]: " << team[i][0] << endl;
cout << "team[i][1]: " << team[i][1] << endl;
#endif
    close += team[i][0];

    

    

    


    

    

    if (left - team[i][0] > 1)
    {
      answer += (unsigned long long)(((left - team[i][0]) * (left - team[i][0] - 1))/2 - (leftclose - tanakveta_left[i])) * i * C;

      #ifdef DBG
      cout << "ans1: " << answer << endl;
      #endif
    }

    open  -= team[i][0];

    rightclose = m - leftclose - team[i][0] - team[i][1] - open;

    


#ifdef DBG
    cout<<"open: " << open << "\n";
    cout<<"open_arr[i]: " <<open_arr[i]<<"\n";
    cout<<"open_conflict_both[i]: "<<open_conflict_both[i]<<endl;
    cout<<"leftclose: " << leftclose << " shared " << tanakveta_left[i] << "\n";
    cout<<"rightclose: " << rightclose << " shared " << tanakveta_right[i] << "\n";
#endif




    

    

    


    

    

    if (right - team[i][1] > 1)
    {
      answer += (unsigned long long)(((right - team[i][1]) * (right - team[i][1] - 1)) / 2 - (rightclose - tanakveta_right[i])) * i * A;

      #ifdef DBG
      cout << "ans2: " << answer << endl;
      #endif
    }




    if (left - team[i][0] >= 1 && right - team[i][1] >= 1)
    {
      answer += (unsigned long long)((left - team[i][0]) * (right - team[i][1]) - open_arr[i]) * i * B;

      #ifdef DBG
      cout << "ans3: " << answer << endl;
      #endif
    }

    open  += team[i][1];

    leftclose += team[i][0];
  }


  cout << answer << endl;
}