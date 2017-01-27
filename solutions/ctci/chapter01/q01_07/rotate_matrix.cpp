#include "rotate_matrix.h"

namespace ctci{
void rotate(int matrix[][ROTATE_MAX], size_t n){
	for (size_t low = 0, high = n - 1; low < high; ++low, --high){
		for (size_t i = 0; low + i < high; ++i){
			auto temp = matrix[low][low + i];
			matrix[low][low + i] = matrix[high - i][low];
			matrix[high - i][low] = matrix[high][high - i];
			matrix[high][high - i] = matrix[low + i][high];
			matrix[low + i][high] = temp;
		}
	}
}
} // namespace ctci