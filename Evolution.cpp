#include <iostream>
#include <assert.h>
#include "Evolution.h"

using namespace std;

Status::Status()
: m_pStatus(NULL)
{

}

Status::Status(const char** pStatus, unsigned int nWidth, unsigned int nHeight)
: m_pStatus(NULL)
{
	assert(pStatus);

	SetStatusOnMap(pStatus, nWidth, nHeight);
}

Status::~Status()
{

}

void Status::SetStatusOnMap(const char** pStatus,unsigned int nWidth, unsigned int nHeight)
{

}

void Status::ShowStatus()
{

}

int Status::CalcNeighbours(int nX, int nY)
{
	return 0;
}

char Status::CreateNewStatus(char status, int nX, int nY)
{
	return NULL;
}

int main()
{
	return 0;
}

