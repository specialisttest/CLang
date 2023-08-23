#ifndef _INC_MY_H_
#define _INC_MY_H_

#define PI 3.1415
#define CLEN(R) (2*PI*(R))
#define CSQR(R) (PI*(R)*(R))

#define ROUND(x)  _Generic((x),\
	long double: roundl,\
	float: roundf,\
	default: round)\
(x)

#endif