class Strategy {
public:
	virtual void drawCard() = 0;
};

class GreedyComputerStrategy : public Strategy
{

};

class HumanStrategy : public Strategy {

};

class ModerateComputerStrategy : public Strategy {

};