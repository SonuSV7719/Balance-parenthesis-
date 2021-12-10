#include<iostream>
#include<string>
#define MAX 100
using namespace std;

template <typename T>
class stack
{
	T stackArr[MAX];
	int top;
	public:
	stack(){
		top = -1;
	}
	bool isFull();
	bool isEmpty();
	void push(T data);
	void pop();
	int topPos();
	T operator [](int index);	
};

template <typename T>
int stack<T>::topPos()
{
	return top;
}

template <typename T>
T stack<T>::operator [](int index)
{
	return stackArr[index];
}

template <typename T>
bool stack<T>::isFull()
{
	if (top>=MAX)
		return 1;
	else
		return 0;
	
}

template <typename T>
bool stack<T>::isEmpty()
{
	if (top==-1)
		return 1;
	else
		return 0;	
}

template <typename T>
void stack<T>::push(T data)
{
	if (isFull())
		cout<<"Stack is Full"<<endl;
	else
	{
		top++;
		stackArr[top] = data;
		
	}
}

template <typename T>
void stack<T>::pop() {
   if(isEmpty())
   cout<<"Stack empty"<<endl;
   else {
      	
    	top--;
   }
}

int main()
{
	string paren;
	stack<char> s1;
	int flag = 0;
	cout<<"Enter parenthesis sting to check its balanced or not: ";
	cin>>paren;
	
	for (int i=0; i<paren.size(); i++)
	{
		if (paren[0] == '[' or paren[0] == '(' or paren[0] == '{' or paren[0] == '<')
		{
			if (paren[i] == '[' or paren[i] == '(' or paren[i] == '{' or paren[i] == '<')
			{
				s1.push(paren[i]);
			}
			if (paren[i] == ']' or paren[i] == ')' or paren[i] == '}' or paren[i] == '>')
			{
				
				if (s1[s1.topPos()] == '[' or s1[s1.topPos()] == '(' or s1[s1.topPos()] == '{' or s1[s1.topPos()] == '<')
				{
					if (i == paren.size()-1)
					{
						flag = 1;
					}
					s1.pop();
				}
				
			}
		}
		if (paren[0] == ']' or paren[0] == ')' or paren[0] == '}' or paren[0] == '>')
		{
					if (paren[i] == ']' or paren[i] == ')' or paren[i] == '}' or paren[i] == '>')
				{
					s1.push(paren[i]);
				}
				if (paren[i] == '[' or paren[i] == '(' or paren[i] == '{' or paren[i] == '<')
				{
					
					if (s1[s1.topPos()] == ']' or s1[s1.topPos()] == ')' or s1[s1.topPos()] == '}' or s1[s1.topPos()] == '>')
					{
						if (i == paren.size()-1)
						{
							flag = 1;
						}
						s1.pop();
					}
				}
		}
	}
	if(s1.isEmpty() and flag == 1)
	{
		cout<<"Parenthesis are balanced"<<endl;
	}
	else
	{
		cout<<"Parenthesis are not balanced"<<endl;
	}
	return 0;
}
