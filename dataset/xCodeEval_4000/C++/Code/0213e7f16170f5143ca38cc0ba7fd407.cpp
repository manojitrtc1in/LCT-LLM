#include <bits/stdc++.h>
#ifndef _LIB_LINEAR_PROGRAM
#define _LIB_LINEAR_PROGRAM
#include <bits/stdc++.h>
#ifndef _LIB_SYMBOLIC
#define _LIB_SYMBOLIC
#include <bits/stdc++.h>

namespace lib {
using namespace std;
    int g_VAR_PTR = 0;

    enum Operation { variable, literal, sum };

    template<typename T>
    struct Variable;

    template<typename T>
    struct BasicExp {
        using node = shared_ptr<BasicExp<T>>;
        using variable = Variable<T>;

        T coef = 1;
        Operation op;
        vector<node> children;
        variable var;

        BasicExp(Operation n_op, const vector<node>& n_children, T n_coef = 1);
        BasicExp(const T& v);

        BasicExp(const Variable<T>& v);

        bool has_children() const {
            return op != Operation::variable && op != Operation::literal;
        }

        Variable<T> get_variable() const { return var; }
    };

    template<typename T>
    using Expression = shared_ptr<BasicExp<T>>;

    template<typename T, typename... Args>
    Expression<T> make_exp(Args&&... args) {
        return make_shared<BasicExp<T>, Args...>(std::forward<Args>(args)...);
    }

    template<typename T>
    struct Variable {
        int id;

        static Variable<T> get_variable() {
            return {g_VAR_PTR++};
        }

        static vector<Variable<T>> get_variables(int n) {
            vector<Variable<T>> vars(n);
            for(int i = 0; i < n; i++) vars[i] = get_variable();
            return vars;
        }

        static Expression<T> get_exp_variable() {
            return Variable<T>::get_variable().as_exp();
        }

        static vector<Expression<T>> get_exp_variables(int n) {
            vector<Expression<T>> vs(n);
            int i = 0;
            for(const auto & v : Variable<T>::get_variables(n)) {
                vs[i++] = v.as_exp();
            }
            return vs;
        }

        operator Expression<T>() const {
            return make_exp<T>(*this);
        }

        Expression<T> as_exp() const {
            return Expression<T>(*this);
        }

        bool operator<(const Variable<T>& rhs) const {
            return id < rhs.id;
        }
    };

    template<typename T>
    BasicExp<T>::BasicExp(Operation n_op, const vector<node>& n_children, T n_coef)
        : op(n_op), children(n_children), coef(n_coef) {}

    template<typename T>
    BasicExp<T>::BasicExp(const T& v) {
        op = Operation::literal;
        coef = v;
    }

    template<typename T>
    BasicExp<T>::BasicExp(const Variable<T>& v) {
        op = Operation::variable;
        var = v;
    }

    template<typename T>
    Expression<T>& operator*=(Expression<T>& e, const T& x) {
        e->coef *= x;
        return e;
    }

    template<typename T>
    Expression<T> operator*(const Expression<T>& e, const T& x) {
        auto res = make_exp<T>(*e);
        return res *= x;
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const Expression<T>& rhs) {
        if(e->op == Operation::sum) {
            e->children.push_back(rhs);
        } else {
            e = make_exp<T>(Operation::sum, vector<Expression<T>>{e, rhs});
        }
        return e;
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const Variable<T>& rhs) {
        return e += make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T>& operator+=(Expression<T>& e, const T& x) {
        return e += make_exp<T>(x);
    }


    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const Expression<T>& rhs) {
        auto res = e->op == Operation::sum ? make_exp<T>(*e) : e;
        return res += rhs;
    }

    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const Variable<T>& rhs) {
        return e + make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T> operator+(const Expression<T>& e, const T& x) {
        return e + make_exp<T>(x);
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const Expression<T>& rhs) {
        return make_exp<T>(v) + rhs;
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const Variable<T>& rhs) {
        return make_exp<T>(v) + make_exp<T>(rhs);
    }

    template<typename T>
    Expression<T> operator+(const Variable<T>& v, const T& x) {
        return make_exp<T>(v) + make_exp<T>(x);
    }

    template<typename T>
    Expression<T> operator*(const Variable<T>& v, const T& x) {
        return make_exp<T>(v) * x;
    }

    template<typename T>
    struct ExpressionVisitor {
        void visit(const Expression<T>& e) {
            if(e->op == Operation::sum)
                this->visit_sum(e);
            else if(e->op == Operation::variable)
                this->visit_variable(e);
            else if(e->op == Operation::literal)
                this->visit_literal(e);
        }
        virtual void visit_children(const Expression<T>& e) {
            if(e->has_children()) {
                for(const Expression<T>& child : e->children)
                    this->visit(child);
            }
        }

        virtual void visit_sum(const Expression<T>& e) {
            this->visit_children(e);
        }
        virtual void visit_variable(const Expression<T>& e) {}
        virtual void visit_literal(const Expression<T>& e) {}
    };

    template<typename T>
    struct VariableVisitor : ExpressionVisitor<T> {
        set<Variable<T>> seen;
        virtual void visit_variable(const Expression<T>& e) {
            seen.insert(e->var);   
        }
    };

    template<typename T, typename S = T>
    struct StackVisitor : ExpressionVisitor<T> {
        vector<S> sta;
        virtual void visit_children(const Expression<T>& e) override {
            sta.push_back(sta.empty() ? e->coef : sta.back() * e->coef);
            ExpressionVisitor<T>::visit_children(e);
            if(!sta.empty()) sta.pop_back();
        }
        S top() const { return sta.empty() ? S(1) : sta.back(); }
    };

    template<typename T>
    struct EvalVisitor : StackVisitor<T> {
        map<Variable<T>, T> values;
        T result;
        T eval(const Expression<T>& e, const map<Variable<T>, T>& values) {
            result = T();
            this->values = values;
            this->visit(e);
            return result;
        }
        virtual void visit_variable(const Expression<T>& e) override {
            result += this->top() * e->coef * values[e->var];
        }
        virtual void visit_literal(const Expression<T>& e) override {
            result += this->top() * e->coef;
        }
    };

    enum ConstraintOperation {
        equals, different, greater, less, greater_eq, less_eq
    };

    template<typename T>
    struct Constraint {
        Expression<T> lhs, rhs;
        ConstraintOperation op;
        Constraint(const Expression<T>& a, const Expression<T>& b, ConstraintOperation op) : lhs(a), rhs(b), op(op) {}
    };

    template<typename T>
    Constraint<T> operator==(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::equals);
    }

    template<typename T>
    Constraint<T> operator!=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::different);
    }

    template<typename T>
    Constraint<T> operator>=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::greater_eq);
    }

    template<typename T>
    Constraint<T> operator<=(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::less_eq);
    }

    template<typename T>
    Constraint<T> operator>(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::greater);
    }

    template<typename T>
    Constraint<T> operator<(const Expression<T>& a, const Expression<T>& b) {
        return Constraint<T>(a, b, ConstraintOperation::less);
    }

    template<typename T>
    T eval(const Expression<T>& e, const map<Variable<T>, T>& values) {
        auto visitor = std::make_unique<EvalVisitor<T>>();
        return visitor->eval(e, values);
    }

}  


#endif
#ifndef _LIB_SIMPLEX
#define _LIB_SIMPLEX
#include <bits/stdc++.h>

namespace lib {
using namespace std;
    template<typename DOUBLE>
    struct LPSolver {
        typedef vector<DOUBLE> VD;
        typedef vector<VD> VVD;
        typedef vector<int> VI;

        constexpr static DOUBLE EPS = 1e-9;

        int m, n;
        VI B, N;
        VVD D;

        LPSolver(const VVD &A, const VD &b, const VD &c) :
            m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, VD(n + 2)) {
            for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) D[i][j] = A[i][j];
            for (int i = 0; i < m; i++) { B[i] = n + i; D[i][n] = -1; D[i][n + 1] = b[i]; }
            for (int j = 0; j < n; j++) { N[j] = j; D[m][j] = -c[j]; }
            N[n] = -1; D[m + 1][n] = 1;
        }

        void Pivot(int r, int s) {
            for (int i = 0; i < m + 2; i++) if (i != r)
            for (int j = 0; j < n + 2; j++) if (j != s)
                D[i][j] -= D[r][j] * D[i][s] / D[r][s];
            for (int j = 0; j < n + 2; j++) if (j != s) D[r][j] /= D[r][s];
            for (int i = 0; i < m + 2; i++) if (i != r) D[i][s] /= -D[r][s];
            D[r][s] = 1.0 / D[r][s];
            swap(B[r], N[s]);
        }

        bool Simplex(int phase) {
            int x = phase == 1 ? m + 1 : m;
            while (true) {
            int s = -1;
            for (int j = 0; j <= n; j++) {
                if (phase == 2 && N[j] == -1) continue;
                if (s == -1 || D[x][j] < D[x][s] || D[x][j] == D[x][s] && N[j] < N[s]) s = j;
            }
            if (D[x][s] > -EPS) return true;
            int r = -1;
            for (int i = 0; i < m; i++) {
                if (D[i][s] < EPS) continue;
                if (r == -1 || D[i][n + 1] / D[i][s] < D[r][n + 1] / D[r][s] ||
                    (D[i][n + 1] / D[i][s]) == (D[r][n + 1] / D[r][s]) && B[i] < B[r]) r = i;
            }
            if (r == -1) return false;
            Pivot(r, s);
            }
        }

        DOUBLE Solve(VD &x) {
            int r = 0;
            for (int i = 1; i < m; i++) if (D[i][n + 1] < D[r][n + 1]) r = i;
            if (D[r][n + 1] < -EPS) {
            Pivot(r, n);
            if (!Simplex(1) || D[m + 1][n + 1] < -EPS) return -numeric_limits<DOUBLE>::infinity();
            for (int i = 0; i < m; i++) if (B[i] == -1) {
                int s = -1;
                for (int j = 0; j <= n; j++)
                if (s == -1 || D[i][j] < D[i][s] || D[i][j] == D[i][s] && N[j] < N[s]) s = j;
                Pivot(i, s);
            }
            }
            if (!Simplex(2)) return numeric_limits<DOUBLE>::infinity();
            x = VD(n);
            for (int i = 0; i < m; i++) if (B[i] < n) x[B[i]] = D[i][n + 1];
            return D[m][n + 1];
        }
    };
}  


#endif

namespace lib {
using namespace std;
    template<typename T = double>
    struct LinearProgram {
        struct ConstraintVisitor : StackVisitor<T> {
            const vector<Variable<T>>& vars;
            const vector<Constraint<T>>& consts;

            vector<vector<T>> A;
            vector<T> b;
            T mult;

            ConstraintVisitor(const vector<Variable<T>>& vars, const vector<Constraint<T>>& consts)
                : vars(vars), consts(consts), mult(1) {
                A = vector<vector<T>>();
                b = vector<T>();
            }

            void populate() {
                for(int i = 0; i < consts.size(); i++) {
                    const auto& constraint = consts[i];
                    if(constraint.op == ConstraintOperation::less_eq)
                        visit_constraint(constraint, 1);
                    else if(constraint.op == ConstraintOperation::greater_eq)
                        visit_constraint(constraint, -1);
                    else if(constraint.op == ConstraintOperation::equals)
                        visit_constraint(constraint, 1), visit_constraint(constraint, -1);
                }

                

                

                

                

                

                

            }

            void visit_constraint(const Constraint<T>& constraint, T constraint_mult) {
                A.emplace_back(vars.size());
                b.emplace_back();
                mult *= constraint_mult;
                this->visit(constraint.lhs);
                mult = -mult;
                this->visit(constraint.rhs);
                mult = -mult;
                mult *= constraint_mult;
            }

            int index(const Variable<T>& v) const {
                return lower_bound(vars.begin(), vars.end(), v) - vars.begin();
            }

            virtual void visit_variable(const Expression<T>& e) override {
                A.back()[index(e->var)] += this->top() * e->coef * mult;
            }
            virtual void visit_literal(const Expression<T>& e) override {
                b.back() -= this->top() * e->coef * mult;
            }
        };

        struct ObjectiveVisitor : StackVisitor<T> {
            const vector<Variable<T>>& vars;
            const Expression<T>& obj;

            vector<T> c;
            T mult;

            ObjectiveVisitor(const vector<Variable<T>>& vars, const Expression<T>& obj, T mult)
                : vars(vars), obj(obj), mult(mult) {
                c = vector<T>(vars.size());
            }

            void populate() {
                this->visit(obj);
                

                

                

                

            }

            int index(const Variable<T>& v) const {
                return lower_bound(vars.begin(), vars.end(), v) - vars.begin();
            }

            virtual void visit_variable(const Expression<T>& e) override {
                c[index(e->var)] += this->top() * e->coef * mult;
            }
        };

        vector<Constraint<T>> constraints;
        void add_constraint(Constraint<T> constraint) {
            constraints.push_back(constraint);
        }
        set<Variable<T>> get_variables(const Expression<T>& obj) const {
            auto visitor = make_unique<VariableVisitor<T>>();
            for(const auto& c : constraints) {
                visitor->visit(c.lhs);
                visitor->visit(c.rhs);
            }
            visitor->visit(obj);
            return visitor->seen;
        }
        map<Variable<T>, T> _solve(const Expression<T>& obj, T obj_mult = 1) {
            const auto& variables = get_variables(obj);
            vector<Variable<T>> vs(variables.begin(), variables.end());
            auto visitor = make_unique<ConstraintVisitor>(vs, constraints);
            visitor->populate();
            auto objVisitor = make_unique<ObjectiveVisitor>(vs, obj, obj_mult);
            objVisitor->populate();

            LPSolver<T> solver(visitor->A, visitor->b, objVisitor->c);
            vector<T> ans;
            solver.Solve(ans);
            if(ans.size() < vs.size()) return {};

            map<Variable<T>, T> res;
            for(int i = 0; i < vs.size(); i++)
                res[vs[i]] = ans[i];
            return res;
        }

        map<Variable<T>, T> maximize(const Expression<T>& obj) {
            return _solve(obj);
        }

        map<Variable<T>, T> minimize(const Expression<T>& obj) {
            return _solve(obj, -1);
        }
    };
}  


#endif
#define int long long
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)
 
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}
 
typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

using namespace lib;

const int N = 505;

int d[N][N];
vector<ii> adj[N];
int is_black[N];
int r;

void dfs(int u, int p = -1, int L = 0) {
    d[r][u] = L;
    for(ii e : adj[u]) {
        if(e.ff == p) continue;
        dfs(e.ff, u, L + e.ss);
    }
}

int32_t main(){
    iopt;
    int n, K;
    cin >> n >> K;

    lib::LinearProgram<double> lp;
    auto x = Variable<double>::get_exp_variables(n);

    int black_cnt = 0;
    for(int i = 0; i < n; i++) cin >> is_black[i], black_cnt += is_black[i];

    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    for(int i = 0; i < n; i++) {
        r = i;
        dfs(i);
    }

    auto black_exp = make_exp<double>(0.0);
    for(int i = 0; i < n; i++) {
        auto exp = make_exp<double>(0.0);
        for(int j = 0; j < n; j++) {
            if(d[i][j] <= K) {
                exp += x[j];
            }
        }
        lp.add_constraint(exp >= make_exp<double>(1.0));
        black_exp += x[i];
    }
    lp.add_constraint(black_exp == make_exp<double>(black_cnt));

    auto obj_exp = make_exp<double>(0.0);
    for(int i = 0; i < n; i++)
        if(!is_black[i])
            obj_exp += x[i];
    
    auto result = lp.minimize(obj_exp);
    if(result.empty()) {
        cout << -1 << endl;
        return 0;
    }
    int ans = eval(obj_exp, result) + 0.5;
    cout << ans << endl;
}
