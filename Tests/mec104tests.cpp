#include "CppUnitTest.h"
#include "../Luke Project/mec104.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public: mec104 mec;
		
		TEST_METHOD(calculate_mrr_test)
		{
			Assert::IsTrue(is_equal(24.0, mec.calculate_mrr(2, 3, 4)));
		}

		TEST_METHOD(calculate_scs_test)
		{
			Assert::IsTrue(is_equal(62.8318, mec.calculate_scs(3.14159, 2, 10)));
		}

		TEST_METHOD(calculate_spindle_test)
		{
			Assert::IsTrue(is_equal(0.132629, mec.calculate_spindlespeed(5, 3.14159, 12)));
		}

		TEST_METHOD(calculate_mp_test)
		{
			Assert::IsTrue(is_equal(50, mec.calculate_mp(5, 10)));
		}

		TEST_METHOD(calculate_upf_test)
		{
			Assert::IsTrue(is_equal(4, mec.calculate_upf(20, 5)));
		}

		TEST_METHOD(calculate_mpmrr_test)
		{
			Assert::IsTrue(is_equal(5, mec.calculate_mp_mrr(5, 25)));
		}
		
		bool is_equal(double a, double b, const double epsilon = 1e-5)
		{
			double c = a - b;
			return c < epsilon && -c < epsilon;  
		}
	};
}