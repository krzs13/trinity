#include <iostream>
#include <tuple>

#include "trinity/include/trinity.h"

using std::cout;
using std::tuple;
using std::make_tuple;
using std::tie;
using std::get;
using std::index_sequence;

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
  Matrix<int, 5> tensor_2{1, 2, 3, 4, 5};  
  Matrix<int, 5> tensor_3{1, 2};

  tensor_3 = move_test<int, 5>();

  cout << tensor_3.size() << '\n';
  print_data<int>(tensor_3.data(), tensor_3.size());


  // cout << tensor_1.n_dimensions() << '\n';
  // cout << tensor_1.shape()[0] << '\n';
  // cout << tensor_1.size() << '\n';

  // tensor_1 = tensor_2;
  // print_data(tensor_1.data(), tensor_2.size());
  // tensor_1 = move_test<int, 5>();
  // print_data(tensor_1.data(), tensor_2.size());
  // Matrix<int, 5> tensor_1{1, 2, 3, 4, 5};
  
}
