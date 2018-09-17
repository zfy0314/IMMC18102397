#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <malloc.h>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
/*
#define min_fbk      0.077849894
#define min_mpp		 0.145781021
#define min_dx		 0
#define min_eff		 0.145827
#define min_edr		 0.159949294
#define max_fbk		 0.311399578
#define max_mpp		 0.185092757
#define max_dx		 0.299100602
#define max_eff		 0.185287079
#define max_edr		 0.168200984
*/

const double min_fbk = 0.077849894;
const double min_mpp = 0.145781021;
const double min_dx  = 0;
const double min_eff = 0.145827;
const double min_edr = 0.159949294;
const double max_fbk = 0.311399578;
const double max_mpp = 0.185092757;
const double max_dx  = 0.299100602;
const double max_eff = 0.185287079;
const double max_edr = 0.168200984;

struct hospital
{
	string name;
	string address;
	double fbk;
	double mpp;
	double dx;
	double eff;
	double edr;
};

hospital list[40];
hospital worst;
hospital ideal;

double hos_dis(hospital a, hospital b)
{
	return (double)sqrt(pow(a.dx - b.dx, 2) + pow(a.edr - b.edr, 2) + pow(a.eff - b.eff, 2) + pow(a.fbk - b.fbk, 2) + pow(a.mpp - b.mpp, 2));
}

/*
hospital hos_crt(string name, string address, double fbk, double mpp, double dx, double eff, double edr)
{
	hospital rlt = (hospital*)malloc(sizeof(hospital));
	rlt.dx = dx;
	rlt.edr = edr;
	rlt.eff = eff;
	rlt.fbk = fbk;
	rlt.mpp = mpp;
	rlt.name = name;
	rlt.address = address;
	return rlt;
}
*/

bool cmp(hospital a, hospital b)
{
	return hos_dis(a, worst) / (hos_dis(a, worst) + hos_dis(a, ideal)) > hos_dis(b, worst) / (hos_dis(b, worst) + hos_dis(b, ideal));
}

void hos_crt(int ptr, string name, string address, double fbk, double mpp, double dx, double eff, double edr)
{
	list[ptr].address = address;
	list[ptr].dx = dx;
	list[ptr].edr = edr;
	list[ptr].eff = eff;
	list[ptr].fbk = fbk;
	list[ptr].mpp = mpp;
	list[ptr].name = name;
}

void init()
{
	hos_crt(0, "BRONX-LEBANON HOSPITAL CENTER", "1276 FULTON AVENUE", 0.077849894, 0.152332977, 0.137885377, 0.16741676, 0.165261809);
	hos_crt(1, "JAMAICA HOSPITAL MEDICAL CENTER", "89TH AVENUE AND VAN WYCK EXPRESSWAY", 0.077849894, 0.168712867, 0.066101233, 0.157509719, 0.159949294);
	hos_crt(2, "NEW YORK COMMUNITY HOSPITAL OF BROOKLYN, INC.", "2525 KINGS HIGHWAY", 0.233549683, 0.167074878, 0.115751933, 0.165989696, 0.163173254);
	hos_crt(3, "MOUNT SINAI HOSPITAL", "ONE GUSTAVE L LEVY PLACE", 0.155699789, 0.160522922, 0.076868855, 0.163258109, 0.168200984);
	hos_crt(4, "RICHMOND UNIVERSITY MEDICAL CENTER", "355 BARD AVENUE", 0.155699789, 0.167074878, 0.13429617, 0.159978698, 0.165261809);
	hos_crt(5, "MOUNT SINAI WEST", "1000 TENTH AVENUE", 0.155699789, 0.157246944, 0.076868855, 0.165824399, 0.168200984);
	hos_crt(6, "NEW YORK-PRESBYTERIAN/QUEENS", "56-45 MAIN STREET", 0.233549683, 0.168712867, 0.207874918, 0.174824023, 0.159949294);
	hos_crt(7, "BROOKLYN HOSPITAL CENTER AT DOWNTOWN CAMPUS", "121 DEKALB AVENUE", 0.155699789, 0.170350856, 0.088832879, 0.166814382, 0.163173254);
	hos_crt(8, "MONTEFIORE MEDICAL CENTER", "111 EAST 210TH STREET", 0.155699789, 0.157246944, 0.299100602, 0.168711454, 0.165261809);
	hos_crt(9, "LINCOLN MEDICAL & MENTAL HEALTH CENTER", "234 EAST 149TH STREET", 0.077849894, 0.168712867, 0.04486509, 0.161676397, 0.165261809);
	hos_crt(10, "NEW YORK-PRESBYTERIAN HOSPITAL", "525 EAST 68TH STREET", 0.233549683, 0.160522922, 0.299100602, 0.159811598, 0.168200984);
	hos_crt(11, "LENOX HILL HOSPITAL", "100 EAST 77TH STREET", 0.155699789, 0.162160911, 0.299100602, 0.1625884, 0.168200984);
	hos_crt(12, "JACOBI MEDICAL CENTER", "1400 PELHAM PARKWAY SOUTH", 0.155699789, 0.1637989, 0.050248901, 0.16030962, 0.165261809);
	hos_crt(13, "ELMHURST HOSPITAL CENTER", "79-01 BROADWAY", 0.077849894, 0.167074878, 0.066101233, 0.152766548, 0.159949294);
	hos_crt(14, "STATEN ISLAND UNIVERSITY HOSPITAL", "475 SEAVIEW AVENUE", 0.233549683, 0.168712867, 0.18903158, 0.183905886, 0.165261809);
	hos_crt(15, "MOUNT SINAI BETH ISRAEL/PETRIE CAMPUS", "FIRST AVENUE AT 16TH STREET", 0.155699789, 0.168712867, 0.299100602, 0.166833058, 0.168200984);
	hos_crt(16, "FLUSHING HOSPITAL MEDICAL CENTER", "45TH AVENUE AND PARSONS BOULEVARD", 0.077849894, 0.183454768, 0.153737709, 0.169289422, 0.159949294);
	hos_crt(17, "MAIMONIDES MEDICAL CENTER", "4802 TENTH AVENUE", 0.077849894, 0.170350856, 0.273078849, 0.164038399, 0.163173254);
	hos_crt(18, "LONG ISLAND JEWISH MEDICAL CENTER", "270 - 05 76TH AVENUE", 0.233549683, 0.167074878, 0.299100602, 0.145831423, 0.159949294);
	hos_crt(19, "CONEY ISLAND HOSPITAL", "2601 OCEAN PARKWAY", 0.155699789, 0.178540801, 0.299100602, 0.150675837, 0.163173254);
	hos_crt(20, "METROPOLITAN HOSPITAL CENTER", "1901 FIRST AVENUE", 0.155699789, 0.145781021, 0.037088475, 0.171016281, 0.168200984);
	hos_crt(21, "KINGSBROOK JEWISH MEDICAL CENTER", "585 SCHENECTADY AVENUE", 0.155699789, 0.185092757, 0.055931813, 0.168526661, 0.163173254);
	hos_crt(22, "KINGS COUNTY HOSPITAL CENTER", "451 CLARKSON AVENUE", 0.077849894, 0.145781021, 0.067895837, 0.178328691, 0.163173254);
	hos_crt(23, "BELLEVUE HOSPITAL CENTER", "462 FIRST AVENUE", 0.155699789, 0.150694988, 0.155831414, 0.154058621, 0.168200984);
	hos_crt(24, "NYU HOSPITALS CENTER", "550 FIRST AVENUE", 0.233549683, 0.165436889, 0.299100602, 0.164402086, 0.168200984);
	hos_crt(25, "WYCKOFF HEIGHTS MEDICAL CENTER", "374 STOCKHOLM STREET", 0.155699789, 0.1637989, 0.066101233, 0.148754356, 0.163173254);
	hos_crt(26, "QUEENS HOSPITAL CENTER", "82-68 164TH STREET", 0.155699789, 0.149056999, 0.087636476, 0.160383832, 0.159949294);
	hos_crt(27, "BROOKDALE HOSPITAL MEDICAL CENTER", "1 BROOKDALE PLAZA", 0.077849894, 0.167074878, 0.100198702, 0.16879058, 0.163173254);
	hos_crt(28, "NEW YORK-PRESBYTERIAN BROOKLYN METHODIST HOSPITAL", "506 SIXTH STREET", 0.155699789, 0.165436889, 0.179460361, 0.167399067, 0.163173254);
	hos_crt(29, "HARLEM HOSPITAL CENTER", "506 LENOX AVENUE", 0.077849894, 0.162160911, 0.02991006, 0.145827, 0.168200984);
	hos_crt(30, "HOSPITAL FOR SPECIAL SURGERY", "535 EAST 70TH STREET", 0.311399578, 0.1637989, 0.08943108, 0.166627132, 0.168200984);
	hos_crt(31, "UNIVERSITY HOSPITAL OF BROOKLYN ( DOWNSTATE )", "445 LENOX ROAD", 0.155699789, 0.157246944, 0, 0.17348689, 0.163173254);
	hos_crt(32, "NORTH CENTRAL BRONX HOSPITAL", "3424 KOSSUTH AVENUE & 210TH STREET", 0.155699789, 0.160522922, 0.021535243, 0.157023001, 0.165261809);
	hos_crt(33, "ST JOHN'S EPISCOPAL HOSPITAL AT SOUTH SHORE", "327 BEACH 19TH STREET", 0.233549683, 0.175264823, 0.068194937, 0.185287079, 0.159949294);
	hos_crt(34, "WOODHULL MEDICAL AND MENTAL HEALTH CENTER", "760 BROADWAY", 0.155699789, 0.153970966, 0.029311859, 0.169368221, 0.163173254);
	hos_crt(35, "INTERFAITH MEDICAL CENTER", "1545 ATLANTIC AVENUE", 0.077849894, 0.173626834, 0.065203931, 0.169696358, 0.163173254);
	hos_crt(36, "ST BARNABAS HOSPITAL", "4422 THIRD AVENUE", 0.155699789, 0.160522922, 0.079859861, 0.156512855, 0.165261809);
	
	worst.address = "";
	worst.name = "worst";
	worst.fbk = min_fbk;
	worst.mpp = min_mpp;
	worst.dx = min_dx;
	worst.eff = min_eff;
	worst.edr = min_edr;
}

void get_ideal()
{
	int temp;
	printf("Please type in the importance of former patients' feedback to you on the scale of 1 to 5, 1 means not important at all, 5 means extremely important\n");
	scanf("%d", &temp);
	ideal.fbk = min_fbk +(max_fbk - min_fbk) / 5.0 * (double)temp;
	printf("Please type in the importance of medicare per patient to you on the scale of 1 to 5, 1 means not important at all, 5 means extremely important\n");
	scanf("%d", &temp);
	ideal.mpp = min_mpp + (max_mpp - min_mpp) / 5.0 * (double)temp;
	printf("Please type in the importance of the number of experienced doctors to you on the scale of 1 to 5, 1 means not important at all, 5 means extremely important\n");
	scanf("%d", &temp);
	ideal.dx = min_dx + (max_dx - min_dx) / 5.0 * (double)temp;
	printf("Please type in the importance of effectiveness to you on the scale of 1 to 5, 1 means not important at all, 5 means extremely important\n");
	scanf("%d", &temp);
	ideal.eff = min_eff + (max_eff - min_eff) / 5.0 * (double)temp;
	printf("Please type in the importance of evitable mortality to you on the scale of 1 to 5, 1 means not important at all, 5 means extremely important\n");
	scanf("%d", &temp);
	ideal.edr = min_edr + (max_edr - min_edr) / 5.0 * (double)temp;
}

int main()
{
	while (1)
	{
		//printf("ENTER\n");
		printf("This is a new york city hospital choosing application developed by IMMC18102397\n");
		init();
		get_ideal();
		printf("The best hospital for you are:\n");
		sort(list, list + 37, cmp);
		for (int i = 0; i < 3; i++)
		{
			//printf("%s at %s\n", list[i].name, list[i].address);
			cout << list[i].name << " at " << list[i].address << endl;
		}
		system("pause");
		printf("\n\n");
	}
	
	//hospital *a = hos_crt("BRONX-LEBANON HOSPITAL CENTER", "1276 FULTON AVENUE", 0.077849894, 0.152332977, 0.137885377, 0.16741676, 0.165261809);
	return 0;
}
