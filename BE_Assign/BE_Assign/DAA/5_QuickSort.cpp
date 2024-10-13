#include <iostream>
#include <vector>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;

int comparisons = 0; // Global variable to count comparisons

// Deterministic Quick Sort
vector<int> deterministicQuickSort(const vector<int> &arr)
{
	if (arr.size() <= 1)
	{
		return arr; // Base case: an array with 0 or 1 element is already sorted
	}

	int pivot = arr[0];
	vector<int> left, right;

	for (size_t i = 1; i < arr.size(); i++)
	{
		comparisons++; // Count comparison
		if (arr[i] < pivot)
		{
			left.push_back(arr[i]); // Elements less than pivot
		}
		else
		{
			right.push_back(arr[i]); // Elements greater than or equal to pivot
		}
	}

	// Recursively sort left and right parts and concatenate with pivot
	vector<int> sorted = deterministicQuickSort(left);
	sorted.push_back(pivot);
	vector<int> rightSorted = deterministicQuickSort(right);
	sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());

	return sorted; // Return the sorted array
}

// Randomized Quick Sort
vector<int> randomizedQuickSort(const vector<int> &arr)
{
	if (arr.size() <= 1)
	{
		return arr; // Base case: an array with 0 or 1 element is already sorted
	}

	int pivotIdx = rand() % arr.size(); // Random pivot index
	int pivot = arr[pivotIdx];
	vector<int> left, right;

	for (size_t i = 0; i < arr.size(); i++)
	{
		comparisons++; // Count comparison
		if (i == pivotIdx)
		{
			continue; // Skip the pivot element
		}
		if (arr[i] < pivot)
		{
			left.push_back(arr[i]); // Elements less than pivot
		}
		else
		{
			right.push_back(arr[i]); // Elements greater than or equal to pivot
		}
	}

	// Recursively sort left and right parts and concatenate with pivot
	vector<int> sorted = randomizedQuickSort(left);
	sorted.push_back(pivot);
	vector<int> rightSorted = randomizedQuickSort(right);
	sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());

	return sorted; // Return the sorted array
}

// Function to count comparisons and return the sorted array
pair<int, vector<int>> countComparisons(const vector<int> &arr, vector<int> (*sortingAlgorithm)(const vector<int> &))
{
	comparisons = 0;							   // Reset comparisons
	vector<int> sortedArr = sortingAlgorithm(arr); // Sort the array
	return {comparisons, sortedArr};			   // Return the number of comparisons and sorted array
}

int main()
{
	srand(static_cast<unsigned>(time(0))); // Seed random number generation

	vector<int> inputList = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};

	// Count comparisons for Deterministic Quick Sort
	auto [deterministicComparisons, deterministicSorted] = countComparisons(inputList, deterministicQuickSort);
	cout << "Deterministic QuickSort:\n";
	cout << "Comparisons: " << deterministicComparisons << endl;
	cout << "Sorted Array: ";
	for (int num : deterministicSorted)
	{
		cout << num << " ";
	}
	cout << endl;

	// Count comparisons for Randomized Quick Sort
	auto [randomizedComparisons, randomizedSorted] = countComparisons(inputList, randomizedQuickSort);
	cout << "\nRandomized QuickSort:\n";
	cout << "Comparisons: " << randomizedComparisons << endl;
	cout << "Sorted Array: ";
	for (int num : randomizedSorted)
	{
		cout << num << " ";
	}
	cout << endl;

	return 0;
}
