#include "test.hpp"


tempTest::tempTest()
{
	//run n tests
	this->Test1();
	this->Test2();
	this->Test3();
}

/**	
* @brief Test if we can csv files
*/
void tempTest::Test1() {
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	const char* whitewine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-white.csv" };
	Reader file_reader;
	file_reader.Read(redwine);
	file_reader.Read(whitewine);
}

void tempTest::Test2()
{
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	Reader file_reader;
	Eigen::MatrixXf temp_mat = file_reader.CSVtoEigen<Eigen::MatrixXf>(redwine);

	std::cout << "mat size\t " << temp_mat.size() << std::endl;
	Eigen::VectorXf row0 = temp_mat.col(0);
	std::cout << "first column size\t" << row0.size() << std::endl;
}

void tempTest::Test3()
{
	const char* redwine{ "C:/Users/Daniel/source/repos/RegressionCpp/data/winequality-red.csv" };
	Reader file_reader;
	DataFrame dataframe;
	dataframe.ReadData(redwine);
	
	Eigen::VectorXf quality_vec;
	try
	{
		quality_vec = dataframe.GetVectorbyColumn("citric acid");
	}
	catch (const std::exception& ex)
	{
		std::cout << "caught\t" << ex.what();
	}

}
