/*************************************************************************
	> File Name: lru.cpp
	> Author: 
	> Mail: 
	> Created Time: 日  8/25 15:04:39 2019
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
	int cap = 0;
	std::list<int> dou_list;
	unordered_map<int, std::list<int>::iterator> mmp;

public:
	LRUCache(int capacity)
	{
		cap = capacity;
	}
	int get(int key)
	{
		int res = -1;
		if (mmp.find(key) == mmp.end())
		{
			return -1;
		}
		else
		{
			//需要更新缓存
			res = *mmp[key];
			dou_list.erase(mmp[key]);

			dou_list.push_front(res);
			mmp[key] = dou_list.begin();
		}
		return res;
	}

	void put(int key, int value)
	{
		//判断缓存满没满
		if (dou_list.size() < cap)
		{
			dou_list.push_front(value);
			mmp[key] = dou_list.begin();
		}
		//缓存满了
		else
		{
			dou_list.pop_back();
			dou_list.push_front(value);
			mmp[key] = dou_list.begin();
		}
	}
};

int main()
{
	LRUCache obj(2);
	obj.put(1, 1);
	obj.put(2, 2);
	cout << obj.get(1) << endl;
	obj.put(3, 3);
	cout << obj.get(2) << endl;

	obj.put(4, 4);
	cout << obj.get(1) << endl;
	cout << obj.get(3) << endl;
	cout << obj.get(4) << endl;

	return 0;
}

class LRUCache
{
private:
	int cap;
	// 双链表：装着 (key, value) 元组
	list<pair<int, int>> cache;
	// 哈希表：key 映射到 (key, value) 在 cache 中的位置
	unordered_map<int, list<pair<int, int>>::iterator> map;

public:
	LRUCache(int capacity)
	{
		this->cap = capacity;
	}

	int get(int key)
	{
		auto it = map.find(key);
		// 访问的 key 不存在
		if (it == map.end())
			return -1;
		// key 存在，把 (k, v) 换到队头
		pair<int, int> kv = *map[key];
		cache.erase(map[key]);
		cache.push_front(kv);
		// 更新 (key, value) 在 cache 中的位置
		map[key] = cache.begin();
		return kv.second; // value
	}

	void put(int key, int value)
	{

		/* 要先判断 key 是否已经存在 */
		auto it = map.find(key);
		if (it == map.end())
		{
			/* key 不存在，判断 cache 是否已满 */
			if (cache.size() == cap)
			{
				// cache 已满，删除尾部的键值对腾位置
				// cache 和 map 中的数据都要删除
				auto lastPair = cache.back();
				int lastKey = lastPair.first;
				map.erase(lastKey);
				cache.pop_back();
			}
			// cache 没满，可以直接添加
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
		else
		{
			/* key 存在，更改 value 并换到队头 */
			cache.erase(map[key]);
			cache.push_front(make_pair(key, value));
			map[key] = cache.begin();
		}
	}
};
using namespace std;
class Solution
{
public:
	int partition(vector<int> &nums, int l, int r)
	{
		int k = l, privot = nums[r];
		for (int i = l; i < r; i++)
		{
			if (nums[i] > privot)
				std::swap(nums[i], nums[k++]);
		}
		std::swap(nums[r], nums[k]);
		return k;
	}
	int findKthLargest(vector<int> &nums, int k)
	{
		if (nums.size() <= 0 || k <= 0)
			return 0;
		int l = 0;
		int r = nums.size() - 1;
		int index = partition(nums, l, r);

		while (index != k - 1)
		{
			if (index < k - 1)
			{
				l = index + 1;
				index = partition(nums, l, r);
			}
			if (index > k - 1)
			{
				r = index - 1;
				index = partition(nums, l, r);
			}
		}
		return nums[index];
	}
};
