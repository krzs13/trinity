#pragma once
#ifndef TRINITY_NDARRAY_H
#define TRINITY_NDARRAY_H

#include <assert.h>

using std::copy;
using std::initializer_list;

template <typename DType, size_t NDimensions>
class NDArray {
  static_assert(NDimensions > 0,
                "At least one dimension needs to be declared.");

 public:
  NDArray()
      : n_dimensions_{NDimensions}, shape_{nullptr}, size_{}, data_{nullptr} {}

  NDArray(initializer_list<size_t> shape)
      : n_dimensions_{NDimensions},
        shape_{new size_t[NDimensions]{}},
        size_{},
        data_{nullptr} {
    copy(shape.begin(), shape.end(), shape_);
    size_ = calculate_size_();
  }

  NDArray(size_t n_dimensions, size_t* shape, size_t size, DType* data)
      : n_dimensions_{n_dimensions}, size_{size} {
    shape_ = new size_t[n_dimensions_]{};
    copy(shape, shape + n_dimensions_, shape_);

    data_ = data;
  }

  NDArray(const NDArray& ndarray_other) {
    n_dimensions_ = ndarray_other.n_dimensions_;
    shape_ = new size_t[n_dimensions_]{};
    copy(ndarray_other.shape_, ndarray_other.shape_ + n_dimensions_, shape_);

    size_ = ndarray_other.size_;
    data_ = new DType[ndarray_other.size_]{};
    copy(ndarray_other.data_, ndarray_other.data_ + size_, data_);
  }

  NDArray(NDArray&& ndarray_other) {
    n_dimensions_ = ndarray_other.n_dimensions_;
    shape_ = ndarray_other.shape_;
    size_ = ndarray_other.size_;
    data_ = ndarray_other.data_;

    ndarray_other.n_dimensions_ = 0;
    ndarray_other.shape_ = nullptr;
    ndarray_other.size_ = 0;
    ndarray_other.data_ = nullptr;
  }

  NDArray& operator=(const NDArray& ndarray_other) {
    n_dimensions_ = ndarray_other.n_dimensions_;
    delete[] shape_;
    shape_ = new size_t[n_dimensions_]{};
    copy(ndarray_other.shape_, ndarray_other.shape_ + n_dimensions_, shape_);

    size_ = ndarray_other.size_;
    delete[] data_;
    data_ = new DType[size_]{};
    copy(ndarray_other.data_, ndarray_other.data_ + size_, data_);

    return *this;
  }

  NDArray& operator=(NDArray&& ndarray_other) {
    n_dimensions_ = ndarray_other.n_dimensions_;
    delete[] shape_;
    shape_ = ndarray_other.shape_;

    size_ = ndarray_other.size_;
    delete[] data_;
    data_ = ndarray_other.data_;

    ndarray_other.n_dimensions_ = 0;
    ndarray_other.shape_ = nullptr;
    ndarray_other.size_ = 0;
    ndarray_other.data_ = nullptr;

    return *this;
  }

  ~NDArray() {
    delete[] shape_;
    delete[] data_;
  }

  size_t n_dimensions() const { return n_dimensions_; }

  size_t* shape() const { return shape_; }

  size_t size() const { return size_; }

  DType* data() const { return data_; }

  void insert(initializer_list<DType> data) {
    assert((data.size() <= size_) && "Data contains too many elements.");

    data_ = new DType[size_]{};
    copy(data.begin(), data.end(), data_);
  }

  bool compare_shape(const NDArray<DType, NDimensions>& ndarray_other) const {
    for (size_t i = 0; i < n_dimensions_; i++) {
      if (shape_[i] != ndarray_other.shape_[i]) {
        return false;
      }
    }

    return true;
  }

  DType find(initializer_list<size_t> indices) const {
    assert((indices.size() == n_dimensions_) && "Wrong number of indices.");

    size_t indices_array[n_dimensions_];
    copy(indices.begin(), indices.end(), indices_array);

    for (size_t i = 0; i < n_dimensions_; i++) {
      assert((indices_array[i] < shape_[i]) && "Index out of range.");
    }

    size_t index{calculate_index_(indices_array, size_, n_dimensions_)};

    return data_[index];
  }

  // size_t calculate_index(initializer_list<size_t> indices) const {
  //   assert((indices.size() == n_dimensions_) && "Wrong number of indices.");

  //   size_t indices_array[n_dimensions_];
  //   copy(indices.begin(), indices.end(), indices_array);

  //   size_t index{index_math_(indices_array, size_, n_dimensions_)};
  //   assert((index < size_) && "Index out of range.");

  //   return index;
  // }

 protected:
  size_t n_dimensions_;
  size_t* shape_;
  size_t size_;
  DType* data_;

 private:
  size_t calculate_size_() const {
    size_t result{shape_[0]};

    if (n_dimensions_ > 1) {
      for (size_t i = 1; i < n_dimensions_; i++) {
        result *= shape_[i];
      }
    }

    return result;
  }

  size_t calculate_index_(size_t* indices, size_t size, size_t n) const {
    size_t index{n_dimensions_ - n};
    size_t current_size{size / shape_[index]};

    if (current_size > 1) {
      return indices[index] * current_size +
             calculate_index_(indices, current_size, n - 1);
    }

    return indices[index];
  }
};

#endif  // TRINITY_NDARRAY_H
