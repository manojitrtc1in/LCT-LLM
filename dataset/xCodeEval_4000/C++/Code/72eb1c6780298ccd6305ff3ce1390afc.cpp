#define NDEBUG
#include <bits/stdc++.h>

#define mp       make_pair
#define mt	  make_tuple

#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF=1<<29;
const double EPS=1e-9;
const ll MOD = 1000000007;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};

#include <algorithm>
#include <assert.h>
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>

#include <unordered_map>
#include <unordered_set>








namespace togasat {
using Var = int;
using CRef = int;
using lbool = int;
const CRef CRef_Undef = -1;
class Solver {

private:
  const lbool l_True = 0;
  const lbool l_False = 1;
  const lbool l_Undef = 2;

  const int var_Undef = -1;

  

  struct Lit {
    int x;
    inline bool operator==(Lit p) const { return x == p.x; }
    inline bool operator!=(Lit p) const { return x != p.x; }
    inline bool operator<(Lit p) const { return x < p.x; }
    inline Lit operator~() {
      Lit q;
      q.x = x ^ 1;
      return q;
    }
  };

  inline Lit mkLit(Var var, bool sign) {
    Lit p;
    p.x = var + var + sign;
    return p;
  };
  inline bool sign(Lit p) const { return p.x & 1; }
  inline int var(Lit p) const { return p.x >> 1; }
  inline int toInt(Var v) { return v; }
  inline int toInt(Lit p) { return p.x; }
  inline Lit toLit(int x) {
    Lit p;
    p.x = x;
    return p;
  }
  const Lit lit_Undef = {-2};
  const Lit lit_Error = {-1};

  

  

  struct VarData {
    CRef reason;
    int level;
  };
  inline VarData mkVarData(CRef cr, int l) {
    VarData d = {cr, l};
    return d;
  }
  

  struct Watcher {
    CRef cref;
    Lit blocker;
    Watcher() {}
    Watcher(CRef cr, Lit p) : cref(cr), blocker(p) {}
    bool operator==(const Watcher &w) const { return cref == w.cref; }
    bool operator!=(const Watcher &w) const { return cref != w.cref; }
  };

  

  class Clause {
  public:
    struct {
      bool learnt;
      int size;
    } header;
    std::vector<Lit> data; 

    Clause() {}
    Clause(const std::vector<Lit> &ps, bool learnt) {
      header.learnt = learnt;
      header.size = ps.size();
      

      data.resize(header.size);
      for (int i = 0; i < ps.size(); i++) {
       	data[i] = ps[i];
      

       }
    }

    int size() const { return header.size; }
    bool learnt() const { return header.learnt; }
    Lit &operator[](int i) { return data[i]; }
    Lit operator[](int i) const { return data[i]; }
  };

  CRef allocClause(std::vector<Lit> &ps, bool learnt = false) {
    static CRef res = 0;
    ca[res] = std::move(Clause(ps, learnt));
    return res++;
  }

  Var newVar(bool sign = true, bool dvar = true) {
    int v = nVars();

    assigns.emplace_back(l_Undef);
    vardata.emplace_back(mkVarData(CRef_Undef, 0));
    activity.emplace_back(0.0);
    seen.emplace_back(false);
    polarity.emplace_back(sign);
    decision.emplace_back(0);
    setDecisionVar(v, dvar);
    return v;
  }

  bool addClause_(std::vector<Lit> &ps) {
    

    

    if (ps.size() == 0) {
      return false;
    } else if (ps.size() == 1) {
      uncheckedEnqueue(ps[0]);
    } else {
      CRef cr = allocClause(ps, false);
      

      attachClause(cr);
    }

    return true;
  }
  void attachClause(CRef cr) {
    const Clause &c = ca[cr];

    assert(c.size() > 1);

    watches[(~c[0]).x].emplace_back(Watcher(cr, c[1]));
    watches[(~c[1]).x].emplace_back(Watcher(cr, c[0]));
  }

  

  void readClause(const std::string &line, std::vector<Lit> &lits) {
    lits.clear();
    int parsed_lit, var;
    parsed_lit = var = 0;
    bool neg = false;
    std::stringstream ss(line);
    while (ss) {
      int val;
      ss >> val;
      if (val == 0)
        break;
      var = abs(val) - 1;
      while (var >= nVars()) {
        newVar();
      }
      lits.emplace_back(val > 0 ? mkLit(var, false) : mkLit(var, true));
    }
  }

  std::unordered_map<CRef, Clause> ca; 

  std::unordered_set<CRef> clauses;    

  std::unordered_set<CRef> learnts;
  std::unordered_map<int, std::vector<Watcher>> watches;
  std::vector<VarData> vardata; 

  std::vector<bool> polarity;   

  std::vector<bool> decision;
  std::vector<bool> seen;
  

  int qhead;
  std::vector<Lit> trail;
  std::vector<int> trail_lim;
  

  std::set<std::pair<double, Var>> order_heap;
  std::vector<double> activity;
  double var_inc;
  std::vector<Lit> model;
  std::vector<Lit> conflict;
  int nVars() const { return vardata.size(); }
  int decisionLevel() const { return trail_lim.size(); }
  void newDecisionLevel() { trail_lim.emplace_back(trail.size()); }

  inline CRef reason(Var x) const { return vardata[x].reason; }
  inline int level(Var x) const { return vardata[x].level; }
  inline void varBumpActivity(Var v){
    std::pair<double, Var> p = std::make_pair(activity[v], v);
    activity[v] += var_inc;
    if (order_heap.erase(p) == 1){
      order_heap.emplace(std::make_pair(activity[v], v));
    }

    if (activity[v] > 1e100){
      

      std::set<std::pair<double,Var>> tmp_order;
      tmp_order = std::move(order_heap);
      order_heap.clear();
      for (int i = 0; i < nVars(); i++){
	activity[i] *= 1e-100;
      }
      for (auto &val : tmp_order){
	order_heap.emplace(std::make_pair(activity[val.second], val.second));
      }
      var_inc *= 1e-100;
    }

  }
  bool satisfied(const Clause &c) const {
    for (int i = 0; i < c.size(); i++) {
      if (value(c[i]) == l_True) {
        return true;
      }
    }
    return false;
  }
  lbool value(Var p) const { return assigns[p]; }
  lbool value(Lit p) const {
    if (assigns[var(p)] == l_Undef) {
      return l_Undef;
    }
    return assigns[var(p)] ^ sign(p);
  }
  void setDecisionVar(Var v, bool b) {
    decision[v] = b;
    order_heap.emplace(std::make_pair(0.0, v));
  }
  void uncheckedEnqueue(Lit p, CRef from = CRef_Undef) {
    assert(value(p) == l_Undef);
    assigns[var(p)] = sign(p);
    vardata[var(p)] = std::move(mkVarData(from, decisionLevel()));
    trail.emplace_back(p);
  }
  

  Lit pickBranchLit() {
    Var next = var_Undef;
    while (next == var_Undef or value(next) != l_Undef) {
      if (order_heap.empty()) {
        next = var_Undef;
        break;
      } else {
	auto p = *order_heap.rbegin();
        next = p.second;
        order_heap.erase(p);
      }
    }
    return next == var_Undef ? lit_Undef : mkLit(next, polarity[next]);
  }
  

  void analyze(CRef confl, std::vector<Lit> &out_learnt, int &out_btlevel) {
    int pathC = 0;
    Lit p = lit_Undef;
    int index = trail.size() - 1;
    out_learnt.emplace_back(mkLit(0, false));
    do {
      assert(confl != CRef_Undef);
      Clause &c = ca[confl];
      for (int j = (p == lit_Undef) ? 0 : 1; j < c.size(); j++) {
        Lit q = c[j];
        if (not seen[var(q)] and level(var(q)) > 0) {
	  varBumpActivity(var(q));
          seen[var(q)] = 1;
          if (level(var(q)) >= decisionLevel()) {
            pathC++;
          } else {
            out_learnt.emplace_back(q);
          }
        }
      }
      while (not seen[var(trail[index--])])
        ;
      p = trail[index + 1];
      confl = reason(var(p));
      seen[var(p)] = 0;
      pathC--;
    } while (pathC > 0);

    out_learnt[0] = ~p;

    

    if (out_learnt.size() == 1) {
      out_btlevel = 0;
    } else {
      int max_i = 1;
      for (int i = 2; i < out_learnt.size(); i++) {
        if (level(var(out_learnt[i])) > level(var(out_learnt[max_i]))) {
          max_i = i;
        }
      }

      Lit p = out_learnt[max_i];
      out_learnt[max_i] = out_learnt[1];
      out_learnt[1] = p;
      out_btlevel = level(var(p));
    }

    for (int i = 0; i < out_learnt.size(); i++) {
      seen[var(out_learnt[i])] = false;
    }
  }

  

  void cancelUntil(int level) {
    if (decisionLevel() > level) {
      for (int c = trail.size() - 1; c >= trail_lim[level]; c--) {
        Var x = std::move(var(trail[c]));
        assigns[x] = l_Undef;
        polarity[x] = sign(trail[c]);
        order_heap.emplace(std::make_pair(activity[x], x));
      }
      qhead = trail_lim[level];
      trail.erase(trail.end() - (trail.size() - trail_lim[level]), trail.end());
      trail_lim.erase(trail_lim.end() - (trail_lim.size() - level),
                      trail_lim.end());
    }
  }
  CRef propagate() {
    CRef confl = CRef_Undef;
    int num_props = 0;
    while (qhead < trail.size()) {
      Lit p = trail[qhead++]; 

      std::vector<Watcher> &ws = watches[p.x];
      std::vector<Watcher>::iterator i, j, end;
      num_props++;

      for (i = j = ws.begin(), end = i + ws.size(); i != end;) {
        

        Lit blocker = i->blocker;
        if (value(blocker) == l_True) {
          *j++ = *i++;
          continue;
        }

        CRef cr = i->cref;
        Clause &c = ca[cr];
        Lit false_lit = ~p;
        if (c[0] == false_lit)
          c[0] = c[1], c[1] = false_lit;
        assert(c[1] == false_lit);
        i++;

        Lit first = c[0];
        Watcher w = Watcher(cr, first);
        if (first != blocker && value(first) == l_True) {
          *j++ = w;
          continue;
        }

        

        for (int k = 2; k < c.size(); k++)
          if (value(c[k]) != l_False) {
            c[1] = c[k];
            c[k] = false_lit;
            watches[(~c[1]).x].emplace_back(w);
            goto NextClause;
          }
        *j++ = w;
        if (value(first) == l_False) { 

          confl = cr;
          qhead = trail.size();
          while (i < end)
            *j++ = *i++;
        } else {
          uncheckedEnqueue(first, cr);
        }
      NextClause:;
      }
      int size = i - j;
      ws.erase(ws.end() - size, ws.end());
    }
    return confl;
  }

  static double luby(double y, int x) {

    

    

    int size, seq;
    for (size = 1, seq = 0; size < x + 1; seq++, size = 2 * size + 1)
      ;

    while (size - 1 != x) {
      size = (size - 1) >> 1;
      seq--;
      x = x % size;
    }

    return pow(y, seq);
  }

  lbool search(int nof_conflicts) {
    int backtrack_level;
    std::vector<Lit> learnt_clause;
    learnt_clause.emplace_back(mkLit(-1, false));
    int conflictC = 0;
    while (true) {
      CRef confl = propagate();

      if (confl != CRef_Undef) {
        

        conflictC++;
        if (decisionLevel() == 0)
          return l_False;
        learnt_clause.clear();
        analyze(confl, learnt_clause, backtrack_level);
        cancelUntil(backtrack_level);
        if (learnt_clause.size() == 1) {
          uncheckedEnqueue(learnt_clause[0]);
        } else {
          CRef cr = allocClause(learnt_clause, true);
          

          attachClause(cr);
          uncheckedEnqueue(learnt_clause[0], cr);
        }
	

	var_inc *= 1.05;
      } else {
        

        if ((nof_conflicts >= 0 and conflictC >= nof_conflicts)) {
          cancelUntil(0);
          return l_Undef;
        }
        Lit next = pickBranchLit();

        if (next == lit_Undef) {
          return l_True;
        }
        newDecisionLevel();
        uncheckedEnqueue(next);
      }
    }
  };

public:
  std::vector<lbool> assigns; 

                              

  lbool answer;               

  Solver() { qhead = 0; }
  void parseDimacsProblem(std::string problem_name) {
    std::vector<Lit> lits;
    int vars = 0;
    int clauses = 0;
    std::string line;
    std::ifstream ifs(problem_name, std::ios_base::in);
    while (ifs.good()) {
      getline(ifs, line);
      if (line.size() > 0) {
        if (line[0] == 'p') {
          sscanf(line.c_str(), "p cnf %d %d", &vars, &clauses);
        } else if (line[0] == 'c' or line[0] == 'p') {
          continue;
        } else {
          readClause(line, lits);
          if (lits.size() > 0)
            addClause_(lits);
        }
      }
    }
    ifs.close();
  }
  lbool solve() {
    model.clear();
    conflict.clear();
    lbool status = l_Undef;
    answer = l_Undef;
    var_inc = 1.01;
    int curr_restarts = 0;
    double restart_inc = 2;
    double restart_first = 100;
    while (status == l_Undef) {
      double rest_base = luby(restart_inc, curr_restarts);
      status = search(rest_base * restart_first);
      curr_restarts++;
    }
    answer = status;
    return status;
  };

  void addClause(std::vector<int> &clause) {
    std::vector<Lit> lits;
    lits.resize(clause.size());
    for (int i = 0; i < clause.size(); i++) {
      int var = abs(clause[i]) - 1;
      while (var >= nVars())
        newVar();
      lits[i] = std::move((clause[i] > 0 ? mkLit(var, false) : mkLit(var, true)));
    }
    addClause_(lits);
  }
  void printAnswer() {
    if (answer == 0) {
      std::cout << "SAT" << std::endl;
      for (int i = 0; i < assigns.size(); i++) {
        if (assigns[i] == 0) {
          std::cout << (i + 1) << " ";
        } else {
          std::cout << -(i + 1) << " ";
        }
      }
      std::cout << "0" << std::endl;
    } else {
      std::cout << "UNSAT" << std::endl;
    }
  }
};
}
int N;
vector<pii> couples;
int main(){
  scanf("%d", &N);
  togasat::Solver toga_sat;
  vector<int> clause(2);
  couples.resize(N);
  for (int i = 0; i < N; i++){
    int a,b;
    scanf("%d %d", &a, &b);
    couples[i] = mp(a, b);
    clause[0] = a;
    clause[1] = b;
    toga_sat.addClause(clause);
    clause[0] = -a;
    clause[1] = -b;
    toga_sat.addClause(clause);
  }
  clause.resize(3);
  for (int i = 0; i < 2 * N; i++){
    int a,b,c;
    a = i;
    b = (a + 1) % (2 * N);
    c = (b + 1) % (2 * N);
    a++;
    b++;
    c++;
    clause[0] = a;
    clause[1] = b;
    clause[2] = c;
    toga_sat.addClause(clause);
    clause[0] = -a;
    clause[1] = -b;
    clause[2] = -c;
    toga_sat.addClause(clause);
  }
  togasat::lbool status = toga_sat.solve();
  if (status == 0){

    for (int i = 0; i < N; i++){
      int a,b;
      a = couples[i].first;
      b = couples[i].second;
      int res1,res2;
      res1 = toga_sat.assigns[a - 1];
      res1++;
      res2 = toga_sat.assigns[b - 1];
      res2++;
      printf("%d %d\n", res1, res2);
    }
  }else{
    cout << -1 << endl;
  }
}
