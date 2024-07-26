#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Direction.h"
#include "Point.h"
#include <array>
#include <cstdint>
#include <utility>
#include <iostream>

namespace BoardConstants
{
	constexpr int32_t maxTileNumber{ 15 };
	constexpr size_t boardSize{ 4 };
	constexpr int32_t consoleLines{ 25 };
	constexpr int32_t shuffler{ 1000 };
}

namespace BoardInteraction
{
	char userCommand();
	Direction charToDirection(char command);
	
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

	static void printEmptyLines(int32_t count)
	{
		for (int i{ 0 }; i < count; ++i)
		{
			std::cout << '\n';
		}
	}

	void moveTile(Direction direction)
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

	void printEmptyTile()
	{
		std::cout << '[' << m_emptyTileCoordinates.getX() << ']' << '[' << m_emptyTileCoordinates.getY() << ']' << '\n';
	}

	void randomize(int32_t count)
	{
		for (size_t i{ 0 }; i < count; ++i)
		{
			moveTile(static_cast<Direction>(Random::selectRandomOrientation()));
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

	friend bool operator==(const Board& lhs, const Board& rhs)
	{
		return lhs.m_tileBoard == rhs.m_tileBoard;
	}

	bool playerWon() const
	{
		static Board s_solved{};  
		return s_solved == *this; 
	}

};

#endif