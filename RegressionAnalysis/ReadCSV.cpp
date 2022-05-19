#include "ReadCSV.hpp"


void DataFrame::SetMatrix(const Eigen::MatrixXf& M)  
{
    this->csv_data = M;
    this->is_set = true;
}

std::vector<std::string> DataFrame::GetNames()
{
    if (not this->is_set)
    {
        throw std::exception("Dataframe not set");
    }
    else
    {
        return this->names;
    }
}

Eigen::VectorXf DataFrame::GetVectorbyColumn(const char* name)
{
    if (not this->is_set)
    {
        throw std::exception("Dataframe not set");
    }
    else if (this->names.empty())
    {
        throw std::exception("Column names are empty");
    }
    else
    {
        //index of interest
        uint32_t index{ 0 };
        //loop through vector of string names
        for (size_t i = 0; i < this->names.size(); i++)
        {       
            //if found
            if (this->names.at(i) == name)
            {
                return this->csv_data.col(i);
            }
        }
        throw std::exception("Cannot find column by that string name");
  
    }
}


void DataFrame::ReadData(const std::string& input_file)
{
    
    this->csv_data = this->CSVtoEigen<Eigen::MatrixXf>(input_file);
    this->is_set = true;
}

/**
* @brief Gets the total number of columns, and rows from path to csv data
* @param input_file path to the file
*/
void Reader::Read(const std::string& input_file)
{
    csv::CSVReader reader(input_file);
    auto col_names = reader.get_col_names();
    uint32_t col_index{ 0 };
    //get all rows for n_rows()
    for (csv::CSVRow& row : reader)
    {

    }
    std::cout << "READ CSV FROM FILE PATH\t" << input_file
        << "\nTotal Columns\t" << col_names.size()
        << "\nTotal Rows\t" << reader.n_rows()
        << "\nColumn Names\t";
         for (auto& cols : col_names)
         {
             std::cout <<"[" << col_index++  << "]\t" << cols <<"\t";
         }
    std::cout << std::endl;
   
}


   