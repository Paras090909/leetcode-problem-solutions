class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>st;
        st.push(0);
        for( char ch : s){
            if(ch == '('){
                st.push(0);
            }else{
                int rec_last = st.top();
                st.pop();

                int prev_count;

                if(rec_last == 0){
                    prev_count = 1;
                }else{
                    prev_count = rec_last*2;
                }

                st.top()+=prev_count;
            }
        }
        return st.top();
    }
};