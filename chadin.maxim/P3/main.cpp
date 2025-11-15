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
}

void chadin::increaseElements(int * arr, size_t rows, size_t cols)
{
}

int chadin::countDiagonals(const int * arr, size_t rows, size_t cols)
{
}
