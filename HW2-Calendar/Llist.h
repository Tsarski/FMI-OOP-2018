#pragma once
#include "stdafx.h"
#include <iostream>
#include <cassert>
#pragma warning (disable : 4996)

template <typename T>
struct Node
{
	T data;
	Node<T> *next;
	Node(T data, Node* next)
	{
		this->data = data;
		this->next = next;
	}
};

template <typename T>
class Llist
{
private:
	Node<T> *first;
	Node<T> *last;
	size_t size;

	void copy(const Llist& other)
	{
		Node<T> *temp = other.first;
		for (int i = 0; i < other.size; i++)
		{
			push_back(temp->data);
			temp = temp->next;
		}
	}
	void erase()
	{
		while (size > 0)
		{
			pop_back();
		}
	}
public:
	Llist()
	{
		this->first = 0;
		this->last = 0;
		this->size = 0;
	}
	Llist(const Llist& other)
	{
		copy(other);
	}
	Llist& operator=(const Llist& other)
	{
		if (this != &other)
		{
			erase();
			copy(other);
		}
		return *this;
	}
	~Llist()
	{
		erase();
	}
	
	bool isEmpty()
	{
		return (this->size == 0);
	}
	T& getAt(size_t index)
	{
		if (!this->isEmpty() && index < size)
		{
			Node<T>* temp = this->first;
			while(index > 0 && temp != nullptr)
			{
				temp = temp->next;
				index--;
			}
			return temp->data;
		}
	}
	void push_back(T data)
	{
			Node<T> *temp = new Node<T>(data, nullptr);
			if (this->size == 0)
			{
				this->first = temp;
				this->last = temp;
			}
			else
			{
				this->last->next = temp;
				this->last = temp;
			}
			this->size++;
	}
	void push_front(T data)
	{
		Node<T> *temp = new Node<T> (data, this->first);
		this->first = temp;
		if (size == 0)
		{
			this->last = temp;
		}
		this->size++;
	}
	void pop_back()
	{
		if (!this->isEmpty())
		{
			removeAt(size - 1);
		}
	}
	void pop_front()
	{
		Node<T> *temp = this->first->next;
		delete this->first;
		this->first = temp;
		this->size--;
	}
	bool insertAt(const T& data, size_t index)
	{
		
		if (index == 0)
		{
			push_front(data);
			return true;
		}
		if (index == size)
		{
			push_back(data);
			return true;
		}
		Node<T> *temp = first;
		while (temp != nullptr && index >1)
		{
			temp = temp->next;
			index--;
		}
		if (temp == nullptr)
		{
			return false;
		}
		temp->next = new Node<T>(data, temp->next);
		this->size++;
		return true;
	}
	bool removeAt(size_t index)
	{
		if (index > size - 1)
		{
			return false;
		}
		Node<T> *temp = this->first;
		Node <T> *temp2 = temp->next;
		while (index > 1 && temp != nullptr)
		{
			temp = temp->next;
			temp2 = temp2->next;
			index--;
		}
		if (temp2 == nullptr)
		{
			return true;
		}
		temp->next = temp2->next;
		delete temp2;
		size--;
	}
	friend std::ostream& operator<<(std::ostream& os, const Llist &list) 
	{
		os << "[";
		Node<T> *temp = list.first;
		while (temp != nullptr) 
		{
			os << " " << temp->data;
			temp = temp->next;
		}
		os << "]";
		return os;
	}
};