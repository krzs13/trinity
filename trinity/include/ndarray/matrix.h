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

  Matrix(const Matrix& matrix_other)
      : NDArray<DType, NShape...>(matrix_other) {}

  Matrix(Matrix&& matrix_other) : NDArray<DType, NShape...>(matrix_other) {}

  ~Matrix() {}

  Matrix& operator=(const Matrix& matrix_other) {
    NDArray<DType, NShape...>::operator=(matrix_other);

    return *this;
  }

  Matrix& operator=(Matrix&& matrix_other) {
    NDArray<DType, NShape...>::operator=(matrix_other);

    return *this;
  }

  friend Matrix operator+(const Matrix<DType, NShape...>& matrix_1,
                          const Matrix<DType, NShape...>& matrix_2) {
    return add(matrix_1, matrix_2);
  }

  friend Matrix operator+(const Matrix<DType, NShape...>& matrix_input,
                          DType scalar) {
    return add(matrix_input, scalar);
  }

  void operator+=(const Matrix<DType, NShape...>& matrix_other) {
    *this = add(*this, matrix_other);
  }

  void operator+=(DType scalar) { *this = add(*this, scalar); }

  friend Matrix operator-(const Matrix<DType, NShape...>& matrix_1,
                          const Matrix<DType, NShape...>& matrix_2) {
    return subtract(matrix_1, matrix_2);
  }

  friend Matrix operator-(const Matrix<DType, NShape...>& matrix_input,
                          DType scalar) {
    return subtract(matrix_input, scalar);
  }

  void operator-=(const Matrix<DType, NShape...>& matrix_other) {
    *this = subtract(*this, matrix_other);
  }

  void operator-=(DType scalar) { *this = subtract(*this, scalar); }

  friend Matrix operator*(const Matrix<DType, NShape...>& matrix_1,
                          const Matrix<DType, NShape...>& matrix_2) {
    return multiply(matrix_1, matrix_2);
  }

  friend Matrix operator*(const Matrix<DType, NShape...>& matrix_input,
                          DType scalar) {
    return multiply(matrix_input, scalar);
  }

  void operator*=(const Matrix<DType, NShape...>& matrix_other) {
    *this = multiply(*this, matrix_other);
  }

  void operator*=(DType scalar) { *this = multiply(*this, scalar); }

  friend Matrix operator/(const Matrix<DType, NShape...>& matrix_1,
                          const Matrix<DType, NShape...>& matrix_2) {
    return divide(matrix_1, matrix_2);
  }

  friend Matrix operator/(const Matrix<DType, NShape...>& matrix_input,
                          DType scalar) {
    return divide(matrix_input, scalar);
  }

  void operator/=(const Matrix<DType, NShape...>& matrix_other) {
    *this = divide(*this, matrix_other);
  }

  void operator/=(DType scalar) { *this = divide(*this, scalar); }
};

#endif  // TRINITY_MATRIX_H
