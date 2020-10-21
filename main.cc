#include <array>
#include <iostream>
#include <tuple>

#include "trinity/include/trinity.h"

using std::array;
using std::cout;
using std::get;
using std::index_sequence;
using std::make_tuple;
using std::tie;
using std::tuple;

template <typename DataType, size_t NDimensions>
Matrix<DataType, NDimensions> move_test() {
  Matrix<DataType, NDimensions> result{1};

  return result;
}

template <typename DataType>
void print_data(DataType* data, size_t size) {
  for (size_t i = 0; i < size; i++) {
    cout << data[i] << ' ';
  }

  cout << '\n';
}

int main(int, char**) {
  Matrix<int, 2> tensor_1{2, 3};
  Matrix<int, 2> tensor_2{3, 2};
  Matrix<int, 2> tensor_3{2, 3};
  Matrix<int, 2> tensor_4{3, 4};
  Matrix<int, 2> tensor_5{};
  Matrix<int, 2> tensor_6{};

  tensor_1.insert({1, 2, 3, 4, 5, 6});
  tensor_2.insert({10, 11, 20, 21, 30, 31});
  tensor_3.insert({2, 1, 4, 0, 1, 1});
  tensor_4.insert({6, 3, -1, 0, 1, 1, 0, 4, -2, 5, 0, 2});

  tensor_5 = tensor_1 & tensor_2;
  print_data(tensor_5.data(), tensor_5.size());

  tensor_6 = dot(tensor_3, tensor_4);
  print_data(tensor_6.data(), tensor_6.size());

  tensor_1 &= tensor_4;
  print_data(tensor_1.data(), tensor_1.size());
}
