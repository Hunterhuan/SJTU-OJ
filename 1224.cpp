#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

template <class Type>
class closeHashTable
{
private:
	struct node
	{
		Type data;
		int state;
		int times;
		node() { state = 0;times = 0; }
	};
	node *array;
	int size;
protected:
	int(*key)(const Type &x);
	static int defaultKey(const int &k)
	{
        if(k > 0) return 2*k;
        else return -2*k+1;
	}
public:
	closeHashTable(int length = 101, int(*f)(const Type &x) = defaultKey)
	{
		size = length;
		array = new node[size];
		key = f;
	}
	~closeHashTable()
	{
		delete[] array;
	}
	int find(const Type &x) const;
	bool insert(const Type &x);
	bool remove(const Type &x);
	void rehash();
};

template<class Type>
int closeHashTable<Type>::find(const Type & x) const
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state == 0) return 0;
		if (array[pos].state == 1 && array[pos].data == x)
            return array[pos].times;
		pos = (pos + 1) % size;
	} while (pos != initPos);
	return 0;
}

template<class Type>
inline bool closeHashTable<Type>::insert(const Type & x)
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state != 1) {
			array[pos].data = x;
			array[pos].state = 1;
			array[pos].times = 1;
			return true;
		}
		if (array[pos].state == 1 && array[pos].data == x)
        {
            array[pos].times ++;
            return true;
        }
		pos = (pos + 1) % size;
	} while (pos != initPos);
	return false;
}

template<class Type>
bool closeHashTable<Type>::remove(const Type & x)
{
	int initPos, pos;
	initPos = pos = key(x) % size;
	do {
		if (array[pos].state == 0) return false;
		if (array[pos].state == 1 && array[pos].data == x)
		{
			array[pos].state = 2;
			return true;
		}
		pos = (pos + 1) % size;
	} while (pos != initPos);
	return false;
}

template<class Type>
void closeHashTable<Type>::rehash()
{
	node *tmp = array;
	array = new node[size];
	for (int i = 0; i < size; ++i) {
		if (tmp[i].state == 1)
			insert(tmp[i].data);
	}
	delete[] tmp;
}


int main()
{
	int n;
	int res = 0;
	int tmp;
	int **num;
	closeHashTable<int> hashtable(299999);

	cin >> n;

	num = new int*[4];
	for (int i = 0; i < 4; i++)
	{
		num[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
		cin >> num[0][i]>> num[1][i]>> num[2][i]>> num[3][i];

	for (int i = 0; i <n; i++)
	{
		for (int j = 0; j <n; j++)
		{
		    tmp = num[0][i] + num[1][j];
			hashtable.insert(tmp);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
		    int tmp = 0-(num[2][i]+num[3][j]);
		    res += (hashtable.find(tmp));
		}
	}
	cout << res;
	return 0;
}
