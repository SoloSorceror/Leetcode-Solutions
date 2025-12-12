class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;

        for (string &t : tokens) {
            if (t == "+") {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();
                st.push_back(b + a);
            }
            else if (t == "-") {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();
                st.push_back(b - a);
            }
            else if (t == "*") {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();
                st.push_back(b * a);
            }
            else if (t == "/") {
                int a = st.back(); st.pop_back();
                int b = st.back(); st.pop_back();
                st.push_back(b / a);  // truncates toward 0 automatically
            }
            else {
                st.push_back(stoi(t));
            }
        }

        return st.back();
    }
};
