#pragma once
#include "schwein.h"
#include "gtest/gtest.h"

class schwein_test : public ::testing::Test
{
    public:
        schwein_test(){};

    protected:
        tiere::schwein* objectUnderTest;

        void SetUp() override {
            objectUnderTest = new tiere::schwein();
        }

        void TearDown() override {
            delete objectUnderTest;
        }
};
