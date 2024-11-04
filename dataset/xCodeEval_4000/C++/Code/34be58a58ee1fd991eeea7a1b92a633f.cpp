#include <sstream>
#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <stack>
#include <fstream>
#include <algorithm>
#include <memory>
#include <cmath>
using namespace std;

class Cell {
public:
    list<Cell*> reachableRats;

    

    

    virtual bool ExplodeAble() const = 0;

    

    

    

    virtual void Explode() {}

    

    

    

    

    

    virtual void CollectIntoCandidateIfRat(Cell* candidate) {};

    Cell(unsigned row, unsigned col) {
        this->row = row;
        this->col = col;
        this->expanded = false;
    }

    

    

    

    

    inline void MarkExpanded(bool expanded) {   this->expanded = expanded;  }
    inline bool Expanded() const { return expanded; }

    

    

    

    inline unsigned NaturalRow() const { return PlainRow() + 1; }
    inline unsigned NaturalCol() const { return PlainCol() + 1; }
    inline unsigned PlainRow() const { return row; }
    inline unsigned PlainCol() const {return col; }

private:
    unsigned row, col;
    bool expanded;
};

class Space : public Cell {
public:
    Space(unsigned row, unsigned col) : Cell(row,col) {}

    virtual bool ExplodeAble() const {
        

        return true;
    }
};

class Wall : public Cell {
public:
    Wall(unsigned row, unsigned col) : Cell(row,col) {}

    virtual bool ExplodeAble() const {
        

        return false;
    }
};

class Rat : public Cell {
public:
    Rat(unsigned row, unsigned col) : Cell(row,col) {
        alive = true;
    }

    virtual void CollectIntoCandidateIfRat(Cell* candidate) {
        

        candidate->reachableRats.push_back(this);
    }

    virtual bool ExplodeAble() const {
        return true;
    }

    virtual void Explode() {
        alive = false;
    }

    void BringAlive() {
        alive = true;
    }

    bool IsAlive() const {
        return alive;
    }

private:
    bool alive;
};

struct CellPair {
    Cell* cell;
    int   remain;

    CellPair(Cell* cell, int remain) {
        this->cell = cell;
        this->remain = remain;
    }
};

void Grenade(Cell* cell) {
    cell->Explode();
}

template<class Container, class Pred>
void for_all(Container& container, Pred pred) {
    for_each( container.begin(), container.end(), pred);
}

template<class ValueType>
class Releaser {
public:
    inline void operator()(ValueType* pointer) {
        delete pointer;
    }
};

class Reborn {
public:
    inline void operator()(Rat* rat) {
        rat->BringAlive();
    }
};

class Basement {
private:
    Basement(unsigned rows, unsigned cols) {
        this->rows = rows;
        this->cols = cols;
    }

    void LoadFrom(istream& input) {
        string markLine;
        for (unsigned row=0; row<rows; ++row) {
            getline(input, markLine);
            for (unsigned col=0; col<cols; ++col) {
                switch(markLine[col])   
                {
                case 'X':
                    cells.push_back(new Wall(row,col));
                    break;
                case 'R': 
                    {
                        Rat* rat = new Rat(row,col);
                        cells.push_back(rat);
                        rats.push_back(rat);
                    }                   
                    break;
                case '.':
                    cells.push_back(new Space(row,col));
                    break;
                default:
                    break;
                }
            }
        }
    }

public:
    static Basement* CreateFrom(unsigned rows, unsigned cols, istream& input) {
        Basement* basement = new Basement(rows,cols);
        basement->LoadFrom(input);

        return basement;
    }

    ~Basement() {
        for_all(cells, Releaser<Cell>());
    }

    vector<Rat*> Rats() const {
        return rats;
    }

    

    

    

    Cell* CellAt(int row, int col) const {
        

        if (row<0 || row>=(int)rows || col<0 || col>=(int)cols)
            return &inaccessable;

        return cells[AsUnaryDimension(row,col)];
    }

private:
    inline unsigned AsUnaryDimension(unsigned row, unsigned col) const {
        return row * cols + col;
    }

private:
    

    

    

    class InaccessbleCell : public Cell {
    public:
        InaccessbleCell():Cell(-1,-1) {}

        virtual bool ExplodeAble() const {  return false;   }
    };

    unsigned rows,  cols;
    vector<Cell*>   cells;
    vector<Rat*>        rats;
    static InaccessbleCell inaccessable;
};

Basement::InaccessbleCell Basement::inaccessable;

class RatsCleaner {
public:
    RatsCleaner(Basement& bsm, unsigned duration) : basement(bsm){
        this->duration = duration;
    }

    bool GetFeasibles(Cell*& feasible1st, Cell*& feasible2nd) {
        rats = basement.Rats();

        if (!TooMuchRats())
        {
            SelectCandidates();
            UpdateReachableRatsForEachCandidate();

            pair<Cell*,Cell*> feasibles = GetFeasiblePairFromCandidates();
            if (feasibles.first!=nullptr && feasibles.second!=nullptr)  {
                feasible1st = feasibles.first;
                feasible2nd = feasibles.second;
                return true;
            }
        }
        
        return false;
    }

private:
    void SelectCandidates() {
        SelectByPlainCoverages();
        UnifyCandidates();
    }

    pair<Cell*,Cell*> GetFeasiblePairFromCandidates() {
        Cell* feasibleOne, *feasibleTwo;
        for (unsigned i=0; i<candidates.size(); ++i) {
            for (unsigned j=i+1; j<candidates.size(); ++j)  {
                feasibleOne = candidates[i];
                feasibleTwo = candidates[j];

                

                

                

                

                if (feasibleOne->reachableRats.size() + feasibleTwo->reachableRats.size()<rats.size())
                    continue;

                

                BringAllAlive();

                

                for_all(feasibleOne->reachableRats, Grenade);
                for_all(feasibleTwo->reachableRats, Grenade);

                

                if (AllEliminated())
                    return make_pair(feasibleOne, feasibleTwo);         }
        }

        

        return make_pair(nullptr, nullptr);
    }

    enum { OFFSET_CNT = 4,
        OFFSET_DIM = 2,
        OFS_ROW = 0,
        OFS_COL = 1 
    };

    typedef vector<Cell*> ExpansionContainer;
    typedef deque<CellPair> AffectionContainer;

    void UpdateReachableRatsForEachCandidate() {
        

        

        

        

        for(vector<Cell*>::iterator canIt = candidates.begin(); canIt!=candidates.end(); canIt++) {
            Cell* candidateCell = *canIt;

            

            deque<CellPair> affections;

            

            

            ExpansionContainer expands;

            affections.push_back(CellPair(candidateCell, duration));
            candidateCell->MarkExpanded(true);
            expands.push_back(candidateCell);

            while (!affections.empty()) {
                CellPair cellPair = affections.front();
                affections.pop_front();

                Cell* expanding = cellPair.cell;
                expanding->CollectIntoCandidateIfRat(candidateCell);
                if (cellPair.remain<=0)
                    continue;

                static int offsets[OFFSET_CNT][OFFSET_DIM] = { 
                    { -1, 0 },
                    { 1, 0 },
                    { 0, -1 },
                    { 0, 1 },
                };

                for (int i=0; i<OFFSET_CNT; ++i) {
                    int row = expanding->PlainRow() + offsets[i][OFS_ROW];
                    int col = expanding->PlainCol() + offsets[i][OFS_COL];

                    Cell* toExpand = basement.CellAt(row,col);
                    if (!toExpand->Expanded()&& toExpand->ExplodeAble()) {
                        affections.push_back(CellPair(toExpand, cellPair.remain-1));
                        toExpand->MarkExpanded(true);
                        expands.push_back(toExpand);
                    }
                }
            }

            ClearExpansionMarks(expands);
        }
    }

    inline void ClearExpansionMarks(ExpansionContainer& expansions )  {
        

        for (unsigned i=0, total=expansions.size(); i<total; ++i)
            expansions[i]->MarkExpanded(false);
    }

    void SelectByPlainCoverages() {
        for(vector<Rat*>::const_iterator ratIt=rats.begin(); ratIt!=rats.end(); ++ratIt) {
            const Rat& rat = *(*ratIt);

            

            int sigDuration = (int)duration;
            for (int offsetRow = -sigDuration; offsetRow<=sigDuration; ++offsetRow) {
                for (int offsetCol = -sigDuration; offsetCol<=sigDuration; ++offsetCol) {               
                    if (abs(offsetRow)+abs(offsetCol)>sigDuration)
                        continue;

                    int row = rat.PlainRow() + offsetRow;
                    int col = rat.PlainCol() + offsetCol;
                    Cell* affectable = basement.CellAt(row,col);

                    

                    

                    

                    if (affectable->ExplodeAble())
                        candidates.push_back(affectable);
                }
            }
        }
    }

    void UnifyCandidates() {
        sort(candidates.begin(), candidates.end());
        vector<Cell*>::iterator firstDuplicated = unique(candidates.begin(), candidates.end());
        candidates.erase(firstDuplicated, candidates.end());
    }

    inline bool AllEliminated() const {
        bool eliminated = true;
        for (unsigned i=0; i<rats.size() && eliminated; ++i)
            eliminated = eliminated && !rats[i]->IsAlive();

        return eliminated;
    }

    inline void BringAllAlive() {
        for (unsigned i=0; i<rats.size(); ++i) {
            rats[i]->BringAlive();
        }
    }

    inline bool TooMuchRats() const {
        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        

        unsigned maxElimination = 2*(2*(duration*duration + duration) + 1);
        return rats.size()>maxElimination;
    }

private:
    Basement& basement;
    unsigned duration;
    vector<Rat*> rats;
    vector<Cell*> candidates;
};


void GetBasicInfos(istream& source, unsigned& rows, unsigned& cols, unsigned& duration) {
    string infoLine;
    getline(source, infoLine);
    stringstream infoProvider(infoLine);
    infoProvider>>rows>>cols>>duration;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    unsigned rows, cols, duration;
    GetBasicInfos(input, rows, cols, duration); 

    

    auto_ptr<Basement> basementGuard(Basement::CreateFrom(rows, cols, input));
    RatsCleaner cleaner(*basementGuard,duration);

    Cell* feasibleOne, *feasibleTwo;
    if (cleaner.GetFeasibles(feasibleOne, feasibleTwo))
    {
        output<<feasibleOne->NaturalRow()<<' '<<feasibleOne->NaturalCol()<<' ';
        output<<feasibleTwo->NaturalRow()<<' '<<feasibleTwo->NaturalCol();
    }
    else
    {
        output<<-1;
    }

    return 0;
}