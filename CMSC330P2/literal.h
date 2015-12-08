
class Literal : public Operand
{
public:
	Literal(int value)
	{
		this->value = value;
	}
	int evaluate()
	{
		int mod = negated ? 0 : 1;

		if (value != 0)
			return mod * value;
		return !mod;
	}
private:
	int value;
};

