#ifndef POLICY
#define POLICY

#include "MergeSort.h"
#include "QuickSort.h"
#include "Context.h"

class Policy
{
	// TODO 4: declare the missing attribute (hint: check the constructor)
private:
	Context* context;	

public:
	Policy(Context* context) : context(context)
	{
		// TODO 5: instantiate the missing attribute
	}

	virtual void configure(bool timeIsImportant, bool spaceIsImportant)
	{
		// TODO 6: add implementation for choosing the appropriate sorting algorithm
		if (timeIsImportant && !spaceIsImportant)
			context->setSortAlgorithm(new MergeSort);
		else if (timeIsImportant && spaceIsImportant)
			context->setSortAlgorithm(new QuickSort);
	}
};


#endif	//#ifndef POLICY
