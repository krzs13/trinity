#pragma once
#ifndef TRINITY_INITIALIZER_H
#define TRINITY_INITIALIZER_H

#include <random>

#include "../ndarray/matrix.h"

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;
using std::uniform_real_distribution;

namespace trinity {
namespace internal {
template <typename DType, size_t NDimensions>
Matrix<DType, NDimensions> initializer(
    const Matrix<DType, NDimensions>& matrix_input, DType initial_value) {
  DType* result{new DType[matrix_input.size()]{initial_value}};

  Matrix<DType, NDimensions> output{NDimensions, matrix_input.shape(),
                                    matrix_input.size(), result};

  return output;
}

template <size_t NDimensions>
Matrix<int, NDimensions> random_initializer(
    const Matrix<int, NDimensions>& matrix_input, int minimum, int maximum) {
  random_device seed{};
  mt19937 engine{seed()};
  uniform_int_distribution<> distribution{minimum, maximum};

  int* result{new int[matrix_input.size()]{}};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result[i] = distribution(engine);
  }

  Matrix<int, NDimensions> output{NDimensions, matrix_input.shape(),
                                  matrix_input.size(), result};

  return output;
}

template <size_t NDimensions>
Matrix<double, NDimensions> random_initializer(
    const Matrix<double, NDimensions>& matrix_input, double minimum,
    double maximum) {
  random_device seed{};
  mt19937 engine{seed()};
  uniform_real_distribution<> distribution{minimum, maximum};

  double* result{new double[matrix_input.size()]{}};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result[i] = distribution(engine);
  }

  Matrix<double, NDimensions> output{NDimensions, matrix_input.shape(),
                                     matrix_input.size(), result};

  return output;
}

template <size_t NDimensions>
Matrix<double, NDimensions> random_initializer(
    const Matrix<double, NDimensions>& matrix_input) {
  random_device seed{};
  mt19937 engine{seed()};
  uniform_real_distribution<> distribution{0, 1};

  double* result{new double[matrix_input.size()]{}};

  for (size_t i = 0; i < matrix_input.size(); i++) {
    result[i] = distribution(engine);
  }

  Matrix<double, NDimensions> output{NDimensions, matrix_input.shape(),
                                     matrix_input.size(), result};

  return output;
}
}  // namespace internal
}  // namespace trinity

#endif  // TRINITY_INITIALIZER_H
