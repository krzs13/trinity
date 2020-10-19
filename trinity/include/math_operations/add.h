#pragma once
#ifndef TRINITY_ADD_H
#define TRINITY_ADD_H

#include "../ndarray/matrix.h"

template <typename DType, size_t... NShape>
Matrix<DType, NShape...> add(const Matrix<DType, NShape...>& matrix_1,
                             const Matrix<DType, NShape...>& matrix_2) {
  DType result[matrix_1.size()]{};

  for (size_t i = 0; i < matrix_1.size(); i++) {
    result[i] = matrix_1.data()[i] + matrix_2.data()[i];
  }

  Matrix<DType, NShape...> output{matrix_1.n_dimensions(), matrix_1.shape(),
                                  matrix_1.size(), result};

  return output;
}

#endif  // TRINITY_ADD_H
