
/*
 * Basic Statistic Function
 *
 * Almost all of this function using operation of array
 *
 */

#include "statistic.h"

#define numOfArray		10
float arrayData[numOfArray];

void CreateRandomData()
{
	for (uint8_t i = 0; i < numOfArray; i++)
	{
		arrayData[i] = (float) ( random(1,1000)/100);
	}
}
void setup() 
{
	Serial.begin(9600);
	randomSeed(analogRead(0));
	Serial.println("======================= data of operation =====================");
	Serial.println("Size of Array    :" +String(arrayLength(arrayData))  );
	Serial.println("Average of datas :" +String(getAverage(arrayData))   );
	Serial.println("Lowest value     :" +String(getLowest(arrayData))    );
	Serial.println("Highest value    :" +String(getHighest(arrayData))   );
	Serial.println("std Dev          :" +String(getDeviasion(arrayData)) );
	Serial.println("Content :");
	for( int i = 0; i<numOfArray; i++)
	{
		Serial.println("data - " +String(i+1)+ " : " +String(arrayData[i]));
	}
	
}

void loop() 
{
  /** Empty loop. **/
}