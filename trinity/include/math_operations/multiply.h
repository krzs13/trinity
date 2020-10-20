#pragma once
#ifndef TRINITY_MULTIPLY_H
#define TRINITY_MULTIPLY_H

#include "../ndarray/matrix.h"

template <typename DType, size_t... NShape>
Matrix<DType, NShape...> multiply(const Matrix<DType, NShape...>& matrix_1,
                                  const Matrix<DType, NShape...>& matrix_2) {
  DType* result{new DType[matrix_1.size()]{}};

  for (size_t i = 0; i < matrix_1.size(); i++) {
    result[i] = matrix_1.data()[i] * matrix_2.data()[i];
  }

  Matrix<DType, NShape...> output{matrix_1.n_dimensions(), matrix_1.shape(),
                                  matrix_1.size(), result};

  return output;
}

template <typename DType, size_t... NShape>
Matrix<DType, NShape...> multiply(const Matrix<DType, NShape...>& matrix_input,
                                  DType scalar) {
  DType* result{new DType[matrix_input.size()]{}};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result[i] = matrix_input.data()[i] * scalar;
  }

  Matrix<DType, NShape...> output{matrix_input.n_dimensions(),
                                  matrix_input.shape(), matrix_input.size(),
                                  result};

  return output;
}

#endif  // TRINITY_MULTIPLY_H
