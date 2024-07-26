#include "Tile.h"

inline const int32_t& Tile::getNumber() const { return m_number; }

inline bool Tile::isEmpty() const { return (m_number == 0); }

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
	if (tile.m_number > 9)
		out << " " << tile.m_number << " ";
	else if (tile.m_number > 0)
		out << "  " << tile.m_number << " ";
	else if (tile.m_number == 0)
		out << "    ";
	return out;
}

bool operator==(const Tile& lhs, const Tile& rhs)
{
	return lhs.m_number == rhs.m_number;
}
