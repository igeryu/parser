#ifndef Expression_HEADER
#define Expression_HEADER

class Expression
{
public:
	virtual int evaluate() = 0;
	bool negated = false;
};

#endif