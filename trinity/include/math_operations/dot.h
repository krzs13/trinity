#pragma once
#ifndef TRINITY_DOT_H
#define TRINITY_DOT_H

#include "../ndarray/matrix.h"

template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> dot(const Matrix<DType, NDimensions>& matrix_1,
                               const Matrix<DType, NDimensions>& matrix_2) {
  assert((NDimensions == 2) && "Dot product implemented only for 2D matrices.");

  size_t matrix_1_rows{matrix_1.shape()[matrix_1.n_dimensions() - 2]};
  size_t matrix_1_columns{matrix_1.shape()[matrix_1.n_dimensions() - 1]};
  size_t matrix_2_rows{matrix_2.shape()[matrix_2.n_dimensions() - 2]};
  size_t matrix_2_columns{matrix_2.shape()[matrix_2.n_dimensions() - 1]};

  assert((matrix_1_columns == matrix_2_rows) &&
         "Dot product not possible. The number of columns in first matrix is "
         "not equal to the number of rows in second matrix.");

  size_t* output_shape{new size_t[2]{matrix_1_rows, matrix_2_columns}};
  size_t output_size{output_shape[0] * output_shape[1]};
  DType* result{new DType[output_size]{}};

  for (size_t row = 0; row < output_shape[0]; row++) {
    for (size_t col = 0; col < output_shape[1]; col++) {
      size_t index{row * matrix_2_columns + col};

      for (size_t i = 0; i < matrix_1_columns; i++) {
        result[index] += matrix_1.find({row, i}) * matrix_2.find({i, col});
      }
    }
  }

  Matrix<DType, NDimensions> output{NDimensions, output_shape, output_size,
                                    result};

  return output;
}

#endif  // TRINITY_DOT_H
