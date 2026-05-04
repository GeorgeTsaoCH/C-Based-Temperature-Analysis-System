#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeviceAlpha.h"
#include "AppSleep.h"


double getTempuraure()
{
	double temperatureInCelsius, totalTemperature, averageTemperature;
	int count;
	U3DigitalState buttonState;
	
	printf(" Attention: Should enable the HEATER and to press and hold Pushbutton 1 to read the temperature and release Pushbutton 1 to stop reading the temperature\n");
	MultiAllPushButtonsWait(ON, PUSHBUTTON1, 0, 0, 0);
	totalTemperature = 0;
	buttonState = GetPushButtonState(PUSHBUTTON1);
	count = 0;
	while (buttonState == ON)
	{
		SetHeaterState(HEATER, ON);
		temperatureInCelsius = GetTemperature(TEMPERATURE_SENSOR);
		totalTemperature += temperatureInCelsius;
		buttonState = GetPushButtonState(PUSHBUTTON1);
		SetBuzzerState(BUZZER, ON);
		AppSleep(200);
		SetBuzzerState(BUZZER, OFF);
		count++;

	}
	SetHeaterState(HEATER, OFF);
	averageTemperature = totalTemperature / count;
	DisplayDoubleValue(averageTemperature, 2);
	return averageTemperature;
}









int main()
{
	double temperatureInCelsius;
	

	DeviceInit();
	temperatureInCelsius = getTempuraure();
	printf("%0.2lf", temperatureInCelsius);
	DeviceCleanup();
	return 0;

}