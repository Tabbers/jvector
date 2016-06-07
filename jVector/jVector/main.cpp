#include <cstdint>
#include <memory>
typedef unsigned int uint;


namespace
{
	template<class T>
	struct CombinedPointer
	{
		char* m_memory;
		T* m_data;
	};

	template<class T>
	static CombinedPointer<T> allocateMemory(uint numberOfObjects)
	{
		size_t memorytoAllocate = sizeof(T)*numberOfObjects;
		size_t alignement = alignof(T);

		char* unalignedMemory = reinterpret_cast<char*>(malloc(memorytoAllocate + alignement));
		size_t difference = reinterpret_cast<size_t>(pOrigin) % alignment;

		if (difference != 0)
			memory = memorytoAllocate + (alignment - difference);
		else
			memory = memorytoAllocate;

		CombinedPointer<T> pointers;
		pointers.m_memory = unalignedMemory;
		pointers.m_data = reinterpret_cast<T*> memory;;

		return pointers;
	}
}

template<class T>
class JVector
{
	
	public:

		uint capacity() const;
		uint size() const;

		void reserve(uint);
		void push_back(T);
		void resize(uint);
		void erease(uint);
		void erease_by_swap(uint);
	private:
		size_t m_capacity;
		size_t m_size;

		char* m_memory;
		T* m_data;

	private:
	

};


template<class T>
uint JVector<T>::capacity() const
{
	return m_capacity;
}

template<class T>
uint JVector<T>::size() const
{
	return m_size();
}

template<class T>
void JVector<T>::reserve(uint numberOfObjects)
{
	if (numberOfObjects <= capacity)
		return;

	CombinedPointer<T> newMemory = allocateMemory(numberOfObjects);

	if (m_size > 0)
	{
		for (uint i = 0u; i < m_size; ++i)
		{
			new (&newMemory.m_data[i]) T(m_data[i]);
		}
		m_memory = newMemory.m_memory;
		m_data = newMemory.m_data;
	}
	else
	{
		m_memory = newMemory.m_memory;
		m_data = newMemory.m_data;
	}
}

template<class T>
void JVector<T>::push_back(T)
{
	size_t newSize = m_size + sizeof(T);
	if (newSize >= capacity)
	{
		CombinedPointer<T> newMemory = allocateMemory(newSize*2);
		for (uint i = 0u; i < m_size; ++i)
		{
			new (&newMemory.m_data[i]) T(m_data[i]);
		}
		m_memory = newMemory.m_memory;
		m_data = newMemory.m_data;
	}
}

template<class T>
void JVector<T>::resize(uint numberOfObjects)
{
	if (m_size > 0)
	{
		
	}
	else
	{

	}

}

template<class T>
void JVector<T>::erease(uint indexToDelete)
{
	
}

template<class T>
void JVector<T>::erease_by_swap(uint indexToDelete)
{
}

int main()
{
	return 0;
}