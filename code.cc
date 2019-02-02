#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#include <algorithm>

using namespace std;

int main() {
	int val = 999;
	int spec_val = 8;
	size_t size = 10;
	size_t position = 1;
	array<int, 6> arr = {1,2,3,4,5,6};
	cout << "Arrays element " << arr.at(0) << arr[0] << arr.front() << arr.back() << (int*)arr.data();
	arr.fill(1);
	// Capacity
	cout << "Arrays capacity " << arr.size() << arr.max_size() << arr.empty();

	vector<int> vec = {1,2,3,4,5,6};
	cout << "vector access " << vec[0] << vec.at(1) << vec.front() << vec.back() << (int*)vec.data();
	// modifiers
	vec.assign(size, val);
	vec.assign({1,2,3,4});
	vec.push_back(val);
	vec.pop_back();
	vec.insert(vec.begin(), val);
	vec.insert(vec.begin(), size, val);
	vec.insert(vec.begin(), vec.begin(), vec.end());
	vec.insert(vec.begin(), {1,2,3});
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

	list<int> lst(size, val);
	int arr_int[] = {1,2,3,4,5,6};
	list<int> lst_int(arr_int, arr_int + sizeof(arr_int)/sizeof(int));
	cout << "list access " << lst.back() << lst.front();
	// modifiers
	list<int> clean_lst;
	lst.assign(size, val);
	lst.assign(clean_lst.begin(), clean_lst.end());
	lst.assign({1,2,3,4});
	lst.emplace(lst.begin(), val);
	lst.emplace_front(val);
	lst.emplace_back(val);
	lst.push_front(val);
	lst.pop_front();
	lst.push_back(val);
	lst.pop_back();
	lst.insert(lst.begin(), size, val);
	lst.insert(lst.begin(), val);
	lst.insert(lst.begin(), clean_lst.begin(), clean_lst.end());
	lst.insert(lst.begin(), {1,2,3});
	lst.erase(lst.begin());
	lst.erase(lst.begin(), lst.end());
	lst.swap(clean_lst);
	lst.resize(size);
	lst.clear();

	// Operations
	lst.splice(lst.begin(), clean_lst);
	clean_lst.push_front(val);
	lst.splice(lst.begin(), clean_lst, clean_lst.begin());
	clean_lst.push_front(val);
	lst.splice(lst.begin(), clean_lst, clean_lst.begin(), clean_lst.end());
	lst.remove(val);
	lst.remove_if([val](const int& in_val) -> bool { return in_val != val;} );
	lst.push_front(val);
	lst.push_front(spec_val);
	lst.push_front(val);
	lst.unique();
	for_each(lst.begin(), lst.end(), [](int i) { cout << i << " ";});
	lst.unique([val, spec_val](int i, int j) { return i == val && j == spec_val;});
	for_each(lst.begin(), lst.end(), [](int i) { cout << i << " ";});
	lst.merge(clean_lst, [](int first, int second) {return first < second;});
	lst.sort();
	lst.sort([](int first, int second) {return first < second;});
	lst.reverse();

	// Capacity
	cout << lst.size() << lst.max_size() << lst.empty();

	forward_list<int> flist(size, val);
	forward_list<int> clean_flist(size, val);
	// Accessor
	cout << "forward_list access " << flist.front();
	flist.emplace_front(val);
	flist.push_front(val);
	flist.pop_front();
	flist.emplace_after(flist.begin(), val);
	flist.insert_after(flist.begin(), val);
	flist.insert_after(flist.begin(), size, val);
	flist.insert_after(flist.begin(), {1,2,3});
	flist.insert_after(flist.begin(), {1,2,3});
	flist.erase_after(flist.begin());

	// Operations
	flist.splice_after(flist.begin(), clean_flist);
	clean_flist.push_front(val);
	flist.splice_after(flist.begin(), clean_flist, clean_flist.begin());
	clean_flist.push_front(val);
	flist.splice_after(flist.begin(), clean_flist, clean_flist.begin(), clean_flist.end());
	clean_flist.push_front(val);
	flist.remove(val);
	flist.remove_if([val](int i) { return val == i;} );
	flist.unique();
	flist.merge(clean_flist);
	flist.sort();
	flist.reverse();

	map<string, int> m, clean_map;
	// Accessor
	m["a"] = val;
	m["b"] = spec_val;
	cout << "map access " << m.at("b");
	pair<map<string, int>::iterator, bool> ret;
	map<string, int>::iterator iter;
	ret = m.insert(pair<string, int>("c", 100));
	iter = m.insert(m.begin(), pair<string, int>("d", 200));
	clean_map.insert(m.begin(), m.find("a"));
	clean_map.insert({{"a", 200}});
	m.erase(m.begin());
	m.erase("a");
	m.erase(m.begin(), m.end());
	m.swap(clean_map);
	m.clear();
	ret = m.emplace("e", 300); // Insert if needed.
	iter = m.emplace_hint(m.begin(), "f", 400);

	// Observer
	map<string, int>::key_compare kc = m.key_comp();
	map<string, int>::value_compare vc = m.value_comp();
	cout << kc("a", "b");

	iter = m.find("a");
	bool count = (bool)m.count("a"); // return 0 or 1
	iter = m.lower_bound("b"); // b
	iter = m.upper_bound("b"); // c
	m.clear();
	m.emplace("a", 100);
	m.emplace("g", 200);
	pair<map<string, int>::iterator, map<string, int>::iterator> range = m.equal_range("a");
	cout << range.first->first;

	// Capacity
	m.empty();
	m.size();
	m.max_size();

	unordered_map<string, int> umap({{"a", 100}, {"b", 200}});
	unordered_map<string, int> clean_umap;
	unordered_map<string, int>::iterator umap_iter;
	// Accessor
	umap["c"] = 300;
	umap.at("a") = 100;

	// Modifiers
	umap.emplace("a", 300); // Insert if needed.
	umap.insert(pair<string, int>("a", 300));
	umap.insert(umap.begin(), {"a", 400});
	umap.erase("a");
	umap.erase(umap.begin());
	for_each(umap.begin(), umap.end(), [](pair<string, int> val) { cout << val.first << " " << val.second;});

	// Bucket
	count = umap.bucket_count();
	count = umap.max_bucket_count();
	count = umap.bucket_size(1);
	count = umap.bucket("a"); // the number of a
	// TODO: Hash

	// Observer
	umap_iter = umap.find("a");
	count = umap.count("a");
	pair<unordered_map<string, int>::iterator, unordered_map<string, int>::iterator> umap_range = umap.equal_range("a");


	stack<int> stack_;
	stack_.push(1);
	stack_.top();
	stack_.pop();
	stack_.emplace(1);

	// Capacity
	stack_.empty();
	stack_.size();

	return 1;
}