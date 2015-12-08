
class Variable : public Operand
{
public:
	Variable(string name);
	int Variable::evaluate();
private:
	string name;
};

