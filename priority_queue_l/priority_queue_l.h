#ifndef PRIORITY_QUEUE_L_H
#define PRIORITY_QUEUE_L_H
#include <iosfwd>

class PriorityQueueL
{
public:
	PriorityQueueL() = default;
	void push(const int& v);
	void pop();
	bool isEmpty() const;

	std::ostream& writeTo(std::ostream& ostrm) const;

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
	Node* pTail_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const PriorityQueueL& z)
{
	return z.writeTo(ostrm);
}
#endif