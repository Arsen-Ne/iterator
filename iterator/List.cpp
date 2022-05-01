#include "List.h"

List::List(size_t aSize) {
	vec.resize(aSize);
}

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

ListIterator* List::createIterator(Iterators its, bool(*aPredicate)(int)) const {
	return new ListIteratorPredicate(this, aPredicate);
}

bool ListIterator::first() {
	current = pList->top;
	return next();
}

int ListIterator::currentItem() const {
	if (current == -1) {
		throw exception("Can't obtain currentItem!");
	}
	return pList->vec[current];
}

bool ListIterator::operator==(const ListIterator& iter) {
	return iter.current == this->current;

}
bool ListIterator::operator!=(const ListIterator& iter) {
	return iter.current != this->current;
}

int ListIterator::operator*() {
	return currentItem();
};

ListIterator& ListIterator::operator++() {
	next();
	return *this;
}

bool ListIteratorStep::next() {
	current = current--;
	for (auto i = 0; current != -1 && i < step; i++) {
		current = current--;
	}
	return current != -1;
}

bool ListIteratorPredicate::next() {	
	current = current--;
	while (current != -1 && !predicate(pList->vec[current]))
		current = current--;
	return current != -1;
}

bool ListIteratorValue::next() {
	current = current--;
	while (current != -1 && pList->vec[current] != value) {
		current = current--;
	}
	return current != -1;
}
