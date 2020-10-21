#pragma once
#ifndef TRINITY_RANDOM_LIKE_H
#define TRINITY_RANDOM_LIKE_H

#include "../initializers/initializer.h"
#include "../ndarray/matrix.h"

namespace trinity {
template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> random_like(
    const Matrix<DType, NDimensions>& matrix_input, DType minimum,
    DType maximum) {
  return random_initializer(matrix_input, minimum, maximum);
}

template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> random_like(
    const Matrix<DType, NDimensions>& matrix_input) {
  return random_initializer(matrix_input);
}
}  // namespace trinity

#endif  // TRINITY_RANDOM_H
