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
  // Matrix<double, 5> tensor_1{1.0, 2.8, 3.7898};
  // Matrix<double, 5> tensor_2{10.25, 20.2126749856, 30.221, 40.0, 50.8756};
  // Matrix<double, 5> tensor_3{1.258, 2.787, 3.2, 4.8, 5.6};
  // Matrix<double, 5> tensor_4{};
  // // tensor_4 = add(tensor_2, tensor_3);
  // tensor_4 = ((tensor_2 + 1000 + tensor_1) * tensor_3) / 200;
  // // tensor_4 *= tensor_2;

  // // cout << sum(tensor_2) << '\n';

  // print_data(tensor_4.data(), tensor_4.size());
  // array<size_t, > x[1]{};
  Matrix<int, 2> tensor_1{2, 2};
  Matrix<int, 2> tensor_2{2, 2};

  // cout << tensor_1.size() << '\n';
  tensor_1.insert({1, 2, 3, 4});
  tensor_2.insert({1, 2, 3, 4});

  tensor_1 += tensor_2 * 2;
  print_data(tensor_1.data(), tensor_1.size());
  size_t idx[2]{1, 1};
  cout << tensor_1.find(idx) << '\n';

  // cout << tensor_1.compare_shape(tensor_2) << '\n';
}
