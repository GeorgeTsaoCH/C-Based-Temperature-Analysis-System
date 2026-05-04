/*
	Program: project.c
	Author:	 Chih-Hsiang Tsao
	Date:	 Nov 13, 2025
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "DeviceAlpha.h"
#include "AppSleep.h"

double getTemperature();
void displayTemperatureAnalysis(double hottestTemperature, double coldestTemperature, double averageTemperature, double numberOfTemperaureReadings);

int main()
{
	char userChoice;
	double userGetTemperature, hottestTemperature, coldestTemperature, numberOfTemperatureReadings, averageTemperature;
	double sumOfTemperature;
	DeviceInit();

	hottestTemperature = 0.0;
	coldestTemperature = 100.0;
	numberOfTemperatureReadings = 0.0;
	averageTemperature = 0.0;
	sumOfTemperature = 0.0;
	
	
	do
	{
		printf("(R) Read temperatures\n(D) Display temperature analysis\n(E) Exit the application\nPlease enter which process you want to do?");
		scanf(" %c%*[^\n]", &userChoice);

		
		switch (userChoice)
		{
		case'R':
		case'r':
			userGetTemperature = getTemperature();
			break;
		case'D':
		case'd':
			if (numberOfTemperatureReadings == 0.0)
			{
				printf("You have no temperatures.\n");
			}
			else
			{
				displayTemperatureAnalysis(hottestTemperature, coldestTemperature, averageTemperature, numberOfTemperatureReadings);
			}
			break;
		case'E':
		case'e':
			break;
		default:
			printf("Not a valid input!\n");

		}
		if (userChoice == 'R' || userChoice == 'r')
		{
			
			if (userGetTemperature > hottestTemperature)
			{
				hottestTemperature = userGetTemperature;
			}
			if (userGetTemperature < coldestTemperature)
			{
				coldestTemperature = userGetTemperature;
			}

			sumOfTemperature += userGetTemperature;
			numberOfTemperatureReadings++;
			averageTemperature = sumOfTemperature / numberOfTemperatureReadings;
		}
		
		
		
	} 
	while (userChoice != 'E' && userChoice != 'e');
	
	

	
	DeviceCleanup();
	
	return 0;
}

double getTemperature()
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
	return averageTemperature;
	
}


void displayTemperatureAnalysis(double hottestTemperature, double coldestTemperature, double averageTemperature, double numberOfTemperaureReadings)
{
	
	printf("Temperature Analysis\n");
	printf("Number of temperature readings : %.0lf\n", numberOfTemperaureReadings);

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
	
}
