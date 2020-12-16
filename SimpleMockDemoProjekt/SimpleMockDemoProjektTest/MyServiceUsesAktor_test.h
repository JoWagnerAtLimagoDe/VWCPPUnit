#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../SimpleMockDemoProjekt/MeinServiceUsesAktor.h"
#include "AktorMock.h"
#include "SensorMock.h"


using namespace ::testing;

class MyServiceUsesAktor_test: public Test
{
public:

	void captureFunction(ParameterStruct& obj) {
		captureObj = obj;
	}
protected:
	MeinServiceUsesAktor * objectUnderTest;
	
	MockAktor aktorMock;
	SensorMock sensorMock;


	ParameterStruct captureObj;


	void SetUp() override
	{
		objectUnderTest = new MeinServiceUsesAktor(aktorMock, sensorMock);
	}

	void TearDown() override
	{
		delete objectUnderTest;
	}
};

