#ifndef ZERO_MATRIX_H
#define ZERO_MATRIX_H

#include <iostream>
namespace ctci{
namespace{
template<size_t M, size_t N>
void set_row_zeros(int(&matrix)[M][N], size_t row){
	for (size_t i = 0; i < N; ++i){
		matrix[row][i] = 0;
	}
}

template<size_t M, size_t N>
void set_col_zeros(int(&matrix)[M][N], size_t col){
	for (size_t i = 0; i < M; ++i){
		matrix[i][col] = 0;
	}
}
} // namespace

template < size_t M, size_t N >
void set_zeros(int(&matrix)[M][N]){
	bool zero_rows[M] = {};
	bool zero_cols[N] = {};

	for (size_t i = 0; i < M; ++i){
		for (size_t j = 0; j < N; ++j){
			if (0 == matrix[i][j]){
				zero_rows[i] = true;
				zero_cols[j] = true;
			}
		}
	}

	for (size_t i = 0; i < M; ++i){
		if (zero_rows[i]){
			set_row_zeros(matrix, i);
		}
	}

	for (size_t i = 0; i < N; ++i){
		if (zero_cols[i]){
			set_col_zeros(matrix, i);
		}
	}
}

template < size_t M, size_t N >
void set_zeros_2(int(&matrix)[M][N]){
	bool zero_row = false;
	bool zero_col = false;

	for (size_t j = 0; j < N; ++j){
		if (0 == matrix[0][j]){
			zero_row = true;
			break;
		}
	}

	for (size_t i = 0; i < M; ++i){
		if (0 == matrix[i][0]){
			zero_col = true;
			break;
		}
	}

	for (size_t i = 1; i < M; ++i){
		for (size_t j = 1; j < N; ++j){
			if (0 == matrix[i][j]){
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	for (size_t i = 1; i < M; ++i){
		if (0 == matrix[i][0]){
			set_row_zeros(matrix, i);
		}
	}

	for (size_t j = 1; j < N; ++j){
		if (0 == matrix[0][j]){
			set_col_zeros(matrix, j);
		}
	}

	if (zero_row){
		set_row_zeros(matrix, 0);
	}

	if (zero_col){
		set_col_zeros(matrix, 0);
	}
}
} // namespace ctci

#endif // !ZERO_MATRIX_H
