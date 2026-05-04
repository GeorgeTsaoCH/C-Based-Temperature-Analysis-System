#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeviceAlpha.h"
#include "AppSleep.h"


void displayTemperatureAnalysis(double hottestTemperature, double coldestTemperature, double averageTemperature, double numberOfTemperaureReadings)
{
	DeviceInit();
	printf("Temperature Analysis\n");
	printf("Number of temperature readings : %.0lf", numberOfTemperaureReadings);

	SetLEDState(RED_LED, ON);
	DisplayDoubleValue(hottestTemperature, 1);
	AppSleep(3300);
	ToggleMultiLEDState(RED_LED, BLUE_LED, 0, 0);
	DisplayDoubleValue(coldestTemperature, 1);
	AppSleep(3300);
	ToggleMultiLEDState(BLUE_LED, YELLOW_LED, 0, 0);
	DisplayDoubleValue(averageTemperature, 1);
	AppSleep(3300);
	SetLEDState(YELLOW_LED, OFF);
	ClearSevenSegmentDisplaysDP(1);
	AppSleep(3300);
	DeviceCleanup();
}







int main()
{
	
	double hottestTemperature, coldestTemperature, averageTemperature, totalTemperature, numberOfTemperaureReadings;
	
	
	numberOfTemperaureReadings = 4;
	coldestTemperature = 40.0;
	hottestTemperature = 15.0;
	averageTemperature = 32.0;
	displayTemperatureAnalysis(hottestTemperature, coldestTemperature, averageTemperature, numberOfTemperaureReadings);

	return 0;

}