#include "Stack2.h"
#include "Iterator.h"
#include <exception>

using namespace std;

bool Stack2::append(int a) {
	if (size == max_size) {
		return false;
	}
	node* tmp = new node(a, top);
	top = tmp;
	size++;
	return true;
}

bool Stack2::remove() {
	if (top == nullptr) {
		return false;
	}
	top = top->next;
	size--;
	return true;
}

StackIterator* Stack2::createIterator(Iterators its, const int aStep) const {
	if (its == Iterators::STEP) {
		return new StackIteratorStep(this, aStep);
	}
	if (its == Iterators::VALUE) {
		return new StackIteratorValue(this, aStep);
	}
	return nullptr;
}

StackIterator* Stack2::createIterator(Iterators its, bool(*aPredicate)(int)) const {
	return new StackIteratorPredicate(this, aPredicate);
}

int StackIterator::currentItem() const {
	if (current == nullptr) {
		throw exception("Can't obtain currentItem!");
	}
	return current->value;
}

bool StackIterator::operator==(const StackIterator& iter) {
	return iter.current == this->current;

}
bool StackIterator::operator!=(const StackIterator& iter) {
	return iter.current != this->current;
}

int StackIterator::operator*() {
	return currentItem();
};

StackIterator& StackIterator::operator++() {
	next();
	return *this;
}

bool StackIteratorStep::first() {
	current = pStack->top;
	for (auto i = 0; current != nullptr && i < step - 1; i++) {
		current = current->next;
	}
	return current != nullptr;
}

bool StackIteratorStep::next() {
	for (auto i = 0; current != nullptr && i < step; i++) {
		current = current->next;
	}
	return current != nullptr;
}

bool StackIteratorValue::first() {
	current = pStack->top;
	return findNext();
}

bool StackIteratorValue::next() {
	current = current->next;
	return findNext();
}

bool StackIteratorValue::findNext() {	
	while (current != nullptr && current->value != value) {
		current = current->next;
	}
	return current != nullptr;
}

bool StackIteratorPredicate::first() {
	current = pStack->top;
	return findNext();
}

bool StackIteratorPredicate::next() {
	current = current->next;
	return findNext();
}

bool StackIteratorPredicate::findNext() {
	while (current != nullptr && !predicate(current->value))
		current = current->next;
	return current != nullptr;
}