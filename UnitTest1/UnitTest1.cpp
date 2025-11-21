#include "pch.h"
#include "CppUnitTest.h"
#include "../LR6.1-Rec/LR6.1-Rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRecursive
{
	TEST_CLASS(UnitTestRecursive)
	{
	public:

		TEST_METHOD(TestAllLogicRecursive)
		{
			int arr[3] = { 2, 2, 1 };
			const int size = 3;

			int count = Count(arr, size, 0);
			Assert::AreEqual(1, count);

			int sum = Sum(arr, size, 0);
			Assert::AreEqual(2, sum);

			ZeroElements(arr, size, 0);

			Assert::AreEqual(0, arr[1]);
			Assert::AreEqual(2, arr[0]);
		}
	};
}