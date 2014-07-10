#ifndef __EVOLUTION_H__
#define  __EVOLUTION_H__

const int ROW_NUM = 5;
const int COL_NUM = 5;

class Status
{
public:
	Status();
	Status(const char** pStatus, unsigned int nWidth, unsigned int nHeight);
	virtual ~Status();

public:
	void SetStatusOnMap(const char** pStatus,unsigned int nWidth, unsigned int nHeight);
	void ShowStatus();

protected:
	int CalcNeighbours(int nX, int nY);
	char CreateNewStatus(char status, int nX, int nY);

private:
	char **m_pStatus;
	char m_szStatusMap[ROW_NUM][COL_NUM];
	char m_szTempStatusMap[ROW_NUM][COL_NUM];

};


#endif