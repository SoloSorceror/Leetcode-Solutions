class Solution {
public:
    int calPoints(vector<string>& op) {
        vector<int> st;
        int n = op.size();
        for(int i=0; i<n; i++){
            if(op[i] == "C"){
                st.pop_back();
            }
            else if(op[i] == "D"){
                int x = st.back() * 2;
                st.push_back(x); 
            }
            else if(op[i] == "+"){
                int y = st.back() + st[st.size()-2];
                st.push_back(y);
            }
            else{
                st.push_back(stoi(op[i]));
            }
        }
        int sum = 0;
        for(auto &a: st){
            sum += a;
        }
        return sum;
    }
};