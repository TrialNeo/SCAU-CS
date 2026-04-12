#include <stack>
#include <iostream>
using namespace std;

int main(){
    unsigned n = 0;
    stack<size_t> st;
    cin >> n;
    while(n != 0){
        st.push(n%8);
        n /= 8;
    }
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    return 0;
}
