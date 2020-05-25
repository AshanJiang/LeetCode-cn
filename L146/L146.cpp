#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    int size{ 0 }, cap{ 0 };
    vector<int> v;
    unordered_map<int, int> umap;
    LRUCache(int capacity) {
        size = 0;
        cap = capacity;
    }

    int get(int key) {
        if (umap.find(key) != umap.end())
        {
            v.erase(find(v.begin(), v.end(), key));
            v.push_back(key);
            return umap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value) {
        if (umap.find(key) != umap.end())
        {
            umap[key] = value;
            v.erase(find(v.begin(), v.end(), key));
            v.push_back(key);
        }
        else
        {
            if (size >= cap)
            {
                int deleteKey = v[0];
                v.erase(v.begin());
                v.push_back(key);
                umap.erase(deleteKey);
                umap[key] = value;
            }
            else
            {
                size++;
                v.push_back(key);
                umap[key] = value;
            }
        }
    }
};

int main()
{
    LRUCache* cache = new LRUCache(2);
    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << "\n";       // 返回  1
    cache->put(3, 3);    // 该操作会使得密钥 2 作废
    cout << cache->get(2) << "\n";       // 返回 -1 (未找到)
    cache->put(4, 4);    // 该操作会使得密钥 1 作废
    cout << cache->get(1) << "\n";       // 返回 -1 (未找到)
    cout << cache->get(3) << "\n";       // 返回  3
    cout << cache->get(4) << "\n";       // 返回  4

	return 0;
}