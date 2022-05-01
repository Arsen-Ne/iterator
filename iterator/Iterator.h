#pragma once

enum class Iterators {
	STEP,
	VALUE,
	PREDICATE
};

class Iterator
{
public:
	virtual bool first() = 0;
	virtual bool next() = 0;
	virtual int currentItem() const = 0;
};

