#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
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

	auto future1 = std::async(std::launch::async, threadFunction, "thread1", std::ref(arr), 0, mid);
	auto future2 = std::async(std::launch::async, threadFunction, "thread2", std::ref(arr), mid, arr.size());

	future1.wait();
	future2.wait();

	auto future3 = std::async(std::launch::async, threadFunction, "thread3", std::ref(arr), 0, arr.size());
	future3.wait();

	std::cout << "все потоки завершили работу" << std::endl;

	return 0;
}