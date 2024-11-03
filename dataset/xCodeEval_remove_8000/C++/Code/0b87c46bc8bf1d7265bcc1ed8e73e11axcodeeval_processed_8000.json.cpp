

using namespace std;

string sequence = "";
int sequenceLength = 0;
vector<bool> hereBefore;
vector<short> id0;



























void id1()
{
    for(int i = 0; i < sequenceLength; i++)
    {
        hereBefore[i] = false;
    }
}

bool willFall(int startingPoint)
{
    vector<int> thisRound = vector<int>();
    while (hereBefore[startingPoint] != true)
    {
        if (id0[startingPoint] != -1)
        {
            if (id0[startingPoint] == 0)
            {
                for(int i = 0; i < thisRound.size(); i++)
                {
                    id0[thisRound[i]] = 0;
                    hereBefore[thisRound[i]] = false;
                }
                
                return false;
            }
            else
            {
                for(int i = 0; i < thisRound.size(); i++)
                {
                    id0[thisRound[i]] = 1;
                    hereBefore[thisRound[i]] = false;
                }
                
                return true;
            }
        }
        
        hereBefore[startingPoint] = true;
        thisRound.push_back(startingPoint);
        
        if (sequence[startingPoint] == '<')
        {
            startingPoint -= 1;
        }
        else
        {
            startingPoint += 1;
        }
        
        if (startingPoint >= sequence.length() || startingPoint < 0)
        {
            for(int i = 0; i < thisRound.size(); i++)
            {
                    id0[thisRound[i]] = 1;
                hereBefore[thisRound[i]] = false;
            }
            
            return true;
        }
    }
    
    for(int i = 0; i < thisRound.size(); i++)
    {
        id0[thisRound[i]] = 0;
        hereBefore[thisRound[i]] = false;
    }
    
    return false;
}

int main()
{
    cin >> sequenceLength;
    cin >> sequence;


    hereBefore = vector<bool>(sequenceLength);
    id0 = vector<short>(sequenceLength, -1);
    id1();
    
    int result = 0;
    
    for (int i = 0; i < sequenceLength; i++)
    {
        if (id0[i] == 1)
        {
            result++;
            continue;
        }
        else if (id0[i] == 0)
        {
            continue;
        }
        
        if (willFall(i))
        {
            result++;
        }
    }
    
    cout << result;
    
    return 0;
}
