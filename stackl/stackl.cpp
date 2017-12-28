#include <iostream>
#include <sstream>
#include "stackl.h"

StackL::StackL(StackL& z)
{
	Node* pCopyFrom = z.pHead_->pNext_;
	Node* pCopyTo = new Node(NULL, z.pHead_->data_);
	pHead_ = pCopyTo;
	while (pCopyFrom != NULL)
	{
		pCopyTo->pNext_ = new Node(NULL, pCopyFrom->data_);
		pCopyTo = pCopyTo->pNext_;
		pCopyFrom = pCopyFrom->pNext_;
	}
}
StackL::~StackL()
{
	while (!isEmpty())
	{
		pop();
	}
}
void StackL::pop()
{
	if (!isEmpty())
	{
		Node* pdeleted(pHead_);
		pHead_ = pdeleted->pNext_;
		delete pdeleted;
	}
}
void StackL::push(const int& v)
{
	pHead_ = new Node(pHead_, v);
}
int& StackL::top()
{
	return pHead_->data_;
}
const int& StackL::top() const
{
	return pHead_->data_;
}
bool StackL::isEmpty() const
{
	return pHead_ == NULL;
}

std::ostream& StackL::writeTo(std::ostream& ostrm) const
{
	Node* temp = pHead_;
	while (temp != NULL)
	{
		ostrm << temp->data_;
		temp = temp->pNext_;
	}
	return ostrm;
}
