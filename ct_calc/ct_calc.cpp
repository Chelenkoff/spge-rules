#include <iostream>

int getCalculationsCount(int nMinTmp, int nMaxTmp, int nStep);
void getTemps(double* pResultsArray, int nArraySize, int nMinTemp, int nMaxTemp, int nTempStep);
double calculateCt(int nTemp);

int main()
{
	int nMinTemp = 270;
	int nMaxTemp = 420;
	int nTempStep = 10;

	int nCalculationsCount = getCalculationsCount(nMinTemp, nMaxTemp, nTempStep);

	double* pResultsArray = 0;
	try{pResultsArray = new double[nCalculationsCount];}
	catch (...) {}

	//exit program - unable to allocate dynamic memory
	if (!pResultsArray) return 0; 

	getTemps(pResultsArray, nCalculationsCount, nMinTemp, nMaxTemp, nTempStep);

	for (int i = 0; i < nCalculationsCount; ++i)
	{
		std::cout << "For temp:" << (nMinTemp + (nTempStep * i)) << " The Ct is:" << pResultsArray[i] << std::endl;
	}

	delete[] pResultsArray;

	return 0;
}

int getCalculationsCount(int nMinTmp, int nMaxTmp, int nStep)
{
	if (nMinTmp > nMaxTmp) return 0;
	if (nMinTmp == nMaxTmp) return 1;

	return ((nMaxTmp - nMinTmp) / nStep) + 1;
}

void getTemps(double* pResultsArray, int nArraySize, int nMinTemp, int nMaxTemp, int nTempStep)
{
	int nCurrentTemp = nMinTemp;

	for (int i = 0; i < nArraySize; ++i)
	{
		pResultsArray[i] = calculateCt(nCurrentTemp);
		nCurrentTemp += nTempStep;
	}
}

double calculateCt(int nTemp)
{
	double dFirstNum = 0.0;
	double dSecondNum = 0.0;

	if (nTemp == 320)
	{
		dFirstNum = 0.62;
		dSecondNum = 1.9;
	}
	else if (nTemp > 320)
	{
		dFirstNum = 0.7;
		dSecondNum = 2.2;
	}
	else
	{
		dFirstNum = 0.5;
		dSecondNum = 1.6;
	}

	return (dFirstNum + dSecondNum * nTemp);
}