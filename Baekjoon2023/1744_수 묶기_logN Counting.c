#include <stdio.h>
int binary_least_greater(const int arr[], int size, int key) {
	int pos = -1, left = 0, mid;
	size = size - 1;
	while (left <= size) {
		mid = left + (size - left) / 2;
		if (arr[mid] <= key) left = mid + 1;
		else {
			pos = mid;
			size = mid - 1;
		}
	}
	return pos;
}
int binary_first(const int arr[], int size, int key) {
	int pos = -1, left = 0, mid;
	size = size - 1;
	while (left <= size) {
		mid = left + (size - left) / 2;
		if (arr[mid] == key) {
			pos = mid;
			size = mid - 1;
		}
		else if (arr[mid] < key) left = mid + 1;
		else size = mid - 1;
	}
	return pos;
}
void _MergeSort_impl(int* list, int* sorted, const int left, const int right) {
	if (left >= right) return;
	const int mid = left + (right - left) / 2;
	_MergeSort_impl(list, sorted, left, mid);
	_MergeSort_impl(list, sorted, mid + 1, right);
	int idx, first, second;
	idx = left, first = left, second = mid + 1;
	while (first <= mid && second <= right) {
		if (list[first] <= list[second]) sorted[idx++] = list[first++];
		else sorted[idx++] = list[second++];
	}
	while (first <= mid)    sorted[idx++] = list[first++];
	while (second <= right) sorted[idx++] = list[second++];
	for (int i = left; i <= right; i++) list[i] = sorted[i];
}
void MergeSort(int* list, int size) {
	static int sorted[50];
	_MergeSort_impl(list, sorted, 0, size - 1);
}
void solve1744(int arr[], int N) {
	int positive_idx, zero_idx, one_greater_idx, answer;
	int count_n, count_z, count_p, count_1;
	MergeSort(arr, N);
	if ((positive_idx = binary_least_greater(arr, N, 0)) == -1) positive_idx = N;
	if ((zero_idx = binary_first(arr, N, 0)) == -1) zero_idx = positive_idx;
	if ((one_greater_idx = binary_least_greater(arr, N, 1)) == -1) one_greater_idx = N;
	// if ((zero_idx = binary_least_greater(arr, N, -1)) == -1) zero_idx = positive_idx; // Replacement
	count_n = zero_idx;
	count_z = positive_idx - zero_idx;
	count_p = N - positive_idx;
	count_1 = one_greater_idx - positive_idx;
	answer = count_1;
	if (count_n % 2) {
		if (count_z == 0) answer += arr[zero_idx - 1];
		for (int i = 0; i < zero_idx - 1; i += 2) {
			answer += arr[i] * arr[i + 1];
		}
	}
	else {
		for (int i = 0; i < zero_idx; i += 2) {
			answer += arr[i] * arr[i + 1];
		}
	}
	if ((count_p - count_1) % 2) {
		answer += arr[one_greater_idx];
		for (int i = one_greater_idx + 1; i < N; i += 2) {
			answer += arr[i] * arr[i + 1];
		}
	}
	else {
		for (int i = one_greater_idx; i < N; i += 2) {
			answer += arr[i] * arr[i + 1];
		}
	}
	printf("%d\n", answer);
}
int main() {
    static int arr[50];
    int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) { scanf("%d", &arr[i]); }
	solve1744(arr, N);
}