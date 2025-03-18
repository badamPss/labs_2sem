#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <chrono>
#include <random>

void threadFunction(const std::string& threadName, std::vector<double>& arr, int start, int end) {
	for (int i = start; i < end - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < end; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		std::swap(arr[i], arr[minIndex]);
	}

	for (int i = start; i < end; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << threadName << ": " << arr[i] << std::endl;
	}
}

int main() {
	std::vector<double> arr(10);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> dis(1.0, 100.0);

	for (double& num : arr) {
		num = dis(gen);
	}

	int mid = arr.size() / 2;

	std::thread t1(threadFunction, "thread1", std::ref(arr), 0, mid);
	std::thread t2(threadFunction, "thread2", std::ref(arr), mid, arr.size());

	t1.join();
	t2.join();

	std::thread t3(threadFunction, "thread3", std::ref(arr), 0, arr.size());
	t3.join();

	std::cout << "все потоки завершили работу" << std::endl;

	return 0;
}