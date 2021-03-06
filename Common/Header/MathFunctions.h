/*
 * LK8000 Tactical Flight Computer -  WWW.LK8000.IT
 * Released under GNU/GPL License v.2
 * See CREDITS.TXT file for authors and copyrights
 *
 * File:   MathFunctions.h
 * Author: Bruno de Lacheisserie
 *
 * Created on 23 octobre 2014
 */

#ifndef MATHFUNCTIONS_H
#define	MATHFUNCTIONS_H

void rotate(double &xin, double &yin, const double &angle);
void rotatescale(double &xin, double &yin, const double &angle, const double &scale);

void frotate(float &xin, float &yin, const float &angle);
void frotatescale(float &xin, float &yin, const float &angle, const float &scale);

void irotate(int &xin, int &yin, const double &angle);
void irotatescale(int &xin, int &yin, const double &angle, const double &scale, double &x, double &y);

void protate(POINT &pin, const double &angle);
void protateshift(POINT &pin, const double &angle, const int &x, const int &y);

double AngleLimit360(double theta);
double AngleLimit180(double theta);

double Reciprocal(double InBound);
double AngleDifference(double angle1, double angle0);
bool AngleInRange(double Angle0, double Angle1, double x, bool is_signed=false);

double HalfAngle(double Angle0, double Angle1);
double BiSector(double InBound, double OutBound);

double ScreenAngle(int x1, int y1, int x2, int y2);

// Fast trig functions
void InitSineTable(void);

#ifdef __MINGW32__
#define DEG_TO_INT(x) ((unsigned short)(int)((x)*(65536.0/360.0)))>>4
#else
#define DEG_TO_INT(x) ((unsigned short)((x)*(65536.0/360.0)))>>4
#endif

extern double COSTABLE[4096];
extern double SINETABLE[4096];
extern double INVCOSINETABLE[4096];
extern int ISINETABLE[4096];
extern int ICOSTABLE[4096];

#define invfastcosine(x) INVCOSINETABLE[DEG_TO_INT(x)]
#define ifastcosine(x) ICOSTABLE[DEG_TO_INT(x)]
#define ifastsine(x) ISINETABLE[DEG_TO_INT(x)]
#define fastcosine(x) COSTABLE[DEG_TO_INT(x)]
#define fastsine(x) SINETABLE[DEG_TO_INT(x)]



unsigned int isqrt4(unsigned long val);

int  roundupdivision(int a, int b);

double LowPassFilter(double y_last, double x_in, double fact);

#ifndef MulDiv
    #define MulDiv _MulDiv
#endif

int _MulDiv(int nNumber, int nNumerator, int nDenominator);


//2^36 * 1.5,  (52-_shiftamt=36) uses limited precisicion to floor
//16.16 fixed point representation,

// =================================================================================
// Real2Int
// =================================================================================
inline int Real2Int(double val)
{
#if (WINDOWS_PC>0)
  val += 68719476736.0*1.5;
  return *((long*)&val) >> 16; 
#else
  return (int)val;
#endif
}


// =================================================================================
// Real2Int
// =================================================================================
inline int Real2Int(float val)
{
#if (WINDOWS_PC>0)
  return Real2Int ((double)val);
#else
  return (int)val;
#endif
}


inline int iround(double i) {
    return Real2Int(floor(i+0.5));
}

inline long lround(double i) {
    return (long)(floor(i+0.5));
}

inline unsigned int CombinedDivAndMod(unsigned int &lx) {
  unsigned int ox = lx & 0xff;
  // JMW no need to check max since overflow will result in 
  // beyond max dimensions
  lx = lx>>8;
  return ox;
}


#endif	/* MATHFUNCTIONS_H */

