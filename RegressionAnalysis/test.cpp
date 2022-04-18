#include "test.hpp"
#include "ReadCSV.hpp"


tempTest::tempTest()
{
	//run n tests
	this->Test1();
}

void tempTest::Test1() {
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	const char* whitewine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-white.csv" };
	Reader file_reader;
	file_reader.Read(redwine);
	file_reader.Read(whitewine);


}
