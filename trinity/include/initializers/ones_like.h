#pragma once
#ifndef TRINITY_ONES_LIKE_H
#define TRINITY_ONES_LIKE_H

#include "../initializers/initializer.h"
#include "../ndarray/matrix.h"

template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> ones_like(
    const Matrix<DType, NDimensions>& matrix_input) {
  return initializer(matrix_input, 1);
}

#endif  // TRINITY_ONES_LIKE_H
