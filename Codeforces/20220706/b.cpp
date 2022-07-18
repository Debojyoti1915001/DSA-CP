#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
The program doesn't handle the unbalanced parantheses,
that logic can be create easily with stacks, and it is exercise
*/

// Precedence of basic operators
int precedence(char operate) {
	if (operate == '+' || operate == '-')
		return 1;
	else if (operate == '*' || operate == '/')
		return 2;
	else if (operate == '^')
		return 3;
	return 0;
}

// utility to find if character is a operand.
bool isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')' || x == '^')
		return false;
	return true;
}

// Algorithm1
// Utility to create Postfix expression
vector<string> InfixtoPostfix(string s) {
	string string_without_spaces{};

	// Creating a string that doesn't include spaces
	// (it is not mandatory, but will decrease the efforts in further steps).
	for (auto x : s)
		if (x != ' ')
			string_without_spaces += x;
	int length = string_without_spaces.size();

	stack<char> Operators;	// It will store our operators
	Operators.push('#');	// '#' will act as a sentinel, to avoid collision with empty stack

	/*
	result will store our Postfix expression, where
	each value in result, is either an operator, or an
	operand.
	*/
	vector<string> result;
	int i = 0, j = 0;
	while (i < length) {

		// If Operand, we find the full number starting at index i
		if (isOperand(string_without_spaces[i])) {
			string this_number{};
			while (i < string_without_spaces.size() && isOperand(string_without_spaces[i]))
				this_number += string_without_spaces[i++];
			result.push_back(this_number);
		}

		// If the Current character is '(', we simply push
		else if (string_without_spaces[i] == '(')
			Operators.push(s[i++]);

		/*
		 If the current character is ')', we get all operators occuring before
		 the character '('.
		*/
		else if (string_without_spaces[i] == ')') {
			while (Operators.top() != '#' && Operators.top() != '(') {
				result.push_back(string(1, Operators.top()));
				Operators.pop();
			}
			if (Operators.top() == '(')
				Operators.pop();
			i++;
		}

		// If the current character is a operator, we find it's appropriate place.
		else {
			string temporary{};
			while (Operators.top() != '#' &&
			        precedence(Operators.top()) >= precedence(string_without_spaces[i])) {

				temporary = string(1, Operators.top());
				result.push_back(temporary);
				Operators.pop();
			}
			Operators.push(s[i++]);
		}
	}

	// If there are still some operators left, we simply get those operators.
	while (Operators.top() != '#') {
		result.push_back((Operators.top() == '^' ? "^" : string(1, Operators.top())));
		Operators.pop();
	}

	// Just return our result.
	return result;
}


// Algorithm2
// Utility to calculate the value Postfix expression we found
long long evaluate(vector<string> &postfix) {
	int i = 0;
	stack<string> values;
	cout << postfix.size() << endl;
	while (i < postfix.size()) {

		// We know operator will have size 1, but to avoid collision with numbers (with number of digits 1)
		// I anded our basic condition with one more condition i.e. isoperand.
		if (postfix[i].size() == 1 && !isOperand(postfix[i][0])) {
			ll number1 = stoll(values.top(), nullptr, 10);	// Second operand (for binary opeartor)
			values.pop();
			ll number2 = stoll(values.top(), nullptr, 10);	// First Operand (for binary operator)
			values.pop();
			ll result = 0;

			// Our cases for operands
			switch (postfix[i][0]) {
			case '+':
				result = number2 + number1;
				break;
			case '-':
				result = number2 - number1;
				break;
			case '/':
				result = number2 / number1;
				break;
			case '*':
				result = number2 * number1;
				break;
			case '^':
				result = (ll)pow(number2, number1);
				break;
			default:
				break;
			}
			// Pushing the result back to stackafter performing binary operation.
			values.push(to_string(result));
		}
		else
			values.push(postfix[i]);
		i++;
	}
	return stoll(values.top(), nullptr, 10);
}

// Example program to verify our
int main() {
	string exp = "18^2-12^4";
	cout << exp << endl;
	auto postfix = InfixtoPostfix(exp);
	for (auto x : postfix)
		cout << x << " ";
	cout << endl;

	auto result = evaluate(postfix);
	cout << "Our result is : " << result << endl;
}