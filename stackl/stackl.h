#ifndef STACKL_H
#define STACKL_H
#include <iosfwd>

class StackL
{
public:
	StackL() = default;
	StackL(StackL& z);
	~StackL();
	void push(const int& v);
	void pop();
	int& top();
	const int& top() const;
	bool isEmpty() const;

	std::ostream& writeTo(std::ostream& ostrm) const;

private:
	struct Node
	{
		Node* pNext_{ nullptr };
		int data_{ 0 };
		Node(Node* pNext, const int& v)
			:pNext_(pNext)
			,data_(v)
		{
		}
	};
	Node* pHead_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const StackL& z)
{
	return z.writeTo(ostrm);
}

#endif