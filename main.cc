#include <iostream>

#include "trinity/include/trinity.h"

using std::cout;
using trinity::add;
using trinity::divide;
using trinity::dot;
using trinity::Matrix;
using trinity::multiply;
using trinity::ones_like;
using trinity::random_like;
using trinity::subtract;
using trinity::sum;
using trinity::transpose;
using trinity::zeros_like;

int main(int, char**) {
  cout << "/// ADD, SUBTRACT, MULTIPLY, DIVIDE ///"
       << "\n\n";

  Matrix<int, 2> matrix_a{3, 5};
  Matrix<int, 2> matrix_b{3, 5};
  Matrix<int, 2> matrix_c{};

  matrix_a.insert({1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3});
  matrix_b.insert({1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3});
  matrix_c = matrix_a + matrix_b;
  // matrix_c = add(matrix_a, matrix_b);
  // matrix_c = matrix_a - matrix_b;
  // matrix_c = subtract(matrix_a, matrix_b);
  // matrix_c = matrix_a * matrix_b;
  // matrix_c = multiply(matrix_a, matrix_b);
  // matrix_c = matrix_a / matrix_b;
  // matrix_c = divide(matrix_a, matrix_b);

  cout << "Matrix A:" << '\n';
  cout << matrix_a << '\n';

  cout << "Matrix B:" << '\n';
  cout << matrix_b << '\n';

  cout << "RESULT:" << '\n';
  cout << matrix_c << '\n';

  cout << "/// DOT PRODUCT ///"
       << "\n\n";

  Matrix<int, 2> matrix_a_a{3, 5};
  Matrix<int, 2> matrix_b_b{5, 2};
  Matrix<int, 2> matrix_c_c{};

  matrix_a_a.insert({1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3});
  matrix_b_b.insert({1, 1, 2, 2, 3, 3, 4, 4, 5, 5});
  matrix_c_c = matrix_a_a & matrix_b_b;
  // matrix_c_c = dot(matrix_a_a, matrix_b_b);

  cout << "Matrix A:" << '\n';
  cout << matrix_a_a << '\n';

  cout << "Matrix B:" << '\n';
  cout << matrix_b_b << '\n';

  cout << "RESULT:" << '\n';
  cout << matrix_c_c << '\n';

  cout << "/// TRANSPOSITION ///"
       << "\n\n";

  Matrix<int, 2> matrix_a_a_a{2, 4};

  matrix_a_a_a.insert({10, 11, 12, 13, 20, 21, 22, 23});

  cout << "Matrix A:" << '\n';
  cout << matrix_a_a_a << '\n';

  cout << "Matrix A.T:" << '\n';
  cout << matrix_a_a_a.T() << '\n';

  cout << "/// SUM & INITIALIZERS ///"
       << "\n\n";

  Matrix<int, 2> matrix_a_a_a_a{2, 4};

  matrix_a_a_a_a.ones();
  // matrix_a_a_a_a.zeros();
  // matrix_a_a_a_a.random()
  // matrix_a_a_a_a.random(1, 10);

  cout << "Matrix A:" << '\n';
  cout << matrix_a_a_a_a << '\n';

  cout << "SUM:" << '\n';
  cout << sum(matrix_a_a_a_a) << '\n';
}
