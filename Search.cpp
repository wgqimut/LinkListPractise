//
// Created by Grady on 2016/12/31.
//

int search (int arr[], int length, int v) {
	int low = 0;
	int high = length - 1;

	while (low <= high) {
		int mid = (high + low) / 2;
		if (v > arr[mid]) {
			low = mid;
		} else if (v < arr[mid]){
			high = mid;
		} else {
			return mid;
		}
	}

	return -1;
}