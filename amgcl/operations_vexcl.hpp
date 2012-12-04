#ifndef AMGCL_OPERATIONS_VEXCL_HPP
#define AMGCL_OPERATIONS_VEXCL_HPP

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

#include <vexcl/vexcl.hpp>

namespace amg {

template <typename T>
struct value_type {
    typedef typename T::value_type type;
};

template <typename T>
T inner_prod(const vex::vector<T> &x, const vex::vector<T> &y) {
    static vex::Reductor<T, vex::SUM> sum(vex::StaticContext<>::get().queue());
    return sum(x * y);
}

template <typename T>
T norm(const vex::vector<T> &x) {
    return sqrt( inner_prod(x, x) );
}

template <typename T>
void clear(vex::vector<T> &x) {
    x = 0;
}

}


#endif
