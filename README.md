# trinity

Simple header only, template based library for linear algebra. Includes operations such as:
* Elementwise addition
* Elementwise subtraction
* Elementwise multiplication
* Elementwise division
* Matrix multiplication (dot product)
* Matrix transposition
* Sum of all matrix elements
* Matrix initializers with zeros, ones and random numbers

## Matrix

### Constructors
* Default: Matrix<DType, NDimensions> matrix{} 
* Construct with shape initializer list: Matrix<DType, NDimensions> matrix{shape}
* Copying constructor: available
* Move constructor: available

### Assigments
* Copying assigment: available
* Move assigment: available

### Comparision

* A == B
* A != B

### Data input

Inserting data is done through the initializer list.

* A.insert({data})

### Access to a specific item

Indexing is done through the initializer list.

* A.find({indices})

## Elementwise operations

Implemented for ND matrices.

### Add
* add(A, B)
* A + B
* A += B

### Subtract
* subtract(A, B)
* A - B
* A -= B

### Multiply
* multiply(A, B)
* A * B
* A *= B

### Divide
* divide(A, B)
* A / B
* A /= B

### Dot product

Implemented only for 2D matrices.

* dot(A, B)
* A & B
* A &= B

### Transposition

Implemented only for 2D matrices.

* A.T()

### Sum
Sum of all elements from matrix.

* sum(A)

## Initializers

### Zeros

* A = zeros_like(B)
* A.zeros()

### Ones
* A = ones_like(B)
* A.ones()

### Random
* A = random_like(B) - 0 to 1 range for double values, -2147483648 to 2147483647 for int values
* A.random() - 0 to 1 range for double values, -2147483648 to 2147483647 for int values
* A.random(minumum, maximum)
