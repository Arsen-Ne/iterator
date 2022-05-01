
#include <vector>
#include "Iterator.h"
using namespace std;

#pragma once

class List
{
private:	
	vector <int> vec;
	size_t top = 0;

public:
	friend class ListIterator;
	friend class ListIteratorValue;
	friend class ListIteratorPredicate;

	List(size_t aSize);

	virtual ~List() {};

	bool append(int a);
	bool remove();

	ListIterator* createIterator(Iterators its, const int aStep) const;
	ListIterator* createIterator(Iterators its, bool(*aPredicate)(int)) const;
};

class ListIterator : public Iterator
{
protected:
	const List* pList;
	size_t current;
	ListIterator(const List* aPList) : pList(aPList) {}
public:
	bool first() override;
	int currentItem() const override;
		
	bool operator==(const ListIterator& iter);
	bool operator!=(const ListIterator& iter);
	int operator*();
	ListIterator& operator++();
};

class ListIteratorStep : public ListIterator 
{
private:
	int step;
public:		
	ListIteratorStep(const List* aPList, const int aStep = 1) : ListIterator(aPList), step(aStep - 1) {}
	bool next() override;
};

class ListIteratorPredicate : public ListIterator
{
private:
	bool(*predicate)(int);
public:
	ListIteratorPredicate(const List* aPList, bool(*aPredicate)(int)) : ListIterator(aPList), predicate(aPredicate) {}
	bool next() override;
};

class ListIteratorValue : public ListIterator
{
private:
	int value;
public:
	ListIteratorValue(const List* aPList, const int aValue) : ListIterator(aPList), value(aValue) {}
	bool next() override;
};