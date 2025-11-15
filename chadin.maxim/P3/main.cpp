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

int main()
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" <<"\n";
    return 1;
  }
  if (argv[1][0] != '1' && argv[1][0] != '2')
  {
    std::cerr << "First parameter is out of range or first parameter is not a number" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input.is_open() || !output.is_open())
  {
    std::cerr << "Error opening files" << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  int result = 0;
  if (!(input >> rows))
  {
    std::cerr << "Incorrect number of rows" << "\n";
    return 2;
  }
  else if (!(input >>cols))
  {
    std::cerr << "Incorrect number of columns" << "\n";
    return 2;
  }
  if (argv[1][0] == '1')
  {
    if (rows * cols > 10000)
    {
      std::cerr << "Too large matrix" << "\n";
      return 2;
    }
    int arr[10000] = {};
    chadin::readArr(input, arr, rows, cols);
    if (!input)
    {
      return 2;
    }
    input.close();
    result = chadin::countDiagonals(arr, rows, cols);
    chadin::writeArr(output, arr, rows, cols, result);
  }
  else if (argv[1][0] == '2')
  {
    int * arr = nullptr;
    try
    {
      if (rows > 0 && cols > 0) {
        if (rows > SIZE_MAX / cols) {
          std::cerr << "Too large matrix" << "\n";
          return 2;
        }
        size_t total_elements = rows * cols;
        if (total_elements > SIZE_MAX / sizeof(int)) {
          std::cerr << "Too large matrix" << "\n";
          return 2;
        }
        arr = new int[total_elements] {};
      } else {
          arr = nullptr;
      }
      chadin::readArr(input, arr, rows, cols);
      if (!input)
      {
        delete[] arr;
        return 2;
      }
      input.close();
      chadin::increaseElements(arr, rows, cols);
      chadin::writeArr(output, arr, rows, cols, 0);

      delete[] arr;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error" << "\n";
      delete[] arr;
      return 1;
    }
    catch (...)
    {
      std::cerr << "Error" << "\n";
      delete[] arr;
      return 1;
    }
  }
  return 0;
}
