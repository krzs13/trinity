#pragma once
#ifndef TRINITY_TRANSPOSE_H
#define TRINITY_TRANSPOSE_H

#include "../ndarray/matrix.h"

template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> transpose(
    const Matrix<DType, NDimensions>& matrix_input) {
  assert((NDimensions == 2) &&
         "Transposition implemented only for 2D matrices.");

  size_t rows{matrix_input.shape()[matrix_input.size() - 2]};
  size_t columns{matrix_input.shape()[matrix_input.size() - 1]};

  size_t* output_shape{new size_t[2]{columns, rows}};
  DType* result{new DType[matrix_input.size()]{}};

  for (size_t row = 0; row < rows; row++) {
    for (size_t col = 0; col < columns; col++) {
      result[row * columns + col] = matrix_input.data()[col * rows + row];
    }
  }

  Matrix<DType, NDimensions> output{NDimensions, output_shape,
                                    matrix_input.size(), result};

  return output;
}

#endif  // TRINITY_TRANSPOSE_H
