#include <iostream>
#include <string>
#include <stack>    
using namespace std;
//check the priority of of the operator
int prior(char s){
	if(s=='^'){
		return 3;
	}else if(s=='*' || s=='/'){
		return 2;
	}
	else if(s=='+' || s=='-'){
		return 1;
	}else{
		return -1;
	}
}

// Function to reverse the string
string reverse(string s){
    int i = 0;
    int j = s.length() - 1;
    while (i < j) {
        swap(s[i], s[j]);
        i++;
        j--;
    }
    return s;
}


string infixToPostFix(string s){
	//store the operand
	stack<char> st;
	//store the answer
	string ans;
	for(int i=0;i<s.length();i++){
		//if it is an operand
		if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>=0 && s[i]<=9){
			ans.push_back(s[i]);
		}
		//if operand in an opening brackets
		else if(s[i]=='('){
			st.push('(');
		}
		//if operand in an closing bracket then pop from the stack and add to the answer till you you get the opening brackets
		else if(s[i]==')'){
			while(st.top()!='('){
				ans.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
		else{
			//now you get an operator
			//pop from stack untill the upcoming operator has lesser priority then the top operator present at the top of the stack otherwise just store it in stack means push it
			while(!st.empty() && prior(s[i])<=prior(st.top())){
				ans.push_back(st.top());
				st.pop();
			}
			st.push(s[i]);
		}
	}
	//means there is no element left on now just push the left element in the ans
	while(!st.empty()){
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}




// Function to convert infix to prefix
string infixToPrefix(string s) {
    s = reverse(s);  // Reverse the input string
    stack<char> st;
    string ans = "";

    // Step 1: Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Step 2: Convert to prefix (using a stack for operators)
    for (int i = 0; i < s.length(); i++) {
        char a = s[i];

        // If the character is an operand, add it to the result
        if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9')) {
            ans.push_back(a);
        }
        // If it's '(', push it to the stack
        else if (a == '(') {
            st.push(a);
        }
        // If it's ')', pop from the stack until '(' is found
        else if (a == ')') {
            while (!st.empty() && st.top() != '(') {
                ans.push_back(st.top());
                st.pop();
            }
            st.pop();  // Pop '('
        }
        // If it's an operator, handle precedence
        else {
            while (!st.empty() && prior(a) <= prior(st.top())) {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(a);
        }
    }

    // Step 3: Pop all remaining operators from the stack
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    // Step 4: Reverse the result to get the final prefix expression
    s = reverse(ans);
    return s;
}

string postfixToInfix(string s) {
    stack<string> st;
    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            string ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ans = '(' + t2 + s[i] + t1 + ')';  // Combine in infix format
            st.push(ans);
        }
    }
    return st.top();
}

string prefixToInfix(string s) {
    stack<string> st;
    int i = s.length()-1;
    while(i>=0){
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            string ans = string(1, s[i]);  // Convert character to string
            st.push(ans);
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ans = '(' + t1 + s[i] + t2 + ')';  // Combine in infix format
            st.push(ans);
        }
        i--;
    }
    return st.top();
}


string postfixToPrefix(string s) {
    stack<string> st;
    int i = 0;
    for(int i=0;i<s.length();i++ ) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            string ans = string(1, s[i]);
            st.push(ans);
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ans = string(1, s[i]) + t2 + t1;  // Concatenate operator with operands
            st.push(ans);
        }
    }
    return st.top();
}

string prefixToPostfix(string s){
	stack<string> st;
    int i = 0;
    for(int i=s.length()-1;i>=0;i-- ) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            string ans = string(1, s[i]);
            st.push(ans);
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string ans = t1 + t2 + string(1, s[i]) ;  // Concatenate operator with operands
            st.push(ans);
        }
    }
    return st.top();
}

int main(){
	cout<<"Stack conversions"<<endl;
	string s = "*-A/BC-/AKL";
	string ans = prefixToPostfix(s);
	cout<<"Infix string = "<<s<<endl;
	cout<<"PostFix string = "<<ans<<endl;
	return 0;
}