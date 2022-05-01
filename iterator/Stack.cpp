#include "Stack.h"

bool Stack::append(int a) {
	auto count = distance(flist.begin(), flist.end());
	if (count >= max_size) {
		return false;
	}
	flist.push_front(a);	
	return true;
}

bool Stack::remove() {
	if (flist.empty()) {
		return false;
	}
	flist.pop_front();
	return true;
}

//StackIterator* Stack::createIterator(Iteratorss its, const int aStep) const {
//	if (its == Iteratorss::STEP) {
//		return new StackIteratorStep(this, aStep);
//	}
//	//if (its == Iterators::VALUE) {
//	//	return new StackIteratorValue(this, aStep);
//	//}
//	return nullptr;
//}
//
//bool StackIterator::first() {
//	current = pStack->flist.cbefore_begin();
//	return next();
//}
//
//int StackIterator::currentItem() const {
//	if (current == pStack->flist.cend() or &current == nullptr) {		
//		throw exception("Can't obtain currentItem!");
//	}	
//	return *current;
//}
//
//bool StackIterator::operator==(const StackIterator& iter) {
//	return iter.current == this->current;
//
//}
//bool StackIterator::operator!=(const StackIterator& iter) {
//	return iter.current != this->current;
//}
//
//int StackIterator::operator*() {
//	return currentItem();
//};
//
//StackIterator& StackIterator::operator++() {
//	current++;
//	return *this;
//}
//
//bool StackIteratorStep::next() {
//	current = current++;	
//	auto end = pStack->flist.end();
//	for (auto i = 0; current != end && i < step; i++) {
//		current = current++;
//	}
//	//forward_list<int>::const_iterator end = pStack->flist.cend();
//	//advance(current, step);
//	return &current != nullptr && current != end;
//}