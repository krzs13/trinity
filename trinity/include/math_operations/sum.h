#pragma once
#ifndef TRINITY_SUM_H
#define TRINITY_SUM_H

#include "../ndarray/matrix.h"

template <typename DType, size_t... NShape>
size_t sum(const Matrix<DType, NShape...>& matrix_1) {
  size_t result{};

  for (size_t i = 0; i < matrix_1.size(); i++) {
    result += matrix_1.data()[i];
  }

  return result;
}

#endif  // TRINITY_SUM_H
