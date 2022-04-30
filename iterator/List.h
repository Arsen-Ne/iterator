
#include <vector>
#include <exception>
using namespace std;

#pragma once

enum class Iterators {
	STEP,
	VALUE,
	PREDICATE
};

class List
{
private:
	//public:
	vector <int> vec;
	size_t top = 0;
public:
	friend class ListIterator;
	//friend class ListIteratorStep;
	friend class ListIteratorValue;

	List(size_t aSize) {
		vec.resize(aSize);
	}

	virtual ~List() {};

	bool append(int a);

	bool remove();

	ListIterator* createIterator(Iterators its, const int aStep) const;
	ListIterator* createIterator(Iterators its, void* aPredicate) const;
};

	class ListIterator {
	protected:
		//friend class List;
		const List* pList;
		size_t current;
		ListIterator(const List* aPList) : pList(aPList) {}
	public:
		//	virtual bool first() = 0;
		virtual bool next() = 0;
		bool first() {
			current = pList->top;
			return next();
		}

		int currentItem() const {
			if (current == -1)
				throw exception("Can't obtain currentItem!");
			return pList->vec[current];
		}
	};

	class ListIteratorStep : public ListIterator {
	private:
		int step;
	public:
		//friend class List;
		ListIteratorStep(const List* aPList, int aStep = 1) : ListIterator(aPList) {
			step = aStep - 1;
			this->first();
		}

		bool next() override {
			current = current--;
			for (auto i = 0; current != -1 && i < step; i++)
				current = current--;
			return current != -1;
		}
	};

	class ListIteratorPredicate : public ListIterator
	{
	private:
		void* predicate;
	public:
		ListIteratorPredicate(const List* aPList, void* aPredicate) : ListIterator(aPList) {
			predicate = aPredicate;
		}

		//bool first() override {
		//	return true;
		//}

		bool next() override
		{
			return true;
		}

	};

	class ListIteratorValue : public ListIterator {
	private:
		int value;
	public:
		//friend class List;
		ListIteratorValue(const List* aPList, int aValue) : ListIterator(aPList) {
			value = aValue;
			//first();
		}

		bool next() override {
			current = current--;
			while (current != -1 && pList->vec[current] != value)
				current = current--;
			return current != -1;
		}

	};





