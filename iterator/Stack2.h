#pragma once
#include "Iterator.h"

class node {
public:
    int value;
    node* next;
    //node() : next(nullptr) {}
    node(int val, node* p = nullptr) : value(val), next(p) {}	
};

class Stack2
{
private:
    node* top = nullptr;    
    int size = 0;
    int max_size;	
public:
	friend class StackIterator;
	friend class StackIteratorStep;
	friend class StackIteratorValue;
	friend class StackIteratorPredicate;

    Stack2(int aSize) : max_size(aSize) {}
    
    virtual ~Stack2() {};

    bool append(int a);
    bool remove();

	StackIterator* createIterator(Iterators its, const int aStep) const;
	StackIterator* createIterator(Iterators its, bool(*aPredicate)(int)) const;
};

class StackIterator : public Iterator
{
protected:
	const Stack2* pStack;
	node* current;
	StackIterator(const Stack2* aPStack) : pStack(aPStack), current(aPStack->top) {}	
public:
	int currentItem() const override;

	bool operator==(const StackIterator& iter);
	bool operator!=(const StackIterator& iter);
	int operator*();
	StackIterator& operator++();
};

class StackIteratorStep : public StackIterator
{
private:
	int step;
public:
	StackIteratorStep(const Stack2* aPStack, const int aStep = 1) : StackIterator(aPStack), step(aStep) {}	
	bool first() override;
	bool next() override;
};

class StackIteratorValue : public StackIterator
{
private:
	int value;
	bool findNext();
public:
	StackIteratorValue(const Stack2* aPStack, const int aValue) : StackIterator(aPStack), value(aValue) {}
	bool first() override;
	bool next() override;
};

class StackIteratorPredicate : public StackIterator
{
private:
	bool(*predicate) (int);
	bool findNext();
public:
	StackIteratorPredicate(const Stack2* aPStack, bool(*aPredicate)(int)) : StackIterator(aPStack), predicate(aPredicate) {}
	bool first() override;
	bool next() override;
};

