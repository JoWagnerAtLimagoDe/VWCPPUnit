#include "pch.h"
#include "../FirstDemo/stack.h"

TEST(stack_test, GivenEmptyStackWhenIs_emptycalledThenReturnsTrue) {
	// Arrange
	teacher::stack mystack;

	// Action
	const bool ergebnis = mystack.is_empty();

	// Assertion
	EXPECT_FALSE(ergebnis);
}
