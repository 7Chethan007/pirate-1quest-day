// Last updated: 3/25/2026, 9:07:13 AM
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string component;

        // Split by '/'
        while (getline(ss, component, '/')) {
            if (component == "" || component == ".") {
                continue;
            } 
            else if (component == "..") {
                if (!st.empty()) st.pop();
            } 
            else {
                st.push(component);
            }
        }

        // Build result
        if (st.empty()) return "/";

        string result = "";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }

        return result;
    }
};