#pragma once
#ifndef TRINITY_TRANSPOSE_H
#define TRINITY_TRANSPOSE_H

#include "../ndarray/matrix.h"
#include "../utilities/calculate_index.h"

using std::copy;
using std::reverse_copy;

namespace trinity {
template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> transpose(
    const Matrix<DType, NDimensions>& matrix_input) {
  size_t size{matrix_input.size()};
  size_t indices[NDimensions]{};
  size_t output_indices[NDimensions]{};
  size_t shape[NDimensions]{};
  size_t* output_shape{new size_t[NDimensions]{}};
  DType* result{new DType[size]{}};

  copy(matrix_input.shape(), matrix_input.shape() + NDimensions, shape);
  reverse_copy(matrix_input.shape(), matrix_input.shape() + NDimensions,
               output_shape);

  for (size_t i = 0; i < size; i++) {
    reverse_copy(indices, indices + NDimensions, output_indices);
    result[calculate_index(output_indices, output_shape, size, NDimensions,
                           NDimensions)] =
        matrix_input.data()[calculate_index(indices, shape, size, NDimensions,
                                            NDimensions)];

    indices[NDimensions - 1] =
        (indices[NDimensions - 1] + 1) % shape[NDimensions - 1];

    for (size_t j = NDimensions - 1; j > 0; j--) {
      if (indices[j] == 0) {
        indices[j - 1] = (indices[j - 1] + 1) % shape[j - 1];
      } else {
        break;
      }
    }
  }

  Matrix<DType, NDimensions> output{NDimensions, output_shape, size, result};

  return output;
}
}  // namespace trinity

#endif  // TRINITY_TRANSPOSE_H
