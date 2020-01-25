
//#define _CRT_SECURE_NO_WARNINGS


#ifdef _WIN32
#include "boinc_win.h"
#else
#include "config.h"
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <map>
#include <set>
#endif


#include "cc_append.h"

using std::string;
using std::vector;
using std::string;

vector<s_dev_info> *DevMap;

// return 0 if end of file, return count of char read, return string with no newline
int ReadLine(FILE* f, char* strOut)
{
	char *pos;
	char strTemp[128];
	int n = 0;
	while (n == 0)
	{
		if (fgets(strTemp, 128, f) == NULL) return 0;
		if ((pos = strchr(strTemp, '\n')) != NULL)
			*pos = '\0';
		n = strlen(strTemp);
	}
	strcpy(strOut, strTemp);
	return n;
}

//return -1 if error, return 0 if out of data, return > 0 is ok
int GetRoot(FILE *f, char *strOut)
{
	char strTemp[256] = "";
	int n = ReadLine(f, (char *)&strTemp);
	if (n == 0)return 0;
	if (strTemp[0] != '<') return -1;
	if (strTemp[n - 1] != '>') return -1;
	strncpy(strOut, &strTemp[1], n - 2);
	return 1;
}

// return -1 if alpha or negative, else the value
int ToInt(char *strIn)
{
	char *s = strIn;
	int n = strlen(strIn);
	for (int i = 0; i < n; i++)
		if (*s < '0' || *s > '9') return -1;
	return atoi(strIn);
}

// return -1 for error
int GetTag(FILE *f, const char *strTag1, const char *strTag2, char *strOut)
{
	char strTemp[256] = "";
	int n, m = strlen(strTag1);
	if (ReadLine(f, (char *)&strTemp) == 0) return -1;
	if (0 != strncmp(strTag1, strTemp, m))return -1;
	strcpy(strOut, &strTemp[m]);
	m = strlen(strTag2);
	n = strlen(strOut) - m;
	if (0 != strncmp(strTag2, &strOut[n], m))return -1;
	strOut[n] = '\0';
	return 1;
}



bool read_append_file(const char* fname)
{
	int NumGpus, RtnCod = 1;
	char * pch;
	s_dev_info d_i;
	char strRoot[256] = "";
	char strLine[256] = "";
	char strTag[256] = "";
	char Tag1[32], Tag2[32];
	FILE* f = fopen(fname, "r");
	if (!f) return false;
	if (GetRoot(f, (char *)&strRoot) <= 0) return false;
	RtnCod = GetTag(f, "<Num_GPUs>", "</Num_GPUs>", (char *)&strTag);
	if (RtnCod < 0)return false;
	NumGpus = ToInt(strTag);
	for (int i = 1; i <= NumGpus; i++)
	{
		sprintf(Tag1, "<%d>", i);
		sprintf(Tag2, "</%d>", i);
		RtnCod = GetTag(f, Tag1, Tag2, (char*)&strLine);
		if (RtnCod < 0)return false;
		pch = strtok(strLine, " ");
		//0 -1 01:00.0 NV GTX-1060-6GB
		//d_i = new s_dev_info();
		d_i.sid = ToInt(pch);       // the index used by nvidia-smi and sensors
		pch = strtok(NULL, " ");
		d_i.nBOD = ToInt(pch);				// we willfill this in
		pch = strtok(NULL, " ");
		strcpy(d_i.sBUSID, pch);
		pch = strtok(NULL, " ");
		strcpy(d_i.sManu, pch);
		pch = strtok(NULL, " ");
		strcpy(d_i.sBoardName, pch);
		DevMap->push_back(d_i);
	}
	fclose(f);
	return true;
}

bool GetBusidInfo(char * fname, vector<s_dev_info> *DM)
{
	DevMap = DM;
	return read_append_file(fname);
}
