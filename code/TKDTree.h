#pragma once

#include <vector>

namespace Assimp {

template<class TPoint, typename TReal>
class TKDTree {
public:
    TKDTree();
    ~TKDTree();
    void build( const std::vector<TPoint> &pointCache );

private:
    struct KDNode {
        size_t m_left;
        size_t m_right;
        TReal m_split;
        size_t m_index;
        void *m_data;

        KDNode();
        ~KDNode();
    };

    KDNode *m_root;
    std::vector<size_t> m_points;
    std::vector<TPoint> m_pointCache;
};

template<class TPoint, typename TReal>
inline
TKDTree<TPoint, TReal>::TKDTree()
: m_root( nullptr )
, m_points()
, m_pointCache() {
    // empty
}

template<class TPoint, typename TReal>
inline
TKDTree<TPoint, TReal>::~TKDTree() {
    // empty
}

template<class TPoint, typename TReal>
inline
void TKDTree<TPoint, TReal>::build( const std::vector<TPoint> &pointCache ) {
    if ( pointCache.empty() ) {
        return;
    }
    const size_t count( pointCache.size() );
    m_points.resize( count );
    for ( size_t i = 0; i < count; ++i ) {
        m_points[ i ] = i;
    }
}


template<class TPoint, typename TReal>
inline
TKDTree<TPoint, TReal>::KDNode::KDNode()
: m_left( -1 )
, m_right( -1 )
, m_split( 0.0 )
, m_index( 9999 )
, m_data( nullptr ) {
    // empty
}

template<class TPoint, typename TReal>
inline
TKDTree<TPoint, TReal>::KDNode::~KDNode() {
    // empty
}

}
