# Big Number Arithmetic Library

This C++ program implements arbitrary-precision arithmetic operations (addition, subtraction, multiplication) for very large integers that exceed native data type limits.

## Features

- **Arbitrary-precision arithmetic**: Handles numbers of virtually any size
- **Full operation support**:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
- **Sign handling**: Properly processes negative numbers
- **Input validation**: Ensures correct number format
- **Clean output**: Formats results with proper sign and without leading zeros

## Implementation Details

### Core Components

1. **`Res` Class**:
   - Stores calculation results (digits vector and sign)
   - Provides accessor methods `get()` and `getSign()`
   - Includes `foo()` method for sign flipping

2. **Arithmetic Operations**:
   - `Big_number_add()`: Handles signed addition
   - `Big_number_subtraction()`: Handles signed subtraction
   - `Big_number_multipy()`: Handles signed multiplication
   - (Note: Division is partially implemented but not completed)

3. **Helper Functions**:
   - Operator overloads for clean output (`<<`)
   - Input parsing and validation
   - Result formatting

### Algorithm Overview

- **Number Representation**:
  - Numbers stored as vectors of digits (0-9)
  - Least significant digit at higher indices (big-endian)
  - Separate sign flag for negative numbers

- **Addition**:
  - Digit-by-digit addition with carry propagation
  - Handles numbers of different lengths
  - Properly manages sign combinations

- **Subtraction**:
  - Implements borrowing algorithm
  - Handles all sign cases through addition delegation
  - Compares magnitudes for smaller-larger cases

- **Multiplication**:
  - Uses grade-school multiplication algorithm
  - Handles carries during multiplication
  - Properly calculates result sign

## Usage

### Input Requirements

- Numbers must be entered as:
  - Optional leading '-' for negative numbers
  - Digits 0-9 (must start with 1-9 unless single 0)
  - No other characters allowed
## Limitations

### Unimplemented Features
- **Division Operation**: Partially implemented but not functional
- **Missing Operations**:
  - Modulo operation
  - Bitwise operations (AND, OR, XOR, etc.)
  - Power/Exponentiation
  - GCD/LCM calculations

### Performance Considerations
- **Multiplication**: Uses basic O(n²) grade-school algorithm
- **Memory Usage**: Stores all digits explicitly (no compression)

### Input Constraints
- **Format Restrictions**:
  - No whitespace allowed within numbers
  - No scientific notation (e.g., 1e100)
  - No decimal points or fractional numbers
- **Validation Rules**:
  - Must start with '-' or digit 1-9 (except single 0)
  - Subsequent digits must be 0-9
  - No other characters permitted


## Future Improvements Roadmap

### Planned Operations
| Operation       | Priority | Notes                          |
|-----------------|----------|--------------------------------|
| Full Division   | High     | Complete partial implementation|
| Modulo          | Medium   | Dependent on division          |
| Exponentiation  | High     | Important for crypto uses      |
| Bitwise Ops     | Low      | AND, OR, XOR, shifts           |
| GCD/LCM         | Medium   | Number theory applications     |


### Enhanced Features
- **Number Support**:
  ```diff
  + Add decimal/fractional support
  + Add scientific notation parsing
