
class Solution {
    void rec(string& w, int p, int n, int no, int nc, vector<string>& v) {
        if (no) {
            w[p] = '(';
            rec(w, p+1, n, no - 1, nc + 1, v);
        }
        if (nc) {
            w[p] = ')';
            rec(w, p+1, n, no, nc - 1, v);
        }
        if (no == 0 && nc == 0) {
            v.push_back(w);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string w(2 * n, ' ');
        vector<string> v;
        /*
        w : string
        p : siguiente caracter
        n : total de parentesis
        no : cuantos quedan por abrir
        nc : cuantos quedan por cerrar
         */
        rec(w, 0, n, n, 0, v);
        return v;
    }
};