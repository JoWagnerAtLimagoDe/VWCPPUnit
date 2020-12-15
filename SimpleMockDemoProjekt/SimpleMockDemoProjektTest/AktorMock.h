#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../SimpleMockDemoProjekt/Aktor.h"

class MockAktor : public Aktor {
 public:
  MOCK_METHOD(void, doIt, (ParameterStruct p), (override));
};
