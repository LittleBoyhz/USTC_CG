// implementation of class DArray
#include "DArray.h"
#include <iostream>

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	//TODO
	m_nSize = nSize;
	m_pData = new double[nSize];
	for (int i = 0; i < nSize; i++) {
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray& arr) {
	//TODO
	m_nSize = arr.GetSize();
	m_pData = new double[m_nSize];
	for (int i = 0; i < m_nSize; i++) {
		m_pData[i] = arr.GetAt(i);
	}
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	//TODO
	std::cout << "size = " << m_nSize << ": ";
	for (int i = 0; i < m_nSize; i++) {
		std::cout << m_pData[i] << ' ';
	}
	std::cout << std::endl;
}

// initilize the array
void DArray::Init() {
	//TODO
	m_nSize = 0;
	m_pData = nullptr;
}

// free the array
void DArray::Free() {
	//TODO
	if (m_pData != nullptr) {
		delete [] m_pData;
		m_pData = nullptr;
		m_nSize = 0;
	}
}

// get the size of the array
int DArray::GetSize() const {
	//TODO
	return m_nSize; // you should return a correct value
}

// set the size of the array
void DArray::SetSize(int nSize) {
	//TODO
	m_nSize = nSize;
	
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	//TODO
	return m_pData[nIndex % m_nSize]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	//TODO
	if (m_pData != nullptr) {
		m_pData[nIndex % m_nSize] = dValue;
	}
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	//TODO
	return m_pData[nIndex]; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	//TODO
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	//TODO
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	//TODO
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	//TODO
	if (m_pData != nullptr) {
		delete [] m_pData;
	}
	m_nSize = arr.GetSize();
	m_pData = new double [m_nSize];
	for (int i = 0; i < m_nSize; i++) {
		m_pData[i] = arr.GetAt(i);
	}
	return *this;
}
