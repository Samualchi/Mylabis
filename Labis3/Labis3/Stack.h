#define MemSize 100

template <class TypeVal>
class Stack
{
private: TypeVal* pMem;
	   int size;
	   int top;
public:
	Stack(const int n = MemSize);
	~Stack();

	bool Empty();
	bool Full();
	void push(TypeVal Elem);
	TypeVal pop();
	TypeVal watch_top_stek();

	int GetSize() const { return size; }
};

template <class TypeVal>
Stack<TypeVal>::Stack(const int n)
{
	if ((n < 0) || (n > MemSize)) throw 'Neg';
	pMem = new TypeVal[n];
	size = n;
	top = -1;
}

template <class TypeVal>
Stack<TypeVal>::~Stack()
{
	delete[]pMem;
}

template <class TypeVal>
bool Stack<TypeVal>::Empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template <class TypeVal>
bool Stack<TypeVal>::Full()
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

template<class TypeVal>
void Stack<TypeVal>::push(TypeVal elem)
{
	if (Full() == true) throw 'Full';
	else
		pMem[++top] = elem;
}

template <class TypeVal>
TypeVal Stack<TypeVal>::pop()
{
	if (Empty()) throw 'Emp';
	else
		return pMem[top--];
}

template <class TypeVal>
TypeVal Stack<TypeVal>::watch_top_stek()
{
	return pMem[top];
}