#ifndef BST_NODE
#define BST_NODE

namespace ft {

template <class T>
struct bst_node {
		typedef T					value_type;
		typedef bst_node* pointer;

		bst_node() : parent(), left(), right(), value(), is_limit( false ) { }

		bst_node( bool b ) : parent(), left(), right(), value(), is_limit( b ) { }

		bst_node( const value_type& val ) : parent(), left(), right(), value( val ), is_limit( false ) { }

		void limit_node_init( value_type& val ) {
			is_limit = true;
			value = val;
			parent = nullptr;
		}

		pointer		 parent;
		pointer		 left;
		pointer		 right;
		value_type value;
		bool			 is_limit;
};

} // namespace ft
#endif