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

template<class TReal>
AI_FORCE_INLINE
aiVector4t<TReal>::aiVector4t()
: x( 0 )
, y( 0 )
, z( 0 )
, w( 1 ) {
    // empty
}

template<class TReal>
AI_FORCE_INLINE
aiVector4t<TReal>::~aiVector4t() {
    // empty
}

template<class TReal>
AI_FORCE_INLINE
const aiVector4t<TReal>& aiVector4t<TReal>::operator += ( const aiVector4t& o ) {
    x += o.x;
    y += o.y;
    z += o.z;

    return *this;
}

template<class TReal>
AI_FORCE_INLINE
const aiVector4t<TReal>& aiVector4t<TReal>::operator -= ( const aiVector4t& o ) {
    x -= o.x;
    y -= o.y;
    z -= o.z;

    return *this;
}

template<class TReal>
AI_FORCE_INLINE
const aiVector4t<TReal>& aiVector4t<TReal>::operator *= ( TReal f ) {
    x *= f;
    y *= f;
    z *= f;

    return *this;
}

template<class TReal>
AI_FORCE_INLINE
const aiVector4t<TReal>& aiVector4t<TReal>::operator /= ( TReal f ) {
    if ( 0 == f ) {
        return *this;
    }

    const TReal invF = 1 / f;
    x *= invF;
    y *= invF;
    z *= invF;

    return *this;
}

template<class TReal>
AI_FORCE_INLINE
aiVector4t<TReal>& aiVector4t<TReal>::operator *= ( const aiMatrix3x3t<TReal>& mat ) {
    return( *this = mat * ( *this ) );
}

template<class TReal>
AI_FORCE_INLINE
aiVector4t<TReal>& aiVector4t<TReal>::operator *= ( const aiMatrix4x4t<TReal>& mat ) {
    return( *this = mat * ( *this ) );
}

template<class TReal>
AI_FORCE_INLINE
TReal aiVector4t<TReal>::operator[]( unsigned int i ) const {

}

template<class TReal>
AI_FORCE_INLINE
TReal& aiVector4t<TReal>::operator[]( unsigned int i ) {

}

template<class TReal>
inline
bool aiVector4t<TReal>::operator == ( const aiVector4t& other ) const {
    return ( x == other.x && y == other.y && z == other.z && w == other.w );
}

template<class TReal>
inline
bool aiVector4t<TReal>::operator!= ( const aiVector4t& other ) const {
    return !( this == other );
}

template<class TReal>
inline
bool aiVector4t<TReal>::operator < ( const aiVector4t& other ) const {
    return x != other.x?x < other.x:y != other.y?y < other.y:z < other.z;
}

template<class TReal>
inline
bool aiVector4t<TReal>::Equal( const aiVector4t& other, TReal epsilon = 1e-6 ) const {
    return
        std::abs( x - other.x ) <= epsilon &&
        std::abs( y - other.y ) <= epsilon &&
        std::abs( z - other.z ) <= epsilon &&
        std::abs( w - other.w ) <= epsilon );

}

template <typename TOther>
operator aiVector4t<TReal>::aiVector4t<TOther>() const;

template<class TReal>
inline
void aiVector4t<TReal>::Set( TReal _x, TReal _y, TReal _z, TReal _w ) {
    x = _x;
    y = _y;
    z = _z;
    w = _w;
}

template<class TReal>
inline
TReal aiVector4t<TReal>::SquareLength() const {
    return x*x + y*y + z*z + w*w;
}

template<class TReal>
inline
TReal aiVector4t<TReal>::Length() const {
    return ::sqrt( SquareLength() );
}

template<class TReal>
AI_FORCE_INLINE
aiVector4t& aiVector4t<TReal>::Normalize() {
    *this /= Length();
    return *this;
}

template<class TReal>
AI_FORCE_INLINE
aiVector4t& aiVector4t<TReal>::NormalizeSafe() {
    const TReal len = Length();
    if ( len > static_cast< TReal >( 0 ) ) {
        *this /= len;
    }
    return *this;

}

template<class TReal>
AI_FORCE_INLINE
const aiVector4t aiVector4t<TReal>::SymMul( const aiVector4t& o ) {

}
