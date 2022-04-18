#include "ReadCSV.hpp"


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