

#include "block.h"

CBlock::CBlock()
{

}

CBlock::~CBlock()
{

}

void CBlock::print()
{
	for (int i = 0; i < BG_SQUARE_LEN; ++i)
	{
		for (int j = 0; j < BG_SQUARE_LEN; ++j)
		{
			printf("%c", m_bg[i][j]);
		}
		printf("\n");
	}
}