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
