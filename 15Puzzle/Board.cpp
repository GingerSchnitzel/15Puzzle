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
			return command;
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

inline void Board::printEmptyLines(int32_t count)
{
	for (int i{ 0 }; i < count; ++i)
	{
		std::cout << '\n';
	}
}

inline void Board::moveTile(Direction direction)
{
	Direction oppositeDirection = -direction;
	Point previousEmpty{ m_emptyTileCoordinates };
	Point adjacentToEmptyPosition = previousEmpty.getAdjacentPoint(oppositeDirection);
	if (adjacentToEmptyPosition != m_emptyTileCoordinates)
	{
		// Reversed because they are stored in row major order in memory
		std::swap(m_tileBoard[static_cast<size_t>(m_emptyTileCoordinates.getY())][static_cast<size_t>(m_emptyTileCoordinates.getX())],
			m_tileBoard[static_cast<size_t>(adjacentToEmptyPosition.getY())][static_cast<size_t>(adjacentToEmptyPosition.getX())]);

		m_emptyTileCoordinates = adjacentToEmptyPosition;
	}
}

inline void Board::printEmptyTile()
{
	std::cout << '[' << m_emptyTileCoordinates.getX() << ']' << '[' << m_emptyTileCoordinates.getY() << ']' << '\n';
}

inline void Board::randomize(int32_t count)
{
	for (size_t i{ 0 }; i < count; ++i)
	{
		moveTile(static_cast<Direction>(Random::selectRandomOrientation()));
	}

}

inline bool Board::playerWon() const
{
	static Board s_solved{};
	return s_solved == *this;
}

std::ostream& operator<<(std::ostream& out, const Board& board)

{
	printEmptyLines(BoardConstants::consoleLines);

	for (size_t i{ 0 }; i < board.m_tileBoard.size(); ++i)
	{
		for (size_t j{ 0 }; j < board.m_tileBoard.size(); ++j)
		{
			out << board.m_tileBoard[i][j];
		}
		out << '\n';
	}
	return out;
}

bool operator==(const Board& lhs, const Board& rhs)
{
	return lhs.m_tileBoard == rhs.m_tileBoard;
}
