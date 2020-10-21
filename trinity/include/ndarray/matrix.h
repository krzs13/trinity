#pragma once
#ifndef TRINITY_MATRIX_H
#define TRINITY_MATRIX_H

#include "../ndarray/ndarray.h"

using std::copy;
using std::initializer_list;

template <typename DType, size_t NDimensions>
class Matrix : public NDArray<DType, NDimensions> {
 public:
  Matrix() : NDArray<DType, NDimensions>() {}

  Matrix(initializer_list<size_t> shape) : NDArray<DType, NDimensions>(shape) {}

  Matrix(size_t n_dimensions, size_t* shape, size_t size, DType* data)
      : NDArray<DType, NDimensions>(n_dimensions, shape, size, data) {}

  Matrix(const Matrix& matrix_other)
      : NDArray<DType, NDimensions>(matrix_other) {}

  Matrix(Matrix&& matrix_other) : NDArray<DType, NDimensions>(matrix_other) {}

  ~Matrix() {}

  Matrix& operator=(const Matrix& matrix_other) {
    NDArray<DType, NDimensions>::operator=(matrix_other);

    return *this;
  }

  Matrix& operator=(Matrix&& matrix_other) {
    NDArray<DType, NDimensions>::operator=(matrix_other);

    return *this;
  }

  friend Matrix operator+(const Matrix<DType, NDimensions>& matrix_1,
                          const Matrix<DType, NDimensions>& matrix_2) {
    return add(matrix_1, matrix_2);
  }

  friend Matrix operator+(const Matrix<DType, NDimensions>& matrix_input,
                          DType scalar) {
    return add(matrix_input, scalar);
  }

  void operator+=(const Matrix<DType, NDimensions>& matrix_other) {
    *this = add(*this, matrix_other);
  }

  void operator+=(DType scalar) { *this = add(*this, scalar); }

  friend Matrix operator-(const Matrix<DType, NDimensions>& matrix_1,
                          const Matrix<DType, NDimensions>& matrix_2) {
    return subtract(matrix_1, matrix_2);
  }

  friend Matrix operator-(const Matrix<DType, NDimensions>& matrix_input,
                          DType scalar) {
    return subtract(matrix_input, scalar);
  }

  void operator-=(const Matrix<DType, NDimensions>& matrix_other) {
    *this = subtract(*this, matrix_other);
  }

  void operator-=(DType scalar) { *this = subtract(*this, scalar); }

  friend Matrix operator*(const Matrix<DType, NDimensions>& matrix_1,
                          const Matrix<DType, NDimensions>& matrix_2) {
    return multiply(matrix_1, matrix_2);
  }

  friend Matrix operator*(const Matrix<DType, NDimensions>& matrix_input,
                          DType scalar) {
    return multiply(matrix_input, scalar);
  }

  void operator*=(const Matrix<DType, NDimensions>& matrix_other) {
    *this = multiply(*this, matrix_other);
  }

  void operator*=(DType scalar) { *this = multiply(*this, scalar); }

  friend Matrix operator/(const Matrix<DType, NDimensions>& matrix_1,
                          const Matrix<DType, NDimensions>& matrix_2) {
    return divide(matrix_1, matrix_2);
  }

  friend Matrix operator/(const Matrix<DType, NDimensions>& matrix_input,
                          DType scalar) {
    return divide(matrix_input, scalar);
  }

  void operator/=(const Matrix<DType, NDimensions>& matrix_other) {
    *this = divide(*this, matrix_other);
  }

  void operator/=(DType scalar) { *this = divide(*this, scalar); }
};

#endif  // TRINITY_MATRIX_H
