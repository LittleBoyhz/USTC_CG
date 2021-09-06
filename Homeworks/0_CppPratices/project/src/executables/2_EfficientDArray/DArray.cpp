// implementation of class DArray
#include "DArray.h"
#include <iostream>
#include <cassert>

// default constructor
DArray::DArray() {
	Init();
}

// set an array with default values
DArray::DArray(int nSize, double dValue) {
	//TODO
	m_nSize = nSize;
	m_nMax = 2 * nSize;
	m_pData = new double [m_nMax];
	for (int i = 0; i < m_nMax; i++) {
		m_pData[i] = dValue;
	}
}

DArray::DArray(const DArray& arr) {
	//TODO
	m_nMax = arr.m_nMax;
	m_nSize = arr.m_nSize;
	m_pData = new double [m_nMax];
	for (int i = 0; i < m_nSize; i++) {
		m_pData[i] = arr.m_pData[i];
	}
}

// deconstructor
DArray::~DArray() {
	Free();
}

// display the elements of the array
void DArray::Print() const {
	//TODO
	std::cout << "size = " << m_nSize << std::endl;
	for (int i = 0; i < m_nSize; i++) {
		std::cout << m_pData[i] << ' ';
	}
	std::cout << std::endl;
}

// initilize the array
void DArray::Init() {
	//TODO
	m_nSize = 0;
	m_nMax = 0;
	m_pData = nullptr;
}

// free the array
void DArray::Free() {
	//TODO
	if (m_pData != nullptr){
		delete [] m_pData;
		m_pData = nullptr;
		m_nSize = 0;
		m_nMax = 0;
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
}

// get an element at an index
const double& DArray::GetAt(int nIndex) const {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex]; // you should return a correct value
}

// set the value of an element 
void DArray::SetAt(int nIndex, double dValue) {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	m_pData[nIndex] = dValue;
}

// overload operator '[]'
double& DArray::operator[](int nIndex) {
	// TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex]; // you should return a correct value
}

// overload operator '[]'
const double& DArray::operator[](int nIndex) const {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	return m_pData[nIndex]; // you should return a correct value
}

// add a new element at the end of the array
void DArray::PushBack(double dValue) {
	//TODO
	if (m_nSize < m_nMax) {
		m_pData[m_nSize++] = dValue;
	}
	else {
		double* array = new double [2 * m_nSize + 2];

		memcpy(array, m_pData, sizeof(double) * m_nSize);
		array[m_nSize] = dValue;

		m_nSize++;
		m_nMax = 2 * m_nSize;
		delete [] m_pData;
		m_pData = array;
	}
}

// delete an element at some index
void DArray::DeleteAt(int nIndex) {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	for (int i = nIndex; i + 1 < m_nSize; i++) {
		m_pData[i] = m_pData[i + 1];
	}
	m_nSize--;
}

// insert a new element at some index
void DArray::InsertAt(int nIndex, double dValue) {
	//TODO
	assert(nIndex >= 0 && nIndex < m_nSize);
	if (m_nSize < m_nMax) {
		for (int i = m_nSize; i > nIndex; i--) {
			m_pData[i] = m_pData[i-1];
		}
		m_pData[nIndex] = dValue;
	}
	else {
		double* array = new double [2 * m_nSize + 2];

		memcpy(array, m_pData, sizeof(double) * nIndex);
		array[nIndex] = dValue;
		memcpy(array + nIndex + 1, m_pData + nIndex, sizeof(double) * (m_nSize - nIndex + 1));

		m_nSize++;
		m_nMax = m_nSize * 2;
		delete [] m_pData;
		m_pData = array;
	}
}

// overload operator '='
DArray& DArray::operator = (const DArray& arr) {
	//TODO
	if (m_pData == nullptr) {
		m_pData = new double [arr.m_nMax];
	}
	else if (m_nMax != arr.m_nMax) {
		double* temp = new double [arr.m_nMax];
		delete [] m_pData;
		m_pData = temp;
	}

	m_nSize = arr.m_nSize;
	m_nMax = arr.m_nMax;
	memcpy(m_pData, arr.m_pData, sizeof(double) * m_nSize);
	return *this;
}
