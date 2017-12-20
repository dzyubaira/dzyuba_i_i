#include <iostream>
#include <sstream>
#include "priority_queue_l.h"

void PriorityQueueL:: push(const int& v)
{
	if (!isEmpty())
	{
		pHead_ = new Node(pHead_, v);
		Node* temp = pHead_;
		while ((v > temp->pNext_->data_))
		{
			temp->data_ = temp->pNext_->data_;
			temp->pNext_->data_ = v;
			temp = temp->pNext_;
			if (temp->pNext_ == pTail_)
			{
				break;
			}
		}
	}
	else
	{
		pHead_ = new Node(pHead_, v);
	}

}
void PriorityQueueL::pop()
{
	if (!isEmpty())
	{
		Node* temp = pHead_;
		while (temp->pNext_ != pTail_)
		{
			temp = temp->pNext_;
		}
		pTail_ = temp;
		delete pTail_->pNext_;
	}
}
bool PriorityQueueL::isEmpty() const
{
	return pHead_ == nullptr;
}

std::ostream& PriorityQueueL:: writeTo(std::ostream& ostrm) const
{
	Node* temp = pHead_;
	while (temp != pTail_)
	{
		ostrm << temp->data_;
		temp = temp->pNext_;
	}
	return ostrm;
}