#include <stdint.h>
#include "defines.h"
#include "config.h"

typedef struct{
		float NB;
		float NM;
		float NS;
		float NSS;
		float ZE;
		float PSS;
		float PS;
		float PM;
		float PB;
	} Fuzzy_Value;
float mftrap(float x,float L, float C1, float C2, float R);
float Fuzzy(float x1,float x2,Fuzzy_Value y);