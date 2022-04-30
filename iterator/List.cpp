#include "List.h"

bool List::append(int a) {
	if (top == vec.size())
		return false;
	vec[top++] = a;
	return true;
}

bool List::remove() {
	if (top == 0)
		return false;
	--top;
	return true;
}

ListIterator* List::createIterator(Iterators its, const int aStep) const {
	if (its == Iterators::STEP) {
		return new ListIteratorStep(this, aStep);
	}
	if (its == Iterators::VALUE) {
		return new ListIteratorValue(this, aStep);
	}
	return nullptr;
}

ListIterator* List::createIterator(Iterators its, void* aPredicate) const {	
		return new ListIteratorPredicate(this, aPredicate);
}
