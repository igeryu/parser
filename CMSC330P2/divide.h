class Divide : public SubExpression
{
public:
	Divide(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		if (left->evaluate() == 0) return 0;
		
		if (right->evaluate() == 0) {
			cout << "\nDivision by zero!\n";
			return 0;
		}
		return left->evaluate() / right->evaluate();
	}
};