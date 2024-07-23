#include "Board.h"

char BoardInteraction::userCommand()
{
	std::cout << "Enter a command: ";
	while (true)
	{
		char command{};
		std::cin >> command;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (command == 'w' || command == 'a' || command == 's' || command == 'd')
		{
			std::cout << "Valid command: " << command << '\n';
		}

		if (command == 'q')
		{
			std::cout << "\n\nBye!\n\n";
			return command;
		}
	}
}

Direction BoardInteraction::charToDirection(char command)
{
	{
		switch (command)
		{
		case 'w': return Direction{ Orientation::up };
		case 's': return Direction{ Orientation::down };
		case 'a': return Direction{ Orientation::left };
		case 'd': return Direction{ Orientation::right };
		default: assert(false && "Unsupported direction was passed!");
		}
		return Direction{ Orientation::up };
	}
}
