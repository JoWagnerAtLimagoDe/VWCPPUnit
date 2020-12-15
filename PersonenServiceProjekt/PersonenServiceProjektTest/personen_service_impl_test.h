#pragma once
#include "gtest/gtest.h"
#include "../PersonenServiceProjekt/person_service_impl.h"
#include "PersonRepositoryMock.h"
class personen_service_impl_test: public ::testing::Test
{
protected:
	person_service_impl* objectUnderTest;
	
	void SetUp() override
	{
		Mockperson_repository personRepo;
		objectUnderTest = new person_service_impl(personRepo);
	}

	void TearDown() override
	{
		
	}
};

