#include "pch.h"
#include "CppUnitTest.h"
#include "/ITMO/Algo/Lab2/Array/Array/MyArray.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		
		TEST_METHOD(StrReadWriteDefaultCapacityInBounds)
		{
			MyArray<std::string> arr;
			arr.insert("hello");
			arr.insert("world");
			Assert::AreEqual(arr[0], std::string("hello"));
			Assert::AreEqual(arr[1], std::string("world"));
		}

		TEST_METHOD(StrReadWriteDefaultCapacityOutBounds)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			Assert::AreEqual(arr[30], std::string("world"));
		}

		TEST_METHOD(StrReadWriteCustomCapacityOutBounds)
		{
			MyArray<std::string> arr(3);
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			Assert::AreEqual(arr[30], std::string("world"));
		}

		TEST_METHOD(StrInsert)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("goodbye");
			arr.insert("sleep");
			arr.insert(30, "world");
			Assert::AreEqual(arr[29], std::string("hello"));
			Assert::AreEqual(arr[30], std::string("world"));
			Assert::AreEqual(arr[31], std::string("goodbye"));
			Assert::AreEqual(arr[32], std::string("sleep"));
		}

		TEST_METHOD(StrRemove)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			arr.insert("world");
			arr.insert("goodbye");
			arr.insert("sleep");
			arr.remove(30);
			Assert::AreEqual(arr[29], std::string("hello"));
			Assert::AreEqual(arr[30], std::string("world"));
			Assert::AreEqual(arr[31], std::string("goodbye"));
			Assert::AreEqual(arr[32], std::string("sleep"));
		}

		TEST_METHOD(LongStrRemove)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			arr.insert("world0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			arr.insert("world0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			arr.insert("goodbye000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			arr.insert("sleep0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
			arr.remove(30);
			Assert::AreEqual(arr[29], std::string("hello00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
			Assert::AreEqual(arr[30], std::string("world0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
			Assert::AreEqual(arr[31], std::string("goodbye000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
			Assert::AreEqual(arr[32], std::string("sleep0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"));
		}

		

		TEST_METHOD(StrArrCopyConstruct)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			arr.insert("goodbye");
			arr.insert("sleep");
			MyArray<std::string> arr2(arr);
			Assert::AreEqual(arr2[29], std::string("hello"));
			Assert::AreEqual(arr2[30], std::string("world"));
			Assert::AreEqual(arr2[31], std::string("goodbye"));
			Assert::AreEqual(arr2[32], std::string("sleep"));
		}

		TEST_METHOD(StrArrCopyAssign)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			arr.insert("goodbye");
			arr.insert("sleep");
			MyArray<std::string> arr2;
			arr2 = arr;
			Assert::AreEqual(arr2[29], std::string("hello"));
			Assert::AreEqual(arr2[30], std::string("world"));
			Assert::AreEqual(arr2[31], std::string("goodbye"));
			Assert::AreEqual(arr2[32], std::string("sleep"));
			Assert::AreEqual(arr[29], std::string("hello"));
			Assert::AreEqual(arr[30], std::string("world"));
			Assert::AreEqual(arr[31], std::string("goodbye"));
			Assert::AreEqual(arr[32], std::string("sleep"));
		}

		TEST_METHOD(StrArrMoveConstruct)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			arr.insert("goodbye");
			arr.insert("sleep");
			MyArray<std::string> arr2(std::move(arr));
			Assert::AreEqual(arr2[29], std::string("hello"));
			Assert::AreEqual(arr2[30], std::string("world"));
			Assert::AreEqual(arr2[31], std::string("goodbye"));
			Assert::AreEqual(arr2[32], std::string("sleep"));
			Assert::AreEqual(arr.size(), 0);
		}

		TEST_METHOD(StrArrMoveAssign)
		{
			MyArray<std::string> arr;
			for (int i = 0; i < 30; i++)
				arr.insert("hello");
			arr.insert("world");
			arr.insert("goodbye");
			arr.insert("sleep");
			MyArray<std::string> arr2 = std::move(arr);
			Assert::AreEqual(arr2[29], std::string("hello"));
			Assert::AreEqual(arr2[30], std::string("world"));
			Assert::AreEqual(arr2[31], std::string("goodbye"));
			Assert::AreEqual(arr2[32], std::string("sleep"));
			Assert::AreEqual(arr.size(), 0);
		}
		
		TEST_METHOD(IntTest)
		{
			MyArray<int> arrayTest;
			Assert::AreEqual(0, arrayTest.size());
			for (int i = 0; i < 10; i++) {
				arrayTest.insert(i + 1);
			}
			Assert::AreEqual(10, arrayTest.size());


		}
		TEST_METHOD(CopyConstructorTest)
		{
			MyArray<int> arrayTestA;
			Assert::AreEqual(0, arrayTestA.size());
			for (int i = 0; i < 10; i++) {
				arrayTestA.insert(i + 1);
			}

			MyArray<int> arrayTestB(arrayTestA);

			Assert::AreEqual(arrayTestA.size(), arrayTestB.size());
			Assert::AreEqual(arrayTestA.capacity(), arrayTestB.capacity());

			for (int i = 0; i < arrayTestA.size(); i++) {
				Assert::AreEqual(arrayTestA[i], arrayTestB[i]);
			}
		}

		TEST_METHOD(MoveConstructorTest) {
			MyArray<int> arrayTestA;
			Assert::AreEqual(0, arrayTestA.size());
			for (int i = 0; i < 10; i++) {
				arrayTestA.insert(i);
			}

			int arrayASize = arrayTestA.size();
			int arrayACapacity = arrayTestA.capacity();

			MyArray<int> arrayTestB = std::move(arrayTestA);

			Assert::AreEqual(arrayASize, arrayTestB.size());
			Assert::AreEqual(arrayACapacity, arrayTestB.capacity());

			for (int i = 0; i < arrayTestB.size(); i++) {
				Assert::AreEqual(arrayTestB[i], i);
			}
		}

	};
}
