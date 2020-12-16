#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../SimpleMockDemoProjekt/Sensor.h"
class SensorMock: public Sensor
{
public:
	MOCK_METHOD(int, getValue, (), (const, override));
};

