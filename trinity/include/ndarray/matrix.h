#pragma once
#ifndef TRINITY_MATRIX_H
#define TRINITY_MATRIX_H

#include "../ndarray/ndarray.h"

using std::copy;
using std::initializer_list;

template <typename DType, size_t... NShape>
class Matrix : public NDArray<DType, NShape...> {
 public:
  Matrix() : NDArray<DType, NShape...>() {}

  Matrix(initializer_list<DType> data) : NDArray<DType, NShape...>(data) {}

  Matrix(size_t n_dimensions, size_t* shape, size_t size, DType* data)
      : NDArray<DType, NShape...>(n_dimensions, shape, size, data) {}

  Matrix(const Matrix& matrix_copy) : NDArray<DType, NShape...>(matrix_copy) {}

  Matrix(Matrix&& matrix_move) : NDArray<DType, NShape...>(matrix_move) {}

  ~Matrix() {}

  Matrix& operator=(const Matrix& matrix_copy) {
    NDArray<DType, NShape...>::operator=(matrix_copy);

    return *this;
  }

  Matrix& operator=(Matrix&& matrix_move) {
    NDArray<DType, NShape...>::operator=(matrix_move);

    return *this;
  }

  friend Matrix operator+(Matrix<DType, NShape...> matrix_1,
                          Matrix<DType, NShape...> matrix_2) {
    return add(matrix_1, matrix_2);
  }

  void operator+=(Matrix<DType, NShape...> matrix_add) {
    *this = add(*this, matrix_add);
  }

  friend Matrix operator-(Matrix<DType, NShape...> matrix_1,
                          Matrix<DType, NShape...> matrix_2) {
    return subtract(matrix_1, matrix_2);
  }

  void operator-=(Matrix<DType, NShape...> matrix_add) {
    *this = subtract(*this, matrix_add);
  }

  friend Matrix operator*(Matrix<DType, NShape...> matrix_1,
                          Matrix<DType, NShape...> matrix_2) {
    return multiply(matrix_1, matrix_2);
  }

  void operator*=(Matrix<DType, NShape...> matrix_add) {
    *this = multiply(*this, matrix_add);
  }

  friend Matrix operator/(Matrix<DType, NShape...> matrix_1,
                          Matrix<DType, NShape...> matrix_2) {
    return divide(matrix_1, matrix_2);
  }

  void operator/=(Matrix<DType, NShape...> matrix_add) {
    *this = divide(*this, matrix_add);
  }
};

#endif  // TRINITY_MATRIX_H
