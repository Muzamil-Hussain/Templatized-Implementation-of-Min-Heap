template<typename T, typename U>
class minHeap {
private:
	int heapSize;
	T *data;
	U *names;
	int currentSize;
public:
	//constructor
	minHeap(int capacity) {
		heapSize = capacity + 1;
		data = new T[capacity + 1];
		names = new U[capacity + 1];
		currentSize = 1;
	}
	// function to if the heap is empty or not
	bool isEmpty() {
		if (currentSize == 1)
			return true;
		return false;
	}
	// return parent 
	int getParent(int index) {
		return floor(static_cast<double>(index / 2));
	}
	// returns right child 
	int getRightChild(int index) {
		return (2 * index) + 1;
	}
	// returns left child
	int getLeftChild(int index) {
		return 2 * index;
	}
	// inserts key while following the rules of insertion if the min heap
	void insertKey(T key, U city) {
		data[currentSize] = key;
		names[currentSize] = city;
		currentSize++;

		int i = currentSize - 1;
		while (i != 1 && data[getParent(i)] > data[i]) {
			// swapping keys
			T tempData = data[i];
			data[i] = data[getParent(i)];
			data[getParent(i)] = tempData;

			//swapping names wrt to keys
			U tempName = names[i];
			names[i] = names[getParent(i)];
			names[getParent(i)] = tempName;

			i = getParent(i);
		}
	}
	// function to assist the main function used for deletion of min value
	void deleteMinInnerProcess(int minIndex) {

		int left = getLeftChild(minIndex);
		int right = getRightChild(minIndex);
		int smallestValue = minIndex;

		if (left < currentSize && data[left] < data[minIndex]) {
			smallestValue = left;
		}
		if (right < currentSize && data[right] < data[smallestValue]) {
			smallestValue = right;
		}
		if (smallestValue != minIndex) {
			T tempData = data[minIndex];
			data[minIndex] = data[smallestValue];
			data[smallestValue] = tempData;

			U tempName = names[minIndex];
			names[minIndex] = names[smallestValue];
			names[smallestValue] = tempName;

			deleteMinInnerProcess(smallestValue);
		}
	}
	// function to delete the min value
	U deleteMin(T &minValue) {
		if (currentSize != 1) {
			if (currentSize == 2) {
				currentSize--;
				minValue = data[1];
				return names[currentSize];
			} else {
				U storeReturnValue = names[1];
				minValue = data[1];
				currentSize--;
				data[1] = data[currentSize];
				names[1] = names[currentSize];
				deleteMinInnerProcess(1);
				return storeReturnValue;
			}
		} else
			cout << "\nHeap is empty!\n";
	}
	// return min value which will always be on the first index
	U getMin() {
		if (currentSize != 1) {
			return names[1];
		} else {
			cout << "Heap is Empty\n";
		}
	}
	// returns the distance of given city
	T getDistance(U cityName, int &cityIndex) {
		//searching for distance of given city
		for (int i = 1; i < currentSize; i++) {
			if (names[i].compare(cityName) == 0) {
				cityIndex = i;
				return data[i];
			}
		}
	}
	// sets the distance of given index
	void setDistance(int index, T distance) {
		data[index] = distance;
		while (index != 1 && data[getParent(index)] > data[index]) {

			T tempData = data[index];
			data[index] = data[getParent(index)];
			data[getParent(index)] = tempData;

			U tempName = names[index];
			names[index] = names[getParent(index)];
			names[getParent(index)] = tempName;

			index = getParent(index);
		}
	}
	// function for displaying min heap. Was used for testing
	void display() {
		for (int i = 1; i < currentSize; i++) {
			cout << data[i] << " " << names[i] << endl;
		}
	}
};
