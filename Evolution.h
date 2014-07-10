#ifndef __EVOLUTION_H__
#define  __EVOLUTION_H__

const int ROW_NUM = 10;		//map's size
const int COL_NUM = 10;

const char DEAD_STATUS = '.';
const char LIVE_STATUS = '*';

const int XSIZE = 3;			//live cells matrix size
const int YSIZE = 3;


class Status
{
public:
	Status(unsigned int nNum);	//if you create  with this constructor, then you should call SetStatusOnMap()
	Status(unsigned int nNum, char** pStatus, unsigned int nXo, unsigned int nYo, unsigned int nWidth, unsigned int nHeight);
	virtual ~Status();

public:
	//pStatus is a point to two dimensions array, nXo and nYo is the begin position on map, nWidth and nHeight is array's.
	void SetStatusOnMap(char** pStatus, unsigned int nXo, unsigned int nYo, unsigned int nWidth, unsigned int nHeight); 
	void ShowStatus();

protected:
	int CalcNeighbours(int nX, int nY);
	char CreateNewStatus(int nX, int nY);

private:
	bool m_bShowMainMap;						//flag to decide which status to update and show
	int m_nTotalShowNum;								//show how many generations
	char m_szStatusMap[ROW_NUM][COL_NUM];				//map which include all dead and live cells
	char m_szTempStatusMap[ROW_NUM][COL_NUM];		// and those maps will show alternately
																								

};


#endif