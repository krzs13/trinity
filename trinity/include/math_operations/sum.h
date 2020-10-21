#pragma once
#ifndef TRINITY_SUM_H
#define TRINITY_SUM_H

#include "../ndarray/matrix.h"

template <typename DType, size_t NDimensions>
size_t sum(const Matrix<DType, NDimensions>& matrix_input) {
  size_t result{};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result += matrix_input.data()[i];
  }

  return result;
}

#endif  // TRINITY_SUM_H
