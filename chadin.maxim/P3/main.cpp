#include <iostream>
#include <fstream>
#include <cstdlib>

namespace chadin
{
  std::istream & readArr(std::istream & input, int * arr, size_t rows, size_t cols);
  std::ostream & writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result);
  void increaseElements(int * arr, size_t rows, size_t cols);
  int countDiagonals(const int * arr, size_t rows, size_t cols);
}

std::istream & chadin::readArr(std::istream & input, int * arr, size_t rows, size_t cols)
{
  size_t number = 0;
  for (size_t i = 0; i < rows * cols && input >> arr[i]; i++)
  {
    ++number;
  }
  if (!input)
  {
    std::cerr << "Incorrect input" << "\n";
  }
  else if (rows * cols > number)
  {
    std::cerr << "Not enough elements" << "\n";
  }
  return input;
}

std::ostream & chadin::writeArr(std::ostream & output, const int * arr, size_t rows, size_t cols, int result)
{
  output << result << "\n";
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      output << arr[i * cols + j];
      if (j < cols - 1) output << " "; // Разделитель внутри строки
    }
    output << "\n"; // Новая строка после каждой строки матрицы
  }
  return output;
}

void chadin::increaseElements(int * arr, size_t rows, size_t cols)
{
}

int chadin::countDiagonals(const int * arr, size_t rows, size_t cols)
{
}
