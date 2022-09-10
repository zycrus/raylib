#include <iostream>

class Player
{
public:
	const char* name;
	Player()
		: name("?????") {}
	Player(const char* _name)
		: name(_name) {}
};

int main()
{
	Player* player = new Player("Joe");
	std::cout << (*player).name << std::endl;

	std::cin.get();
	delete player;
}