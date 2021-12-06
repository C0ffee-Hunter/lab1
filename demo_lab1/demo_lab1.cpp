#include "pch.h"
#include "CppUnitTest.h"
#include"..\lab1\List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(Lab1_list)
	{
	public:

		TEST_METHOD(push_back_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1); 
			list.push_back(115); 
			Assert::IsTrue(list.IsEmpty() == 0); 
			Assert::IsTrue(list.at(0) == 115); 
			list.push_back(39); 
			Assert::IsTrue(list.at(1) == 39); 
			list.push_back(5);
			Assert::IsTrue(list.at(2) == 5); 
		}

		TEST_METHOD(push_front_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1);  
			list.push_front(2); 
			Assert::IsTrue(list.IsEmpty() == 0); 
			Assert::IsTrue(list.at(0) == 2); 
			list.push_front(204); 
			Assert::IsTrue(list.at(0) == 204); 
		}

		TEST_METHOD(pop_back_test)
		{
			List list;
			list.push_back(1);
			list.push_back(2); 
			list.push_back(3); 
			Assert::IsTrue(list.at(2) == 3); 
			list.pop_back(); 
			Assert::IsTrue(list.at(1) == 2); 
			list.pop_back(); 
			Assert::IsTrue(list.at(0) == 1);
			list.pop_back(); 
			Assert::IsTrue(list.IsEmpty() == 1); 
		}

		TEST_METHOD(pop_front_test)
		{
			List list;
			list.push_back(1); 
			list.push_back(2); 
			list.push_back(3); 
			Assert::IsTrue(list.at(0) == 1);
			list.pop_front();  
			Assert::IsTrue(list.at(0) == 2);
		}

		TEST_METHOD(insert_test)
		{
			List list;
			list.push_back(1);
			list.push_back(2);
			list.push_back(3);
			list.push_back(4);
			Assert::IsTrue(list.at(1) == 2);
			list.insert(5, 1); 
			Assert::IsTrue(list.at(1) == 5);
			Assert::IsTrue(list.at(2) == 2);
			Assert::IsTrue(list.at(4) == 4);
		}

		TEST_METHOD(at_test)
		{
			List list;
			list.push_back(6);
			list.push_back(-3);
			list.push_back(78);
			list.push_back(-43); 
			Assert::IsTrue(list.at(0) == 6);
			Assert::IsTrue(list.at(1) == -3);
			Assert::IsTrue(list.at(2) == 78);
			Assert::IsTrue(list.at(3) == -43);
		}

		TEST_METHOD(remove_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1);
			list.push_front(45);
			Assert::IsTrue(list.IsEmpty() == 0);
			list.remove(0);
			Assert::IsTrue(list.IsEmpty() == 1);

			list.push_front(1);
			list.push_front(2);
			list.push_front(3);
			list.remove(0);
			Assert::IsTrue(list.IsEmpty() == 0);
			Assert::IsTrue(list.at(0) == 2);
		}

		TEST_METHOD(get_size_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1 && list.get_size() == 0);
			list.push_front(345);
			Assert::IsTrue(list.get_size() == 1);
		}

		TEST_METHOD(clear_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1);
			list.push_front(345);
			list.push_front(34);
			list.push_front(35);
			list.push_front(45);
			Assert::IsTrue(list.get_size() == 4);
			list.clear();
			Assert::IsTrue(list.IsEmpty() == 1);
		}

		TEST_METHOD(set_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1);
			list.push_front(5);
			list.push_front(6);
			list.push_front(7);
			list.push_front(8);
			Assert::IsTrue(list.at(1) == 7);
			list.set(1, 1);
			Assert::IsTrue(list.get_size() == 4 && list.at(1) == 1);

		}
		TEST_METHOD(IsEmpty_test)
		{
			List list;
			Assert::IsTrue(list.IsEmpty() == 1);
			list.push_front(5);
			Assert::IsTrue(list.IsEmpty() == 0);
		}
	};
}
