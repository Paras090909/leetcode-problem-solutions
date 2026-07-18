class Solution {

private:
    void solve(int n, int openP, int closeP, vector<string>&res, string &tmp){
        // base case
        if(openP == n && closeP == n){
            res.push_back(tmp);
            return ;
        }
        // for choosing that can  we take the open parantheses
        if(openP < n){
            tmp.push_back('(');
            solve(n, openP+1, closeP, res, tmp);
            tmp.pop_back();
        }

        // for choosing can we take the close parantheses
        if(closeP < openP){
            tmp.push_back(')');
            solve(n, openP, closeP+1, res, tmp);
            tmp.pop_back();
        }
        return ;
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string tmp = "";
        int openP = 0, closeP = 0;
        solve(n, openP, closeP, res, tmp);
        return res;
    }
};