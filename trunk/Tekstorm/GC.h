#pragma once
#ifndef _TEKSTORM_GC_H
#define _TEKSTORM_GC_H
#include "BuildConf.h"
#include <list>	// we use std :: list for now for gc objects

namespace Tekstorm
{
	/*
	**	This data structure describes a "node" (or element)
	** that is stored in the Garbage Collection list.
	*/
	template <class T>
	struct GCNode
	{
		/*
		** The current reference count of this element.
		** If this value is 0, then the memory used by this object
		** is freed and the element is recycled.
		*/
		unsigned int nRefCount;

		/*
		** The address of the allocated memory
		*/
		T *pAddr;

		/*
		** If this element is an array, the size of the array.
		** Otherwise, if not an array, this value should be 1.
		*/
		unsigned int nArraySize;

		GCNode(T *ptr, unsigned int arrSize = 1)
		{
			nRefCount = 1;
			pAddr = ptr;
			nArraySize = arrSize;
		}
	};

	/*
	** Global operator overload for GCNode, for address
	** comparisons.
	*/
	template <class T>
	bool operator==(const GCNode<T> &first, const GCNode<T> &second)
	{
		return (first.pAddr == second.pAddr);
	}

	/*
	** Garbage Collected pointer class. This class will automatically
	** managage pointers.
	*/
	template <class T, unsigned int size = 1>
	class GCPtr
	{
	private:
		/*
		** The address that this GCPtr pointers to.
		*/
		T *pAddr;

		/*
		** If an array, the size of the array. If not
		** an array, 1.
		*/
		unsigned int nArraySize;

		/*
		** The main garbage collection list.
		*/
		static std::list<GCNode<T> > gcList;

		/*
		** Searches for the given address in the list.
		*/
		typename std::list<GCNode<T> >::iterator FindPointer(T *p)
		{
			std::list<GCNode<T> >::iterator it = gcList.begin();
			while (it != gcList.end())
			{
				if (it->pAddr == p)
					return it;
			}

			return gcList.end();
		}
	public:
		/*
		** Initializes a new instance of GCPtr.
		*/
		GCPtr(T *p) : nArraySize(size)
		{
			/* look to see if 'p' is already referenced */
			std::list<GCNode<T> >::iterator it = FindPointer(p);

			if (it != gcList.end())
			{
				it->nRefCount++;
			}
			else
			{
				GCNode<T> obj(p, size);
				gcList.push_front(obj);
			}

			std::cout << "GCPtr constructor called!\n";

			pAddr = p;
		}

		/*
		** Initializes a new instance of GCPtr.
		*/
		GCPtr(const GCPtr<T> &obj)
		{
			std::cout << "GCPtr constructor called!\n";
			std::list<GCNode<T> >::iterator it = FindPointer(obj.pAddr);
			it->nRefCount++;
			pAddr = obj.pAddr;
			nArraySize = obj.nArraySize;
		}

		/*
		** Destroys this instance of GCPtr.
		*/
		~GCPtr()
		{
			std::cout << "GCPtr destructor called!\n";
			std::list<GCNode<T> >::iterator it = FindPointer(pAddr);
			if (it->nRefCount) it->nRefCount--;
			else
			{
				if (it->nArraySize > 1)
					delete[] it->pAddr;
				else
					delete pAddr;

				gcList.erase(it);
			}
		}

		/*
		** Returns the reference pointed to by this pointer.
		*/
		T &operator*()
		{
			return *pAddr;
		}

		/*
		** Returns the constant reference pointed to by this pointer.
		*/
		const T &operator*() const
		{
			return *pAddr;
		}

		/*
		** Returns the address being pointed to.
		*/
		T *operator->()
		{
			return pAddr;
		}

		/*
		** Allows for array indexing.
		*/
		T &operator[](unsigned int index)
		{
			return pAddr[index];
		}

		/*
		** Allows for array indexing
		*/
		const T &operator[](unsigned int index) const
		{
			return pAddr[index];
		}
	};

	template <class T, unsigned int size>
	std::list<GCNode<T> > GCPtr<T, size>::gcList;
}

#endif /* _TEKSTORM_GC_H */