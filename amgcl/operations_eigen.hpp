#ifndef AMGCL_OPERATIONS_EIGEN_HPP
#define AMGCL_OPERATIONS_EIGEN_HPP

/*
The MIT License

Copyright (c) 2012 Denis Demidov <ddemidov@ksu.ru>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <Eigen/Dense>

namespace amg {

template <typename T>
struct value_type {
    typedef typename T::Scalar type;
};

template <typename T1, typename T2>
typename T1::Scalar inner_prod(const Eigen::MatrixBase<T1> &x, const Eigen::MatrixBase<T2> &y) {
    return x.dot(y);
}

template <typename T>
typename T::Scalar norm(const Eigen::MatrixBase<T> &x) {
    return x.norm();
}

template <typename T>
void clear(Eigen::MatrixBase<T> &x) {
    x.setZero();
}

}


#endif
