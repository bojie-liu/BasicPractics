#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int main() {
	int val = 999;
	size_t size = 10;
	size_t position = 1;
	array<int, 6> arr = {1,2,3,4,5,6};

	vector<int> vec = {1,2,3,4,5,6};
	cout << "vector access " << vec[0] << vec.at(1) << vec.front() << vec.back() << (int*)vec.data();
	// modifiers
	vec.assign(size, val);
	vec.push_back(val);
	vec.pop_back();
	vec.insert(vec.begin(), val);
	vec.insert(vec.begin(), size, val);
	vec.insert(vec.begin(), vec.begin(), vec.end());
	vec.erase(vec.begin());
	vec.erase(vec.begin(), vec.begin()+1);
	vector<int> clean_vec;
	vec.swap(clean_vec);
	vec.clear();
	vec.emplace(vec.begin(), val);
	vec.emplace_back(val);
	// Capacity
	cout << "vector Capacity " << vec.size() << vec.max_size() << vec.capacity() << vec.empty();
	vec.resize(size);
	vec.reserve(size);
	vec.shrink_to_fit();

	deque<int> deq = {1,2,3,4,5,6};
	cout << "deque access " << deq[0] << deq.at(1) << deq.front() << vec.back();
	deq.push_front(val);
	deq.pop_front();
	deq.emplace_front(val);

	queue<int> que(deq);
	cout << "queue access " << que.back() << que.front();
	que.push(val);
	que.pop();
	que.emplace(val);
	cout << "queue Capacity " << que.size() << que.empty();


	return 1;
}