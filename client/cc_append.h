/*
<devmap>
<Num_GPUs>9</Num_GPUs>
<1>0 -1 01:00.0 NV GTX-1060-6GB</1>
<2>1 -1 02:00.0 NV GTX-1060-3GB</2>
<3>2 -1 03:00.0 NV GTX-1060-3GB</3>
<4>3 -1 04:00.0 NV P106-100</4>
<5>4 -1 05:00.0 NV GTX-1070</5>
<6>5 -1 08:00.0 NV P106-090</6>
<7>6 -1 0A:00.0 NV GTX-1060-3GB</7>
<8>7 -1 0B:00.0 NV GTX-1060-3GB</8>
<9>8 -1 0E:00.0 NV GTX-1060-3GB</9>
</devmap>
*/

#include <string>
#include <vector>


using std::string;
using std::vector;


struct s_dev_info {
	int sid;				// sensor or nvidia-smi id for the device (amd or nvidia)
	int nBOD;				// boinc device id, initially -1 since not known
	char sBUSID[32];		// 04:00.0 for example
	char sManu[32];			// one of NV, ATI, INTEL
	char sBoardName[32];	// might be longer
};

bool GetBusidInfo(char *fname, vector<s_dev_info> *di);
