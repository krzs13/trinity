#pragma once
#ifndef TRINITY_MATRIX_H
#define TRINITY_MATRIX_H

#include "../math_operations/add.h"
#include "../math_operations/divide.h"
#include "../math_operations/dot.h"
#include "../math_operations/multiply.h"
#include "../math_operations/subtract.h"
#include "../math_operations/sum.h"

using std::copy;
using std::initializer_list;

template <typename DataType, size_t... MatrixShape>
class Matrix {
  static_assert(sizeof...(MatrixShape) > 0,
                "At least one dimension needs to be declared.");

 public:
  Matrix()
      : n_dimensions_{sizeof...(MatrixShape)},
        shape_{new size_t[n_dimensions_]{MatrixShape...}},
        size_{calculate_size_()},
        data_{nullptr} {}

  Matrix(initializer_list<DataType> data)
      : n_dimensions_{sizeof...(MatrixShape)},
        shape_{new size_t[n_dimensions_]{MatrixShape...}},
        size_{calculate_size_()},
        data_{new DataType[size_]} {
    copy(data.begin(), data.end(), data_);
  }

  Matrix(const Matrix& matrix_copy) {
    delete[] data_;
    data_ = new DataType[size_];
    copy(matrix_copy.data_, matrix_copy.data_ + size_, data_);
  }

  Matrix(Matrix&& matrix_move) {
    delete[] data_;
    data_ = matrix_move.data_;

    matrix_move.n_dimensions_ = 0;
    matrix_move.shape_ = nullptr;
    matrix_move.size_ = 0;
    matrix_move.data_ = nullptr;
  }

  ~Matrix() {
    delete[] shape_;
    delete[] data_;
  }

  Matrix& operator=(const Matrix& matrix_copy) {
    delete[] data_;
    data_ = new DataType[size_];
    copy(matrix_copy.data_, matrix_copy.data_ + size_, data_);

    return *this;
  }

  Matrix& operator=(Matrix&& matrix_move) {
    delete[] data_;
    data_ = matrix_move.data_;

    matrix_move.n_dimensions_ = 0;
    matrix_move.shape_ = nullptr;
    matrix_move.size_ = 0;
    matrix_move.data_ = nullptr;

    return *this;
  }

  size_t n_dimensions() const { return n_dimensions_; }

  size_t* shape() const { return shape_; }

  size_t size() const { return size_; }

  void get_data() {
    for (size_t i = 0; i < size_; i++) {
      std::cout << data_[i] << ' ';
    }

    std::cout << '\n';
  }

 private:
  size_t n_dimensions_;
  size_t* shape_;
  size_t size_;
  DataType* data_;

  size_t calculate_size_() {
    size_t result{shape_[0]};

    if (n_dimensions_ > 1) {
      for (size_t i = 1; i < n_dimensions_; i++) {
        result *= shape_[i];
      }
    }

    return result;
  }
};

#endif  // TRINITY_MATRIX_H
