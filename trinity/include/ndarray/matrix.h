#pragma once
#ifndef TRINITY_MATRIX_H
#define TRINITY_MATRIX_H

#include "../math_operations/add.h"
#include "../math_operations/divide.h"
#include "../math_operations/dot.h"
#include "../math_operations/multiply.h"
#include "../math_operations/subtract.h"
#include "../math_operations/sum.h"
#include "../ndarray/ndarray.h"

using std::copy;
using std::initializer_list;

template <typename Dtype, size_t... NShape>
class Matrix : public NDArray<Dtype, NShape...> {
 public:
  Matrix() : NDArray<Dtype, NShape...>() {}

  Matrix(initializer_list<Dtype> data) : NDArray<Dtype, NShape...>(data) {}

  Matrix(const Matrix& matrix_copy) : NDArray<Dtype, NShape...>(matrix_copy) {}

  Matrix(Matrix&& matrix_move) : NDArray<Dtype, NShape...>(matrix_move) {}

  ~Matrix() {}

  Matrix& operator=(const Matrix& matrix_copy) {
    NDArray<Dtype, NShape...>::operator=(matrix_copy);

    return *this;
  }

  Matrix& operator=(Matrix&& matrix_move) {
    NDArray<Dtype, NShape...>::operator=(matrix_move);

    return *this;
  }
};

#endif  // TRINITY_MATRIX_H
