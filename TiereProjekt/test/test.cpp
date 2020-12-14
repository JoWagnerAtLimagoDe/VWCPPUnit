#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "schwein_test.h"
#include <string>
#include <exception>

TEST(schwein_ctor, ctorWithDefaults_ctorCalledDefault) {
	tiere::schwein s = tiere::schwein();

	// Assertion
	EXPECT_EQ(s.getName(), "nobody");
	EXPECT_THAT(s.getGewicht(), ::testing::Eq(10));
}

TEST(schwein_ctor2, ctorWithNameElsa_ctorCalledThenThrowsException) {
	// Assertion
	EXPECT_THROW(tiere::schwein("Elsa"), std::exception);
}

TEST_F(schwein_test, GivenElsaAsName_setNameCalledThenThrowsExeption) {
	std::string name("Elsa");

	// Assertion
	EXPECT_THROW(objectUnderTest->setName(name), std::exception);
}

TEST_F(schwein_test, GivenUschiAsName_setNameCalledThenNoThrow) {
	std::string name("Uschi");

	// Assertion
	EXPECT_NO_THROW(objectUnderTest->setName(name));
}

TEST_F(schwein_test, GivenFood_fressenCalledThen) {
	int gewicht_vorher = objectUnderTest->getGewicht();
	objectUnderTest->fressen();
	int gewicht_nachher = objectUnderTest->getGewicht();

	// Assertion
	EXPECT_GT(gewicht_nachher, gewicht_vorher);
}
