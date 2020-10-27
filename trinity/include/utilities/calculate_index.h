#pragma once
#ifndef TRINITY_CALCULATE_INDEX_H
#define TRINITY_CALCULATE_INDEX_H

namespace trinity {
size_t calculate_index(size_t* indices, size_t* shape, size_t size,
                       size_t n_dimensions, size_t n) {
  size_t index{n_dimensions - n};
  size_t current_size{size / shape[index]};

  if (current_size > 1) {
    return indices[index] * current_size +
           calculate_index(indices, shape, current_size, n_dimensions, n - 1);
  }

  return indices[index];
}
}  // namespace trinity

#endif  // TRINITY_CALCULATE_INDEX_H
