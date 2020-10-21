#pragma once
#ifndef TRINITY_ZEROS_LIKE_H
#define TRINITY_ZEROS_LIKE_H

#include "../initializers/initializer.h"
#include "../ndarray/matrix.h"

namespace trinity {
template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> zeros_like(
    const Matrix<DType, NDimensions>& matrix_input) {
  return initializer(matrix_input, 0);
}
}  // namespace trinity

#endif  // TRINITY_ZEROS_LIKE_H
