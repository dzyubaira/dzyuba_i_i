#include <iostream>
#include <sstream>
#include "stackl.h"

StackL::StackL(StackL& z)
{
	StackL x;
	Node* temp = z.pHead_;
	while (temp != NULL)
	{
		x.push(temp->data_);
		temp = temp->pNext_;
	}
	temp = x.pHead_;
	while (temp != NULL)
	{
		push(temp->data_);
		temp = temp->pNext_;
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