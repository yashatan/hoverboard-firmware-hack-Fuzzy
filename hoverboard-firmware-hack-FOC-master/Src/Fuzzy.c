#include "Fuzzy.h"
#include "stm32f1xx_hal.h"
#include "defines.h"
#include "setup.h"
#include "config.h"



float Fuzzy(float x1,float x2,Fuzzy_Value y, Membership_Value u)
	{ float y_out;
		
		float x1_NB = mftrap(x1,-2,-1,-u.B,-u.M);
		float x1_NM = mftrap(x1,-u.B,-u.M,-u.M,-u.S);
		float x1_NS = mftrap(x1,-u.M,-u.S,-u.S,-0.035);
		float x1_ZE = mftrap(x1,-u.S,-0.035,0.035,u.S) ;
		float x1_PS = mftrap(x1,0.035,u.S,u.S,u.M);
		float x1_PM = mftrap(x1,u.S,u.M,u.M,u.B);
		float x1_PB = mftrap(x1,u.M,u.B,1,2);
		float x2_NE = mftrap(x2,-2,-1,-1,0);
		float x2_ZE = mftrap(x2,-1,0,0,1);
		float x2_PO = mftrap(x2,0,1,1,2);
		
		float beta_1 = x1_NB*x2_NE;
		float beta_2 = x1_NB*x2_ZE;
		float beta_3 = x1_NB*x2_PO;
		float beta_4 = x1_NM*x2_NE;
		float beta_5 = x1_NM*x2_ZE;
		float beta_6 = x1_NM*x2_PO;
		float beta_7 = x1_NS*x2_NE;
		float beta_8 = x1_NS*x2_ZE;
		float beta_9 = x1_NS*x2_PO;
		float beta_10 = x1_ZE*x2_NE;
		float beta_11 = x1_ZE*x2_ZE;
		float beta_12 = x1_ZE*x2_PO;
		float beta_13 = x1_PS*x2_NE;
		float beta_14 = x1_PS*x2_ZE;
		float beta_15 = x1_PS*x2_PO;
		float beta_16 = x1_PM*x2_NE;
		float beta_17 = x1_PM*x2_ZE;
		float beta_18 = x1_PM*x2_PO;
		float beta_19 = x1_PB*x2_NE;
		float beta_20 = x1_PB*x2_ZE;
		float beta_21 = x1_PB*x2_PO;
		float sum = beta_1 + beta_2 + beta_3 + beta_4 + beta_5 + beta_6 + beta_7 + beta_8 + beta_9 + beta_10 + beta_11 + beta_12 + beta_13 + beta_14 + beta_15 + beta_16 + beta_17 + beta_18 + beta_19 + beta_20 + beta_21;
		y_out = ((beta_1)*y.NB + (beta_2+beta_4)*y.NM + (beta_3+beta_5+beta_7)*y.NS + (beta_6+beta_8+beta_10)*y.NSS + (beta_9+beta_11+beta_13)*y.ZE + (beta_12+beta_14+beta_16)*y.PSS+(beta_15 + beta_17+beta_19)*y.PS + (beta_18 +beta_20)*y.PM	 + beta_21*y.PB)/sum;
		return y_out;
		}
float mftrap(float x,float L, float C1, float C2, float R)
	{ float y;
		if (x>1) x=1;
		if (x<-1) x=-1;
		if (x<L) y=0;
		else if (x<C1) y= (x-L)/(C1-L);
		else if (x<C2) y=1;
		else if (x<R)  y=(R-x)/(R-C2);
		else y = 0;
		return y;
		}
	
