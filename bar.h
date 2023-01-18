// bar.h

#include "myrandom.h"
#include <iostream>
#include <string>
using namespace std;

//
// Bar
//
class Bar {
private:
	// Private member variables for a Bar object
	// TO DO:  Define private member variables for this class
	// NOTE: You should not be allocating memory on the heap for this class.
	string name;
	int value;
	string category;

public:
	// default constructor:
	Bar() {
		// TO DO:  Write this constructor.
		name = "";
		value = 0;
		category = "";
	}

	//
	// a second constructor:
	//
	// Parameter passed in constructor Bar object.
	//
	Bar(string name, int value, string category) {
		// TO DO:  Write this constructor.
		this->name = name;
		this->value = value;
		this->category = category;
	}

	// destructor:
	virtual ~Bar() {
		// TO DO:  Write this destructor or leave empty if not needed.
		// delete name;
		// delete value;
		// delete category;
	}

	// getName:
	string getName() const {
		return name;
	}

	// getValue:
	int getValue() const {
		return value;
	}

	// getCategory:
	string getCategory() const {
		return category;
	}

	// operators
	bool operator<(const Bar &other) const {
		return (this->value < other.value); // TO DO:  update this, it is only
											// here so code compiles.
	}

	bool operator<=(const Bar &other) const {
		return !(this->value > other.value); // TO DO:  update this, it is only
											 // here so code compiles.
	}

	bool operator>(const Bar &other) const {
		return (this->value > other.value); // TO DO:  update this, it is only
											// here so code compiles.
	}

	bool operator>=(const Bar &other) const {
		return !(this->value < other.value); // TO DO:  update this, it is only
											 // here so code compiles.
	}
};