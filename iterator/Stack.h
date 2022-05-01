#pragma once
#include <forward_list>
#include <iterator>

using namespace std;

enum class Iteratorss {
	STEP,
	VALUE,
	PREDICATE
};

class Stack
{
private:
	forward_list <int> flist;
	size_t max_size = 0;

public:
	friend class StackIterator;
	friend class StackIteratorStep;
	//friend class ListIteratorValue;
	//friend class ListIteratorPredicate;

	Stack(size_t aSize) : max_size(aSize) {}

	virtual ~Stack() {};

	bool append(int a);
	bool remove();

	StackIterator* createIterator(Iteratorss its, const int aStep) const;
		//ListIterator* createIterator(Iterators its, bool(*aPredicate)(int)) const;
};

class StackIterator
{
protected:
	const Stack* pStack;
	forward_list<int>::const_iterator current;
	StackIterator(const Stack* aPStack) : pStack(aPStack) {}
public:
	bool first();
	virtual bool next() = 0;
	int currentItem() const;

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
	StackIteratorStep(const Stack* aPStack, const int aStep = 1) : StackIterator(aPStack), step(aStep - 1) {}
	bool next() override;
};
