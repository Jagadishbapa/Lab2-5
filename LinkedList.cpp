// LinkedList.cpp

// tom bailey   0745  5 oct 2010
// Definition of methods for the List class.

#include "stdafx.h"
#include "LinkedList.h"

#include <utility>


List::List()
	: first_(NULL)
{
}


List::List(const List & other)
	: first_(clone(other.first_))
{
}


List::~List()
{
	while (!empty())
	{
		removeFirst();
	}
}

const List & List::operator=(const List & other)
{
	// check for list = list
	if (&other != this)
	{
		// clear the current contents of this List
		this -> ~List();
		// and get a copy of other
		first_ = clone(other.first_);
	}

	return *this;
}

bool List::operator==(const List &rhs){
    /*if(size() == 0 && rhs.size() == 0){return true;}//both empty
    if(size() != rhs.size()){return false;}//sizes not the same

    Node * lptr = this->next_;
    Node * rptr = rhs->next_;
		Double lEntry = lptr->entry_;
    Double rEntry = rptr->entry_;
		while (lptr != NULL && rptr != NULL)
		{
      if(lEntry != rEntry){
        return false;
      }
      lptr = lptr->next_;
      rptr = rptr->next_;
      lEntry = lptr->entry_;
      rEntry = rptr->entry_;
		}
*/
  	return true;
}


bool List::empty() const
{
	return first_ == NULL;
}


void List::insertAsFirst(double x)
{
	first_ = new Node(x, first_);
}

void List::insertAsLast(double x)
{
	if (!empty())									// If the List object is not empty...
	{
		Node * ptr = first_;						// ...make a pointer to the first entry.
		while (ptr->next_ != NULL)					// While not at the end of the list...
		{
			ptr = ptr->next_;						// ...have the pointer point to the next entry.
		}
		ptr->next_ = new Node(x, NULL);				// At the end of the list, make a new Node.
	}
	if (empty())									// If the List obejct is empty...
	{
		first_ = new Node(x, first_);				// ...just make a new Node.
	}
}

double List::removeFirst()
{
	double item = first_->entry_;
	Node * tempPtr = first_;
	first_ = first_->next_;
	delete tempPtr;
	return item;
}


void List::print(ostream & outfile) const
{
	outfile << "[ ";
	if (!empty())
	{
		// The first entry is printed separately because no comma
		// is needed.
		outfile << first_->entry_;
		Node * ptr = first_->next_;
		while (ptr != NULL)
		{
			outfile << ", " << ptr->entry_;
			ptr = ptr->next_;
		}
	}
	outfile << " ]";
}

int List::size()
{
	int count = 0;									// Make a variable to count each entry.
	if (!empty())									// If the List object is not empty...
	{
		if (first_ != NULL)							// ...if the first entry has information...
		{
			count++;								// ...increment the count...
			Node * ptr = first_->next_;				// ...make a pointer to the next address.
			while (ptr != NULL)						// While the pointer continues to point to an address...
			{
				count += 1;							// ...increment the count...
				ptr = ptr->next_;					// ...make the pointer point to the next address.
			}
		}
	}
	return count;
}

double List::sum()
{
	double sum = 0;									// Make a variable to keep track of the sum.
	if (!empty())									// If the List object is not empty...
	{
		if (first_ != NULL)							// ...if the first entry has information...
		{
			sum += first_->entry_;					// ...add the value of the entry to the sum...
			Node * ptr = first_->next_;				// ...make a pointer to the next address.
			while (ptr != NULL)						// While the pointer continues to point to an address...
			{
				sum += ptr->entry_;					// ...add the next value to the sum...
				ptr = ptr->next_;					// ...make the pointer point to the next address.
			}
		}
	}
	return sum;
}

// Iterative version of clone.
// This version walks down the linked structure making a
//   new Node for each double in the structure.
Node * List::clone(Node * ptr)
{
	if (ptr == NULL)
	{
		return NULL;
	}
	Node * first = new Node(ptr->entry_);
	Node * last = first;
	ptr = ptr->next_;
	while (ptr != NULL)
	{
		last->next_ = new Node(ptr->entry_);
		last = last->next_;
		ptr = ptr->next_;
	}
	return first;
}


//// Recursive version of clone.
//// This version handles two cases, a linked structure with
////   no Nodes, and a linked structure with one or more
////   Nodes.
//Node * List::clone( Node * ptr )
//{
//   if( ptr == NULL )
//   {
//      return NULL;
//   }
//   return new Node( ptr->entry_, clone( ptr->next_ ) );
//}


ostream & operator<<(ostream & outfile, const List & list)
{
	list.print(outfile);
	return outfile;
}
