
#include <cstdint>

template<class T>
class JVector
{
	public:
		void reserve(size_t);
		void push_back(T);
		void resize(size_t);
		void erease(unsigned int);
		void erease_by_swap(unsigned int);
	private:
		size_t capacity;
		size_t size;

		uintptr_t memory;
};

template<class T>
void JVector<T>::reserve(size_t numberOfObjects)
{
}

template<class T>
void JVector<T>::push_back(T)
{
	size_t newSize = size + sizeof(T);
	if (newSize >= capacity)
	{
		//need to allocate new memory here
	}
}

template<class T>
void JVector<T>::resize(size_t numberOfObjects)
{
	// allocate new Memory
	// construct T in

}

template<class T>
void JVector<T>::erease(unsigned int indexToDelete)
{
	
}

template<class T>
void JVector<T>::erease_by_swap(unsigned int indexToDelete)
{
}
