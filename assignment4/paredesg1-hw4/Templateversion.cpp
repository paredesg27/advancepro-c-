//
// Created by Georg on 3/16/2023.
//
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
//template <typename T>
//class IComparableTemp {
//public:
//    virtual bool isLessThan(T other) const = 0;
//};
//
//template <typename T>
//class IntWrapperTemp : public IComparableTemp<IntWrapper<T>> {
//public:
//    IntWrapperTemp(T val) : value(val) {}
//
//    bool isLessThan(IntWrapperTemp<T> other) const override {
//        return value < other.value;
//    }
//
//    T getValue() const {
//        return value;
//    }
//
//private:
//    T value;
//};
//
//template <typename T>
//class StringWrapperTemp : public IComparableTemp<StringWrapper<T>> {
//public:
//    StringWrapperTemp(T val) : value(val) {}
//
//    bool isLessThan(StringWrapperTemp<T> other) const override {
//        return value < other.value;
//    }
//
//    T getValue() const {
//        return value;
//    }
//
//private:
//    T value;
//};
//
//template <typename T>
//void sortTemp(vector<IComparableTemp<T>*> &vec) {
//    for (int i = 0; i < vec.size(); i++) {
//        for (int j = i + 1; j < vec.size(); j++) {
//            if (vec[j]->isLessThan(dynamic_cast<T*>(vec[i]))) {
//                std::swap(vec[i], vec[j]);
//            }
//        }
//    }
//}
//
//template <typename T>
//bool verifySortedTemp(vector<IComparableTemp<T>*> vec) {
//    for (int i = 1; i < vec.size(); i++) {
//        if (vec[i]->isLessThan(dynamic_cast<T*>(vec[i-1]))) {
//            return false;
//        }
//    }
//    return true;
//}
