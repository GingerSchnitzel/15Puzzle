#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include <array>
#include <cstdint>

namespace BoardConstants
{
	constexpr int32_t maxTileNumber{ 15 };
	constexpr size_t boardSize{ 4 };
	constexpr int32_t consoleLines{ 25 };
}


class Board
{
private:
	std::array <std::array<Tile, BoardConstants::boardSize>, BoardConstants::boardSize> m_tileBoard;
public:
	Board()
		:m_tileBoard{}
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
				}
			}
		}
	}

	static void printEmptyLines(int32_t count)
	{
		for (int i{ 0 }; i < count; ++i)
		{
			std::cout << '\n';
		}
	}

	friend std::ostream& operator<< (std::ostream& out, const Board& board)

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


};

#endif