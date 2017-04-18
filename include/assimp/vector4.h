/*
---------------------------------------------------------------------------
Open Asset Import Library (assimp)
---------------------------------------------------------------------------

Copyright (c) 2006-2017, assimp team

All rights reserved.

Redistribution and use of this software in source and binary forms,
with or without modification, are permitted provided that the following
conditions are met:

* Redistributions of source code must retain the above
copyright notice, this list of conditions and the
following disclaimer.

* Redistributions in binary form must reproduce the above
copyright notice, this list of conditions and the
following disclaimer in the documentation and/or other
materials provided with the distribution.

* Neither the name of the assimp team, nor the names of its
contributors may be used to endorse or promote products
derived from this software without specific prior
written permission of the assimp team.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
---------------------------------------------------------------------------
*/
#pragma once

// ---------------------------------------------------------------------------
/** Represents a three-dimensional vector. */
template <typename TReal>
class aiVector4t {
public:
    aiVector4t();
    ~aiVector4t();
    aiVector4t( TReal _x, TReal _y, TReal _z, TReal _w ) : x( _x ), y( _y ), z( _z ), w(_w) {}
    explicit aiVector4t( TReal _xyz ) : x( _xyz ), y( _xyz ), z( _xyz ), w(1) {}
    aiVector4t( const aiVector4t& o ) : x( o.x ), y( o.y ), z( o.z ), w( o.w ) {}

    // combined operators
    const aiVector4t& operator += ( const aiVector4t& o );
    const aiVector4t& operator -= ( const aiVector4t& o );
    const aiVector4t& operator *= ( TReal f );
    const aiVector4t& operator /= ( TReal f );

    // transform vector by matrix
    aiVector4t& operator *= ( const aiMatrix3x3t<TReal>& mat );
    aiVector4t& operator *= ( const aiMatrix4x4t<TReal>& mat );

    // access a single element
    TReal operator[]( unsigned int i ) const;
    TReal& operator[]( unsigned int i );

    // comparison
    bool operator== ( const aiVector3t& other ) const;
    bool operator!= ( const aiVector3t& other ) const;
    bool operator < ( const aiVector3t& other ) const;

    bool Equal( const aiVector4t& other, TReal epsilon = 1e-6 ) const;

    template <typename TOther>
    operator aiVector4t<TOther>() const;

public:
    /** @brief Set the components of a vector
     *  @param x X component
     *  @param y Y component
     *  @param z Z component  
     *  @param w W component  
     */
    void Set( TReal x, TReal y, TReal z, TReal w );

    /** @brief Get the squared length of the vector
    *  @return Square length */
    TReal SquareLength() const;

    /** @brief Get the length of the vector
    *  @return length */
    TReal Length() const;

    /** @brief Normalize the vector */
    aiVector4t& Normalize();

    /** @brief Normalize the vector with extra check for zero vectors */
    aiVector4t& NormalizeSafe();

    /** @brief Component-wise multiplication of two vectors
    *
    *  Note that vec*vec yields the dot product.
    *  @param o Second factor */
    const aiVector4t SymMul( const aiVector4t& o );

public:
    TReal x, y, z, w;
};

typedef aiVector4t<ai_real> aiVector4D;


#include <assimp/vector4.inl>