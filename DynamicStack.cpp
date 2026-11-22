#include <iostream>
#include <string.h>
#include <time.h>
#include <stdexcept>

using namespace std;

template <typename T>

class Stack
{
	enum { EMPTY = -1, FULL = 4 };
	T* st;

	int top;
	int capacity;
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	void Push(T value);
	T Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Show();

	~Stack();

};

template <typename T>
Stack<T>::Stack()
{
	capacity = FULL;
	st = new T[capacity];
	top = EMPTY;

}

template <typename T>
Stack<T>::Stack(const Stack& other)
{
	capacity = other.capacity;
	top = other.top;

	st = new T[capacity];

	for (int i = 0; i <= top; i++)
	{
		st[i] = other.st[i];
	}
	
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
	if (this == &other)
		return *this;

	T* temp = new T[other.capacity];

	for (int i = 0; i <= other.top; i++)
	{
		temp[i] = other.st[i];
	}

	delete[] st;

	st = temp;

	capacity = other.capacity;
	top = other.top;

	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] st;
}

template <typename T>
void Stack<T>::Clear()
{
	top = EMPTY;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	return top == EMPTY;
}

template <typename T>
bool Stack<T>::IsFull()
{
	return capacity - 1 == top;
}

template <typename T>
void Stack<T>::Push(T value)
{
	if (!IsFull())
	{
		st[++top] = value;
	}
	else
	{
		T* temp = new T[++capacity];
		
		for (int i = 0; i <= top; i++)
		{
			temp[i] = st[i];
		}

		delete[] st;

		st = temp;
		st[++top] = value;
	}
	
}

template <typename T>
T Stack<T>::Pop()
{
	if (!IsEmpty())
	{
		return st[top--];
	}
	else
		throw runtime_error("Stack is empty!");
}

template <typename T>
int Stack<T>::GetCount()
{
	return top + 1;
}

template <typename T>
void Stack<T>::Show()
{
	for (int i = 0; i <= top; i++)
	{
		cout << st[i] << " ";
	}

}

void CheckBrackets(const string& equation)
{
	Stack<char> value;

	bool isCorrect = true;

	for (int i = 0; i < equation.length(); i++)
	{
		if (equation[i] != ';')
		{
			if (equation[i] == '(' || equation[i] == '[' || equation[i] == '{')
			{
				value.Push(equation[i]);
			}
			else if (equation[i] == ')' || equation[i] == ']' || equation[i] == '}')
			{
				if (!value.IsEmpty())
				{
					char temp = value.Pop();

					if ((temp == '(' && equation[i] == ')') || (temp == '[' && equation[i] == ']') || (temp == '{' && equation[i] == '}'))
					{

					}
					else
					{
						isCorrect = false;
						cout << "The equation is incorrect." << endl;

						for (int j = 0; j < i; j++)
						{
							cout << equation[j];
						}
						cout << endl;
						break;

					}
				}

				else
				{
					isCorrect = false;
					cout << "The equation is incorrect." << endl;

					for (int j = 0; j < i; j++)
					{
						cout << equation[j];
					}
					cout << endl;
					break;
				}
			}
		}
		else
			break;
	}

	if (isCorrect)
	{
		if (value.IsEmpty())
		{
			cout << "The equation is correct." << endl;
		}
		else
		{
			cout << "The equation is incorrect." << endl;

			for (int j = 0; equation[j] != ';'; j++)
			{
				cout << equation[j];
			}

			cout << endl;
		}

	}
}

int main()
{
	// Task 1
	/*
	Stack<int> s;

	cout << "Initial count: " << s.GetCount() << endl;

	for (int i = 1; i <= 10; i++)
	{
		s.Push(i);
	}

	cout << "\nCount after Push: " << s.GetCount() << endl;

	cout << "\nPop elements:\n";

	while (!s.IsEmpty())
	{
		cout << s.Pop() << " ";
	}

	cout << "\nCount after Pop: " << s.GetCount() << endl;

	cout << "\nException test:\n";

	try
	{
		s.Pop();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	for (int i = 1; i <= 5; i++)
	{
		s.Push(i);
	}

	s.Clear();

	cout << "\nCount after Clear: " << s.GetCount() << endl;*/

	// Task 2
	string equation1 = "({ x - y - z } * [x + 2y] - (z + 4x));";
	string equation2 = "({ x - y - z } * [x + 2y - (z + 4x));";
	string equation3 = "({ x - y - z } * [x + 2y] - (z + 4x);";

	CheckBrackets(equation1);
	CheckBrackets(equation2);
	CheckBrackets(equation3);
	

	return 0;
	}