#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab2\Lab2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(issorted_true)
		{
			const size_t size = 5;
			int test[size] = { 0,1,2,3,4 };
			Assert::AreEqual(issorted(test, size), true);
		}
		TEST_METHOD(issorted_false)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			Assert::AreEqual(issorted(test, size), false);
		}
		TEST_METHOD(issorted_char_true)
		{
			const size_t size = 5;
			char test[size] = {1,2,3,4,5};
			Assert::AreEqual(issorted_char(test, size), true);
		}
		TEST_METHOD(issorted_char_false)
		{
			const size_t size = 5;
			char test[size] = "leti";
			Assert::AreEqual(issorted_char(test, size), false);
		}
		TEST_METHOD(BogoSort_Test)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			bogoSort(test, size);
			Assert::AreEqual(issorted(test, size), true);
		}
		TEST_METHOD(BubbleSort_Test)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			BubbleSort(test, size);
			Assert::AreEqual(issorted(test, size), true);
		}
		TEST_METHOD(QuickSort_Test)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			QuickSort(test, size);
			Assert::AreEqual(issorted(test, size), true);
		}
		TEST_METHOD(InsertionSort_Test)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			InsertionSort(test, size);
			Assert::AreEqual(issorted(test, size), true);
		}
		TEST_METHOD(CountingSort_Test)
		{
			const size_t size = 10;
			char test[size] = {5,4,3,2,1,1,2,3,4,5};
			CountingSort(test, size);
			Assert::AreEqual(issorted_char(test,size), true);
		}
		TEST_METHOD(BinarySearch_NotSortedArray)
		{
			const size_t size = 5;
			int test[size] = { 0,1,20,3,4 };
			try 
			{
				BinarySearch(test, size, 1);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "The array is not sorted");
			}
		}
		TEST_METHOD(BinarySearch_ErrorKey)
		{
			const size_t size = 5;
			int test[size] = { 0,1,2,3,4 };
			BinarySearch(test, size, 1);
			try {
				BinarySearch(test, size, 5);
			}
			catch (const char* error)
			{
				Assert::AreEqual(error, "Element not found");
			}
		}
		TEST_METHOD(BinarySearch_Normal)
		{
			const size_t size = 5, correct_index = 2;
			int test[size] = { 1,3,5,7,9 };
			Assert::AreEqual(BinarySearch(test, size, 5),correct_index);
		}
	};
}
