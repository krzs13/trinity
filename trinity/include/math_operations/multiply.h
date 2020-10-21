#pragma once
#ifndef TRINITY_MULTIPLY_H
#define TRINITY_MULTIPLY_H

#include "../ndarray/matrix.h"

namespace trinity {
template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> multiply(
    const Matrix<DType, NDimensions>& matrix_1,
    const Matrix<DType, NDimensions>& matrix_2) {
  assert(matrix_1.compare_shape(matrix_2) &&
         "Matrices could not be broadcast together with different shapes.");

  DType* result{new DType[matrix_1.size()]{}};

  for (size_t i = 0; i < matrix_1.size(); i++) {
    result[i] = matrix_1.data()[i] * matrix_2.data()[i];
  }

  Matrix<DType, NDimensions> output{matrix_1.n_dimensions(), matrix_1.shape(),
                                    matrix_1.size(), result};

  return output;
}

template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> multiply(
    const Matrix<DType, NDimensions>& matrix_input, DType scalar) {
  DType* result{new DType[matrix_input.size()]{}};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result[i] = matrix_input.data()[i] * scalar;
  }

  Matrix<DType, NDimensions> output{NDimensions, matrix_input.shape(),
                                    matrix_input.size(), result};

  return output;
}
}  // namespace trinity

#endif  // TRINITY_MULTIPLY_H
