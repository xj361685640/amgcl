#ifndef AMGCL_MPI_UTIL_HPP
#define AMGCL_MPI_UTIL_HPP

/*
The MIT License

Copyright (c) 2012-2014 Denis Demidov <dennis.demidov@gmail.com>
Copyright (c) 2014, Riccardo Rossi, CIMNE (International Center for Numerical Methods in Engineering)

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

/**
 * \file   amgcl/mpi/util.hpp
 * \author Denis Demidov <dennis.demidov@gmail.com>
 * \brief  MPI utilities.
 */

#include <mpi.h>

namespace amgcl {
namespace mpi {

/// Converts C type to MPI datatype.
template <class T, class Enable = void>
struct datatype;

template <>
struct datatype<float> {
    static MPI_Datatype get() { return MPI_FLOAT; }
};

template <>
struct datatype<double> {
    static MPI_Datatype get() { return MPI_DOUBLE; }
};

template <>
struct datatype<long double> {
    static MPI_Datatype get() { return MPI_LONG_DOUBLE; }
};

template <>
struct datatype<ptrdiff_t> {
    static MPI_Datatype get() {
        return sizeof(ptrdiff_t) == sizeof(int) ? MPI_INT : MPI_LONG_LONG_INT;
    }
};

/// Convenience wrapper around MPI_Comm.
struct communicator {
    MPI_Comm comm;
    int      rank;
    int      size;

    communicator(MPI_Comm comm) : comm(comm) {
        MPI_Comm_rank(comm, &rank);
        MPI_Comm_size(comm, &size);
    };

    operator MPI_Comm() const {
        return comm;
    }
};

} // namespace mpi
} // namespace amgcl

#endif
