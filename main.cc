#include <iostream>

#include "trinity/include/trinity.h"

using std::cout;

template <typename DataType, size_t... MatrixShape>
Matrix<DataType, MatrixShape...> move_test() {
  Matrix<DataType, MatrixShape...> result{1};

  return result;
}

int main(int, char**) {
  Matrix<int, 5> tensor_1{1, 2, 3};
  Matrix<int, 5> tensor_2{1, 2, 3, 4, 5};

  cout << tensor_1.n_dimensions() << '\n';
  cout << tensor_1.shape()[0] << '\n';
  cout << tensor_1.size() << '\n';

  tensor_1 = tensor_2;
  tensor_1.get_data();
  tensor_1 = move_test<int, 5>();
  tensor_1.get_data();
}
