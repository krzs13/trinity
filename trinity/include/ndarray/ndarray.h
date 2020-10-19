#pragma once
#ifndef TRINITY_NDARRAY_H
#define TRINITY_NDARRAY_H

using std::copy;
using std::initializer_list;

template <typename DType, size_t... NShape>
class NDArray {
  static_assert(sizeof...(NShape) > 0,
                "At least one dimension needs to be declared.");

 public:
  NDArray()
      : n_dimensions_{sizeof...(NShape)},
        shape_{new size_t[n_dimensions_]{NShape...}},
        size_{calculate_size_()},
        data_{nullptr} {}

  NDArray(initializer_list<DType> data)
      : n_dimensions_{sizeof...(NShape)},
        shape_{new size_t[n_dimensions_]{NShape...}},
        size_{calculate_size_()},
        data_{new DType[size_]} {
    copy(data.begin(), data.end(), data_);
  }

  NDArray(size_t n_dimensions, size_t* shape, size_t size, DType* data)
      : n_dimensions_{n_dimensions}, size_{size} {
    shape_ = new size_t[n_dimensions_];
    copy(shape, shape + n_dimensions_, shape_);

    data_ = new DType[size_];
    copy(data, data + size_, data_);
  }

  NDArray(const NDArray& ndarray_copy) {
    n_dimensions_ = ndarray_copy.n_dimensions_;
    shape_ = new size_t[n_dimensions_];
    copy(ndarray_copy.shape_, ndarray_copy.shape_ + n_dimensions_, shape_);

    size_ = ndarray_copy.size_;
    data_ = new DType[ndarray_copy.size_];
    copy(ndarray_copy.data_, ndarray_copy.data_ + size_, data_);
  }

  NDArray(NDArray&& ndarray_move) {
    n_dimensions_ = ndarray_move.n_dimensions_;
    shape_ = ndarray_move.shape_;
    size_ = ndarray_move.size_;
    data_ = ndarray_move.data_;

    ndarray_move.n_dimensions_ = 0;
    ndarray_move.shape_ = nullptr;
    ndarray_move.size_ = 0;
    ndarray_move.data_ = nullptr;
  }

  NDArray& operator=(const NDArray& ndarray_copy) {
    n_dimensions_ = ndarray_copy.n_dimensions_;
    delete[] shape_;
    shape_ = new size_t[n_dimensions_];
    copy(ndarray_copy.shape_, ndarray_copy.shape_ + n_dimensions_, shape_);

    size_ = ndarray_copy.size_;
    delete[] data_;
    data_ = new DType[size_];
    copy(ndarray_copy.data_, ndarray_copy.data_ + size_, data_);

    return *this;
  }

  NDArray& operator=(NDArray&& ndarray_move) {
    n_dimensions_ = ndarray_move.n_dimensions_;
    delete[] shape_;
    shape_ = ndarray_move.shape_;

    size_ = ndarray_move.size_;
    delete[] data_;
    data_ = ndarray_move.data_;

    ndarray_move.n_dimensions_ = 0;
    ndarray_move.shape_ = nullptr;
    ndarray_move.size_ = 0;
    ndarray_move.data_ = nullptr;

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

 protected:
  size_t n_dimensions_;
  size_t* shape_;
  size_t size_;
  DType* data_;

 private:
  size_t calculate_size_() {
    size_t result{shape_[0]};

    if (n_dimensions_ > 1) {
      for (size_t i = 1; i < n_dimensions_; i++) {
        result *= shape_[i];
      }
    }

    return result;
  }

  size_t index_math_(size_t* indices, size_t size, size_t n) {
    size_t index{n_dimensions_ - n};
    size_t current_size{size / shape_[index]};

    if (current_size > 1) {
      return indices[index] * current_size +
             index_math_(indices, current_size, n - 1);
    }

    return indices[index];
  }
};

#endif  // TRINITY_NDARRAY_H
