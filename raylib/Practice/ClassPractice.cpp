#include <iostream>
#include <vector>

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
	std::vector<Player*> players;
	players.push_back(new Player("Joe"));
	players.push_back(new Player("Pikachu"));
	players.push_back(new Player("Candace"));
	players.push_back(new Player("Mogusa"));

	for (size_t i = 0; i < players.size(); i++)
	{
		std::cout << (*players[i]).name << std::endl;
	}

	std::cin.get();
	players.clear();
}