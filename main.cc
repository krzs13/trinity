#include <iostream>
#include <tuple>

#include "trinity/include/trinity.h"

using std::cout;
using std::get;
using std::index_sequence;
using std::make_tuple;
using std::tie;
using std::tuple;

template <typename DataType, size_t... MatrixShape>
Matrix<DataType, MatrixShape...> move_test() {
  Matrix<DataType, MatrixShape...> result{1};

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
  Matrix<int, 5> tensor_1{1, 2, 3};
  Matrix<int, 5> tensor_2{10, 20, 30, 40, 50};
  Matrix<int, 5> tensor_3{1, 2, 3, 4, 5};
  Matrix<int, 5> tensor_4{};
  // tensor_4 = add(tensor_2, tensor_3);
  tensor_4 = tensor_2 + 1000;
  // tensor_4 *= tensor_2;

  // cout << sum(tensor_2) << '\n';

  print_data(tensor_4.data(), tensor_4.size());
}
