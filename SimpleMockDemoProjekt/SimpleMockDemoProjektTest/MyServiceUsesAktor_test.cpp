#include "MyServiceUsesAktor_test.h"
#include <exception>
TEST_F(MyServiceUsesAktor_test, foo__HappyDay__AktorCall) {
	int parameterValue = 1;

	EXPECT_CALL(aktorMock, doIt(_))
		.WillOnce(Invoke(this, &MyServiceUsesAktor_test::captureFunction));

	objectUnderTest->foo(parameterValue);

	EXPECT_EQ(captureObj.x, 2);
	EXPECT_EQ(captureObj.y, 3);
	EXPECT_EQ(captureObj.z, 4);
}

TEST_F(MyServiceUsesAktor_test, foo__HappyDaySecond__AktorCall) {
	int parameterValue = 1;


	ParameterStruct captureParam{};

	EXPECT_CALL(aktorMock, doIt)
		.WillRepeatedly(SaveArg<0>(&captureParam));

	objectUnderTest->foo(parameterValue);

	EXPECT_EQ(captureParam.x, 2);
	EXPECT_EQ(captureParam.y, 3);
	EXPECT_EQ(captureParam.z, 4);
}


TEST_F(MyServiceUsesAktor_test, bar__HappyDaySecond__AktorCall) {
	
	ParameterStruct captureParam{};

	//ON_CALL(sensorMock, getValue()).WillByDefault(Return(1));

	EXPECT_CALL(sensorMock, getValue())
		.WillOnce(Return(1))
		.WillOnce(Return(2))
		//.WillRepeatedly(Return(3))
		.WillOnce(Throw(std::exception{}))
		;



	EXPECT_CALL(aktorMock, doIt)
		.WillRepeatedly(SaveArg<0>(&captureParam));

	objectUnderTest->bar();

	EXPECT_EQ(captureParam.x, 4);
	EXPECT_EQ(captureParam.y, 3);
	EXPECT_EQ(captureParam.z, 2);
}




