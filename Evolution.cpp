#include <iostream>
#include <assert.h>
#include "Evolution.h"

using namespace std;

Status::Status(unsigned int nNum)
:  m_bShowMainMap(true)
, m_nTotalShowNum(nNum)
{

}
Status::Status(unsigned int nNum, char** pStatus, unsigned int nXo, unsigned int nYo, unsigned int nWidth, unsigned int nHeight)
:  m_bShowMainMap(true)
, m_nTotalShowNum(nNum)
{
	SetStatusOnMap(pStatus, nXo, nYo, nWidth, nHeight);
}


Status::~Status()
{

}

void Status::SetStatusOnMap(char** pStatus, unsigned int nXo, unsigned int nYo, unsigned int nWidth, unsigned int nHeight)
{
	assert(pStatus);

	for (int j = 0; j < ROW_NUM; ++j)
	{
		for (int i = 0; i < COL_NUM; ++i)
		{
			if ((i >= nXo) && (i < nXo + nWidth) && (j >= nYo) && (j < nYo + nHeight))
			{
				m_szStatusMap[i][j] = pStatus[i - nXo][j - nYo];
				m_szTempStatusMap[i][j] = pStatus[i - nXo][j - nYo];
			}
			else
			{
				m_szStatusMap[i][j] = DEAD_STATUS;
				m_szTempStatusMap[i][j] = DEAD_STATUS;
			}
		}
	}
}

void Status::ShowStatus()
{
	char cStatus;

	while (m_nTotalShowNum--)
	{
		//the border cells of the array always is dead 
		for (int j = 1; j < ROW_NUM - 1; ++j)
		{
			for (int i =1; i < COL_NUM - 1; ++i)
			{
				cStatus = CreateNewStatus(i, j);

				if (m_bShowMainMap)
				{
					m_szStatusMap[i][j] = cStatus;
				}
				else
				{
					m_szTempStatusMap[i][j] = cStatus;
				}

				cout << cStatus << ' ' ;
			}
			cout << endl;
		}
		cout << "###########################" << endl;

		m_bShowMainMap = !m_bShowMainMap;
		int n ;
	}

}


int Status::CalcNeighbours(int nX, int nY)
{
	int nCount = 0;

	for (int j = nY - 1; j <= nY + 1; ++j)
	{
		for (int i = nX - 1; i <= nX + 1; ++i)
		{
			//show m_szTempStatusMap and m_szStatusMap alternately
			if (i == nX && j == nY)
			{
				continue;
			}
			if (m_bShowMainMap)
			{
				if (m_szTempStatusMap[i][j] == LIVE_STATUS)
					nCount++;
			}
			else
			{
				if (m_szStatusMap[i][j] == LIVE_STATUS)
					nCount++;
			}
		}
	}
	return nCount;
}

char Status::CreateNewStatus(int nX, int nY)
{
	int nCount = CalcNeighbours(nX, nY);

	char cTemp;
	if (m_bShowMainMap)
	{
		cTemp = m_szTempStatusMap[nX][nY];
	}
	else
	{
		cTemp = m_szStatusMap[nX][nY];
	}
	// rules which decide live or dead
	if (cTemp == LIVE_STATUS)
	{
		if (nCount < 2 || nCount > 3)
			return DEAD_STATUS;
		else
			return LIVE_STATUS;
	}
	else
	{
		if (nCount == 3)
		{
			return LIVE_STATUS;
		}
	}
}

int main()
{
	char **pTest = NULL;
	pTest = new char *[YSIZE];
	for (int i =0; i< YSIZE; ++i)
	{
		pTest[i] = new char [XSIZE];
	}

	pTest[0][0] = LIVE_STATUS;
	pTest[0][1] = LIVE_STATUS;
	pTest[1][0] = LIVE_STATUS;
	pTest[1][1] = LIVE_STATUS;

	Status sta(3);
	sta.SetStatusOnMap(pTest, 2, 2, 2, 2);
	sta.ShowStatus();

	for (int i=0; i<YSIZE; ++i)
	{
		delete [] pTest[i];
		pTest[i] = NULL;
	}
	delete [] pTest;
	pTest = NULL;

	return 0;
}

