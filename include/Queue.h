#ifndef _QUEUE_
#define _QUEUE_

#include <iostream>
using namespace std;

template <class T>
class TQueue 
{
protected:
  int size;
  int start, end;
  T* data;

public:
  TQueue(int _size = 0);
  TQueue(const TQueue<T>& q);
  TQueue(TQueue<T>&& q);
  ~TQueue();
  void Push(T a);
  T GetElem();
  int GetCount();
  bool IsFull();
  bool IsEmpty();
};

template <class T>
TQueue <T> ::TQueue(int _size) //конструктор
{
	if (_size < 0)
	{
		throw "Ошибка";
	}
	else if (_size == 0)
	{
		data = nullptr;
		size = 0;
	}
	else
	{
		size = _size;
		data = new T[size];
	}
	start = 0;
	end = 0;
}

template <class T>
TQueue<T> ::TQueue(const TQueue<T>& q) //конструктор копирования
{
	if (q.data == nullptr)
	{
		data = nullptr;
		size = 0;
	}
	else
	{
		size = q.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = q.data[i];
		}
	}
	start = q.start;
	end = q.end;
}

template <class T>
TQueue<T> :: ~TQueue() //деструктор
{
	if (data != nullptr)
	{
		delete[] data;
		data = nullptr;
	}
}

template <class T>
TQueue<T> ::TQueue(TQueue<T>&& q) //конструктор перемещения
{
	data = q.data;
	size = q.size;
	start = q.start;
	end = q.end;
	q.data = nullptr;
	q.size = 0;
	q.start = 0;
	q.end = 0;
}

template <class T>
bool TQueue<T> ::IsEmpty() //проверет пустая ли очередь
{
	if (start == end) return true;
	else return false;
}

template <class T>
bool TQueue<T> ::IsFull() //проверяет полна ли очередь
{
	if ((end + 1) % size == start) return true;
	else return false;
}

template <class T>
T TQueue <T> ::GetElem() //возвращает самый первый вошедший элемент в очередь
{
	if (IsEmpty())
	{
		throw "Ошибка";
	}
	int st = start;
	start = (start + 1) % size;
	return data[st];
}

template <class T>
void TQueue<T> ::Push(T a) //кладет элемент в очередь
{
	if (IsFull())
	{
		throw "Ошибка";
	}
	else
	{
		data[end] = a;
		end++;
		if (end == size)
		{
			end = 0;
		}
	}
}

template <class T>
int TQueue <T> ::GetCount()
{
	return (end - start + size) % size;
}
 
#endif