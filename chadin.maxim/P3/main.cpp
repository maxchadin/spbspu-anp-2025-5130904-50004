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
      if (j < cols - 1) output << " ";
    }
    output << "\n";
  }
  return output;
}

void chadin::increaseElements(int * arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) return;

  size_t t = rows * cols;
  int * temp = new int [t];
  for (size_t i = 0; i < t; i++)
  {
    temp[i] = arr[i];
  }

  int left = 0;
  int right = cols - 1;
  int up = 0;
  int down = rows - 1;
  int step = 1;

  while (left <= right && up <= down)
  {
    for (int i = down; i >= up; i--)
    {
      size_t index = i * cols + left;
      temp[index] += step++;
    }
    left++;
    if (left > right) break;
    for (int j = left; j <= right; j++)
    {
      size_t index = down * cols + j;
      temp[index] += step++;
    }
    if (up == down) break;
    down--;
    if (up > down) break;
    for (int j = right; j >= left; j--)
    {
      size_t index = down * cols + j;
      temp[index] += step++;
    }
    if (left == right) break;
    right--;
    if (left > right) break;
    for (int i = down - 1; i >= up; i--)
    {
      size_t index = i * cols + right;
      temp[index] += step++;
    }
    up++;
  }

  for (size_t i = 0; i < t; i++)
  {
    arr[i] = temp[i];
  }
  delete[] temp;
}

int chadin::countDiagonals(const int * arr, size_t rows, size_t cols)
{
  if (rows == 0 || cols == 0) {
    return 0;
  }
  int count = 0;
  for (size_t start_col = 0; start_col < cols; start_col++) {
    bool has_zero = false;
    size_t r = 0;
    size_t c = start_col;
    while (r < rows && c < cols) {
      if (arr[r * cols + c] == 0) {
        has_zero = true;
        break;
      }
      r++;
      c++;
    }
    if (!has_zero) {
      count++;
    }
  }
  for (size_t start_row = 1; start_row < rows; start_row++) {
    bool has_zero = false;
    size_t r = start_row;
    size_t c = 0;
    while (r < rows && c < cols) {
      if (arr[r * cols + c] == 0) {
        has_zero = true;
        break;
      }
      r++;
      c++;
    }
    if (!has_zero) {
      count++;
    }
  }
  return count;
}
