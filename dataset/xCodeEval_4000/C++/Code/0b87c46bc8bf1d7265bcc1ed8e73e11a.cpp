#include<iostream>
#include<vector>
using namespace std;

string sequence = "";
int sequenceLength = 0;
vector<bool> hereBefore;
vector<short> willFallVec;



























void clearHereBefore()
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
        if (willFallVec[startingPoint] != -1)
        {
            if (willFallVec[startingPoint] == 0)
            {
                for(int i = 0; i < thisRound.size(); i++)
                {
                    willFallVec[thisRound[i]] = 0;
                    hereBefore[thisRound[i]] = false;
                }
                
                return false;
            }
            else
            {
                for(int i = 0; i < thisRound.size(); i++)
                {
                    willFallVec[thisRound[i]] = 1;
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
                    willFallVec[thisRound[i]] = 1;
                hereBefore[thisRound[i]] = false;
            }
            
            return true;
        }
    }
    
    for(int i = 0; i < thisRound.size(); i++)
    {
        willFallVec[thisRound[i]] = 0;
        hereBefore[thisRound[i]] = false;
    }
    
    return false;
}

int main()
{
    cin >> sequenceLength;
    cin >> sequence;


    hereBefore = vector<bool>(sequenceLength);
    willFallVec = vector<short>(sequenceLength, -1);
    clearHereBefore();
    
    int result = 0;
    
    for (int i = 0; i < sequenceLength; i++)
    {
        if (willFallVec[i] == 1)
        {
            result++;
            continue;
        }
        else if (willFallVec[i] == 0)
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
