#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Direction.h"
#include "Point.h"
#include <array>
#include <cstdint>
#include <utility>
#include <iostream>
#include <string>

namespace BoardConstants
{
	constexpr int32_t maxTileNumber{ 15 };
	constexpr size_t boardSize{ 4 };
	constexpr int32_t consoleLines{ 25 };
	constexpr int32_t shuffler{ 3 };
}

namespace BoardInteraction
{
	char userCommand();
	Direction charToDirection(char command);
	bool playAgain();
	
}

class Board
{
private:
	std::array <std::array<Tile, BoardConstants::boardSize>, BoardConstants::boardSize> m_tileBoard;
	Point m_emptyTileCoordinates;

public:
	Board()
		: m_tileBoard{}
		, m_emptyTileCoordinates{}
	{
		int32_t value = 1;
		for (size_t i{ 0 }; i < BoardConstants::boardSize; ++i)
		{
			for (size_t j{ 0 }; j < BoardConstants::boardSize; ++j)
			{
				if (value <= 15)
				{
					m_tileBoard[i][j] = Tile(value);
					++value;
				}
				else
				{
					m_tileBoard[i][j] = Tile(0);
					// No other conversion neccessary as the last position has the same coordinates in row/column as well as XoY system
					m_emptyTileCoordinates.setCoordinates(static_cast<int32_t>(i), static_cast<int32_t>(j));
				}
			}
		}
	}

	static void printEmptyLines(int32_t count);
	void moveTile(Direction direction);
	void printEmptyTile();
	void randomize(int32_t count);
	friend std::ostream& operator<< (std::ostream& out, const Board& board);
	friend bool operator==(const Board& lhs, const Board& rhs);
	bool playerWon() const;

};

#endif