/*
 James Lindfors
 CS 262
 Lab 2
 */

#include "setFunctions.h"
#include "set.h"
#include "set.cpp"

#include <math.h>

using namespace std;

// Returns a set that is the Union of the two sets s1 and s2
Set<char> setUnion(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	int size1 = s1.cardinality();
	int size2 = s2.cardinality();

	// Add your code here
	for(int i = 0; i< size1; ++i)
	{
		result.insertElement(s1[i]);
	};
	for (int i = 0; i < size2; ++i)	
	{
		result.insertElement(s2[i]);
	};

	return result;
	
}

// Returns a set that is the intersection of the two sets s1 and s2
Set<char> setIntersection(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	
	int size1 = s1.cardinality();
	int size2 = s2.cardinality();
	
	// Add your code here
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
		{
			if(s1[i] == s2[j]) {
				result.insertElement(s1[i]);
			}
		}
	}

	return result;
	
}

// Returns a set that is the s1 - s2
Set<char> setDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;
	
	int size1 = s1.cardinality();
	int size2 = s2.cardinality();

	// Add your code here
	int j;
	for (int i = 0; i<size1; ++i)
	{
		for (j = 0; j<size2; ++j)
		{
			if(s1[i] == s2[j])
				break;
		}
		if (j == size2)
			result.insertElement(s1[i]);
	}
	
	return result;
	
}

// Returns a set that is the symetric difference of the two sets s1 and s2
Set<char> setSymDiff(const Set<char>& s1, const Set<char>& s2)
{
	Set<char> result;

	int size1 = s1.cardinality();

	// Add your code here
	for (int i = 0; i < size1; ++i)
	{
		if (!s1.isElement(s2[i])) {
			result.insertElement(s2[i]);
		}
		if (!s2.isElement(s1[i])) {
			result.insertElement(s1[i]);
		}
	}
	
	return result;
	
}

// Returns true if s1 is a subset of s2
bool isSubSet(const Set<char>& s1, const Set<char>& s2)
{

	int size1 = s1.cardinality();
	bool isSubset = true;
	
	// Add your code here and return the correct truth value
		for (int i = 0; i < size1; ++i)
		{
			if(s2.isElement(s1[i]) == false) {
				isSubset = false;
				break;
			}
		}
		return isSubset;
	
}

// Returns true if s1 is a proper subset of s2
bool isProperSubSet(const Set<char>& s1, const Set<char>& s2)
{
	
	int size1 = s1.cardinality();
	int size2 = s2.cardinality();
	bool isProperSubset = false;
	
	// Add your code here and return the correct truth value
		if(isSubSet(s1,s2) == true && size1 < size2) {
			isProperSubset = true;
		}
		return isProperSubset;
	
}

// Returns the Power Set of set s as a set of sets
Set<Set<char>> PowerSet(const Set<char>& s)
{
	Set<Set<char>> result;
	
	
	int powSet = pow(2, s.cardinality());
	int size = s.cardinality();

	// Add your code here
	for (int i = 0; i < powSet; i++)
	{
		Set<char> subSet;
		for (int j = 0; j < size; j++)
		{
			if (i & (1 << j)) {
				subSet.insertElement(s[j]);
			}
		}
		result.insertElement(subSet);
	}
	
	return result;
	
}

// Returns true if the sets in p make up a Partition of set s
bool isPartition(const Set<Set<char>>& p, const Set<char>& s)
{
	// Add your code here and return the correct truth value
	int size = p.cardinality();
		for (int i = 0; i < size; ++i)
		{
			if(isSubSet(p[i], s) == false) {
				return false;
			}
		}
	return true;

}
