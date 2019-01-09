/*
	This library's purpose to create simple-linear-filter recursively
	simply way to filtering data-series on mcu ( arduino or stm32 board)
	
	Lib_name 	: FILTER
	AUTHOR		: Andri Setyabudi ; 
	
*/

#pragma once
#ifndef RECURSIVEFILTER_H
#define RECURSIVEFILTER_H

// constant variables bellow is in percent
#define MAX_WEIGTH	100.0
#define MIN_WEIGHT 	0.1

class RecursiveFilter
{
	protected:
		float weight;   // in percent ( 0.1 - 100.0 )
		float currData;
	public:
		RecursiveFilter(float wValue)
		{
			weight = (wValue>MAX_WEIGTH)?MAX_WEIGTH:wValue;
			weight = (weight<MIN_WEIGHT)?MIN_WEIGHT:weight;
			currData = 0;
		}
		float Filtered( float newData)
		{
      currData = (( weight * newData )/100) + ( ( 1 - (weight/100))*currData); 
      return  currData;
		}
   float getValue() const {return currData;}
};

#endif
