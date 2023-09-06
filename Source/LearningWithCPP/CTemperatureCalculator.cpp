// Fill out your copyright notice in the Description page of Project Settings.


#include "CTemperatureCalculator.h"

UCTemperatureCalculator::UCTemperatureCalculator()
{
}

// This definition is the first iteration of Calculate, using the FText type for both parameters and the return value
FText UCTemperatureCalculator::Calculate(FText inputValue, FText inputUnit)
{
	FString outputMessage{ "" };
	float coefficient{ 1.8 };
	float offset{ 32.0 };
	float calculatedValue{ 0 };

	if(!inputUnit.ToString().IsEmpty() && !inputValue.ToString().IsEmpty()) {
		if ((inputUnit.ToString() == "C" || inputUnit.ToString() == "Celcius") && inputValue.ToString().IsNumeric())  {
			// Celcius to Fahrenheit: F = (C * (9/5)) + 32
			calculatedValue = (FCString::Atof(*inputValue.ToString()) * coefficient) + offset;
			outputMessage = (FString::SanitizeFloat(calculatedValue)).Append(" F");
		} else if((inputUnit.ToString() == "F" || inputUnit.ToString() == "Fahrenheit") && inputValue.ToString().IsNumeric()) {
			// Fahrenheit to Celcius: C = (F - 32) * (5/9)
			calculatedValue = (FCString::Atof(*inputValue.ToString()) - offset) * (1 / coefficient);
			outputMessage = (FString::SanitizeFloat(calculatedValue)).Append(" C");
		} else {
			outputMessage = "Unrecognized input. Please enter a numerical value for temperature and a valid unit.";
		}
	} else {
		outputMessage = "Please fill both fields.";
	}

	return FText::FromString(outputMessage);
}

// This version of Calculate is simplified with simplified parameter and return types, though it functions less desirably when handling incorrect input. As such, this is more of a demonstration of float and FString as parameters than it is meant to be practical
float UCTemperatureCalculator::CalculateBad(float inputValue, FString inputUnit)
{
	float coefficient{ 1.8 };
	float offset{ 32.0 };
	float calculatedValue{ 0 };

	if (!inputUnit.IsEmpty()) {
		if (inputUnit == "C" || inputUnit == "Celcius") {
			// Celcius to Fahrenheit: F = (C * (9/5)) + 32
			calculatedValue = (inputValue * coefficient) + offset;
		}
		else if (inputUnit == "F" || inputUnit == "Fahrenheit") {
			// Fahrenheit to Celcius: C = (F - 32) * (5/9)
			calculatedValue = (inputValue - offset) * (1 / coefficient);
		}
	}

	return calculatedValue;
}